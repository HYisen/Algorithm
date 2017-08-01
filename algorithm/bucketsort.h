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
		//The Stream in Java seems would work perfectly there.
		vector<vector<T>> data = resolve(orig,100);
		for (auto one : data)
		{
			insert_sort(one);
		}
		return assemble(data);
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
		int max;
		for (int i = 0; i != orig.size(); ++i)
		{
			max = i;
			//After a long consieration, I think != is as workable as < .
			for (int j = i+1; j != orig.size(); ++j)
			{
				if (orig[j] > orig[max])
				{
					max = j;
				}
			}
			std::swap(orig[max], orig[i]);
		}
		return orig;
	}

	template<typename T>
	vector<T> assemble(vector<vector<T>>& orig)
	{
		vector<T> rtn{};
		for (auto one : orig)
		{
			for (auto two : one)
			{
				rtn.push_back(two);
			}
		}
		return rtn;
	}

}
