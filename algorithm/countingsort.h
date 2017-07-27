#pragma once

#include <vector>
#include <iostream>

namespace countingsort
{
	using std::vector;

	template<typename T>
	vector<T> sort(vector<T> &orig, size_t variety);
	template<typename T>
	vector<T> sort(vector<T>& orig, size_t variety)
	{
		vector<T> stats(variety, 0);
		for (auto one : orig)
		{
			stats[one]++;
		}
		//It's quite stupid to use size()-1, as a minus one in unsiged is bad.
		for (auto k = 1; k < variety; ++k)
		{
			stats[k] += stats[k - 1];
		}
		vector<T> rtn{};
		//Unlike .at() , [] doesn't check range, so set the size at first.
		rtn.resize(orig.size());
		for (auto one : orig)
		{
			rtn[stats[one] - 1] = one;
			stats[one]--;
		}
		return rtn;
	}
}