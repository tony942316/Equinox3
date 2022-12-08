#include "Tester.h"

#include <iostream>
#include <unordered_map>

#include "EquinoxSTD.h"

Tester::Tester()
{
}

void Tester::testAll()
{
	testRandom();
}

void Tester::testRandom()
{
	bool fail = false;
	int randomInteger = 0;
	double randomDouble = 0.0;
	unsigned int seed1 = 0, seed2 = 0;
	std::unordered_map<int, int> intDist;
	for (int i = 0; i < 101; i++)
	{
		intDist[i] = 0;
	}
	for (int i = 0; i < 100'000; i++)
	{
		seed1 = eqx::Random::generateSeed();

		randomInteger = eqx::Random::randInt(0, 100);
		if (randomInteger > 100 || randomInteger < 0)
		{
			std::cout << "Random Fail 0-100: " << randomInteger << std::endl;
			fail = true;
			break;
		}
		intDist[randomInteger]++;

		randomDouble = eqx::Random::randDouble(0.0, 100.0);
		if (randomDouble > 100.0 || randomDouble < 0.0)
		{
			std::cout << "Random Fail 0.0-100.0: " << randomDouble << std::endl;
			fail = true;
			break;
		}

		seed2 = eqx::Random::generateSeed();
		if (seed1 == seed2)
		{
			std::cout << "Random Fail seed == seed: " << seed1 << ", " << seed2 << std::endl;
			fail = true;
			break;
		}
	}

	for (const std::pair<int, int>& num : intDist)
	{
		if (num.second > 1400 || num.second < 600)
		{
			std::cout << "Unexpected Distribution: " << num.first << ", " << num.second << std::endl;
			fail = true;
			break;
		}
	}

	if (!fail)
	{
		std::cout << "Random Tests Pass" << std::endl;
	}
}