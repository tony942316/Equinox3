#include "LogTester.h"

#include <iostream>
#include <unordered_map>
#include <algorithm>

std::string LogTester::s_FileName{ "TestOutputFile.txt" };
std::stringstream LogTester::s_SS;
UnitTest<std::string, std::string> LogTester::s_StringTests;
UnitTest<eqx::Log::Type, eqx::Log::Type> LogTester::s_TypeTests;
std::source_location LogTester::s_Location;

bool LogTester::test()
{
	eqx::Log::setOutputFile(s_FileName);
	eqx::Log::setOutputStream(s_SS);
	eqx::Log::setLevel(eqx::Log::Level::all);

	bool pass = false;
	if (testLog() &&
		testSetLevel() &&
		testSetOutputStream() &&
		testSetOutputFile() &&
		testClear() &&
		testGetLastLogType() &&
		testGetLastLogMessage() &&
		testGetFormattedString())
	{
		std::cout << "Log Tests Passed" << std::endl;
		pass = true;
	}
	else
	{
		std::cout << "Log Tests Failed!" << std::endl;
		pass = false;
	}

	eqx::Log::setOutputFile("Log.txt");
	eqx::Log::setOutputStream(std::cout);
	eqx::Log::setLevel(eqx::Log::Level::none);

	return pass;
}

bool LogTester::testLog()
{
	prep();

	std::unordered_map<eqx::Log::Level, std::string> expectedStrings{
		{ eqx::Log::Level::info, eqx::Log::getFormattedString(
								 s_Location, eqx::Log::Level::info,
								 "Testing Logging Info") },
		{ eqx::Log::Level::warning, eqx::Log::getFormattedString(
									s_Location, eqx::Log::Level::warning,
									"Testing Logging Warning") },
		{ eqx::Log::Level::error, eqx::Log::getFormattedString(
								  s_Location, eqx::Log::Level::error,
								  "Testing Logging Error") }
	};
	std::unordered_map<eqx::Log::Level, std::string> logMsgStrings{
		{ eqx::Log::Level::info, "Testing Logging Info" },
		{ eqx::Log::Level::warning, "Testing Logging Warning" },
		{ eqx::Log::Level::error, "Testing Logging Error"}
	};
	std::string
		produced = "",
		expected = "";
	for (const eqx::Log::Level level : eqx::Log::getLoggableLevels())
	{
		expected = expectedStrings[level];

		eqx::Log::log(level, logMsgStrings[level], 
			eqx::Log::Type::none, s_Location);
		std::getline(s_SS, produced);
		s_StringTests.addTest(std::make_tuple(produced, expected, 
			EQ2<std::string, std::string>));

		produced = "";
		expected = "";
	}

	return s_StringTests.test();
}

bool LogTester::testSetLevel()
{
	prep();

	std::unordered_map<eqx::Log::Level, std::vector<eqx::Log::Level>> cutoffs{
		{ eqx::Log::Level::all, { eqx::Log::Level::info,
								  eqx::Log::Level::warning,
								  eqx::Log::Level::error } },
		{ eqx::Log::Level::info, { eqx::Log::Level::info,
								   eqx::Log::Level::warning,
								   eqx::Log::Level::error } },
		{ eqx::Log::Level::warning, { eqx::Log::Level::warning,
								      eqx::Log::Level::error } },
		{ eqx::Log::Level::error, { eqx::Log::Level::error } },
		{ eqx::Log::Level::none, {  } }
	};
	std::unordered_map<eqx::Log::Level, std::string> expectedStrings{
		{ eqx::Log::Level::info,  eqx::Log::getFormattedString(
									s_Location, eqx::Log::Level::info) },
		{ eqx::Log::Level::warning,  eqx::Log::getFormattedString(
									s_Location, eqx::Log::Level::warning) },
		{ eqx::Log::Level::error,  eqx::Log::getFormattedString(
									s_Location, eqx::Log::Level::error) }
	};
	std::string
		produced = "",
		expected = "",
		logMsg = "",
		shouldStream = "Should Stream",
		shouldNotStream = "Shouldn't Stream";

	for (const std::pair<const eqx::Log::Level, std::vector<eqx::Log::Level>>& 
		link :
		cutoffs)
	{
		eqx::Log::setLevel(link.first);
		for (const eqx::Log::Level level : eqx::Log::getLoggableLevels())
		{
			logMsg = std::find(link.second.begin(), 
				link.second.end(), level) != link.second.end() ? 
				shouldStream : shouldNotStream;
			expected = logMsg == shouldStream ? 
				expectedStrings[level] + logMsg : "";

			eqx::Log::log(level, logMsg, eqx::Log::Type::none, s_Location);
			if (s_SS.eof())
			{
				s_SS.clear();
			}
			std::getline(s_SS, produced);
			s_StringTests.addTest(std::make_tuple(produced, expected,
				EQ2<std::string, std::string>));

			produced = "";
			expected = "";
		}
	}

	eqx::Log::setLevel(eqx::Log::Level::all);

	return s_StringTests.test();
}

