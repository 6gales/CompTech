#pragma once
#include <string>
#include <map>
#include "Interface.h"
#include "Levenshtein.h"

inline size_t subKeeping0(size_t a, size_t b);

class BKNode
{
	const std::string word;
	std::map <size_t, BKNode*> next;

public:
	BKNode(const std::string &_word) : word{ _word } {}

	void addWord(const std::string &);

	void findWord(const std::string &, const size_t &,
		std::multimap <size_t, std::string> &);

	~BKNode() { for (auto i : next) delete i.second; }
};

class BKtree : public SpellChecker
{
	BKNode *head = nullptr;
public:
	BKtree(const char *name);

	std::multimap <size_t, std::string> checkWord(const std::string &);

	~BKtree() { delete head; head = nullptr; }
};