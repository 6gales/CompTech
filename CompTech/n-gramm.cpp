#include "n-gramm.h"
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
	std::set<std::string> result;
	std::set<std::string> buffer;

	set_intersection(
		match_lists[0].begin(), match_lists[0].end(),
		match_lists[1].begin(), match_lists[1].end(),
		std::inserter(result, result.begin()));

	for (size_t i = 2; i < match_lists.size(); i++) {
		buffer.clear();

		set_intersection(
			result.begin(), result.end(),
			match_lists[i].begin(), match_lists[i].end(),
			std::inserter(buffer, buffer.begin()));

		swap(result, buffer);
	}
	return result;
}

std::multimap<size_t, std::string> NGramm_Spell_Checker::checkWord(const std::string & word) { // TODO: словарь сделать картой строк-карт
	if (word.length() >= 3) {
		std::vector<std::set<std::string>> match_lists;
		for (size_t i = 0; i < word.length() - 2; ++i) {
			string trigraph = word.substr(i, 3);
			match_lists.push_back(ngramm_dictionary.find(trigraph)->second);
			//cout << trigraph << ": " << match_lists[match_lists.size() - 1].count("молоко") << endl;
			/*if (match_lists[match_lists.size()-1].count(word) > 0) {
				cout << trigraph << ": " << "found!" << endl;
			}
			else {
				cout << trigraph << ": " << "NOT found!" << endl;
			}*/
		}

		//---------------------------------------------------------------------------------
				
		//std::set<std::string> result = match_lists[0];
		//std::set<std::string> saved_result;


		//for (auto i : match_lists) {
		//	if (i == match_lists[0]) {
		//		continue;
		//	}
		//	std::set_intersection(result.begin(), result.end(), i.begin(), i.end(), std::inserter(saved_result, saved_result.begin()));
		//	cout << "//---------------------------------------//" << endl;
		//	/*if (result.empty()) {
		//		result = saved_result;
		//		break;
		//	}*/
		//	result.clear();
		//	result = saved_result;
		//	
		//}

		std::set<std::string> result = intersect(match_lists);
		for (auto i : result) {
			cout << i << endl;
		}

		//cout << result.count("молоко") << endl;

		/*for (auto i : match_lists) {
			if (i.count(word) > 0) {
				cout << 
			}
		}*/

		/*size_t i_min = 0;
		for (size_t i = 0; i < match_lists.size(); i++) {
			if (match_lists[i] < match_lists[i_min]) {
				i_min = i;
			}
		}
		std::map<std::string, size_t> matches;
		for (auto i : match_lists[i_min]) {
			matches.insert(make_pair(i, 0));
		}

		for (auto j : matches) {
			for (size_t i = 0; i < match_lists.size(); i++) {
				if (i != i_min) {
					j.second += match_lists[i].count(j.first);
				}
			}
		}
		for (auto i : matches) {
			cout << i.first << ": " << i.second << " matches" << endl;
		}*/
	}
	return std::multimap<size_t, std::string>();
}