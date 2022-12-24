#pragma once

#include <functional>

class RandomTester
{
public:
	RandomTester();

	bool testAll();
	bool testRandInt();
	bool testRandUnsignedInt();
	bool testRandDouble();
	bool testIntDistribution();
	bool testFlipCoin();
	bool testRollDice();
	bool testGenerateSeed();
};