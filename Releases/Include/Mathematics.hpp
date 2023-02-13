#pragma once

#include <type_traits>
#include <limits>

#include "Log.hpp"

namespace eqx
{
	/**
	 * @brief Pi Accurate To 36 Decimal Points
	 */
	template <typename T>
	T constexpr pi = static_cast<T>(3.141592653589793238462643383279502884L);

	/**
	 * @brief Type Accurate Zero
	 */
	template <typename T>
	T constexpr zero = static_cast<T>(0);

	/**
	 * @brief std::fabs(x - y) < error
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
	 * 
	 * @param val Value To Be Checked
	 * 
	 * @returns 1, 0, And -1 For Positive, Zero, And Negative
	 *		Values Respectively
	 */
	template <typename T>
	int getSign(T val)
	{
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
	bool isPositive(T val)
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
	bool isNegative(T val)
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
	 *
	 * @param x Value To Be Checked
	 * @param y Other Value To Be Checked
	 *
	 * @returns true If Overflow Would Occur
	 */
	template<typename T>
	bool willOverflowAddition(T x, T y)
	{
		if (!std::is_arithmetic_v<T>)
		{
			eqx::Log::log(eqx::Log::Level::error, 
				"Not defined for non arithmetic types", 
				eqx::Log::Type::runtimeError);
			return true;
		}
		else if (x == eqx::zero<T> || y == eqx::zero<T>)
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
	 * @brief Must Be Arithmetic Types
	 * 
	 * @param x1 First Point
	 * @param x2 Second Point
	 *
	 * @returns Distance Between Two One Dimensional Points
	 */
	template<typename T>
	T distance(T x1, T x2)
	{
		if (!std::is_arithmetic_v<T>)
		{
			eqx::Log::log(eqx::Log::Level::error, 
				"Not defined for non arithmetic types", 
				eqx::Log::Type::runtimeError);
			return eqx::zero<T>;
		}
		else if (willOverflowAddition(x1, -x2) ||
				 (std::is_integral_v<T> && 
				 (x1 - x2) == std::numeric_limits<T>::lowest()))
		{
			eqx::Log::log(eqx::Log::Level::error, 
				"Arithmetic Overflow", 
				eqx::Log::Type::overflowError);
			return eqx::zero<T>;
		}
		else if (std::is_integral_v<T>)
		{
			return std::abs(x1 - x2);
		}
		else if (std::is_floating_point_v<T>)
		{
			return std::fabs(x1 - x2);
		}
		else
		{
			eqx::Log::log(eqx::Log::Level::error, 
				"Unknown Case", 
				eqx::Log::Type::runtimeError);
			return static_cast<T>(0);
		}
	}

	/**
	 * @brief Convert Degrees To Radians
	 * 
	 * @param degrees Degrees To Be Converted
	 * 
	 * @returns Radian Equivalent Of The Input
	 */
	template <typename T>
	double degreesToRadians(T degrees)
	{
		return static_cast<double>(degrees) * (eqx::pi<double> / 180.0);
	}

	/**
	 * @brief Convert Radians To Degrees
	 *
	 * @param radians Radians To Be Converted
	 *
	 * @returns Degree Equivalent Of The Input
	 */
	template <typename T>
	double radiansToDegrees(T radians)
	{
		return static_cast<double>(radians) * (180.0 / eqx::pi<double>);
	}

	/**
	 * @brief Compute Both Arcsine Values
	 * @brief Value Must Be In Interval [-1.0, 1.0]
	 * 
	 * @param value Value To Be Computed
	 * 
	 * @returns A Pair Of Both Values In Degrees
	 */
	template <typename T>
	std::pair<double, double> arcsin(T value)
	{
		if (value > 1.0 || value < -1.0)
		{
			eqx::Log::log(eqx::Log::Level::error, "Domain Error: [-1.0, 1.0]", eqx::Log::Type::runtimeError);
			return std::make_pair(0.0, 0.0);
		}
		else if (!std::is_arithmetic<T>::value)
		{
			eqx::Log::log(eqx::Log::Level::error, "Not defined for non arithmetic types", eqx::Log::Type::runtimeError);
			return std::make_pair(0.0, 0.0);
		}

		std::pair<double, double> result;
		result.first = eqx::radiansToDegrees(std::asin(value));
		result.second = 180.0 - result.first;
		result.first = result.first >= 0.0 ?
			result.first : 360.0 + result.first;
		return result;
	}

	/**
	 * @brief Compute Both Arccosine Values
	 * @brief Value Must Be In Interval [-1.0, 1.0]
	 *
	 * @param value Value To Be Computed
	 *
	 * @returns A Pair Of Both Values In Degrees
	 */
	template <typename T>
	std::pair<double, double> arccos(T value)
	{
		if (value > 1.0 || value < -1.0)
		{
			eqx::Log::log(eqx::Log::Level::error, "Domain Error: [-1.0, 1.0]", eqx::Log::Type::runtimeError);
			return std::make_pair(0.0, 0.0);
		}
		else if (!std::is_arithmetic<T>::value)
		{
			eqx::Log::log(eqx::Log::Level::error, "Not defined for non arithmetic types", eqx::Log::Type::runtimeError);
			return std::make_pair(0.0, 0.0);
		}

		std::pair<double, double> result;
		result.first = eqx::radiansToDegrees(std::acos(value));
		result.second = 360.0 - result.first;
		return result;
	}
}