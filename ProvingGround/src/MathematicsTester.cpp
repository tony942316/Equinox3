#include "MathematicsTester.h"

#include <iostream>

#include "EquinoxSTD.h"
#include "UnitTest.h"

UnitTest<bool, bool> MathematicsTester::s_BoolTests;

bool MathematicsTester::test()
{
	if (testEquals())
	{
		std::cout << "Mathematics Tests Passed" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Mathematics Tests Failed!" << std::endl;
		return false;
	}
}

template <typename T>
bool testEqualsTypes(UnitTest<bool, bool>& tests)
{
	for (int i = 0; i < 1'000; i++)
	{
		tests.addTest(std::make_tuple(
			eqx::equals(i * static_cast<T>(1.0), i * static_cast<T>(1.0)),
			true,
			EQ2<bool, bool>));
		tests.addTest(std::make_tuple(
			eqx::equals(i * static_cast<T>(1.0), 
					   (i * static_cast<T>(1.0)) + static_cast<T>(0.01)),
			false,
			EQ2<bool, bool>));
		tests.addTest(std::make_tuple(
			eqx::equals(i * static_cast<T>(1.0), 
					   (i * static_cast<T>(1.0)) - static_cast<T>(0.01)),
			false,
			EQ2<bool, bool>));
		tests.addTest(std::make_tuple(
			eqx::equals(i * static_cast<T>(1.0), 
					   (i * static_cast<T>(1.0)) + static_cast<T>(0.01), 
					   static_cast<T>(0.1)),
			true,
			EQ2<bool, bool>));
		tests.addTest(std::make_tuple(
			eqx::equals(i * static_cast<T>(1.0),
					   (i * static_cast<T>(1.0)) - static_cast<T>(0.01),
					   static_cast<T>(0.1)),
			true,
			EQ2<bool, bool>));
	}

	return false;
}

bool MathematicsTester::testEquals()
{
	prep();

	testEqualsTypes<float>(s_BoolTests);
	testEqualsTypes<double>(s_BoolTests);
	testEqualsTypes<long double>(s_BoolTests);

	return s_BoolTests.test();
}

void MathematicsTester::prep()
{
	s_BoolTests.clear();
}
