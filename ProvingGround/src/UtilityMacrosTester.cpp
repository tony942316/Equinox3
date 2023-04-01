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
		std::size_t>);
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
	constexpr auto testForEachListAux = []<typename... Types>
		(Types... args) constexpr
		{
			return static_cast<std::size_t>(sizeof...(args));
		};

	constexpr auto x = testForEachListAux
		(EQX_FOR_EACH_LIST(TEST_FOR_EACH_LIST_MACRO, a, b, c, d, e, f, g));
	static_assert(x == 7ULL);

	constexpr auto arr = std::array<const char*, 3ULL>({ 
		EQX_FOR_EACH_LIST(TEST_FOR_EACH_LIST_MACRO, 1, 2, 3)
	});
	static_assert(arr == std::array<const char*, 3ULL>({ "1", "2", "3" }));
}