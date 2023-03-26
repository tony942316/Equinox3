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

	std::string_view toString() const
	{
		return m_String;
	}

private:
	std::function<bool(T, U)> m_Function;
	std::string_view m_String;
};

template <typename T, typename U>
const UnitTestFunction EQ = UnitTestFunction(
	std::function([](T x, U y) { return x == y; }),
	" == ");

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
	" >= ");

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
		std::string_view info = "", 
		const UnitTestFunction<T, U>& func = EQ<T, U>, 
		const std::source_location& loc = std::source_location::current())
	{
		if (!func(val1, val2))
		{
			s_FailedTests.emplace_back(
				makeString(val1, val2, info, func, loc));
			
		}
	}

	static bool isPassing()
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

	static void printStatus(int num = 3)
	{
		std::cout << std::setprecision(20);
		std::cout << std::boolalpha;

		if (isPassing())
		{
			std::cout << "Pass!" << std::endl;
		}
		else
		{
			std::cout << "Fail!\n" << std::endl;
			auto i = 0ULL;
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

		std::cout << std::noboolalpha;
		std::cout << std::setprecision(6);
	}

	static void clear()
	{
		s_FailedTests.clear();
	}

public:
	template <typename T>
		requires(requires(T x) { std::stringstream() << x; })
	static std::string toString(T x)
	{
		auto ss = std::stringstream();
		auto result = std::string("");
		ss << x;
		std::getline(ss, result);
		return result;
	}

	template <typename T>
	static std::string toString(std::vector<T> x)
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
		locationString += std::string(" -> ") + loc.function_name();

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

class Primitives
{
public:
	Primitives();

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
void makeMacros();








/*
#include <functional>
#include <vector>
#include <tuple>
#include <source_location>
#include <string>
#include <iostream>
#include <iomanip>
#include <type_traits>
#include <cassert>
#include <algorithm>

template <typename T, typename U>
std::ostream& operator<< (std::ostream& os, std::pair<T, U> p)
{
	return os << "(" << p.first << ", " << p.second << ")";
}

template <typename T, typename U>
bool TEST(T Produced, U Expected,
		  const UnitTestFunction<T, U>& func = EQ<T, U>,
		  const std::string& additionInfo = "",
		  const std::source_location& loc = std::source_location::current())
{
	if (!func.getFunction()(Produced, Expected))
	{
		std::cout << std::setprecision(20);
		std::cout << std::boolalpha;

		std::string fileName(loc.file_name()),
					functionName(loc.function_name());

		fileName.erase(fileName.begin(), 
			fileName.begin() + fileName.rfind('\\') + 1);
		fileName.erase(fileName.begin() + fileName.rfind('.'), fileName.end());

		std::cout << fileName + " -> " + functionName + " Failure!\n";
		std::cout << "Evaluated To False: " <<
			Produced << func.getString() << Expected << std::endl;

		if (additionInfo != "")
		{
			std::cout << additionInfo << std::endl;
		}

		std::cout << std::noboolalpha;
		std::cout << std::setprecision(6);
		return false;
	}
	else
	{
		return true;
	}
}

class UnitTestBase
{
public:
	virtual bool test(const std::source_location& loc =
		std::source_location::current()) const = 0;

	virtual void clear() = 0;
};

template <class T, class U>
class UnitTest : public UnitTestBase
{
public:
	UnitTest()
	{
		m_Tests.reserve(1'000'000);
	}

	~UnitTest() = default;

	UnitTest(const UnitTest&) = delete;
	UnitTest(UnitTest&&) = delete;
	UnitTest& operator= (const UnitTest&) = delete;
	UnitTest& operator= (UnitTest&&) = delete;

	void addTest(
		const std::tuple<T, U, UnitTestFunction<T, U>, std::string>& test)
	{
		m_Tests.emplace_back(test);
	}

	void addTest(const T& val1, const U& val2,
		const std::string& info = "",
		const UnitTestFunction<T, U>& func = EQ<T, U>)
	{
		addTest(std::make_tuple(val1, val2, func, info));
	}

	void clear() override
	{
		m_Tests.clear();
	}

	bool test(const std::source_location& loc = 
		std::source_location::current()) const override
	{
		bool pass = true;
		for (const std::tuple<T, U, UnitTestFunction<T, U>, std::string>& 
				test : m_Tests)
		{
			pass = pass &&
				TEST(std::get<0>(test),
					 std::get<1>(test),
					 std::get<2>(test),
					 std::get<3>(test),
					 loc);
		}
		return pass;
	}

private:
	std::vector<std::tuple<T, U, UnitTestFunction<T, U>, std::string>> m_Tests;
};

class UniversalTester
{
public:
	template <typename T, typename U>
	void addTest(const T& val1, const U& val2,
				 const std::string& info = "",
				 const UnitTestFunction<T, U>& func = EQ<T, U>)
	{
		static UnitTest<T, U> tests;
		if (std::find(m_UnitTests.begin(), m_UnitTests.end(), &tests) ==
			m_UnitTests.end())
		{
			m_UnitTests.push_back(&tests);
		}
		tests.addTest(val1, val2, info, func);
	}

	template<typename C1, typename C2, 
			 typename T = C1::value_type, typename U = C2::value_type>
	void addBulkTests(const C1& expectedVals, const C2& producedVals,
					  const std::vector<std::string>& infoVals =
						  std::vector<std::string>(),
					  const std::vector<UnitTestFunction<T, U>>& functions =
							std::vector<UnitTestFunction<T, U>>())
	{
		assert(expectedVals.size() == producedVals.size());
		assert((void*)(&expectedVals) != (void*)(&producedVals));

		std::string info("");
		UnitTestFunction<T, U> func(EQ<T, U>);

		for (std::size_t i = 0ULL; i < producedVals.size(); i++)
		{
			info = infoVals.size() == 0ULL ? "" : infoVals.at(i);
			func = functions.size() == 0ULL ? 
				UnitTestFunction<T, U>(EQ<T, U>) : functions.at(i);
			addTest(expectedVals.at(i), producedVals.at(i), info, func);
		}
	}

	bool test(const std::source_location& loc =
		std::source_location::current())
	{
		bool pass = true;
		std::for_each(m_UnitTests.begin(), m_UnitTests.end(),
			[&pass, &loc](UnitTestBase* unitTest)
			{
				pass = pass && unitTest->test(loc);
				unitTest->clear();
			});
		return pass;
	}

private:
	std::vector<UnitTestBase*> m_UnitTests;
};*/