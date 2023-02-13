#include "PointTester.hpp"

#include <iostream>

#include "EquinoxSTD.hpp"
#include "UnitTest.hpp"

PointTester::PointTester()
{
}

bool PointTester::testAll()
{
	if (testConstruction() &&
		testOperators() &&
		testFunctions())
	{
		std::cout << "Point Tests Passed" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Point Tests Failed!" << std::endl;
		return false;
	}
}

bool PointTester::testConstruction()
{
	eqx::Point<int> defaultConInt;
	if (defaultConInt.x != 0 || defaultConInt.y != 0)
	{
		std::cout << "\nTestPointConstruction IntDefault Fail!" << std::endl;
		return false;
	}

	eqx::Point<double> defaultConDouble;
	if (defaultConDouble.x != 0.0 || defaultConDouble.y != 0.0)
	{
		std::cout << "\nTestPointConstruction DoubleDefault Fail!" << std::endl;
		return false;
	}

	int paramInt1, paramInt2;
	double paramDouble1, paramDouble2;
	std::stringstream ss;
	eqx::Log::setOutputStream(ss);
	eqx::Log::setOutputFile("TestOutputFile.txt");
	eqx::Log::clear();
	for (int i = 0; i < 100'000; i++)
	{
		paramInt1 = eqx::Random::randInt(-100'000, 100'000);
		paramInt2 = eqx::Random::randInt(-100'000, 100'000);
		eqx::Point<int> paramConInt(paramInt1, paramInt2);
		if (paramConInt.x != paramInt1 || paramConInt.y != paramInt2)
		{
			std::cout << "\nTestPointConstruction IntParam Fail!" << std::endl;
			return false;
		}

		paramDouble1 = eqx::Random::randDouble(-100'000.0, 100'000.0);
		paramDouble2 = eqx::Random::randDouble(-100'000.0, 100'000.0);
		eqx::Point<double> paramConDouble(paramDouble1, paramDouble2);
		if (paramConDouble.x != paramDouble1 || paramConDouble.y != paramDouble2)
		{
			std::cout << "\nTestPointConstruction DoubleParam Fail!" << std::endl;
			return false;
		}

		eqx::Point<int> copyConInt(paramConDouble);
		if (copyConInt.x != static_cast<int>(paramConDouble.x) || copyConInt.y != static_cast<int>(paramConDouble.y) ||
			eqx::Log::getLastLogMessage() != "Lossy Conversion" || eqx::Log::getLastLogType() != eqx::Log::Type::runtimeWarning)
		{
			std::cout << "\nTestPointConstruction IntCopyDouble Fail!" << std::endl;
			return false;
		}
		eqx::Log::clear();

		eqx::Point<double> copyConDouble(paramConInt);
		if (copyConDouble.x != static_cast<double>(paramConInt.x) || copyConDouble.y != static_cast<double>(paramConInt.y))
		{
			std::cout << "\nTestPointConstruction DoubleCopy Fail!" << std::endl;
			return false;
		}
	}
	eqx::Log::setOutputStream(std::cout);
	eqx::Log::setOutputFile("Log.txt");
	eqx::Log::clear();

	return true;
}

bool PointTester::testOperators()
{
	int intParam1, intParam2;
	eqx::Point<int> intPoint, intPlusPoint;
	double doubleParam1, doubleParam2;
	eqx::Point<double> doublePoint, doublePlusPoint;
	std::stringstream ss;
	eqx::Log::setOutputStream(ss);
	eqx::Log::setOutputFile("TestOutputFile.txt");
	eqx::Log::clear();
	for (int i = 0; i < 100'000; i++)
	{
		intParam1 = eqx::Random::randInt(-100'000, 100'000);
		intParam2 = eqx::Random::randInt(-100'000, 100'000);
		intPoint = eqx::Point<int>(intParam1, intParam2);
		if (intPoint.x != intParam1 || intPoint.y != intParam2)
		{
			std::cout << "\nTestPointOperator Int= Fail!" << std::endl;
			return false;
		}

		doubleParam1 = eqx::Random::randDouble(-100'000.0, 100'000.0);
		doubleParam2 = eqx::Random::randDouble(-100'000.0, 100'000.0);
		doublePoint = eqx::Point<double>(doubleParam1, doubleParam2);
		if (doublePoint.x != doubleParam1 || doublePoint.y != doubleParam2)
		{
			std::cout << "\nTestPointOperator Double= Fail!" << std::endl;
			return false;
		}

		intPoint = doublePoint;
		if (intPoint.x != static_cast<int>(doublePoint.x) || intPoint.y != static_cast<int>(doublePoint.y) ||
			eqx::Log::getLastLogMessage() != "Lossy Conversion" || eqx::Log::getLastLogType() != eqx::Log::Type::runtimeWarning)
		{
			std::cout << "\nTestPointOperator Int==Double Fail" << std::endl;
			return false;
		}
		eqx::Log::clear();

		intPoint = eqx::Point<int>(intParam1, intParam2);
		doublePoint = eqx::Point<double>(doubleParam1, doubleParam2);

		intPlusPoint = intPoint + intPoint;
		if (intPlusPoint.x != (2 * intPoint.x) || intPlusPoint.y != (2 * intPoint.y))
		{
			std::cout << "\nTestPointOperator Int+ Fail" << std::endl;
			return false;
		}

		doublePlusPoint = doublePoint + doublePoint;
		if (doublePlusPoint.x != (2.0 * doublePoint.x) || doublePlusPoint.y != (2.0 * doublePoint.y))
		{
			std::cout << "\nTestPointOperator Double+ Fail" << std::endl;
			return false;
		}

		intPlusPoint = intPoint - intPoint;
		if (intPlusPoint.x != 0 || intPlusPoint.y != 0)
		{
			std::cout << "\nTestPointOperator Int- Fail" << std::endl;
			return false;
		}

		doublePlusPoint = doublePoint - doublePoint;
		if (doublePlusPoint.x != 0.0 || doublePlusPoint.y != 0.0)
		{
			std::cout << "\nTestPointOperator Double- Fail" << std::endl;
			return false;
		}

		intPlusPoint += intPoint;
		if (intPlusPoint.x != intPoint.x || intPlusPoint.y != intPoint.y)
		{
			std::cout << "\nTestPointOperator Int+= Fail" << std::endl;
			return false;
		}

		doublePlusPoint += doublePoint;
		if (doublePlusPoint.x != doublePoint.x || doublePlusPoint.y != doublePoint.y)
		{
			std::cout << "\nTestPointOperator Double+= Fail" << std::endl;
			return false;
		}

		intPlusPoint -= intPoint;
		if (intPlusPoint.x != 0 || intPlusPoint.y != 0)
		{
			std::cout << "\nTestPointOperator Int-= Fail" << std::endl;
			return false;
		}

		doublePlusPoint -= doublePoint;
		if (doublePlusPoint.x != 0.0 || doublePlusPoint.y != 0.0)
		{
			std::cout << "\nTestPointOperator Double-= Fail" << std::endl;
			return false;
		}

		intPlusPoint = intPoint + intPoint;
		if (intPlusPoint == intPoint)
		{
			std::cout << "\nTestPointOperator Int== Fail" << std::endl;
			return false;
		}

		doublePlusPoint = doublePoint + doublePoint;
		if (doublePlusPoint == doublePoint)
		{
			std::cout << "\nTestPointOperator Double== Fail" << std::endl;
		}

		intPlusPoint = intPoint;
		if (intPlusPoint != intPoint)
		{
			std::cout << "\nTestPointOperator Int!= Fail" << std::endl;
			return false;
		}

		doublePlusPoint = doublePoint;
		if (doublePlusPoint != doublePoint)
		{
			std::cout << "\nTestPointOperator Double!= Fail" << std::endl;
			return false;
		}
	}

	eqx::Log::setOutputStream(std::cout);
	eqx::Log::setOutputFile("Log.txt");
	eqx::Log::clear();

	return true;
}

bool PointTester::testFunctions()
{
	eqx::Point<int> intPoint;
	eqx::Point<double> doublePoint;
	std::string ans = "";
	for (int i = 0; i < 100'000; i++)
	{
		intPoint = { eqx::Random::randInt(-100'000, 100'000), eqx::Random::randInt(-100'000, 100'000) };
		ans = std::string("(") + std::to_string(intPoint.x) + std::string(", ") + std::to_string(intPoint.y) + std::string(")");
		if (intPoint.toString() != ans)
		{
			std::cout << "\nTestPointFunction toStringInt Fail" << std::endl;
			return false;
		}

		doublePoint = { eqx::Random::randDouble(-100'000.0, 100'000.0), eqx::Random::randDouble(-100'000.0, 100'000.0) };
		ans = std::string("(") + std::to_string(doublePoint.x) + std::string(", ") + std::to_string(doublePoint.y) + std::string(")");
		if (doublePoint.toString() != ans)
		{
			std::cout << "\nTestPointFunction toStringDouble Fail" << std::endl;
			return false;
		}
	}

	std::vector<std::tuple<eqx::Point<int>, eqx::Point<int>, int>> intTests;
	intTests.emplace_back(eqx::Point<int>(0, 0), eqx::Point<int>(0, 0), 0);
	intTests.emplace_back(eqx::Point<int>(0, 0), eqx::Point<int>(1, 1), 1);
	intTests.emplace_back(eqx::Point<int>(0, 0), eqx::Point<int>(-1, -1), 1);
	intTests.emplace_back(eqx::Point<int>(1, 1), eqx::Point<int>(1, 1), 0);
	intTests.emplace_back(eqx::Point<int>(0, 0), eqx::Point<int>(0, 10), 10);
	intTests.emplace_back(eqx::Point<int>(10, 10), eqx::Point<int>(-10, -10), 28);

	for (const std::tuple<eqx::Point<int>, eqx::Point<int>, int>& test : intTests)
	{
		if (eqx::distance(std::get<0>(test), std::get<1>(test)) != std::get<2>(test) ||
			eqx::distance(std::get<1>(test), std::get<0>(test)) != std::get<2>(test))
		{
			std::cout << "\nTestPointFunction distanceInt Fail" << std::endl;
			return false;
		}
	}

	std::vector<std::tuple<eqx::Point<double>, eqx::Point<double>, double>> doubleTests;
	doubleTests.emplace_back(eqx::Point<double>(0.0, 0.0), eqx::Point<double>(0.0, 0.0), 0.0);
	doubleTests.emplace_back(eqx::Point<double>(0.0, 0.0), eqx::Point<double>(0.0, 1.0), 1.0);
	doubleTests.emplace_back(eqx::Point<double>(0.0, 0.0), eqx::Point<double>(1.0, 0.0), 1.0);
	doubleTests.emplace_back(eqx::Point<double>(0.0, 0.0), eqx::Point<double>(1.0, 1.0), std::sqrt(2.0));

	for (const std::tuple<eqx::Point<double>, eqx::Point<double>, double>& test : doubleTests)
	{
		if (eqx::distance(std::get<0>(test), std::get<1>(test)) != std::get<2>(test) ||
			eqx::distance(std::get<1>(test), std::get<0>(test)) != std::get<2>(test))
		{
			std::cout << "\nTestPointFunction distanceDouble Fail" << std::endl;
			return false;
		}
	}

	return true;
}