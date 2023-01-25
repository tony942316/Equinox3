#include <iostream>

#include "EquinoxSTD.h"
#include "Benchmark.h"

#include "Tester.h"

void test1()
{
	static constexpr size_t size = 100'000;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = i;
	}
	delete[] arr;
}

int main()
{
	std::cout << "Start" << std::endl;

	eqx::Benchmark base(test1);
	base.avgBench();
	std::cout << base.toString(eqx::Benchmark::Time::microseconds) << std::endl;

	//Tester tests;
	//tests.testAll();

	//std::cout << eqx::getSign(-10.0) << std::endl;

	std::cout << "End" << std::endl;
	std::cin.get();
	return 0;
}