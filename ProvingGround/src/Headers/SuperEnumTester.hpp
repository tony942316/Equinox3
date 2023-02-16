#pragma once

#include "SuperEnum.hpp"

#include "UnitTest.hpp"

class SuperEnumTester
{
public:
	SuperEnumTester() = delete;
	SuperEnumTester(const SuperEnumTester&) = delete;
	SuperEnumTester(SuperEnumTester&&) = delete;
	SuperEnumTester& operator= (const SuperEnumTester&) = delete;
	SuperEnumTester& operator= (SuperEnumTester&&) = delete;
	~SuperEnumTester() = delete;

	static bool test();

private:
	class superEnumShell
	{
	public:
		EQX_SUPER_ENUM_1(OnePub, e1)
		EQX_SUPER_ENUM_4(FourPub, e1, e2,
			e3, e4)
		EQX_SUPER_ENUM_6(SixPub,
			e1,
			e2,
			e3,
			e4,
			e5,
			e6
		)
		EQX_SUPER_ENUM_10(TenPub,
			One,
			Two,
			Three,
			Four,
			Five,
			Six,
			Seven,
			Eight,
			Nine,
			Ten
		)
	};

	static bool testGetEnums();
	static bool testGetStrings();
	static bool testToString();
	static bool testStream();

	static UniversalTester s_Tests;

	static inline constexpr
		std::array<superEnumShell::OnePub, 1ULL> s_ExpectedOnePubEnums = {
			superEnumShell::OnePub::e1
		};
	static inline constexpr
		std::array<superEnumShell::FourPub, 4ULL> s_ExpectedFourPubEnums = {
			superEnumShell::FourPub::e1,
			superEnumShell::FourPub::e2,
			superEnumShell::FourPub::e3,
			superEnumShell::FourPub::e4
		};
	static inline constexpr
		std::array<superEnumShell::SixPub, 6ULL> s_ExpectedSixPubEnums = {
			superEnumShell::SixPub::e1,
			superEnumShell::SixPub::e2,
			superEnumShell::SixPub::e3,
			superEnumShell::SixPub::e4,
			superEnumShell::SixPub::e5,
			superEnumShell::SixPub::e6
		};

	static inline constexpr 
		std::array<superEnumShell::TenPub, 10ULL> s_ExpectedTenPubEnums = {
			superEnumShell::TenPub::One,
			superEnumShell::TenPub::Two,
			superEnumShell::TenPub::Three,
			superEnumShell::TenPub::Four,
			superEnumShell::TenPub::Five,
			superEnumShell::TenPub::Six,
			superEnumShell::TenPub::Seven,
			superEnumShell::TenPub::Eight,
			superEnumShell::TenPub::Nine,
			superEnumShell::TenPub::Ten
		};

	static inline constexpr 
		std::array<std::string_view, 1ULL> s_ExpectedOnePubStrings = {
			"e1"
		};

	static inline constexpr
		std::array<std::string_view, 4ULL> s_ExpectedFourPubStrings = {
			"e1",
			"e2",
			"e3",
			"e4",
		};

	static inline constexpr
		std::array<std::string_view, 6ULL> s_ExpectedSixPubStrings = {
			"e1",
			"e2",
			"e3",
			"e4",
			"e5",
			"e6"
		};

	static inline constexpr
		std::array<std::string_view, 10ULL> s_ExpectedTenPubStrings = {
			"One",
			"Two",
			"Three",
			"Four",
			"Five",
			"Six",
			"Seven",
			"Eight",
			"Nine",
			"Ten"
		};
};