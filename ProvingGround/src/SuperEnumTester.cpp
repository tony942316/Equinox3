#include "SuperEnumTester.h"

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

#include "UnitTest.h"

bool SuperEnumTester::test()
{
	if (testGetTypes() &&
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

bool SuperEnumTester::testGetTypes()
{
	UnitTest<superEnumShell::OnePub, superEnumShell::OnePub> onePubTests;
	UnitTest<superEnumShell::FourPub, superEnumShell::FourPub> fourPubTests;
	UnitTest<superEnumShell::SixPub, superEnumShell::SixPub> sixPubTests;

	onePubTests.addExpectedValues({
		superEnumShell::OnePub::e1
	});
	onePubTests.addProducedValues({
		superEnumShell::OnePubGetTypes()
	});

	fourPubTests.addExpectedValues({
		superEnumShell::FourPub::e1,
		superEnumShell::FourPub::e2,
		superEnumShell::FourPub::e3,
		superEnumShell::FourPub::e4
	});
	fourPubTests.addProducedValues({
		superEnumShell::FourPubGetTypes()
	});

	sixPubTests.addExpectedValues({
		superEnumShell::SixPub::e1,
		superEnumShell::SixPub::e2,
		superEnumShell::SixPub::e3,
		superEnumShell::SixPub::e4,
		superEnumShell::SixPub::e5,
		superEnumShell::SixPub::e6
	});
	sixPubTests.addProducedValues({
		superEnumShell::SixPubGetTypes()
	});

	return 
		onePubTests.test() &&
		fourPubTests.test() &&
		sixPubTests.test();
}

bool SuperEnumTester::testToString()
{
	UnitTest<std::string, std::string> tests;

	tests.addExpectedValues({
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
	});

	tests.addProducedValues([&]() {
		std::vector<std::string> result;
		for (superEnumShell::OnePub val : superEnumShell::OnePubGetTypes())
		{
			result.emplace_back(superEnumShell::OnePubToString(val));
		}
		for (superEnumShell::FourPub val : superEnumShell::FourPubGetTypes())
		{
			result.emplace_back(superEnumShell::FourPubToString(val));
		}
		for (superEnumShell::SixPub val : superEnumShell::SixPubGetTypes())
		{
			result.emplace_back(superEnumShell::SixPubToString(val));
		}
		
		return result;
	});

	return tests.test();
}

bool SuperEnumTester::testStream()
{
	std::stringstream ss;
	std::string actual = "";

	UnitTest<std::string, std::string> tests;

	tests.addExpectedValues({
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
	});

	for (superEnumShell::OnePub val : superEnumShell::OnePubGetTypes())
	{
		ss << val;
		std::getline(ss, actual);
		ss.clear();
		tests.addProducedValue(actual);
		actual = "";
	}

	for (superEnumShell::FourPub val : superEnumShell::FourPubGetTypes())
	{
		ss << val;
		std::getline(ss, actual);
		ss.clear();
		tests.addProducedValue(actual);
		actual = "";
	}

	for (superEnumShell::SixPub val : superEnumShell::SixPubGetTypes())
	{
		ss << val;
		std::getline(ss, actual);
		ss.clear();
		tests.addProducedValue(actual);
		actual = "";
	}


	return tests.test();
}