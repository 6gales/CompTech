#include "SymSpell.h"

void SymSpell::fillDeletionsMap(const std::string &word, size_t pos)
{
	editDistance = editDistFormula(word.size());

	std::map <std::string, size_t> toInsert;
	generateDeletions(word, editDistance, toInsert);

	for (auto it : toInsert)
		generated.insert({ it.first, { it.second, pos } });
}

void SymSpell::generateDeletions(const std::string &word,
	size_t distance, std::map <std::string, size_t> &deletions)
{
	deletions.insert({ word, editDistance - distance });

	if (!distance || word.size() <= 1)
		return;

	std::string wDeletion;
	for (size_t i = 0; i < word.size(); i++)
	{
		wDeletion = word;
		wDeletion.erase(wDeletion.begin() + i);
		generateDeletions(wDeletion, distance - 1, deletions);
	}
}

SymSpell::SymSpell(const char *name) : SpellChecker(name)
{
	editDistFormula = editDistFormula = [](size_t sz) -> size_t
	{ if (sz / 2 + sz % 2 >= 2) return 2; return 1; };

	std::string word;
	while (dictionary.good())
	{
		dictionary >> word;
		originals.push_back(word);
		fillDeletionsMap(word, originals.size() - 1);
	}
}

std::multimap<size_t, std::string> SymSpell::checkWord(const std::string &word)
{
	editDistance = editDistFormula(word.size());

	std::map <std::string, size_t> deletions;
	generateDeletions(word, editDistance, deletions);

	std::map <std::string, size_t> reverseSuggestions;
	for (auto i : deletions)
	{
		for (auto fnd = generated.find(i.first); fnd != generated.end(); ++fnd)
		{
			if (fnd->first != i.first)
				break;

			if (fnd->second.first <= editDistance)
			{
				size_t priority = (fnd->second.first > i.second ? fnd->second.first : i.second);
				auto it = reverseSuggestions.insert({ originals[fnd->second.second], priority });
				if (priority < it.first->second)
					it.first->second = priority;
			}
		}
	}

	std::multimap<size_t, std::string> suggestions;
	for (auto i : reverseSuggestions)
		suggestions.insert({ LevenshteinDistance(i.first, word), i.first });

	return suggestions;
}