#pragma once

#include <vector>
#include <utility>
#include <iostream>

namespace quicksort
{
	using std::vector;

	template<typename T>
	vector<T> sort(vector<T> &orig);

	template<typename T>
	void qsort(vector<T> &orig, size_t from, size_t to);

	template<typename T>
	vector<T> sort(vector<T>& orig)
	{
		qsort(orig, 0, orig.size());
		return orig;
	}

	template<typename T>
	void qsort(vector<T>& orig, size_t from, size_t to)
	{
		if (to - from < 2)
		{
			return;
		}
		auto alpha = from;
		auto omega = from;
		T criterion = orig[to - 1];

		while (omega != to - 1)
		{
			if (orig[omega] < criterion)
			{
				std::swap(orig[alpha], orig[omega]);
				alpha++;
			}
			omega++;
		}
		std::swap(orig[to - 1], orig[alpha]);

		qsort(orig, from, alpha);
		qsort(orig, alpha, omega);
	}
}