#include "LinSpell.h"
#include <sstream>

size_t LinSpell::hash(const std::string& str) const
{
	size_t hash_value = 0;
	for (int i = 0; i < str.size(); i++) {
		hash_value += static_cast<unsigned char>(str[i]) - static_cast<unsigned char>('à') + 1;
	}
	return hash_value;
}

void LinSpell::edits(const std::string& word, std::multimap<size_t, std::string>& variants)
{
	size_t min_hash, max_hash;
	size_t delta = alphabet_power * editDistance;
	size_t word_hash = hash(word);

	if (word_hash <= delta)
		min_hash = 0;
	else 
		min_hash = word_hash - delta;

	if (delta + word_hash >= dic.size())
		max_hash = dic.size() - 1;
	else 
		max_hash = word_hash + delta;

	for (size_t i = min_hash; i <= max_hash; i++) {
		for (auto it = dic[i].begin(); it != dic[i].end(); it++) {
			if (std::abs(static_cast<int>(word.size() - (*it).size())) > editDistance)
				continue;

			size_t distance = LevensteinDistance(word, *it);
			if (distance <= editDistance)
				variants.insert({ distance, *it });
		}
	}
}

LinSpell::LinSpell(const char* name) : SpellChecker(name)
{
	std::string str;
	while (dictionary.good())
	{
		dictionary >> str;

		size_t hash_value = hash(str);
		dic[hash_value].push_back(str);
	}
}

std::multimap<size_t, std::string> LinSpell::checkWord(const std::string &word)
{
	std::multimap<size_t, std::string> variants;

	edits(word, variants);

	return variants;
}

