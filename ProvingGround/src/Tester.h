#pragma once

class Tester
{
public:
	Tester();

	bool testLog();
	bool testLogLog();
	bool testLogSetLevel();
	bool testLogSetOutputStream();
	bool testLogSetOutputFile();
	bool testLogClear();
	bool testLogGetLastLogType();
	bool testLogGetLastLogMessage();

	bool testRandom();
	bool testRandInt();
	bool testIntDistribution();
	bool testRandDouble();
	bool testGenerateSeed();

	bool testStopWatch();
	bool testStartStop();
	bool testReading();
	bool testGetting();

	bool testMathematics();
	bool testWillOverflowAddition();
	bool testDistanceGeneric();

	void testAll();

private:
	
};