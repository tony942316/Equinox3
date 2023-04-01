#include "StopWatchTester.hpp"

#include <iostream>
#include <chrono>

#include "UnitTest.hpp"
#include "eqx_StopWatch.hpp"

namespace StopWatchTester
{
	void testGetTime();
	void testReadTime();

	void test()
	{
		std::cout << "Testing StopWatch..." << std::endl;
		testGetTime();
		testReadTime();
		UnitTester::printStatus();
		UnitTester::clear();
	}

	void wasteTime(std::chrono::microseconds ms);
}

void StopWatchTester::wasteTime(std::chrono::microseconds ms)
{
	std::this_thread::sleep_for(ms);
}

void StopWatchTester::testGetTime()
{
	using namespace std::chrono_literals;
	using namespace eqx::shortTimeUnits;
	auto watch = eqx::StopWatch();
	wasteTime(1'000us);
	watch.stop();

	UnitTester::test(watch.getTime<tu_us>(), 100'000LL, 
		LTE<long long, long long>);
	UnitTester::test(watch.getTime<tu_us>(), 1'000LL,
		GTE<long long, long long>);
}

void StopWatchTester::testReadTime()
{
	using namespace std::chrono_literals;
	using namespace eqx::shortTimeUnits;
	auto watch = eqx::StopWatch();
	wasteTime(1'000us);
	auto result = watch.readTime<tu_us>();

	UnitTester::test(result, 100'000LL, LTE<long long, long long>);
	UnitTester::test(result, 1'000LL, GTE<long long, long long>);
}