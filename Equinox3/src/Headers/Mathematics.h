#pragma once

#include <cmath>
#include <type_traits>

#include "Log.h"

namespace eqx
{
	/**
	 * @brief Check If Two Aritmetic Types Will Overflow
	 * 
	 * @param val1 Value To Be Checked
	 * @param val2 Other Value To Be Checked
	 * 
	 * @returns If Overflow Would Occur
	 */
	template<typename T>
	bool willOverflowAddition(T val1, T val2)
	{
		T zero = static_cast<T>(0);
		if (val1 == zero || val2 == zero)
		{
			return false;
		}
		else if (val1 > zero && val2 > zero)
		{
			if (val1 + val2 <= val1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (val1 < zero && val2 < zero)
		{
			if (val1 + val2 >= val1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if ((val1 < zero && val2 > zero) || (val1 > zero && val2 < zero))
		{
			return false;
		}
		else
		{
			eqx::Log::log(eqx::Log::Level::error, "willOverflowAddition should not have reached this line", eqx::Log::Type::unreachableCodeError);
			return true;
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
		if (willOverflowAddition(x1, -x2))
		{
			eqx::Log::log(eqx::Log::Level::error, "Arithmetic Overflow", eqx::Log::Type::overflowError);
			return static_cast<T>(0);
		}
		else if (std::is_integral<T>::value)
		{
			return static_cast<T>(std::abs(x1 - x2));
		}
		else if (std::is_floating_point<T>::value)
		{
			return static_cast<T>(std::fabs(x1 - x2));
		}
		else
		{
			eqx::Log::log(eqx::Log::Level::error, "Unknown Case", eqx::Log::Type::runtimeError);
			return static_cast<T>(0);
		}
	}
}