bool LogTester::testSetOutputStream()
{
	prep();

	std::unordered_map<eqx::Log::Level, std::string> expectedStrings{
		{ eqx::Log::Level::info, eqx::Log::getFormattedString(
								 s_Location, eqx::Log::Level::info,
								 "Testing Output Stream") },
		{ eqx::Log::Level::warning, eqx::Log::getFormattedString(
									s_Location, eqx::Log::Level::warning,
									"Testing Output Stream") },
		{ eqx::Log::Level::error, eqx::Log::getFormattedString(
								  s_Location, eqx::Log::Level::error,
								  "Testing Output Stream") }
	};
	std::string
		produced = "",
		expected = "",
		logMsg = "Testing Output Stream";
	std::stringstream ss;

	for (const eqx::Log::Level level : eqx::Log::getLoggableLevels())
	{
		expected = expectedStrings[level];

		ss = std::stringstream();
		eqx::Log::setOutputStream(ss);
		eqx::Log::log(level, logMsg, eqx::Log::Type::none, s_Location);
		std::getline(ss, produced);
		s_StringTests.addTest(std::make_tuple(produced, expected,
			EQ2<std::string, std::string>));

		produced = "";
		expected = "";
	}

	eqx::Log::setOutputStream(s_SS);

	return s_StringTests.test();
}

bool LogTester::testSetOutputFile()
{
	prep();

	std::unordered_map<eqx::Log::Level, std::string> expectedStrings{
		{ eqx::Log::Level::info, eqx::Log::getFormattedString(
								 s_Location, eqx::Log::Level::info,
								 "Testing Output File") },
		{ eqx::Log::Level::warning, eqx::Log::getFormattedString(
									s_Location, eqx::Log::Level::warning,
									"Testing Output File") },
		{ eqx::Log::Level::error, eqx::Log::getFormattedString(
								  s_Location, eqx::Log::Level::error,
								  "Testing Output File") }
	};
	std::string
		produced = "",
		expected = "",
		logMsg = "Testing Output File";

	for (const eqx::Log::Level level : eqx::Log::getLoggableLevels())
	{
		expected = expectedStrings[level];

		eqx::Log::setOutputFile(s_FileName);
		eqx::Log::log(level, logMsg, eqx::Log::Type::none, s_Location);
		std::fstream file(s_FileName);
		std::getline(file, produced);
		file.close();
		s_StringTests.addTest(std::make_tuple(produced, expected,
			EQ2<std::string, std::string>));

		produced = "";
		expected = "";
	}

	return s_StringTests.test();
}

