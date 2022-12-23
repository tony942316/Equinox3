#pragma once

#include <sstream>
#include <string>

class LogTester
{
public:
	LogTester();
	~LogTester();

	bool testAll();
	bool testLog();
	bool testSetLevel();
	bool testSetOutputStream();
	bool testSetOutputFile();
	bool testClear();
	bool testGetLastLogType();
	bool testGetLastLogMessage();

private:
	std::string m_FileName;
	std::stringstream m_SS;

};