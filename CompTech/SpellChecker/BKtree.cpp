#include "BKtree.h"

inline size_t subKeeping0(size_t a, size_t b)
{
	if (a < b)
		return 0;
	return a - b;
}

void BKNode::addWord(const std::string &newWord)
{
	size_t currentDistance = LevenshteinDistance(word, newWord);
	auto it = next.find(currentDistance);
	if (it != next.end())
	{
		it->second->addWord(newWord);
	}
	else next.insert({ currentDistance, new BKNode{ newWord } });
}

void BKNode::findWord(const std::string &target, const size_t &editDistance,
	std::multimap<size_t, std::string> &suggestions)
{
	size_t currentDistance = LevenshteinDistance(word, target);

	if (currentDistance <= editDistance)
		suggestions.insert({ currentDistance, word });

	std::pair <size_t, size_t> inRange
		= { subKeeping0(currentDistance, editDistance), currentDistance + editDistance };

	for (auto it = next.begin(); it != next.end(); ++it)
	{
		if (it->first > inRange.second)
			break;

		if (it->first >= inRange.first)
			it->second->findWord(target, editDistance, suggestions);
	}
}

BKtree::BKtree(const char *name) : SpellChecker(name)
{
	std::string word;
	dictionary >> word;
	head = new BKNode{ word };
	while (dictionary.good())
	{
		dictionary >> word;
		head->addWord(word);
	}
}

std::multimap<size_t, std::string> BKtree::checkWord(const std::string &word)
{
	std::multimap<size_t, std::string> suggestions;
	editDistance = editDistFormula(word.size());

	head->findWord(word, editDistance, suggestions);

	return suggestions;
}