#include <iostream>

#include "SuperEnumTester.hpp"

#include "Workbench.hpp"

int main()
{
	std::cout << "Start\n" << std::endl;

	workbenchMain();

	SuperEnumTester::test();

	std::cout << "\nEnd" << std::endl;
	std::cin.get();
	return 0;
}