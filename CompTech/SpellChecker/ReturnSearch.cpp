#include "ReturnSearch.h"

std::multimap<size_t, std::string> ReturnSearch::checkWord(const std::string &source)
{
	editDistance = editDistFormula(source.size());

	Solution resolve{ source };
	const TNode *curr = wordTree.getHead();

	recursiveSearch(curr, resolve);

	return resolve.getSuggestions();
}

void ReturnSearch::recursiveSearch(const TNode *curr, Solution &resolve)
{
	if (editDistance < resolve.getDistance() && editDistance < resolve.currentSize())
	{
		--resolve;
		return;
	}
	if (resolve.getDistance() <= editDistance && curr->isFinal())
		resolve.addWord();

	for (size_t i = 0; i < std::numeric_limits<unsigned char>::max() + 1; i++)
	{
		if (curr->getNext(static_cast<unsigned char>(i)))
		{
			resolve += static_cast<unsigned char>(i);
			recursiveSearch(curr->getNext(static_cast<unsigned char>(i)), resolve);
		}
	}
	--resolve;
}