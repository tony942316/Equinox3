#include "Misc.hpp"

#include <iostream>

#ifndef NDEBUG
void eqx_debugOnly_runtimeAssert(bool expr, std::string_view msg) noexcept
{
	if (!expr)
	{
		std::cerr << msg << std::endl;
		std::abort();
	}
}
#endif

namespace eqx
{
	void runtimeAssert(bool expr, std::string_view msg) noexcept
	{
		if (!expr)
		{
			std::cerr << msg << std::endl;
			std::abort();
		}
	}

	std::string toString(const char* cstring)
	{
		return std::string(cstring);
	}
}