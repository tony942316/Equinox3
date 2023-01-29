#pragma once

#include "LogTester.h"
#include "RandomTester.h"
#include "StopWatchTester.h"
#include "MathematicsTester.h"
#include "PointTester.h"
#include "RectangleTester.h"

class Tester
{
public:
	Tester();

	void testAll();

private:
	RandomTester randTests;
	StopWatchTester stopWatchTests;
	MathematicsTester mathematicsTests;
	PointTester pointTests;
	RectangleTester rectTests;
};