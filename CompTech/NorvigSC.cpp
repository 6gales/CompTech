#include "NorvigSC.h"
#include <sstream>
#include <fstream>

void NorvigSC::edit1(const std::string &word, std::multimap<std::string, int>& syntactic_variants, int edit_distance)
{
	for (int i = 0; i < word.size(); i++) {
		syntactic_variants.insert({ word.substr(0, i) + word.substr(i + 1), edit_distance });
	}
	for (int i = 0; i < word.size() - 1; i++) {
		syntactic_variants.insert({ word.substr(0, i) + word[i + 1] + word[i] + word.substr(i + 2), edit_distance });
	}
	for (char ch = '�'; ch <= '�'; ch++) {
		for (int i = 0; i < word.size(); i++) {
			syntactic_variants.insert({word.substr(0, i) + ch + word.substr(i + 1), edit_distance});
		}
		for (int i = 0; i < word.size() + 1; i++) {
			syntactic_variants.insert({ word.substr(0, i) + ch + word.substr(i), edit_distance });
		}
	}
}

void NorvigSC::edits(const std::string& word, std::multimap<std::string, int>& syntactic_variants, int edit_distance) {
	if (edit_distance == 1) {
		edit1(word, syntactic_variants, edit_distance);
	}
	else {
		edits(word, syntactic_variants, edit_distance - 1);
		std::multimap<std::string, int> sub_syntactic_variants = syntactic_variants;
		for (auto it = sub_syntactic_variants.begin(); it != sub_syntactic_variants.end(); it++) {
			edit1(it->first, syntactic_variants, edit_distance);
		}
	}
}

void NorvigSC::known(const std::string& word, std::map<std::string, int>& semantic_variants) {

	std::multimap<std::string, int> syntactic_variants;
	edits(word, syntactic_variants, editDistance);  
	syntactic_variants.insert({ word, 0 });

	for (int i = 0; i < dic.size(); i++) {
		auto it = syntactic_variants.find(dic[i]);
		if (it != syntactic_variants.end()) {
			semantic_variants[it->first] = it->second;
		}
	}
}

NorvigSC::NorvigSC(const char* name) : SpellChecker(name)
{
	std::string str;
	std::string word;
	while (std::getline(dictionary, str))
	{
		std::istringstream line(str);
		while (line >> word)
		{
			dic.push_back(word);	//��������� ������ �������
		}
	}
}

std::multimap<size_t, std::string> NorvigSC::checkWord(const std::string& word)
{
	std::multimap<size_t, std::string> result;
	std::map<std::string, int> semantic_variants;

	known(word, semantic_variants);
	
	for (auto it = semantic_variants.begin(); it != semantic_variants.end(); it++) {
		result.insert({ it->second, it->first });
	}
	return result;
}




