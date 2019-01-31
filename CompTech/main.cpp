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
	string ordered_dict_path = "alphabet_order.txt";
	if (argc >= 2) {
		ordered_dict_path = argv[1];
	}
	string dictionary_path = "n-gramm_dictionary.txt";

	read_alphabet(ordered_dict_path, dictionary_path);

	NGramm_Spell_Checker sp(dictionary_path.c_str());
	while (stdin) {
		string input_word;
		cin >> input_word;
		std::multimap <size_t, std::string> result = sp.checkWord(input_word);
		size_t counter = 0;
		for (auto i : result) {
			if (counter >= 5) break;
			cout << i.second << endl;
			counter++;
		}
		cout << "end" << endl;
	}
	
	return 0;
}