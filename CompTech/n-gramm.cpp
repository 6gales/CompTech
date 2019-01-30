#include "n-gramm.h"
#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

map<string, vector<string>> NGramm_Spell_Checker::read_dictionary(ifstream& in) {
	map<string, vector<string>> res;
	while (in.eof() == false) {
		string trigraph;
		in >> trigraph;
		//cout << trigraph << endl;
		vector<string> list;
		while (in.eof() == false
) {
			string word;
			in >> word;
			if (word == "end") {
				break;
			}
			list.push_back(word);
			//cout << word << " ";
		}
		//cout << endl;
		res.insert(make_pair(trigraph, list));
	}
	return res;
}

void NGramm_Spell_Checker::write_dictionary(ofstream& out, map<string, vector<string>> ngramm_dictionary) {
	for (auto i : ngramm_dictionary) {
		cout << i.first << endl;
		for (auto j : i.second) {
			cout << j << " ";
		}
		cout << endl << "end" << endl;
	}
}

std::multimap<size_t, std::string> NGramm_Spell_Checker::checkWord(const std::string &) {

}