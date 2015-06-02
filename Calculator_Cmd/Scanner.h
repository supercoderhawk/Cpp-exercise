//扫描器定义文件
#ifndef SCANNER_H_
#define SCANNER_H_
#include <assert.h>
//使用枚举定义记号列表
enum Token
{
	End,		//结束
	Error,		//错误
	Number,		//数字
	Plus,		//加号+
	Minus,		//减号-
	Mult,		//乘号*
	Divide,		//除号/
	LParen,		//左括号
	RParen,		//右括号
	Assign,		//赋值运算符=
	Ident		//标识符

};

//定义标识符的最大长度
const int MAXSYMBOLLEN=8;

//定义扫描器类
//扫描器
class Scanner
{
public:
	//构造与析构函数
	Scanner(char *buf);
	~Scanner(){}
	//获得当前的记号
	Token GetToken(){return token;}
	//识别字符串中的字符
	void Accept();
	//获得识别到的数字
	double GetNumber()
	{
		//记号为数字时才返回，否则抛异常
		assert(token==Number);
		return number;
	}
	//获得解析得到的标识符及其长度，通过输入的指针和引用返回
	void GetSymbolName(char* strOut, int& len);
private:
	//需要解析的缓冲器字符串
	char* buffer;
	//清除输入缓冲器中的空格
	void EatWhite();
	//跟踪索引
	int look;
	//记号
	Token token;
	//解析得到的数字值
	double number;
	//标识符长度
	int symbolLength;
	//标识符在缓冲器中的位置
	int symbolIndex;
};

#endif