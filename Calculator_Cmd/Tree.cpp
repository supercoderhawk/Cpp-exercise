//Node类及其子类的实现文件
#include "Tree.h"
#ifndef STROE_H_
#include "Store.h"
#endif
#ifndef _IOSTREAM_
#include <iostream>
#endif
#include <assert.h>

//实现BinNode类
BinNode::~BinNode()
{
	delete left;
	delete right;
}

//实现VarNode类
//得到标识符的值
double VarNode::Calc() const
{
	double x=0;
	if(store.IsInit(id))
		x=store.GetValue(id);
	else
		std::cout<<"Use uninitialized variable"<<std::endl;
	return x;

}

//相加
void VarNode::Assign(double value)
{
	store.SetValue(id,value);
}

//标识符为左值
bool VarNode::IsLeftValue() const
{
	return true;
}

//实现AddNode类加运算
double AddNode::Calc() const
{
	return left->Calc()+right->Calc();
}

//实现SubNode类减运算
double SubNode::Calc() const
{
	return left->Calc()-right->Calc();
}

//实现MultNode类乘运算
double MultNode::Calc() const
{
	return left->Calc()*right->Calc();
}

//实现DivideNode类除运算
double DivideNode::Calc() const
{
	return left->Calc()/right->Calc();
}

//实现AssignNode类赋值运算
double AssignNode::Calc() const
{
	double x=right->Calc();
	left->Assign(x);
	return x;
}

//实现FunNode类函数运算
double FunNode::Calc() const
{
	//确保函数指针非空
	assert(pFun!=0);
	return (*pFun)(pNode->Calc());
}

//实现UMinusNode类的取负值运算
double UMinusNode::Calc() const
{
	return -pNode->Calc();
}