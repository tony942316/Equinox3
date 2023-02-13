#include "StopWatchTester.hpp"

#include <iostream>

std::chrono::time_point<std::chrono::steady_clock>
	StopWatchTester::s_Start, StopWatchTester::s_End;
long long StopWatchTester::s_Time = 0LL;
eqx::StopWatch StopWatchTester::s_Watch;
UnitTest<long long, long long> StopWatchTester::s_LongLongTests;

bool StopWatchTester::test()
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
	prep();

	for (int i = 0; i < 1'000; i++)
	{
		s_Start = std::chrono::steady_clock::now();
		s_End = s_Start;
		s_Watch.start();

		s_LongLongTests.addTest(std::make_tuple(
			s_Watch.getTimeMicro(), 0ULL, EQ2<long long, long long>));
		s_LongLongTests.addTest(std::make_tuple(
			s_Watch.getTimeNano(), 0ULL, EQ2<long long, long long>));
		s_LongLongTests.addTest(std::make_tuple(
			s_Watch.getTimeMilli(), 0ULL, EQ2<long long, long long>));
		s_LongLongTests.addTest(std::make_tuple(
			s_Watch.getTimeSeconds(), 0ULL, EQ2<long long, long long>));

		while (s_Watch.getTimeNano() < 1'000 || s_Time < 1)
		{
			doWork();
			s_Watch.stop();
			s_End = std::chrono::steady_clock::now();
			s_Time = std::chrono::duration_cast<std::chrono::milliseconds>(
				s_End - s_Start).count();
		}

		s_Watch.stop();

		s_LongLongTests.addTest(std::make_tuple(
			s_Watch.getTimeMicro(), 1LL, GTE<long long, long long>()));
		s_LongLongTests.addTest(std::make_tuple(
			s_Watch.getTimeNano(), 1LL, GTE<long long, long long>()));

	}

	for (int i = 0; i < 200; i++)
	{
		s_Start = std::chrono::steady_clock::now();
		s_End = s_Start;
		s_Watch.start();

		while (s_Watch.getTimeMilli() < 1 || s_Time < 5)
		{
			doWork();
			s_Watch.stop();
			s_End = std::chrono::steady_clock::now();
			s_Time = std::chrono::duration_cast<std::chrono::milliseconds>(
				s_End - s_Start).count();
		}

		s_Watch.stop();

		s_LongLongTests.addTest(std::make_tuple(
			s_Watch.getTimeMilli(), 1LL, GTE<long long, long long>()));

	}

	for (int i = 0; i < 3; i++)
	{
		s_Start = std::chrono::steady_clock::now();
		s_End = s_Start;
		s_Watch.start();

		while (s_Watch.getTimeSeconds() < 1 || s_Time < 3)
		{
			doWork();
			s_Watch.stop();
			s_End = std::chrono::steady_clock::now();
			s_Time = std::chrono::duration_cast<std::chrono::seconds>(
				s_End - s_Start).count();
		}

		s_Watch.stop();

		s_LongLongTests.addTest(std::make_tuple(
			s_Watch.getTimeSeconds(), 1LL, GTE<long long, long long>()));
	}

	return s_LongLongTests.test();
}

bool StopWatchTester::testReading()
{
	prep();

	for (int i = 0; i < 1'000; i++)
	{
		s_Start = std::chrono::steady_clock::now();
		s_End = s_Start;
		s_Watch.start();

		s_LongLongTests.addTest(std::make_tuple(
			s_Watch.getTimeMicro(), 0ULL, EQ2<long long, long long>));
		s_LongLongTests.addTest(std::make_tuple(
			s_Watch.getTimeNano(), 0ULL, EQ2<long long, long long>));
		s_LongLongTests.addTest(std::make_tuple(
			s_Watch.getTimeMilli(), 0ULL, EQ2<long long, long long>));
		s_LongLongTests.addTest(std::make_tuple(
			s_Watch.getTimeSeconds(), 0ULL, EQ2<long long, long long>));

		while (s_Watch.readTimeNano() < 1'000 || s_Time < 1)
		{
			doWork();
			s_End = std::chrono::steady_clock::now();
			s_Time = std::chrono::duration_cast<std::chrono::milliseconds>(
				s_End - s_Start).count();
		}

		s_LongLongTests.addTest(std::make_tuple(
			s_Watch.readTimeMicro(), 1LL, GTE<long long, long long>()));
		s_LongLongTests.addTest(std::make_tuple(
			s_Watch.readTimeNano(), 1LL, GTE<long long, long long>()));

	}

	for (int i = 0; i < 200; i++)
	{
		s_Start = std::chrono::steady_clock::now();
		s_End = s_Start;
		s_Watch.start();

		while (s_Watch.readTimeMilli() < 1 || s_Time < 5)
		{
			doWork();
			s_End = std::chrono::steady_clock::now();
			s_Time = std::chrono::duration_cast<std::chrono::milliseconds>(
				s_End - s_Start).count();
		}

		s_LongLongTests.addTest(std::make_tuple(
			s_Watch.readTimeMilli(), 1LL, GTE<long long, long long>()));

	}

	for (int i = 0; i < 3; i++)
	{
		s_Start = std::chrono::steady_clock::now();
		s_End = s_Start;
		s_Watch.start();

		while (s_Watch.readTimeSeconds() < 1 || s_Time < 3)
		{
			doWork();
			s_End = std::chrono::steady_clock::now();
			s_Time = std::chrono::duration_cast<std::chrono::seconds>(
				s_End - s_Start).count();
		}

		s_LongLongTests.addTest(std::make_tuple(
			s_Watch.readTimeSeconds(), 1LL, GTE<long long, long long>()));
	}

	return s_LongLongTests.test();
}

bool StopWatchTester::testGetting()
{
	return testStartStop();
}

void StopWatchTester::prep()
{
	s_Watch = eqx::StopWatch();
	s_Start = std::chrono::steady_clock::now();
	s_End = s_Start;
	s_Time = 0LL;
}

void StopWatchTester::doWork()
{
	constexpr std::size_t dataSize = 500ULL;
	int* data = new int[dataSize];

	std::for_each(data, data + dataSize, [](int& x) { x = 25; });

	delete[] data;
}