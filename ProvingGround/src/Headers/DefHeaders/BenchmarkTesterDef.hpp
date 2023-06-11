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

inline void BenchmarkTester::test()
{
	std::cout << "Testing Benchmark..." << std::endl;
	testGetBench();
	testToString();
	UnitTester::printStatus();
	UnitTester::clear();
}

inline void BenchmarkTester::testGetBench()
{
	using namespace std::literals;
	using namespace eqx::shortTimeUnits;
	auto bench = eqx::Benchmark();

	bench.bench(wasteTime, 5us);
	UnitTester::test(bench.getBench<t_US>(), 0LL, GT<long long, long long>);

	bench.avgBench(10, wasteTime, 5us);
	UnitTester::test(bench.getBench<t_US>(), 0LL, GT<long long, long long>);

	bench = eqx::Benchmark::runBench(wasteTime, 5us);
	UnitTester::test(bench.getBench<t_US>(), 0LL, GT<long long, long long>);

	bench = eqx::Benchmark::runAvgBench(10, wasteTime, 5us);
	UnitTester::test(bench.getBench<t_US>(), 0LL, GT<long long, long long>);
}

inline void BenchmarkTester::testToString()
{
	using namespace std::literals;
	using namespace eqx::shortTimeUnits;
	auto bench = eqx::Benchmark();
	bench.bench(wasteTime, 5us);

	auto expected = std::format("Bench: {}us", bench.getBench<t_US>());
	auto produced = bench.toString<t_US>();
	UnitTester::test(produced, expected);
	UnitTester::test(produced, eqx::toString<t_US>(bench));
}

inline void BenchmarkTester::wasteTime(std::chrono::microseconds us)
{
	std::this_thread::sleep_for(us);
}
