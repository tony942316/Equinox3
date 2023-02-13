#pragma once

#include "UnitTest.hpp"

class MathematicsTester
{
public:
	MathematicsTester() = delete;
	MathematicsTester(const MathematicsTester&) = delete;
	MathematicsTester(MathematicsTester&&) = delete;
	MathematicsTester& operator= (const MathematicsTester&) = delete;
	MathematicsTester& operator= (MathematicsTester&&) = delete;
	~MathematicsTester() = delete;

	static bool test();

private:
	static bool testEquals();
	static void prep();

	static UnitTest<bool, bool> s_BoolTests;
};