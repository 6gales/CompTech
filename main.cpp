#include <iostream>
#include <windows.h>
#include "BruteForce.h"

int main(int argc, char** argv)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	SpellChecker *sp = new BruteForce("relevance_order.txt");

	std::string source;
	std::cin >> source;

	auto suggestions = sp->checkWord(source);
	{
		for (auto i : suggestions)
		{
			std::cout << i.first << ": \"" << i.second << "\"" << std::endl;
		}
		if (!suggestions.size())
			std::cout << "Word not found." << std::endl;
	}
	
	return 0;
}