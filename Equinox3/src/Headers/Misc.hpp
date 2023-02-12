#pragma once

#include <string>
#include <iostream>

#ifdef NDEBUG
#define eqx_dynamic_assert(expr, message) 0;
#else

void eqx_dynamic_assert(bool expr, const std::string& msg = "");

#endif