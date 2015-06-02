//HashTable.h的实现文件
//实现哈希表利用哈希函数添加映射和查找字符串的功能
#include"HashTable.h"
#include <assert.h>

//哈希函数定义
int HashTable::Hash(char const *str) const
{
	//若字符串为空，发出警告
	assert(str!=NULL && str[0]!=0);
	unsigned h=str[0];
	//进行左移
	for (int i=1;str[i];i++)
		h=(h<<4)+str[i];
	//求余，保证求得的数据在List的范围内
	return h%LISTSIZE;
}

//添加字符串到整数的映射
void HashTable::Add(const char *str, int id)
{
	//进行哈希变换，获得索引
	int i=Hash(str);
	shortList[i].Add(id);

}

//得到字符串所在的短列表链表
const List& HashTable::Find(const char *str) const
{
	//获得索引
	int i=Hash(str);
	return shortList[i];
}
