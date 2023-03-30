#include "StopWatchTester.hpp"

#include <iostream>

#include "UnitTest.hpp"
#include "StopWatch.hpp"

void testGetTime();
void testReadTime();

namespace StopWatchTester
{
	void test()
	{
		std::cout << "Testing StopWatch..." << std::endl;
		testGetTime();
		testReadTime();
		UnitTester::printStatus();
		UnitTester::clear();
	}
}

void wasteTime(std::chrono::microseconds ms)
{
	std::this_thread::sleep_for(ms);
}

void testGetTime()
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

void testReadTime()
{
	using namespace std::chrono_literals;
	using namespace eqx::shortTimeUnits;
	auto watch = eqx::StopWatch();
	wasteTime(1'000us);
	auto result = watch.readTime<tu_us>();

	UnitTester::test(result, 100'000LL, LTE<long long, long long>);
	UnitTester::test(result, 1'000LL, GTE<long long, long long>);
}