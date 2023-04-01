#pragma once

#include <functional>
#include <chrono>

#include "eqx_StopWatch.hpp"

namespace eqx
{
	class Benchmark
	{
	public:
		/**
		 * @brief Construct Benchmark With A Function To Test
		 * 
		 * @param function The Function To Be Tested
		 */
		Benchmark(std::function<void(void)> function);

		/**
		 * Trivial Move And Copy Operation
		 */
		Benchmark(const Benchmark& other) = default;
		Benchmark(Benchmark&& other) = default;
		Benchmark& operator= (const Benchmark& other) = default;
		Benchmark& operator= (Benchmark&& other) = default;
		~Benchmark() = default;

		/**
		 * @brief Time How Long It Takes To Run The Function
		 */
		void bench() noexcept(noexcept(m_Function()));

		/**
		 * @brief Time How Long It Takes To Run The Function On Average
		 * 
		 * @param runs The Number Of Times The Function Is Run
		 */
		void avgBench(int runs = 1'000) noexcept(noexcept(m_Function()));

		/**
		 * @brief Build A String Representing The Time It Took To Run
		 *		The Function
		 * 
		 * @returns std::string Of Form "Bench: X TimeUnits"
		 */
		template <eqx::timeUnit T = std::chrono::milliseconds>
		[[nodiscard]] std::string toString() const
		{
			auto result = std::string("");
			result += "Bench: "; 
			result += 
				std::to_string(std::chrono::duration_cast<T>(m_Bench).count());
			if constexpr (std::same_as<T, std::chrono::nanoseconds>)
			{
				result += " ns";
			}
			else if constexpr (std::same_as<T, std::chrono::microseconds>)
			{
				result += " us";
			}
			else if constexpr (std::same_as<T, std::chrono::milliseconds>)
			{
				result += " ms";
			}
			else if constexpr (std::same_as<T, std::chrono::seconds>)
			{
				result += " s";
			}
			return result;
		}

	private:
		std::function<void(void)> m_Function;
		std::chrono::nanoseconds m_Bench;
	};
}