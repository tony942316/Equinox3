#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <source_location>

#include "SuperEnum.hpp"

namespace eqx
{
	/**
	 * @brief Logs Errors And Warnings To A Stream And A File
	 */
	class Log
	{
	public:
		/**
		 * Pure Static Class Is Not Ment To Be Constructed Or Copied
		 */
		Log() = delete;
		Log(const Log&) = delete;
		Log(Log&&) = delete;
		Log& operator= (const Log&) = delete;
		Log& operator= (Log&&) = delete;
		~Log() = delete;

		/**
		 * @brief Severity Of A Log
		 */
		EQX_SUPER_ENUM_5(Level, 
			all, 
			info, 
			warning, 
			error, 
			none
		)

		/**
		 * @brief Type Of A Log
		 */
		EQX_SUPER_ENUM_6(Type,
			none,
			info,
			runtimeWarning,
			runtimeError,
			overflowError,
			unreachableCodeError
		)

		/**
		 * @brief Log A Message To The Active Stream And File
		 * 
		 * @param level Level Of The Log
		 * @param msg Message Of The Log
		 * @param type Type Of The Log
		 * @param loc Current Location In Source
		 */
		static void log(Level level, const std::string& msg, 
			Type type = Type::none, 
			const std::source_location& loc = std::source_location::current());

		/**
		 * @brief Set Level Of Logs To Be Output i.e.
		 * warning Will Output warnings And errors But Not info
		 * 
		 * @param level Cutoff i.e. all -> info -> warning -> error -> none
		 */
		static void setLevel(Level level) noexcept;

		/**
		 * @brief Set The Stream Logs Are Written To
		 * 
		 * @param stream The New Output Stream
		*/
		static void setOutputStream(std::ostream& stream) noexcept;

		/**
		 * @brief Set The File Logs Are Written To
		 * 
		 * @param file The New File
		 */
		static void setOutputFile(const std::string& file);

		/**
		 * @brief Clears The Last Error Message And Type
		 */
		static void clear() noexcept;

		/**
		 * @brief Get Type Of Last Log
		 * 
		 * @returns Last Log Type
		 */
		static Type getLastLogType() noexcept;

		/**
		 * @brief Get Message Of Last Log
		 * 
		 * @returns Last Message String
		 */
		static const std::string& getLastLogMessage() noexcept;

		/**
		 * @brief Build String With eqx::Log Formatting i.e.
		 * "{SourceLocation}[{Log::Level}]: {Message}"
		 * 
		 * @param loc Location Of The Log
		 * @param level Level Of The Log
		 * @param msg Message Of The Log
		 * 
		 * @returns Formatted String
		 */
		static std::string getFormattedString(
			const std::source_location& loc, Level level,
			const std::string& msg = "");

		/**
		 * @brief Get Log Levels That Log Properly i.e.
		 * eqx::Log::all Is Not Meant To Be Logged
		 * 
		 * @returns std::vector Of Loggable Levels
		 */
		static const std::vector<Level>& getLoggableLevels();

	private:
		static std::ofstream s_LogFile;
		static std::ostream* s_OutputStream;
		static Level s_LogLevel;
		static Type s_LastErrorType;
		static std::string s_LastMessage;
	};
}