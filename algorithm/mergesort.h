#pragma once

#include <vector>
#include <iostream>

namespace mergesort
{
	using std::vector;

	template<typename T>
	vector<T> sort(const vector<T> &orig);

	template<typename T>
	vector<T> merge(const vector<T> &lhs, const vector<T> &rhs);

	template<typename T>
	vector<T> sort(const vector<T>& orig)
	{
		if (orig.size() == 1)
		{
			return orig;
		}
		else
		{
			auto mid = orig.cbegin() + orig.size() / 2;
			//std::cout << "mid = " << mid - orig.cbegin() << std::endl;
			//system("pause");
			return merge(
				sort(vector<T>{orig.cbegin(), mid}),
				sort(vector<T>{mid, orig.cend()}));
		}
	}

	template<typename T>
	vector<T> merge(const vector<T>& lhs, const vector<T>& rhs)
	{
		vector<T> rtn{};

		//for (auto one : lhs)
		//{
		//	std::cout << one << std::ends;
		//}
		//std::cout << std::endl;
		//for (auto one : rhs)
		//{
		//	std::cout << one << std::ends;
		//}
		//std::cout << std::endl;

		auto li = lhs.cbegin();
		auto ri = rhs.cbegin();
		auto it = &li;
		
		while (true)
		{
			it = (*li >= *ri) ? &li : &ri;
			//std::cout << *li << " vs " << *ri << std::endl;
			//system("pause");
			rtn.push_back(**it);
			(*it)++;
			if (li == lhs.cend())
			{
				while (ri != rhs.cend())
				{
					rtn.push_back(*ri);
					ri++;
				}
				break;
			}
			else if(ri == rhs.cend())
			{
				while (li != lhs.cend())
				{
					rtn.push_back(*li);
					li++;
				}
				break;
			}
		}

		return rtn;
	}
}