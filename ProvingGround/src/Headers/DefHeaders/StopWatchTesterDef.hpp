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

#pragma once

inline void StopWatchTester::test()
{
	std::cout << "Testing StopWatch..." << std::endl;
	testGetTime();
	testReadTime();
	testGetSeconds();
	testReadSeconds();
	testToString();
	UnitTester::printStatus();
	UnitTester::clear();
}

inline void StopWatchTester::testGetTime()
{
	using namespace std::chrono_literals;
	using namespace eqx::TimeTypes;
	auto watch = eqx::StopWatch();
	wasteTime(1'000us);
	watch.stop();

	UnitTester::test(watch.getTime<t_US>(), 100'000LL,
		LTE<long long, long long>);
	UnitTester::test(watch.getTime<t_US>(), 1'000LL,
		GTE<long long, long long>);
}

inline void StopWatchTester::testReadTime()
{
	using namespace std::chrono_literals;
	using namespace eqx::TimeTypes;
	auto watch = eqx::StopWatch();
	wasteTime(1'000us);
	const auto result = watch.readTime<t_US>();

	UnitTester::test(result, 100'000LL, LTE<long long, long long>);
	UnitTester::test(result, 1'000LL, GTE<long long, long long>);
	UnitTester::test(result, watch.getTime<t_US>());
}

inline void StopWatchTester::testGetSeconds()
{
	using namespace std::chrono_literals;
	using namespace eqx::TimeTypes;
	auto watch = eqx::StopWatch();
	wasteTime(1'000ms);
	watch.stop();

	UnitTester::test(watch.getSeconds(), 2.0,
		LTE<double, double>);
	UnitTester::test(watch.getSeconds(), 1.0,
		GTE<double, double>);

	watch.start();
	wasteTime(500ms);
	watch.stop();

	UnitTester::test(watch.getSeconds(), 1.0,
		LTE<double, double>);
	UnitTester::test(watch.getSeconds(), 0.5,
		GTE<double, double>);
}

inline void StopWatchTester::testReadSeconds()
{
	using namespace std::chrono_literals;
	using namespace eqx::TimeTypes;
	auto watch = eqx::StopWatch();
	wasteTime(1'000ms);
	auto result = watch.readSeconds();

	UnitTester::test(result, 2.0,
		LTE<double, double>);
	UnitTester::test(result, 1.0,
		GTE<double, double>);
	UnitTester::test(result, watch.getSeconds());

	watch.start();
	wasteTime(500ms);
	result = watch.readSeconds();

	UnitTester::test(result, 1.0,
		LTE<double, double>);
	UnitTester::test(result, 0.5,
		GTE<double, double>);
	UnitTester::test(result, watch.getSeconds());
}

inline void StopWatchTester::testToString()
{
	using namespace std::chrono_literals;
	using namespace eqx::TimeTypes;
	auto watch = eqx::StopWatch();
	wasteTime(1'000us);
	watch.stop();

	UnitTester::test(watch.toString<t_US>(), 
		std::format("{}us", watch.getTime<t_US>()));
	UnitTester::test(eqx::toString<t_US>(watch), watch.toString<t_US>());
}

inline void StopWatchTester::wasteTime(std::chrono::microseconds ms)
{
	std::this_thread::sleep_for(ms);
}
