#pragma once

#include <functional>
#include <unordered_map>

#include "StopWatch.h"

namespace eqx
{
	class Benchmark
	{
	public:
		enum class Time
		{
			nanoseconds,
			microseconds,
			milliseconds,
			seconds
		};

		Benchmark(std::function<void(void)> function);

		void bench();
		void avgBench(int runs = 100'000);

		std::string toString(Time time) const;

	private:
		std::function<void(void)> m_Function;
		std::unordered_map<Time, long long> m_Benchmarks;

		StopWatch m_Timer;
	};
}