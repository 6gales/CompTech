#include <iostream>
#include <windows.h>
#include <string>
#include "n-gramm_alphabet_order.h"
#include "n-gramm.h"

using namespace std;



int main(int argc, char** argv)
{	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string usual_dictionary_path = "alphabet_order.txt";

	size_t three_gr = 3;
	string three_gr_dictionary_path = to_string(three_gr) + "-gramm_dictionary.txt";
	write_alphabet("alphabet_order.txt", three_gr_dictionary_path, three_gr);
	
	size_t two_gr = 2;
	string two_gr_dictionary_path = to_string(two_gr) + "-gramm_dictionary.txt";
	write_alphabet("alphabet_order.txt", two_gr_dictionary_path, two_gr);

	if (argc >= 2) {
		usual_dictionary_path = argv[1];
	}

	NGramm_Spell_Checker two_gr_sp(two_gr_dictionary_path.c_str(), two_gr);
	NGramm_Spell_Checker three_gr_sp(three_gr_dictionary_path.c_str(), three_gr);

	while (stdin) {
		string input_word;
		cin >> input_word;
		std::multimap <size_t, std::string> result;
		if (input_word.length() <= 11) {
			result = two_gr_sp.checkWord(input_word);
		}
		else {
			result = three_gr_sp.checkWord(input_word);
		}

		for (auto i : result) {
			cout << i.second << endl;
		}
		cout << "end" << endl;
	}
	
	return 0;
}