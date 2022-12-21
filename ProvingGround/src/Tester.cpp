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
		eqx::Log::setLevel(eqx::Log::Level::warning);
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
		std::cout << "\nLogging Fail!" << std::endl;
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
		std::cout << "\nSetLevel Fail!" << std::endl;
		return false;
	}

	eqx::Log::setLevel(eqx::Log::Level::error);
	eqx::Log::log(eqx::Log::Level::info, "This Should Not Stream");

	std::getline(ss, line);
	ans = "";
	if (ans != line)
	{
		std::cout << "\nSetLevel Fail!" << std::endl;
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
		std::cout << "\nSetOutputStream Fail!" << std::endl;
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
		std::cout << "\nSetOutputFile Fail!" << std::endl;
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
		std::cout << "\nLogClear Fail!" << std::endl;
		return false;
	}

	eqx::Log::clear();
	if (eqx::Log::getLastLogMessage() != "" ||
		eqx::Log::getLastLogType() != eqx::Log::Type::none)
	{
		std::cout << "\nLogClear Fail!" << std::endl;
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
		std::cout << "\nGetLastLogType Fail!" << std::endl;
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
		std::cout << "\nGetLastLogMessage Fail!" << std::endl;
		return false;
	}

	return true;
}

bool Tester::testRandom()
{
	if (testRandInt() &&
		testRandUnsignedInt() &&
		testRandDouble() &&
		testFlipCoin() &&
		testRollDice() &&
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
	std::vector<std::pair<int, int>> tests;
	tests.emplace_back(0, 100);
	tests.emplace_back(-100, 0);
	tests.emplace_back(-100, 100);
	for (int i = 0; i < 100'000; i++)
	{
		for (const std::pair<int, int>& test : tests)
		{
			randomInteger = eqx::Random::randInt(test.first, test.second);
			if (randomInteger < test.first || randomInteger > test.second)
			{
				std::cout << "\nRandInt Fail!" << std::endl;
				std::cout << "lower: " << test.first << std::endl;
				std::cout << "upper: " << test.second << std::endl;
				std::cout << "generated: " << randomInteger << std::endl;
				return false;
			}
		}
	}

	return true;
}

bool Tester::testRandUnsignedInt()
{
	unsigned int randomUInteger = 0;
	std::vector<std::pair<unsigned int, unsigned int>> tests;
	tests.emplace_back(0U, 100U);
	tests.emplace_back(0U, std::numeric_limits<unsigned int>::max());
	for (int i = 0; i < 100'000; i++)
	{
		for (const std::pair<unsigned int, unsigned int>& test : tests)
		{
			randomUInteger = eqx::Random::randUnsignedInt(test.first, test.second);
			if (randomUInteger < test.first || randomUInteger > test.second)
			{
				std::cout << "\nRandUnsignedInt Fail!" << std::endl;
				std::cout << "lower: " << test.first << std::endl;
				std::cout << "upper: " << test.second << std::endl;
				std::cout << "generated: " << randomUInteger << std::endl;
				return false;
			}
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
			std::cout << "\nIntDistribution Fail!" << std::endl;
			return false;
		}
	}

	return true;
}

bool Tester::testRandDouble()
{
	double randomDouble = 0.0;
	std::vector<std::pair<double, double>> tests;
	tests.emplace_back(0.0, 1.0);
	tests.emplace_back(-1.0, 0.0);
	tests.emplace_back(-1.0, 1.0);
	tests.emplace_back(-10.0, 1.0);
	tests.emplace_back(-1.0, 10.0);
	tests.emplace_back(0.0, std::numeric_limits<double>::max());
	tests.emplace_back(std::numeric_limits<double>::lowest(), 0.0);
	tests.emplace_back(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::max());
	for (int i = 0; i < 100'000; i++)
	{
		for (const std::pair<double, double>& test : tests)
		{
			randomDouble = eqx::Random::randDouble(test.first, test.second);
			if (randomDouble < test.first || randomDouble > test.second)
			{
				std::cout << std::setprecision(20);
				std::cout << "\nRandDouble Fail" << std::endl;
				std::cout << "lower: " << test.first << std::endl;
				std::cout << "upper: " << test.second << std::endl;
				std::cout << "generated: " << randomDouble << std::endl;
				std::cout << std::setprecision(6);
				return false;
			}
		}
	}

	return true;
}

bool Tester::testFlipCoin()
{
	int result = 0;
	int count = 0;
	for (int i = 0; i < 100'000; i++)
	{
		result = eqx::Random::flipCoin();
		if (result != 1 && result != 0)
		{
			std::cout << "\nFlipCoin Fail" << std::endl;
			std::cout << "Produced: " << result << std::endl;
			return false;
		}
		else
		{
			count += result;
		}
	}

	if (count > 60'000 || count < 40'000)
	{
		std::cout << "\nFlipCoin Fail" << std::endl;
		std::cout << "Landed " << count << " heads" << std::endl;
		return false;
	}

	return true;
}

bool Tester::testRollDice()
{
	unsigned int roll = 0U;
	for (int i = 0; i < 100'000; i++)
	{
		for (unsigned int j = 2; j < 100; j++)
		{
			roll = eqx::Random::rollDice(j);
			if (roll < 1 || roll > j)
			{
				std::cout << "\nRollDice Fail" << std::endl;
				std::cout << j << " Sided Dice Rolled: " << roll << std::endl;
				return false;
			}
		}
	}

	return true;
}

bool Tester::testGenerateSeed()
{
	unsigned int seed = 0;
	std::unordered_map<unsigned int, unsigned int> seedCounts;
	for (int i = 0; i < 500'000; i++)
	{
		seed = eqx::Random::generateSeed();
		if (seedCounts.find(seed) == seedCounts.end())
		{
			seedCounts[seed] = 1;
		}
		else
		{
			seedCounts[seed]++;
		}
	}

	for (const std::pair<unsigned int, unsigned int>& link : seedCounts)
	{
		if (link.second > 5)
		{
			std::cout << "\nGenerateSeed Fail!" << std::endl;
			std::cout << link.first << " Generated " << link.second << " Times" << std::endl;
			return false;
		}
	}

	return true;
}

bool Tester::testStopWatch()
{
	if (testStartStop() &&
		testReading() &&
		testGetting())
	{
		std::cout << "StopWatch Tests Passed" << std::endl;
		return true;
	}
	else
	{
		std::cout << "StopWatch Tests Failed!" << std::endl;
		return false;
	}
}

bool Tester::testStartStop()
{
	eqx::StopWatch watch;
	for (int i = 0; i < 100'000; i++)
	{
		watch.start();
		watch.stop();
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		std::chrono::system_clock::time_point end = start;
		while (watch.getTimeNano() < 1)
		{
			watch.stop();
			if (watch.getTimeNano() > 0 ||
				std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() > 50)
			{
				break;
			}
			end = std::chrono::system_clock::now();
		}

		if (watch.getTimeNano() < 1)
		{
			std::cout << "\nStartStop Fail!" << std::endl;
			return false;
		}
	}

	return true;
}

bool Tester::testReading()
{
	eqx::StopWatch watch;
	for (int i = 0; i < 100'000; i++)
	{
		watch.start();
		std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
		std::chrono::system_clock::time_point end = start;
		while (watch.readTimeNano() < 1)
		{
			if (watch.readTimeNano() > 0 ||
				std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() > 50)
			{
				break;
			}
			end = std::chrono::system_clock::now();
		}

		if (watch.getTimeNano() < 1)
		{
			std::cout << "\nTestReading Fail!" << std::endl;
			return false;
		}
	}

	return true;
}

bool Tester::testGetting()
{
	eqx::StopWatch watch;
	for (int i = 0; i < 100'000; i++)
	{
		if (watch.getTimeNano() > 0)
		{
			std::cout << "\nTestGetting Fail!" << std::endl;
			return false;
		}
	}

	return true;
}

bool Tester::testMathematics()
{
	if (testWillOverflowAddition() &&
		testDistanceGeneric())
	{
		std::cout << "Mathematics Tests Passed" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Mathematics Tests Failed!" << std::endl;
		return false;
	}
}

bool Tester::testWillOverflowAddition()
{
	std::vector<std::tuple<int, int, bool>> integralTests;
	integralTests.reserve(200'000);
	integralTests.emplace_back(0, 0, false);
	integralTests.emplace_back(1, 0, false);
	integralTests.emplace_back(-1, 0, false);
	integralTests.emplace_back(1, 1, false);
	integralTests.emplace_back(-1, -1, false);
	integralTests.emplace_back(-1, 1, false);
	integralTests.emplace_back(1, -1, false);
	integralTests.emplace_back(std::numeric_limits<int>::max(), 1, true);
	integralTests.emplace_back(std::numeric_limits<int>::lowest(), -1, true);
	integralTests.emplace_back(std::numeric_limits<int>::max(), std::numeric_limits<int>::max(), true);
	integralTests.emplace_back(std::numeric_limits<int>::lowest(), std::numeric_limits<int>::lowest(), true);
	integralTests.emplace_back(std::numeric_limits<int>::lowest(), std::numeric_limits<int>::max(), false);
	integralTests.emplace_back(std::numeric_limits<int>::max(), std::numeric_limits<int>::lowest(), false);

	for (int i = 0; i < 50'000; i++)
	{
		integralTests.emplace_back(std::numeric_limits<int>::max(), eqx::Random::randInt(1, std::numeric_limits<int>::max()), true);
		integralTests.emplace_back(std::numeric_limits<int>::lowest(), eqx::Random::randInt(std::numeric_limits<int>::lowest(), -1), true);
		integralTests.emplace_back(eqx::Random::randInt(std::numeric_limits<int>::lowest(), -1), eqx::Random::randInt(1, std::numeric_limits<int>::max()), false);
	}

	for (const std::tuple<int, int, bool>& test : integralTests)
	{
		if (eqx::willOverflowAddition(std::get<0>(test), std::get<1>(test)) != std::get<2>(test))
		{
			std::cout << "\nTestWillOverflowAddition Integral Fail!" << std::endl;
			return false;
		}
	}

	std::vector<std::tuple<unsigned int, unsigned int, bool>> unsignedTests;
	unsignedTests.reserve(200'000);
	unsignedTests.emplace_back(0U, 0U, false);
	unsignedTests.emplace_back(1U, 0U, false);
	unsignedTests.emplace_back(1U, 1U, false);
	unsignedTests.emplace_back(std::numeric_limits<unsigned int>::max(), 1U, true);
	unsignedTests.emplace_back(std::numeric_limits<unsigned int>::max(), std::numeric_limits<unsigned int>::max(), true);
	unsignedTests.emplace_back(std::numeric_limits<unsigned int>::max(), 0U, false);

	for (const std::tuple<unsigned int, unsigned int, bool>& test : unsignedTests)
	{
		if (eqx::willOverflowAddition(std::get<0>(test), std::get<1>(test)) != std::get<2>(test))
		{
			std::cout << std::boolalpha;
			std::cout << "\nTestWillOverflowAddition Unsigned Fail!" << std::endl;
			std::cout << std::get<0>(test) << " + " << std::get<1>(test) << " = " << std::get<2>(test) << std::endl;
			std::cout << std::noboolalpha;
			return false;
		}
	}

	std::vector<std::tuple<double, double, bool>> doubleTests;
	double smallPosDouble = std::nexttoward(0.0, std::numeric_limits<double>::max());
	double smallNegDouble = std::nexttoward(0.0, std::numeric_limits<double>::lowest());
	doubleTests.reserve(200'000);
	doubleTests.emplace_back(0.0, 0.0, false);
	doubleTests.emplace_back(1.0, 0.0, false);
	doubleTests.emplace_back(smallPosDouble, 0.0, false);
	doubleTests.emplace_back(-1.0, 0.0, false);
	doubleTests.emplace_back(smallNegDouble, 0.0, false);
	doubleTests.emplace_back(1.0, 1.0, false);
	doubleTests.emplace_back(smallPosDouble, smallPosDouble, false);
	doubleTests.emplace_back(-1.0, -1.0, false);
	doubleTests.emplace_back(smallNegDouble, smallNegDouble, false);
	doubleTests.emplace_back(-1.0, 1.0, false);
	doubleTests.emplace_back(smallNegDouble, smallPosDouble, false);
	doubleTests.emplace_back(1.0, -1.0, false);
	doubleTests.emplace_back(smallPosDouble, smallNegDouble, false);
	doubleTests.emplace_back(std::numeric_limits<double>::max(), 1.0, true);
	doubleTests.emplace_back(std::numeric_limits<double>::max(), smallPosDouble, true);
	doubleTests.emplace_back(std::numeric_limits<double>::lowest(), -1.0, true);
	doubleTests.emplace_back(std::numeric_limits<double>::lowest(), smallNegDouble, true);
	doubleTests.emplace_back(std::numeric_limits<double>::max(), std::numeric_limits<double>::max(), true);
	doubleTests.emplace_back(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::lowest(), true);
	doubleTests.emplace_back(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::max(), false);
	doubleTests.emplace_back(std::numeric_limits<double>::max(), std::numeric_limits<double>::lowest(), false);

	for (int i = 0; i < 50'000; i++)
	{
		doubleTests.emplace_back(std::numeric_limits<double>::max(), eqx::Random::randDouble(1.0, std::numeric_limits<double>::max()), true);
		doubleTests.emplace_back(std::numeric_limits<double>::lowest(), eqx::Random::randDouble(std::numeric_limits<double>::lowest(), -1.0), true);
		doubleTests.emplace_back(eqx::Random::randDouble(std::numeric_limits<double>::lowest(), -1.0), eqx::Random::randDouble(1.0, std::numeric_limits<double>::max()), false);
	}

	for (const std::tuple<double, double, bool>& test : doubleTests)
	{
		if (eqx::willOverflowAddition(std::get<0>(test), std::get<1>(test)) != std::get<2>(test))
		{
			std::cout << std::boolalpha;
			std::cout << "\nTestWillOverflowAddition Double Fail!" << std::endl;
			std::cout << std::get<0>(test) << " + " << std::get<1>(test) << " = " << std::get<2>(test) << std::endl;
			std::cout << std::noboolalpha;
			return false;
		}
	}

	return true;
}

bool Tester::testDistanceGeneric()
{
	int integerDist = 0;
	std::vector<std::tuple<int, int, int>> integerTests;
	integerTests.emplace_back(0, 0, 0);
	integerTests.emplace_back(-1, 0, 1);
	integerTests.emplace_back(0, 1, 1);
	integerTests.emplace_back(0, std::numeric_limits<int>::max(), std::numeric_limits<int>::max());
	integerTests.emplace_back(std::numeric_limits<int>::lowest() + 1, 0, std::numeric_limits<int>::max());

	for (const std::tuple<int, int, int>& test : integerTests)
	{
		integerDist = eqx::distance(std::get<0>(test), std::get<1>(test));
		if (integerDist != std::get<2>(test) ||
			integerDist != eqx::distance(std::get<1>(test), std::get<0>(test)))
		{
			std::cout << "\nTestDistanceGeneric Integer Fail!" << std::endl;
			std::cout << "Distance from " << std::get<0>(test) << " to " << std::get<1>(test) << " is " << integerDist << std::endl;
			std::cout << "Reverse: " << eqx::distance(std::get<1>(test), std::get<0>(test)) << std::endl;
			return false;
		}
	}

	double doubleDist = 0.0;
	std::vector<std::tuple<double, double, double>> doubleTests;
	doubleTests.emplace_back(0.0, 0.0, 0.0);
	doubleTests.emplace_back(-1.0, 0.0, 1.0);
	doubleTests.emplace_back(std::nexttoward(0.0, std::numeric_limits<double>::lowest()), 0.0, std::nexttoward(0.0, std::numeric_limits<double>::max()));
	doubleTests.emplace_back(0.0, 1.0, 1.0);
	doubleTests.emplace_back(0.0, std::nexttoward(0.0, std::numeric_limits<double>::max()), std::nexttoward(0.0, std::numeric_limits<double>::max()));
	doubleTests.emplace_back(0.0, std::numeric_limits<double>::max(), std::numeric_limits<double>::max());
	doubleTests.emplace_back(std::numeric_limits<double>::lowest(), 0.0, std::numeric_limits<double>::max());

	for (const std::tuple<double, double, double>& test : doubleTests)
	{
		doubleDist = eqx::distance(std::get<0>(test), std::get<1>(test));
		if (doubleDist != std::get<2>(test) ||
			doubleDist != eqx::distance(std::get<1>(test), std::get<0>(test)))
		{
			std::cout << std::setprecision(20);
			std::cout << "\nTestDistanceGeneric Double Fail!" << std::endl;
			std::cout << "Distance from " << std::get<0>(test) << " to " << std::get<1>(test) << " is " << doubleDist << std::endl;
			std::cout << std::setprecision(6);
			return false;
		}
	}

	return true;
}

bool Tester::testPoint()
{
	if (testPointConstruction() &&
		testPointOperator() &&
		testPointFunction())
	{
		std::cout << "Point Tests Passed" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Point Tests Failed!" << std::endl;
		return false;
	}
}

bool Tester::testPointConstruction()
{
	eqx::Point<int> defalutConInt;
	if (defalutConInt.x != 0 || defalutConInt.y != 0)
	{
		std::cout << "\nTestPointConstruction IntDefault Fail!" << std::endl;
		return false;
	}

	eqx::Point<double> defalutConDouble;
	if (defalutConDouble.x != 0.0 || defalutConDouble.y != 0.0)
	{
		std::cout << "\nTestPointConstruction DoubleDefault Fail!" << std::endl;
		return false;
	}

	int paramInt1, paramInt2;
	double paramDouble1, paramDouble2;
	std::stringstream ss;
	eqx::Log::setOutputStream(ss);
	eqx::Log::setOutputFile("TestOutputFile.txt");
	eqx::Log::clear();
	for (int i = 0; i < 100'000; i++)
	{
		paramInt1 = eqx::Random::randInt(-100'000, 100'000);
		paramInt2 = eqx::Random::randInt(-100'000, 100'000);
		eqx::Point<int> paramConInt(paramInt1, paramInt2);
		if (paramConInt.x != paramInt1 || paramConInt.y != paramInt2)
		{
			std::cout << "\nTestPointConstruction IntParam Fail!" << std::endl;
			return false;
		}

		paramDouble1 = eqx::Random::randDouble(-100'000.0, 100'000.0);
		paramDouble2 = eqx::Random::randDouble(-100'000.0, 100'000.0);
		eqx::Point<double> paramConDouble(paramDouble1, paramDouble2);
		if (paramConDouble.x != paramDouble1 || paramConDouble.y != paramDouble2)
		{
			std::cout << "\nTestPointConstruction DoubleParam Fail!" << std::endl;
			return false;
		}

		eqx::Point<int> copyConInt(paramConDouble);
		if (copyConInt.x != static_cast<int>(paramConDouble.x) || copyConInt.y != static_cast<int>(paramConDouble.y) ||
			eqx::Log::getLastLogMessage() != "Lossy Conversion" || eqx::Log::getLastLogType() != eqx::Log::Type::runtimeWarning)
		{
			std::cout << "\nTestPointConstruction IntCopyDouble Fail!" << std::endl;
			return false;
		}
		eqx::Log::clear();

		eqx::Point<double> copyConDouble(paramConInt);
		if (copyConDouble.x != static_cast<double>(paramConInt.x) || copyConDouble.y != static_cast<double>(paramConInt.y))
		{
			std::cout << "\nTestPointConstruction DoubleCopy Fail!" << std::endl;
			return false;
		}
	}
	eqx::Log::setOutputStream(std::cout);
	eqx::Log::setOutputFile("Log.txt");
	eqx::Log::clear();

	return true;
}

bool Tester::testPointOperator()
{
	int intParam1, intParam2;
	eqx::Point<int> intPoint, intPlusPoint;
	double doubleParam1, doubleParam2;
	eqx::Point<double> doublePoint, doublePlusPoint;
	std::stringstream ss;
	eqx::Log::setOutputStream(ss);
	eqx::Log::setOutputFile("TestOutputFile.txt");
	eqx::Log::clear();
	for (int i = 0; i < 100'000; i++)
	{
		intParam1 = eqx::Random::randInt(-100'000, 100'000);
		intParam2 = eqx::Random::randInt(-100'000, 100'000);
		intPoint = eqx::Point<int>(intParam1, intParam2);
		if (intPoint.x != intParam1 || intPoint.y != intParam2)
		{
			std::cout << "\nTestPointOperator Int== Fail!" << std::endl;
			return false;
		}

		doubleParam1 = eqx::Random::randDouble(-100'000.0, 100'000.0);
		doubleParam2 = eqx::Random::randDouble(-100'000.0, 100'000.0);
		doublePoint = eqx::Point<double>(doubleParam1, doubleParam2);
		if (doublePoint.x != doubleParam1 || doublePoint.y != doubleParam2)
		{
			std::cout << "\nTestPointOperator Double== Fail!" << std::endl;
			return false;
		}

		intPoint = doublePoint;
		if (intPoint.x != static_cast<int>(doublePoint.x) || intPoint.y != static_cast<int>(doublePoint.y) ||
			eqx::Log::getLastLogMessage() != "Lossy Conversion" || eqx::Log::getLastLogType() != eqx::Log::Type::runtimeWarning)
		{
			std::cout << "\nTestPointOperator Int==Double Fail" << std::endl;
			return false;
		}
		eqx::Log::clear();

		intPoint = eqx::Point<int>(intParam1, intParam2);
		doublePoint = eqx::Point<double>(doubleParam1, doubleParam2);

		intPlusPoint = intPoint + intPoint;
		if (intPlusPoint.x != (2 * intPoint.x) || intPlusPoint.y != (2 * intPoint.y))
		{
			std::cout << "\nTestPointOperator Int+ Fail" << std::endl;
			return false;
		}

		doublePlusPoint = doublePoint + doublePoint;
		if (doublePlusPoint.x != (2.0 * doublePoint.x) || doublePlusPoint.y != (2.0 * doublePoint.y))
		{
			std::cout << "\nTestPointOperator Double+ Fail" << std::endl;
			return false;
		}

		intPlusPoint = intPoint - intPoint;
		if (intPlusPoint.x != 0 || intPlusPoint.y != 0)
		{
			std::cout << "\nTestPointOperator Int- Fail" << std::endl;
			return false;
		}

		doublePlusPoint = doublePoint - doublePoint;
		if (doublePlusPoint.x != 0.0 || doublePlusPoint.y != 0.0)
		{
			std::cout << "\nTestPointOperator Double- Fail" << std::endl;
			return false;
		}

		intPlusPoint += intPoint;
		if (intPlusPoint.x != intPoint.x || intPlusPoint.y != intPoint.y)
		{
			std::cout << "\nTestPointOperator Int+= Fail" << std::endl;
			return false;
		}

		doublePlusPoint += doublePoint;
		if (doublePlusPoint.x != doublePoint.x || doublePlusPoint.y != doublePoint.y)
		{
			std::cout << "\nTestPointOperator Double+= Fail" << std::endl;
			return false;
		}

		intPlusPoint -= intPoint;
		if (intPlusPoint.x != 0 || intPlusPoint.y != 0)
		{
			std::cout << "\nTestPointOperator Int-= Fail" << std::endl;
			return false;
		}

		doublePlusPoint -= doublePoint;
		if (doublePlusPoint.x != 0.0 || doublePlusPoint.y != 0.0)
		{
			std::cout << "\nTestPointOperator Double-= Fail" << std::endl;
			return false;
		}

		intPlusPoint = intPoint + intPoint;
		if (intPlusPoint == intPoint)
		{
			std::cout << "\nTestPointOperator Int== Fail" << std::endl;
			return false;
		}

		doublePlusPoint = doublePoint + doublePoint;
		if (doublePlusPoint == doublePoint)
		{
			std::cout << "\nTestPointOperator Double== Fail" << std::endl;
		}

		intPlusPoint = intPoint;
		if (intPlusPoint != intPoint)
		{
			std::cout << "\nTestPointOperator Int!= Fail" << std::endl;
			return false;
		}

		doublePlusPoint = doublePoint;
		if (doublePlusPoint != doublePoint)
		{
			std::cout << "\nTestPointOperator Double!= Fail" << std::endl;
			return false;
		}
	}

	eqx::Log::setOutputStream(std::cout);
	eqx::Log::setOutputFile("Log.txt");
	eqx::Log::clear();

	return true;
}

bool Tester::testPointFunction()
{
	eqx::Point<int> intPoint;
	eqx::Point<double> doublePoint;
	std::string ans = "";
	for (int i = 0; i < 100'000; i++)
	{
		intPoint = { eqx::Random::randInt(-100'000, 100'000), eqx::Random::randInt(-100'000, 100'000) };
		ans = std::string("(") + std::to_string(intPoint.x) + std::string(", ") + std::to_string(intPoint.y) + std::string(")");
		if (intPoint.toString() != ans)
		{
			std::cout << "\nTestPointFunction toStringInt Fail" << std::endl;
			return false;
		}

		doublePoint = { eqx::Random::randDouble(-100'000.0, 100'000.0), eqx::Random::randDouble(-100'000.0, 100'000.0) };
		ans = std::string("(") + std::to_string(doublePoint.x) + std::string(", ") + std::to_string(doublePoint.y) + std::string(")");
		if (doublePoint.toString() != ans)
		{
			std::cout << "\nTestPointFunction toStringDouble Fail" << std::endl;
			return false;
		}
	}

	std::vector<std::tuple<eqx::Point<int>, eqx::Point<int>, int>> intTests;
	intTests.emplace_back(eqx::Point<int>(0, 0), eqx::Point<int>(0, 0), 0);
	intTests.emplace_back(eqx::Point<int>(0, 0), eqx::Point<int>(1, 1), 1);
	intTests.emplace_back(eqx::Point<int>(0, 0), eqx::Point<int>(-1, -1), 1);
	intTests.emplace_back(eqx::Point<int>(1, 1), eqx::Point<int>(1, 1), 0);
	intTests.emplace_back(eqx::Point<int>(0, 0), eqx::Point<int>(0, 10), 10);
	intTests.emplace_back(eqx::Point<int>(10, 10), eqx::Point<int>(-10, -10), 28);

	for (const std::tuple<eqx::Point<int>, eqx::Point<int>, int>& test : intTests)
	{
		if (eqx::distance(std::get<0>(test), std::get<1>(test)) != std::get<2>(test) ||
			eqx::distance(std::get<1>(test), std::get<0>(test)) != std::get<2>(test))
		{
			std::cout << "\nTestPointFunction distanceInt Fail" << std::endl;
			return false;
		}
	}

	std::vector<std::tuple<eqx::Point<double>, eqx::Point<double>, double>> doubleTests;
	doubleTests.emplace_back(eqx::Point<double>(0.0, 0.0), eqx::Point<double>(0.0, 0.0), 0.0);
	doubleTests.emplace_back(eqx::Point<double>(0.0, 0.0), eqx::Point<double>(0.0, 1.0), 1.0);
	doubleTests.emplace_back(eqx::Point<double>(0.0, 0.0), eqx::Point<double>(1.0, 0.0), 1.0);
	doubleTests.emplace_back(eqx::Point<double>(0.0, 0.0), eqx::Point<double>(1.0, 1.0), std::sqrt(2.0));

	for (const std::tuple<eqx::Point<double>, eqx::Point<double>, double>& test : doubleTests)
	{
		if (eqx::distance(std::get<0>(test), std::get<1>(test)) != std::get<2>(test) ||
			eqx::distance(std::get<1>(test), std::get<0>(test)) != std::get<2>(test))
		{
			std::cout << "\nTestPointFunction distanceDouble Fail" << std::endl;
			return false;
		}
	}

	return true;
}

void Tester::testAll()
{
	std::cout << "\n*********************" << std::endl;
	if (testLog() &&
		testRandom() &&
		testStopWatch() &&
		testMathematics() &&
		testPoint())
	{
		std::cout << "---All Pass---" << std::endl;
	}
	std::cout << "*********************\n" << std::endl;
}