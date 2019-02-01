#pragma once
#include "Interface.h"
#include <vector>

	class NorvigSC : public SpellChecker {
	private:

		std::vector<std::string> dic;

		void edit1(const std::string&, std::multimap<std::string, int>&, size_t);
		void edits(const std::string&, std::multimap<std::string, int>&, size_t);
		void known(const std::string&, std::map<std::string, int>&);

	public:
		NorvigSC(const char*);

		virtual std::multimap<size_t, std::string> checkWord(const std::string &) override;
	};

