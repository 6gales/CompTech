#pragma once
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include "Interface.h"
using namespace std;

class NGramm_Spell_Checker : public SpellChecker {
	map<string, vector<string>> read_dictionary(ifstream& in);
	map<string, vector<string>> NGramm_Dictionary;
public:
	NGramm_Spell_Checker(const char* name) : SpellChecker(name) { this->NGramm_Dictionary = read_dictionary(this->dictionary); }
	virtual std::multimap <size_t, std::string> checkWord(const std::string &);
	void write_dictionary(ofstream& out, map<string, vector<string>> ngramm_dictionary);
	virtual ~NGramm_Spell_Checker() {}
};