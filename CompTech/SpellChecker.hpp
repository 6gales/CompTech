#pragma once
#include "SpellChecker/BruteForce.h"
#include "SpellChecker/ReturnSearch.h"
#include "SpellChecker/NorvigSC.h"
#include "SpellChecker/NorvigTrie.h"
#include "SpellChecker/BKtree.h"
#include "SpellChecker/LinSpell.h"
#include "SpellChecker/SymSpell.h"
#include "SpellChecker/n-gramm.h"
#include "SpellChecker/n-gramm_linear.h"

enum SPELL_MODE
{
	BRUTE_FORCE,
	RETURN_SEARCH,
	NORVIG,
	NORVIG_TRIE,
	BK_TREE,
	LIN_SPELL,
	SYM_SPELL,
	N_GRAMM,
	N_GRAMM_LIN
};

SpellChecker *getImplementation(SPELL_MODE mode, const char *dictionary)
{
	switch (mode)
	{
	case BRUTE_FORCE: return new BruteForce(dictionary);
	
	case RETURN_SEARCH: return new ReturnSearch(dictionary);
	
	case NORVIG: return new NorvigSC(dictionary);
	
	case NORVIG_TRIE: return new NorvigTrie(dictionary);
		
	case BK_TREE: return new BKtree(dictionary);
	
	case LIN_SPELL: return new LinSpell(dictionary);
	
	case SYM_SPELL: return new SymSpell(dictionary);
	
	case N_GRAMM: return new BruteForce(dictionary);
	
	case N_GRAMM_LIN: return new BruteForce(dictionary);
	}
}