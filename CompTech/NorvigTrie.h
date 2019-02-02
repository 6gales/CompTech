#pragma once
#include "Interface.h"
#include "Trie.h"

class NorvigTrie : public SpellChecker
{
	Trie wordTree;

public:
	NorvigTrie(const char *name) : SpellChecker(name), wordTree(dictionary) {}

	std::multimap <size_t, std::string> checkWord(const std::string &);

//	void recursiveSearch(const TNode *curr, Solution &resolve);
};