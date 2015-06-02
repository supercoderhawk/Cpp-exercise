//º∆À„∆˜≤‚ ‘÷˜≥Ã–Ú
const int maxBuf=100;
const int maxSymbols=40;
#ifndef PARSER_H_
#include "Parser.h"
#endif

#include "Scanner.h"
#include "SymbolTable.h"
#include "Store.h"
#ifndef TREE_H_
#include "Tree.h"
#endif
#include "FunctionTable.h"

#ifndef FUNCTIONARRAY_H_
#include "FunctionArray.h"
#endif


int main()
{
	char buf[maxBuf];
	Status status;
	SymbolTable symTab(maxSymbols);
	FunctionTable funTab(symTab,funArr);
	Store store(maxSymbols,symTab);
	do
	{
		std::cout<<">";
		std::cin.getline(buf,maxBuf);
		Scanner scanner(buf);
		Parser parser(scanner,store,funTab,symTab);
		status=parser.Eval();
	}while(status!=stQuit);

	return 0;
}