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

#include "eqx_StopWatch.hpp"

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