#include "StopWatch.h"

namespace eqx
{
	eqx::StopWatch::StopWatch()
	{
		start();
	}

	void eqx::StopWatch::start()
	{
		m_StartTime = std::chrono::high_resolution_clock::now();
		m_EndTime = m_StartTime;
	}

	void eqx::StopWatch::stop()
	{
		m_EndTime = std::chrono::high_resolution_clock::now();
	}

	long long eqx::StopWatch::readTimeSeconds()
	{
		stop();
		return getTimeSeconds();
	}

	long long eqx::StopWatch::readTimeMilli()
	{
		stop();
		return getTimeMilli();
	}

	long long eqx::StopWatch::readTimeMicro()
	{
		stop();
		return getTimeMicro();
	}

	long long StopWatch::readTimeNano()
	{
		stop();
		return getTimeNano();
	}

	long long eqx::StopWatch::getTimeSeconds() const
	{
		return std::chrono::duration_cast<std::chrono::seconds>(m_EndTime - m_StartTime).count();
	}

	long long eqx::StopWatch::getTimeMilli() const
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(m_EndTime - m_StartTime).count();
	}

	long long eqx::StopWatch::getTimeMicro() const
	{
		return std::chrono::duration_cast<std::chrono::microseconds>(m_EndTime - m_StartTime).count();
	}
	long long StopWatch::getTimeNano() const
	{
		return std::chrono::duration_cast<std::chrono::nanoseconds>(m_EndTime - m_StartTime).count();
	}
}