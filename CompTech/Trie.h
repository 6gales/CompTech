#pragma once
#include <iostream>
#include <vector>
#include <limits>
#include <string>

#undef max

class TNode
{
	
	bool finite;
	std::vector <TNode*> next;
//	std::map <char, TNode*> next;

public:
	TNode(bool _f) : finite{ _f },
		next{ std::numeric_limits<unsigned char>::max() + 1, nullptr } {}

	bool isFinal() const { return finite; }
	void setFinite(bool fin) { finite = fin; }

	TNode *getNext(unsigned char ch) { return next[ch]; }
	const TNode *getNext(unsigned char ch) const { return next[ch]; }
	TNode *getNext(char ch) { return next[static_cast<unsigned char>(ch)]; }
	const TNode *getNext(char ch) const { return next[static_cast<unsigned char>(ch)]; }


	void create(unsigned char ch, bool fin) { next[ch] = new TNode{ fin }; }
	void create(char ch, bool fin) { next[static_cast<unsigned char>(ch)] = new TNode{ fin }; }

	~TNode() { for (auto i : next) { delete i; i = nullptr; } }

	void dfs(std::string &str)
	{
		if (finite) std::cout << str << std::endl;

		for (size_t i = 0; i < next.size(); i++)
		{
			if (next[i])
			{
				str += static_cast<unsigned char>(i);
				next[i]->dfs(str);
				str.pop_back();
			}
		}
	}
};

class Trie
{
	TNode * head = nullptr;
public:
	Trie() { head = new TNode{ false }; }
	Trie(std::istream &);
	void insert(const std::string &);
	~Trie() { delete head; head = nullptr; }

	void initDfs()
	{
		std::string str;
		head->dfs(str);
	}
};

//
////void createString(std::string &creature)
////{
////	creature.resize(rand() % 30);
////	for (size_t k = 0; k < creature.size(); k++)
////	{
////		creature[k] = static_cast<char>(rand() % 255 - 128);
////	}
////}
////
////std::string createString()
////{
////	std::string creature;
////	creature.resize(rand() % 30);
////	for (size_t k = 0; k < creature.size(); k++)
////	{
////		creature[k] = static_cast<char>(rand() % 255 - 128);
////	}
////	return creature;
////}
//
//std::vector <std::string> generateVector(size_t size)
//{
//	std::vector <std::string> res;
//	for (size_t i = 0; i < size; i++)
//	{
//		res.push_back(createString());
//	}
//	return res;
//}
//
//#include <ctime>
//void checkTime(std::vector <std::string> &data,
//	size_t func(const std::string&, const std::string&))
//{
//	double fTimeStart = clock() / (double)CLOCKS_PER_SEC;
//	for (size_t i = 0; i < data.size() - 1; i++)
//	{
//		func(data[i], data[i + 1]);
//	}
//	double fTimeStop = clock() / (double)CLOCKS_PER_SEC;
//	std::cout << "Duration %d: " << fTimeStop - fTimeStart << std::endl;
//}
//
//bool wordSearch(std::ifstream &dictionary, const std::string &source,
//	std::multimap <size_t, std::string> &suggestions)
//{
//	const size_t upperBound = source.size() / 2 + source.size() % 2;
//	std::string tmp;
//	while (dictionary.good())
//	{
//		dictionary >> tmp;
//		size_t dist = LevensteinDistance(source, tmp);
//
//		if (!dist) return true;
//
//		if (dist <= upperBound)
//			suggestions.insert({ dist, tmp });
//	}
//	return false;
//}
//

//#include "Trie.h"
//int main()
//{
//	SetConsoleOutputCP(1251);
//	std::ifstream ifs("alphabet_order.txt");
//	Trie tree(ifs);
//	tree.initDfs();
//	return 0;
//}