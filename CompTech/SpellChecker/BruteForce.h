#pragma once
#include "Interface.h"
#include "Levenshtein.h"

class BruteForce : public SpellChecker
{
public:
	BruteForce(const char *name) : SpellChecker(name) {}

	std::multimap <size_t, std::string> checkWord(const std::string &);
};