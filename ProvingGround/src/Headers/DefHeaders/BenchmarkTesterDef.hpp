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
	testToString();
	UnitTester::printStatus();
	UnitTester::clear();
}

inline std::vector<int> BenchmarkTester::doWork()
{
	constexpr auto size = 1'000'000;
	auto data = std::vector<int>();
	data.resize(size);
	for (int i = 0; i < size; i++)
	{
		data.at(i) = 44;
	}
	return data;
}

inline void BenchmarkTester::testToString()
{
	auto bench = eqx::Benchmark([]() { doWork(); });
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
