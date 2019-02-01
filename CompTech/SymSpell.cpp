#include "SymSpell.h"

void SymSpell::fillDeletionsMap(const std::string &word, size_t pos)
{
	editDistance = editDistFormula(word.size());

	generateDeletions(word, editDistance,
		[this](const std::string &word, size_t dist, size_t pos) mutable
		{
			auto inserted = generated.insert({ word, {} });
			inserted.first->second.emplace_front(dist, pos);
		}, pos);
}

SymSpell::SymSpell(const char *name) : SpellChecker(name)
{
	editDistFormula = [](size_t sz) -> size_t
	{ size_t ret = sz / 2 + sz % 2; if (ret > 2) return 2; return ret; };

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
	generateDeletions(word, editDistance,
		[&deletions](const std::string &word, size_t distance) mutable
		{
			deletions.insert({ word, distance });
		});

	std::map <std::string, size_t> reverseSuggestions;
	for (auto del : deletions)
	{
		auto fnd = generated.find(del.first);
		
		if (fnd == generated.end())
			continue;
		
		for (auto it = fnd->second.begin(); it != fnd->second.end(); ++it)
		{
			if (it->first <= editDistance)
			{
				size_t priority = (it->first > del.second ? it->first : del.second);
				auto insrtRes = reverseSuggestions.emplace(originals[it->second], priority);
					//.insert({ originals[fnd->second[i].second], priority });
				if (priority < insrtRes.first->second)
					insrtRes.first->second = priority;
			}
		}
	}

	std::multimap<size_t, std::string> suggestions;
	for (auto i : reverseSuggestions)
		suggestions.insert({ i.second, i.first });

	return suggestions;
}
