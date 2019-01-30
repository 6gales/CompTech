#include "Levinsthein.h"

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

const injection &injection::operator+=(unsigned char ch)
{
	size_t currentPos = target.size();
	target += ch;
	bool inject = false;

	for (size_t i = nextEdge; i < source.size() && !inject; i++)
	{
		if (target[currentPos] == source[i])
		{
			mapping[i] = { true, i };
			nextEdge = i + 1;
			inject = true;
		}
	}

	for (int i = nextEdge - 1; i >= 0 && !inject; i--)
	{
		if (target[currentPos] == source[i])
		{
			conflict(i, currentPos);
		}
	}

	countDistance();
	return *this;
}

void injection::countDistance()
{
	size_t i = 0;
	while (!mapping[i].first && i < mapping.size())
		i++;

	distance = mapping[i].second + mapping[nextEdge - 1].second - nextEdge + 1
		+ (mapping[nextEdge - 1].second - mapping[i].second);
}

void injection::conflict(size_t place, size_t candidat)
{

}