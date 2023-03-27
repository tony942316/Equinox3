#include "LogTester.hpp"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <source_location>

#include <array>

#include "UnitTest.hpp"
#include "Log.hpp"

void testLog();
void testSetLevel();
void testSetOutputStream();
void testSetOutputFile();
void testClear();
void testGetFormattedString();

namespace LogTester
{
	void test()
	{
		std::cout << "Testing Log..." << std::endl;
		auto prevLogLevel = eqx::Log::getCurrentLogLevel();
		testLog();
		testSetLevel();
		testSetOutputStream();
		testSetOutputFile();
		testClear();
		testGetFormattedString();
		UnitTester::printStatus();
		UnitTester::clear();
		eqx::Log::setLevel(prevLogLevel);
		auto cleanFile = std::ofstream("Log.txt",
			std::ios::out | std::ios::trunc);
		cleanFile.close();
	}
}

void testLog()
{
	using namespace std::string_view_literals;

	auto ss = std::stringstream();
	auto produced = std::string("");
	auto loc = std::source_location::current();
	eqx::Log::setOutputStream(ss);
	eqx::Log::setLevel(eqx::Log::Level::all);
	
	eqx::Log::log(eqx::Log::Level::error, "TestLog"sv, eqx::Log::Type::none, 
		loc);
	eqx::Log::log(eqx::Log::Level::warning, "TestLog"sv, eqx::Log::Type::none,
		loc);

	std::getline(ss, produced);
	UnitTester::test(produced,
		eqx::Log::getFormattedString(loc, eqx::Log::Level::error, 
			"TestLog"sv));
	std::getline(ss, produced);
	UnitTester::test(produced,
		eqx::Log::getFormattedString(loc, eqx::Log::Level::warning,
			"TestLog"sv));

	eqx::Log::log(eqx::Log::Level::error, "TestLog"sv,
		eqx::Log::Type::runtimeError);
	UnitTester::test(eqx::Log::getLastLogType(), eqx::Log::Type::runtimeError);
}

void testSetLevel()
{
	eqx::Log::setLevel(eqx::Log::Level::all);
	UnitTester::test(eqx::Log::getCurrentLogLevel(), eqx::Log::Level::all);
	eqx::Log::setLevel(eqx::Log::Level::info);
	UnitTester::test(eqx::Log::getCurrentLogLevel(), eqx::Log::Level::info);
	eqx::Log::setLevel(eqx::Log::Level::warning);
	UnitTester::test(eqx::Log::getCurrentLogLevel(), eqx::Log::Level::warning);
	eqx::Log::setLevel(eqx::Log::Level::error);
	UnitTester::test(eqx::Log::getCurrentLogLevel(), eqx::Log::Level::error);
	eqx::Log::setLevel(eqx::Log::Level::none);
	UnitTester::test(eqx::Log::getCurrentLogLevel(), eqx::Log::Level::none);
}

void testSetOutputStream()
{
	using namespace std::string_literals;
	using namespace std::string_view_literals;

	auto ss = std::stringstream();
	auto produced = std::string("");
	eqx::Log::setLevel(eqx::Log::Level::all);
	eqx::Log::setOutputStream(ss);

	eqx::Log::log(eqx::Log::Level::error, "testOutputStream"sv);
	std::getline(ss, produced);
	UnitTester::test(produced, ""s, ""sv, NEQ<std::string, std::string>);

	auto ss2 = std::stringstream();
	eqx::Log::setOutputStream(ss2);

	eqx::Log::log(eqx::Log::Level::error, "testOutputStream"sv);
	std::getline(ss2, produced);
	UnitTester::test(produced, ""s, ""sv, NEQ<std::string, std::string>);

	std::getline(ss, produced);
	UnitTester::test(produced, ""s);
}

void testSetOutputFile()
{
	using namespace std::string_view_literals;
	using namespace std::string_literals;

	auto ss = std::stringstream();
	auto produced = std::string("");
	auto loc = std::source_location::current();
	eqx::Log::setLevel(eqx::Log::Level::all);
	eqx::Log::setOutputStream(ss);
	eqx::Log::setOutputFile("TestOutputFile.txt"sv);

	eqx::Log::log(eqx::Log::Level::error, "testOutputFile"sv, 
		eqx::Log::Type::none, loc);
	eqx::Log::setOutputFile("Log.txt"sv);
	auto file = std::ifstream("testOutputFile.txt"s, std::ios::in);
	std::getline(file, produced);

	UnitTester::test(produced, eqx::Log::getFormattedString(loc, 
		eqx::Log::Level::error, "testOutputFile"sv));
	file.close();
}

void testClear()
{
	using namespace std::string_view_literals;

	auto ss = std::stringstream();
	eqx::Log::setOutputStream(ss);
	eqx::Log::setLevel(eqx::Log::Level::all);

	eqx::Log::log(eqx::Log::Level::error, "testClear"sv, 
		eqx::Log::Type::runtimeError);

	UnitTester::test(eqx::Log::getLastLogType(), eqx::Log::Type::runtimeError);
	UnitTester::test(eqx::Log::getLastLogMessage(), "testClear"sv);
	eqx::Log::clear();
	UnitTester::test(eqx::Log::getLastLogType(), eqx::Log::Type::none);
	UnitTester::test(eqx::Log::getLastLogMessage(), ""sv);
}

void testGetFormattedString()
{
	using namespace std::string_view_literals;

	auto loc = std::source_location::current();
	auto lineNumber = std::to_string(loc.line());

	auto produced = eqx::Log::getFormattedString(loc, eqx::Log::Level::error,
		"testFString"sv);
	auto expected = std::string("..\\LogTester.cpp(testGetFormattedString,"sv);
	expected += lineNumber;
	expected += ") [ERROR]: testFString"sv;

	UnitTester::test(produced, expected);
}

void testGetLoggableLevels()
{
	constexpr auto produced = eqx::Log::getLoggableLevels();
	constexpr auto expected = std::array<eqx::Log::Level, 3ULL>({
			eqx::Log::Level::info,
			eqx::Log::Level::warning,
			eqx::Log::Level::error
		});
	static_assert(produced == expected);
}