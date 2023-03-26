#include <iostream>

#include "UnitTest.hpp"
#include "MiscTester.hpp"

#include "Workbench.hpp"

int main()
{
	std::cout << "Start\n" << std::endl;

	workbenchMain();

	MiscTester::test();
	UnitTester::printStatus();

	std::cout << "\nEnd" << std::endl;
	std::cin.get();
	return 0;
}