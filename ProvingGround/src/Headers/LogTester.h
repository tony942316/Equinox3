#pragma once

#include <sstream>
#include <string>
#include <vector>
#include <source_location>

#include "Log.h"

#include "UnitTest.h"

class LogTester
{
public:
	LogTester() = delete;
	LogTester(const LogTester&) = delete;
	LogTester(LogTester&&) = delete;
	LogTester& operator= (const LogTester&) = delete;
	LogTester& operator= (LogTester&&) = delete;

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

	static std::string m_FileName;
	static std::stringstream m_SS;
	static UnitTest<std::string, std::string> m_StringTests;
	static UnitTest<eqx::Log::Type, eqx::Log::Type> m_TypeTests;
	static std::source_location m_Location;
};