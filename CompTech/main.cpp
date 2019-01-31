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
	string dictionary_path = argv[1];
	NGramm_Spell_Checker sp(dictionary_path.c_str());
	while (stdin) {
		string input_word;
		cin >> input_word;
		std::multimap <size_t, std::string> result = sp.checkWord(input_word);

		for (auto i : result) {
			cout << i.second << endl;
		}
		cout << "end" << endl;
	}
	
	return 0;
}