bool LogTester::testClear()
{
	prep();

	std::string
		producedString = "",
		expectedString = "",
		logMsg = "Testing Clear";

	eqx::Log::Type
		producedType = eqx::Log::Type::none,
		expectedType = eqx::Log::Type::none;

	for (const eqx::Log::Level level : eqx::Log::getLoggableLevels())
	{
		for (const eqx::Log::Type type : eqx::Log::TypeGetTypes())
		{
			eqx::Log::log(level, logMsg, type, s_Location);
			producedString = eqx::Log::getLastLogMessage();
			producedType = eqx::Log::getLastLogType();
			expectedString = logMsg;
			expectedType = type;
			s_StringTests.addTest(
				std::make_tuple(producedString, expectedString,
					EQ2<std::string, std::string>));
			s_TypeTests.addTest(
				std::make_tuple(producedType, expectedType,
					EQ2<eqx::Log::Type, eqx::Log::Type>));
			eqx::Log::clear();
			producedString = eqx::Log::getLastLogMessage();
			expectedString = "";
			producedType = eqx::Log::getLastLogType();
			expectedType = eqx::Log::Type::none;
			s_StringTests.addTest(
				std::make_tuple(producedString, expectedString,
					EQ2<std::string, std::string>));
			s_TypeTests.addTest(
				std::make_tuple(producedType, expectedType,
					EQ2<eqx::Log::Type, eqx::Log::Type>));

			producedString = "";
			expectedString = "";
			producedType = eqx::Log::Type::none;
			expectedType = eqx::Log::Type::none;
		}
	}

	return s_StringTests.test() && s_TypeTests.test();
}

bool LogTester::testGetLastLogType()
{
	prep();

	std::string logMsg = "Testing Get Last Log Type";

	eqx::Log::Type
		producedType = eqx::Log::Type::none,
		expectedType = eqx::Log::Type::none;

	for (const eqx::Log::Level level : eqx::Log::getLoggableLevels())
	{
		for (const eqx::Log::Type type : eqx::Log::TypeGetTypes())
		{
			eqx::Log::log(level, logMsg, type, s_Location);
			producedType = eqx::Log::getLastLogType();
			expectedType = type;
			s_TypeTests.addTest(
				std::make_tuple(producedType, expectedType,
					EQ2<eqx::Log::Type, eqx::Log::Type>));
			producedType = eqx::Log::Type::none;
			expectedType = eqx::Log::Type::none;
		}
	}

	return s_TypeTests.test();
}

bool LogTester::testGetLastLogMessage()
{
	prep();

	std::string
		producedString = "",
		expectedString = "",
		logMsg = "Testing Get Last Message";

	for (const eqx::Log::Level level : eqx::Log::getLoggableLevels())
	{
		eqx::Log::log(level, logMsg, eqx::Log::Type::none, s_Location);
		producedString = eqx::Log::getLastLogMessage();
		expectedString = logMsg;
		s_StringTests.addTest(
			std::make_tuple(producedString, expectedString,
				EQ2<std::string, std::string>));
		producedString = "";
		expectedString = "";
	}

	return s_StringTests.test();
}

bool LogTester::testGetFormattedString()
{
	prep();

	std::string
		producedString = "",
		expectedStringBase = "",
		tempString = "",
		expectedString = "",
		logMsg = "Testing Get Formatted String";

	expectedStringBase += "..\\LogTester.cpp(testGetFormattedString,";
	expectedStringBase += std::to_string(s_Location.line());
	expectedStringBase += ") [";

	for (const eqx::Log::Level level : eqx::Log::getLoggableLevels())
	{
		producedString = 
			eqx::Log::getFormattedString(s_Location, level, logMsg);
		tempString = eqx::Log::LevelToString(level);
		std::transform(tempString.cbegin(), tempString.cend(), 
			tempString.begin(), std::toupper);
		expectedString = expectedStringBase + tempString;
		expectedString += "]: " + logMsg;
		s_StringTests.addTest(
			std::make_tuple(producedString, expectedString,
				EQ2<std::string, std::string>));
		producedString = "";
		expectedString = "";
	}

	return s_StringTests.test();
}

void LogTester::prep(const std::source_location& loc)
{
	eqx::Log::clear();
	s_SS = std::stringstream();
	s_Location = loc;
	s_StringTests.clear();
	s_TypeTests.clear();
}