#pragma once

#include <vector>
#include <utility>
#include <iostream>

namespace heapsort
{
	using std::vector;

	template<typename T>
	vector<T> sort(vector<T> &orig);

	template<typename T>
	void heapify(vector<T> &orig, size_t from, size_t size);

	template<typename T>
	void buildHeap(vector<T> &orig);

	template<typename T>
	vector<T> sort(vector<T>& orig)
	{
		buildHeap(orig);

		for (int k = orig.size() - 1; k >= 1; --k)
		{
			//std::cout << "get " << orig[0] << " at " << 0 << std::endl;
			std::swap(orig[k], orig[0]);
			//std::cout << "put " << orig[k] << " at " << k << std::endl;
			heapify(orig, 0, k);
		}
		return orig;
	}

	template<typename T>
	void heapify(vector<T>& orig, size_t from, size_t size)
	{
		auto max = from;

		//I believe that the complier will optimize it to `l = from << 2;`
		auto l = 2 * (from + 1) - 1;

		if (l >= size)
		{
			return;
		}
		else if (orig[l] > orig[max])
		{
			max = l;
		}

		auto r = l + 1;
		if (r<size && orig[r]>orig[max])
		{
			max = r;
		}

		if (max != from)
		{
			std::swap(orig[max], orig[from]);
			heapify(orig, max, size);
		}
	}
	template<typename T>
	void buildHeap(vector<T>& orig)
	{
		//How could the complier does't optimize it to `orig.size() >> 2`
		//type of iterator mustn't be unsigned, overflow.
		for (int k = (orig.size() / 2) - 1; k >= 0; --k)
		{
			heapify(orig, k, orig.size());

			//std::cout << k << " ->" << std::ends;
			//for (auto one : orig)
			//{
			//	std::cout << one << std::ends;
			//}
			//std::cout << std::endl;
		}
	}
}