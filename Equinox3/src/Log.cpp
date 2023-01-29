#include "Log.h"

namespace eqx
{
	std::ofstream Log::m_LogFile{ "Log.txt", std::ios::out | std::ios::trunc };
	std::ostream Log::m_OutputStream{ std::cout.rdbuf() };
	Log::Level Log::m_LogLevel{ Level::none };
	Log::Type Log::m_LastErrorType{ Type::none };
	std::string Log::m_LastMessage{ "" };

	void Log::log(Level level, const std::string& msg,
		Type type,
		const std::source_location& loc)
	{
		std::string logString{ getFormattedString(loc, level, msg) };
		if (level >= m_LogLevel)
		{
			m_OutputStream << logString << std::endl;
			m_LogFile << logString << std::endl;
			m_LastErrorType = type;
			m_LastMessage = msg;
		}
	}

	void Log::setLevel(Level level)
	{
		m_LogLevel = level;
	}

	void Log::setOutputStream(const std::ostream& stream)
	{
		m_OutputStream.rdbuf(stream.rdbuf());
	}

	void Log::setOutputFile(const std::string& file)
	{
		m_LogFile.close();
		m_LogFile.open(file, std::ios::out | std::ios::trunc);
	}

	void Log::clear()
	{
		m_LastErrorType = Log::Type::none;
		m_LastMessage = "";
	}

	Log::Type Log::getLastLogType()
	{
		return m_LastErrorType;
	}

	const std::string& Log::getLastLogMessage()
	{
		return m_LastMessage;
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