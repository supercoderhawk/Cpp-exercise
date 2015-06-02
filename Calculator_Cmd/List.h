//List.h 定义存储整数链表结构的类
#ifndef LIST_H_
#define LIST_H_

#ifndef _IOSTREAM_H
#include <iostream>
#endif
//定义链表单元类
class Link
{
public:
	//链表单元的构造函数
	Link(Link* pNext,int nId):next(pNext),id(nId){}
	//析构函数
	~Link(){delete next;}
	//获得指向下一个链表单元的指针
	Link* Next() const {return next;}
	int Id() const {return id;}
private:
	//链表的整型数据
	int id;
	//指向下一个链表成员的指针
	Link* next;

};

//定义存储整数单链表结构类
class List
{
public:
	//构造函数
	List():head(0){}
	//析构函数，使用递归法清除链表
	~List(){delete head;};
	//添加链表元素
	void Add(int id);
	//获得链表的头指针
	const Link* GetHead() const{return head;}
private:
	//定义链表的头指针
	Link* head;

};
#endif