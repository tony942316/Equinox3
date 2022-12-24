#pragma once
class MathematicsTester
{
public:
	MathematicsTester();

	bool testAll();
	bool testWillOverflowAddition();
	bool testDistanceGeneric();
};