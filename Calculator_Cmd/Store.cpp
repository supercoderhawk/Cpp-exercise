//存储标识符值的类Store.h的实现
#include "SymbolTable.h"
#include "Store.h"
#include <cmath>

//构造函数的定义
Store::Store(int s, SymbolTable &symbolTable):size(s)
{
	//建立存储空间并初始化
	cell=new double[size];
	status=new unsigned char[size];
	for (int i=0; i<size; i++)
		status[i]=NotInit;
	//添加预定义变量
	//添加自然对数e
	int id=symbolTable.ForceAdd("e",1);
	SetValue(id,std::exp(1.0));
	//添加圆周率pi
	id=symbolTable.ForceAdd("pi",2);
	SetValue(id,2*std::acos(0.0));

}

//析构函数
Store::~Store()
{
	delete[] cell;
	delete[] status;
}
