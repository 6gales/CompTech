#include "n-gramm_alphabet_order.h"
map<string, vector<string>> create_empty_dictionary(size_t n_gr) {
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

	string str;
	if (n_gr >= 3)
		str = "ààà";
	else
		str = "àà";
	for (size_t i = 0; i < alphabet.size(); ++i) {
		for (size_t j = 0; j < alphabet.size(); ++j) {
			if (n_gr >= 3) {
				for (size_t k = 0; k < alphabet.size(); ++k) {
					res.insert(make_pair(str, vector<string>()));
					str[2] = alphabet[k];
				}
				str[2] = 'à';
			}
			else {
				res.insert(make_pair(str, vector<string>()));
			}
			str[1] = alphabet[j];
		}
		str[1] = 'à';
		str[0] = alphabet[i];
	}
	return res;
}

void write_alphabet(string input, string output, size_t n_gr) {
	ifstream in;
	in.open(input);
	map<string, vector<string>> ngramm_dictionary = create_empty_dictionary(n_gr);
	while (in.eof() == false) {
		string word;
		in >> word;
		if (word.length() >= n_gr) {
			for (size_t i = 0; i < word.length() - n_gr + 1; ++i) {
				string ngraph = word.substr(i, n_gr);
				ngramm_dictionary.find(ngraph)->second.push_back(word);
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