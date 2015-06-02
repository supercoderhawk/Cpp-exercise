//List.cpp--List.h的实现文件，实现链表类的功能
#include "List.h"

void List::Add(int id)
{
	//将链表元素添加到列表头
	Link* pLink=new Link(head,id);
	head=pLink;
}

