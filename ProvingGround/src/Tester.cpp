/*
 * Copyright (C) 2023 Anthony H. Grasso
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

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