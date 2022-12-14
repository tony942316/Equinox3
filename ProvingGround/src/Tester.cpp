#include "Tester.h"

#include <iostream>
#include <unordered_map>
#include <sstream>
#include <chrono>
#include <thread>

#include "EquinoxSTD.h"

Tester::Tester()
{
}

bool Tester::testLog()
{
	if (testLogLog() &&
		testLogSetLevel() &&
		testLogSetOutputStream() &&
		testLogSetOutputFile() &&
		testLogClear() &&
		testLogGetLastLogType() &&
		testLogGetLastLogMessage())
	{
		std::cout << "Log Tests Passed" << std::endl;
		eqx::Log::setLevel(eqx::Log::Level::none);
		eqx::Log::setOutputStream(std::cout);
		eqx::Log::setOutputFile("Log.txt");
		return true;
	}
	else
	{
		std::cout << "Log Tests Failed!" << std::endl;
		return false;
	}
}

bool Tester::testLogLog()
{
	std::stringstream ss;
	std::string line = "", ans = "";

	eqx::Log::setOutputStream(ss);
	eqx::Log::setLevel(eqx::Log::Level::error);
	eqx::Log::log(eqx::Log::Level::error, "Testing");

	ans = "..\\Tester.cpp(testLogLog,45) [ERROR]: Testing";
	std::getline(ss, line);
	if (ans != line)
	{
		std::cout << "Logging Fail!" << std::endl;
		return false;
	}

	return true;
}

bool Tester::testLogSetLevel()
{
	std::stringstream ss;
	std::string line = "", ans = "";

	eqx::Log::setOutputStream(ss);
	eqx::Log::setLevel(eqx::Log::Level::info);
	eqx::Log::log(eqx::Log::Level::info, "This Should Stream");

	ans = "..\\Tester.cpp(testLogSetLevel,65) [INFO]: This Should Stream";
	std::getline(ss, line);
	if (ans != line)
	{
		std::cout << "SetLevel Fail!" << std::endl;
		return false;
	}

	eqx::Log::setLevel(eqx::Log::Level::error);
	eqx::Log::log(eqx::Log::Level::info, "This Should Not Stream");

	std::getline(ss, line);
	ans = "";
	if (ans != line)
	{
		std::cout << "SetLevel Fail!" << std::endl;
		return false;
	}

	return true;
}

bool Tester::testLogSetOutputStream()
{
	std::stringstream ss;
	std::string line = "", ans = "";

	eqx::Log::setOutputStream(ss);
	eqx::Log::setLevel(eqx::Log::Level::info);
	eqx::Log::log(eqx::Log::Level::error, "String Stream");

	ans = "..\\Tester.cpp(testLogSetOutputStream,96) [ERROR]: String Stream";
	std::getline(ss, line);
	if (ans != line)
	{
		std::cout << "SetOutputStream Fail!" << std::endl;
		return false;
	}

	return true;
}

bool Tester::testLogSetOutputFile()
{
	std::stringstream ss;
	std::string line = "", ans = "";
	std::ifstream file;

	eqx::Log::setOutputStream(ss);
	eqx::Log::setOutputFile("TestOutputFile.txt");
	eqx::Log::setLevel(eqx::Log::Level::info);
	eqx::Log::log(eqx::Log::Level::error, "OutputFile");
	eqx::Log::setOutputFile("Log.txt");

	file.open("TestOutputFile.txt", std::ios::in);
	ans = "..\\Tester.cpp(testLogSetOutputFile,118) [ERROR]: OutputFile";
	std::getline(file, line);
	if (ans != line)
	{
		std::cout << "SetOutputFile Fail!" << std::endl;
		return false;
	}

	return true;
}

bool Tester::testLogClear()
{
	std::stringstream ss;

	eqx::Log::setOutputStream(ss);
	eqx::Log::setLevel(eqx::Log::Level::info);
	eqx::Log::log(eqx::Log::Level::error, "TestClear", eqx::Log::Type::runtimeError);

	if (eqx::Log::getLastLogMessage() != "TestClear" ||
		eqx::Log::getLastLogType() != eqx::Log::Type::runtimeError)
	{
		std::cout << "LogClear Fail!" << std::endl;
		return false;
	}

	eqx::Log::clear();
	if (eqx::Log::getLastLogMessage() != "" ||
		eqx::Log::getLastLogType() != eqx::Log::Type::none)
	{
		std::cout << "LogClear Fail!" << std::endl;
		return false;
	}

	return true;
}

