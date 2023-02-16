#include "SuperEnum.hpp"

#include <string>
#include <cassert>

std::string enumMacroDeclaration(std::size_t num)
{
	std::string result = "";
	result += "#define EQX_SUPER_ENUM_" + std::to_string(num);
	result += "(name";
	for (std::size_t i = 0; i < num; i++)
	{
		result += ", e" + std::to_string(i);
	}
	result += ")\\\n";
	return result;
}

std::string enumClassDefinition(std::size_t num)
{
	std::string result = "";
	result += "    enum class name : std::size_t\\\n";
	result += "        { e0";
	for (std::size_t i = 1; i < num; i++)
	{
		result += ", e" + std::to_string(i);
	}
	result += " };\\\n";
	return result;
}

std::string enumClassArrayDefinition(std::size_t num)
{
	std::string result = "";
	result += "    static inline constexpr std::array<EnumPair<name>, ";
	result += std::to_string(num) + "ULL> \\\n";
	result += "        name##Collection = \\\n";
	result += "        {\\\n";
	for (std::size_t i = 0; i < num; i++)
	{
		result += "            EnumPair(name::e" + std::to_string(i);
		result += ", #e" + std::to_string(i) + "),\\\n";
	}
	result.erase(result.end() - 3);
	result += "        };\\\n";
	
	return result;
}

namespace eqx
{
	std::string superEnumMacroFactory(std::size_t num)
	{
		assert(num > 0ULL);
		std::string result = "";
		result += enumMacroDeclaration(num);
		result += enumClassDefinition(num);
		result += enumClassArrayDefinition(num);
		result += "    " + 
			std::string("__EQX_SUPER_ENUM_FULL_IMPLEMENTATION(name)\n");

		return result;
	}
}