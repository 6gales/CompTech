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
};

class Trie
{
	TNode * head = nullptr;
public:
	Trie() { head = new TNode{ false }; }
	Trie(std::istream &);
	void insert(const std::string &);
	~Trie() { delete head; head = nullptr; }

	bool findWord(const std::string &) const;

	const TNode *getHead() const { return head; }
};