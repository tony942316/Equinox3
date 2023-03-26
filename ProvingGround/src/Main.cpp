#include <iostream>

#include "UnitTest.hpp"
#include "MiscTester.hpp"
#include "UtilityMacrosTester.hpp"

#include "Workbench.hpp"

int main()
{
	std::cout << "Start\n" << std::endl;

	workbenchMain();

	MiscTester::test();
	UtilityMacrosTester::test();
	UnitTester::printStatus();

	std::cout << "\nEnd" << std::endl;
	std::cin.get();
	return 0;
}