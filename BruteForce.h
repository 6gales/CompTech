#pragma once
#include "Interface.h"
#include "Levinsthein.h"

class BruteForce : public SpellChecker
{	
public:
	std::multimap <size_t, std::string> checkWord(const std::string &);
};