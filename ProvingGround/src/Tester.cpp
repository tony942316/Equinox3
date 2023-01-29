#include "Tester.h"

#include <iostream>

Tester::Tester()
{
}

void Tester::testAll()
{
	std::cout << "\n*********************" << std::endl;
	if (LogTester::test() &&
		randTests.testAll() &&
		stopWatchTests.testAll() &&
		mathematicsTests.testAll() &&
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