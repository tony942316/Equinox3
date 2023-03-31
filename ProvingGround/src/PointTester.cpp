#include "PointTester.hpp"

#include <iostream>

#include "UnitTest.hpp"
#include "Point.hpp"

namespace PointTester
{
	void testEquals();
	void testToString();
	void testDistance();
	void testNormalize();
	void testAngle();

	void test()
	{
		std::cout << "Testing Point..." << std::endl;
		testEquals();
		testToString();
		testDistance();
		testNormalize();
		testAngle();
		UnitTester::printStatus();
		UnitTester::clear();
	}

	consteval void testConstruction();
	consteval void testPlus();
	consteval void testMinus();
}

consteval void PointTester::testConstruction()
{
	constexpr auto pointDefault = eqx::Point<double>();
	static_assert(pointDefault.x == 0.0);
	static_assert(pointDefault.y == 0.0);

	constexpr auto pointParam = eqx::Point<double>(1.5, 3.9);
	static_assert(pointParam.x == 1.5);
	static_assert(pointParam.y == 3.9);
}

consteval void PointTester::testPlus()
{
	constexpr auto point1 = eqx::Point<double>(1.0, 1.0);
	constexpr auto point2 = eqx::Point<double>(-10.0, 10.0);
	constexpr auto point3 = eqx::Point<double>(1.234, 7.654);

	constexpr auto cabs =
		[](double x) constexpr
		{
			return x >= 0 ? x : -x;
		};

	constexpr auto testLambda =
		[](const eqx::Point<double>& point, double x, double y) constexpr
		{
			return cabs(point.x - x) < 0.001 && cabs(point.y - y) < 0.001;
		};

	static_assert(testLambda(point1 + point1, 2.0, 2.0));
	static_assert(testLambda(point1 + point2, -9.0, 11.0));
	static_assert(testLambda(point1 + point3, 2.234, 8.654));
	static_assert(testLambda(point2 + point2, -20.0, 20.0));
	static_assert(testLambda(point2 + point3, -8.766, 17.654));
	static_assert(testLambda(point3 + point3, 2.468, 15.308));
}

consteval void PointTester::testMinus()
{
	constexpr auto point1 = eqx::Point<double>(1.0, 1.0);
	constexpr auto point2 = eqx::Point<double>(-10.0, 10.0);
	constexpr auto point3 = eqx::Point<double>(1.234, 7.654);

	constexpr auto cabs =
		[](double x) constexpr
		{
			return x >= 0 ? x : -x;
		};

	constexpr auto testLambda =
		[](const eqx::Point<double>& point, double x, double y) constexpr
		{
			return cabs(point.x - x) < 0.001 && cabs(point.y - y) < 0.001;
		};

	constexpr auto v = point2 - point3;

	static_assert(testLambda(point1 - point1, 0.0, 0.0));
	static_assert(testLambda(point1 - point2, 11.0, -9.0));
	static_assert(testLambda(point1 - point3, -0.234, -6.654));
	static_assert(testLambda(point2 - point2, 0.0, 0.0));
	static_assert(testLambda(point2 - point3, -11.234, 2.346));
	static_assert(testLambda(point3 - point3, 0.0, 0.0));
}

void PointTester::testEquals()
{
	constexpr auto point1 = eqx::Point<double>(1.0, 1.0);
	constexpr auto point2 = eqx::Point<double>(-10.0, 10.0);
	constexpr auto point3 = eqx::Point<double>(1.234, 7.654);
	constexpr auto point4 = eqx::Point<double>(-10.0, 10.0);

	UnitTester::test(eqx::equals(point1, point1), true);
	UnitTester::test(eqx::equals(point1, point2), false);
	UnitTester::test(eqx::equals(point1, point3), false);
	UnitTester::test(eqx::equals(point1, point4), false);
	UnitTester::test(eqx::equals(point2, point2), true);
	UnitTester::test(eqx::equals(point2, point3), false);
	UnitTester::test(eqx::equals(point2, point4), true);
	UnitTester::test(eqx::equals(point3, point3), true);
	UnitTester::test(eqx::equals(point3, point4), false);
	UnitTester::test(eqx::equals(point4, point4), true);
}

void PointTester::testToString()
{
	using namespace std::string_literals;
	constexpr auto point1 = eqx::Point<double>(1.0, 1.0);
	constexpr auto point2 = eqx::Point<double>(-10.0, 10.0);
	constexpr auto point3 = eqx::Point<double>(1.234, 7.654);

	UnitTester::test(eqx::toString(point1), "(1.000000, 1.000000)"s);
	UnitTester::test(eqx::toString(point2), "(-10.000000, 10.000000)"s);
	UnitTester::test(eqx::toString(point3), "(1.234000, 7.654000)"s);
}

void PointTester::testDistance()
{
	constexpr auto point1 = eqx::Point<double>(1.0, 1.0);
	constexpr auto point2 = eqx::Point<double>(-10.0, 10.0);
	constexpr auto point3 = eqx::Point<double>(1.234, 7.654);

	UnitTester::test(eqx::distance(point1, point1), 0.0);
	UnitTester::test(eqx::distance(point1, point2), 14.2126704);
	UnitTester::test(eqx::distance(point1, point3), 6.658113246);
	UnitTester::test(eqx::distance(point2, point2), 0.0);
	UnitTester::test(eqx::distance(point2, point3), 11.47634402);
	UnitTester::test(eqx::distance(point3, point3), 0.0);

}

void PointTester::testNormalize()
{
	constexpr auto origin = eqx::Point<double>(0.0, 0.0);

	constexpr auto point1 = eqx::Point<double>(1.0, 1.0);
	constexpr auto point2 = eqx::Point<double>(-10.0, 10.0);
	constexpr auto point3 = eqx::Point<double>(1.234, 7.654);

	auto point1Norm = eqx::normalize(point1);
	auto point2Norm = eqx::normalize(point2);
	auto point3Norm = eqx::normalize(point3);

	UnitTester::test(point1Norm.x, 0.70710678);
	UnitTester::test(point1Norm.y, 0.70710678);
	UnitTester::test(point2Norm.x, -0.70710678);
	UnitTester::test(point2Norm.y, 0.70710678);
	UnitTester::test(point3Norm.x, 0.15916755);
	UnitTester::test(point3Norm.y, 0.98725158);
	
	UnitTester::test(eqx::distance(origin, point1Norm), 1.0);
	UnitTester::test(eqx::distance(origin, point2Norm), 1.0);
	UnitTester::test(eqx::distance(origin, point3Norm), 1.0);
}

void PointTester::testAngle()
{
	constexpr auto point1 = eqx::Point<double>(1.0, 1.0);
	constexpr auto point2 = eqx::Point<double>(-10.0, 10.0);
	constexpr auto point3 = eqx::Point<double>(1.234, 7.654);

	UnitTester::test(eqx::angle(point1), 45.0);
	UnitTester::test(eqx::angle(point2), 135.0);
	UnitTester::test(eqx::angle(point3), 80.84141723);
}