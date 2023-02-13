#include "StopWatch.hpp"

namespace eqx
{
	eqx::StopWatch::StopWatch() noexcept
	{
		start();
	}

	void eqx::StopWatch::start() noexcept
	{
		m_StartTime = std::chrono::steady_clock::now();
		m_EndTime = m_StartTime;
	}

	void eqx::StopWatch::stop() noexcept
	{
		m_EndTime = std::chrono::steady_clock::now();
	}

	long long eqx::StopWatch::readTimeSeconds() noexcept
	{
		stop();
		return getTimeSeconds();
	}

	long long eqx::StopWatch::readTimeMilli() noexcept
	{
		stop();
		return getTimeMilli();
	}

	long long eqx::StopWatch::readTimeMicro() noexcept
	{
		stop();
		return getTimeMicro();
	}

	long long StopWatch::readTimeNano() noexcept
	{
		stop();
		return getTimeNano();
	}

	long long eqx::StopWatch::getTimeSeconds() const noexcept
	{
		return std::chrono::duration_cast<std::chrono::seconds>(
			m_EndTime - m_StartTime).count();
	}

	long long eqx::StopWatch::getTimeMilli() const noexcept
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(
			m_EndTime - m_StartTime).count();
	}

	long long eqx::StopWatch::getTimeMicro() const noexcept
	{
		return std::chrono::duration_cast<std::chrono::microseconds>(
			m_EndTime - m_StartTime).count();
	}

	long long StopWatch::getTimeNano() const noexcept
	{
		return std::chrono::duration_cast<std::chrono::nanoseconds>(
			m_EndTime - m_StartTime).count();
	}
}