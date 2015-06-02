//实现符号表类SymbolTable
#include "SymbolTable.h"
#ifndef _IOSTREAM_
#include <iostream>
#endif
#include<assert.h>

//缓冲器类StringBuffer的实现
//构造函数,根据输入的值构建缓冲器
StringBuffer::StringBuffer(int s)
:curOffset(0)
,size(s)
{
	buffer=new char[size];
}

//析构函数
StringBuffer::~StringBuffer()
{
	delete[] buffer;
}

//将字符串添加进缓冲器
void StringBuffer::Add(const char *str)
{
	//将字符串复制进缓冲器
	strcpy(&buffer[curOffset],str);
	//更新字符串的偏移量
	curOffset+=std::strlen(str)+1;
}

//判断给定字符串与指定的缓冲区字符串是否相同
//使用offsetString指定缓冲器中的字符串
bool StringBuffer::IsEqual(int offsetString,const char* str) const
{
	return std::strcmp(str,&buffer[offsetString])==0;
}

//实现符号表类
//构造函数
SymbolTable::SymbolTable(int size)
:curId(0)
,maxId(size)
,hashTable(size+1)
,stringBuffer(size*10)
{
	offsetString=new int[size+1];	
}

//析构函数
SymbolTable::~SymbolTable()
{
	delete[] offsetString;
}

//字符串添加进字符串缓冲器并添加映射，返回当前的字符串id
int SymbolTable::ForceAdd(const char *str, int len)
{
	if(curId==maxId || !stringBuffer.IsFit(len))
		return IDNOTFOUND;
	//指向字符串保存的地方
	offsetString[curId]=stringBuffer.GetCurrentOffset();
	stringBuffer.Add(str);
	//给哈希表添加映射
	hashTable.Add(str,curId);
	curId++;
	return curId-1;

}

//按字符串寻找id
int SymbolTable::Find(const char *str) const
{
	//从哈希表获得字符串id所在的短列表
	const List& list=hashTable.Find(str);
	//在此列表中寻找id
	for(const Link* pLink=list.GetHead();
		pLink;
		pLink=pLink->Next())
	{
		int id=pLink->Id();
		int offStr=offsetString[id];
		//若相同，返回
		if(stringBuffer.IsEqual(offStr,str))
			return id;
	}
	return IDNOTFOUND;
}

//通过id寻找缓冲器中的字符串
const char* SymbolTable::GetString(int id) const
{
	assert(id>=0);
	assert(id<curId);
	int offStr=offsetString[id];
	return stringBuffer.GetString(offStr);
}