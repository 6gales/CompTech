#pragma once
#include "Interface.h"
#include <vector>

	class NorvigSC : public SpellChecker {
	private:
		//std::map<std::string, int> freq_table;
		//void fillFreqTable(const char*);
		
		std::vector<std::string> dic;

		void edit1(const std::string&, std::multimap<std::string, int>&, int);
		void edits(const std::string&, std::multimap<std::string, int>&, int);
		void known(const std::string&, std::map<std::string, int>&);

	public:
		NorvigSC(const char*);

		virtual std::multimap<size_t, std::string> checkWord(const std::string &) override;
	};

