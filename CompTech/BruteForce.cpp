#include "BruteForce.h"
#include "Levinsthein.h"

std::multimap <size_t, std::string> BruteForce::checkWord(const std::string &source)
{
	const size_t editDistance = editDistFormula(source.size());
	std::string tmp;

	std::multimap <size_t, std::string> suggestions;

	while (dictionary.good())
	{
		dictionary >> tmp;
		size_t dist = LevensteinDistance(source, tmp);

		if (dist <= editDistance)
			suggestions.insert({ dist, tmp });
	}

	dictionary.clear();
	dictionary.seekg(0, std::ios::beg);

	return suggestions;
}