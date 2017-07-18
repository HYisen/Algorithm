#include "benchmark.h"
#include "mergesort.h"

#include <iostream>
#include <vector>

void test()
{
	using std::cout;
	using std::endl;
	using std::ends;

	int a = 4;
	int b = 8;
	int &ref = a;
	cout << a << endl;
	cout << ref << endl;
	ref = 10;
	cout << ref << endl;
	cout << a << endl;

	std::vector<int> data{ 1,2,3,5,8,9,4,6 };
	for (auto one : mergesort::sort(data))
	{
		cout << one << ends;
	}
}

int main()
{
	auto data = generate(10, 4);
	print(data);

	test();

    return 0;
}

