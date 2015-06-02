//HashTable.h
//定义哈希表类，哈希表数据结构是基于使用表查找来加速任意映射而实现的
#ifndef LIST_H_
#include "List.h"
#endif

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

class HashTable
{
public:
	//构造与析构函数
	explicit HashTable(int s);
	~HashTable();
	//返回字符串所在的短列表
	const List& Find(const char* str) const;
	//添加string->ID的映射
	void Add(const char* str, int id);
private:
	
	//哈希短列表的数量
	int size;
	//定义哈希函数
	int Hash(const char* str) const;
	//定义短列表
	List *shortList;

};
#endif