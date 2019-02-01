#pragma once
#include <forward_list>
#include <vector>
#include "Interface.h"

class SymSpell : public SpellChecker
{
	std::vector <std::string> originals;
	std::map <std::string, std::forward_list <std::pair <size_t, size_t>>> generated;

	template <class function, class ... args>
	void generateDeletions(const std::string &, size_t, function, args...);

	void fillDeletionsMap(const std::string &, size_t);

public:
	SymSpell(const char *name);

	std::multimap <size_t, std::string> checkWord(const std::string &);
};

template <class function, class ... args>
void SymSpell::generateDeletions(const std::string &word,
	size_t distance, function foo, args ... parameters)
{
	foo(word, editDistance - distance, parameters...);

	if (!distance || word.size() <= 1)
		return;

	std::string wDeletion;
	for (size_t i = 0; i < word.size(); i++)
	{
		wDeletion = word;
		wDeletion.erase(wDeletion.begin() + i);
		generateDeletions(wDeletion, distance - 1, foo, parameters...);
	}
}