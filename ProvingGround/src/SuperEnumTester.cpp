#include "SuperEnumTester.hpp"

#include <iostream>
#include <string>
#include <string_view>
#include <sstream>

#include <array>

#include "UnitTest.hpp"
#include "SuperEnum.hpp"

namespace SuperEnumTester
{
	void testStreaming();

	void test()
	{
		std::cout << "Testing SuperEnum..." << std::endl;
		testStreaming();
		UnitTester::printStatus();
		UnitTester::clear();
	}

	consteval void testEnumCollection();
	consteval void testGetEnums();
	consteval void testGetString();
}

class SuperEnumShell
{
public:
	EQX_SUPER_ENUM(Pub3,
		v1,
		v2,
		v3)
	EQX_SUPER_ENUM(Pub5, v1, v2, v3, v4, v5)
	EQX_SUPER_ENUM(Pub7, v1, v2, v3, v4, v5,
		v6, v7)
};

consteval void SuperEnumTester::testEnumCollection()
{
	using namespace std::string_view_literals;

	constexpr auto expected3 = 
		std::array<EnumPair<SuperEnumShell::Pub3>, 3ULL>({
			{ SuperEnumShell::Pub3::v1, "v1"sv },
			{ SuperEnumShell::Pub3::v2, "v2"sv },
			{ SuperEnumShell::Pub3::v3, "v3"sv }
		});
	static_assert(expected3 == SuperEnumShell::Pub3Collection);

	constexpr auto expected5 =
		std::array<EnumPair<SuperEnumShell::Pub5>, 5ULL>({
			{ SuperEnumShell::Pub5::v1, "v1"sv },
			{ SuperEnumShell::Pub5::v2, "v2"sv },
			{ SuperEnumShell::Pub5::v3, "v3"sv },
			{ SuperEnumShell::Pub5::v4, "v4"sv },
			{ SuperEnumShell::Pub5::v5, "v5"sv }
		});
	static_assert(expected5 == SuperEnumShell::Pub5Collection);

	constexpr auto expected7 =
		std::array<EnumPair<SuperEnumShell::Pub7>, 7ULL>({
			{ SuperEnumShell::Pub7::v1, "v1"sv },
			{ SuperEnumShell::Pub7::v2, "v2"sv },
			{ SuperEnumShell::Pub7::v3, "v3"sv },
			{ SuperEnumShell::Pub7::v4, "v4"sv },
			{ SuperEnumShell::Pub7::v5, "v5"sv },
			{ SuperEnumShell::Pub7::v6, "v6"sv },
			{ SuperEnumShell::Pub7::v7, "v7"sv }
		});
	static_assert(expected7 == SuperEnumShell::Pub7Collection);
}

consteval void SuperEnumTester::testGetEnums()
{
	constexpr auto expected3 =
		std::array<SuperEnumShell::Pub3, 3ULL>({
			SuperEnumShell::Pub3::v1,
			SuperEnumShell::Pub3::v2,
			SuperEnumShell::Pub3::v3
		});
	static_assert(expected3 == SuperEnumShell::getPub3Enums());

	constexpr auto expected5 =
		std::array<SuperEnumShell::Pub5, 5ULL>({
			SuperEnumShell::Pub5::v1,
			SuperEnumShell::Pub5::v2,
			SuperEnumShell::Pub5::v3,
			SuperEnumShell::Pub5::v4,
			SuperEnumShell::Pub5::v5
		});
	static_assert(expected5 == SuperEnumShell::getPub5Enums());

	constexpr auto expected7 =
		std::array<SuperEnumShell::Pub7, 7ULL>({
			SuperEnumShell::Pub7::v1,
			SuperEnumShell::Pub7::v2,
			SuperEnumShell::Pub7::v3,
			SuperEnumShell::Pub7::v4,
			SuperEnumShell::Pub7::v5,
			SuperEnumShell::Pub7::v6,
			SuperEnumShell::Pub7::v7
		});
	static_assert(expected7 == SuperEnumShell::getPub7Enums());
}

consteval void SuperEnumTester::testGetString()
{
	using namespace std::string_view_literals;

	constexpr auto expected3 =
		std::array<std::string_view, 3ULL>({
			"v1"sv,
			"v2"sv,
			"v3"sv
		});
	static_assert(expected3 == SuperEnumShell::getPub3Strings());

	constexpr auto expected5 =
		std::array<std::string_view, 5ULL>({
			"v1"sv,
			"v2"sv,
			"v3"sv,
			"v4"sv,
			"v5"sv
		});
	static_assert(expected5 == SuperEnumShell::getPub5Strings());

	constexpr auto expected7 =
		std::array<std::string_view, 7ULL>({
			"v1"sv,
			"v2"sv,
			"v3"sv,
			"v4"sv,
			"v5"sv,
			"v6"sv,
			"v7"sv,
		});
	static_assert(expected7 == SuperEnumShell::getPub7Strings());
}

void SuperEnumTester::testStreaming()
{
	using namespace std::string_literals;

	auto ss = std::stringstream();
	ss << SuperEnumShell::Pub3::v1;
	ss << SuperEnumShell::Pub3::v2;
	ss << SuperEnumShell::Pub3::v3;
	ss << SuperEnumShell::Pub5::v1;
	ss << SuperEnumShell::Pub5::v2;
	ss << SuperEnumShell::Pub5::v3;
	ss << SuperEnumShell::Pub5::v4;
	ss << SuperEnumShell::Pub5::v5;
	ss << SuperEnumShell::Pub7::v1;
	ss << SuperEnumShell::Pub7::v2;
	ss << SuperEnumShell::Pub7::v3;
	ss << SuperEnumShell::Pub7::v4;
	ss << SuperEnumShell::Pub7::v5;
	ss << SuperEnumShell::Pub7::v6;
	ss << SuperEnumShell::Pub7::v7;

	UnitTester::test(ss.str(), "v1v2v3v1v2v3v4v5v1v2v3v4v5v6v7"s);
}