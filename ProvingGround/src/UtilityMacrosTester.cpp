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

#include "UtilityMacrosTester.hpp"

#include <iostream>

#include <array>

#include "UnitTest.hpp"
#include "eqx_UtilityMacros.hpp"

namespace UtilityMacrosTester
{
	void test()
	{
		std::cout << "Testing UtilityMacros..." << std::endl;
		UnitTester::printStatus();
		UnitTester::clear();
	}
	consteval void testCountArgs();
	consteval void testStringArgs();
	consteval void testForEach();
	consteval void testForEachList();
}

consteval void UtilityMacrosTester::testCountArgs()
{
	static_assert(std::is_same_v<decltype(EQX_COUNT_ARGS(1, 2, 3)), 
		unsigned int>);
	static_assert(EQX_COUNT_ARGS(1, 2, 3, 4, 5) == 5ULL);
}

consteval void UtilityMacrosTester::testStringArgs()
{
	static_assert(std::is_same_v<decltype(EQX_STRING_ARGS(1)), decltype("1")>);
	constexpr auto arr = std::array<const char*, 5ULL>({
		EQX_STRING_ARGS(1, 2, 3, 4, 5)
	});
	static_assert(arr == std::array<const char*, 5ULL>({
		"1", "2", "3", "4", "5"
	}));
}

#define TEST_FOR_EACH_MACRO1(x) static_assert(x); val++;
#define TEST_FOR_EACH_MACRO2(x) static_assert(!x); val++;

consteval void UtilityMacrosTester::testForEach()
{
	constexpr auto testForEachAux = []() constexpr
	{
		std::size_t val = 0;
		EQX_FOR_EACH(TEST_FOR_EACH_MACRO1, true, true, true);
		EQX_FOR_EACH(TEST_FOR_EACH_MACRO2, false, false, false);
		return val;
	};
	static_assert(testForEachAux() == 6ULL);
}

#define TEST_FOR_EACH_LIST_MACRO(x) #x
consteval void UtilityMacrosTester::testForEachList()
{
#pragma warning(push)
#pragma warning(disable: 4100)
	constexpr auto testForEachListAux = []<typename... Types>
		(Types... args) constexpr
		{
			return static_cast<std::size_t>(sizeof...(args));
		};
#pragma warning(pop)


	constexpr auto x = testForEachListAux
		(EQX_FOR_EACH_LIST(TEST_FOR_EACH_LIST_MACRO, a, b, c, d, e, f, g));
	static_assert(x == 7ULL);

	constexpr auto arr = std::array<const char*, 3ULL>({ 
		EQX_FOR_EACH_LIST(TEST_FOR_EACH_LIST_MACRO, 1, 2, 3)
	});
	static_assert(arr == std::array<const char*, 3ULL>({ "1", "2", "3" }));
}