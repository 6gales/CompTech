#pragma once
#include "Interface.h"
#include "BruteForce.h"

enum  IMPL {BRUTE, TRIE, NORVIG};

SpellChecker* getImplementation(IMPL impl, const char* dict);
void testing(SpellChecker* sc, std::vector<std::string> correct, std::vector<std::string> incorrect, std::ofstream & out, int step);
void test(const char* dictionary, const char* correct_sourse, const char* incorrect_sourse, const char* output, IMPL impl);