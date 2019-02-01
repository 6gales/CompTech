#include <iostream>
#include <windows.h>
#include "SymSpell.h"
#include <ctime>

int main(int argc, char** argv)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	auto start = clock();
	SpellChecker *sp = new SymSpell("alphabet_order.txt");
	std::cout << (double)(clock() - start) / CLOCKS_PER_SEC << std::endl;
	
	for (size_t i = 0; i < 5; i++)
	{
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
	}

	return 0;
}