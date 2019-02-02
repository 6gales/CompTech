#include "Trie.h"

Trie::Trie(std::istream &is)
{
	head = new TNode{ false };
	std::string tmp;
	while (is.good())
	{
		is >> tmp;
		insert(tmp);
	}
}

void Trie::insert(const std::string &word)
{
	TNode *ptr = head;
	for (size_t i = 0; i < word.size(); i++)
	{
		if (ptr->getNext(word[i]))
		{
			ptr = ptr->getNext(word[i]);
			if (i == word.size() - 1)
				ptr->setFinite(true);
		}
		else
		{
			ptr->create(word[i], i == word.size() - 1);
			ptr = ptr->getNext(word[i]);
		}
	}
}