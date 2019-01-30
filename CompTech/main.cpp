#include <iostream>
#include <windows.h>
#include "test.h"
#include "generatingDataSet.h"
#include <time.h>
#include <string>

std::string getName(std::string name)
{
	std::string result = name;

}

int main(int argc, char** argv)
{	
	srand(time(NULL));

	if (argc < 2) 
	{
		return 1;
	}

	std::string name(argv[1]);





	//test("relevance_order.txt", "input.txt", "incorrect.txt", "test1.txt", BRUTE);

	system("pause");
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