#include <iostream>

#include "UnitTest.hpp"
#include "MiscTester.hpp"
#include "UtilityMacrosTester.hpp"
#include "SuperEnumTester.hpp"
#include "LogTester.hpp"

#include "Workbench.hpp"

int main()
{
	std::cout << "Start\n" << std::endl;

	workbenchMain();

	MiscTester::test();
	UtilityMacrosTester::test();
	SuperEnumTester::test();
	LogTester::test();

	std::cout << "\nEnd" << std::endl;
	std::cin.get();
	return 0;
}