#pragma once

#include <chrono>

namespace eqx
{
	class StopWatch
	{
	public:
		/**
		 * @brief Starts StopWatch On Construction
		 */
		StopWatch() noexcept;

		/**
		 * Trivial Move And Copy Operation
		 */
		StopWatch(const StopWatch&) = default;
		StopWatch(StopWatch&&) = default;
		StopWatch& operator= (const StopWatch&) = default;
		StopWatch& operator= (StopWatch&&) = default;
		~StopWatch() = default;

		/**
		 * @brief Set The Start Time Of The StopWatch And Reset The End Time
		 */
		void start() noexcept;

		/**
		 * @brief Set The End Time Of The StopWatch
		 */
		void stop() noexcept;

		/**
		 * @brief Stops And Gives Past Time In Seconds
		 * 
		 * @returns Past Time In Seconds
		 */
		long long readTimeSeconds() noexcept;

		/**
		 * @brief Stops And Gives Past Time In MilliSeconds
		 *
		 * @returns Past Time In MilliSeconds
		 */
		long long readTimeMilli() noexcept;

		/**
		 * @brief Stops And Gives Past Time In MicroSeconds
		 *
		 * @returns Past Time In MicroSeconds
		 */
		long long readTimeMicro() noexcept;

		/**
		 * @brief Stops And Gives Past Time In NanoSeconds
		 *
		 * @returns Past Time In NanoSeconds
		 */
		long long readTimeNano() noexcept;

		/**
		 * @brief Gives Past Time From Last Stop In Seconds
		 * 
		 * @returns Past Time In Seconds
		 */
		long long getTimeSeconds() const noexcept;

		/**
		 * @brief Gives Past Time From Last Stop In MilliSeconds
		 *
		 * @returns Past Time In MilliSeconds
		 */
		long long getTimeMilli() const noexcept;

		/**
		 * @brief Gives Past Time From Last Stop In MicroSeconds
		 *
		 * @returns Past Time In MicroSeconds
		 */
		long long getTimeMicro() const noexcept;

		/**
		 * @brief Gives Past Time In NanoSeconds
		 *
		 * @returns Past Time In NanoSeconds
		 */
		long long getTimeNano() const noexcept;

	private:
		std::chrono::time_point<std::chrono::steady_clock> 
			m_StartTime, m_EndTime;
	};
}