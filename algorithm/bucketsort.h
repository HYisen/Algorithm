#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

namespace bucketgsort
{
	using std::vector;

	template<typename T>
	vector<T> sort(vector<T> &orig);

	template<typename T>
	vector<vector<T>> resolve(vector<T> &orig, size_t bucket_size);

	template<typename T>
	vector<T> insert_sort(vector<T> &orig);

	template<typename T>
	vector<T> assemble(vector<vector<T>> &orig);

	template<typename T>
	vector<T> sort(vector<T>& orig)
	{
		return vector<T>();
	}

	template<typename T>
	vector<vector<T>> resolve(vector<T>& orig, size_t bucket_size)
	{
		auto max = std::max_element(orig.cbegin(), orig.cend());
		vector<vector<T>> rtn{};
		std::generate_n(rtn.begin(), max / bucket_size, []()->return vector<T>{});
		for (auto one : orig)
		{
			rtn.at(one / bucket_size).push_back(one);
		}
		return rtn;
	}

	template<typename T>
	vector<T> insert_sort(vector<T>& orig)
	{
		return vector<T>();
	}

	template<typename T>
	vector<T> assemble(vector<vector<T>>& orig)
	{
		return vector<T>();
	}

}
