#include "StopWatch.hpp"

namespace eqx
{
	StopWatch::StopWatch() noexcept
	{
		start();
	}

	void StopWatch::start() noexcept
	{
		m_StartTime = std::chrono::steady_clock::now();
		m_EndTime = m_StartTime;
	}

	void StopWatch::stop() noexcept
	{
		m_EndTime = std::chrono::steady_clock::now();
	}
}