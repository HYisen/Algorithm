#include <random>

#include "rselect.h"

size_t rselect::random(size_t alpha, size_t omega)
{
	static std::default_random_engine e{};
	std::uniform_int_distribution<size_t> d(alpha, omega-1);
	//std::cout << alpha << "->" << omega << std::endl;
	return d(e);
}
