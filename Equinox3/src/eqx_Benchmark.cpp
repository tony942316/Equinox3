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