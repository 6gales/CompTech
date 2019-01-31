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
	while (stdin) {
		string input_word;
		cin >> input_word;
		NGramm_Spell_Checker sp("n-gramm_dictionary.txt");
		std::multimap <size_t, std::string> result = sp.checkWord(input_word);

		for (auto i : result) {
			cout << i.second << endl;
		}
		cout << "end" << endl;
	}
	

	system("pause");
	return 0;
}