/*
 * Copyright (C) 2023 Anthony H. Grasso
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "Workbench.hpp"

#include <algorithm>
#include <vector>
#include <chrono>
#include <unordered_map>
#include <map>
#include <list>
#include <array>
#include <iostream>
#include <iterator>
#include <string_view>
#include <type_traits>
#include <fstream>
#include <thread>
#include <memory>

#include "UnitTest.hpp"
#include "EquinoxSTD.hpp"

constexpr void func(const int& x)
{
	x;
}

void workbenchMain()
{
	std::cout << std::setprecision(100);
	std::cout << std::boolalpha;

	constexpr auto x = 10;
	func(x);

	std::cout << "End Workbench" << std::endl;
	std::cin.get();
}