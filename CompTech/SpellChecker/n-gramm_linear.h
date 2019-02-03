#pragma once
#include <map>
#include <set>
#include <string>
#include <vector>
#include <fstream>
#include "Interface.h"

class NGramm_Linear_Spell_Checker : public SpellChecker {
	std::map <std::string, std::set <std::string>> read_dictionary(std::ifstream& in);
	std::map<std::string, std::set<std::string>> ngramm_dictionary;
public:
	NGramm_Linear_Spell_Checker(const char* name) : SpellChecker(name) { this->ngramm_dictionary = read_dictionary(this->dictionary); }
	virtual std::multimap <size_t, std::string> checkWord(const std::string &);
	void write_dictionary(std::ofstream& out, std::map<std::string, std::set<std::string>> ngramm_dictionary);
	virtual ~NGramm_Linear_Spell_Checker() {}
};