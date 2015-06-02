//节点类Node以及子代的定义
#ifndef TREE_H_
#define TREE_H_
#include <assert.h>
#ifndef FUNCTIONTABLE_H_
#include "FunctionTable.h"
#endif

//定义node抽象类
class Node
{
public:
	virtual ~Node(){}
	//判断节点是否为左值
	virtual bool  IsLeftValue() const {return false;}
	//实现加方法
	virtual void Assign(double value){}
	virtual double Calc() const=0;
};

//Node类的派生类NumNode，表示一个数
class NumNode:public Node
{
public:
	NumNode(double n):num(n){}
	double Calc() const{return num;}
private:
	const double num;
};

//Node的派生类BinNode，表示一个二元运算符
class BinNode:public Node
{
public:
	BinNode(Node* pleft, Node* pright)
		:left(pleft),right(pright){}
	~BinNode();
protected:
	//操作符的左操作数和右操作数
	Node* left;
	Node* right;

};

//Node类的派生类UniNode类，表示单目或者函数运算
class UniNode:public Node
{
public:
	UniNode(Node* n):node(n){}
	~UniNode(){delete node;}
protected:
	Node* node;
};

//Node的派生类VarNode，处理变量的运算
//前向声明
class Store;
class VarNode: public Node
{
public:
	//构造函数
	VarNode(int ID, Store& _store):id(ID),store(_store){}
	//重写计算函数
	double Calc() const;
	//判断变量是够为左值
	bool IsLeftValue() const;
	//重写加运算
	void Assign(double value);
private:
	//标识符在符号表中的id
	const int id;
	//存储的符号表
	Store& store;

};

//BinNode派生类AddNode,表示两操作数的相加
class AddNode:public BinNode
{
public:
	AddNode(Node* pLeft,Node* pRight):BinNode(pLeft,pRight){}
	double Calc() const;
};

//BinNode派生类SubNode，表示两操作数相减
class SubNode:public BinNode
{
public:
	SubNode(Node* pLeft,Node* pRight):BinNode(pLeft,pRight){}
	double Calc() const;
};

//BinNode派生类MultNode类，表示两操作数相除
class MultNode:public BinNode
{
public:
	MultNode(Node* pLeft,Node* pRight):BinNode(pLeft,pRight){}
	double Calc() const;
};

//BinNode派生类DivideNode类，表示两操作数相除
class DivideNode:public BinNode
{
public:
	DivideNode(Node* pLeft,Node* pRight):BinNode(pLeft,pRight){}
	double Calc() const;
};

//BinNode派生类AssignNode类，表示赋值运算
class AssignNode:public BinNode
{
public:
	AssignNode(Node* pLeft,Node* pRight):BinNode(pLeft,pRight)
	{assert(left->IsLeftValue());}	//确保赋值运算符左边为左值
	double Calc() const;
};

//UniNode的派生类FunNode，表示函数运算
class FunNode:public UniNode
{
public:
	FunNode(PtrFun _pFun, Node* _pNode)
		:UniNode(_pNode),pFun(_pFun),pNode(_pNode){}
	double Calc() const;
private:
	//函数指针
	PtrFun pFun;
	Node* pNode;

};

//UniNode派生类UMinusNode,表示取负值
class UMinusNode:public UniNode
{
public:
	UMinusNode(Node* _pNode):UniNode(_pNode),pNode(_pNode){}
	double Calc() const;
private:
	Node* pNode;
};
#endif