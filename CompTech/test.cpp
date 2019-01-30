//#include <iostream>
//#include "test.h"
//#include <time.h>
//
//SpellChecker* getImplementation(IMPL impl, const char* dict)
//{
//	switch (impl)
//	{
//	case BRUTE:  return new BruteForce(dict);
//	case TRIE: return new ReturnSearch(dict);
//	case NORVIG:return new NorvigSC(dict);
//	default: return nullptr;
//	}
//}
//
//double testing(SpellChecker* sc, std::vector<std::string> correct, std::vector<std::string> incorrect, std::ofstream & out, int step)
//{
//	int begin, end;
//	while (true)
//	{
//		begin = rand() % correct.size();
//		end = begin + step;
//		if (end < correct.size())
//		{
//			break;
//		}
//	}
//	long long t1, t2;
//	t1 = clock();
//	for (int i = 0; i < step; ++i)
//	{
//		std::string sourse = incorrect[begin + i];
//		std::string answer = correct[begin + i];
//		std::multimap <size_t, std::string> suggestions = sc->checkWord(sourse);
//		int counter = 0;
//
//		if (suggestions.empty()) 
//		{
//			//out << sourse << ";" << "not found" << ";" << answer << ";0" << std::endl;
//			continue;
//		}
//
//		for (auto j : suggestions)
//		{
//			if (counter != 5 && j.second == answer)
//			{
//				//out << sourse << ";" << j.second << ";" << answer << ";1" << std::endl;
//				break;
//			}
//			++counter;
//		}
//
//		if (counter == 5) 
//		{
//			//out << sourse << ";" << "not found" << ";" << answer << ";0" << std::endl;
//			continue;
//		}
//
//	}
//	t2 = clock();
//	return (double(t2 - t1)) / ((double)step);
//}
//
//void test(const char* dictionary, const char* correct_sourse, const char* incorrect_sourse, const char* output, IMPL impl)
//{
//	SpellChecker *sc = getImplementation(impl, dictionary);
//
//	std::ofstream out("test1.txt");
//	std::ifstream cor(correct_sourse),
//		incor(incorrect_sourse);
//	std::vector<std::string> correct,
//		incorrect;
//
//	std::string tmp;
//	while (cor.good())
//	{
//		cor >> tmp;
//		correct.push_back(tmp);
//	}
//
//	while (incor.good())
//	{
//		incor >> tmp;
//		incorrect.push_back(tmp);
//
//	}
//
//	std::cout << correct.size() << ' ' << incorrect.size() << std::endl;
//
//	for (int step = 10; step <= 100; step += step / 2)
//	{
//		out << "STEP SIZE = " << step << ";";
//		out << testing(sc, correct, incorrect, out, step) << std::endl;
//	}
//}