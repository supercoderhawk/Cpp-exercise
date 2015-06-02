//实现扫描器Parser类
#include "Parser.h"
#include "Scanner.h"
#include "SymbolTable.h"
#include "Store.h"
#include "Tree.h"
#include "FunctionTable.h"

//构造函数
Parser::Parser(Scanner &_scanner,
			   Store &_store,
			   FunctionTable &_funTab,
			   SymbolTable &_symTab)
		:scanner(_scanner),
		tree(0),
		status(stOk),
		functionTable(_funTab),
		store(_store),
		symbolTable(_symTab)
{

}

//析构函数
Parser::~Parser()
{
	//递归删除
	delete tree;
}

//解析输入并计算
Status Parser::Eval()
{
	//解析输入
	Parse();
	//解析成功，执行，否则退出
	if(status==stOk)
		Execute();
	else
		status=stQuit;
	return status;

}

//执行计算
void Parser::Execute()
{
	if(tree)
		double result=tree->Calc();
	
}

//进行初始解析
void Parser::Parse()
{
	tree=Expr();
}

//解析表达式，处理加减与赋值
Node* Parser::Expr()
{
	Node* pNode=Term();
	Token token=scanner.GetToken();
	if(token==Plus)
	{
		scanner.Accept();
		Node* pRight=Expr();
		pNode=new AddNode(pNode,pRight);
	}
	else if(token==Minus)
	{
		scanner.Accept();
		Node* pRight=Expr();
		pNode=new SubNode(pNode,pRight);
	}
	else if(token==Assign)
	{
		scanner.Accept();
		Node* pRight=Expr();
		if(pNode->IsLeftValue())
		{
			pNode=new AssignNode(pNode,pRight);
		}
		else
		{
			status=stError;
			delete pNode;
			pNode=Expr();
		}
	}
	return pNode;
}

//处理乘与除
Node* Parser::Term()
{
	Node* pNode=Factor();
	if(scanner.GetToken()==Mult)
	{
		scanner.Accept();
		Node* pRight=Term();
		pNode=new MultNode(pNode,pRight);
	}
	else if(scanner.GetToken()==Divide)
	{
		scanner.Accept();
		Node* pRight=Term();
		pNode=new DivideNode(pNode,pRight);
	}
	return pNode;
}

//处理因子
Node* Parser::Factor()
{
	Node* pNode;
	Token token=scanner.GetToken();

	if(token==LParen)
	{
		//接受左括号
		scanner.Accept();
		pNode=Expr();
		if(scanner.GetToken()!=RParen)
			status=stError;
		else
			scanner.Accept();
	}
	else if(token==Number)
	{
		pNode=new NumNode(scanner.GetNumber());
		scanner.Accept();
	}
	else if(token==Ident)
	{
		char strSymbol[MAXSYMBOLLEN];
		int lenSym=MAXSYMBOLLEN;
		//把符号复制到strSymbol中
		scanner.GetSymbolName(strSymbol,lenSym);
		int id=symbolTable.Find(strSymbol);
		scanner.Accept();
		if(scanner.GetToken()==LParen)
		{
			scanner.Accept();//接受左括号
			pNode=Expr();
			if(scanner.GetToken()==RParen)
				scanner.Accept();	//接受右括号
			else
				status=stError;
			if(id!=IDNOTFOUND && id<functionTable.GetSize())
			{
				pNode=new FunNode(functionTable.GetFunction(id),pNode);
			}
			else
			{
				std::cout<<"Unknown function\"";
				std::cout<<strSymbol<<"\"\n";
			}
		}
		else
		{
			if(id==IDNOTFOUND)
				id=symbolTable.ForceAdd(strSymbol,lenSym);
			pNode=new VarNode(id,store);

		}
	}
	else if(token==Minus)
	{
		scanner.Accept();	//接受减
		pNode=new UMinusNode(Factor());
	}
	else
	{
		scanner.Accept();
		status=stError;
		pNode=0;
	}
	return pNode;
}