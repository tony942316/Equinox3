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

#include "RandomTester.hpp"

#include <iostream>
#include <algorithm>

#include <unordered_map>

#include "UnitTest.hpp"
#include "eqx_Random.hpp"

namespace RandomTester
{
	void testRandomNumber();
	void testFlipCoin();
	void testRollDice();
	void testGenerateSeed();

	void test()
	{
		std::cout << "Testing Random..." << std::endl;
		testRandomNumber();
		testFlipCoin();
		testRollDice();
		testGenerateSeed();
		UnitTester::printStatus();
		UnitTester::clear();
	}
}

void RandomTester::testRandomNumber()
{
	auto runs = 1'000'000;
	auto randNum = 0;
	auto randNumDouble = 0.0;
	auto distInit = [](int lb, int ub)
	{
		auto dist = std::unordered_map<int, std::size_t>();
		for (int i = lb; i <= ub; i++)
		{
			dist[i] = 0ULL;
		}
		return dist;
	};
	auto testDist = [runs](const std::unordered_map<int, std::size_t>& dist)
	{
		std::ranges::for_each(dist,
			[&dist, runs](const auto& x)
			{
				auto exp = (static_cast<double>(runs) / dist.size());
				auto deviation = x.second / exp;
				UnitTester::test(deviation, 0.9, GTE<double, double>);
				UnitTester::test(deviation, 1.1, LTE<double, double>);
			});
	};

	auto dist = distInit(0, 100);
	auto dist2 = distInit(-100, 0);
	auto dist3 = distInit(-100, 100);

	for (int i = 0; i < runs; i++)
	{
		randNum = eqx::Random::randomNumber(0, 100);
		dist.at(randNum)++;
		UnitTester::test(randNum, 0, GTE<int, int>);
		UnitTester::test(randNum, 100, LTE<int, int>);

		randNum = eqx::Random::randomNumber(-100, 0);
		dist2.at(randNum)++;
		UnitTester::test(randNum, -100, GTE<int, int>);
		UnitTester::test(randNum, 0, LTE<int, int>);

		randNum = eqx::Random::randomNumber(-100, 100);
		dist3.at(randNum)++;
		UnitTester::test(randNum, -100, GTE<int, int>);
		UnitTester::test(randNum, 100, LTE<int, int>);

		randNumDouble = eqx::Random::randomNumber(0.0, 1.0);
		UnitTester::test(randNumDouble, 0.0, GTE<double, double>);
		UnitTester::test(randNumDouble, 1.0, LTE<double, double>);

		randNumDouble = eqx::Random::randomNumber(-1.0, 0.0);
		UnitTester::test(randNumDouble, -1.0, GTE<double, double>);
		UnitTester::test(randNumDouble, 0.0, LTE<double, double>);

		randNumDouble = eqx::Random::randomNumber(-1.0, 1.0);
		UnitTester::test(randNumDouble, -1.0, GTE<double, double>);
		UnitTester::test(randNumDouble, 1.0, LTE<double, double>);

		randNumDouble = eqx::Random::randomNumber(0.0,
			std::numeric_limits<double>::max());
		UnitTester::test(randNumDouble, 0.0, GTE<double, double>);
		UnitTester::test(randNumDouble, std::numeric_limits<double>::max(), 
			LTE<double, double>);

		randNumDouble = eqx::Random::randomNumber(
			std::numeric_limits<double>::lowest(), 0.0);
		UnitTester::test(randNumDouble, std::numeric_limits<double>::lowest(),
			GTE<double, double>);
		UnitTester::test(randNumDouble, 0.0, LTE<double, double>);

		randNumDouble = eqx::Random::randomNumber(
			std::numeric_limits<double>::lowest(), 
			std::numeric_limits<double>::max());
		UnitTester::test(randNumDouble, std::numeric_limits<double>::lowest(),
			GTE<double, double>);
		UnitTester::test(randNumDouble, std::numeric_limits<double>::max(), 
			LTE<double, double>);
	}

	testDist(dist);
	testDist(dist2);
	testDist(dist3);
}

void RandomTester::testFlipCoin()
{
	auto runs = 1'000'000;
	auto randCoin = 0U;
	auto heads = 0U;
	auto tails = 0U;

	for (int i = 0; i < runs; i++)
	{
		randCoin = eqx::Random::flipCoin();
		randCoin == 1U ? heads++ : tails++;
		UnitTester::test(randCoin, 0U, GTE<unsigned int, unsigned int>);
		UnitTester::test(randCoin, 1U, LTE<unsigned int, unsigned int>);
	}

	auto expected = runs / 2.0;
	auto deviation = heads / expected;
	UnitTester::test(deviation, 0.9, GTE<double, double>);
	UnitTester::test(deviation, 1.1, LTE<double, double>);
	deviation = tails / expected;
	UnitTester::test(deviation, 0.9, GTE<double, double>);
	UnitTester::test(deviation, 1.1, LTE<double, double>);
}

void RandomTester::testRollDice()
{
	auto runs = 1'000'000;
	auto randNum = 0U;

	for (int i = 0; i < runs; i++)
	{
		randNum = eqx::Random::rollDice();
		UnitTester::test(randNum, 1U, GTE<unsigned int, unsigned int>);
		UnitTester::test(randNum, 6U, LTE<unsigned int, unsigned int>);

		randNum = eqx::Random::rollDice(20U);
		UnitTester::test(randNum, 1U, GTE<unsigned int, unsigned int>);
		UnitTester::test(randNum, 20U, LTE<unsigned int, unsigned int>);

		randNum = eqx::Random::rollDice(50U);
		UnitTester::test(randNum, 1U, GTE<unsigned int, unsigned int>);
		UnitTester::test(randNum, 50U, LTE<unsigned int, unsigned int>);

		randNum = eqx::Random::rollDice(100U);
		UnitTester::test(randNum, 1U, GTE<unsigned int, unsigned int>);
		UnitTester::test(randNum, 100U, LTE<unsigned int, unsigned int>);
	}
}

void RandomTester::testGenerateSeed()
{
	auto runs = 1'000'000;
	auto seed = 0U;
	auto dist = std::unordered_map<unsigned int, std::size_t>();

	for (int i = 0; i < runs; i++)
	{
		seed = eqx::Random::generateSeed();
		try
		{
			dist.at(seed)++;
		}
		catch (const std::out_of_range&)
		{
			dist[seed] = static_cast<std::size_t>(1);
		}
	}

	auto collisions = 0ULL;
	auto expectedVariance = 1ULL;
	std::ranges::for_each(dist,
		[expectedVariance, &collisions](const auto& x)
		{
			if (x.second > static_cast<std::size_t>(1))
			{
				auto count = x.second - static_cast<std::size_t>(1);
				collisions += static_cast<unsigned long long>(count);
				auto deviation = 
					static_cast<unsigned long long>(count - expectedVariance);
				UnitTester::test(deviation, 3ULL,
					LTE<unsigned long long, unsigned long long>);
			}
		});

	auto totalVariance = collisions / static_cast<double>(runs);
	UnitTester::test(totalVariance, 0.001, LTE<double, double>);
}