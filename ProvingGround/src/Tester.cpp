#include "Tester.hpp"

#include <iostream>

#include "UtilityMacrosTester.hpp"
#include "MiscTester.hpp"
#include "SuperEnumTester.hpp"
#include "LogTester.hpp"
#include "MathematicsTester.hpp"
#include "RandomTester.hpp"
#include "StopWatchTester.hpp"
#include "PointTester.hpp"
#include "RectangleTester.hpp"
#include "BenchmarkTester.hpp"

namespace Tester
{
	void test()
	{
		std::cout << "\n*********************" << std::endl;
		UtilityMacrosTester::test();
		MiscTester::test();
		SuperEnumTester::test();
		LogTester::test();
		MathematicsTester::test();
		RandomTester::test();
		StopWatchTester::test();
		PointTester::test();
		RectangleTester::test();
		BenchmarkTester::test();
		std::cout << "*********************\n" << std::endl;
	}
}