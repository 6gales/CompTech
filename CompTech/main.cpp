#include <iostream>
#include <windows.h>
#include "BruteForce.h"
#include "test.h"
#include "generatingDataSet.h"
#include "NorvigSC.h"
#include <time.h>

int main(int argc, char** argv)
{	
	srand(time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	
	test("relevance_order.txt", "input.txt", "incorrect.txt", "test1.txt", BRUTE);

	system("pause");
	return 0;
}