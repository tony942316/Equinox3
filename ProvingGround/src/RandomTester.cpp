#include "RandomTester.hpp"

#include <iostream>
#include <unordered_map>

#include "EquinoxSTD.hpp"

UnitTest<int, int> RandomTester::s_IntTests;
UnitTest<unsigned int, unsigned int> RandomTester::s_UIntTests;
UnitTest<double, double> RandomTester::s_DoubleTests;

bool RandomTester::test()
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
	prep();

	int runs = 100'000;

	std::function<void(int, int)> testLambda([&](int lb, int ub) {
		int producedValue = 0;
		for (int i = 0; i < runs; i++)
		{
			producedValue = eqx::Random::randInt(lb, ub);
			s_IntTests.addTest(std::make_tuple(
				producedValue, ub, LTE<int, int>()));
			s_IntTests.addTest(std::make_tuple(
				producedValue, lb, GTE<int, int>()));
		}
	});

	testLambda(0, 2);
	testLambda(-1, 0);
	testLambda(0, 100);
	testLambda(-100, 0);
	testLambda(-100, 100);
	testLambda(50, 100);
	testLambda(-100, -50);
	testLambda(27, 159);
	testLambda(-10'456, 7'964);

	return s_IntTests.test();
}

bool RandomTester::testRandUnsignedInt()
{
	prep();

	int runs = 100'000;

	std::function<void(unsigned int, unsigned int)> testLambda(
		[&](unsigned int lb, unsigned int ub) {
		unsigned int producedValue = 0;
		for (int i = 0; i < runs; i++)
		{
			producedValue = eqx::Random::randUnsignedInt(lb, ub);
			s_UIntTests.addTest(std::make_tuple(
				producedValue, ub, LTE<unsigned int, unsigned int>()));
			s_UIntTests.addTest(std::make_tuple(
				producedValue, lb, GTE<unsigned int, unsigned int>()));
		}
	});

	testLambda(0U, 100U);
	testLambda(50U, 100U);
	testLambda(27U, 159U);
	testLambda(10'456U, 13'964U);

	return s_UIntTests.test();
}

bool RandomTester::testRandDouble()
{
	prep();

	int runs = 100'000;

	std::function<void(double, double)> testLambda([&](double lb, double ub) {
		double producedValue = 0.0;
		for (int i = 0; i < runs; i++)
		{
			producedValue = eqx::Random::randDouble(lb, ub);
			s_DoubleTests.addTest(std::make_tuple(
				producedValue, ub, LTE<double, double>()));
			s_DoubleTests.addTest(std::make_tuple(
				producedValue, lb, GTE<double, double>()));
		}
	});

	testLambda(0.0, 1.0);
	testLambda(-1.0, 0.0);
	testLambda(-1.0, 1.0);
	testLambda(-10.0, 1.0);
	testLambda(-1.0, 10.0);
	testLambda(-10.0, -1.0);
	testLambda(1.0, 10.0);
	testLambda(0.0, std::numeric_limits<double>::max());
	testLambda(std::numeric_limits<double>::lowest(), 0.0);
	testLambda(std::numeric_limits<double>::lowest(),
			   std::numeric_limits<double>::max());
	testLambda(std::numeric_limits<double>::lowest(),
			   std::nexttoward(0.0, std::numeric_limits<double>::max()));
	testLambda(std::nexttoward(0.0, std::numeric_limits<double>::lowest()),
			   std::numeric_limits<double>::max());
	testLambda(std::numeric_limits<double>::lowest(),
			   std::nextafter(0.0, std::numeric_limits<double>::max()));
	testLambda(std::nextafter(0.0, std::numeric_limits<double>::lowest()),
			   std::numeric_limits<double>::max());
	testLambda(std::nexttoward(0.0, std::numeric_limits<double>::lowest()),
			   std::nexttoward(0.0, std::numeric_limits<double>::max()));

	return s_DoubleTests.test();
}

