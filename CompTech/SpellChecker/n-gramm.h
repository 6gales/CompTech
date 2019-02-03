#pragma once
#include <map>
#include <set>
#include <string>
#include <vector>
#include <fstream>
#include "Interface.h"

class NGramm_Spell_Checker : public SpellChecker {
	std::map <std::string, std::set <std::string>> read_dictionary(std::ifstream& in);
	std::map <std::string, std::set <std::string>> ngramm_dictionary;
	size_t n_gr;
public:
	NGramm_Spell_Checker(const char* name, size_t n_gr) : SpellChecker(name) {
		this->ngramm_dictionary = read_dictionary(this->dictionary);
		this->n_gr = n_gr;
	}
	virtual std::multimap <size_t, std::string> checkWord(const std::string &);
	void write_dictionary(std::map <std::string, std::set <std::string>> ngramm_dictionary);
	virtual ~NGramm_Spell_Checker() {}
};