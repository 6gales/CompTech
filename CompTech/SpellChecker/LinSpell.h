#pragma once
#include <list>
#include "Interface.h"
#include "Levenshtein.h"

class LinSpell : public SpellChecker
{
private:
	const static size_t alphabet_power = 33;
	std::map<size_t, std::list<std::string>> dic;

	size_t hash(const std::string&) const;
	void edits(const std::string&, std::multimap<size_t, std::string>&);

public:
	LinSpell(const char*);

	virtual std::multimap<size_t, std::string> checkWord(const std::string&) override;
};