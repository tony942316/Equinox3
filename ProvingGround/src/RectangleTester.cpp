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

#include "RectangleTester.hpp"

#include "UnitTest.hpp"
#include "eqx_Rectangle.hpp"

namespace RectangleTester
{
	void testToString();

	void test()
	{
		std::cout << "Testing Rectangle..." << std::endl;
		testToString();
		UnitTester::printStatus();
		UnitTester::clear();
	}

	consteval void testConstruction();
	consteval void testGetPoints();
	consteval void testIntersect();
	consteval void testIntersectExclusive();
}

void RectangleTester::testToString()
{
	using namespace std::string_literals;

	constexpr auto rect1 = eqx::Rectangle<double>(1.0, 1.0, 1.0, 1.0);
	constexpr auto rect2 = 
		eqx::Rectangle<double>(-10.0, -10.0, 3.0, 15.0);
	constexpr auto rect3 = 
		eqx::Rectangle<double>(6.123, -9.874, 6.548, 3.698);

	UnitTester::test(eqx::toString(rect1), 
		"(1.000000, 1.000000, 1.000000, 1.000000)"s);
	UnitTester::test(eqx::toString(rect2), 
		"(-10.000000, -10.000000, 3.000000, 15.000000)"s);
	UnitTester::test(eqx::toString(rect3), 
		"(6.123000, -9.874000, 6.548000, 3.698000)"s);
}

consteval void RectangleTester::testConstruction()
{
	constexpr auto rect0 = eqx::Rectangle<double>();
	constexpr auto rect1 = eqx::Rectangle<double>(1.0, 1.0, 1.0, 1.0);
	constexpr auto rect2 =
		eqx::Rectangle<double>(-10.0, -10.0, 3.0, 15.0);
	constexpr auto rect3 =
		eqx::Rectangle<double>(6.123, -9.874, 6.548, 3.698);

	constexpr auto testLambda =
		[](const eqx::Rectangle<double>& rect,
			double x, double y, double w, double h) constexpr
		{
			return rect.x == x && rect.y == y && rect.w == w && rect.h == h;
		};

	static_assert(testLambda(rect0, 0.0, 0.0, 0.0, 0.0));
	static_assert(testLambda(rect1, 1.0, 1.0, 1.0, 1.0));
	static_assert(testLambda(rect2, -10.0, -10.0, 3.0, 15.0));
	static_assert(testLambda(rect3, 6.123, -9.874, 6.548, 3.698));
}

consteval void RectangleTester::testGetPoints()
{
	constexpr auto rect1 = eqx::Rectangle<double>(1.0, 1.0, 1.0, 1.0);
	constexpr auto rect2 =
		eqx::Rectangle<double>(-10.0, -10.0, 3.0, 15.0);
	constexpr auto rect3 =
		eqx::Rectangle<double>(6.123, -9.874, 6.548, 3.698);

	constexpr auto cabs =
		[](double x) constexpr
		{
			return x >= 0.0 ? x : -x;
		};

	constexpr auto approxEq =
		[](double x, double y) constexpr
		{
			return cabs(x - y) < 0.001;
		};

	constexpr auto testLambdaHelper =
		[](const eqx::Point<double>& point1, 
			const eqx::Point<double>& point2) constexpr
		{
			return approxEq(point1.x, point2.x) && 
				approxEq(point1.y, point2.y);
		};

	constexpr auto testLambda =
		[](const eqx::Rectangle<double>& rect,
			const eqx::Point<double>& point) constexpr
		{
			auto tl = rect.getLocation();
			auto tr = rect.getTopRightPoint();
			auto bl = rect.getBottomLeftPoint();
			auto br = rect.getBottomRightPoint();
			auto c = rect.getCenterPoint();
			auto ec = eqx::Point<double>(rect.x + (rect.w / 2.0),
				rect.y + (rect.h / 2.0));

			return testLambdaHelper(tl, eqx::Point<double>(rect.x, rect.y)) &&
				testLambdaHelper(tr, eqx::Point<double>(point.x, rect.y)) &&
				testLambdaHelper(bl, eqx::Point<double>(rect.x, point.y)) &&
				testLambdaHelper(c, ec) && testLambdaHelper(br, point);
		};

	static_assert(testLambda(rect1, eqx::Point<double>(2.0, 2.0)));
	static_assert(testLambda(rect2, eqx::Point<double>(-7.0, 5.0)));
	static_assert(testLambda(rect3, eqx::Point<double>(12.671, -6.176)));
}

