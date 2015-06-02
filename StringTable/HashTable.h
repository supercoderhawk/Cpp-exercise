//HashTable.h
//定义哈希表类，哈希表数据结构是基于使用表查找来加速任意映射而实现的
#ifndef LIST_H_
#include "List.h"
#endif

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

//定义哈希表列表短列表的最大个数
const int LISTSIZE=127;
class HashTable
{
public:
	//返回字符串所在的短列表
	const List& Find(const char* str) const;
	//添加string->ID的映射
	void Add(const char* str, int id);
private:
	
	
	//定义哈希函数
	int Hash(const char* str) const;
	//定义短列表
	List shortList[LISTSIZE];  

};
#endif