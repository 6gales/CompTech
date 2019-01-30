#include <iostream>
#include <fstream>
#include <windows.h>
#include "BKtree.h"

#include <ctime>

int main(int argc, char** argv)
{	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	auto start = clock();
	SpellChecker *sp = new BKtree("relevance_order.txt");
	std::cout << (double)(clock() - start) / CLOCKS_PER_SEC << std::endl;
	std::string source;
	std::cin >> source;
	start = clock();
	auto suggestions = sp->checkWord(source);
	{
		std::cout << (double)(clock() - start) / CLOCKS_PER_SEC << std::endl;
		for (auto i : suggestions)
		{
			std::cout << i.first << ": \"" << i.second << "\"" << std::endl;
		}
		if (!suggestions.size())
			std::cout << "Word not found." << std::endl;
	}
	
	return 0;
}