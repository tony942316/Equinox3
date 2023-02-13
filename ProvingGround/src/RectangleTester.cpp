#include "RectangleTester.hpp"

#include <iostream>

#include "EquinoxSTD.hpp"
#include "UnitTest.hpp"

RectangleTester::RectangleTester()
{
}

bool RectangleTester::testAll()
{
	if (testConstruction() &&
		testOperators() &&
		testFunctions())
	{
		std::cout << "Rectangle Tests Passed" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Rectangle Tests Failed!" << std::endl;
		return false;
	}
}

bool RectangleTester::testConstruction()
{
	eqx::Rectangle<int> defaultConInt;
	if (defaultConInt.x != 0 || defaultConInt.y != 0 || 
		defaultConInt.w != 0 || defaultConInt.h != 0)
	{
		std::cout << "\nTestRectangleConstruction IntDefault Fail!" << std::endl;
		return false;
	}

	eqx::Rectangle<double> defaultConDouble;
	if (defaultConDouble.x != 0.0 || defaultConDouble.y != 0.0 ||
		defaultConDouble.w != 0.0 || defaultConDouble.h != 0.0)
	{
		std::cout << "\nTestRectangleConstruction DoubleDefault Fail!" << std::endl;
		return false;
	}

	int paramIntX, paramIntY, paramIntW, paramIntH;
	double paramDoubleX, paramDoubleY, paramDoubleW, paramDoubleH;
	std::stringstream ss;
	eqx::Log::setOutputStream(ss);
	eqx::Log::setOutputFile("TestOutputFile.txt");
	eqx::Log::clear();
	for (int i = 0; i < 100'000; i++)
	{
		paramIntX = eqx::Random::randInt(-100'000, 100'000);
		paramIntY = eqx::Random::randInt(-100'000, 100'000);
		paramIntW = eqx::Random::randInt(-100'000, 100'000);
		paramIntH = eqx::Random::randInt(-100'000, 100'000);
		eqx::Rectangle<int> paramConInt(paramIntX, paramIntY, paramIntW, paramIntH);
		if (paramConInt.x != paramIntX || paramConInt.y != paramIntY ||
			paramConInt.w != paramIntW || paramConInt.h != paramIntH)
		{
			std::cout << "\nTestRectangleConstruction IntParam Fail!" << std::endl;
			return false;
		}

		paramDoubleX = eqx::Random::randDouble(-100'000.0, 100'000.0);
		paramDoubleY = eqx::Random::randDouble(-100'000.0, 100'000.0);
		paramDoubleW = eqx::Random::randDouble(-100'000.0, 100'000.0);
		paramDoubleH = eqx::Random::randDouble(-100'000.0, 100'000.0);
		eqx::Rectangle<double> paramConDouble(paramDoubleX, paramDoubleY, paramDoubleW, paramDoubleH);
		if (paramConDouble.x != paramDoubleX || paramConDouble.y != paramDoubleY ||
			paramConDouble.w != paramDoubleW || paramConDouble.h != paramDoubleH)
		{
			std::cout << "\nTestRectangleConstruction DoubleParam Fail!" << std::endl;
			return false;
		}

		eqx::Rectangle<int> copyConInt(paramConDouble);
		if (copyConInt.x != static_cast<int>(paramConDouble.x) || copyConInt.y != static_cast<int>(paramConDouble.y) ||
			copyConInt.w != static_cast<int>(paramConDouble.w) || copyConInt.h != static_cast<int>(paramConDouble.h) ||
			eqx::Log::getLastLogMessage() != "Lossy Conversion" || eqx::Log::getLastLogType() != eqx::Log::Type::runtimeWarning)
		{
			std::cout << "\nTestRectangleConstruction IntCopyDouble Fail!" << std::endl;
			return false;
		}
		eqx::Log::clear();

		eqx::Rectangle<double> copyConDouble(paramConInt);
		if (copyConDouble.x != static_cast<double>(paramConInt.x) || copyConDouble.y != static_cast<double>(paramConInt.y) ||
			copyConDouble.w != static_cast<double>(paramConInt.w) || copyConDouble.h != static_cast<double>(paramConInt.h))
		{
			std::cout << "\nTestRectangleConstruction DoubleCopy Fail!" << std::endl;
			return false;
		}
	}
	eqx::Log::setOutputStream(std::cout);
	eqx::Log::setOutputFile("Log.txt");
	eqx::Log::clear();

	return true;
}

bool RectangleTester::testOperators()
{
	int intParamX, intParamY, intParamW, intParamH;
	eqx::Rectangle<int> intRect;
	double doubleParamX, doubleParamY, doubleParamW, doubleParamH;
	eqx::Rectangle<double> doubleRect;
	std::stringstream ss;
	eqx::Log::setOutputStream(ss);
	eqx::Log::setOutputFile("TestOutputFile.txt");
	eqx::Log::clear();
	for (int i = 0; i < 100'000; i++)
	{
		intParamX = eqx::Random::randInt(-100'000, 100'000);
		intParamY = eqx::Random::randInt(-100'000, 100'000);
		intParamW = eqx::Random::randInt(-100'000, 100'000);
		intParamH = eqx::Random::randInt(-100'000, 100'000);
		intRect = eqx::Rectangle<int>(intParamX, intParamY, intParamW, intParamH);
		if (intRect.x != intParamX || intRect.y != intParamY ||
			intRect.w != intParamW || intRect.h != intParamH)
		{
			std::cout << "\nTestRectangleOperator Int= Fail!" << std::endl;
			return false;
		}

		doubleParamX = eqx::Random::randDouble(-100'000.0, 100'000.0);
		doubleParamY = eqx::Random::randDouble(-100'000.0, 100'000.0);
		doubleParamW = eqx::Random::randDouble(-100'000.0, 100'000.0);
		doubleParamH = eqx::Random::randDouble(-100'000.0, 100'000.0);
		doubleRect = eqx::Rectangle<double>(doubleParamX, doubleParamY, doubleParamW, doubleParamH);
		if (doubleRect.x != doubleParamX || doubleRect.y != doubleParamY ||
			doubleRect.w != doubleParamW || doubleRect.h != doubleParamH)
		{
			std::cout << "\nTestRectangleOperator Double= Fail!" << std::endl;
			return false;
		}

		intRect = doubleRect;
		if (intRect.x != static_cast<int>(doubleRect.x) || intRect.y != static_cast<int>(doubleRect.y) ||
			intRect.w != static_cast<int>(doubleRect.w) || intRect.h != static_cast<int>(doubleRect.h) ||
			eqx::Log::getLastLogMessage() != "Lossy Conversion" || eqx::Log::getLastLogType() != eqx::Log::Type::runtimeWarning)
		{
			std::cout << "\nTestRectangleOperator Int==Double Fail" << std::endl;
			return false;
		}
		eqx::Log::clear();
	}

	eqx::Log::setOutputStream(std::cout);
	eqx::Log::setOutputFile("Log.txt");
	eqx::Log::clear();

	return true;
}

bool RectangleTester::testFunctions()
{
	eqx::Rectangle<int> intRect;
	eqx::Rectangle<double> doubleRect;
	std::string ans = "";
	for (int i = 0; i < 100'000; i++)
	{
		intRect = { eqx::Random::randInt(-100'000, 100'000), eqx::Random::randInt(-100'000, 100'000),
					eqx::Random::randInt(-100'000, 100'000), eqx::Random::randInt(-100'000, 100'000) };
		ans = std::string("(") + std::to_string(intRect.x) + std::string(", ") + 
			  std::to_string(intRect.y) + std::string(", ") + std::to_string(intRect.w) + std::string(", ") +
			  std::to_string(intRect.h) + std::string(")");
		if (intRect.toString() != ans)
		{
			std::cout << "\nTestPointFunction toStringInt Fail" << std::endl;
			return false;
		}

		doubleRect = { eqx::Random::randDouble(-100'000.0, 100'000.0), eqx::Random::randDouble(-100'000.0, 100'000.0),
						eqx::Random::randDouble(-100'000.0, 100'000.0), eqx::Random::randDouble(-100'000.0, 100'000.0) };
		ans = std::string("(") + std::to_string(doubleRect.x) + std::string(", ") +
			  std::to_string(doubleRect.y) + std::string(", ") + std::to_string(doubleRect.w) + std::string(", ") +
			  std::to_string(doubleRect.h) + std::string(")");
		if (doubleRect.toString() != ans)
		{
			std::cout << "\nTestPointFunction toStringDouble Fail" << std::endl;
			return false;
		}
	}

	return true;
}