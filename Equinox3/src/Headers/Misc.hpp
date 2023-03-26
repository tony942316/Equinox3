#pragma once

#include <string>
#include <string_view>
#include <utility>
#include <vector>
#include <algorithm>
#include <ranges>
#include <type_traits>

#ifdef NDEBUG
#define eqx_debugOnly_runtimeAssert(expr, message) 0;
#else

/**
 * @brief Checks If A Boolean Expression Is True, If Not Then Print
 *		A Message To std::cerr And Call std::abort()
 * @brief Note: Removed If NDEBUG Is Defined
 *
 * @param expr Expression To Be Checked
 * @param msg Message To Print To std::cerr
 */
void eqx_debugOnly_runtimeAssert(bool expr, 
	std::string_view msg = "") noexcept;

#endif

namespace eqx
{
	/**
	 * @brief Constrain T To Be Convertable To A String
	 */
	template <typename T>
	concept stringable = requires(const T& t)
	{
		std::to_string(t);
	};

	template <typename T>
	concept stringType =
		std::is_same<std::remove_cv_t<T>, std::string>::value ||
		std::is_same<std::remove_cv_t<T>, std::wstring>::value ||
		std::is_same<std::remove_cv_t<T>, std::u8string>::value ||
		std::is_same<std::remove_cv_t<T>, std::u16string>::value ||
		std::is_same<std::remove_cv_t<T>, std::u32string>::value ||
		std::is_same<std::remove_cv_t<T>, std::string_view>::value ||
		std::is_same<std::remove_cv_t<T>, std::wstring_view>::value ||
		std::is_same<std::remove_cv_t<T>, std::u8string_view>::value ||
		std::is_same<std::remove_cv_t<T>, std::u16string_view>::value ||
		std::is_same<std::remove_cv_t<T>, std::u32string_view>::value;

	/**
	 * @brief Constrain T To Be A Const Collection
	 */
	template <typename T>
	concept constCollection = !eqx::stringType<T> &&
		requires(const T & t)
		{
			std::ranges::cbegin(t);
			std::ranges::cend(t);
			std::ranges::size(t);
		};

	/**
	 * @brief Convert A const char* To A std::string
	 * 
	 * @param cstring Value To Be Converted
	 * 
	 * @returns Value Converted To std::string
	 */
	std::string toString(const char* cstring);

	/**
	 * @brief Convert A Value To A std::string
	 * 
	 * @param val Value To Be Converted, Must Be eqx::stringable Compliant
	 * 
	 * @returns Value Converted To std::string
	 */
	template <eqx::stringable T>
	std::string toString(const T& val)
	{
		return std::to_string(val);
	}

	/**
	 * @brief Convert A Value To A std::string
	 *
	 * @param val Value To Be Converted, Must Be eqx::stringType Compliant
	 *
	 * @returns Value Converted To std::string
	 */
	template <eqx::stringType T>
	std::string toString(const T& val)
	{
		return std::string(val);
	}

	/**
	 * @brief Convert A std::pair To A std::string Of Form
	 *		"(p.first, p.second)"
	 *
	 * @param val Pair To Be Converted
	 *
	 * @returns Pair Converted To std::string
	 */
	template <typename T, typename U>
	std::string toString(const std::pair<T, U>& val)
	{
		return std::string("(" + eqx::toString(val.first) +
			", " + eqx::toString(val.second) + ")");
	}

	/**
	 * @brief
	 * 
	 * @param val Collection To Be Converted, Must Be eqx::constCollection
	 *		Compliant
	 * 
	 * @returns Collection Converted To std::string
	 */
	template <eqx::constCollection T>
	std::string toString(const T& val)
	{
		auto result = std::string("");
		result += "{ ";
		std::ranges::for_each(val,
			[&result](const auto& x)
			{
				result += eqx::toString(x);
				result += ", ";
			});
		result.pop_back();
		result.pop_back();
		result += " }";
		return result;
	}

	namespace pairPrint
	{
		/**
		 * @brief Allow std::pair To Be Streamed In The Form
		 *		"(p.first, p.second)"
		 */
		template <typename T, typename U>
		std::ostream& operator<< (std::ostream& os, std::pair<T, U> p)
		{
			return os << eqx::toString(p);
		}
	}

	namespace literals
	{
		/**
		 * @brief std::size_t Literal
		 */
		consteval std::size_t operator""_size (unsigned long long x) noexcept
		{
			return static_cast<std::size_t>(x);
		}

		/**
		 * @brief short Literal
		 */
		consteval short operator""_short (unsigned long long x) noexcept
		{
			return static_cast<short>(x);
		}

		/**
		 * @brief unsigned short Literal
		 */
		consteval unsigned short operator""_ushort (
			unsigned long long x) noexcept
		{
			return static_cast<unsigned short>(x);
		}
	}

	/**
	 * @brief Checks If A Boolean Expression Is True, If Not Then Print
	 *		A Message To std::cerr And Call std::abort()
	 * 
	 * @param expr Expression To Be Checked
	 * @param msg Message To Print To std::cerr
	 */
	void runtimeAssert(bool expr, std::string_view msg = "") noexcept;

	/**
	 * @brief "Zip" Two Collections Together In The Form Of
	 *		A std::vector<std::pair<C1 Held Value, C2 Held Value>>
	 * 
	 * @param x, y Must Be eqx::constCollection Compliant And 
	 *		Must Be The Same Size
	 * 
	 * @returns std::vector<std::pair<C1 Held Value, C2 Held Value>>
	 */
	template <eqx::constCollection C1, eqx::constCollection C2>
	[[nodiscard]] auto zip(const C1& x, const C2& y)
	{
		eqx::runtimeAssert(std::ranges::size(x) == std::ranges::size(y),
			"eqx::zip std::ranges::size(x) != std::ranges::size(y)!");

		using C1HeldValue = 
			std::remove_cvref_t<decltype(*std::ranges::cbegin(x))>;
		using C2HeldValue = 
			std::remove_cvref_t<decltype(*std::ranges::cbegin(y))>;

		auto zippedRange = 
			std::vector<std::pair<C1HeldValue, C2HeldValue>>();
		zippedRange.reserve(std::ranges::size(x));

		auto xIter = std::ranges::cbegin(x);
		auto yIter = std::ranges::cbegin(y);
		for (; xIter != std::ranges::cend(x); xIter++, yIter++)
		{
			zippedRange.push_back(std::make_pair(*xIter, *yIter));
		}

		return zippedRange;
	}
}