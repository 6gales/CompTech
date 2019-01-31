#pragma once
#include <map>
#include <set>
#include <string>
#include <vector>
#include <fstream>
#include "Interface.h"
using namespace std;

class NGramm_Spell_Checker : public SpellChecker {
	map<string, set<string>> read_dictionary(ifstream& in);
	map<string, set<string>> ngramm_dictionary;
public:
	NGramm_Spell_Checker(const char* name) : SpellChecker(name) { this->ngramm_dictionary = read_dictionary(this->dictionary); }
	virtual std::multimap <size_t, std::string> checkWord(const std::string &);
	void write_dictionary(ofstream& out, map<string, set<string>> ngramm_dictionary);
	virtual ~NGramm_Spell_Checker() {}
};