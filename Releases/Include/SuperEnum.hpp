#pragma once

#include <array>
#include <string_view>
#include <iostream>

template <class T>
struct EnumPair
{
    consteval EnumPair(T e, std::string_view s)
        :
        m_Enum(e),
        m_String(s)
    {

    }

    T m_Enum;
    std::string_view m_String;
};

#define __EQX_SUPER_ENUM_TO_STRING(name)\
	static constexpr std::string_view name##ToString(name value) noexcept\
	{ return name##Collection.at(static_cast<std::size_t>(value)).m_String; }

#define __EQX_SUPER_ENUM_GET_ENUMS(name)\
	[[nodiscard]] static consteval \
        std::array<name, name##Collection.size()> \
            get##name##Enums() noexcept\
	{\
        std::array<name, name##Collection.size()> result;\
        for (std::size_t i = 0ULL; i < name##Collection.size(); i++)\
        {\
            result[i] = name##Collection.at(i).m_Enum;\
        }\
        return result;\
    }\

#define __EQX_SUPER_ENUM_GET_STRINGS(name)\
    [[nodiscard]] static consteval \
        std::array<std::string_view, name##Collection.size()> \
            get##name##Strings() noexcept\
	{\
        std::array<std::string_view, name##Collection.size()> result;\
        for (std::size_t i = 0ULL; i < name##Collection.size(); i++)\
        {\
            result[i] = name##Collection.at(i).m_String;\
        }\
        return result;\
    }\

#define __EQX_SUPER_ENUM_OSTREAM(name)\
	friend std::ostream& operator<<(std::ostream& oStream, name val)\
	{\
		oStream << name##ToString(val);\
		return oStream;\
	}

#define __EQX_SUPER_ENUM_FULL_IMPLEMENTATION(name)\
	__EQX_SUPER_ENUM_TO_STRING(name)\
	__EQX_SUPER_ENUM_GET_ENUMS(name)\
    __EQX_SUPER_ENUM_GET_STRINGS(name)\
	__EQX_SUPER_ENUM_OSTREAM(name)

#define EQX_SUPER_ENUM_1(name, e0)\
    enum class name : std::size_t\
        { e0 };\
    static inline constexpr std::array<EnumPair<name>, 1ULL> \
        name##Collection = \
        {\
            EnumPair(name::e0, #e0)\
        };\
    __EQX_SUPER_ENUM_FULL_IMPLEMENTATION(name)

#define EQX_SUPER_ENUM_3(name, e0, e1, e2)\
    enum class name : std::size_t\
        { e0, e1, e2 };\
    static inline constexpr std::array<EnumPair<name>, 3ULL> \
        name##Collection = \
        {\
            EnumPair(name::e0, #e0),\
            EnumPair(name::e1, #e1),\
            EnumPair(name::e2, #e2)\
        };\
    __EQX_SUPER_ENUM_FULL_IMPLEMENTATION(name)

#define EQX_SUPER_ENUM_4(name, e0, e1, e2, e3)\
    enum class name : std::size_t\
        { e0, e1, e2, e3 };\
    static inline constexpr std::array<EnumPair<name>, 4ULL> \
        name##Collection = \
        {\
            EnumPair(name::e0, #e0),\
            EnumPair(name::e1, #e1),\
            EnumPair(name::e2, #e2),\
            EnumPair(name::e3, #e3)\
        };\
    __EQX_SUPER_ENUM_FULL_IMPLEMENTATION(name)

#define EQX_SUPER_ENUM_5(name, e0, e1, e2, e3, e4)\
    enum class name : std::size_t\
        { e0, e1, e2, e3, e4 };\
    static inline constexpr std::array<EnumPair<name>, 5ULL> \
        name##Collection = \
        {\
            EnumPair(name::e0, #e0),\
            EnumPair(name::e1, #e1),\
            EnumPair(name::e2, #e2),\
            EnumPair(name::e3, #e3),\
            EnumPair(name::e4, #e4)\
        };\
    __EQX_SUPER_ENUM_FULL_IMPLEMENTATION(name)

#define EQX_SUPER_ENUM_6(name, e0, e1, e2, e3, e4, e5)\
    enum class name : std::size_t\
        { e0, e1, e2, e3, e4, e5 };\
    static inline constexpr std::array<EnumPair<name>, 6ULL> \
        name##Collection = \
        {\
            EnumPair(name::e0, #e0),\
            EnumPair(name::e1, #e1),\
            EnumPair(name::e2, #e2),\
            EnumPair(name::e3, #e3),\
            EnumPair(name::e4, #e4),\
            EnumPair(name::e5, #e5)\
        };\
    __EQX_SUPER_ENUM_FULL_IMPLEMENTATION(name)

namespace eqx
{
    /**
     * @brief Generate A Copy Pastable Super Enum Macro Of Given Size
     * 
     * @param num Number Of Values To Be Stored In The Enum
     * 
     * @returns std::string That Represents The Macro
     */
	std::string superEnumMacroFactory(std::size_t num);
}