#include "Tester.h"

#include <iostream>

Tester::Tester()
{
}

void Tester::testAll()
{
	std::cout << "\n*********************" << std::endl;
	if (SuperEnumTester::test() &&
		LogTester::test() &&
		RandomTester::test() &&
		StopWatchTester::test() &&
		MathematicsTester::test() &&
		pointTests.testAll() &&
		rectTests.testAll())
	{
		std::cout << "---All Pass---" << std::endl;
	}
	else
	{
		std::cout << "---FAIL!!!!---" << std::endl;
	}
	std::cout << "*********************\n" << std::endl;
}