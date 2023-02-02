#pragma once

#include <functional>
#include <vector>
#include <tuple>
#include <source_location>
#include <string>
#include <iostream>
#include <iomanip>
#include <type_traits>

template <typename T, typename U>
const std::function<bool(T, U)> EQ2 = [](T x, U y) { return x == y; };

template <typename T, typename U>
std::function<bool(T, U)> EQ()
{
	return [](T x, U y) { return x == y; };
}

template <typename T, typename U>
std::function<bool(T, U)> NEQ()
{
	return [](T x, U y) { return x != y; };
}

template <typename T, typename U>
std::function<bool(T, U)> GT()
{
	return [](T x, U y) { return x > y; };
}

template <typename T, typename U>
std::function<bool(T, U)> GTE()
{
	return [](T x, U y) { return x >= y; };
}

template <typename T, typename U>
std::function<bool(T, U)> LT()
{
	return [](T x, U y) { return x < y; };
}

template <typename T, typename U>
std::function<bool(T, U)> LTE()
{
	return [](T x, U y) { return x <= y; };
}

template <typename T, typename U>
bool TEST(T Produced, U Expected,
		  std::function<bool(T, U)> func = EQ2<T, U>,
		  const std::source_location& loc = std::source_location::current())
{
	if (!func(Produced, Expected))
	{
		std::cout << std::setprecision(20);
		std::cout << std::boolalpha;
		std::string
			fileName = loc.file_name(),
			functionName = loc.function_name();
		fileName.erase(fileName.begin(), 
			fileName.begin() + fileName.rfind('\\') + 1);
		fileName.erase(fileName.begin() + fileName.rfind('.'), fileName.end());
		std::cout << fileName << " -> " << functionName << 
			" Failure!\nExpected: " << Expected << "\n" <<
			"Produced: " << Produced << std::endl;
		std::cout << std::noboolalpha;
		std::cout << std::setprecision(6);
		return false;
	}
	else
	{
		return true;
	}
}

template <typename T, typename U>
bool TESTALL(const std::vector<std::pair<T, U>>& tests,
			 std::function<bool(T, U)> func = EQ2<T, U>,
			 const std::source_location& loc = std::source_location::current())
{
	bool pass = true;
	for (const std::pair<T, U>& test : tests)
	{
		pass = TEST(test.first, test.second, func, loc) && pass;
	}
	return pass;
}

template <typename T, typename U>
bool TestAll2(
	const std::vector<std::tuple<T, U, std::function<bool(T, U)>>>& tests,
	const std::source_location& loc = std::source_location::current())
{
	bool pass = true;
	for (const std::tuple<T, U, std::function<bool(T, U)>>& test : tests)
	{
		pass = pass &&
			TEST(std::get<0>(test),
				std::get<1>(test),
				std::get<2>(test) ?
				std::get<2>(test) :
				EQ2<T, U>,
				loc);
	}
	return pass;
}

template <class T, class U>
class UnitTest
{
public:
	UnitTest()
		:
		m_ProducedIndex(0ULL),
		m_ExpectedIndex(0ULL),
		m_FunctionIndex(0ULL)
	{
		m_Tests.reserve(1'000'000);
	}

	UnitTest(const UnitTest&) = delete;
	UnitTest(UnitTest&&) = delete;
	UnitTest& operator= (const UnitTest&) = delete;
	UnitTest& operator= (UnitTest&&) = delete;

	void addProducedValue(const T& val)
	{
		if (m_ProducedIndex >= m_Tests.size())
		{
			m_Tests.resize(m_Tests.size() + 100);
		}
		std::tuple<T, U, std::function<bool(T, U)>>& test = 
			m_Tests[m_ProducedIndex];
		std::get<0>(test) = val;
		m_ProducedIndex++;
	}

	void addProducedValues(std::function<std::vector<T>()> func)
	{
		addProducedValues(func());
	}

	void addProducedValues(const std::vector<T>& vals)
	{
		for (const T& val : vals)
		{
			addProducedValue(val);
		}
	}

	void addExpectedValue(const U& val)
	{
		if (m_ExpectedIndex >= m_Tests.size())
		{
			m_Tests.resize(m_Tests.size() + 100);
		}
		std::tuple<T, U, std::function<bool(T, U)>>& test =
			m_Tests[m_ExpectedIndex];
		std::get<1>(test) = val;
		m_ExpectedIndex++;
	}

	void addExpectedValues(std::function<std::vector<U>()> func)
	{
		addExpectedValues(func());
	}

	void addExpectedValues(const std::vector<U>& vals)
	{
		for (const T& val : vals)
		{
			addExpectedValue(val);
		}
	}

	void addFunction(const std::function<bool(T, U)>& val)
	{
		if (m_FunctionIndex >= m_Tests.size())
		{
			m_Tests.resize(m_Tests.size() + 100);
		}
		std::tuple<T, U, std::function<bool(T, U)>>& test =
			m_Tests[m_FunctionIndex];
		std::get<2>(test) = val;
		m_FunctionIndex++;
	}

	void addFunctions(const std::vector<std::function<bool(T, U)>>& vals)
	{
		for (const std::function<bool(T, U)>& val : vals)
		{
			addFunction(val);
		}
	}

	void addTest(const std::tuple<T, U, std::function<bool(T, U)>>& test)
	{
		m_Tests.emplace_back(test);
		m_ProducedIndex++;
		m_ExpectedIndex++;
		m_FunctionIndex++;
	}

	void clear()
	{
		m_Tests.clear();
		m_ProducedIndex = 0ULL;
		m_ExpectedIndex = 0ULL;
		m_FunctionIndex = 0ULL;
	}

	bool test(
		const std::source_location& loc = 
		std::source_location::current()) const
	{
		return TestAll2<T, U>(m_Tests, loc);
	}

private:
	std::vector<std::tuple<T, U, std::function<bool(T, U)>>> m_Tests;
	std::size_t m_ProducedIndex, m_ExpectedIndex, m_FunctionIndex;
};