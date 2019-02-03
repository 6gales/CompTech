#pragma once
#include <map>
#include <string>
#include <fstream>
#include <functional>

class SpellChecker
{
protected:
	std::ifstream dictionary;
	size_t editDistance;
	std::function <size_t(size_t)> editDistFormula = [](size_t sz) { return sz / 2 + sz % 2; };

public:
	SpellChecker(const char *name) { dictionary.open(name); }

	void setDistance(size_t ed) { editDistance = ed; }
	void setFormula(std::function <size_t(size_t)> f) { editDistFormula = f; }

	virtual std::multimap <size_t, std::string> checkWord(const std::string &) = 0;

	virtual ~SpellChecker() {}
};