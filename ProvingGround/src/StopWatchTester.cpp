#include "StopWatchTester.h"

#include <iostream>

#include "EquinoxSTD.h"
#include "UnitTest.h"

StopWatchTester::StopWatchTester()
{
}

bool StopWatchTester::testAll()
{
	if (testStartStop() &&
		testReading() &&
		testGetting())
	{
		std::cout << "StopWatch Tests Passed" << std::endl;
		return true;
	}
	else
	{
		std::cout << "StopWatch Tests Failed!" << std::endl;
		return false;
	}
}

bool StopWatchTester::testStartStop()
{
	eqx::StopWatch watch;
	for (int i = 0; i < 100'000; i++)
	{
		watch.start();
		watch.stop();
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		std::chrono::system_clock::time_point end = start;
		while (watch.getTimeNano() < 1)
		{
			watch.stop();
			if (watch.getTimeNano() > 0 ||
				std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() > 50)
			{
				break;
			}
			end = std::chrono::system_clock::now();
		}

		if (!TEST(watch.getTimeNano(), 1LL, GTE<long long, long long>()))
		{
			return false;
		}
	}

	return true;
}

bool StopWatchTester::testReading()
{
	eqx::StopWatch watch;
	for (int i = 0; i < 100'000; i++)
	{
		watch.start();
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		std::chrono::system_clock::time_point end = start;
		while (watch.readTimeNano() < 1)
		{
			if (watch.readTimeNano() > 0 ||
				std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() > 50)
			{
				break;
			}
			end = std::chrono::system_clock::now();
		}

		if (!TEST(watch.getTimeNano(), 1LL, GTE<long long, long long>()))
		{
			return false;
		}
	}

	return true;
}

bool StopWatchTester::testGetting()
{
	eqx::StopWatch watch;
	for (int i = 0; i < 100'000; i++)
	{
		if (!TEST(watch.getTimeNano(), 0LL))
		{
			return false;
		}
	}

	return true;
}