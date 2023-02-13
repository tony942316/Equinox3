#pragma once

#include "SuperEnumTester.hpp"
#include "LogTester.hpp"
#include "RandomTester.hpp"
#include "StopWatchTester.hpp"
#include "MathematicsTester.hpp"
#include "PointTester.hpp"
#include "RectangleTester.hpp"

class Tester
{
public:
	Tester();

	void testAll();

private:
	PointTester pointTests;
	RectangleTester rectTests;
};