#include <iostream>
//#include "test.h"
#include <time.h>
#include <string>
#include <boost/process.hpp>
#include <windows.h>

namespace bp = boost::process;


std::string getName(std::string name)
{

	std::string result = name;

	size_t flag2 = result.rfind('.');
	if (flag2 == std::string::npos)
	{
		return result;
	}

	result = result.substr(0, flag2);

	size_t flag = result.rfind('\\');
	if(flag == std::string::npos)
	{
		return result;
	}

	return result.substr(flag + 1, result.size());
}

std::vector<std::string> correct, incorrect;

void getExamples(const char* correct_source, const char* incorrect_source)
{
	std::ifstream cor(correct_source);
	std::ifstream incor(incorrect_source);

	std::string buff;
	while (cor.good())
	{
		cor >> buff;
		correct.push_back(buff);
	}
	while (incor.good())
	{
		incor >> buff;
		incorrect.push_back(buff);
	}
	cor.close();
	incor.close();
	return;
}


int main(int argc, char** argv)
{	
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if (argc < 4) 
	{
		return 1;
	}
	std::string name(argv[1]);
	std::ofstream output(getName(name) + "test.txt");
	std::cout << "Uploading test files... ";
	getExamples(argv[3], argv[4]);
	std::cout << "COMPLITED!" << std::endl;
	bp::ipstream pipe_out;
	bp::opstream pipe_in;
	//std::cout << "1.2" << std::endl;
	bp::child c(argv[1], argv[2], bp::std_in < pipe_in, bp::std_out > pipe_out);
	//bp::child c(argv[1],)
	//std::cout << "1.3" << std::endl;

	std::string buffer;
					
	size_t begin = 0, 
		end = 0,
		step = 100000;

	//std::cout << correct.size() << ' ' << incorrect.size() << std::endl;
	//std::cout << "1.4" << std::endl;
	while (true)
	{
		begin = rand() % correct.size();
		end = begin + step;

		if (end < correct.size())
		{
			break;
		}
	}

	std::string answer = "not found";
	size_t success = 0;
	long long t1, t2;
	t1 = clock();
	for (size_t i = begin; i < end; ++i)
	{
		if ((i - begin) % 1000 == 0) {	std::cout << "PROCESSING " << i - begin << std::endl;	}
		bool wordFound = false;
		pipe_in << incorrect[i] << std::endl;
		size_t counter = 0;
		while (pipe_out)
		{
			pipe_out >> buffer;
			if (buffer == "not found" || buffer == "end") { break; }
			if (!wordFound && buffer == correct[i] && counter < 5)
			{
				answer = buffer;
				wordFound = true;
				++success;
			}
			++counter;
		}
		output << incorrect[i] << ';' << correct[i] << ';' << answer << ';' <<  wordFound << std::endl;
		answer = "not found";
	}
	pipe_in.pipe().close();
	t2 = clock();
	double average = ((double)(t2 - t1)) / ((double)step) / CLOCKS_PER_SEC;
	double chance = ((double)success) / ((double)step);
	std::cout << success << ' ' << step << std::endl;
	output << "Average time on a word: " << average << " sec." << std::endl << "chance = " << chance * 100 << '%' << std::endl;
	
	c.terminate();
	return 0;
}
