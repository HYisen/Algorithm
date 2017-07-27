#pragma once

#include <vector>
#include <utility>
#include <iostream>

namespace radixsort
{
	using std::vector;

	template<typename T>
	vector<T> sort(vector<T> &orig);

	template<typename T>
	vector<vector<T>> sortAll(vector<vector<T>> &orig, size_t length);

	template<typename T>
	vector<vector<T>> sortOne(vector<vector<T>> &orig, size_t digit, size_t variety);

	template<typename T, int length>
	vector<T> resolve(T &orig, vector<T> &result);

	template<typename T>
	T assemble(vector<T> &orig);

	template <size_t base, size_t exponent>
	size_t exp();

	template<typename T>
	void print(std::vector<std::vector<T>> &data);

	template<typename T>
	vector<T> sort(vector<T>& orig)
	{
		vector<vector<T>> data{};
		for (auto one : orig)
		{
			data.push_back(resolve<T, 2>(one, vector<T>{}));
		}
		//print(data);
		vector<T> rtn{};
		for (auto one : sortAll(data, 3))
		{
			rtn.push_back(assemble(one));
		}
		return rtn;
	}

	template<typename T>
	void print(std::vector<std::vector<T>> &data)
	{
		for (auto one : data)
		{
			for (auto two : one)
			{
				std::cout << two << std::ends;
			}
			std::cout << std::endl;
		}
	}

	template<typename T>
	vector<vector<T>> sortAll(vector<vector<T>>& orig, size_t length)
	{
		vector<vector<T>> rtn(orig);
		for (int k = length-1; k >=0; --k)
		{
			rtn = sortOne(rtn, k, 10);
			//std::cout << "digit " << k << std::endl;
			//print(rtn);
		}
		return rtn;
	}

	template<typename T>
	vector<vector<T>> sortOne(vector<vector<T>>& orig, size_t digit, size_t variety)
	{
		vector<T> stats( variety, 0 );
		for (auto one : orig)
		{
			stats[one[digit]]++;
		}
		vector<T> count{ stats };
		for (auto k = 1; k < variety; ++k)
		{
			stats[k] += stats[k - 1];
		}
		vector<vector<T>> rtn{};
		rtn.resize(orig.size());
		for (auto one : orig)
		{
			rtn[stats[one[digit]] - count[one[digit]]] = one;
			count[one[digit]]--;
		}
		return rtn;
	}

	//template partial specialization of a function is unavailable.
	template<>
	vector<int> resolve<int, -1>(int &orig, vector<int> &result)
	{
		return result;
	}

	template<typename T, int length>
	vector<T> resolve(T &orig, vector<T> &result)
	{
		if (length < 0)
		{
			return result;
		}
		T number = orig / (exp<10, length>());
		//std::cout << orig << " / " << exp<10, length>()
		//	<< " = " << number << std::endl;
		result.push_back(number);
		orig -= number*(exp<10, length>());
		return resolve<T, length - 1>(orig, result);
	}

	template<typename T>
	T assemble(vector<T>& orig)
	{
		auto base = 1;
		T rtn{};
		for (auto it=orig.crbegin();it!=orig.crend();++it)
		{
			rtn += (*it)*base;
			base *= 10;
		}
		return rtn;
	}


	template<>
	size_t exp<10, 0>()
	{
		return 1;
	}

	template<size_t base, size_t exponent>
	size_t exp()
	{
		return base*(exp<base, exponent - 1>());
	}

}