bool RandomTester::testIntDistribution()
{
	prep();

	int runs = 100'000;

	std::function<void(int, int)> testLambda([&](int lb, int ub) {
		std::unordered_map<int, int> dist;
		for (int i = lb; i <= ub; i++)
		{
			dist[lb] = 0;
		}

		for (int i = 0; i < runs; i++)
		{
			dist[eqx::Random::randInt(lb, ub)]++;
		}

		int n = ub - lb + 1,
			expectedCount = static_cast<int>(static_cast<double>(runs) / n),
			delta = static_cast<int>(expectedCount * 0.3) + 8;
		for (const std::pair<const int, int>& link : dist)
		{
			s_IntTests.addTest(std::make_tuple(
				link.second, expectedCount + delta, LTE<int, int>()));
			s_IntTests.addTest(std::make_tuple(
				link.second, expectedCount - delta, GTE<int, int>()));
		}
	});

	testLambda(1, 100'000);
	testLambda(-100, 100);
	testLambda(-100'000, 100'000);
	testLambda(-1'000'000, 1'000'000);
	testLambda(0, 1'000'000);
	testLambda(-1'000'000, 0);
	testLambda(10, 20);
	testLambda(-20, 10);
	testLambda(17, 33);
	testLambda(0, 2);
	testLambda(-1, 0);

	return s_IntTests.test();
}

bool RandomTester::testFlipCoin()
{
	prep();

	int runs = 1'000'000,
		producedValue = 0,
		heads = 0,
		tails = 0,
		expectedCount = static_cast<int>(runs / 2.0),
		delta = static_cast<int>(expectedCount * 0.3) + 8;
	for (int i = 0; i < runs; i++)
	{
		producedValue = eqx::Random::flipCoin();
		s_IntTests.addTest(std::make_tuple(
			producedValue, 1, LTE<int, int>()));
		s_IntTests.addTest(std::make_tuple(
			producedValue, 0, GTE<int, int>()));
		if (producedValue == 0)
		{
			heads++;
		}
		else if (producedValue == 1)
		{
			tails++;
		}
	}
	s_IntTests.addTest(std::make_tuple(
		heads, expectedCount + delta, LTE<int, int>()));
	s_IntTests.addTest(std::make_tuple(
		heads, expectedCount - delta, GTE<int, int>()));
	s_IntTests.addTest(std::make_tuple(
		tails, expectedCount + delta, LTE<int, int>()));
	s_IntTests.addTest(std::make_tuple(
		tails, expectedCount - delta, GTE<int, int>()));

	return s_IntTests.test();
}

bool RandomTester::testRollDice()
{
	prep();

	int runs = 100'000;

	std::function<void(unsigned int)> testLambda([&](unsigned int sides) {
		std::unordered_map<unsigned int, int> dist;
		for (unsigned int i = 1U; i <= sides; i++)
		{
			dist[i] = 0;
		}

		unsigned int producedValue = 0U;
		for (int i = 0; i < runs; i++)
		{
			producedValue = eqx::Random::rollDice(sides);
			s_UIntTests.addTest(std::make_tuple(
				producedValue, 1U, GTE<unsigned int, unsigned int>()));
			s_UIntTests.addTest(std::make_tuple(
				producedValue, sides, LTE<unsigned int, unsigned int>()));
			dist[i]++;
		}

		int n = sides,
			expectedCount = static_cast<int>(static_cast<double>(runs) / n),
			delta = static_cast<int>(expectedCount * 0.3) + 8;
		for (const std::pair<const unsigned int, int>& link : dist)
		{
			s_IntTests.addTest(std::make_tuple(
				link.second, expectedCount + delta, LTE<int, int>()));
			s_IntTests.addTest(std::make_tuple(
				link.second, expectedCount - delta, GTE<int, int>()));
		}
	});

	testLambda(2U);
	testLambda(10U);
	testLambda(100U);
	testLambda(60U);

	return s_UIntTests.test();
}

bool RandomTester::testGenerateSeed()
{
	prep();

	int runs = 1'000'000;

	std::unordered_map<unsigned int, int> seeds;
	unsigned int producedValue = 0U;
	for (int i = 0; i < runs; i++)
	{
		producedValue = eqx::Random::generateSeed();
		seeds[producedValue]++;
	}

	for (const std::pair<const unsigned int, int>& link : seeds)
	{
		s_IntTests.addTest(std::make_tuple(
			link.second, 2, LTE<int, int>()));
	}

	return s_IntTests.test();
}

void RandomTester::prep()
{
	s_IntTests.clear();
	s_UIntTests.clear();
	s_DoubleTests.clear();
}