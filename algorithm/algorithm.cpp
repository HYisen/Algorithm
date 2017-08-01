#include "benchmark.h"
#include "mergesort.h"
#include "heapsort.h"
#include "quicksort.h"
#include "countingsort.h"
#include "radixsort.h"

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

	//for (auto one : mergesort::sort(data))
	//{
	//	cout << one << ends;
	//}

	//for (auto one : heapsort::sort(data))
	//{
	//	cout << one << ends;
	//}

	for (auto one : quicksort::sort(data))
	{
		cout << one << ends;
	}
	cout << endl;

	std::vector<int> data1{ 1,2,4,0,3,1,0,2,3,4,0,1,1 };
	for (auto one : countingsort::sort(data1, 5))
	{
		cout << one << ends;
	}
	cout << endl;

	std::vector<int> data2{ 123,456,258,698,451,102,52,8,984 };
	for (auto one : radixsort::sort(data2))
	{
		cout << one << ends;
	}
	cout << endl;

	std::vector<int> data3{ 123,456,258,698,451,102,52,4,984 };
	for (auto one : radixsort::sort(data3))
	{
		cout << one << ends;
	}
	cout << endl;
}

int main()
{
	auto data = generate(10, 4);
	print(data);

	test();

	return 0;
}