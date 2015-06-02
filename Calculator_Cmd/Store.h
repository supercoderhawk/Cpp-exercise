//存储标识符及其值的符号表类Store.h
#ifndef STORE_H_
#define STORE_H_
#include <assert.h>
//存储标识符及其符号表类Store.h的定义
class SymbolTable;	//前向声明
//定义单元的两种状态
enum {
	NotInit,	//标识符未被初始化
	Init};		//标识符已被初始化
class Store
{
public:
	//构造与析构函数
	Store(int size, SymbolTable& symbolTable);
	~Store();
	//判断id是否被初始化
	bool IsInit(int id) const{return (id<size&&status[id]==Init);}
	//获得某id的值
	double GetValue(int id) const{assert(IsInit(id));return cell[id];}
	//设置id对应的值
	void SetValue(int id, double val)
	{
		if(id<size)
		{
			cell[id]=val;
			status[id]=Init;
		}
	}
private:
	//标识符值的最大存储容量
	int size;
	//存储标识符值的数组指针
	double* cell;
	//标识符是否初始化的状态
	unsigned char* status;

};
#endif