#include <iostream>
#include <windows.h>
#include "test.h"
#include "generatingDataSet.h"
#include <time.h>
#include <string>

std::string getName(std::string name)
{
	std::string result = name;
	size_t flag = result.rfind('\\');
	if(flag == std::string::npos)
	{
		return name;
	}

	result = result.substr(flag + 1, result.size());
	size_t flag2 = result.rfind('.');
	if (flag2 == std::string::npos)
	{
		return result;
	}

	return result.substr(0, flag2);
}

int main(int argc, char** argv)
{	
	srand(time(NULL));

	if (argc < 2) 
	{
		return 1;
	}

	std::string name(argv[1]);

	std::cout << getName(name) + "test.txt" << std::endl;

	//system("pause");
	return 0;


	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}


/*
std::string source;
std::cin >> source;
SpellChecker* sp = new NorvigSC("alphabet_order.txt");
sp->setDistance(3);
auto suggestions = sp->checkWord(source);
{
	for (auto i : suggestions)
	{
		std::cout << i.first << ": \"" << i.second << "\"" << std::endl;
	}
	if (!suggestions.size())
		std::cout << "Word not found." << std::endl;
}
*/

//for (int i = 64; i <= 127; ++i) {
//	std::cout << (int)i << ' ' << (char)i << std::endl;
//}
//std::cout << (int)'À' << std::endl;
//std::cout << (int)'ß' << std::endl;
//std::cout << (int)'à' << std::endl << (int)'ÿ' << std::endl;
//corruptData("input.txt", "incorrect.txt");
//std::cout << 'ÿ' - 'À' + 1 << std::endl;


	//std::string source;
	//std::cin >> source;


	//auto suggestions = sp->checkWord(source);
	//{
	//	for (auto i : suggestions)
	//	{
	//		std::cout << i.first << ": \"" << i.second << "\"" << std::endl;
	//	}
	//	if (!suggestions.size())
	//		std::cout << "Word not found." << std::endl;
	//}