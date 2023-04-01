/*
 * Copyright (C) 2023 Anthony H. Grasso
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

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