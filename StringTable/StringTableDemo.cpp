//测试字符串表的功能的main函数
#ifndef _IOSTREAM_
#include<iostream>
#endif

#ifndef LIST_H_ 
#include "List.h"
#endif

#ifndef HASHTABLE_H_
#include "HashTable.h"
#endif

#ifndef STRINGTABLE_H_
#include "StringTable.h"
#endif

int main(int argc,char* argu)
{
	//定义字符串表
	StringTable stringTable;
	//将字符串加入缓冲器并建立映射
	stringTable.ForceAdd("One");
	stringTable.ForceAdd("Two");
	stringTable.ForceAdd("Three");
	//通过字符串寻找id
	int id=stringTable.Find("One");
	//输出id
	std::cout<<"One at "<<id<<std::endl;
	//通过id寻找字符串
	std::cout<<"String 0 is "<<stringTable.GetString(0)<<std::endl;
	return 0;
}

