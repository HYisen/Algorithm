#pragma once

#include <array>

namespace mergesort
{
	using std::array;

	template<typename T, size_t size>
	array<T, size> sort(const array<T, size> &orig);

	//It's quite tricky to calculate size during the compiling, isn't it?
	template<typename T, size_t ls, size_t rs>
	array<T, ls + rs> merge(const array<T, ls> &lhs, const array<T, rs> &rhs);

	template<typename T, size_t ls, size_t rs>
	array<T, ls + rs> merge(const array<T, ls>& lhs, const array<T, rs>& rhs)
	{
		array<T, ls + rs> rtn{};
		size_t li{ 0 }, ri{ 0 }, it{ 0 };
		while (true)
		{
			if (lhs[li] >= rhs[ri])
			{
				rtn[it] = lhs[li];
				li++;
				if (li == lhs.size())
				{
					while (ri != rhs.size())
					{
						rtn[it] = rhs[ri];
						it++;
						ri++;
					}
					break;
				}
			}
			else
			{
				rtn[it] = rhs[ri];
				ri++;
				if (ri == rhs.size())
				{
					while (li != lhs.size())
					{
						rtn[it] = lhs[li];
						it++;
						li++;
					}
					break;
				}
			}
			it++;
		}
		return rtn;
	}
}