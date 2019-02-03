# CompTech
Winter school project directed to find whether there is a mistake in word or not, also trying to suggest probable corrections.

## Implemented alghorithms
Each alghorithm has it's own branch in the project.
Master branch is summing up all of them into one useful library.

### Brute Force
Linear pass throug the dictionary counting Levenshtein distance for each word.

### Trie
First we build prefix tree from dictionary, then, to find particullar word we use dfs, going as deep, as we can, while distance from current word to source word can decrease.

### Norvig alghorithm
The main idea is to generate all possible variants of source word at a given distance and searching them for O(log(N))
[Link to original article] (https://norvig.com/spell-correct.html)

### Trie using Norvig
Combination of generating each possible variant using Norvig and searching for them using Trie (search in O(k), k is word lenght)

### BK-tree
Dictionary is a tree, where each vertex is a word for which each subtree is a set of words with the same Levenshtein distance to a word from the root.
The search uses the triangle inequality: only those subtrees are considered, where the distance from the word to the root is in the interval:
[current e.d. - maximum e.d., currnet e.d. + maximum e.d.]

### SymSpell
New dictionary is builded from original, including all possible deletions in range of edit distance.
After generating all possible deletions from source word and finding one of them in new dictionary we can suggesy that source word could be mentioned as original word from dictionary.

### LinSpell
Improved BruteForce alghorithm using hashes for dictionary.

### N-Gramm
First generating sets of N-gramms for each word from dictionary, same for source word. After intersecating sets of n-gramms we can suggest, that word with higher number of intersecations is the 
mentioned one.


### Test results

####Name	Average time per word, s.	Chance, %.
```
BruteForce	0,0576212		92,804
		
Trie		0,0124044		86,645
		
Norvig		0,127461		88,41

Norvig 
1 edit distance	0,00032357		83,133
		
NorvigTrie	0,118838		88,69

NorvigTrie
1 edit distance	0,00024381		83,061
		
BK-tree		0,0212679		87,891
		
LinSpell	0,024703		87,786
		
SymSpell	0,00032758		88,139
		
n-gramm linear	0,00156387		63,134

n-gramm		0,0102204		70,034
intersec		
```
