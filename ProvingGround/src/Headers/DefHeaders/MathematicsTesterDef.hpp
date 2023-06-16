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

#pragma once

inline void MathematicsTester::test()
{
	std::cout << "Testing Mathematics..." << std::endl;
	testArccos();
	testArcsin();
	UnitTester::printStatus();
	UnitTester::clear();
}

inline void MathematicsTester::testArccos()
{
	const auto root2o2 = std::sqrt(2.0) / 2.0;
	const auto root3o2 = std::sqrt(3.0) / 2.0;

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

inline void MathematicsTester::testArcsin()
{
	const auto root2o2 = std::sqrt(2.0) / 2.0;
	const auto root3o2 = std::sqrt(3.0) / 2.0;

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

constexpr void MathematicsTester::testAbs() noexcept
{
	static_assert(eqx::abs(0) == 0);
	static_assert(eqx::abs(1) == 1);
	static_assert(eqx::abs(-1) == 1);
	static_assert(eqx::abs(0.0) == 0.0);
	static_assert(eqx::abs(0.1) == 0.1);
	static_assert(eqx::abs(-0.1) == 0.1);
	static_assert(eqx::abs(-100.05) == 100.05);
	static_assert(eqx::abs(100.05) == 100.05);
	static_assert(eqx::abs(std::numeric_limits<double>::lowest()) == 
		std::numeric_limits<double>::max());
}

constexpr void MathematicsTester::testEquals() noexcept
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

	static_assert(eqx::equals(0.01, 0.01) == true);
	static_assert(eqx::equals(1.01, 0.01) == false);

	static_assert(eqx::equals(0.01, 0.02) == false);
	static_assert(eqx::equals(0.01, 0.02, 0.01) == false);
	static_assert(eqx::equals(0.01, 0.02, 0.1) == true);

	static_assert(eqx::equals(0.000001, 0.0000001, 0.0000001) == false);
	static_assert(eqx::equals(1000.0, 1100.0, 100.0) == false);
	static_assert(eqx::equals(1000.0, 1099.0, 100.0) == true);
}

constexpr void MathematicsTester::testDistance() noexcept
{
	static_assert(eqx::distance(0, 0) == 0);
	static_assert(eqx::distance(0, 1) == 1);
	static_assert(eqx::distance(1, 0) == 1);
	static_assert(eqx::distance(-1, 1) == 2);

	static_assert(eqx::distance(0.0, 0.0) == 0.0);
	static_assert(eqx::distance(0.0, 1.0) == 1.0);
	static_assert(eqx::distance(1.0, 0.0) == 1.0);
	static_assert(eqx::distance(-1.0, 1.0) == 2.0);

	static_assert(eqx::distance(0U, 0U) == 0U);
	static_assert(eqx::distance(0U, 1U) == 1U);

	static_assert(eqx::distance(-100, 250) == 350);
	static_assert(eqx::distance(-250, 100) == 350);
	static_assert(eqx::distance(0, 100'000) == 100'000);

	static_assert(eqx::distance(-100.0, 250.0) == 350.0);
	static_assert(eqx::distance(-250.0, 100.0) == 350.0);
	static_assert(eqx::distance(0.0, 100'000.0) == 100'000.0);
	static_assert(eqx::distance(1.5, 10.2) == 8.7);
	static_assert(eqx::distance(-10.2, -1.5) == 8.7);
	static_assert(eqx::distance(-1.054689, 1.5047896) == 2.5594786000000003);

	static_assert(eqx::distance(0U, 100'000U) == 100'000U);
}

consteval void MathematicsTester::testGetSign() noexcept
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

consteval void MathematicsTester::testIsPositive() noexcept
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

consteval void MathematicsTester::testIsNegative() noexcept
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

constexpr void MathematicsTester::testWillOverflow() noexcept
{
	constexpr auto testLamda =
		[]<typename T>(T x, T y, bool expected) constexpr
	{
		const bool a = eqx::willOverflowAddition(x, y) == expected;
		const bool s = eqx::willOverflowSubtraction(x, -y) == expected;
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

constexpr void MathematicsTester::testDegreesToRadians() noexcept
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

constexpr void MathematicsTester::testRadiansToDegrees() noexcept
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

	constexpr auto pi6 = std::numbers::pi / 6;
	constexpr auto pi4 = std::numbers::pi / 4;
	constexpr auto pi3 = std::numbers::pi / 3;
	constexpr auto pi2 = std::numbers::pi / 2;

	static_assert(aproxEq(eqx::radiansToDegrees(0.0), 0.0));
	static_assert(aproxEq(eqx::radiansToDegrees(pi6), 30.0));
	static_assert(aproxEq(eqx::radiansToDegrees(pi4), 45.0));
	static_assert(aproxEq(eqx::radiansToDegrees(1.0), 57.29578));
	static_assert(aproxEq(eqx::radiansToDegrees(pi3), 60.0));
	static_assert(aproxEq(eqx::radiansToDegrees(pi2), 90.0));
	static_assert(aproxEq(eqx::radiansToDegrees(pi3 * 2.0), 120.0));
	static_assert(aproxEq(eqx::radiansToDegrees(pi4 * 3.0), 135.0));
	static_assert(aproxEq(eqx::radiansToDegrees(pi6 * 5.0), 150.0));
	static_assert(aproxEq(eqx::radiansToDegrees(std::numbers::pi), 180.0));
	static_assert(aproxEq(eqx::radiansToDegrees(pi6 * 7.0), 210.0));
	static_assert(aproxEq(eqx::radiansToDegrees(pi4 * 5.0), 225.0));
	static_assert(aproxEq(eqx::radiansToDegrees(pi3 * 4.0), 240.0));
	static_assert(aproxEq(eqx::radiansToDegrees(pi2 * 3.0), 270.0));
	static_assert(aproxEq(eqx::radiansToDegrees(pi3 * 5.0), 300.0));
	static_assert(aproxEq(eqx::radiansToDegrees(pi4 * 7.0), 315.0));
	static_assert(aproxEq(eqx::radiansToDegrees(pi6 * 11), 330.0));
	static_assert(aproxEq(eqx::radiansToDegrees(std::numbers::pi * 2), 360.0));
}
