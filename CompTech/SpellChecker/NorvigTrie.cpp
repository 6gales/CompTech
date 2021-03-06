#include "NorvigTrie.h"

std::map<std::string, size_t> NorvigTrie::editWord(const std::string &word, size_t currDistance)
{
	std::map<std::string, size_t> generated;

	for (size_t i = 0; i < word.size(); i++)
	{
		generated.insert({ word.substr(0, i) + word.substr(i + 1), currDistance });
	}
	for (size_t i = 0; i < word.size() - 1; i++)
	{
		generated.insert({ word.substr(0, i) + word[i + 1] + word[i] + word.substr(i + 2), currDistance });
	}
	for (char ch = '�'; ch <= '�'; ch++)
	{
		for (size_t i = 0; i < word.size(); i++)
		{
			generated.insert({ word.substr(0, i) + ch + word.substr(i + 1), currDistance });
		}
		for (size_t i = 0; i < word.size() + 1; i++)
		{
			generated.insert({ word.substr(0, i) + ch + word.substr(i), currDistance });
		}
	}

	return generated;
}

std::vector <std::map <std::string, size_t>> NorvigTrie::edits(const std::string& word)
{
	std::vector <std::map <std::string, size_t>> editLevel(editDistance + 1);
	editLevel[0].emplace(word, 0);

	for (size_t i = 1; i <= editDistance; i++)
	{
		for (auto it : editLevel[i - 1])
		{
			auto nextLevel = editWord(it.first, editDistance);
			editLevel[i].insert(nextLevel.begin(), nextLevel.end());
		}
	}
	return editLevel;
}

std::multimap<size_t, std::string> NorvigTrie::checkWord(const std::string &word)
{
	editDistance = 1;

	auto generated = edits(word);

	std::multimap<size_t, std::string> suggestions;

	for (auto vecIt : generated)
	{
		for (auto mapIt : vecIt)
		{
			if (wordTree.findWord(mapIt.first))
				suggestions.emplace(mapIt.second, mapIt.first);
		}
	}

	return suggestions;
}