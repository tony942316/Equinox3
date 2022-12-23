#include "LogTester.h"

#include <iostream>
#include <source_location>

#include "Log.h"

#include "UnitTest.h"

LogTester::LogTester()
	:
	m_FileName("TestOutputFile.txt")
{
	eqx::Log::setOutputFile(m_FileName);
	eqx::Log::setOutputStream(m_SS);
	eqx::Log::setLevel(eqx::Log::Level::info);
}

LogTester::~LogTester()
{
	eqx::Log::setOutputFile("Log.txt");
	eqx::Log::setOutputStream(std::cout);
	eqx::Log::setLevel(eqx::Log::Level::none);
}

bool LogTester::testAll()
{
	if (testLog() &&
		testSetLevel() &&
		testSetOutputStream() &&
		testSetOutputFile() &&
		testClear() &&
		testGetLastLogType() &&
		testGetLastLogMessage())
	{
		std::cout << "Log Tests Passed" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Log Tests Failed!" << std::endl;
		return false;
	}
}

bool LogTester::testLog()
{
	eqx::Log::clear();
	m_SS = std::stringstream();

	std::source_location location = std::source_location::current();
	std::string
		actual = "",
		expected = "..\\LogTester.cpp(testLog," + std::to_string(location.line()) + ") [ERROR]: Testing Logging";
	eqx::Log::log(eqx::Log::Level::error, "Testing Logging", eqx::Log::Type::runtimeError, location);
	std::getline(m_SS, actual);

	return TEST(actual, expected);
}

bool LogTester::testSetLevel()
{
	eqx::Log::clear();
	m_SS = std::stringstream();

	std::vector<std::tuple<std::string, std::string>> tests;
	std::source_location location = std::source_location::current();

	std::string
		actual = "",
		expected = "..\\LogTester.cpp(testSetLevel," + std::to_string(location.line()) + ") [INFO]: Should Stream";
	eqx::Log::setLevel(eqx::Log::Level::info);
	eqx::Log::log(eqx::Log::Level::info, "Should Stream", eqx::Log::Type::none, location);
	std::getline(m_SS, actual);
	tests.emplace_back(actual, expected);

	expected = "";
	eqx::Log::setLevel(eqx::Log::Level::error);
	eqx::Log::log(eqx::Log::Level::info, "Shouldn't Stream", eqx::Log::Type::none, location);
	std::getline(m_SS, actual);
	tests.emplace_back(actual, expected);

	eqx::Log::setLevel(eqx::Log::Level::info);

	for (const std::tuple<std::string, std::string>& test : tests)
	{
		if (!TEST(std::get<0>(test), std::get<1>(test)))
		{
			return false;
		}
	}

	return true;
}

bool LogTester::testSetOutputStream()
{
	eqx::Log::clear();
	m_SS = std::stringstream();

	std::source_location location = std::source_location::current();
	std::string
		actual = "",
		expected = "..\\LogTester.cpp(testSetOutputStream," + std::to_string(location.line()) + ") [ERROR]: Testing Output Stream";
	eqx::Log::log(eqx::Log::Level::error, "Testing Output Stream", eqx::Log::Type::runtimeError, location);
	std::getline(m_SS, actual);

	return TEST(actual, expected);
}

bool LogTester::testSetOutputFile()
{
	eqx::Log::clear();
	m_SS = std::stringstream();

	std::source_location location = std::source_location::current();
	std::string
		actual = "",
		expected = "..\\LogTester.cpp(testSetOutputFile," + std::to_string(location.line()) + ") [ERROR]: Testing Output File";
	eqx::Log::setOutputFile(m_FileName);
	eqx::Log::log(eqx::Log::Level::error, "Testing Output File", eqx::Log::Type::runtimeError, location);
	std::fstream file(m_FileName);
	std::getline(file, actual);
	file.close();

	return TEST(actual, expected);
}

bool LogTester::testClear()
{
	eqx::Log::clear();
	m_SS = std::stringstream();

	std::source_location location = std::source_location::current();
	eqx::Log::log(eqx::Log::Level::error, "Testing Clear", eqx::Log::Type::runtimeError, location);
	eqx::Log::clear();

	if (!TEST(eqx::Log::getLastLogMessage(), "") ||
		!TEST(static_cast<int>(eqx::Log::getLastLogType()), static_cast<int>(eqx::Log::Type::none)))
	{
		return false;
	}

	return true;
}

bool LogTester::testGetLastLogType()
{
	eqx::Log::clear();
	m_SS = std::stringstream();

	std::source_location location = std::source_location::current();
	eqx::Log::log(eqx::Log::Level::error, "Testing Get Last Log Type", eqx::Log::Type::runtimeError, location);

	return TEST(static_cast<int>(eqx::Log::getLastLogType()), static_cast<int>(eqx::Log::Type::runtimeError));
}

bool LogTester::testGetLastLogMessage()
{
	eqx::Log::clear();
	m_SS = std::stringstream();

	std::source_location location = std::source_location::current();
	eqx::Log::log(eqx::Log::Level::error, "Testing Get Last Log Message", eqx::Log::Type::runtimeError, location);

	return TEST(eqx::Log::getLastLogMessage(), "Testing Get Last Log Message");
}