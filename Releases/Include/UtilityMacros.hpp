#pragma once

/**
 * @brief Macro For Use By Other Macros In The UtilityMacros Header, 
 *		NOT FOR EXTERNAL USE!
 **/
#define P_EQX_PARENS ()
/**
 * @brief Macro For Use By Other Macros In The UtilityMacros Header,
 *		NOT FOR EXTERNAL USE!
 **/
#define P_EQX_COMMA ,

/**
 * @brief Macro For Use By Other Macros In The UtilityMacros Header,
 *		NOT FOR EXTERNAL USE!
 **/
#define P_EQX_EXPAND1(...) __VA_ARGS__
/**
 * @brief Macro For Use By Other Macros In The UtilityMacros Header,
 *		NOT FOR EXTERNAL USE!
 **/
#define P_EQX_EXPAND2(...) \
	P_EQX_EXPAND1(P_EQX_EXPAND1(P_EQX_EXPAND1(P_EQX_EXPAND1(__VA_ARGS__))))
/**
 * @brief Macro For Use By Other Macros In The UtilityMacros Header,
 *		NOT FOR EXTERNAL USE!
 **/
#define P_EQX_EXPAND3(...) \
	P_EQX_EXPAND2(P_EQX_EXPAND2(P_EQX_EXPAND2(P_EQX_EXPAND2(__VA_ARGS__))))
/**
 * @brief Macro For Use By Other Macros In The UtilityMacros Header,
 *		NOT FOR EXTERNAL USE!
 **/
#define P_EQX_EXPAND4(...) \
	P_EQX_EXPAND3(P_EQX_EXPAND3(P_EQX_EXPAND3(P_EQX_EXPAND3(__VA_ARGS__))))
/**
 * @brief Macro For Use By Other Macros In The UtilityMacros Header,
 *		NOT FOR EXTERNAL USE!
 **/
#define P_EQX_EXPAND5(...) \
	P_EQX_EXPAND4(P_EQX_EXPAND4(P_EQX_EXPAND4(P_EQX_EXPAND4(__VA_ARGS__))))
/**
 * @brief Macro For Use By Other Macros In The UtilityMacros Header,
 *		NOT FOR EXTERNAL USE!
 **/
#define P_EQX_EXPAND(...) \
	P_EQX_EXPAND5(P_EQX_EXPAND5(P_EQX_EXPAND5(P_EQX_EXPAND5(__VA_ARGS__))))

/**
 * @brief Apply The First Argument To All Other Arguments
 *		i.e. EQX_FOR_EACH(SOME_MACRO, x, y, z) Would Produce
 *		SOME_MACRO(x) SOME_MACRO(y) SOME_MACRO(z)
 * 
 * @param macro The Macro That Will Be Called On Each Argument
 * @param ... The Arguments That Will Be Used As Parameters For macro
 * 
 * @returns The Result Of Applying macro To Each Argument Seperated By Spaces
 **/
#define EQX_FOR_EACH(macro, ...) \
	__VA_OPT__(P_EQX_EXPAND(P_EQX_FOR_EACH_HELPER(macro, __VA_ARGS__)))
/**
 * @brief Macro For Use By Other Macros In The UtilityMacros Header,
 *		NOT FOR EXTERNAL USE!
 **/
#define P_EQX_FOR_EACH_HELPER(macro, a1, ...) \
	macro(a1) \
	__VA_OPT__(P_EQX_FOR_EACH_AGAIN P_EQX_PARENS (macro, __VA_ARGS__))
/**
 * @brief Macro For Use By Other Macros In The UtilityMacros Header,
 *		NOT FOR EXTERNAL USE!
 **/
#define P_EQX_FOR_EACH_AGAIN() P_EQX_FOR_EACH_HELPER

/**
 * @brief Apply The First Argument To All Other Arguments
 *		i.e. EQX_FOR_EACH_LIST(SOME_MACRO, x, y, z) Would Produce
 *		SOME_MACRO(x), SOME_MACRO(y), SOME_MACRO(z),
 *		Note The Addition Of Commas As Compared To EQX_FOR_EACH
 *
 * @param macro The Macro That Will Be Called On Each Argument
 * @param ... The Arguments That Will Be Used As Parameters For macro
 * 
 * @returns The Result Of Applying macro To Each Argument Seperated By Commas
 **/
#define EQX_FOR_EACH_LIST(macro, ...) \
	__VA_OPT__(P_EQX_EXPAND(P_EQX_FOR_EACH_LIST_HELPER(macro, __VA_ARGS__)))
/**
 * @brief Macro For Use By Other Macros In The UtilityMacros Header,
 *		NOT FOR EXTERNAL USE!
 **/
#define P_EQX_FOR_EACH_LIST_HELPER(macro, a1, ...) \
	macro(a1) \
	__VA_OPT__(P_EQX_COMMA P_EQX_FOR_EACH_LIST_AGAIN P_EQX_PARENS \
	(macro, __VA_ARGS__))
/**
 * @brief Macro For Use By Other Macros In The UtilityMacros Header,
 *		NOT FOR EXTERNAL USE!
 **/
#define P_EQX_FOR_EACH_LIST_AGAIN() P_EQX_FOR_EACH_LIST_HELPER

/**
 * @brief Macro For Use By Other Macros In The UtilityMacros Header,
 *		NOT FOR EXTERNAL USE!
 **/
#define P_EQX_COUNT_ARGS_HELPER(x) 1ULL+
/**
 * @brief Macro That Will Count The Number Of Arguments Provided
 *		i.e. EQX_COUNT_ARGS(a, b, c) Would Produce 1ULL + 1ULL + 1ULL + 0ULL
 * 
 * @param ... The Arguments To Be Counted
 * 
 * @returns The Sum Of The Number Of Arguments As A Repeated Addition Of
 *		1ULL
 */
#define EQX_COUNT_ARGS(...) \
    EQX_FOR_EACH(P_EQX_COUNT_ARGS_HELPER, __VA_ARGS__) 0ULL

/**
 * @brief Macro For Use By Other Macros In The UtilityMacros Header,
 *		NOT FOR EXTERNAL USE!
 **/
#define P_EQX_STRING_ARGS_HELPER(x) #x
/**
 * @breif Macro That Will Parrot Back A const char[n] Of Its Inputs
 *		i.e. EQX_STRING_ARGS(a, b, c) Would Produce "a", "b", "c"
 * 
 * @param ... The Arguments To Be Converted To const char[n]
 * 
 * @returns A Comma Seperated "List"
 *		(NOT A std::list JUST LITERAL VALUES SEPERATED BY COMMAS!)
 *		Of The Converted Arguments
 */
#define EQX_STRING_ARGS(...) \
    EQX_FOR_EACH_LIST(P_EQX_STRING_ARGS_HELPER, __VA_ARGS__)