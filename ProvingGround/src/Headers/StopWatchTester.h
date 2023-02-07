#pragma once

#include "StopWatch.h"

#include "UnitTest.h"

class StopWatchTester
{
public:
	StopWatchTester() = delete;
	StopWatchTester(const StopWatchTester&) = delete;
	StopWatchTester(StopWatchTester&&) = delete;
	StopWatchTester& operator= (const StopWatchTester&) = delete;
	StopWatchTester& operator= (StopWatchTester&&) = delete;
	~StopWatchTester() = delete;

	static bool test();

private:
	static bool testStartStop();
	static bool testReading();
	static bool testGetting();
	static void prep();
	static void doWork();

	static std::chrono::time_point<std::chrono::steady_clock> s_Start, s_End;
	static long long s_Time;
	static eqx::StopWatch s_Watch;
	static UnitTest<long long, long long> s_LongLongTests;
};