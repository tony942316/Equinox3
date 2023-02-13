#include "Benchmark.hpp"

#include <vector>
#include <numeric>

namespace eqx
{
	Benchmark::Benchmark(std::function<void(void)> function)
		:
		m_Function(function)
	{

	}

	void Benchmark::bench()
	{
		m_Timer.start();
		m_Function();
		m_Timer.stop();

		m_Benchmarks[Time::nanoseconds] = m_Timer.getTimeNano();
		m_Benchmarks[Time::microseconds] = m_Timer.getTimeMicro();
		m_Benchmarks[Time::milliseconds] = m_Timer.getTimeMilli();
		m_Benchmarks[Time::seconds] = m_Timer.getTimeSeconds();
	}

	void Benchmark::avgBench(int runs)
	{
		std::unordered_map<Time, std::vector<long long>> totalTimes;
		totalTimes[Time::nanoseconds].reserve(runs);
		totalTimes[Time::microseconds].reserve(runs);
		totalTimes[Time::milliseconds].reserve(runs);
		totalTimes[Time::seconds].reserve(runs);

		for (int i = 0; i < runs; i++)
		{
			bench();
			totalTimes[Time::nanoseconds].emplace_back(m_Benchmarks[Time::nanoseconds]);
			totalTimes[Time::microseconds].emplace_back(m_Benchmarks[Time::microseconds]);
			totalTimes[Time::milliseconds].emplace_back(m_Benchmarks[Time::milliseconds]);
			totalTimes[Time::seconds].emplace_back(m_Benchmarks[Time::seconds]);
		}

		m_Benchmarks[Time::nanoseconds] = std::accumulate(totalTimes[Time::nanoseconds].begin(), totalTimes[Time::nanoseconds].end(), 0ll) / runs;
		m_Benchmarks[Time::microseconds] = std::accumulate(totalTimes[Time::microseconds].begin(), totalTimes[Time::microseconds].end(), 0ll) / runs;
		m_Benchmarks[Time::milliseconds] = std::accumulate(totalTimes[Time::milliseconds].begin(), totalTimes[Time::milliseconds].end(), 0ll) / runs;
		m_Benchmarks[Time::seconds] = std::accumulate(totalTimes[Time::seconds].begin(), totalTimes[Time::seconds].end(), 0ll) / runs;
	}

	std::string Benchmark::toString(Time time) const
	{
		std::string result = "";

		result += std::string("Bench: ") + std::to_string(m_Benchmarks.at(time));

		return result;
	}
}