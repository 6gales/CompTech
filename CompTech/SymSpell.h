#pragma once
#include <vector>
#include "Interface.h"
#include "Levinsthein.h"

class SymSpell : public SpellChecker
{
	std::vector <std::string> originals;
	std::multimap <std::string, std::pair <size_t, size_t>> generated;

	void generateDeletions(const std::string &, size_t, std::map <std::string, size_t> &);

	void fillDeletionsMap(const std::string &, size_t);

public:
	SymSpell(const char *name);

	std::multimap <size_t, std::string> checkWord(const std::string &);
};