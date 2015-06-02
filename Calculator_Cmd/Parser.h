//解析器类Parse.h的定义
#ifndef PARSER_H_
#define PARSER_H_
//前向声明
class Node;
class Scanner;
class Store;
class FunctionTable;
class SymbolTable;
//解析结果的状态码
enum Status
{
	stOk,	//正确
	stQuit,	//退出
	stError	//错误
};

class Parser
{
public:
	//构造与析构函数
	Parser(Scanner& _scanner,
			Store& _store,
			FunctionTable& _funTab,
			SymbolTable& _symTab);
	~Parser();
	//计算
	Status Eval();
private:
	void Parse();
	Node* Expr();
	Node* Term();
	Node* Factor();
	void Execute();

	Scanner& scanner;
	Node* tree;
	Status status;
	Store& store;
	FunctionTable& functionTable;
	SymbolTable& symbolTable;
};
#endif