#pragma once

#include "SuperEnum.hpp"

#include "UnitTest.hpp"

class SuperEnumTester
{
public:
	SuperEnumTester() = delete;
	SuperEnumTester(const SuperEnumTester&) = delete;
	SuperEnumTester(SuperEnumTester&&) = delete;
	SuperEnumTester& operator= (const SuperEnumTester&) = delete;
	SuperEnumTester& operator= (SuperEnumTester&&) = delete;
	~SuperEnumTester() = delete;

	static bool test();

private:
	class superEnumShell
	{
	public:
		EQX_SUPER_ENUM_1(OnePub, e1)
		EQX_SUPER_ENUM_4(FourPub, e1, e2, 
			e3, e4)
		EQX_SUPER_ENUM_6(SixPub,
			e1, 
			e2, 
			e3, 
			e4, 
			e5, 
			e6
		)
	};

	static bool testGetEnums();
	static bool testGetStrings();
	static bool testToString();
	static bool testStream();

	static UniversalTester s_Tests;
};