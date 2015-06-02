//定义符号表SymbolTable类
#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_
#include "HashTable.h"

//定义字符串缓冲器，实质是一个字符串数组
class StringBuffer
{
public:
	//定义构造函数，初始化偏移量为0
	StringBuffer(int s);
	//析构函数
	~StringBuffer();
	//判断将要输入的字符串有没有足够的空间接收
	bool IsFit(int len) const
	{
		return (curOffset+len+1)<size;
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
	//定义缓冲器的空间
	int size;
	//定义字符串缓冲器指针
	char *buffer;
	//定义偏移量
	int curOffset;

};

//定义符号表类
//定义表示未找到id的常量值
const int IDNOTFOUND=-1;
class SymbolTable
{
public:
	//构造与析构函数
	explicit SymbolTable(int size);
	~SymbolTable();
	//增加元素并建立映射
	int ForceAdd(const char* str, int len);
	//寻找给定字符串在缓冲器中的位置
	int	Find(const char* str) const;
	//字符串在缓冲区中的位置，返回字符串
	const char* GetString(int id) const;
private:
	//定义哈希表
	HashTable hashTable;
	//缓冲器中存储的字符串数量最大值
	int maxId;
	//存储字符串偏移值的数组
	int *offsetString;
	//当前字符串id
	int curId;
	//字符串缓冲器
	StringBuffer stringBuffer;
};
#endif