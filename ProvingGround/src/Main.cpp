#include <iostream>
#include <sstream>
#include <type_traits>

#include "EquinoxSTD.hpp"

#include "UnitTest.hpp"
#include "SuperEnumTester.hpp"
#include "LogTester.hpp"
#include "RandomTester.hpp"
#include "StopWatchTester.hpp"
#include "MathematicsTester.hpp"

#include "Workbench.hpp"



int main()
{
	std::cout << "Start\n" << std::endl;

	workbenchMain();
	eqx::Log::setLevel(eqx::Log::Level::all);
	SuperEnumTester::test();
	LogTester::test();
	eqx::Log::setLevel(eqx::Log::Level::all);
	RandomTester::test();
	StopWatchTester::test();
	MathematicsTester::test();

	std::cout << "\nEnd" << std::endl;
	std::cin.get();
	return 0;
}