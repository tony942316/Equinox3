#include <iostream>

#include "Tester.hpp"

#include "Workbench.hpp"

int main()
{
	std::cout << "Start" << std::endl;
	std::cin.get();

	workbenchMain();

	Tester::test();

	std::cout << "\nEnd" << std::endl;
	std::cin.get();
	return 0;
}