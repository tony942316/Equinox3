#include "MathematicsTester.hpp"

#include <iostream>
#include <source_location>

#include "UnitTest.hpp"
#include "eqx_Mathematics.hpp"

namespace MathematicsTester
{
	void testEquals();
	void testDistance();
	void testArccos();
	void testArcsin();

	void test()
	{
		std::cout << "Testing Mathematics..." << std::endl;
		testEquals();
		testDistance();
		testArccos();
		testArcsin();
		UnitTester::printStatus();
		UnitTester::clear();
	}

	consteval void testGetSign();
	consteval void testIsPositive();
	consteval void testIsNegative();
	consteval void testWillOverflow();
	consteval void testDegreesToRadians();
	consteval void testRadiansToDegrees();
}

void MathematicsTester::testEquals()
{
	constexpr auto loc = std::source_location::current();
	auto testLambda =
		[&loc](bool expected, double p1, double p2, double e = 0.001)
		{
			auto info = std::string("");
			info += "eqx::equals(";
			info += std::to_string(p1);
			info += ", ";
			info += std::to_string(p2);
			info += ", ";
			info += std::to_string(e);
			info += ")";
			UnitTester::test(eqx::equals(p1, p2, e), expected,
				EQ<bool, bool>, info, loc);
		};

	testLambda(true, 0.01, 0.01);
	testLambda(false, 1.01, 0.01);

	testLambda(false, 0.01, 0.02);
	testLambda(false, 0.01, 0.02, 0.01);
	testLambda(true, 0.01, 0.02, 0.1);

	testLambda(false, 0.000001, 0.0000001, 0.0000001);
	testLambda(false, 1000.0, 1100.0, 100.0);
	testLambda(true, 1000.0, 1099.0, 100.0);

	
}

consteval void MathematicsTester::testGetSign()
{
	static_assert(eqx::getSign(1) == 1);
	static_assert(eqx::getSign(0) == 0);
	static_assert(eqx::getSign(-1) == -1);
	
	static_assert(eqx::getSign(1.0) == 1);
	static_assert(eqx::getSign(0.0) == 0);
	static_assert(eqx::getSign(-1.0) == -1);

	static_assert(eqx::getSign(2) == 1);
	static_assert(eqx::getSign(3) == 1);
	static_assert(eqx::getSign(5) == 1);
	static_assert(eqx::getSign(7) == 1);
	static_assert(eqx::getSign(10) == 1);

	static_assert(eqx::getSign(-2) == -1);
	static_assert(eqx::getSign(-3) == -1);
	static_assert(eqx::getSign(-5) == -1);
	static_assert(eqx::getSign(-7) == -1);
	static_assert(eqx::getSign(-10) == -1);
}

consteval void MathematicsTester::testIsPositive()
{
	static_assert(eqx::isPositive(1) == true);
	static_assert(eqx::isPositive(0) == false);
	static_assert(eqx::isPositive(-1) == false);

	static_assert(eqx::isPositive(1.0) == true);
	static_assert(eqx::isPositive(0.0) == false);
	static_assert(eqx::isPositive(-1.0) == false);

	static_assert(eqx::isPositive(2) == true);
	static_assert(eqx::isPositive(3) == true);
	static_assert(eqx::isPositive(5) == true);
	static_assert(eqx::isPositive(7) == true);
	static_assert(eqx::isPositive(10) == true);
	static_assert(eqx::isPositive(12) == true);
	static_assert(eqx::isPositive(13) == true);

	static_assert(eqx::isPositive(-2) == false);
	static_assert(eqx::isPositive(-3) == false);
	static_assert(eqx::isPositive(-5) == false);
	static_assert(eqx::isPositive(-7) == false);
	static_assert(eqx::isPositive(-10) == false);
	static_assert(eqx::isPositive(-12) == false);
	static_assert(eqx::isPositive(-13) == false);
}

