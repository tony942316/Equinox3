#include <iostream>
#include <sstream>
#include <type_traits>

#include "EquinoxSTD.h"

#include "UnitTest.h"
#include "SuperEnumTester.h"
#include "LogTester.h"
#include "RandomTester.h"
#include "StopWatchTester.h"

#include "Workbench.h"



int main()
{
	std::cout << "Start\n" << std::endl;

	//workbenchMain();
	eqx::Log::setLevel(eqx::Log::Level::all);
	SuperEnumTester::test();
	LogTester::test();
	eqx::Log::setLevel(eqx::Log::Level::all);
	RandomTester::test();
	StopWatchTester::test();

	std::cout << "\nEnd" << std::endl;
	std::cin.get();
	return 0;
}