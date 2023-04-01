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

#include "MiscTester.hpp"

#include <iostream>
#include <sstream>
#include <utility>
#include <algorithm>

#include <array>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include "UnitTest.hpp"
#include "eqx_Misc.hpp"

namespace MiscTester
{
	void testToString();
	void testPairPrint();
	void testZip();

	void test()
	{
		std::cout << "Testing Misc..." << std::endl;
		testToString();
		testPairPrint();
		testZip();
		UnitTester::printStatus();
		UnitTester::clear();
	}

	consteval void testLiterals();
}

void MiscTester::testToString()
{
	using namespace std::string_view_literals;
	using namespace std::string_literals;

	UnitTester::test(eqx::toString("cstring"), "cstring"s);
	UnitTester::test(eqx::toString("stdstring"s), "stdstring"s);
	UnitTester::test(eqx::toString("string_view"sv), "string_view"s);

	UnitTester::test(eqx::toString(5), "5"s);
	UnitTester::test(eqx::toString(5L), "5"s);
	UnitTester::test(eqx::toString(5LL), "5"s);
	UnitTester::test(eqx::toString(5U), "5"s);
	UnitTester::test(eqx::toString(5UL), "5"s);
	UnitTester::test(eqx::toString(5ULL), "5"s);
	UnitTester::test(eqx::toString(5.1234567F), "5.123456"s);
	UnitTester::test(eqx::toString(5.1234567), "5.123457"s);
	UnitTester::test(eqx::toString(5.1234567L), "5.123457"s);

	UnitTester::test(eqx::toString(std::make_pair(5, 5)), "(5, 5)"s);
	UnitTester::test(eqx::toString(std::make_pair("Yes", 5)), "(Yes, 5)"s);
	UnitTester::test(
		eqx::toString(std::make_pair(5, 5.123)),"(5, 5.123000)"s);
	UnitTester::test(
		eqx::toString(std::make_pair("Hello"sv, 6UL)), "(Hello, 6)"s);
	UnitTester::test(
		eqx::toString(std::make_pair("v"s, "X"sv)), "(v, X)"s);

	auto p1 = std::make_pair("A", "B");
	auto p2 = std::make_pair("C", "D");
	UnitTester::test(
		eqx::toString(std::make_pair(p1, p2)), "((A, B), (C, D))"s);

	auto vec = std::vector<int>({ 1, 2, 3 });
	UnitTester::test(eqx::toString(vec), "{ 1, 2, 3 }"s);

	auto vecWPairs = std::vector<std::pair<int, std::string_view>>({
		{ 1, "One" },
		{ 2, "Two" },
		{ 3, "Three" },
		{ 4, "Four" }
	});
	UnitTester::test(eqx::toString(vecWPairs), 
		"{ (1, One), (2, Two), (3, Three), (4, Four) }"s);
}

void MiscTester::testPairPrint()
{
	using namespace eqx::pairPrint;
	using namespace std::string_view_literals;

	auto ss = std::stringstream();
	auto temp = std::string("");

	ss << std::make_pair(1, 1) << "\n";
	std::getline(ss, temp);
	UnitTester::test(temp, "(1, 1)"sv);

	ss << std::make_pair("Yes", "No") << "\n";
	std::getline(ss, temp);
	UnitTester::test(temp, "(Yes, No)"sv);

	ss << std::make_pair(1.5, "Double") << "\n";
	std::getline(ss, temp);
	UnitTester::test(temp, "(1.500000, Double)"sv);
}

consteval void MiscTester::testLiterals()
{
	using namespace eqx::literals;

	static_assert(std::is_same_v<decltype(1_size), std::size_t>);
	static_assert(std::is_same_v<decltype(1_short), short>);
	static_assert(std::is_same_v<decltype(1_ushort), unsigned short>);
}

void MiscTester::testZip()
{
	using namespace std::string_view_literals;

	auto emptyTest = eqx::zip(std::vector<int>(), std::vector<int>());
	UnitTester::test(emptyTest, std::vector<std::pair<int, int>>());

	auto diffCollectionTest = eqx::zip(
		std::vector<int>({ 1, 2, 3 }),
		std::array<int, 3ULL>({ 1, 2, 3 }));
	UnitTester::test(diffCollectionTest, std::vector<std::pair<int, int>>({
		{ 1, 1 },
		{ 2, 2 },
		{ 3, 3 }
	}));

	auto diffCollectionTest2 = eqx::zip(
		std::vector<int>({ 1, 2, 3 }),
		std::map<int, int>({ 
			{ 1, 1 },
			{ 2, 2 },
			{ 3, 3 }
		}));
	UnitTester::test(diffCollectionTest2, 
		std::vector<std::pair<int, std::pair<const int, int>>>({
			{ 1, { 1, 1 } },
			{ 2, { 2, 2 } },
			{ 3, { 3, 3 } }
		}));

	auto diffCollectionTest3 = eqx::zip(
		std::unordered_map<int, std::string_view>({
			{ 0, "XX"sv },
			{ 10'000, "x"sv }
		}),
		std::set<double>({ 0.001, 11.12234 }));
	UnitTester::test(diffCollectionTest3,
		std::vector<std::pair<
			std::pair<const int, std::string_view>, double>>({
			{ { 0, "XX"sv }, 0.001 },
			{ { 10'000, "x"sv }, 11.12234 }
		}));

	auto diffHeldTypeTest = eqx::zip(
		std::vector<std::string_view>({ "Hello"sv, "Goodbye"sv }),
		std::vector<double>({ 1.0, 2.0 }));
	UnitTester::test(diffHeldTypeTest,
		std::vector<std::pair<std::string_view, double>>({
			{ "Hello"sv, 1.0 },
			{ "Goodbye"sv, 2.0 }
		}));
}