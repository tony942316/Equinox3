#include "UnitTest.hpp"

#include <algorithm>

std::vector<std::string> UnitTester::s_FailedTests;

Primitives::Primitives()
{
	makePrimitives();
	makeStrings();
	makeCollections();
}

void Primitives::makePrimitives()
{
	primitives = std::vector<std::string>({
			"char", "wchar_t", "char8_t", "char16_t", "char32_t",
			"short", "int", "long", "long long",
			"unsigned short", "unsigned int",
			"unsigned long", "unsigned long long",
			"float", "double", "long double"
		});

	auto generator = [this](std::vector<std::string>& vec,
		std::string_view prefix)
	{
		vec.reserve(primitives.size());
		std::ranges::transform(primitives,
			std::back_inserter(vec),
			[prefix](const auto& x)
			{
				auto temp = std::string("");
				temp += prefix;
				temp += " ";
				temp += x;
				return temp;
			});
	};

	generator(volatilePrimitives, "volatile");
	generator(constPrimitives, "const");
	generator(constVolatilePrimitives, "const volatile");

	appendStrVector(containerPrimitives, primitives);
	appendStrVector(containerPrimitives, volatilePrimitives);

	appendStrVector(allPrimitives, primitives);
	appendStrVector(allPrimitives, volatilePrimitives);
	appendStrVector(allPrimitives, constPrimitives);
	appendStrVector(allPrimitives, constVolatilePrimitives);
}

void Primitives::makeStrings()
{
	strings = std::vector<std::string>({
		"std::string", "std::wstring", "std::u8string", "std::u16string",
		"std::u32string", "std::string_view", "std::wstring_view",
		"std::u8string_view", "std::u16string_view", "std::u32string_view"
		});

	auto generator = [this](std::vector<std::string>& vec,
		std::string_view prefix)
	{
		vec.reserve(strings.size());
		std::ranges::transform(strings,
			std::back_inserter(vec),
			[prefix](const auto& x)
			{
				auto temp = std::string("");
				temp += prefix;
				temp += " ";
				temp += x;
				return temp;
			});
	};

	generator(volatileStrings, "volatile");
	generator(constStrings, "const");
	generator(constVolatileStrings, "const volatile");

	appendStrVector(allStrings, strings);
	appendStrVector(allStrings, volatileStrings);
	appendStrVector(allStrings, constStrings);
	appendStrVector(allStrings, constVolatileStrings);
}

void Primitives::makeCollections()
{
	auto generator1Param = [this](std::vector<std::string>& vec,
		std::string_view name)
	{
		vec.reserve(containerPrimitives.size());
		std::ranges::transform(containerPrimitives,
			std::back_inserter(vec),
			[name](const auto& x)
			{
				auto temp = std::string("");
				temp += name;
				temp += "<";
				temp += x;
				temp += ">";
				return temp;
			});
	};

	generator1Param(allVectors, "std::vector");
	generator1Param(allLists, "std::list");
	generator1Param(allFLists, "std::forward_list");
	generator1Param(allSets, "std::set");
	generator1Param(allUSets, "std::unordered_set");
	generator1Param(allQueues, "std::queue");
	generator1Param(allPQueues, "std::priority_queue");
	generator1Param(allDeques, "std::deque");
	generator1Param(allStacks, "std::stack");

	auto generatorArray = [this](std::vector<std::string>& vec,
		std::size_t num)
	{
		vec.reserve(vec.size() + containerPrimitives.size());
		std::ranges::transform(containerPrimitives,
			std::back_inserter(vec),
			[num](const auto& x)
			{
				auto temp = std::string("");
				temp += "std::array<";
				temp += x;
				temp += ", ";
				temp += std::to_string(num);
				temp += ">";
				return temp;
			});
	};

	for (std::size_t i = 1ULL; i <= 100ULL; i++)
	{
		generatorArray(allArrays, i);
	}

	auto generator2Param = [this](std::vector<std::string>& vec,
		std::string_view name)
	{
		vec.reserve(containerPrimitives.size() *
			containerPrimitives.size());
		for (const auto& x : containerPrimitives)
		{
			for (const auto& y : containerPrimitives)
			{
				auto temp = std::string("");
				temp += name;
				temp += "<";
				temp += x;
				temp += ", ";
				temp += y;
				temp += ">";
				vec.emplace_back(std::move(temp));
			}
		}
	};

	generator2Param(allMaps, "std::map");
	generator2Param(allUMaps, "std::unordered_map");

	appendStrVector(allRangeCollections, allVectors);
	appendStrVector(allRangeCollections, allLists);
	appendStrVector(allRangeCollections, allSets);
	appendStrVector(allRangeCollections, allUSets);
	appendStrVector(allRangeCollections, allDeques);
	appendStrVector(allRangeCollections, allArrays);
	appendStrVector(allRangeCollections, allMaps);
	appendStrVector(allRangeCollections, allUMaps);

	appendStrVector(allNonRangeCollections, allFLists);
	appendStrVector(allNonRangeCollections, allQueues);
	appendStrVector(allNonRangeCollections, allPQueues);
	appendStrVector(allNonRangeCollections, allStacks);

	appendStrVector(allCollections, allVectors);
	appendStrVector(allCollections, allLists);
	appendStrVector(allCollections, allFLists);
	appendStrVector(allCollections, allSets);
	appendStrVector(allCollections, allUSets);
	appendStrVector(allCollections, allQueues);
	appendStrVector(allCollections, allPQueues);
	appendStrVector(allCollections, allDeques);
	appendStrVector(allCollections, allStacks);
	appendStrVector(allCollections, allArrays);
	appendStrVector(allCollections, allMaps);
	appendStrVector(allCollections, allUMaps);
}

