#include "benchmark.h"

#include <iostream>

void test()
{
	using std::cout;
	using std::endl;

	int a = 4;
	int b = 8;
	int &ref = a;
	cout << a << endl;
	cout << ref << endl;
	ref = 10;
	cout << ref << endl;
	cout << a << endl;
}

int main()
{
	auto data = generate(10, 4);
	print(data);

	test();

    return 0;
}

