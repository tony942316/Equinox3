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

	void testAll();

private:
	
};