#pragma once
#include "Interface.h"
#include "Trie.h"
#include "Levenshtein.h"

class Solution
{
	size_t lastDistance;
	const std::string source;
	std::string word;
	std::multimap <size_t, std::string> suggestions;
public:
	Solution(const std::string &_s) :source(_s) {}
	const Solution &operator+=(unsigned char ch) { word += ch; lastDistance = LevenshteinDistance(source, word); return *this; }
	const Solution &operator--() { if (word.size()) word.pop_back(); return *this; }
	void addWord() { suggestions.insert({ lastDistance, word }); }

	size_t currentSize() const { return word.size(); }
	size_t getDistance() const { return lastDistance; }
	std::multimap <size_t, std::string> getSuggestions() const { return suggestions; }
};

class ReturnSearch : public SpellChecker
{
	Trie wordTree;

public:
	ReturnSearch(const char *name) : SpellChecker(name), wordTree(dictionary) {}

	std::multimap <size_t, std::string> checkWord(const std::string &);

	void recursiveSearch(const TNode *curr, Solution &resolve);
};