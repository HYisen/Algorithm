#pragma once

//Randomized Select

#include <iostream>
#include <vector>

namespace rselect
{
	//range in [from,to)
	size_t random(size_t alpha, size_t omega);

	template<typename T> T select(std::vector<T> &orig, size_t alpha, size_t omega, size_t order);

	template<typename T>
	size_t partition(std::vector<T> &orig, size_t alpha, size_t omega);

	template<typename T>
	T select(std::vector<T>& orig, size_t alpha, size_t omega, size_t order)
	{
		//for (auto one : orig)
		//{
		//	std::cout << one << std::ends;
		//}
		//std::cout << std::endl;
		//std::cout << alpha << std::ends << omega << std::ends << order << std::endl;
		if (alpha == omega - 1)
		{
			return orig[alpha];
		}
		auto anchor = partition(orig, alpha, omega) - alpha;
		//std::cout << anchor << std::endl;
		if (anchor == order)
		{
			return orig[anchor+alpha];
		}
		else if (anchor < order)
		{
			return select(orig, alpha + anchor + 1, omega, order - anchor - 1);
		}
		else
		{
			return select(orig, alpha, alpha + anchor, order);
		}
	}

	template<typename T>
	size_t partition(std::vector<T> &orig, size_t alpha, size_t omega)
	{
		auto index = random(alpha, omega);
		std::swap(orig[index], orig[omega - 1]);
		T pivot = orig[omega - 1];
		//std::cout << pivot << std::endl;
		index = alpha;
		for (auto k = alpha; k != omega; ++k)
		{
			if (orig[k] < pivot)
			{
				std::swap(orig[k], orig[index]);
				index++;
			}
		}
		std::swap(orig[index], orig[omega - 1]);
		return index;
	}
}