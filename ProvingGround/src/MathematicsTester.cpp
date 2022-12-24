#include "MathematicsTester.h"

#include <iostream>

#include "EquinoxSTD.h"
#include "UnitTest.h"

MathematicsTester::MathematicsTester()
{
}

bool MathematicsTester::testAll()
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

bool MathematicsTester::testWillOverflowAddition()
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
		if (!TEST(eqx::willOverflowAddition(std::get<0>(test), std::get<1>(test)), std::get<2>(test)))
		{
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
		if (!TEST(eqx::willOverflowAddition(std::get<0>(test), std::get<1>(test)), std::get<2>(test)))
		{
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
		if (!TEST(eqx::willOverflowAddition(std::get<0>(test), std::get<1>(test)), std::get<2>(test)))
		{
			return false;
		}
	}

	return true;
}

bool MathematicsTester::testDistanceGeneric()
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
		if (!(
			TEST(integerDist, std::get<2>(test)) &&
			TEST(integerDist, eqx::distance(std::get<1>(test), std::get<0>(test)))
			))
		{
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
		if (!(
			TEST(doubleDist, std::get<2>(test)) &&
			TEST(doubleDist, eqx::distance(std::get<1>(test), std::get<0>(test)))
			))
		{
			return false;
		}
	}

	return true;
}