#pragma once
#include <string>
#include <vector>
#include <algorithm>

size_t LevensteinDistance(const std::string &source, const std::string &target);

class injection
{
	const std::string source;
	std::string target;

	size_t distance;// = t.size - num_mapping + s.size - num_mapping
	
	std::vector <std::pair <bool, size_t>> mapping;
	size_t nextEdge;
	std::vector <std::pair <size_t, size_t>> pretendents;
//	std::vector <void> a;

	void countDistance();
	void conflict(size_t place, size_t candidat); //call when mapping is crossing

public:
	injection(const std::string &_src, const std::string &_trgt) : source{ _src },
		target{ _trgt }, mapping{ source.size(), {false, 0} }, nextEdge{ 0 } {}

	const injection &operator+=(unsigned char);


};