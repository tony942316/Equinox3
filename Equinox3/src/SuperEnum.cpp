#include "SuperEnum.hpp"

std::string enumMacroDeclaration(std::size_t num)
{
	std::string result = "#define EQX_SUPER_ENUM_" + std::to_string(num);
	result += "(name";
	for (std::size_t i = 0; i < num; i++)
	{
		result += ", e" + std::to_string(i);
	}
	result += ")";
	return result;
}

std::string enumClassDefinition(std::size_t num)
{
	std::string result = "enum class name { e0";
	for (std::size_t i = 1; i < num; i++)
	{
		result += ", e" + std::to_string(i);
	}
	result += " };";
	return result;
}

std::string enumClassMapDefinition(std::size_t num)
{
	std::string result =
		"static inline const std::unordered_map<name, std::string> ";
	result += "name##Strings{\\\n";
	for (std::size_t i = 0; i < num - 1; i++)
	{
		result += "    { name::e" + std::to_string(i);
		result += ", #e" + std::to_string(i) + " },\\\n";
	}
	result += "    { name::e" + std::to_string(num - 1);
	result += ", #e" + std::to_string(num - 1) + " }\\\n";
	result += "    };";
	return result;
}

namespace eqx
{
	std::string superEnumMacroFactory(std::size_t num)
	{
		std::string result = enumMacroDeclaration(num) + "\\\n";
		result += "    " + enumClassDefinition(num) + "\\\n";
		result += "    " + enumClassMapDefinition(num) + "\\\n";
		result += "    " + 
			std::string("EQX_SUPER_ENUM_FULL_IMPLEMENTATION(name)\n");

		return result;
	}
}