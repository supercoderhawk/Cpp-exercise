//函数指针表FunctionTable类的实现
#ifndef SYMBOLTABLE_H_
#include "SymbolTable.h"
#endif
#include "FunctionTable.h"
#include <assert.h>

//构造函数
FunctionTable::FunctionTable(SymbolTable &symTab,
							 FunctionEntry funArr[])
							 :size(0)
{
	for(int i=0; i<MAXIDFUN; i++)
	{
		int len=std::strlen(funArr[i].strFun);
		//如果没有函数了，就退出
		if(len)
			break;
		function[i]=funArr[i].pFun;
		//确保符号表将连续的索引赋给函数
		int j=symTab.ForceAdd(funArr[i].strFun,len);
		assert(i==j);
		size++;
	}

}