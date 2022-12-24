#pragma once

#include <functional>
#include <source_location>
#include <string>
#include <iostream>
#include <iomanip>
#include <type_traits>

template <typename T, typename U>
std::function<bool(T, U)> GT()
{
	return [](T x, U y) { return x > y; };
}

template <typename T, typename U>
std::function<bool(T, U)> GTE()
{
	return [](T x, U y) { return x >= y; };
}

template <typename T, typename U>
std::function<bool(T, U)> LT()
{
	return [](T x, U y) { return x < y; };
}

template <typename T, typename U>
std::function<bool(T, U)> LTE()
{
	return [](T x, U y) { return x <= y; };
}

template <typename T, typename U>
bool TEST(T Produced, U Expected,
		  std::function<bool(T, U)> func = [](T a, U b) { return a == b ? true : false; },
		  const std::source_location& loc = std::source_location::current())
{
	if (!func(Produced, Expected))
	{
		std::cout << std::setprecision(20);
		std::cout << std::boolalpha;
		std::string
			fileName = loc.file_name(),
			functionName = loc.function_name();
		fileName.erase(fileName.begin(), fileName.begin() + fileName.rfind('\\') + 1);
		fileName.erase(fileName.begin() + fileName.rfind('.'), fileName.end());
		std::cout << fileName << " -> " << functionName << 
			" Failure!\nExpected: " << Expected << "\n" <<
			"Produced: " << Produced << std::endl;
		std::cout << std::noboolalpha;
		std::cout << std::setprecision(6);
		return false;
	}
	else
	{
		return true;
	}
}