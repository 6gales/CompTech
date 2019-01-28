#include "BruteForce.h"

std::multimap <size_t, std::string> BruteForce::checkWord(const std::string &source)
{
	const size_t upperBound = formula(source.size());
	std::string tmp;

	std::multimap <size_t, std::string> suggestions;

	while (dictionary.good())
	{
		dictionary >> tmp;
		size_t dist = LevensteinDistance(source, tmp);

		if (dist <= upperBound)
			suggestions.insert({ dist, tmp });
	}

	return suggestions;
}