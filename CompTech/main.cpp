#include <iostream>
#include <windows.h>
#include "SymSpell.h"
#include <ctime>

int main(int argc, char** argv)
{	
	srand(time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	SpellChecker *sp = new SymSpell("alphabet_order.txt");

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
	system("pause");
	return 0;
}