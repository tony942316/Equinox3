#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

#define EQX_SUPER_ENUM_TO_STRING(name)\
	static const std::string& name##ToString(name value) noexcept\
	{ return name##Strings.at(value); }

#define EQX_SUPER_ENUM_GET_ENUMS(name)\
	static const std::vector<name>& name##GetTypes()\
	{\
		static std::vector<name> result = std::invoke(\
        []()\
        {\
            std::vector<name> temp;\
            temp.reserve(name##Strings.size());\
            std::for_each(name##Strings.begin(), name##Strings.end(),\
            [&temp](const std::pair<const name, std::string>& link)\
            {\
                temp.emplace_back(link.first);\
            });\
            return temp;\
        });\
		return result;\
	}

#define EQX_SUPER_ENUM_OSTREAM(name)\
	friend std::ostream& operator<<(std::ostream& oStream, name val)\
	{\
		oStream << name##ToString(val);\
		return oStream;\
	}

#define EQX_SUPER_ENUM_FULL_IMPLEMENTATION(name)\
	EQX_SUPER_ENUM_TO_STRING(name)\
	EQX_SUPER_ENUM_GET_ENUMS(name)\
	EQX_SUPER_ENUM_OSTREAM(name)

#define EQX_SUPER_ENUM_1(name, e0)\
    enum class name { e0 };\
    static inline const std::unordered_map<name, std::string> name##Strings{\
    { name::e0, #e0 }\
    };\
    EQX_SUPER_ENUM_FULL_IMPLEMENTATION(name)

#define EQX_SUPER_ENUM_2(name, e0, e1)\
    enum class name { e0, e1 };\
    static inline const std::unordered_map<name, std::string> name##Strings{\
    { name::e0, #e0 },\
    { name::e1, #e1 }\
    };\
    EQX_SUPER_ENUM_FULL_IMPLEMENTATION(name)

#define EQX_SUPER_ENUM_3(name, e0, e1, e2)\
    enum class name { e0, e1, e2 };\
    static inline const std::unordered_map<name, std::string> name##Strings{\
    { name::e0, #e0 },\
    { name::e1, #e1 },\
    { name::e2, #e2 }\
    };\
    EQX_SUPER_ENUM_FULL_IMPLEMENTATION(name)

#define EQX_SUPER_ENUM_4(name, e0, e1, e2, e3)\
    enum class name { e0, e1, e2, e3 };\
    static inline const std::unordered_map<name, std::string> name##Strings{\
    { name::e0, #e0 },\
    { name::e1, #e1 },\
    { name::e2, #e2 },\
    { name::e3, #e3 }\
    };\
    EQX_SUPER_ENUM_FULL_IMPLEMENTATION(name)

#define EQX_SUPER_ENUM_5(name, e0, e1, e2, e3, e4)\
    enum class name { e0, e1, e2, e3, e4 };\
    static inline const std::unordered_map<name, std::string> name##Strings{\
    { name::e0, #e0 },\
    { name::e1, #e1 },\
    { name::e2, #e2 },\
    { name::e3, #e3 },\
    { name::e4, #e4 }\
    };\
    EQX_SUPER_ENUM_FULL_IMPLEMENTATION(name)

#define EQX_SUPER_ENUM_6(name, e0, e1, e2, e3, e4, e5)\
    enum class name { e0, e1, e2, e3, e4, e5 };\
    static inline const std::unordered_map<name, std::string> name##Strings{\
    { name::e0, #e0 },\
    { name::e1, #e1 },\
    { name::e2, #e2 },\
    { name::e3, #e3 },\
    { name::e4, #e4 },\
    { name::e5, #e5 }\
    };\
    EQX_SUPER_ENUM_FULL_IMPLEMENTATION(name)

#define EQX_SUPER_ENUM_7(name, e0, e1, e2, e3, e4, e5, e6)\
    enum class name { e0, e1, e2, e3, e4, e5, e6 };\
    static inline const std::unordered_map<name, std::string> name##Strings{\
    { name::e0, #e0 },\
    { name::e1, #e1 },\
    { name::e2, #e2 },\
    { name::e3, #e3 },\
    { name::e4, #e4 },\
    { name::e5, #e5 },\
    { name::e6, #e6 }\
    };\
    EQX_SUPER_ENUM_FULL_IMPLEMENTATION(name)

#define EQX_SUPER_ENUM_8(name, e0, e1, e2, e3, e4, e5, e6, e7)\
    enum class name { e0, e1, e2, e3, e4, e5, e6, e7 };\
    static inline const std::unordered_map<name, std::string> name##Strings{\
    { name::e0, #e0 },\
    { name::e1, #e1 },\
    { name::e2, #e2 },\
    { name::e3, #e3 },\
    { name::e4, #e4 },\
    { name::e5, #e5 },\
    { name::e6, #e6 },\
    { name::e7, #e7 }\
    };\
    EQX_SUPER_ENUM_FULL_IMPLEMENTATION(name)

#define EQX_SUPER_ENUM_9(name, e0, e1, e2, e3, e4, e5, e6, e7, e8)\
    enum class name { e0, e1, e2, e3, e4, e5, e6, e7, e8 };\
    static inline const std::unordered_map<name, std::string> name##Strings{\
    { name::e0, #e0 },\
    { name::e1, #e1 },\
    { name::e2, #e2 },\
    { name::e3, #e3 },\
    { name::e4, #e4 },\
    { name::e5, #e5 },\
    { name::e6, #e6 },\
    { name::e7, #e7 },\
    { name::e8, #e8 }\
    };\
    EQX_SUPER_ENUM_FULL_IMPLEMENTATION(name)

#define EQX_SUPER_ENUM_10(name, e0, e1, e2, e3, e4, e5, e6, e7, e8, e9)\
    enum class name { e0, e1, e2, e3, e4, e5, e6, e7, e8, e9 };\
    static inline const std::unordered_map<name, std::string> name##Strings{\
    { name::e0, #e0 },\
    { name::e1, #e1 },\
    { name::e2, #e2 },\
    { name::e3, #e3 },\
    { name::e4, #e4 },\
    { name::e5, #e5 },\
    { name::e6, #e6 },\
    { name::e7, #e7 },\
    { name::e8, #e8 },\
    { name::e9, #e9 }\
    };\
    EQX_SUPER_ENUM_FULL_IMPLEMENTATION(name)


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