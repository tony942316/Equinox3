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

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <string_view>
#include <sstream>
#include <functional>
#include <source_location>

#include <vector>

template <class T, class U>
class UnitTestFunction
{
public:
	UnitTestFunction(const std::function<bool(T, U)>& func,
		std::string_view string)
		:
		m_Function(func),
		m_String(string)
	{
	}
	
	~UnitTestFunction() = default;

	UnitTestFunction(const UnitTestFunction&) = delete;
	UnitTestFunction(UnitTestFunction&&) = delete;
	UnitTestFunction& operator= (const UnitTestFunction&) = delete;
	UnitTestFunction& operator= (UnitTestFunction&&) = delete;

	bool operator()(T x, U y) const
	{
		return m_Function(x, y);
	}

	const std::function<bool(T, U)>& getFunction() const
	{
		return m_Function;
	}

	std::string_view toString() const noexcept
	{
		return m_String;
	}

private:
	std::function<bool(T, U)> m_Function;
	std::string_view m_String;
};

template <typename T, typename U>
const UnitTestFunction EQ = UnitTestFunction(
	std::function([](T x, U y) noexcept
	{ 
		if constexpr (std::is_floating_point_v<T> ||
			std::is_floating_point_v<U>)
		{
			return std::fabs(x - y) < 0.00001L;
		}
		else
		{
			return x == y; 
		}
	}),
	std::string_view(" == "));

template <typename T, typename U, typename V, typename W>
const UnitTestFunction PEQ = UnitTestFunction(
	std::function([](std::pair<T, U> p1, std::pair<V, W> p2)
	{
		return EQ<T, U>(p1.first, p2.first) && EQ<V, W>(p1.second, p2.second);
	}),
	" =p= ");

template <typename T, typename U>
const UnitTestFunction NEQ = UnitTestFunction(
	std::function([](T x, U y) { return x != y; }),
	" != ");

template <typename T, typename U>
const UnitTestFunction GT = UnitTestFunction(
	std::function([](T x, U y) { return x > y; }),
	" > ");

template <typename T, typename U>
const UnitTestFunction GTE = UnitTestFunction(
	std::function([](T x, U y) { return x >= y; }),
	std::string_view(" >= "));

template <typename T, typename U>
const UnitTestFunction LT = UnitTestFunction(
	std::function([](T x, U y) { return x < y; }),
	" < ");

template <typename T, typename U>
const UnitTestFunction LTE = UnitTestFunction(
	std::function([](T x, U y) { return x <= y; }),
	" <= ");

class UnitTester
{
public:
	template <typename T, typename U>
	static void test(const T& val1, const U& val2, 
		const UnitTestFunction<T, U>& func = EQ<T, U>, 
		std::string_view info = "", 
		const std::source_location& loc = std::source_location::current())
	{
		if (!func(val1, val2))
		{
			s_FailedTests.emplace_back(
				makeString(val1, val2, info, func, loc));
			
		}
	}

	static bool isPassing() noexcept
	{
		if (s_FailedTests.size() == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	static void printStatus(std::size_t num = 3)
	{

		if (isPassing())
		{
			std::cout << "Pass!" << std::endl;
		}
		else
		{
			std::cout << "Fail!\n" << std::endl;
			auto i = 0U;
			for (; i < num && i < s_FailedTests.size(); i++)
			{
				std::cout << i + 1 << ")" << std::endl;
				std::cout << s_FailedTests.at(i) << "\n" << std::endl;
			}

			if (i < s_FailedTests.size())
			{
				std::cout << i + 1 << ")...\n" << std::endl;
			}
		}
	}

	static void clear() noexcept
	{
		s_FailedTests.clear();
	}

private:
	template <typename T>
		requires(requires(T x) { std::stringstream() << x; })
	static std::string toString(T x)
	{
		auto ss = std::stringstream();
		ss << std::setprecision(100);
		ss << std::boolalpha;
		auto result = std::string("");
		ss << x;
		std::getline(ss, result);
		return result;
	}

	template <typename T>
	static std::string toString(const std::vector<T>& x)
	{
		auto result = std::string("");
		result += "{ ";
		std::ranges::for_each(x,
			[&result](const auto& val)
			{
				result += toString(val);
				result += ", ";
			});
		result.pop_back();
		result.pop_back();
		result += " }";
		return result;
	}

	template <typename T, std::size_t U>
	static std::string toString(const std::array<T, U>& x)
	{
		auto v = std::vector<T>();
		v.resize(U);
		std::copy(x.cbegin(), x.cend(), v.begin());
		return toString(v);
	}

	template <typename T, typename U>
	static std::string toString(std::pair<T, U> x)
	{
		auto result = std::string("");
		result += "(";
		result += toString(x.first);
		result += ", ";
		result += toString(x.second);
		result += ")";
		return result;
	}

	template <typename T, typename U>
	static std::string makeString(const T& val1, const U& val2,
		std::string_view info, const UnitTestFunction<T, U>& func,
		const std::source_location& loc)
	{
		auto val1Str = toString(val1);
		auto val2Str = toString(val2);

		auto locationString = std::string("");
		locationString += loc.file_name();
		locationString.erase(0ULL, locationString.rfind('\\') + 1);
		locationString += "(";
		locationString += loc.function_name();
		locationString += ",";
		locationString += std::to_string(loc.line());
		locationString += ")";

		auto result = std::string("");
		result += "Evaluated To False: ";
		result += val1Str + std::string(func.toString()) +
			val2Str + "\n";
		result += std::string("Location: ") + locationString;
		if (info != "")
		{
			result += "\nInfo: " + std::string(info);
		}

		return result;
	}

	static std::vector<std::string> s_FailedTests;
};

/*
class Primitives
{
public:
	Primitives() noexcept;

	std::vector<std::string> primitives;
	std::vector<std::string> volatilePrimitives;
	std::vector<std::string> constPrimitives;
	std::vector<std::string> constVolatilePrimitives;

	std::vector<std::string> containerPrimitives;
	std::vector<std::string> allPrimitives;

	std::vector<std::string> strings;
	std::vector<std::string> volatileStrings;
	std::vector<std::string> constStrings;
	std::vector<std::string> constVolatileStrings;

	std::vector<std::string> allStrings;

	std::vector<std::string> allVectors;
	std::vector<std::string> allLists;
	std::vector<std::string> allFLists;
	std::vector<std::string> allSets;
	std::vector<std::string> allUSets;
	std::vector<std::string> allQueues;
	std::vector<std::string> allPQueues;
	std::vector<std::string> allDeques;
	std::vector<std::string> allStacks;
	std::vector<std::string> allArrays;
	std::vector<std::string> allMaps;
	std::vector<std::string> allUMaps;

	std::vector<std::string> allRangeCollections;
	std::vector<std::string> allNonRangeCollections;
	std::vector<std::string> allCollections;

private:
	void makePrimitives();
	void makeStrings();
	void makeCollections();

	void appendStrVector(std::vector<std::string>& appendi,
		const std::vector<std::string>& appender);
};

std::vector<std::string> makeMacroString(const std::string& macroName,
	const std::vector<std::string>& macroDefTokens);
void makeMacros();*/