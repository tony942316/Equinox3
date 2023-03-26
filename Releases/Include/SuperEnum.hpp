#pragma once

#include <array>
#include <string_view>
#include <iostream>

#include "UtilityMacros.hpp"

template <class T>
struct EnumPair
{
    consteval EnumPair()
        :
        m_Enum(static_cast<T>(0ULL)),
        m_String("")
    {
    }

    consteval EnumPair(T e, std::string_view s)
        :
        m_Enum(e),
        m_String(s)
    {
    }

    T m_Enum;
    std::string_view m_String;
};

namespace eqx
{
    /**
     * @brief Function For Use By EQX_SUPER_ENUM, NOT FOR EXTERNAL USE!
     **/
    template <std::size_t N, typename EnumType, typename... Types>
    consteval std::array<EnumPair<EnumType>, N> __makeArr(Types... args)
    {
        std::array<EnumPair<EnumType>, N> arr;
        std::array<std::string_view, N> arr2 = { args... };

        for (std::size_t i = 0ULL; i < arr.size(); i++)
        {
            arr[i].m_Enum = static_cast<EnumType>(i);
            arr[i].m_String = arr2[i];
        }

        return arr;
    }
}


#define __EQX_SUPER_ENUM_TO_STRING(name) \
	[[nodiscard]]static constexpr \
        std::string_view name##ToString(name value) noexcept \
	{ return name##Collection.at(static_cast<std::size_t>(value)).m_String; }

#define __EQX_SUPER_ENUM_GET_ENUMS(name) \
	[[nodiscard]] static consteval \
        std::array<name, name##Collection.size()> get##name##Enums() \
	{ \
        std::array<name, name##Collection.size()> result; \
        for (std::size_t i = 0ULL; i < name##Collection.size(); i++) \
        { \
            result[i] = name##Collection.at(i).m_Enum; \
        } \
        return result; \
    }

#define __EQX_SUPER_ENUM_GET_STRINGS(name)\
    [[nodiscard]] static consteval \
        std::array<std::string_view, name##Collection.size()> \
        get##name##Strings() \
	{ \
        std::array<std::string_view, name##Collection.size()> result; \
        for (std::size_t i = 0ULL; i < name##Collection.size(); i++) \
        { \
            result[i] = name##Collection.at(i).m_String; \
        } \
        return result; \
    }

#define __EQX_SUPER_ENUM_OSTREAM(name) \
	friend std::ostream& operator<< (std::ostream& oStream, name val) \
	{ \
		oStream << name##ToString(val); \
		return oStream; \
	}

#define __EQX_SUPER_ENUM_FULL_IMPLEMENTATION(name) \
	__EQX_SUPER_ENUM_TO_STRING(name) \
	__EQX_SUPER_ENUM_GET_ENUMS(name) \
    __EQX_SUPER_ENUM_GET_STRINGS(name) \
	__EQX_SUPER_ENUM_OSTREAM(name)

#define EQX_SUPER_ENUM(name, ...) \
    enum class name : std::size_t \
        { __VA_ARGS__ }; \
    static inline constexpr auto name##Collection = \
        eqx::__makeArr<EQX_COUNT_ARGS(__VA_ARGS__), name> \
        (EQX_STRING_ARGS(__VA_ARGS__)); \
    __EQX_SUPER_ENUM_FULL_IMPLEMENTATION(name)