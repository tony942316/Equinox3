#include "Workbench.hpp"

#include <fstream>
#include <random>
#include <cmath>
#include <cassert>
#include <array>
#include <vector>

#include "EquinoxSTD.hpp"

#include "UnitTest.hpp"

void test(std::string_view sv)
{
	std::cout << sv << std::endl;
}

void workbenchMain()
{
	std::cout << std::setprecision(100);
	std::cout << std::boolalpha;

	std::string str("HelloStdString");
	test("HelloCC*");
	test(str);

	std::cout << "End Workbench" << std::endl;
	std::cin.get();
}