void Primitives::appendStrVector(std::vector<std::string>& appendi,
	const std::vector<std::string>& appender)
{
	appendi.reserve(appendi.size() + appender.size());
	std::ranges::transform(appender,
		std::back_inserter(appendi),
		[](const auto& x)
		{
			return x;
		});
}

std::vector<std::string> makeMacroString(const std::string& macroName,
	const std::vector<std::string>& macroDefTokens)
{
	auto macroLines = std::vector<std::string>();

	auto temp = std::string("");
	temp += "#define ";
	temp += macroName;
	temp += " ";

	for (const auto& val : macroDefTokens)
	{
		if (temp.size() + val.size() > 75ULL)
		{
			temp += " \\";
			macroLines.emplace_back(std::move(temp));
			temp = "    ";
		}
		temp += val;
		temp += ", ";
	}

	auto& last = macroLines.back();
	last.pop_back();
	last.pop_back();
	last.pop_back();
	last.pop_back();

	return macroLines;
}

void makeMacros()
{
	const auto prims = Primitives();
	auto file = std::ofstream("src/Headers/HolyMacros.hpp",
		std::ios::out | std::ios::trunc);

	auto writeToFile =
		[&file](const std::vector<std::string>& lines)
	{
		std::ranges::for_each(lines,
			[&file](const auto& x)
			{
				file << x << "\n";
			});
		file << "\n";
	};

	const auto includes = std::vector<std::string>({
		"#pragma once\n"
		"#include <string>",
		"#include <string_view>",
		"#include <vector>",
		"#include <list>",
		"#include <forward_list>",
		"#include <set>",
		"#include <unordered_set>",
		"#include <queue>",
		"#include <deque>",
		"#include <stack>",
		"#include <array>",
		"#include <map>",
		"#include <unordered_map>"
		});

	const auto allMacros = std::vector<std::vector<std::string>>({
		includes,
		makeMacroString("ALL_PRIMITIVES", prims.allPrimitives),
		makeMacroString("ALL_STD_STRINGS", prims.allStrings),
		makeMacroString("ALL_STD_RANGE_COLLECTIONS",
			prims.allRangeCollections),
		makeMacroString("ALL_STD_NONRANGE_COLLECTIONS",
			prims.allNonRangeCollections),
		makeMacroString("ALL_STD_COLLECTIONS", prims.allCollections)
		});

	std::ranges::for_each(allMacros,
		[&writeToFile](const auto& x)
		{
			writeToFile(x);
		});

	file.close();
}