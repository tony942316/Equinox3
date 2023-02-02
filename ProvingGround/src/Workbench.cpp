#include "Workbench.h"

#include <fstream>
#include <random>

#include "Benchmark.h"
#include "Random.h"

foo::foo()
	:
	x(nullptr),
	size(100'000ull)
{
	std::cout << "Default Construction" << std::endl;
	x = new int[size];
}

foo::foo(size_t s)
	:
	x(nullptr),
	size(s)
{
	std::cout << "Param Construction" << std::endl;
	x = new int[size];
}

foo::~foo()
{
	std::cout << "Destruction" << std::endl;
	delete[] x;
}

foo::foo(const foo& other)
	:
	x(nullptr),
	size(other.size)
{
	std::cout << "Copy Construction" << std::endl;
	x = new int[size];
	std::copy(other.x, other.x + size, x);
}

foo::foo(foo&& other) noexcept
	:
	x(other.x),
	size(other.size)
{
	std::cout << "Move Construction" << std::endl;
	other.x = nullptr;
	other.size = 0ull;
}

foo& foo::operator= (const foo& other)
{
	std::cout << "Copy Assignment" << std::endl;
	delete[] x;
	size = other.size;
	x = new int[size];
	return *this;
}

foo& foo::operator= (foo&& other) noexcept
{
	std::cout << "Move Assignment" << std::endl;
	delete[] x;
	size = other.size;
	x = other.x;
	other.x = nullptr;
	other.size = 0ull;
	return *this;
}

size_t foo::getSize()
{
	return size;
}

void foo::leak()
{
	x = nullptr;
}

//foo who::f;

void initContainer(std::vector<foo>& container, std::initializer_list<size_t>&& vals)
{
	std::cout << "Emplace Factory" << std::endl;
	container.reserve(vals.size());
	for (auto& val : vals)
	{
		container.emplace_back(val);
	}
}

void initContainer(std::vector<foo>& container, std::initializer_list<foo>&& vals)
{
	std::cout << "Move Factory" << std::endl;
	container.reserve(vals.size());
	for (const foo& val : vals)
	{
		container.emplace_back((foo&&)val);
	}
}

void testFunc()
{
	
}

void workbenchMain()
{
	std::mt19937_64 eng(0U);
	std::uniform_real_distribution<double> dist(std::numeric_limits<double>::lowest(), std::nexttoward(0.0, std::numeric_limits<double>::max()));
	std::cout << dist(eng) << std::endl;

	std::cin.get();
}