#pragma once

#include <functional>
#include <source_location>
#include <string>
#include <iostream>
#include <type_traits>

template <typename T, typename U>
bool TEST(T Produced, U Expected,
		  std::function<bool(T, U)> func = [](T a, U b) { return a == b ? true : false; },
		  const std::source_location& loc = std::source_location::current())
{
	if (!func(Produced, Expected))
	{
		std::string
			fileName = loc.file_name(),
			functionName = loc.function_name();
		fileName.erase(fileName.begin(), fileName.begin() + fileName.rfind('\\') + 1);
		fileName.erase(fileName.begin() + fileName.rfind('.'), fileName.end());
		std::cout << fileName << " -> " << functionName << 
			" Failure!\nExpected: " << Expected << "\n" <<
			"Produced: " << Produced << std::endl;
		return false;
	}
	else
	{
		return true;
	}
}