//定义字符串缓冲器与字符串表
#ifndef STRINGTABLE_H_
#define STRINGTABLE_H_
#include "HashTable.h"  

//定义字符串缓冲器，实质是一个字符串数组
//声明缓冲器最大接收的字符数
const int MAXBUFSIZE=500;
class StringBuffer
{
public:
	//构造函数，初始化偏移量为0
	StringBuffer():curOffset(0){}
	//析构函数
	~StringBuffer(){}
	//判断将要输入的字符串有没有足够的空间接收
	bool IsFit(int len) const
	{
		return (curOffset+len+1)<MAXBUFSIZE;
	}
	//向缓冲器中加入字符串
	void Add(const char* str);
	//获得当前的偏移量
	int GetCurrentOffset() const {return curOffset;}
	//判断给定的字符串与缓冲器中指定字符串是否相同
	//使用offsetString指定缓冲器中的字符串
	bool IsEqual(int offseString, const char* str) const;
	//获得缓冲器中指定位置的字符串
	const char*  GetString(int offsetString) const
	{return &buffer[offsetString];}
private:
	//定义字符串缓冲器
	char buffer[MAXBUFSIZE];
	//定义偏移量
	int curOffset;

};

//定义字符串表StringTable类
//字符串表的类功能是建立字符串与整数之间的相互映射关系
//定义未找到的值
const int NOTFOUND=-1;
//定义字符串最大数量
const int MAXSTRINGS=100;

class StringTable
{
public:
	//构造函数与析构函数
	StringTable():curId(0){}
	~StringTable(){}
	//向字符串缓冲器中添加字符串并建立映射
	int ForceAdd(const char* str);
	//寻找所给的字符串在缓冲器中的位置
	int Find(const char* str) const;
	//通过位置id获得缓冲器中的字符串
	const char* GetString(int id) const;
private:
	//字符串->整数的实现类
	HashTable hashTable;
	//每个字符串的偏移量数组
	int offsetString[MAXSTRINGS];
	//当前的字符串id值
	int curId;
	//字符串缓冲器
	StringBuffer stringBuffer;

};

#endif