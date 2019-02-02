#pragma once
#include <set>
#include <vector>
#include "Interface.h"

class NorvigSC : public SpellChecker {
	private:

		std::set <std::string> dict;

		std::map<std::string, size_t> editWord(const std::string &, size_t);
		std::vector <std::map <std::string, size_t>> edits(const std::string &);
		
	public:
		NorvigSC(const char*);

		virtual std::multimap<size_t, std::string> checkWord(const std::string &) override;
	};

