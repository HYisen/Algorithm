#pragma once

#include <vector>

namespace mergesort
{
	std::vector<int> sort(std::vector<int> orig);

	std::vector<int> merge(std::vector<int> lhs, std::vector<int> rhs);
}