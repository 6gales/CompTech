#pragma once
#include "Interface.h"
#include "Trie.h"

class NorvigTrie : public SpellChecker
{
	Trie wordTree;

	std::map<std::string, size_t> editWord(const std::string &, size_t);
	std::vector <std::map <std::string, size_t>> edits(const std::string &);

public:
	NorvigTrie(const char *name) : SpellChecker(name), wordTree(dictionary)
	{
		editDistFormula = editDistFormula = [](size_t sz) -> size_t
		{ if (sz / 2 + sz % 2 >= 2) return 2; return 1; };
	}

	std::multimap <size_t, std::string> checkWord(const std::string &);
};