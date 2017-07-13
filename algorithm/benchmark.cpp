#include "benchmark.h"

std::vector<std::vector<int>> generate(int length,int sample)
{
	static std::default_random_engine e;
	std::uniform_int_distribution<int> u{};

	//efficiency is not important there.
	//std::move is redundant in my opinion.

	std::vector<std::vector<int>> major{};
	std::vector<int> minor{};

	for (int i = 0; i != sample; ++i)
	{
		for (int j = 0; j != length; j++)
		{
			minor.push_back(u(e));
		}
		major.push_back(minor);
		minor.clear();
	}

	return major;
}

void print(std::vector<std::vector<int>> orig)
{
	for (auto line : orig)
	{
		for (auto word : line)
		{
			std::cout << word << std::ends;
		}
		std::cout << std::endl;
	}
}
