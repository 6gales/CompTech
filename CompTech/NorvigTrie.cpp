#include "NorvigTrie.h"

void edit(const std::string &word,
	std::map<std::string, size_t> &syntactic_variants, size_t edit_distance)
{
	for (int i = 0; i < word.size(); i++)
	{
		syntactic_variants.insert({ word.substr(0, i) + word.substr(i + 1), edit_distance });
	}
	for (int i = 0; i < word.size() - 1; i++)
	{
		syntactic_variants.insert({ word.substr(0, i) + word[i + 1] + word[i] + word.substr(i + 2), edit_distance });
	}
	for (char ch = 'à'; ch <= 'ÿ'; ch++)
	{
		for (int i = 0; i < word.size(); i++)
		{
			syntactic_variants.insert({ word.substr(0, i) + ch + word.substr(i + 1), edit_distance });
		}
		for (int i = 0; i < word.size() + 1; i++)
		{
			syntactic_variants.insert({ word.substr(0, i) + ch + word.substr(i), edit_distance });
		}
	}
}

void edits(const std::string& word,
	std::map<std::string, size_t> &syntactic_variants, size_t edit_distance)
{
	if (edit_distance == 1)
	{
		edit(word, syntactic_variants, edit_distance);
	}
	else
	{
		edits(word, syntactic_variants, edit_distance - 1);
		std::map<std::string, size_t> sub_syntactic_variants = syntactic_variants;
		for (auto it = sub_syntactic_variants.begin(); it != sub_syntactic_variants.end(); it++)
		{
			edit(it->first, syntactic_variants, edit_distance);
		}
	}
}

std::multimap<size_t, std::string> NorvigTrie::checkWord(const std::string &word)
{
	editDistance = 1; editDistFormula(word.size());

	std::map <std::string, size_t> generated;
	edits(word, generated, editDistance);

	std::multimap<size_t, std::string> suggestions;

	for (auto i : generated)
	{
		if (wordTree.findWord(i.first))
			suggestions.emplace(i.second, i.first);
	}

	return suggestions;
}



//void known(const std::string& word, std::map<std::string, int>& semantic_variants)
//{
//
//	std::multimap<std::string, size_t> syntactic_variants;
//	syntactic_variants.insert({ word, 0 });
//	edits(word, syntactic_variants, editDistance);
//
//	for (int i = 0; i < dic.size(); i++) {
//		auto it = syntactic_variants.find(dic[i]);
//		if (it != syntactic_variants.end()) {
//			semantic_variants[it->first] = it->second;
//		}
//	}
//}