consteval void MathematicsTester::testIsNegative()
{
	static_assert(eqx::isNegative(1) == false);
	static_assert(eqx::isNegative(0) == false);
	static_assert(eqx::isNegative(-1) == true);

	static_assert(eqx::isNegative(1.0) == false);
	static_assert(eqx::isNegative(0.0) == false);
	static_assert(eqx::isNegative(-1.0) == true);

	static_assert(eqx::isNegative(2) == false);
	static_assert(eqx::isNegative(3) == false);
	static_assert(eqx::isNegative(5) == false);
	static_assert(eqx::isNegative(7) == false);
	static_assert(eqx::isNegative(10) == false);
	static_assert(eqx::isNegative(12) == false);
	static_assert(eqx::isNegative(13) == false);

	static_assert(eqx::isNegative(-2) == true);
	static_assert(eqx::isNegative(-3) == true);
	static_assert(eqx::isNegative(-5) == true);
	static_assert(eqx::isNegative(-7) == true);
	static_assert(eqx::isNegative(-10) == true);
	static_assert(eqx::isNegative(-12) == true);
	static_assert(eqx::isNegative(-13) == true);
}

consteval void MathematicsTester::testWillOverflow()
{
	constexpr auto testLamda = 
		[]<typename T>(T x, T y, bool expected) constexpr
		{
			bool a = eqx::willOverflowAddition(x, y) == expected;
			bool s = eqx::willOverflowSubtraction(x, -y) == expected;
			return a && s;
		};

	static_assert(testLamda(-1, -1, false));
	static_assert(testLamda(0, 0, false));
	static_assert(testLamda(1, 1, false));

	static_assert(testLamda(-1.0, -1.0, false));
	static_assert(testLamda(0.0, 0.0, false));
	static_assert(testLamda(1.0, 1.0, false));

	static_assert(eqx::willOverflowAddition(0U, 0U) == false);
	static_assert(eqx::willOverflowAddition(0U, 1U) == false);

	static_assert(testLamda(std::numeric_limits<int>::max(), 1, true));
	static_assert(testLamda(std::numeric_limits<int>::max(), -1, false));
	static_assert(testLamda(std::numeric_limits<int>::lowest(), 1, false));
	static_assert(testLamda(std::numeric_limits<int>::lowest(), -1, true));
	static_assert(testLamda(std::numeric_limits<int>::max(), 
		std::numeric_limits<int>::max(), true));
	static_assert(testLamda(std::numeric_limits<int>::lowest(),
		std::numeric_limits<int>::lowest(), true));

	static_assert(eqx::willOverflowAddition(
		std::numeric_limits<int>::max(), std::numeric_limits<int>::lowest())
		== false);
	static_assert(eqx::willOverflowSubtraction(
		std::numeric_limits<int>::max(), std::numeric_limits<int>::lowest())
		== true);

	static_assert(testLamda(std::numeric_limits<double>::max(), 1.0, true));
	static_assert(testLamda(std::numeric_limits<double>::max(), -1.0, false));
	static_assert(testLamda(std::numeric_limits<double>::lowest(), 
		1.0, false));
	static_assert(testLamda(std::numeric_limits<double>::lowest(), 
		-1.0, true));
	static_assert(testLamda(std::numeric_limits<double>::max(),
		std::numeric_limits<double>::max(), true));
	static_assert(testLamda(std::numeric_limits<double>::lowest(),
		std::numeric_limits<double>::lowest(), true));
	static_assert(testLamda(std::numeric_limits<double>::max(),
		std::numeric_limits<double>::lowest(), false));

	static_assert(
		eqx::willOverflowAddition(std::numeric_limits<unsigned int>::max(),
			1U)
		== true);
	static_assert(
		eqx::willOverflowAddition(std::numeric_limits<unsigned int>::max(),
			0U)
		== false);
	static_assert(
		eqx::willOverflowAddition(std::numeric_limits<unsigned int>::max(),
			std::numeric_limits<unsigned int>::max())
		== true);

	static_assert(
		eqx::willOverflowSubtraction(std::numeric_limits<unsigned int>::max(),
			std::numeric_limits<unsigned int>::max())
		== false);
	static_assert(
		eqx::willOverflowSubtraction(0U,
			std::numeric_limits<unsigned int>::max())
		== true);
	static_assert(
		eqx::willOverflowSubtraction(1U,
			std::numeric_limits<unsigned int>::max())
		== true);
}

