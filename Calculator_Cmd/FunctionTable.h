//函数指针表FunctionTable类的定义
#ifndef FUNCTIONTABLE_H_
#define FUNCTIONTABLE_H_
#include <cmath>
//首先定义函数指针的别名
typedef double (*PtrFun)(double);
//定义函数指针与函数名联系的类
class FunctionEntry
{
public:
	//函数指针
	PtrFun pFun;
	//函数名
	char* strFun;
};

//定义表中存储的最大函数量
const int MAXIDFUN=16;


//定义函数表FunctionTable类

//前向声明
class SymbolTable;
class FunctionTable
{
public:
	//构造与析构函数
	FunctionTable(SymbolTable& symTab, FunctionEntry funArr[]);
	~FunctionTable(){}
	//获得表中函数的个数
	int GetSize() const {return size;}
	//通过id获得函数指针
	PtrFun GetFunction(int id) const{return function[id];}
private:
	//函数的数量
	int size;
	//函数指针表
	PtrFun function[MAXIDFUN];

};
#endif