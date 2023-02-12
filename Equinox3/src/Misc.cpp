#include "Misc.hpp"

#ifndef NDEBUG
void eqx_dynamic_assert(bool expr, const std::string& msg)
{
	if (!expr)
	{
		std::cerr << msg << std::endl;
		std::abort();
	}
}
#endif