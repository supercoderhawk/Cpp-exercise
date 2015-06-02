//扫描器Scanner类的实现文件
#include "Scanner.h"
#ifndef _IOSTREAM_
#include <iostream>
#include <ctype.h>
#endif
#include<assert.h>

//Scanner构造函数
Scanner::Scanner(char* buf):buffer(buf),look(0)
{
	Accept();
}
//清除输入缓冲器中的空格
void Scanner::EatWhite()
{
	for (int i=0;i<std::strlen(buffer);i++)
		if(isspace(buffer[i]))
			for(int j=i;j<strlen(buffer);j++)
				buffer[j]=buffer[j+1];
}

//识别字符串中的字符
void Scanner::Accept()
{
	//清除缓冲器字符串中的空格
	EatWhite();
	//识别字符的类型
	switch(buffer[look])
	{
	//识别出加号
	case '+':
		token=Plus;
		look++;
		break;
	//识别出减号
	case '-':
		token=Minus;
		look++;
		break;
	//识别出乘号
	case '*':
		token=Mult;
		look++;
		break;
	//识别出除号
	case '/':
		token=Divide;
		look++;
		break;
	//识别出数字
	case '0':case '1':case '2':case '3':case '4':
	case '5':case '6':case '7':case '8':case '9':
	case '.':
	{
		token=Number;
		char *p;
		//获得字符串中的浮点数与其后的第一个未识别字符串的指针
		//指针p被函数strtod初始化
		number=std::strtod(&buffer[look],&p);
		//更新跟踪索引
		look=p-buffer;
		break;
	}
	//识别出标识符或者错误
	default:
	//识别是否为标识符，标识符命名按C++规定，首字符必须为字母、下划线
	//标识符只能由字母数字下划线组成,最大长度为MAXSYMBOLLEN
	//首字符符合要求
	if(isalpha(buffer[look]) || buffer[look]=='_')
	{
		token=Ident;
		//记录位置索引
		symbolIndex=look;
		//提取出标识符
		int slook;
		do 
		{
			look++;
			//记录标识符中的字符，用于判断是否结束
			slook=buffer[look];
		}while(isalnum(slook) || slook=='_');
		//计算标识符的长度
		symbolLength=look-symbolIndex;
		if(symbolLength>=MAXSYMBOLLEN)
			symbolLength=MAXSYMBOLLEN-1;

	}
	//如果不是标识符，那么就是错误的输入
	else
		token=Error;
	break;
	}
}
//获得解析得到的标识符及其长度，通过输入的指针和引用返回
void Scanner::GetSymbolName(char* strOut, int& len)
{
	//确保给定的len大于标识符长度，保证空间足够
	assert(len>=MAXSYMBOLLEN);
	assert(symbolLength<=MAXSYMBOLLEN);
	//标识符的赋值
	std::strncpy(strOut,&buffer[symbolIndex],symbolLength);
	strOut[symbolLength]='\0';
	len=symbolLength;
}