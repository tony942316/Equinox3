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

#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

class foo
{
public:
	foo() noexcept
		:
		x(nullptr),
		size(100'000ull)
	{
		std::cout << "Default Construction" << std::endl;
		x = new int[size];
	}

	foo(size_t s) noexcept
		:
		x(nullptr),
		size(s)
	{
		std::cout << "Param Construction" << std::endl;
		x = new int[size];
	}

	foo& operator= (const foo& other)
	{
		std::cout << "Copy Assignment" << std::endl;
		delete[] x;
		size = other.size;
		x = new int[size];
		std::copy(other.x, other.x + size, x);
		return *this;
	}

	foo& operator= (foo&& other) noexcept
	{
		std::cout << "Move Assignment" << std::endl;
		delete[] x;
		size = other.size;
		x = other.x;
		other.x = nullptr;
		other.size = 0ull;
		return *this;
	}

	foo(const foo& other)
		:
		x(nullptr),
		size(other.size)
	{
		std::cout << "Copy Construction" << std::endl;
		x = new int[size];
		std::copy(other.x, other.x + size, x);
	}

	foo(foo&& other) noexcept
		:
		x(other.x),
		size(other.size)
	{
		std::cout << "Move Construction" << std::endl;
		other.x = nullptr;
		other.size = 0ull;
	}

	~foo() noexcept
	{
		std::cout << "Destruction" << std::endl;
		delete[] x;
	}

	void leak()
	{
		x = nullptr;
	}

	int* getX() const noexcept
	{
		return x;
	}

	size_t getSize() const noexcept
	{
		return size;
	}

private:
	int* x;
	size_t size;
};

void workbenchMain();