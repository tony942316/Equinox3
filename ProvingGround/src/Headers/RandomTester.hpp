#pragma once

#include "UnitTest.hpp"

class RandomTester
{
public:
	RandomTester() = delete;
	RandomTester(const RandomTester&) = delete;
	RandomTester(RandomTester&&) = delete;
	RandomTester& operator= (const RandomTester&) = delete;
	RandomTester& operator= (RandomTester&&) = delete;
	~RandomTester() = delete;

	static bool test();

private:
	static bool testRandInt();
	static bool testRandUnsignedInt();
	static bool testRandDouble();
	static bool testIntDistribution();
	static bool testFlipCoin();
	static bool testRollDice();
	static bool testGenerateSeed();
	static void prep();

	static UnitTest<int, int> s_IntTests;
	static UnitTest<unsigned int, unsigned int> s_UIntTests;
	static UnitTest<double, double> s_DoubleTests;
};