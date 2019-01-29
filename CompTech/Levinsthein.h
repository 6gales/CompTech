#pragma once
#include <string>
#include <vector>
#include <algorithm>

template <class last>
auto minmax(last a, last b)
{
	if (a > b)
		return std::pair<last, last>(b, a);
	return std::pair<last, last>(a, b);
}

template <class first, class ... args>
auto minmax(first a, args ... params)
{
	auto tmp = minmax(params...);
	if (a > tmp.second)
		tmp.second = a;
	else if (a < tmp.first)
		tmp.first = a;
	return tmp;
}

class NFA
{

};

size_t prevDiff(const std::string &source, const std::string &target, size_t prevDist)
{

}

void LevenshteinAutomata(const std::string &source, const size_t editDistance)
{

	for (size_t i = 0; i < source.size(); i++)
	{
		for (size_t e = 0; e < editDistance + 1; e++)
		{

		}
	}
}

//size_t DLdistance(std::string a, std::string b, const size_t E = 255)
//{
//	std::vector <int> da(E, 0);
//	std::vector <int> d((a.size() + 2) * (b.size() + 2));
//	size_t maxdist = a.size() + b.size();
//	d[0] = maxdist;
//	for (size_t i = 0; i < a.size(); i++)
//	{
//		d[(i + 1) * a.size() - 1] = maxdist;
//		d[(i + 1) * a.size()] = i;
//		for (size_t j = 0; j < b.size(); j++)
//		{
//			d[j + 1] = maxdist;
//			d[(i + 1) * a.size() + j] = j;
//			for (size_t i = 1; i < a.size(); i++)
//			{
//				int db = 0;
//				for (size_t j = 1; j < b.size(); j++)
//				{
//					int k = da[b[j] + 1];
//					int	l = db;
//					int cost;
//					if (a[i] = b[j])
//					{
//						cost = 0;
//						db = j;
//					}
//					else int cost = 1;
//
//					d[(i + 1) * a.size() + j + 1] =
//						min<size_t>(min(d[(i)* a.size() + j] + cost,  //substitution
//							d[(i + 1) * a.size() + j] + 1),     //insertion
//							min(d[(i)* a.size() + j + 1] + 1,     //deletion
//							d[(k)* a.size() + l]
//							+ (i - k) + 1 + (j - l))); //transposition
//					da[a[i]] = i;
//				}
//			}
//		}
//	}
//	return d[d.size() - 1];
//}
//size_t D(size_t i, size_t j, const std::string &source, const std::string &target)
//{
//	if (i == 0)
//		return j;
//	if (j == 0)
//		return i;
//	return std::min(D(i, j - 1, source, target) + 1,
//		std::min(D(i - 1, j, source, target) + 1,
//			D(i - 1, j - 1, source, target) + (source[i] != target[j])));
//}
//
//size_t LevenstheinDistanceRec(const std::string &source, const std::string &target)
//{
//	std::string s = ' ' + source,
//		t = ' ' + target;
//
//	return D(s.size(), t.size(), s, t);
//}

size_t LevensteinDistance(const std::string &source, const std::string &target)
{
	if (source.size() > target.size())
	{
		return LevensteinDistance(target, source);
	}

	const size_t min_size = source.size(), max_size = target.size();
	std::vector<size_t> lev_dist(min_size + 1);

	for (size_t i = 0; i <= min_size; ++i)
	{
		lev_dist[i] = i;
	}

	for (size_t j = 1; j <= max_size; ++j)
	{
		size_t previous_diagonal = lev_dist[0], previous_diagonal_save;
		++lev_dist[0];

		for (size_t i = 1; i <= min_size; ++i)
		{
			previous_diagonal_save = lev_dist[i];
			if (source[i - 1] == target[j - 1])
			{
				lev_dist[i] = previous_diagonal;
			}
			else
			{
				lev_dist[i] = std::min<size_t>(std::min<size_t>(lev_dist[i - 1], lev_dist[i]),
					previous_diagonal) + 1;
			}
			previous_diagonal = previous_diagonal_save;
		}
	}
	return lev_dist[min_size];
}

//void createString(std::string &creature)
//{
//	creature.resize(rand() % 30);
//	for (size_t k = 0; k < creature.size(); k++)
//	{
//		creature[k] = static_cast<char>(rand() % 255 - 128);
//	}
//}
//
//std::string createString()
//{
//	std::string creature;
//	creature.resize(rand() % 30);
//	for (size_t k = 0; k < creature.size(); k++)
//	{
//		creature[k] = static_cast<char>(rand() % 255 - 128);
//	}
//	return creature;
//}
//
//bool distanceTest()
//{
//	std::string source = createString(),
//		target = source;
//	size_t diff = 0;
//	for (size_t i = 0; i < target.size(); i++)
//	{
//		switch (rand() % 5)
//		{
//		case 2:
//			target.erase(target.begin() + i);
//			diff++;
//			break;
//		case 3:
//			target.insert(i, 1, static_cast<char>(rand() % 255 - 128));
//			diff++;
//			break;
//		case 4:
//			target[i] = (rand() % 255 - 128);
//			diff++;
//			break;
//		}
//	}
//	return diff == LevensteinDistance(source, target);
//}