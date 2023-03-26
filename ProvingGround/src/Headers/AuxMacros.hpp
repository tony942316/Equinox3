#pragma once

#include "HolyMacros.hpp"

#define CONCEPT_CTG(c) \
template <typename... Types> \
consteval bool c##CTG(bool es) \
{ \
	if (es) \
	{ \
		return (... && eqx::c<Types>); \
	} \
	else \
	{ \
		return (... && !eqx::c<Types>); \
	} \
}

#define PARENS ()
#define COMMA ,

#define EXPAND(...) EXPAND5(EXPAND5(EXPAND5(EXPAND5(__VA_ARGS__))))
#define EXPAND5(...) EXPAND4(EXPAND4(EXPAND4(EXPAND4(__VA_ARGS__))))
#define EXPAND4(...) EXPAND3(EXPAND3(EXPAND3(EXPAND3(__VA_ARGS__))))
#define EXPAND3(...) EXPAND2(EXPAND2(EXPAND2(EXPAND2(__VA_ARGS__))))
#define EXPAND2(...) EXPAND1(EXPAND1(EXPAND1(EXPAND1(__VA_ARGS__))))
#define EXPAND1(...) __VA_ARGS__

#define FOR_EACH(macro, ...) \
	__VA_OPT__(EXPAND(FOR_EACH_HELPER(macro, __VA_ARGS__)))
#define FOR_EACH_HELPER(macro, a1, ...) \
	macro(a1) \
	__VA_OPT__(FOR_EACH_AGAIN PARENS (macro, __VA_ARGS__))
#define FOR_EACH_AGAIN() FOR_EACH_HELPER

#define FOR_EACH_LIST(macro, ...) \
	__VA_OPT__(EXPAND(FOR_EACH_LIST_HELPER(macro, __VA_ARGS__)))
#define FOR_EACH_LIST_HELPER(macro, a1, ...) \
	macro(a1) \
	__VA_OPT__(COMMA FOR_EACH_LIST_AGAIN PARENS (macro, __VA_ARGS__))
#define FOR_EACH_LIST_AGAIN() FOR_EACH_LIST_HELPER