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

bool SuperEnumTester::testGetEnums()
{
	const std::vector<superEnumShell::OnePub> expectedOne = {
		superEnumShell::OnePub::e1
	};

	constexpr std::array<superEnumShell::OnePub, 
						 superEnumShell::getOnePubEnums().size()>
		producedOne(superEnumShell::getOnePubEnums());

	const std::vector<superEnumShell::FourPub> expectedFour = {
		superEnumShell::FourPub::e1,
		superEnumShell::FourPub::e2,
		superEnumShell::FourPub::e3,
		superEnumShell::FourPub::e4
	};

	constexpr std::array<superEnumShell::FourPub,
						 superEnumShell::getFourPubEnums().size()>
		producedFour(superEnumShell::getFourPubEnums());

	const std::vector<superEnumShell::SixPub> expectedSix = {
		superEnumShell::SixPub::e1,
		superEnumShell::SixPub::e2,
		superEnumShell::SixPub::e3,
		superEnumShell::SixPub::e4,
		superEnumShell::SixPub::e5,
		superEnumShell::SixPub::e6
	};

	constexpr std::array<superEnumShell::SixPub,
						 superEnumShell::getSixPubEnums().size()>
		producedSix(superEnumShell::getSixPubEnums());

	s_Tests.addTest(expectedOne.size(), producedOne.size(),
		"Size Mismatch!");
	s_Tests.addBulkTests(expectedOne, producedOne);
	s_Tests.addTest(expectedFour.size(), producedFour.size(),
		"Size Mismatch!");
	s_Tests.addBulkTests(expectedFour, producedFour);
	s_Tests.addTest(expectedSix.size(), producedSix.size(),
		"Size Mismatch!");
	s_Tests.addBulkTests(expectedSix, producedSix);

	return s_Tests.test();
}

bool SuperEnumTester::testGetStrings()
{
	const std::vector<std::string> expected = {
		"e1",
		"e1",
		"e2",
		"e3",
		"e4",
		"e1",
		"e2",
		"e3",
		"e4",
		"e5",
		"e6"
	};

	constexpr std::array<std::string_view, 1ULL>
		producedOne = superEnumShell::getOnePubStrings();
	constexpr std::array<std::string_view, 4ULL>
		producedFour = superEnumShell::getFourPubStrings();
	constexpr std::array<std::string_view, 6ULL>
		producedSix = superEnumShell::getSixPubStrings();

	std::vector<std::string> produced;
	std::for_each(producedOne.begin(), producedOne.end(),
		[&produced](std::string_view val)
		{
			produced.emplace_back(val);
		});
	std::for_each(producedFour.begin(), producedFour.end(),
		[&produced](std::string_view val)
		{
			produced.emplace_back(val);
		});
	std::for_each(producedSix.begin(), producedSix.end(),
		[&produced](std::string_view val)
		{
			produced.emplace_back(val);
		});

	s_Tests.addTest(expected.size(), produced.size(),
		"Size Mismatch!");
	s_Tests.addBulkTests(expected, produced);

	return s_Tests.test();
}

bool SuperEnumTester::testToString()
{
	constexpr std::array<std::string_view, 1ULL>
		expectedOne = superEnumShell::getOnePubStrings();
	constexpr std::array<std::string_view, 4ULL>
		expectedFour = superEnumShell::getFourPubStrings();
	constexpr std::array<std::string_view, 6ULL>
		expectedSix = superEnumShell::getSixPubStrings();

	std::vector<std::string> expected;
	std::for_each(expectedOne.begin(), expectedOne.end(),
		[&expected](std::string_view val)
		{
			expected.emplace_back(val);
		});
	std::for_each(expectedFour.begin(), expectedFour.end(),
		[&expected](std::string_view val)
		{
			expected.emplace_back(val);
		});
	std::for_each(expectedSix.begin(), expectedSix.end(),
		[&expected](std::string_view val)
		{
			expected.emplace_back(val);
		});

	constexpr std::array<superEnumShell::OnePub, 1ULL>
		producedOne = superEnumShell::getOnePubEnums();
	constexpr std::array<superEnumShell::FourPub, 4ULL>
		producedFour = superEnumShell::getFourPubEnums();
	constexpr std::array<superEnumShell::SixPub, 6ULL>
		producedSix = superEnumShell::getSixPubEnums();

	std::vector<std::string> produced;
	std::for_each(producedOne.begin(), producedOne.end(),
		[&produced](superEnumShell::OnePub val)
		{
			produced.emplace_back(superEnumShell::OnePubToString(val));
		});
	std::for_each(producedFour.begin(), producedFour.end(),
		[&produced](superEnumShell::FourPub val)
		{
			produced.emplace_back(superEnumShell::FourPubToString(val));
		});
	std::for_each(producedSix.begin(), producedSix.end(),
		[&produced](superEnumShell::SixPub val)
		{
			produced.emplace_back(superEnumShell::SixPubToString(val));
		});

	s_Tests.addTest(expected.size(), produced.size(),
		"Size Mismatch!");
	s_Tests.addBulkTests(expected, produced);

	return s_Tests.test();
}

bool SuperEnumTester::testStream()
{
	constexpr std::array<std::string_view, 1ULL>
		expectedOne = superEnumShell::getOnePubStrings();
	constexpr std::array<std::string_view, 4ULL>
		expectedFour = superEnumShell::getFourPubStrings();
	constexpr std::array<std::string_view, 6ULL>
		expectedSix = superEnumShell::getSixPubStrings();

	std::vector<std::string> expected;
	std::for_each(expectedOne.begin(), expectedOne.end(),
		[&expected](std::string_view val)
		{
			expected.emplace_back(val);
		});
	std::for_each(expectedFour.begin(), expectedFour.end(),
		[&expected](std::string_view val)
		{
			expected.emplace_back(val);
		});
	std::for_each(expectedSix.begin(), expectedSix.end(),
		[&expected](std::string_view val)
		{
			expected.emplace_back(val);
		});

	constexpr std::array<superEnumShell::OnePub, 1ULL>
		producedOne = superEnumShell::getOnePubEnums();
	constexpr std::array<superEnumShell::FourPub, 4ULL>
		producedFour = superEnumShell::getFourPubEnums();
	constexpr std::array<superEnumShell::SixPub, 6ULL>
		producedSix = superEnumShell::getSixPubEnums();

	std::stringstream ss;
	std::string line("");

	std::vector<std::string> produced;
	std::for_each(producedOne.begin(), producedOne.end(),
		[&produced, &ss, &line](superEnumShell::OnePub val)
		{
			ss = std::stringstream();
			line = "";
			ss << val;
			std::getline(ss, line);
			produced.emplace_back(line);
		});
	std::for_each(producedFour.begin(), producedFour.end(),
		[&produced, &ss, &line](superEnumShell::FourPub val)
		{
			ss = std::stringstream();
			line = "";
			ss << val;
			std::getline(ss, line);
			produced.emplace_back(line);
		});
	std::for_each(producedSix.begin(), producedSix.end(),
		[&produced, &ss, &line](superEnumShell::SixPub val)
		{
			ss = std::stringstream();
			line = "";
			ss << val;
			std::getline(ss, line);
			produced.emplace_back(line);
		});

	s_Tests.addTest(expected.size(), produced.size(),
		"Size Mismatch!");
	s_Tests.addBulkTests(expected, produced);

	return s_Tests.test();
}