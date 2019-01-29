#pragma once
#include "Interface.h"
#include "Trie.h"
#include <stack>
class ReturnSearch : public SpellChecker
{
	Trie wordTree;
public:
	ReturnSearch(const char *name) : SpellChecker(name), wordTree(dictionary) {}

	std::multimap <size_t, std::string> checkWord(const std::string &);
};