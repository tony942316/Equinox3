#include "SuperEnumTester.hpp"

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

#include "UnitTest.hpp"

UniversalTester SuperEnumTester::s_Tests;

bool SuperEnumTester::test()
{
	if (testGetEnums() &&
		testGetStrings() &&
		testToString() &&
		testStream())
	{
		std::cout << "SuperEnum Tests Passed" << std::endl;
		return true;
	}
	else
	{
		std::cout << "SuperEnum Tests Failed!" << std::endl;
		return false;
	}
}

#define testGetEnums_M(name)\
	constexpr std::array<superEnumShell::name,\
						 superEnumShell::get##name##Enums().size()>\
		produced##name(superEnumShell::get##name##Enums());\
		s_Tests.addTest(s_Expected##name##Enums.size(), produced##name.size(),\
			"Size Mismatch!");\
		s_Tests.addBulkTests(s_Expected##name##Enums, produced##name);\

bool SuperEnumTester::testGetEnums()
{
	testGetEnums_M(OnePub)
	testGetEnums_M(FourPub)
	testGetEnums_M(SixPub)
	testGetEnums_M(TenPub)

	return s_Tests.test();
}

#define testGetStrings_M(name)\
	constexpr std::array<std::string_view,\
						 superEnumShell::get##name##Strings().size()>\
		produced##name(superEnumShell::get##name##Strings());\
	s_Tests.addTest(s_Expected##name##Strings.size(), produced##name.size(),\
		"Size Mismatch!");\
	s_Tests.addBulkTests(s_Expected##name##Strings, produced##name);

bool SuperEnumTester::testGetStrings()
{
	testGetStrings_M(OnePub)
	testGetStrings_M(FourPub)
	testGetStrings_M(SixPub)
	testGetStrings_M(TenPub)

	return s_Tests.test();
}

#define testToString_M(name)\
	constexpr std::array<superEnumShell::name,\
						 superEnumShell::get##name##Enums().size()>\
		raw##name(superEnumShell::get##name##Enums());\
	std::array<std::string_view, superEnumShell::get##name##Enums().size()>\
		produced##name;\
	std::transform(raw##name.begin(), raw##name.end(), produced##name.begin(),\
		[](superEnumShell::name val)\
		{\
			return superEnumShell::name##ToString(val);\
		});\
	s_Tests.addTest(s_Expected##name##Strings.size(), produced##name.size(),\
		"Size Mismatch!");\
	s_Tests.addBulkTests(s_Expected##name##Strings, produced##name);

bool SuperEnumTester::testToString()
{
	testToString_M(OnePub)
	testToString_M(FourPub)
	testToString_M(SixPub)
	testToString_M(TenPub)

	return s_Tests.test();
}

#define testStream_M(name)\
	constexpr std::array<superEnumShell::name,\
						 superEnumShell::get##name##Enums().size()>\
		raw##name(superEnumShell::get##name##Enums());\
	std::array<std::string, superEnumShell::get##name##Enums().size()>\
		produced##name;\
	std::transform(raw##name.begin(), raw##name.end(), produced##name.begin(),\
		[](superEnumShell::name val)\
		{\
			std::stringstream ss;\
			std::string line("");\
			ss << val;\
			std::getline(ss, line);\
			return line;\
		});\
	s_Tests.addTest(s_Expected##name##Strings.size(), produced##name.size(),\
		"Size Mismatch!");\
	s_Tests.addBulkTests(s_Expected##name##Strings, produced##name);

bool SuperEnumTester::testStream()
{
	testStream_M(OnePub)
	testStream_M(FourPub)
	testStream_M(SixPub)
	testStream_M(TenPub)

	return s_Tests.test();
}