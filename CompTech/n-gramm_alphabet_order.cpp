#include "n-gramm_alphabet_order.h"
map<string, vector<string>> create_empty_dictionary() {
	vector<char> alphabet =
	{
		'à', 'á', 'â', 'ã', 'ä',
		'å', '¸', 'æ', 'ç', 'è',
		'é', 'ê', 'ë', 'ì', 'í',
		'î', 'ï', 'ð', 'ñ', 'ò',
		'ó', 'ô', 'õ', 'ö', '÷',
		'ø', 'ù', 'ú', 'û', 'ü',
		'ý', 'þ', 'ÿ', ' '
	};
	map<string, vector<string>> res;
	string str = "ààà";
	for (size_t i = 0; i < alphabet.size(); ++i) {
		for (size_t j = 0; j < alphabet.size(); ++j) {
			for (size_t k = 0; k < alphabet.size(); ++k) {
				res.insert(make_pair(str, vector<string>()));
				str[2] = alphabet[k];
			}
			str[2] = 'à';
			str[1] = alphabet[j];
		}
		str[1] = 'à';
		str[0] = alphabet[i];
	}
	return res;
}

void read_alphabet(string input, string output) {
	ifstream in;
	in.open(input);
	map<string, vector<string>> ngramm_dictionary = create_empty_dictionary();
	while (in.eof() == false) {
		string word;
		in >> word;
		if (word.length() >= 3) {
			for (size_t i = 0; i < word.length() - 2; ++i) {
				string trigraph = word.substr(i, 3);
				ngramm_dictionary.find(trigraph)->second.push_back(word);
			}
		}
	}
	ofstream out;
	out.open(output);
	for (auto i : ngramm_dictionary) {
		out << i.first << endl;
		for (auto j : i.second) {
			out << j << " ";
		}
		out << endl << "end" << endl;
	}
	in.close();
	out.close();
}