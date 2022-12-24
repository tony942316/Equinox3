#include "RandomTester.h"

#include <iostream>

#include "EquinoxSTD.h"

#include "UnitTest.h"

RandomTester::RandomTester()
{
}

bool RandomTester::testAll()
{
	if (testRandInt() &&
		testRandUnsignedInt() &&
		testRandDouble() &&
		testIntDistribution() &&
		testFlipCoin() &&
		testRollDice() &&
		testGenerateSeed())
	{
		std::cout << "Random Tests Passed" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Random Tests Failed!" << std::endl;
		return false;
	}
}

bool RandomTester::testRandInt()
{
	int randomInteger = 0;
	std::vector<std::pair<int, int>> tests;
	tests.emplace_back(0, 100);
	tests.emplace_back(-100, 0);
	tests.emplace_back(-100, 100);
	for (int i = 0; i < 100'000; i++)
	{
		for (std::pair<int, int>& test : tests)
		{
			randomInteger = eqx::Random::randInt(test.first, test.second);
			if (!(
				TEST(randomInteger, test.first, GTE<int, int>()) && 
				TEST(randomInteger, test.second, LTE<int, int>())
				))
			{
				return false;
			}
		}
	}

	return true;
}

bool RandomTester::testRandUnsignedInt()
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
			if (!(
				TEST(randomUInteger, test.first, GTE<unsigned int, unsigned int>()) &&
				TEST(randomUInteger, test.second, LTE<unsigned int, unsigned int>())
				))
			{
				return false;
			}
		}
	}

	return true;
}

bool RandomTester::testRandDouble()
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
			if (!(
				TEST(randomDouble, test.first, GTE<double, double>()) &&
				TEST(randomDouble, test.second, LTE<double, double>())
				))
			{
				return false;
			}
		}
	}

	return true;
}

bool RandomTester::testIntDistribution()
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
		if (!(
			TEST(link.second, 1'300, LTE<int, int>()) &&
			TEST(link.second, 700, GTE<int, int>())
			))
		{
			return false;
		}
	}

	return true;
}

bool RandomTester::testFlipCoin()
{
	int result = 0;
	int count = 0;
	for (int i = 0; i < 100'000; i++)
	{
		result = eqx::Random::flipCoin();
		if (!(
			TEST(result, 0, GTE<int, int>()) &&
			TEST(result, 1, LTE<int, int>())
			))
		{
			return false;
		}
		else
		{
			count += result;
		}
	}

	if (!(
		TEST(count, 60'000, LTE<int, int>()) &&
		TEST(count, 40'000, GTE<int, int>())
		))
	{
		return false;
	}

	return true;
}

bool RandomTester::testRollDice()
{
	unsigned int roll = 0U;
	for (int i = 0; i < 100'000; i++)
	{
		for (unsigned int j = 2; j < 100U; j++)
		{
			roll = eqx::Random::rollDice(j);
			if (!(
				TEST(roll, 1U, GTE<unsigned int, unsigned int>()) &&
				TEST(roll, j, LTE<unsigned int, unsigned int>())
				))
			{
				return false;
			}
		}
	}

	return true;
}

bool RandomTester::testGenerateSeed()
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
		if (!TEST(link.second, 5U, LTE<unsigned int, unsigned int>()))
		{
			return false;
		}
	}

	return true;
}