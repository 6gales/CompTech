#include <iostream>
#include <windows.h>
//#include "BruteForce.h"
#include "test.h"
#include "generatingDataSet.h"
#include <time.h>

int main(int argc, char** argv)
{	
	srand(time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//for (int i = 64; i <= 127; ++i) {
	//	std::cout << (int)i << ' ' << (char)i << std::endl;
	//}
	//std::cout << (int)'�' << std::endl;
	//std::cout << (int)'�' << std::endl;
	//std::cout << (int)'�' << std::endl << (int)'�' << std::endl;
	//corruptData("input.txt", "incorrect.txt");
	//std::cout << '�' - '�' + 1 << std::endl;
	test("relevance_order.txt", "input.txt", "incorrect.txt", "test1.txt", BRUTE);

	//std::string source;
	//std::cin >> source;

	//auto suggestions = sp->checkWord(source);
	//{
	//	for (auto i : suggestions)
	//	{
	//		std::cout << i.first << ": \"" << i.second << "\"" << std::endl;
	//	}
	//	if (!suggestions.size())
	//		std::cout << "Word not found." << std::endl;
	//}
	system("pause");
	return 0;
}