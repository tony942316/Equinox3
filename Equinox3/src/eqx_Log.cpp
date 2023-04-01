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

#include "eqx_Log.hpp"

namespace eqx
{
	std::ofstream Log::s_LogFile("Log.txt", std::ios::out | std::ios::trunc);
	std::ostream* Log::s_OutputStream = &std::clog;
	Log::Level Log::s_LogLevel = Level::none;
	Log::Type Log::s_LastErrorType = Type::none;
	std::string Log::s_LastMessage("");

	void Log::log(Level level, std::string_view msg, 
		Type type,
		const std::source_location& loc)
	{
		auto logString = getFormattedString(loc, level, msg);
		if (level >= s_LogLevel)
		{
			if (s_OutputStream != nullptr)
			{
				*s_OutputStream << logString << std::endl;
			}
			s_LogFile << logString << std::endl;
			s_LastErrorType = type;
			s_LastMessage = msg;
		}
	}

	void Log::setLevel(Level level) noexcept
	{
		s_LogLevel = level;
	}

	void Log::setOutputStream(std::ostream& stream) noexcept
	{
		s_OutputStream = &stream;
	}

	void Log::setOutputFile(std::string_view file)
	{
		if (s_LogFile.is_open())
		{
			s_LogFile.close();
		}
		s_LogFile.open(std::string(file), std::ios::out | std::ios::trunc);
	}

	void Log::clear() noexcept
	{
		s_LastErrorType = Log::Type::none;
		s_LastMessage = "";
	}

	Log::Level Log::getCurrentLogLevel() noexcept
	{
		return s_LogLevel;
	}

	Log::Type Log::getLastLogType() noexcept
	{
		return s_LastErrorType;
	}

	std::string_view Log::getLastLogMessage() noexcept
	{
		return s_LastMessage;
	}

	std::string Log::getFormattedString(
		const std::source_location& loc, eqx::Log::Level level,
		std::string_view msg)
	{
		auto result = std::string("");
		result.reserve(100);

		auto fileName = std::string_view(loc.file_name());
		auto functionName = std::string(loc.function_name());
		auto lineNumber = std::to_string(loc.line());

		result += "..";
		result += fileName.substr(fileName.rfind('\\'));
		result += "(";
		result += functionName;
		result += ",";
		result += lineNumber;
		result += ") ";
		switch (level)
		{
		case Level::info:
			result += "[INFO]: ";
			break;

		case Level::warning:
			result += "[WARNING]: ";
			break;

		case Level::error:
			result += "[ERROR]: ";
			break;

		default:
			result += "[UNKNOWN]: ";
			break;
		}
		result += msg;

		return result;
	}
}