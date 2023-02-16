#include "Misc.hpp"

#include <iostream>

#ifndef NDEBUG
void eqx_dynamic_assert(bool expr, const std::string& msg) noexcept
{
	if (!expr)
	{
		std::cerr << msg << std::endl;
		std::abort();
	}
}
#endif