#pragma once

#include <functional>
#include <vector>
#include <source_location>
#include <string>
#include <iostream>
#include <iomanip>
#include <type_traits>

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
		  std::function<bool(T, U)> func = EQ<T, U>(),
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
			 std::function<bool(T, U)> func = EQ<T, U>(),
			 const std::source_location& loc = std::source_location::current())
{
	bool pass = true;
	for (const std::pair<T, U>& test : tests)
	{
		pass = TEST(test.first, test.second, func, loc) && pass;
	}
	return pass;
}

template <class T, class U>
class UnitTest
{
public:
	UnitTest()
	{

	}

	UnitTest(const UnitTest&) = delete;
	UnitTest(UnitTest&&) = delete;
	UnitTest& operator= (const UnitTest&) = delete;
	UnitTest& operator= (UnitTest&&) = delete;

	void addProducedValue(const T& val)
	{
		m_ProducedValues.emplace_back(val);
	}

	void setProducedValues(std::function<std::vector<T>()> func)
	{
		m_ProducedValues = func();
	}

	void setProducedValues(const std::vector<T>& vals)
	{
		m_ProducedValues = vals;
	}

	void addExpectedValue(const U& val)
	{
		m_ExpectedValues.emplace_back(val);
	}

	void setExpectedValues(std::function<std::vector<U>()> func)
	{
		m_ExpectedValues = func();
	}

	void setExpectedValues(const std::vector<U>& vals)
	{
		m_ExpectedValues = vals;
	}

	void addTest(const T& produced, const U& expected)
	{
		addProducedValue(produced);
		addExpectedValue(expected);
	}

	void clear()
	{
		m_ProducedValues.clear();
		m_ExpectedValues.clear();
	}

	bool test(const std::source_location& loc = 
		std::source_location::current()) const
	{
		std::vector<std::pair<T, U>> tests;
		tests.reserve(m_ProducedValues.size());
		for (std::size_t i = 0; i < m_ProducedValues.size(); i++)
		{
			tests.emplace_back(m_ProducedValues[i], m_ExpectedValues[i]);
		}
		return TESTALL<T, U>(tests, EQ<T, U>(), loc);
	}

private:
	std::vector<T> m_ProducedValues;
	std::vector<U> m_ExpectedValues;
};