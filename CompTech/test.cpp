#include <iostream>
#include "test.h"

SpellChecker* getImplementation(IMPL impl, const char* dict)
{
	switch (impl)
	{
	case BRUTE:  return new BruteForce(dict);
	case TRIE:
	case NORVIG:
	default: return nullptr;
	}
}

void testing(SpellChecker* sc, std::vector<std::string> correct, std::vector<std::string> incorrect, std::ofstream & out, int step)
{
	int begin, end;
	while (true)
	{
		begin = rand() % correct.size();
		end = begin + step;
		if (end < correct.size())
		{
			break;
		}
	}

	for (int i = 0; i < step; ++i)
	{
		std::string sourse = incorrect[begin + i];
		std::string answer = correct[begin + i];
		std::multimap <size_t, std::string> suggestions = sc->checkWord(sourse);
		int counter = 0;

		for (auto j : suggestions)
		{
			if (counter != 5 && j.second == answer)
			{
				out << sourse << ";" << j.second << ";" << answer << ";1" << std::endl;
			}
			++counter;
		}

		out << sourse << ";" << "not found" << ";" << answer << ";0" << std::endl;
	}
}

void test(const char* dictionary, const char* correct_sourse, const char* incorrect_sourse, const char* output, IMPL impl)
{
	SpellChecker *sc = getImplementation(impl, dictionary);

	std::ofstream out("test1.txt");
	std::ifstream cor(correct_sourse),
		incor(incorrect_sourse);
	std::vector<std::string> correct,
		incorrect;

	std::string tmp;
	while (cor.good())
	{
		cor >> tmp;
		correct.push_back(tmp);
	}

	while (incor.good())
	{
		incor >> tmp;
		incorrect.push_back(tmp);

	}

	std::cout << correct.size() << ' ' << incorrect.size() << std::endl;

	for (int step = 10; step <= 10; step += step / 2)
	{
		std::cout << "step =" << step << std::endl;
		out << "STEP SIZE = " << step << ";" << std::endl;
		testing(sc, correct, incorrect, out, step);
	}
}