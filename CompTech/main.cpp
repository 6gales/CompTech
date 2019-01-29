#include <iostream>
#include <windows.h>
#include "ReturnSearch.h"

int main(int argc, char** argv)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	SpellChecker *sp = new ReturnSearch("relevance_order.txt");

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
	
	delete sp;

	return 0;
}