consteval void RectangleTester::testIntersect()
{
	constexpr auto rect1 = eqx::Rectangle<double>(1.0, 1.0, 1.0, 1.0);
	constexpr auto rect2 =
		eqx::Rectangle<double>(0.0, 0.0, 3.0, 3.0);
	constexpr auto rect3 =
		eqx::Rectangle<double>(1.459, 0.889, 0.374, 8.398);
	constexpr auto rect4 =
		eqx::Rectangle<double>(-5.689, -2.448, 3.589, 1.005);

	static_assert(eqx::intersect(rect1, rect1) == true);
	static_assert(eqx::intersect(rect1, rect2) == true);
	static_assert(eqx::intersect(rect1, rect3) == true);
	static_assert(eqx::intersect(rect1, rect4) == false);
	static_assert(eqx::intersect(rect2, rect2) == true);
	static_assert(eqx::intersect(rect2, rect3) == true);
	static_assert(eqx::intersect(rect2, rect4) == false);
	static_assert(eqx::intersect(rect3, rect3) == true);
	static_assert(eqx::intersect(rect3, rect4) == false);
	static_assert(eqx::intersect(rect4, rect4) == true);

	constexpr auto point1 = eqx::Point<double>();
	constexpr auto point2 = eqx::Point<double>(1.0, 1.0);
	constexpr auto point3 = eqx::Point<double>(1.713, 7.145);
	constexpr auto point4 = eqx::Point<double>(-3.1, -2.1);

	static_assert(eqx::intersect(rect1, point1) == false);
	static_assert(eqx::intersect(rect1, point2) == true);
	static_assert(eqx::intersect(rect1, point3) == false);
	static_assert(eqx::intersect(rect1, point4) == false);

	static_assert(eqx::intersect(rect2, point1) == true);
	static_assert(eqx::intersect(rect2, point2) == true);
	static_assert(eqx::intersect(rect2, point3) == false);
	static_assert(eqx::intersect(rect2, point4) == false);

	static_assert(eqx::intersect(rect3, point1) == false);
	static_assert(eqx::intersect(rect3, point2) == false);
	static_assert(eqx::intersect(rect3, point3) == true);
	static_assert(eqx::intersect(rect3, point4) == false);

	static_assert(eqx::intersect(rect4, point1) == false);
	static_assert(eqx::intersect(rect4, point2) == false);
	static_assert(eqx::intersect(rect4, point3) == false);
	static_assert(eqx::intersect(rect4, point4) == true);
}

consteval void testIntersectExclusive()
{
	constexpr auto rect1 = eqx::Rectangle<double>(1.0, 1.0, 1.0, 1.0);
	constexpr auto rect2 =
		eqx::Rectangle<double>(0.0, 0.0, 3.0, 3.0);
	constexpr auto rect3 =
		eqx::Rectangle<double>(1.459, 0.889, 0.374, 8.398);
	constexpr auto rect4 =
		eqx::Rectangle<double>(-5.689, -2.448, 3.589, 1.005);

	// Same As Inclusive
	static_assert(eqx::intersectExclusive(rect1, rect1) == true);
	static_assert(eqx::intersectExclusive(rect1, rect2) == true);
	static_assert(eqx::intersectExclusive(rect1, rect3) == true);
	static_assert(eqx::intersectExclusive(rect1, rect4) == false);
	static_assert(eqx::intersectExclusive(rect2, rect2) == true);
	static_assert(eqx::intersectExclusive(rect2, rect3) == true);
	static_assert(eqx::intersectExclusive(rect2, rect4) == false);
	static_assert(eqx::intersectExclusive(rect3, rect3) == true);
	static_assert(eqx::intersectExclusive(rect3, rect4) == false);
	static_assert(eqx::intersectExclusive(rect4, rect4) == true);

	// Diff
	constexpr auto rect5 =
		eqx::Rectangle<double>(3.0, 0.0, 3.0, 3.0);
	static_assert(eqx::intersectExclusive(rect2, rect5) == false);

	constexpr auto point1 = eqx::Point<double>();
	constexpr auto point2 = eqx::Point<double>(1.0, 1.0);
	constexpr auto point3 = eqx::Point<double>(1.713, 7.145);
	constexpr auto point4 = eqx::Point<double>(-3.1, -2.1);

	// Same As Inclusive
	static_assert(eqx::intersectExclusive(rect1, point1) == false);
	static_assert(eqx::intersectExclusive(rect1, point3) == false);
	static_assert(eqx::intersectExclusive(rect1, point4) == false);

	static_assert(eqx::intersectExclusive(rect2, point2) == true);
	static_assert(eqx::intersectExclusive(rect2, point3) == false);
	static_assert(eqx::intersectExclusive(rect2, point4) == false);

	static_assert(eqx::intersectExclusive(rect3, point1) == false);
	static_assert(eqx::intersectExclusive(rect3, point2) == false);
	static_assert(eqx::intersectExclusive(rect3, point3) == true);
	static_assert(eqx::intersectExclusive(rect3, point4) == false);

	static_assert(eqx::intersectExclusive(rect4, point1) == false);
	static_assert(eqx::intersectExclusive(rect4, point2) == false);
	static_assert(eqx::intersectExclusive(rect4, point3) == false);
	static_assert(eqx::intersectExclusive(rect4, point4) == true);

	// Diff
	static_assert(eqx::intersectExclusive(rect1, point2) == false);
	static_assert(eqx::intersectExclusive(rect2, point1) == false);
}