void MathematicsTester::testDistance()
{
	UnitTester::test(eqx::distance(0, 0), 0);
	UnitTester::test(eqx::distance(0, 1), 1);
	UnitTester::test(eqx::distance(1, 0), 1);
	UnitTester::test(eqx::distance(-1, 1), 2);
	
	UnitTester::test(eqx::distance(0.0, 0.0), 0.0);
	UnitTester::test(eqx::distance(0.0, 1.0), 1.0);
	UnitTester::test(eqx::distance(1.0, 0.0), 1.0);
	UnitTester::test(eqx::distance(-1.0, 1.0), 2.0);

	UnitTester::test(eqx::distance(0U, 0U), 0U);
	UnitTester::test(eqx::distance(0U, 1U), 1U);

	UnitTester::test(eqx::distance(-100, 250), 350);
	UnitTester::test(eqx::distance(-250, 100), 350);
	UnitTester::test(eqx::distance(0, 100'000), 100'000);

	UnitTester::test(eqx::distance(-100.0, 250.0), 350.0);
	UnitTester::test(eqx::distance(-250.0, 100.0), 350.0);
	UnitTester::test(eqx::distance(0.0, 100'000.0), 100'000.0);
	UnitTester::test(eqx::distance(1.5, 10.2), 8.7);
	UnitTester::test(eqx::distance(-10.2, -1.5), 8.7);
	UnitTester::test(eqx::distance(-1.054689, 1.5047896), 2.5594786);

	UnitTester::test(eqx::distance(0U, 100'000U), 100'000U);
}

consteval void MathematicsTester::testDegreesToRadians()
{
	constexpr auto cAbs =
		[]<typename T>(T x)
		{
			return x >= 0 ? x : x * -1;
		};

	constexpr auto aproxEq =
		[]<typename T, typename U>(T x, U y) constexpr
		{
			if constexpr (std::is_floating_point_v<T> ||
				std::is_floating_point_v<U>)
			{
				return cAbs(x - y) < 0.00001L;
			}
			else
			{
				return x == y;
			}
		};

	static_assert(aproxEq(eqx::degreesToRadians(0.0), 0.0));
	static_assert(aproxEq(eqx::degreesToRadians(1.0), 0.0174533));
	static_assert(aproxEq(eqx::degreesToRadians(30.0), 0.523599));
	static_assert(aproxEq(eqx::degreesToRadians(45.0), 0.785398));
	static_assert(aproxEq(eqx::degreesToRadians(60.0), 1.0472));
	static_assert(aproxEq(eqx::degreesToRadians(90.0), 1.5708));
	static_assert(aproxEq(eqx::degreesToRadians(120.0), 2.0944));
	static_assert(aproxEq(eqx::degreesToRadians(135.0), 2.35619));
	static_assert(aproxEq(eqx::degreesToRadians(150.0), 2.61799));
	static_assert(aproxEq(eqx::degreesToRadians(180.0), 3.14159));
	static_assert(aproxEq(eqx::degreesToRadians(210.0), 3.66519));
	static_assert(aproxEq(eqx::degreesToRadians(225.0), 3.92699));
	static_assert(aproxEq(eqx::degreesToRadians(240.0), 4.18879));
	static_assert(aproxEq(eqx::degreesToRadians(270.0), 4.71239));
	static_assert(aproxEq(eqx::degreesToRadians(300.0), 5.23599));
	static_assert(aproxEq(eqx::degreesToRadians(315.0), 5.49779));
	static_assert(aproxEq(eqx::degreesToRadians(330.0), 5.75959));
	static_assert(aproxEq(eqx::degreesToRadians(360.0), 6.28319));
}

consteval void MathematicsTester::testRadiansToDegrees()
{
	constexpr auto cAbs =
		[]<typename T>(T x)
		{
			return x >= 0 ? x : x * -1;
		};

	constexpr auto aproxEq =
		[]<typename T, typename U>(T x, U y) constexpr
		{
			if constexpr (std::is_floating_point_v<T> ||
				std::is_floating_point_v<U>)
			{
				return cAbs(x - y) < 0.00001L;
			}
			else
			{
				return x == y;
			}
		};

	constexpr auto pi6 = eqx::pi / 6;
	constexpr auto pi4 = eqx::pi / 4;
	constexpr auto pi3 = eqx::pi / 3;
	constexpr auto pi2 = eqx::pi / 2;

	static_assert(aproxEq(eqx::radiansToDegrees(0.0), 0.0));
	static_assert(aproxEq(eqx::radiansToDegrees(pi6), 30.0));
	static_assert(aproxEq(eqx::radiansToDegrees(pi4), 45.0));
	static_assert(aproxEq(eqx::radiansToDegrees(1.0), 57.29578));
	static_assert(aproxEq(eqx::radiansToDegrees(pi3), 60.0));
	static_assert(aproxEq(eqx::radiansToDegrees(pi2), 90.0));
	static_assert(aproxEq(eqx::radiansToDegrees(pi3 * 2.0), 120.0));
	static_assert(aproxEq(eqx::radiansToDegrees(pi4 * 3.0), 135.0));
	static_assert(aproxEq(eqx::radiansToDegrees(pi6 * 5.0), 150.0));
	static_assert(aproxEq(eqx::radiansToDegrees(eqx::pi), 180.0));
	static_assert(aproxEq(eqx::radiansToDegrees(pi6 * 7.0), 210.0));
	static_assert(aproxEq(eqx::radiansToDegrees(pi4 * 5.0), 225.0));
	static_assert(aproxEq(eqx::radiansToDegrees(pi3 * 4.0), 240.0));
	static_assert(aproxEq(eqx::radiansToDegrees(pi2 * 3.0), 270.0));
	static_assert(aproxEq(eqx::radiansToDegrees(pi3 * 5.0), 300.0));
	static_assert(aproxEq(eqx::radiansToDegrees(pi4 * 7.0), 315.0));
	static_assert(aproxEq(eqx::radiansToDegrees(pi6 * 11), 330.0));
	static_assert(aproxEq(eqx::radiansToDegrees(eqx::pi * 2), 360.0));
}

void MathematicsTester::testArccos()
{
	auto root2o2 = std::sqrt(2.0) / 2.0;
	auto root3o2 = std::sqrt(3.0) / 2.0;

	UnitTester::test(eqx::arccos(1.0), std::make_pair(0.0, 360.0), 
		PEQ<double, double, double, double>);
	UnitTester::test(eqx::arccos(root3o2), std::make_pair(30.0, 330.0),
		PEQ<double, double, double, double>);
	UnitTester::test(eqx::arccos(root2o2), std::make_pair(45.0, 315.0),
		PEQ<double, double, double, double>);
	UnitTester::test(eqx::arccos(0.5), std::make_pair(60.0, 300.0),
		PEQ<double, double, double, double>);
	UnitTester::test(eqx::arccos(0.0), std::make_pair(90.0, 270.0),
		PEQ<double, double, double, double>);
	UnitTester::test(eqx::arccos(-0.5), std::make_pair(120.0, 240.0),
		PEQ<double, double, double, double>);
	UnitTester::test(eqx::arccos(-root2o2), std::make_pair(135.0, 225.0),
		PEQ<double, double, double, double>);
	UnitTester::test(eqx::arccos(-root3o2), std::make_pair(150.0, 210.0),
		PEQ<double, double, double, double>);
	UnitTester::test(eqx::arccos(-1.0), std::make_pair(180.0, 180.0),
		PEQ<double, double, double, double>);
}

void MathematicsTester::testArcsin()
{
	auto root2o2 = std::sqrt(2.0) / 2.0;
	auto root3o2 = std::sqrt(3.0) / 2.0;

	UnitTester::test(eqx::arcsin(1.0), std::make_pair(90.0, 90.0),
		PEQ<double, double, double, double>);
	UnitTester::test(eqx::arcsin(root3o2), std::make_pair(60.0, 120.0),
		PEQ<double, double, double, double>);
	UnitTester::test(eqx::arcsin(root2o2), std::make_pair(45.0, 135.0),
		PEQ<double, double, double, double>);
	UnitTester::test(eqx::arcsin(0.5), std::make_pair(30.0, 150.0),
		PEQ<double, double, double, double>);
	UnitTester::test(eqx::arcsin(0.0), std::make_pair(0.0, 180.0),
		PEQ<double, double, double, double>);
	UnitTester::test(eqx::arcsin(-0.5), std::make_pair(330.0, 210.0),
		PEQ<double, double, double, double>);
	UnitTester::test(eqx::arcsin(-root2o2), std::make_pair(315.0, 225.0),
		PEQ<double, double, double, double>);
	UnitTester::test(eqx::arcsin(-root3o2), std::make_pair(300.0, 240.0),
		PEQ<double, double, double, double>);
	UnitTester::test(eqx::arcsin(-1.0), std::make_pair(270.0, 270.0),
		PEQ<double, double, double, double>);
}