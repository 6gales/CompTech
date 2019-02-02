#include <iostream>
#include <windows.h>
#include "NorvigTrie.h"

int main(int argc, char** argv)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string dictionary_path = "alphabet_order.txt";
	if (argc >= 2)
	{
		dictionary_path = argv[1];
	}

	NorvigTrie sp(dictionary_path.c_str());
	while (stdin)
	{
		std::string input_word;
		std::cin >> input_word;
		std::multimap <size_t, std::string> result = sp.checkWord(input_word);
		size_t counter = 0;
		for (auto i : result)
		{
			if (counter >= 5) break;
			std::cout << i.second << std::endl;
			counter++;
		}
		std::cout << "end" << std::endl;
	}
	return 0;
}