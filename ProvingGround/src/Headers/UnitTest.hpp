#pragma once

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

template <class T, class U>
class UnitTestFunction
{
public:
	UnitTestFunction(const std::function<bool(T, U)>& func,
		const std::string& string)
		:
		m_Function(func),
		m_String(string)
	{

	}

	UnitTestFunction(const UnitTestFunction&) = default;
	UnitTestFunction(UnitTestFunction&&) = default;
	UnitTestFunction& operator= (const UnitTestFunction&) = default;
	UnitTestFunction& operator= (UnitTestFunction&&) = default;
	~UnitTestFunction() = default;

	const std::function<bool(T, U)>& getFunction() const noexcept
	{
		return m_Function;
	}

	const std::string& getString() const noexcept
	{
		return m_String;
	}

private:
	std::function<bool(T, U)> m_Function;
	std::string m_String;
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
};