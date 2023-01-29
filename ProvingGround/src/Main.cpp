#include <iostream>
#include <sstream>
#include <type_traits>

#include "EquinoxSTD.h"

#include "UnitTest.h"
#include "Tester.h"
#include "SuperEnumTester.h"

#include "Workbench.h"



int main()
{
	std::cout << "Start\n" << std::endl;

	//workbenchMain();

	SuperEnumTester::test();
	LogTester::test();

	std::cout << "\nEnd" << std::endl;
	std::cin.get();
	return 0;
}