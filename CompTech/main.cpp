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
	//std::cout << correct_source << std::endl << incorrect_source << std::endl;
	std::ifstream cor("C:/Users/YGAR/source/repos/CompTech3/CompTech/CompTech/correct.txt");
	std::ifstream incor("C:/Users/YGAR/source/repos/CompTech3/CompTech/CompTech/incorrect.txt");

	std::string buff;
	//std::cout << "cor good " << cor.good() << std::endl;
	//std::cout << cor.bad() << ' ' << cor.eof() << ' ' << cor.fail() << std::endl;
	while (cor.good())
	{
		cor >> buff;
		correct.push_back(buff);
	}
	//std::cout << "incor good " << incor.good() << std::endl;
	//std::cout << incor.bad() << ' ' << incor.eof() << ' ' << incor.fail() << std::endl;
	while (incor.good())
	{
		incor >> buff;
		incorrect.push_back(buff);
	}
	//std::cout << correct.size() << ' ' << incorrect.size() << std::endl;
	cor.close();
	incor.close();
	return;
}


int main(int argc, char** argv)
{	
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if (argc < 2) 
	{
		return 1;
	}
	//std::cout << "1.1" << std::endl;
	std::string name(argv[1]);
	std::ofstream output(getName(name) + "test.txt");
	std::cout << "Uploading test files... ";
	getExamples("correct.txt", "incorrect.txt");
	std::cout << "COMPLITED!" << std::endl;
	bp::ipstream pipe_out;
	bp::opstream pipe_in;
	//std::cout << "1.2" << std::endl;
	bp::child c(argv[1], bp::std_in < pipe_in, bp::std_out > pipe_out);
	//std::cout << "1.3" << std::endl;

	std::string buffer;
					
	size_t begin = 0, 
		end = 0,
		step = 10000;

	std::cout << correct.size() << ' ' << incorrect.size() << std::endl;
	std::cout << "1.4" << std::endl;
	while (true)
	{
		begin = rand() % correct.size();
		end = begin + step;

		if (end < correct.size())
		{
			break;
		}
	}

	//std::cout << "1.5" << std::endl;
	//std::cout << begin << ' ' << end << std::endl;
	//std::cout << "1.6" << std::endl;
	long long t1, t2;
	t1 = clock();
	for (size_t i = begin; i < end; ++i)
	{
		if ((i- begin) % 100 == 0) {	std::cout << "PROCESSING " << i - begin << std::endl;	}
		bool wordFound = false;
		std::vector<std::string> result;
		pipe_in << incorrect[i] << std::endl;
		size_t counter = 0;
		while (pipe_out)
		{
			pipe_out >> buffer;
			//std::cout << "buffer = " << buffer << std::endl;
			if (buffer == "not found" || buffer == "end") { break; }
			if (buffer == correct[i] && counter < 5) 
			{
				wordFound = true;
			}
			++counter;
		}
		output << incorrect[i] << ';' << correct[i] << ';' << buffer << ';' <<  wordFound << std::endl;
	}
	pipe_in.pipe().close();
	t2 = clock();
	double average = ((double)(t2 - t1)) / ((double)step) / CLOCKS_PER_SEC;
	output << "Average time on a word: " << average << " sec." << std::endl;
	//pipe_in << "dadaya" << std::endl;
	//pipe_in.pipe().close();

	//std::string tmp;
	//pipe_out >> tmp;
	//std::cout << tmp << std::endl;

	c.wait();
	c.terminate();


	return 0;
}
