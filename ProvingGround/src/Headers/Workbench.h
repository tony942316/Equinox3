#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

#include "SuperEnum.h"

class foo
{
public:

	EQX_SUPER_ENUM_3(bar, ar, ba, br)

	foo();
	foo(size_t s);
	~foo();
	foo(const foo& other);
	foo(foo&& other) noexcept;

	foo& operator= (const foo& other);
	foo& operator= (foo&& other) noexcept;

	size_t getSize();

	void leak();

private:
	int* x;
	size_t size;
};

class who
{
public:
	who() = delete;
	who(const who&) = delete;
	who(who&&) = delete;
	who& operator= (const who&) = delete;
	who& operator= (who&&) = delete;
	~who() = delete;

private:
	//static foo f;
};

void initContainer(std::vector<foo>& container, std::initializer_list<size_t>&& vals);
void initContainer(std::vector<foo>& container, std::initializer_list<foo>&& vals);

void workbenchMain();