#include <iostream>

#include "UnitTest.hpp"
#include "MiscTester.hpp"
#include "UtilityMacrosTester.hpp"
#include "SuperEnumTester.hpp"
#include "LogTester.hpp"
#include "MathematicsTester.hpp"
#include "RandomTester.hpp"
#include "StopWatchTester.hpp"

#include "Workbench.hpp"

int main()
{
	std::cout << "Start" << std::endl;
	std::cin.get();

	StopWatchTester::test();

	workbenchMain();

	MiscTester::test();
	UtilityMacrosTester::test();
	SuperEnumTester::test();
	LogTester::test();
	MathematicsTester::test();
	RandomTester::test();
	StopWatchTester::test();

	std::cout << "\nEnd" << std::endl;
	std::cin.get();
	return 0;
}