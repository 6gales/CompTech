#include "n-gramm.h"
#include "Levinsthein.h"

#include <map>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

map<string, set<string>> NGramm_Spell_Checker::read_dictionary(ifstream& in) {
	map<string, set<string>> res;
	while (in.eof() == false) {
		string trigraph;
		in >> trigraph;
		set<string> list;
		while (in.eof() == false
) {
			string word;
			in >> word;
			if (word == "end") {
				break;
			}
			list.insert(word);
		}
		res.insert(make_pair(trigraph, list));
	}
	return res;
}

void NGramm_Spell_Checker::write_dictionary(ofstream& out, map<string, set<string>> ngramm_dictionary) {
	for (auto i : ngramm_dictionary) {
		cout << i.first << endl;
		for (auto j : i.second) {
			cout << j << " ";
		}
		cout << endl << "end" << endl;
	}
}

std::vector<std::set<std::string>> intersect_sets(std::vector<std::set<std::string>> match_lists, int shift) {
	if (match_lists.size() == 1) return match_lists;
	if (match_lists.size() - shift - 2 <= 0) return match_lists;
	std::set<std::string> tmp;
	std::set_intersection(
		match_lists[match_lists.size() - shift - 2].begin(), match_lists[match_lists.size() - shift - 2].end(), 
		match_lists[match_lists.size() - shift - 1].begin(), match_lists[match_lists.size() - shift - 1].end(),
		std::inserter(tmp, tmp.begin()));
	if (tmp.empty()) return intersect_sets(match_lists, shift + 1);
	match_lists.pop_back();
	match_lists.pop_back();
	match_lists.push_back(tmp);
	return intersect_sets(match_lists, shift);
}

std::set<std::string> intersect(std::vector<std::set<std::string>> match_lists) {

	if (match_lists.size() == 1) return match_lists[0];
	if (match_lists.size() == 0) return std::set<std::string>();

	std::set<std::string> result;
	std::set<std::string> buffer;

	set_intersection(
		match_lists[0].begin(), match_lists[0].end(),
		match_lists[1].begin(), match_lists[1].end(),
		std::inserter(result, result.begin()));

	vector<std::set<std::string>> i_skipped_lists;


	for (size_t i = 2; i < match_lists.size(); i++) {
		buffer.clear();

		set_intersection(
			result.begin(), result.end(),
			match_lists[i].begin(), match_lists[i].end(),
			std::inserter(buffer, buffer.begin()));

		if (buffer.empty()) { 
			i_skipped_lists.push_back(match_lists[i]);
			continue;
		}

		swap(result, buffer);
	}
	if (i_skipped_lists.size() > 1) {
		std::set<std::string> tmp = intersect(i_skipped_lists);
		result.insert(tmp.begin(), tmp.end());
	}
	return result;
}

std::multimap<size_t, std::string> NGramm_Spell_Checker::checkWord(const std::string & word) {
	if (word.length() >= 3) {
		std::vector<std::set<std::string>> match_lists;
		for (size_t i = 0; i < word.length() - 2; ++i) {
			string trigraph = word.substr(i, 3);
			match_lists.push_back(ngramm_dictionary.find(trigraph)->second);
		}

		
		std::set<std::string> intersect_result = intersect(match_lists);
		std::multimap<size_t, std::string> result;
		for (size_t i = 0; i < 5; ++i) {
			auto min = make_pair<size_t, std::string>(99999999, "no word");
			for (auto j : intersect_result) {
				size_t dist = LevensteinDistance(word, j);
				if (dist < min.first) {
					min.first = dist;
					min.second = j;
				}
			}
			if (min.first < word.length() * 10) {
				result.insert(min);
				intersect_result.erase(min.second);
			}
		}
		return result;
	}
	return std::multimap<size_t, std::string>();
}