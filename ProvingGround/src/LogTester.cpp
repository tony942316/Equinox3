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

#include "LogTester.hpp"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <source_location>

#include <array>

#include "UnitTest.hpp"
#include "eqx_Log.hpp"

namespace LogTester
{
	void testLog();
	void testSetLevel();
	void testSetOutputStream();
	void testSetOutputFile();
	void testClear();
	void testGetFormattedString();

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

	consteval void testGetLoggableLevels();
}

void LogTester::testLog()
{
	using namespace std::string_view_literals;

	auto ss = std::stringstream();
	auto produced = std::string("");
	auto loc = std::source_location::current();
	eqx::Log::setOutputStream(ss);
	eqx::Log::setLevel(eqx::Log::Level::All);
	
	eqx::Log::log(eqx::Log::Level::Error, "TestLog"sv, eqx::Log::Type::None, 
		loc);
	eqx::Log::log(eqx::Log::Level::Warning, "TestLog"sv, eqx::Log::Type::None,
		loc);

	std::getline(ss, produced);
	UnitTester::test(produced,
		eqx::Log::getFormattedString(loc, eqx::Log::Level::Error, 
			"TestLog"sv));
	std::getline(ss, produced);
	UnitTester::test(produced,
		eqx::Log::getFormattedString(loc, eqx::Log::Level::Warning,
			"TestLog"sv));

	eqx::Log::log(eqx::Log::Level::Error, "TestLog"sv,
		eqx::Log::Type::RuntimeError);
	UnitTester::test(eqx::Log::getLastLogType(), eqx::Log::Type::RuntimeError);
}

void LogTester::testSetLevel()
{
	eqx::Log::setLevel(eqx::Log::Level::All);
	UnitTester::test(eqx::Log::getCurrentLogLevel(), eqx::Log::Level::All);
	eqx::Log::setLevel(eqx::Log::Level::Info);
	UnitTester::test(eqx::Log::getCurrentLogLevel(), eqx::Log::Level::Info);
	eqx::Log::setLevel(eqx::Log::Level::Warning);
	UnitTester::test(eqx::Log::getCurrentLogLevel(), eqx::Log::Level::Warning);
	eqx::Log::setLevel(eqx::Log::Level::Error);
	UnitTester::test(eqx::Log::getCurrentLogLevel(), eqx::Log::Level::Error);
	eqx::Log::setLevel(eqx::Log::Level::None);
	UnitTester::test(eqx::Log::getCurrentLogLevel(), eqx::Log::Level::None);
}

void LogTester::testSetOutputStream()
{
	using namespace std::string_literals;
	using namespace std::string_view_literals;

	auto ss = std::stringstream();
	auto produced = std::string("");
	eqx::Log::setLevel(eqx::Log::Level::All);
	eqx::Log::setOutputStream(ss);

	eqx::Log::log(eqx::Log::Level::Error, "testOutputStream"sv);
	std::getline(ss, produced);
	UnitTester::test(produced, ""s, NEQ<std::string, std::string>);

	auto ss2 = std::stringstream();
	eqx::Log::setOutputStream(ss2);

	eqx::Log::log(eqx::Log::Level::Error, "testOutputStream"sv);
	std::getline(ss2, produced);
	UnitTester::test(produced, ""s, NEQ<std::string, std::string>);

	std::getline(ss, produced);
	UnitTester::test(produced, ""s);
}

void LogTester::testSetOutputFile()
{
	using namespace std::string_view_literals;
	using namespace std::string_literals;

	auto ss = std::stringstream();
	auto produced = std::string("");
	auto loc = std::source_location::current();
	eqx::Log::setLevel(eqx::Log::Level::All);
	eqx::Log::setOutputStream(ss);
	eqx::Log::setOutputFile("TestOutputFile.txt"sv);

	eqx::Log::log(eqx::Log::Level::Error, "testOutputFile"sv, 
		eqx::Log::Type::None, loc);
	eqx::Log::setOutputFile("Log.txt"sv);
	auto file = std::ifstream("testOutputFile.txt"s, std::ios::in);
	std::getline(file, produced);

	UnitTester::test(produced, eqx::Log::getFormattedString(loc, 
		eqx::Log::Level::Error, "testOutputFile"sv));
	file.close();
}

void LogTester::testClear()
{
	using namespace std::string_view_literals;

	auto ss = std::stringstream();
	eqx::Log::setOutputStream(ss);
	eqx::Log::setLevel(eqx::Log::Level::All);

	eqx::Log::log(eqx::Log::Level::Error, "testClear"sv, 
		eqx::Log::Type::RuntimeError);

	UnitTester::test(eqx::Log::getLastLogType(), eqx::Log::Type::RuntimeError);
	UnitTester::test(eqx::Log::getLastLogMessage(), "testClear"sv);
	eqx::Log::clear();
	UnitTester::test(eqx::Log::getLastLogType(), eqx::Log::Type::None);
	UnitTester::test(eqx::Log::getLastLogMessage(), ""sv);
}

void LogTester::testGetFormattedString()
{
	using namespace std::string_view_literals;

	auto loc = std::source_location::current();
	auto lineNumber = std::to_string(loc.line());

	auto produced = eqx::Log::getFormattedString(loc, eqx::Log::Level::Error,
		"testFString"sv);
	auto expected = std::string("..\\LogTester.cpp"sv);
	expected += "(void __cdecl LogTester::testGetFormattedString(void),"sv;
	expected += lineNumber;
	expected += ") [ERROR]: testFString"sv;

	UnitTester::test(produced, expected);
}

consteval void LogTester::testGetLoggableLevels()
{
	constexpr auto produced = eqx::Log::getLoggableLevels();
	constexpr auto expected = std::array<eqx::Log::Level, 3ULL>({
			eqx::Log::Level::Info,
			eqx::Log::Level::Warning,
			eqx::Log::Level::Error
		});
	static_assert(produced == expected);
}