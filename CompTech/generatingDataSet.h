#pragma once
#include <fstream>
#include <vector>
#include <string>

void corruptData(const char* correct_source, const char* incorrect_source) 
{
	std::ifstream cor(correct_source);
	std::ofstream incor(incorrect_source);

	while (cor.good()) 
	{

		std::string buff;
		cor >> buff;
	
		size_t numOfChanges = rand() % (buff.size() / 2 + buff.size() % 2);
		for (int j = 0; j < numOfChanges; ++j) 
		{
			size_t position = rand() % buff.size();
			switch (rand() % 6)
			{
				case 0: // delete element
				{
					if (buff.size() == 1) 
					{
						break;
					}
					buff.erase(buff.begin() + position);
					break;
				}
				case 1: // add element
				{
					buff.insert(position, 1, static_cast<char>(rand() % 64 - 64 ));
					break;
				}
				case 2: // change element
				{
					buff[position] = static_cast<char>(rand() % 64 - 64);
					break;
				}
				default: {	break; }
			}
		}
	
		incor << buff << ' ';

	}
}