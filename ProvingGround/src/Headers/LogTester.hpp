#pragma once

#include <sstream>
#include <string>
#include <vector>
#include <source_location>

#include "Log.hpp"

#include "UnitTest.hpp"

class LogTester
{
public:
	LogTester() = delete;
	LogTester(const LogTester&) = delete;
	LogTester(LogTester&&) = delete;
	LogTester& operator= (const LogTester&) = delete;
	LogTester& operator= (LogTester&&) = delete;
	~LogTester() = delete;

	static bool test();

private:
	static bool testLog();
	static bool testSetLevel();
	static bool testSetOutputStream();
	static bool testSetOutputFile();
	static bool testClear();
	static bool testGetLastLogType();
	static bool testGetLastLogMessage();
	static bool testGetFormattedString();
	static void prep(const std::source_location& loc = 
		std::source_location::current());

	static std::string s_FileName;
	static std::stringstream s_SS;
	static UnitTest<std::string, std::string> s_StringTests;
	static UnitTest<eqx::Log::Type, eqx::Log::Type> s_TypeTests;
	static std::source_location s_Location;
};