bool Tester::testLogGetLastLogType()
{
	std::stringstream ss;

	eqx::Log::setOutputStream(ss);
	eqx::Log::setLevel(eqx::Log::Level::info);
	eqx::Log::log(eqx::Log::Level::info, "TestGetLogType", eqx::Log::Type::info);

	if (eqx::Log::getLastLogType() != eqx::Log::Type::info)
	{
		std::cout << "GetLastLogType Fail!" << std::endl;
		return false;
	}

	return true;
}

bool Tester::testLogGetLastLogMessage()
{
	std::stringstream ss;

	eqx::Log::setOutputStream(ss);
	eqx::Log::setLevel(eqx::Log::Level::info);
	eqx::Log::log(eqx::Log::Level::info, "TestGetLogMessage");

	if (eqx::Log::getLastLogMessage() != "TestGetLogMessage")
	{
		std::cout << "GetLastLogMessage Fail!" << std::endl;
		return false;
	}

	return true;
}

bool Tester::testRandom()
{
	if (testRandInt() &&
		testRandDouble() &&
		testGenerateSeed() &&
		testIntDistribution())
	{
		std::cout << "Random Tests Passed" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Random Test Failed!" << std::endl;
		return false;
	}
}

bool Tester::testRandInt()
{
	int randomInteger = 0;
	for (int i = 0; i < 100'000; i++)
	{
		randomInteger = eqx::Random::randInt(0, 100);
		if (randomInteger > 100 || randomInteger < 0)
		{
			std::cout << "RandInt Fail!" << std::endl;
			return false;
		}

		randomInteger = eqx::Random::randInt(-100, 0);
		if (randomInteger < -100 || randomInteger > 0)
		{
			std::cout << "RandInt Fail!" << std::endl;
			return false;
		}

		randomInteger = eqx::Random::randInt(-100, 100);
		if (randomInteger < -100 || randomInteger > 100)
		{
			std::cout << "RandInt Fail!" << std::endl;
			return false;
		}
	}

	return true;
}

bool Tester::testIntDistribution()
{
	std::unordered_map<int, int> intDistribution;
	for (size_t i = 1; i <= 100; i++)
	{
		intDistribution[static_cast<int>(i)] = 0;
	}

	for (int i = 0; i < 100'000; i++)
	{
		intDistribution[eqx::Random::randInt(1, 100)]++;
	}

	for (std::pair<int, int> link : intDistribution)
	{
		if (link.second > 1'300 || link.second < 700)
		{
			std::cout << "IntDistribution Fail!" << std::endl;
			return false;
		}
	}

	return true;
}

bool Tester::testRandDouble()
{
	double randomDouble = 0.0;
	for (int i = 0; i < 100'000; i++)
	{
		randomDouble = eqx::Random::randDouble(0.0, 1.0);
		if (randomDouble > 1.0 || randomDouble < 0.0)
		{
			std::cout << "RandDouble Fail!" << std::endl;
			return false;
		}

		randomDouble = eqx::Random::randDouble(-1.0, 0.0);
		if (randomDouble < -1.0 || randomDouble > 0.0)
		{
			std::cout << "RandDouble Fail!" << std::endl;
			return false;
		}

		randomDouble = eqx::Random::randDouble(-1.0, 1.0);
		if (randomDouble < -1.0 || randomDouble > 1.0)
		{
			std::cout << "RandDouble Fail!" << std::endl;
			return false;
		}
	}

	return true;
}

bool Tester::testGenerateSeed()
{
	unsigned int seed = 0;
	for (int i = 0; i < 100'000; i++)
	{
		seed = eqx::Random::generateSeed();

		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		std::chrono::system_clock::time_point end = start;
		while (seed == eqx::Random::generateSeed())
		{
			if (seed != eqx::Random::generateSeed() ||
				std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() > 50)
			{
				break;
			}
			end = std::chrono::system_clock::now();
		}

		if (seed == eqx::Random::generateSeed())
		{
			std::cout << "GenerateSeed Fail!" << std::endl;
			return false;
		}
	}

	return true;
}

void Tester::testAll()
{
	std::cout << "\n";
	testLog();
	std::cout << "\n";
	testRandom();
	std::cout << "\n";
}