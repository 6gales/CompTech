#pragma once
#include <string>
#include <vector>
#include <algorithm>

size_t D(size_t i, size_t j, const std::string &source, const std::string &target)
{
	if (i == 0)
		return j;
	if (j == 0)
		return i;
	return std::min(D(i, j - 1, source, target) + 1,
		std::min(D(i - 1, j, source, target) + 1,
			D(i - 1, j - 1, source, target) + (source[i] != target[j])));
}

size_t LevenstheinDistanceRec(const std::string &source, const std::string &target)
{
	std::string s = ' ' + source,
		t = ' ' + target;

	return D(s.size(), t.size(), s, t);
}

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
				lev_dist[i] = std::min(std::min(lev_dist[i - 1], lev_dist[i]),
					previous_diagonal) + 1;
			}
			previous_diagonal = previous_diagonal_save;
		}
	}
	return lev_dist[min_size];
}