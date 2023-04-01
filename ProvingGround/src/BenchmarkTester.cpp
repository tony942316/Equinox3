#include "BenchmarkTester.hpp"

#include <iostream>
#include <string>

#include "UnitTest.hpp"
#include "Benchmark.hpp"

namespace BenchmarkTester
{
	void testToString();

	void test()
	{
		std::cout << "Testing Benchmark..." << std::endl;
		testToString();
		UnitTester::printStatus();
		UnitTester::clear();
	}
}

void doWork()
{
	constexpr auto size = 1'000'000;
	volatile auto data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = 44;
	}
	delete[] data;
}

void BenchmarkTester::testToString()
{
	auto bench = eqx::Benchmark(doWork);
	bench.bench();
	auto str = bench.toString<std::chrono::microseconds>();
	auto numStr = str.substr(7);
	numStr.pop_back();
	numStr.pop_back();
	numStr.pop_back();

	auto expected = std::string("");
	expected += "Bench: ";
	expected += numStr;
	expected += " us";
	auto produced = bench.toString<std::chrono::microseconds>();
	UnitTester::test(produced, expected);
	UnitTester::test(std::stoll(numStr), 50LL, GTE<long long, long long>);
}