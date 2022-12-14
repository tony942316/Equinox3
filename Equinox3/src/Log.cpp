#include "Log.h"

namespace eqx
{
	void Log::log(Level level, const std::string& msg, Type type, const std::source_location& loc)
	{
		std::string
			preface = "",
			fileName = loc.file_name(),
			functionName = loc.function_name(),
			lineNumber = std::to_string(loc.line());
		fileName.erase(fileName.begin(), fileName.begin() + fileName.rfind('\\'));
		preface += ".." + fileName + "(" + functionName + "," + lineNumber + ") ";
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
		}
		if (level >= getInstance().m_LogLevel)
		{
			getInstance().m_OutputStream << preface + msg << std::endl;
		}
		getInstance().m_LastErrorType = type;
		getInstance().m_LogFile << preface + msg << std::endl;
		getInstance().m_LastMessage = msg;
	}

	void Log::setLevel(Level level)
	{
		getInstance().m_LogLevel = level;
	}

	void Log::setOutputStream(const std::ostream& stream)
	{
		getInstance().m_OutputStream.rdbuf(stream.rdbuf());
	}

	void Log::setOutputFile(const std::string& file)
	{
		getInstance().m_LogFile.close();
		getInstance().m_LogFile.open(file, std::ios::out | std::ios::trunc);
	}

	void Log::clear()
	{
		getInstance().m_LastErrorType = Log::Type::none;
		getInstance().m_LastMessage = "";
	}

	Log::Type Log::getLastLogType()
	{
		return getInstance().m_LastErrorType;
	}

	const std::string& Log::getLastLogMessage()
	{
		return getInstance().m_LastMessage;
	}

	Log::Log()
		:
		m_LogFile("Log.txt", std::ios::out | std::ios::trunc),
		m_OutputStream(std::cout.rdbuf()),
		m_LogLevel(Level::none),
		m_LastErrorType(Type::none),
		m_LastMessage("")
	{
	}

	Log& Log::getInstance()
	{
		static Log log;
		return log;
	}
}
