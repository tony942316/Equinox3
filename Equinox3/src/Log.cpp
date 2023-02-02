#include "Log.h"

namespace eqx
{
	std::ofstream Log::s_LogFile{ "Log.txt", std::ios::out | std::ios::trunc };
	std::ostream Log::s_OutputStream{ std::cout.rdbuf() };
	Log::Level Log::s_LogLevel{ Level::none };
	Log::Type Log::s_LastErrorType{ Type::none };
	std::string Log::s_LastMessage{ "" };

	void Log::log(Level level, const std::string& msg,
		Type type,
		const std::source_location& loc)
	{
		std::string logString{ getFormattedString(loc, level, msg) };
		if (level >= s_LogLevel)
		{
			s_OutputStream << logString << std::endl;
			s_LogFile << logString << std::endl;
			s_LastErrorType = type;
			s_LastMessage = msg;
		}
	}

	void Log::setLevel(Level level)
	{
		s_LogLevel = level;
	}

	void Log::setOutputStream(const std::ostream& stream)
	{
		s_OutputStream.rdbuf(stream.rdbuf());
	}

	void Log::setOutputFile(const std::string& file)
	{
		s_LogFile.close();
		s_LogFile.open(file, std::ios::out | std::ios::trunc);
	}

	void Log::clear()
	{
		s_LastErrorType = Log::Type::none;
		s_LastMessage = "";
	}

	Log::Type Log::getLastLogType()
	{
		return s_LastErrorType;
	}

	const std::string& Log::getLastLogMessage()
	{
		return s_LastMessage;
	}

	std::string Log::getFormattedString(
		const std::source_location& loc, eqx::Log::Level level,
		const std::string& msg)
	{
		std::string
			preface = "",
			fileName = loc.file_name(),
			functionName = loc.function_name(),
			lineNumber = std::to_string(loc.line());

		fileName.erase(fileName.begin(),
			fileName.begin() + fileName.rfind('\\'));
		preface += ".." + fileName + "(" +
			functionName + "," + lineNumber + ") ";
		switch (level)
		{
		case Level::info:
			preface += "[INFO]: ";
			break;

		case Level::warning:
			preface += "[WARNING]: ";
			break;

		case Level::error:
			preface += "[ERROR]: ";
			break;

		default:
			preface += "[UNKNOWN]: ";
			break;
		}
		preface += msg;

		return preface;
	}

	const std::vector<Log::Level>& Log::getLoggableLevels()
	{
		static std::vector<Level> loggable{
			Level::info,
			Level::warning,
			Level::error
		};
		return loggable;
	}
}