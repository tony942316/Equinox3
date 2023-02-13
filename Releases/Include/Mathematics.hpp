#pragma once

#include <type_traits>
#include <limits>

#include "Misc.hpp"

namespace eqx
{
	/**
	 * @brief Pi Accurate To 36 Decimal Points
	 */
	template <typename T = double>
	T constexpr pi_t = static_cast<T>(3.141592653589793238462643383279502884L);

	/**
	 * @brief Pi Accurate To Double Precision
	 */
	double constexpr pi = pi_t<double>;

	/**
	 * @brief Type Accurate Zero
	 */
	template <typename T>
	T constexpr zero = static_cast<T>(0);

	/**
	 * @brief std::fabs(x - y) < error
	 * @brief T Must Be A Floating Point Type
	 *
	 * @param x, y Values Must Be Floating Point
	 * @param error Amount Of Inaccuracy Permissible
	 *
	 * @returns true If The Difference Is Less Than error
	 */
	template <typename T>
	bool equals(T x, T y, T error = static_cast<T>(0.001))
	{
		static_assert(std::is_floating_point_v<T>, 
			"eqx::equals(T x, T y) : T Must Be A Floating Point Type!");

		return (std::fabs(x - y) < error);
	}

	/**
	 * @brief Checks The Sign Of A Given Value
	 * @brief T Must Be An Arithmetic Type
	 * 
	 * @param val Must Be Arithmetic
	 * 
	 * @returns 1, 0, And -1 For Positive, Zero, And Negative
	 *		Values Respectively
	 */
	template <typename T>
	int constexpr getSign(T val) noexcept
	{
		static_assert(std::is_arithmetic_v<T>,
			"eqx::getSign(T val) : T Must Be An Arithmetic Type!");

		if (val > eqx::zero<T>)
		{
			return 1;
		}
		else if (val < eqx::zero<T>)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}

	/**
	 * @brief Check If A Value Is Positive
	 * @brief 0 Is Not Positive
	 * 
	 * @param val Value To Be Checked
	 * 
	 * @returns true If The Value Is Positive
	 */
	template <typename T>
	bool constexpr isPositive(T val) noexcept
	{
		if (getSign(val) == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	/**
	 * @brief Check If A Value Is Negative
	 * @brief 0 Is Not Negative
	 *
	 * @param val Value To Be Checked
	 *
	 * @returns true If The Value Is Negative
	 */
	template <typename T>
	bool constexpr isNegative(T val) noexcept
	{
		if (getSign(val) == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	/**
	 * @brief Check If Two Aritmetic Types Will Overflow
	 * @brief T Must Be An Arithmetic Type
	 *
	 * @param x, y Values Must Be Arithmetic
	 *
	 * @returns true If Overflow Would Occur
	 */
	template<typename T>
	bool constexpr willOverflowAddition(T x, T y) noexcept
	{
		static_assert(std::is_arithmetic_v<T>, 
			"T Must Be An Arithmetic Type!");
		
		if (x == eqx::zero<T> || y == eqx::zero<T>)
		{
			return false;
		}
		else if (x > eqx::zero<T> && y > eqx::zero<T>)
		{
			if ((std::numeric_limits<T>::max() - x) < y)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (x < eqx::zero<T> && y < eqx::zero<T>)
		{
			if ((std::numeric_limits<T>::lowest() - x) > y)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	/**
	 * @brief Compute The Distance Between Two One Dimensional Points
	 * @brief T Must Be An Arithmetic Type
	 * 
	 * @param x1, x2 Values Must Be Arithmetic
	 *
	 * @returns Distance Between Two One Dimensional Points
	 */
	template<typename T>
	T distance(T x1, T x2) noexcept
	{
		static_assert(std::is_arithmetic_v<T>,
			"eqx::distance(T x1, T x2) : T Must Be An Arithmetic Type!");

		eqx_dynamic_assert(willOverflowAddition(x1, -x2) ||
						  (std::is_integral_v<T> &&
						  (x1 - x2) == std::numeric_limits<T>::lowest()),
						  "Arithmetic Overflow!");

		return static_cast<T>(std::fabs(x1 - x2));
	}

	/**
	 * @brief Convert Degrees To Radians
	 * @brief T Must Be An Arithmetic Type
	 * 
	 * @param degrees Degrees To Be Converted
	 * 
	 * @returns double Equal To The Radian Equivalent Of The Input
	 */
	template <typename T>
	double constexpr degreesToRadians(T degrees) noexcept
	{
		static_assert(std::is_arithmetic_v<T>,
			"T Must Be An Arithmetic Type!");

		return static_cast<double>(degrees) * (eqx::pi / 180.0);
	}

	/**
	 * @brief Convert Radians To Degrees
	 * @brief T Must Be An Arithmetic Type
	 *
	 * @param radians Radians To Be Converted
	 *
	 * @returns double Equal To The Degree Equivalent Of The Input
	 */
	template <typename T>
	double constexpr radiansToDegrees(T radians) noexcept
	{
		static_assert(std::is_arithmetic_v<T>,
			"T Must Be An Arithmetic Type!");

		return static_cast<double>(radians) * (180.0 / eqx::pi);
	}

	/**
	 * @brief Compute Both Arcsine Values
	 * @brief T Must Be An Arithmetic Type
	 * @brief Value Must Be In Interval [-1.0, 1.0]
	 * 
	 * @param value Value To Be Computed
	 * 
	 * @returns std::pair<double, double>, Values Are In Degrees
	 */
	template <typename T>
	std::pair<double, double> arcsin(T value) noexcept
	{
		static_assert(std::is_arithmetic_v<T>,
			"T Must Be An Arithmetic Type!");
		eqx_dynamic_assert(value <= 1.0 || value >= -1.0, "Domain Error!");

		std::pair<double, double> result;
		result.first = eqx::radiansToDegrees(std::asin(value));
		result.second = 180.0 - result.first;
		result.first = result.first >= 0.0 ?
			result.first : 360.0 + result.first;
		return result;
	}

	/**
	 * @brief Compute Both Arccosine Values
	 * @brief T Must Be An Arithmetic Type
	 * @brief Value Must Be In Interval [-1.0, 1.0]
	 *
	 * @param value Value To Be Computed
	 *
	 * @returns std::pair<double, double>, Values Are In Degrees
	 */
	template <typename T>
	std::pair<double, double> arccos(T value) noexcept
	{
		static_assert(std::is_arithmetic_v<T>,
			"T Must Be An Arithmetic Type!");
		eqx_dynamic_assert(value <= 1.0 || value >= -1.0, "Domain Error!");

		std::pair<double, double> result;
		result.first = eqx::radiansToDegrees(std::acos(value));
		result.second = 360.0 - result.first;
		return result;
	}
}