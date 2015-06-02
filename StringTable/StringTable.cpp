//缓冲器类与字符串表类的实现文件
#include "StringTable.h"
#ifndef _IOSTREAM_
#include<iostream>
#endif
#include<assert.h>

//缓冲器类StringBuffer的实现
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

//字符串表类StringTable的实现
//向字符串缓冲器中添加字符串并建立映射
int StringTable::ForceAdd(const char* str)
{
	//判断缓冲器空间是够足够容纳字符串
	int len=std::strlen(str);
	if(curId==MAXSTRINGS || !stringBuffer.IsFit(len))
	{
		return NOTFOUND;
	}

	//空间足够，先保存偏移量，再保存字符串
	offsetString[curId]=stringBuffer.GetCurrentOffset();
	stringBuffer.Add(str);
	//添加映射
	hashTable.Add(str,curId);
	curId++;
	return curId-1;
}

//在缓冲器中寻找字符串
int StringTable::Find(const char *str) const
{
	//获得哈希表中该字符串的短列表
	const List& list=hashTable.Find(str);
	//遍历链表，在此链表中找到字符串，返回在缓冲器中的id
	for(const Link* pLink=list.GetHead();
		pLink;
		pLink=pLink->Next())
	{
		//获得缓冲区中的id
		int id=pLink->Id();
		//获得对应的偏移量
		int offStr=offsetString[id];
		//使用缓冲器中的比较函数进行比较，若找到，返回id
		if(stringBuffer.IsEqual(offStr,str))
			return id;
		
	}
	//列表为空，即找不到，返回未找到
	return NOTFOUND;
}

const char* StringTable::GetString(int id) const
{
	//如果id不在范围内，抛异常
	assert(id>=0);
	assert(id<curId);
	//获得偏移量
	int offStr=offsetString[id];
	return stringBuffer.GetString(offStr);
}