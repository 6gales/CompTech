#include <iostream>
#include <fstream>
#include <map>
#include <windows.h>
#include "Levinsthein.h"

bool wordSearch(std::ifstream &dictionary, const std::string &source,
	std::multimap <size_t, std::string> &suggestions)
{
	const size_t upperBound = source.size() / 2 + source.size() % 2;
	std::string tmp;
	while (dictionary.good())
	{
		dictionary >> tmp;
		size_t dist = LevensteinDistance(source, tmp);

		if (!dist) return true;

		if (dist <= upperBound)
			suggestions.insert({ dist, tmp });
	}
	return false;
}

int main(int argc, char** argv)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream dictionary("dictionary.txt");
	std::string source;
	std::multimap <size_t, std::string> suggestions;
	
	std::cin >> source;

	if (wordSearch(dictionary, source, suggestions))
	{
		std::cout << "Alright!" << std::endl;
	}
	else
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