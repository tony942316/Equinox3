#include "eqx_Benchmark.hpp"

namespace eqx
{
	Benchmark::Benchmark(std::function<void(void)> function)
		:
		m_Function(function),
		m_Bench(std::chrono::nanoseconds())
	{
	}

	void Benchmark::bench() noexcept(noexcept(m_Function()))
	{
		StopWatch timer;
		timer.start();
		m_Function();
		timer.stop();
		m_Bench = timer.getDuration<std::chrono::nanoseconds>();
	}
	
	void Benchmark::avgBench(int runs) noexcept(noexcept(m_Function()))
	{
		StopWatch timer;
		timer.start();
		for (int i = 0; i < runs; i++)
		{
			bench();
		}
		timer.stop();
		m_Bench = static_cast<std::chrono::nanoseconds>(
			timer.getTime<std::chrono::nanoseconds>() / runs);
	}
}