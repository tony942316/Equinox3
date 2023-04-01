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
#include <string>
#include <string_view>
#include <vector>
#include <list>
#include <forward_list>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>
#include <array>
#include <map>
#include <unordered_map>

#define ALL_PRIMITIVES char, wchar_t, char8_t, char16_t, char32_t, short,  \
    int, long, long long, unsigned short, unsigned int, unsigned long,  \
    unsigned long long, float, double, long double, volatile char,  \
    volatile wchar_t, volatile char8_t, volatile char16_t,  \
    volatile char32_t, volatile short, volatile int, volatile long,  \
    volatile long long, volatile unsigned short, volatile unsigned int,  \
    volatile unsigned long, volatile unsigned long long, volatile float,  \
    volatile double, volatile long double, const char, const wchar_t,  \
    const char8_t, const char16_t, const char32_t, const short, const int,  \
    const long, const long long, const unsigned short, const unsigned int,  \
    const unsigned long, const unsigned long long, const float,  \
    const double, const long double, const volatile char,  \
    const volatile wchar_t, const volatile char8_t, const volatile char16_t,  \
    const volatile char32_t, const volatile short, const volatile int,  \
    const volatile long, const volatile long long,  \
    const volatile unsigned short, const volatile unsigned int,  \
    const volatile unsigned long, const volatile unsigned long long

#define ALL_STD_STRINGS std::string, std::wstring, std::u8string,  \
    std::u16string, std::u32string, std::string_view, std::wstring_view,  \
    std::u8string_view, std::u16string_view, std::u32string_view,  \
    volatile std::string, volatile std::wstring, volatile std::u8string,  \
    volatile std::u16string, volatile std::u32string,  \
    volatile std::string_view, volatile std::wstring_view,  \
    volatile std::u8string_view, volatile std::u16string_view,  \
    volatile std::u32string_view, const std::string, const std::wstring,  \
    const std::u8string, const std::u16string, const std::u32string,  \
    const std::string_view, const std::wstring_view,  \
    const std::u8string_view, const std::u16string_view,  \
    const std::u32string_view, const volatile std::string,  \
    const volatile std::wstring, const volatile std::u8string,  \
    const volatile std::u16string, const volatile std::u32string,  \
    const volatile std::string_view, const volatile std::wstring_view,  \
    const volatile std::u8string_view, const volatile std::u16string_view

#define ALL_STD_RANGE_COLLECTIONS std::vector<char>, std::vector<wchar_t>,  \
    std::vector<char8_t>, std::vector<char16_t>, std::vector<char32_t>,  \
    std::vector<short>, std::vector<int>, std::vector<long>,  \
    std::vector<long long>, std::vector<unsigned short>,  \
    std::vector<unsigned int>, std::vector<unsigned long>,  \
    std::vector<unsigned long long>, std::vector<float>,  \
    std::vector<double>, std::vector<long double>,  \
    std::vector<volatile char>, std::vector<volatile wchar_t>,  \
    std::vector<volatile char8_t>, std::vector<volatile char16_t>,  \
    std::vector<volatile char32_t>, std::vector<volatile short>,  \
    std::vector<volatile int>, std::vector<volatile long>,  \
    std::vector<volatile long long>, std::vector<volatile unsigned short>,  \
    std::vector<volatile unsigned int>, std::vector<volatile unsigned long>,  \
    std::vector<volatile unsigned long long>, std::vector<volatile float>,  \
    std::vector<volatile double>, std::vector<volatile long double>,  \
    std::list<char>, std::list<wchar_t>, std::list<char8_t>,  \
    std::list<char16_t>, std::list<char32_t>, std::list<short>,  \
    std::list<int>, std::list<long>, std::list<long long>,  \
    std::list<unsigned short>, std::list<unsigned int>,  \
    std::list<unsigned long>, std::list<unsigned long long>,  \
    std::list<float>, std::list<double>, std::list<long double>,  \
    std::list<volatile char>, std::list<volatile wchar_t>,  \
    std::list<volatile char8_t>, std::list<volatile char16_t>,  \
    std::list<volatile char32_t>, std::list<volatile short>,  \
    std::list<volatile int>, std::list<volatile long>,  \
    std::list<volatile long long>, std::list<volatile unsigned short>,  \
    std::list<volatile unsigned int>, std::list<volatile unsigned long>,  \
    std::list<volatile unsigned long long>, std::list<volatile float>,  \
    std::list<volatile double>, std::list<volatile long double>,  \
    std::set<char>, std::set<wchar_t>, std::set<char8_t>,  \
    std::set<char16_t>, std::set<char32_t>, std::set<short>, std::set<int>,  \
    std::set<long>, std::set<long long>, std::set<unsigned short>,  \
    std::set<unsigned int>, std::set<unsigned long>,  \
    std::set<unsigned long long>, std::set<float>, std::set<double>,  \
    std::set<long double>, std::set<volatile char>,  \
    std::set<volatile wchar_t>, std::set<volatile char8_t>,  \
    std::set<volatile char16_t>, std::set<volatile char32_t>,  \
    std::set<volatile short>, std::set<volatile int>,  \
    std::set<volatile long>, std::set<volatile long long>,  \
    std::set<volatile unsigned short>, std::set<volatile unsigned int>,  \
    std::set<volatile unsigned long>, std::set<volatile unsigned long long>,  \
    std::set<volatile float>, std::set<volatile double>,  \
    std::set<volatile long double>, std::unordered_set<char>,  \
    std::unordered_set<wchar_t>, std::unordered_set<char8_t>,  \
    std::unordered_set<char16_t>, std::unordered_set<char32_t>,  \
    std::unordered_set<short>, std::unordered_set<int>,  \
    std::unordered_set<long>, std::unordered_set<long long>,  \
    std::unordered_set<unsigned short>, std::unordered_set<unsigned int>,  \
    std::unordered_set<unsigned long>,  \
    std::unordered_set<unsigned long long>, std::unordered_set<float>,  \
    std::unordered_set<double>, std::unordered_set<long double>,  \
    std::unordered_set<volatile char>, std::unordered_set<volatile wchar_t>,  \
    std::unordered_set<volatile char8_t>,  \
    std::unordered_set<volatile char16_t>,  \
    std::unordered_set<volatile char32_t>,  \
    std::unordered_set<volatile short>, std::unordered_set<volatile int>,  \
    std::unordered_set<volatile long>,  \
    std::unordered_set<volatile long long>,  \
    std::unordered_set<volatile unsigned short>,  \
    std::unordered_set<volatile unsigned int>,  \
    std::unordered_set<volatile unsigned long>,  \
    std::unordered_set<volatile unsigned long long>,  \
    std::unordered_set<volatile float>, std::unordered_set<volatile double>,  \
    std::unordered_set<volatile long double>, std::deque<char>,  \
    std::deque<wchar_t>, std::deque<char8_t>, std::deque<char16_t>,  \
    std::deque<char32_t>, std::deque<short>, std::deque<int>,  \
    std::deque<long>, std::deque<long long>, std::deque<unsigned short>,  \
    std::deque<unsigned int>, std::deque<unsigned long>,  \
    std::deque<unsigned long long>, std::deque<float>, std::deque<double>,  \
    std::deque<long double>, std::deque<volatile char>,  \
    std::deque<volatile wchar_t>, std::deque<volatile char8_t>,  \
    std::deque<volatile char16_t>, std::deque<volatile char32_t>,  \
    std::deque<volatile short>, std::deque<volatile int>,  \
    std::deque<volatile long>, std::deque<volatile long long>,  \
    std::deque<volatile unsigned short>, std::deque<volatile unsigned int>,  \
    std::deque<volatile unsigned long>,  \
    std::deque<volatile unsigned long long>, std::deque<volatile float>,  \
    std::deque<volatile double>, std::deque<volatile long double>,  \
    std::array<char, 1>, std::array<wchar_t, 1>, std::array<char8_t, 1>,  \
    std::array<char16_t, 1>, std::array<char32_t, 1>, std::array<short, 1>,  \
    std::array<int, 1>, std::array<long, 1>, std::array<long long, 1>,  \
    std::array<unsigned short, 1>, std::array<unsigned int, 1>,  \
    std::array<unsigned long, 1>, std::array<unsigned long long, 1>,  \
    std::array<float, 1>, std::array<double, 1>, std::array<long double, 1>,  \
    std::array<volatile char, 1>, std::array<volatile wchar_t, 1>,  \
    std::array<volatile char8_t, 1>, std::array<volatile char16_t, 1>,  \
    std::array<volatile char32_t, 1>, std::array<volatile short, 1>,  \
    std::array<volatile int, 1>, std::array<volatile long, 1>,  \
    std::array<volatile long long, 1>,  \
    std::array<volatile unsigned short, 1>,  \
    std::array<volatile unsigned int, 1>,  \
    std::array<volatile unsigned long, 1>,  \
    std::array<volatile unsigned long long, 1>,  \
    std::array<volatile float, 1>, std::array<volatile double, 1>,  \
    std::array<volatile long double, 1>, std::array<char, 2>,  \
    std::array<wchar_t, 2>, std::array<char8_t, 2>, std::array<char16_t, 2>,  \
    std::array<char32_t, 2>, std::array<short, 2>, std::array<int, 2>,  \
    std::array<long, 2>, std::array<long long, 2>,  \
    std::array<unsigned short, 2>, std::array<unsigned int, 2>,  \
    std::array<unsigned long, 2>, std::array<unsigned long long, 2>,  \
    std::array<float, 2>, std::array<double, 2>, std::array<long double, 2>,  \
    std::array<volatile char, 2>, std::array<volatile wchar_t, 2>,  \
    std::array<volatile char8_t, 2>, std::array<volatile char16_t, 2>,  \
    std::array<volatile char32_t, 2>, std::array<volatile short, 2>,  \
    std::array<volatile int, 2>, std::array<volatile long, 2>,  \
    std::array<volatile long long, 2>,  \
    std::array<volatile unsigned short, 2>,  \
    std::array<volatile unsigned int, 2>,  \
    std::array<volatile unsigned long, 2>,  \
    std::array<volatile unsigned long long, 2>,  \
    std::array<volatile float, 2>, std::array<volatile double, 2>,  \
    std::array<volatile long double, 2>, std::array<char, 3>,  \
    std::array<wchar_t, 3>, std::array<char8_t, 3>, std::array<char16_t, 3>,  \
    std::array<char32_t, 3>, std::array<short, 3>, std::array<int, 3>,  \
    std::array<long, 3>, std::array<long long, 3>,  \
    std::array<unsigned short, 3>, std::array<unsigned int, 3>,  \
    std::array<unsigned long, 3>, std::array<unsigned long long, 3>,  \
    std::array<float, 3>, std::array<double, 3>, std::array<long double, 3>,  \
    std::array<volatile char, 3>, std::array<volatile wchar_t, 3>,  \
    std::array<volatile char8_t, 3>, std::array<volatile char16_t, 3>,  \
    std::array<volatile char32_t, 3>, std::array<volatile short, 3>,  \
    std::array<volatile int, 3>, std::array<volatile long, 3>,  \
    std::array<volatile long long, 3>,  \
    std::array<volatile unsigned short, 3>,  \
    std::array<volatile unsigned int, 3>,  \
    std::array<volatile unsigned long, 3>,  \
    std::array<volatile unsigned long long, 3>,  \
    std::array<volatile float, 3>, std::array<volatile double, 3>,  \
    std::array<volatile long double, 3>, std::array<char, 4>,  \
    std::array<wchar_t, 4>, std::array<char8_t, 4>, std::array<char16_t, 4>,  \
    std::array<char32_t, 4>, std::array<short, 4>, std::array<int, 4>,  \
    std::array<long, 4>, std::array<long long, 4>,  \
    std::array<unsigned short, 4>, std::array<unsigned int, 4>,  \
    std::array<unsigned long, 4>, std::array<unsigned long long, 4>,  \
    std::array<float, 4>, std::array<double, 4>, std::array<long double, 4>,  \
    std::array<volatile char, 4>, std::array<volatile wchar_t, 4>,  \
    std::array<volatile char8_t, 4>, std::array<volatile char16_t, 4>,  \
    std::array<volatile char32_t, 4>, std::array<volatile short, 4>,  \
    std::array<volatile int, 4>, std::array<volatile long, 4>,  \
    std::array<volatile long long, 4>,  \
    std::array<volatile unsigned short, 4>,  \
    std::array<volatile unsigned int, 4>,  \
    std::array<volatile unsigned long, 4>,  \
    std::array<volatile unsigned long long, 4>,  \
    std::array<volatile float, 4>, std::array<volatile double, 4>,  \
    std::array<volatile long double, 4>, std::array<char, 5>,  \
    std::array<wchar_t, 5>, std::array<char8_t, 5>, std::array<char16_t, 5>,  \
    std::array<char32_t, 5>, std::array<short, 5>, std::array<int, 5>,  \
    std::array<long, 5>, std::array<long long, 5>,  \
    std::array<unsigned short, 5>, std::array<unsigned int, 5>,  \
    std::array<unsigned long, 5>, std::array<unsigned long long, 5>,  \
    std::array<float, 5>, std::array<double, 5>, std::array<long double, 5>,  \
    std::array<volatile char, 5>, std::array<volatile wchar_t, 5>,  \
    std::array<volatile char8_t, 5>, std::array<volatile char16_t, 5>,  \
    std::array<volatile char32_t, 5>, std::array<volatile short, 5>,  \
    std::array<volatile int, 5>, std::array<volatile long, 5>,  \
    std::array<volatile long long, 5>,  \
    std::array<volatile unsigned short, 5>,  \
    std::array<volatile unsigned int, 5>,  \
    std::array<volatile unsigned long, 5>,  \
    std::array<volatile unsigned long long, 5>,  \
    std::array<volatile float, 5>, std::array<volatile double, 5>,  \
    std::array<volatile long double, 5>, std::array<char, 6>,  \
    std::array<wchar_t, 6>, std::array<char8_t, 6>, std::array<char16_t, 6>,  \
    std::array<char32_t, 6>, std::array<short, 6>, std::array<int, 6>,  \
    std::array<long, 6>, std::array<long long, 6>,  \
    std::array<unsigned short, 6>, std::array<unsigned int, 6>,  \
    std::array<unsigned long, 6>, std::array<unsigned long long, 6>,  \
    std::array<float, 6>, std::array<double, 6>, std::array<long double, 6>,  \
    std::array<volatile char, 6>, std::array<volatile wchar_t, 6>,  \
    std::array<volatile char8_t, 6>, std::array<volatile char16_t, 6>,  \
    std::array<volatile char32_t, 6>, std::array<volatile short, 6>,  \
    std::array<volatile int, 6>, std::array<volatile long, 6>,  \
    std::array<volatile long long, 6>,  \
    std::array<volatile unsigned short, 6>,  \
    std::array<volatile unsigned int, 6>,  \
    std::array<volatile unsigned long, 6>,  \
    std::array<volatile unsigned long long, 6>,  \
    std::array<volatile float, 6>, std::array<volatile double, 6>,  \
    std::array<volatile long double, 6>, std::array<char, 7>,  \
    std::array<wchar_t, 7>, std::array<char8_t, 7>, std::array<char16_t, 7>,  \
    std::array<char32_t, 7>, std::array<short, 7>, std::array<int, 7>,  \
    std::array<long, 7>, std::array<long long, 7>,  \
    std::array<unsigned short, 7>, std::array<unsigned int, 7>,  \
    std::array<unsigned long, 7>, std::array<unsigned long long, 7>,  \
    std::array<float, 7>, std::array<double, 7>, std::array<long double, 7>,  \
    std::array<volatile char, 7>, std::array<volatile wchar_t, 7>,  \
    std::array<volatile char8_t, 7>, std::array<volatile char16_t, 7>,  \
    std::array<volatile char32_t, 7>, std::array<volatile short, 7>,  \
    std::array<volatile int, 7>, std::array<volatile long, 7>,  \
    std::array<volatile long long, 7>,  \
    std::array<volatile unsigned short, 7>,  \
    std::array<volatile unsigned int, 7>,  \
    std::array<volatile unsigned long, 7>,  \
    std::array<volatile unsigned long long, 7>,  \
    std::array<volatile float, 7>, std::array<volatile double, 7>,  \
    std::array<volatile long double, 7>, std::array<char, 8>,  \
    std::array<wchar_t, 8>, std::array<char8_t, 8>, std::array<char16_t, 8>,  \
    std::array<char32_t, 8>, std::array<short, 8>, std::array<int, 8>,  \
    std::array<long, 8>, std::array<long long, 8>,  \
    std::array<unsigned short, 8>, std::array<unsigned int, 8>,  \
    std::array<unsigned long, 8>, std::array<unsigned long long, 8>,  \
    std::array<float, 8>, std::array<double, 8>, std::array<long double, 8>,  \
    std::array<volatile char, 8>, std::array<volatile wchar_t, 8>,  \
    std::array<volatile char8_t, 8>, std::array<volatile char16_t, 8>,  \
    std::array<volatile char32_t, 8>, std::array<volatile short, 8>,  \
    std::array<volatile int, 8>, std::array<volatile long, 8>,  \
    std::array<volatile long long, 8>,  \
    std::array<volatile unsigned short, 8>,  \
    std::array<volatile unsigned int, 8>,  \
    std::array<volatile unsigned long, 8>,  \
    std::array<volatile unsigned long long, 8>,  \
    std::array<volatile float, 8>, std::array<volatile double, 8>,  \
    std::array<volatile long double, 8>, std::array<char, 9>,  \
    std::array<wchar_t, 9>, std::array<char8_t, 9>, std::array<char16_t, 9>,  \
    std::array<char32_t, 9>, std::array<short, 9>, std::array<int, 9>,  \
    std::array<long, 9>, std::array<long long, 9>,  \
    std::array<unsigned short, 9>, std::array<unsigned int, 9>,  \
    std::array<unsigned long, 9>, std::array<unsigned long long, 9>,  \
    std::array<float, 9>, std::array<double, 9>, std::array<long double, 9>,  \
    std::array<volatile char, 9>, std::array<volatile wchar_t, 9>,  \
    std::array<volatile char8_t, 9>, std::array<volatile char16_t, 9>,  \
    std::array<volatile char32_t, 9>, std::array<volatile short, 9>,  \
    std::array<volatile int, 9>, std::array<volatile long, 9>,  \
    std::array<volatile long long, 9>,  \
    std::array<volatile unsigned short, 9>,  \
    std::array<volatile unsigned int, 9>,  \
    std::array<volatile unsigned long, 9>,  \
    std::array<volatile unsigned long long, 9>,  \
    std::array<volatile float, 9>, std::array<volatile double, 9>,  \
    std::array<volatile long double, 9>, std::array<char, 10>,  \
    std::array<wchar_t, 10>, std::array<char8_t, 10>,  \
    std::array<char16_t, 10>, std::array<char32_t, 10>,  \
    std::array<short, 10>, std::array<int, 10>, std::array<long, 10>,  \
    std::array<long long, 10>, std::array<unsigned short, 10>,  \
    std::array<unsigned int, 10>, std::array<unsigned long, 10>,  \
    std::array<unsigned long long, 10>, std::array<float, 10>,  \
    std::array<double, 10>, std::array<long double, 10>,  \
    std::array<volatile char, 10>, std::array<volatile wchar_t, 10>,  \
    std::array<volatile char8_t, 10>, std::array<volatile char16_t, 10>,  \
    std::array<volatile char32_t, 10>, std::array<volatile short, 10>,  \
    std::array<volatile int, 10>, std::array<volatile long, 10>,  \
    std::array<volatile long long, 10>,  \
    std::array<volatile unsigned short, 10>,  \
    std::array<volatile unsigned int, 10>,  \
    std::array<volatile unsigned long, 10>,  \
    std::array<volatile unsigned long long, 10>,  \
    std::array<volatile float, 10>, std::array<volatile double, 10>,  \
    std::array<volatile long double, 10>, std::array<char, 11>,  \
    std::array<wchar_t, 11>, std::array<char8_t, 11>,  \
    std::array<char16_t, 11>, std::array<char32_t, 11>,  \
    std::array<short, 11>, std::array<int, 11>, std::array<long, 11>,  \
    std::array<long long, 11>, std::array<unsigned short, 11>,  \
    std::array<unsigned int, 11>, std::array<unsigned long, 11>,  \
    std::array<unsigned long long, 11>, std::array<float, 11>,  \
    std::array<double, 11>, std::array<long double, 11>,  \
    std::array<volatile char, 11>, std::array<volatile wchar_t, 11>,  \
    std::array<volatile char8_t, 11>, std::array<volatile char16_t, 11>,  \
    std::array<volatile char32_t, 11>, std::array<volatile short, 11>,  \
    std::array<volatile int, 11>, std::array<volatile long, 11>,  \
    std::array<volatile long long, 11>,  \
    std::array<volatile unsigned short, 11>,  \
    std::array<volatile unsigned int, 11>,  \
    std::array<volatile unsigned long, 11>,  \
    std::array<volatile unsigned long long, 11>,  \
    std::array<volatile float, 11>, std::array<volatile double, 11>,  \
    std::array<volatile long double, 11>, std::array<char, 12>,  \
    std::array<wchar_t, 12>, std::array<char8_t, 12>,  \
    std::array<char16_t, 12>, std::array<char32_t, 12>,  \
    std::array<short, 12>, std::array<int, 12>, std::array<long, 12>,  \
    std::array<long long, 12>, std::array<unsigned short, 12>,  \
    std::array<unsigned int, 12>, std::array<unsigned long, 12>,  \
    std::array<unsigned long long, 12>, std::array<float, 12>,  \
    std::array<double, 12>, std::array<long double, 12>,  \
    std::array<volatile char, 12>, std::array<volatile wchar_t, 12>,  \
    std::array<volatile char8_t, 12>, std::array<volatile char16_t, 12>,  \
    std::array<volatile char32_t, 12>, std::array<volatile short, 12>,  \
    std::array<volatile int, 12>, std::array<volatile long, 12>,  \
    std::array<volatile long long, 12>,  \
    std::array<volatile unsigned short, 12>,  \
    std::array<volatile unsigned int, 12>,  \
    std::array<volatile unsigned long, 12>,  \
    std::array<volatile unsigned long long, 12>,  \
    std::array<volatile float, 12>, std::array<volatile double, 12>,  \
    std::array<volatile long double, 12>, std::array<char, 13>,  \
    std::array<wchar_t, 13>, std::array<char8_t, 13>,  \
    std::array<char16_t, 13>, std::array<char32_t, 13>,  \
    std::array<short, 13>, std::array<int, 13>, std::array<long, 13>,  \
    std::array<long long, 13>, std::array<unsigned short, 13>,  \
    std::array<unsigned int, 13>, std::array<unsigned long, 13>,  \
    std::array<unsigned long long, 13>, std::array<float, 13>,  \
    std::array<double, 13>, std::array<long double, 13>,  \
    std::array<volatile char, 13>, std::array<volatile wchar_t, 13>,  \
    std::array<volatile char8_t, 13>, std::array<volatile char16_t, 13>,  \
    std::array<volatile char32_t, 13>, std::array<volatile short, 13>,  \
    std::array<volatile int, 13>, std::array<volatile long, 13>,  \
    std::array<volatile long long, 13>,  \
    std::array<volatile unsigned short, 13>,  \
    std::array<volatile unsigned int, 13>,  \
    std::array<volatile unsigned long, 13>,  \
    std::array<volatile unsigned long long, 13>,  \
    std::array<volatile float, 13>, std::array<volatile double, 13>,  \
    std::array<volatile long double, 13>, std::array<char, 14>,  \
    std::array<wchar_t, 14>, std::array<char8_t, 14>,  \
    std::array<char16_t, 14>, std::array<char32_t, 14>,  \
    std::array<short, 14>, std::array<int, 14>, std::array<long, 14>,  \
    std::array<long long, 14>, std::array<unsigned short, 14>,  \
    std::array<unsigned int, 14>, std::array<unsigned long, 14>,  \
    std::array<unsigned long long, 14>, std::array<float, 14>,  \
    std::array<double, 14>, std::array<long double, 14>,  \
    std::array<volatile char, 14>, std::array<volatile wchar_t, 14>,  \
    std::array<volatile char8_t, 14>, std::array<volatile char16_t, 14>,  \
    std::array<volatile char32_t, 14>, std::array<volatile short, 14>,  \
    std::array<volatile int, 14>, std::array<volatile long, 14>,  \
    std::array<volatile long long, 14>,  \
    std::array<volatile unsigned short, 14>,  \
    std::array<volatile unsigned int, 14>,  \
    std::array<volatile unsigned long, 14>,  \
    std::array<volatile unsigned long long, 14>,  \
    std::array<volatile float, 14>, std::array<volatile double, 14>,  \
    std::array<volatile long double, 14>, std::array<char, 15>,  \
    std::array<wchar_t, 15>, std::array<char8_t, 15>,  \
    std::array<char16_t, 15>, std::array<char32_t, 15>,  \
    std::array<short, 15>, std::array<int, 15>, std::array<long, 15>,  \
    std::array<long long, 15>, std::array<unsigned short, 15>,  \
    std::array<unsigned int, 15>, std::array<unsigned long, 15>,  \
    std::array<unsigned long long, 15>, std::array<float, 15>,  \
    std::array<double, 15>, std::array<long double, 15>,  \
    std::array<volatile char, 15>, std::array<volatile wchar_t, 15>,  \
    std::array<volatile char8_t, 15>, std::array<volatile char16_t, 15>,  \
    std::array<volatile char32_t, 15>, std::array<volatile short, 15>,  \
    std::array<volatile int, 15>, std::array<volatile long, 15>,  \
    std::array<volatile long long, 15>,  \
    std::array<volatile unsigned short, 15>,  \
    std::array<volatile unsigned int, 15>,  \
    std::array<volatile unsigned long, 15>,  \
    std::array<volatile unsigned long long, 15>,  \
    std::array<volatile float, 15>, std::array<volatile double, 15>,  \
    std::array<volatile long double, 15>, std::array<char, 16>,  \
    std::array<wchar_t, 16>, std::array<char8_t, 16>,  \
    std::array<char16_t, 16>, std::array<char32_t, 16>,  \
    std::array<short, 16>, std::array<int, 16>, std::array<long, 16>,  \
    std::array<long long, 16>, std::array<unsigned short, 16>,  \
    std::array<unsigned int, 16>, std::array<unsigned long, 16>,  \
    std::array<unsigned long long, 16>, std::array<float, 16>,  \
    std::array<double, 16>, std::array<long double, 16>,  \
    std::array<volatile char, 16>, std::array<volatile wchar_t, 16>,  \
    std::array<volatile char8_t, 16>, std::array<volatile char16_t, 16>,  \
    std::array<volatile char32_t, 16>, std::array<volatile short, 16>,  \
    std::array<volatile int, 16>, std::array<volatile long, 16>,  \
    std::array<volatile long long, 16>,  \
    std::array<volatile unsigned short, 16>,  \
    std::array<volatile unsigned int, 16>,  \
    std::array<volatile unsigned long, 16>,  \
    std::array<volatile unsigned long long, 16>,  \
    std::array<volatile float, 16>, std::array<volatile double, 16>,  \
    std::array<volatile long double, 16>, std::array<char, 17>,  \
    std::array<wchar_t, 17>, std::array<char8_t, 17>,  \
    std::array<char16_t, 17>, std::array<char32_t, 17>,  \
    std::array<short, 17>, std::array<int, 17>, std::array<long, 17>,  \
    std::array<long long, 17>, std::array<unsigned short, 17>,  \
    std::array<unsigned int, 17>, std::array<unsigned long, 17>,  \
    std::array<unsigned long long, 17>, std::array<float, 17>,  \
    std::array<double, 17>, std::array<long double, 17>,  \
    std::array<volatile char, 17>, std::array<volatile wchar_t, 17>,  \
    std::array<volatile char8_t, 17>, std::array<volatile char16_t, 17>,  \
    std::array<volatile char32_t, 17>, std::array<volatile short, 17>,  \
    std::array<volatile int, 17>, std::array<volatile long, 17>,  \
    std::array<volatile long long, 17>,  \
    std::array<volatile unsigned short, 17>,  \
    std::array<volatile unsigned int, 17>,  \
    std::array<volatile unsigned long, 17>,  \
    std::array<volatile unsigned long long, 17>,  \
    std::array<volatile float, 17>, std::array<volatile double, 17>,  \
    std::array<volatile long double, 17>, std::array<char, 18>,  \
    std::array<wchar_t, 18>, std::array<char8_t, 18>,  \
    std::array<char16_t, 18>, std::array<char32_t, 18>,  \
    std::array<short, 18>, std::array<int, 18>, std::array<long, 18>,  \
    std::array<long long, 18>, std::array<unsigned short, 18>,  \
    std::array<unsigned int, 18>, std::array<unsigned long, 18>,  \
    std::array<unsigned long long, 18>, std::array<float, 18>,  \
    std::array<double, 18>, std::array<long double, 18>,  \
    std::array<volatile char, 18>, std::array<volatile wchar_t, 18>,  \
    std::array<volatile char8_t, 18>, std::array<volatile char16_t, 18>,  \
    std::array<volatile char32_t, 18>, std::array<volatile short, 18>,  \
    std::array<volatile int, 18>, std::array<volatile long, 18>,  \
    std::array<volatile long long, 18>,  \
    std::array<volatile unsigned short, 18>,  \
    std::array<volatile unsigned int, 18>,  \
    std::array<volatile unsigned long, 18>,  \
    std::array<volatile unsigned long long, 18>,  \
    std::array<volatile float, 18>, std::array<volatile double, 18>,  \
    std::array<volatile long double, 18>, std::array<char, 19>,  \
    std::array<wchar_t, 19>, std::array<char8_t, 19>,  \
    std::array<char16_t, 19>, std::array<char32_t, 19>,  \
    std::array<short, 19>, std::array<int, 19>, std::array<long, 19>,  \
    std::array<long long, 19>, std::array<unsigned short, 19>,  \
    std::array<unsigned int, 19>, std::array<unsigned long, 19>,  \
    std::array<unsigned long long, 19>, std::array<float, 19>,  \
    std::array<double, 19>, std::array<long double, 19>,  \
    std::array<volatile char, 19>, std::array<volatile wchar_t, 19>,  \
    std::array<volatile char8_t, 19>, std::array<volatile char16_t, 19>,  \
    std::array<volatile char32_t, 19>, std::array<volatile short, 19>,  \
    std::array<volatile int, 19>, std::array<volatile long, 19>,  \
    std::array<volatile long long, 19>,  \
    std::array<volatile unsigned short, 19>,  \
    std::array<volatile unsigned int, 19>,  \
    std::array<volatile unsigned long, 19>,  \
    std::array<volatile unsigned long long, 19>,  \
    std::array<volatile float, 19>, std::array<volatile double, 19>,  \
    std::array<volatile long double, 19>, std::array<char, 20>,  \
    std::array<wchar_t, 20>, std::array<char8_t, 20>,  \
    std::array<char16_t, 20>, std::array<char32_t, 20>,  \
    std::array<short, 20>, std::array<int, 20>, std::array<long, 20>,  \
    std::array<long long, 20>, std::array<unsigned short, 20>,  \
    std::array<unsigned int, 20>, std::array<unsigned long, 20>,  \
    std::array<unsigned long long, 20>, std::array<float, 20>,  \
    std::array<double, 20>, std::array<long double, 20>,  \
    std::array<volatile char, 20>, std::array<volatile wchar_t, 20>,  \
    std::array<volatile char8_t, 20>, std::array<volatile char16_t, 20>,  \
    std::array<volatile char32_t, 20>, std::array<volatile short, 20>,  \
    std::array<volatile int, 20>, std::array<volatile long, 20>,  \
    std::array<volatile long long, 20>,  \
    std::array<volatile unsigned short, 20>,  \
    std::array<volatile unsigned int, 20>,  \
    std::array<volatile unsigned long, 20>,  \
    std::array<volatile unsigned long long, 20>,  \
    std::array<volatile float, 20>, std::array<volatile double, 20>,  \
    std::array<volatile long double, 20>, std::array<char, 21>,  \
    std::array<wchar_t, 21>, std::array<char8_t, 21>,  \
    std::array<char16_t, 21>, std::array<char32_t, 21>,  \
    std::array<short, 21>, std::array<int, 21>, std::array<long, 21>,  \
    std::array<long long, 21>, std::array<unsigned short, 21>,  \
    std::array<unsigned int, 21>, std::array<unsigned long, 21>,  \
    std::array<unsigned long long, 21>, std::array<float, 21>,  \
    std::array<double, 21>, std::array<long double, 21>,  \
    std::array<volatile char, 21>, std::array<volatile wchar_t, 21>,  \
    std::array<volatile char8_t, 21>, std::array<volatile char16_t, 21>,  \
    std::array<volatile char32_t, 21>, std::array<volatile short, 21>,  \
    std::array<volatile int, 21>, std::array<volatile long, 21>,  \
    std::array<volatile long long, 21>,  \
    std::array<volatile unsigned short, 21>,  \
    std::array<volatile unsigned int, 21>,  \
    std::array<volatile unsigned long, 21>,  \
    std::array<volatile unsigned long long, 21>,  \
    std::array<volatile float, 21>, std::array<volatile double, 21>,  \
    std::array<volatile long double, 21>, std::array<char, 22>,  \
    std::array<wchar_t, 22>, std::array<char8_t, 22>,  \
    std::array<char16_t, 22>, std::array<char32_t, 22>,  \
    std::array<short, 22>, std::array<int, 22>, std::array<long, 22>,  \
    std::array<long long, 22>, std::array<unsigned short, 22>,  \
    std::array<unsigned int, 22>, std::array<unsigned long, 22>,  \
    std::array<unsigned long long, 22>, std::array<float, 22>,  \
    std::array<double, 22>, std::array<long double, 22>,  \
    std::array<volatile char, 22>, std::array<volatile wchar_t, 22>,  \
    std::array<volatile char8_t, 22>, std::array<volatile char16_t, 22>,  \
    std::array<volatile char32_t, 22>, std::array<volatile short, 22>,  \
    std::array<volatile int, 22>, std::array<volatile long, 22>,  \
    std::array<volatile long long, 22>,  \
    std::array<volatile unsigned short, 22>,  \
    std::array<volatile unsigned int, 22>,  \
    std::array<volatile unsigned long, 22>,  \
    std::array<volatile unsigned long long, 22>,  \
    std::array<volatile float, 22>, std::array<volatile double, 22>,  \
    std::array<volatile long double, 22>, std::array<char, 23>,  \
    std::array<wchar_t, 23>, std::array<char8_t, 23>,  \
    std::array<char16_t, 23>, std::array<char32_t, 23>,  \
    std::array<short, 23>, std::array<int, 23>, std::array<long, 23>,  \
    std::array<long long, 23>, std::array<unsigned short, 23>,  \
    std::array<unsigned int, 23>, std::array<unsigned long, 23>,  \
    std::array<unsigned long long, 23>, std::array<float, 23>,  \
    std::array<double, 23>, std::array<long double, 23>,  \
    std::array<volatile char, 23>, std::array<volatile wchar_t, 23>,  \
    std::array<volatile char8_t, 23>, std::array<volatile char16_t, 23>,  \
    std::array<volatile char32_t, 23>, std::array<volatile short, 23>,  \
    std::array<volatile int, 23>, std::array<volatile long, 23>,  \
    std::array<volatile long long, 23>,  \
    std::array<volatile unsigned short, 23>,  \
    std::array<volatile unsigned int, 23>,  \
    std::array<volatile unsigned long, 23>,  \
    std::array<volatile unsigned long long, 23>,  \
    std::array<volatile float, 23>, std::array<volatile double, 23>,  \
    std::array<volatile long double, 23>, std::array<char, 24>,  \
    std::array<wchar_t, 24>, std::array<char8_t, 24>,  \
    std::array<char16_t, 24>, std::array<char32_t, 24>,  \
    std::array<short, 24>, std::array<int, 24>, std::array<long, 24>,  \
    std::array<long long, 24>, std::array<unsigned short, 24>,  \
    std::array<unsigned int, 24>, std::array<unsigned long, 24>,  \
    std::array<unsigned long long, 24>, std::array<float, 24>,  \
    std::array<double, 24>, std::array<long double, 24>,  \
    std::array<volatile char, 24>, std::array<volatile wchar_t, 24>,  \
    std::array<volatile char8_t, 24>, std::array<volatile char16_t, 24>,  \
    std::array<volatile char32_t, 24>, std::array<volatile short, 24>,  \
    std::array<volatile int, 24>, std::array<volatile long, 24>,  \
    std::array<volatile long long, 24>,  \
    std::array<volatile unsigned short, 24>,  \
    std::array<volatile unsigned int, 24>,  \
    std::array<volatile unsigned long, 24>,  \
    std::array<volatile unsigned long long, 24>,  \
    std::array<volatile float, 24>, std::array<volatile double, 24>,  \
    std::array<volatile long double, 24>, std::array<char, 25>,  \
    std::array<wchar_t, 25>, std::array<char8_t, 25>,  \
    std::array<char16_t, 25>, std::array<char32_t, 25>,  \
    std::array<short, 25>, std::array<int, 25>, std::array<long, 25>,  \
    std::array<long long, 25>, std::array<unsigned short, 25>,  \
    std::array<unsigned int, 25>, std::array<unsigned long, 25>,  \
    std::array<unsigned long long, 25>, std::array<float, 25>,  \
    std::array<double, 25>, std::array<long double, 25>,  \
    std::array<volatile char, 25>, std::array<volatile wchar_t, 25>,  \
    std::array<volatile char8_t, 25>, std::array<volatile char16_t, 25>,  \
    std::array<volatile char32_t, 25>, std::array<volatile short, 25>,  \
    std::array<volatile int, 25>, std::array<volatile long, 25>,  \
    std::array<volatile long long, 25>,  \
    std::array<volatile unsigned short, 25>,  \
    std::array<volatile unsigned int, 25>,  \
    std::array<volatile unsigned long, 25>,  \
    std::array<volatile unsigned long long, 25>,  \
    std::array<volatile float, 25>, std::array<volatile double, 25>,  \
    std::array<volatile long double, 25>, std::array<char, 26>,  \
    std::array<wchar_t, 26>, std::array<char8_t, 26>,  \
    std::array<char16_t, 26>, std::array<char32_t, 26>,  \
    std::array<short, 26>, std::array<int, 26>, std::array<long, 26>,  \
    std::array<long long, 26>, std::array<unsigned short, 26>,  \
    std::array<unsigned int, 26>, std::array<unsigned long, 26>,  \
    std::array<unsigned long long, 26>, std::array<float, 26>,  \
    std::array<double, 26>, std::array<long double, 26>,  \
    std::array<volatile char, 26>, std::array<volatile wchar_t, 26>,  \
    std::array<volatile char8_t, 26>, std::array<volatile char16_t, 26>,  \
    std::array<volatile char32_t, 26>, std::array<volatile short, 26>,  \
    std::array<volatile int, 26>, std::array<volatile long, 26>,  \
    std::array<volatile long long, 26>,  \
    std::array<volatile unsigned short, 26>,  \
    std::array<volatile unsigned int, 26>,  \
    std::array<volatile unsigned long, 26>,  \
    std::array<volatile unsigned long long, 26>,  \
    std::array<volatile float, 26>, std::array<volatile double, 26>,  \
    std::array<volatile long double, 26>, std::array<char, 27>,  \
    std::array<wchar_t, 27>, std::array<char8_t, 27>,  \
    std::array<char16_t, 27>, std::array<char32_t, 27>,  \
    std::array<short, 27>, std::array<int, 27>, std::array<long, 27>,  \
    std::array<long long, 27>, std::array<unsigned short, 27>,  \
    std::array<unsigned int, 27>, std::array<unsigned long, 27>,  \
    std::array<unsigned long long, 27>, std::array<float, 27>,  \
    std::array<double, 27>, std::array<long double, 27>,  \
    std::array<volatile char, 27>, std::array<volatile wchar_t, 27>,  \
    std::array<volatile char8_t, 27>, std::array<volatile char16_t, 27>,  \
    std::array<volatile char32_t, 27>, std::array<volatile short, 27>,  \
    std::array<volatile int, 27>, std::array<volatile long, 27>,  \
    std::array<volatile long long, 27>,  \
    std::array<volatile unsigned short, 27>,  \
    std::array<volatile unsigned int, 27>,  \
    std::array<volatile unsigned long, 27>,  \
    std::array<volatile unsigned long long, 27>,  \
    std::array<volatile float, 27>, std::array<volatile double, 27>,  \
    std::array<volatile long double, 27>, std::array<char, 28>,  \
    std::array<wchar_t, 28>, std::array<char8_t, 28>,  \
    std::array<char16_t, 28>, std::array<char32_t, 28>,  \
    std::array<short, 28>, std::array<int, 28>, std::array<long, 28>,  \
    std::array<long long, 28>, std::array<unsigned short, 28>,  \
    std::array<unsigned int, 28>, std::array<unsigned long, 28>,  \
    std::array<unsigned long long, 28>, std::array<float, 28>,  \
    std::array<double, 28>, std::array<long double, 28>,  \
    std::array<volatile char, 28>, std::array<volatile wchar_t, 28>,  \
    std::array<volatile char8_t, 28>, std::array<volatile char16_t, 28>,  \
    std::array<volatile char32_t, 28>, std::array<volatile short, 28>,  \
    std::array<volatile int, 28>, std::array<volatile long, 28>,  \
    std::array<volatile long long, 28>,  \
    std::array<volatile unsigned short, 28>,  \
    std::array<volatile unsigned int, 28>,  \
    std::array<volatile unsigned long, 28>,  \
    std::array<volatile unsigned long long, 28>,  \
    std::array<volatile float, 28>, std::array<volatile double, 28>,  \
    std::array<volatile long double, 28>, std::array<char, 29>,  \
    std::array<wchar_t, 29>, std::array<char8_t, 29>,  \
    std::array<char16_t, 29>, std::array<char32_t, 29>,  \
    std::array<short, 29>, std::array<int, 29>, std::array<long, 29>,  \
    std::array<long long, 29>, std::array<unsigned short, 29>,  \
    std::array<unsigned int, 29>, std::array<unsigned long, 29>,  \
    std::array<unsigned long long, 29>, std::array<float, 29>,  \
    std::array<double, 29>, std::array<long double, 29>,  \
    std::array<volatile char, 29>, std::array<volatile wchar_t, 29>,  \
    std::array<volatile char8_t, 29>, std::array<volatile char16_t, 29>,  \
    std::array<volatile char32_t, 29>, std::array<volatile short, 29>,  \
    std::array<volatile int, 29>, std::array<volatile long, 29>,  \
    std::array<volatile long long, 29>,  \
    std::array<volatile unsigned short, 29>,  \
    std::array<volatile unsigned int, 29>,  \
    std::array<volatile unsigned long, 29>,  \
    std::array<volatile unsigned long long, 29>,  \
    std::array<volatile float, 29>, std::array<volatile double, 29>,  \
    std::array<volatile long double, 29>, std::array<char, 30>,  \
    std::array<wchar_t, 30>, std::array<char8_t, 30>,  \
    std::array<char16_t, 30>, std::array<char32_t, 30>,  \
    std::array<short, 30>, std::array<int, 30>, std::array<long, 30>,  \
    std::array<long long, 30>, std::array<unsigned short, 30>,  \
    std::array<unsigned int, 30>, std::array<unsigned long, 30>,  \
    std::array<unsigned long long, 30>, std::array<float, 30>,  \
    std::array<double, 30>, std::array<long double, 30>,  \
    std::array<volatile char, 30>, std::array<volatile wchar_t, 30>,  \
    std::array<volatile char8_t, 30>, std::array<volatile char16_t, 30>,  \
    std::array<volatile char32_t, 30>, std::array<volatile short, 30>,  \
    std::array<volatile int, 30>, std::array<volatile long, 30>,  \
    std::array<volatile long long, 30>,  \
    std::array<volatile unsigned short, 30>,  \
    std::array<volatile unsigned int, 30>,  \
    std::array<volatile unsigned long, 30>,  \
    std::array<volatile unsigned long long, 30>,  \
    std::array<volatile float, 30>, std::array<volatile double, 30>,  \
    std::array<volatile long double, 30>, std::array<char, 31>,  \
    std::array<wchar_t, 31>, std::array<char8_t, 31>,  \
    std::array<char16_t, 31>, std::array<char32_t, 31>,  \
    std::array<short, 31>, std::array<int, 31>, std::array<long, 31>,  \
    std::array<long long, 31>, std::array<unsigned short, 31>,  \
    std::array<unsigned int, 31>, std::array<unsigned long, 31>,  \
    std::array<unsigned long long, 31>, std::array<float, 31>,  \
    std::array<double, 31>, std::array<long double, 31>,  \
    std::array<volatile char, 31>, std::array<volatile wchar_t, 31>,  \
    std::array<volatile char8_t, 31>, std::array<volatile char16_t, 31>,  \
    std::array<volatile char32_t, 31>, std::array<volatile short, 31>,  \
    std::array<volatile int, 31>, std::array<volatile long, 31>,  \
    std::array<volatile long long, 31>,  \
    std::array<volatile unsigned short, 31>,  \
    std::array<volatile unsigned int, 31>,  \
    std::array<volatile unsigned long, 31>,  \
    std::array<volatile unsigned long long, 31>,  \
    std::array<volatile float, 31>, std::array<volatile double, 31>,  \
    std::array<volatile long double, 31>, std::array<char, 32>,  \
    std::array<wchar_t, 32>, std::array<char8_t, 32>,  \
    std::array<char16_t, 32>, std::array<char32_t, 32>,  \
    std::array<short, 32>, std::array<int, 32>, std::array<long, 32>,  \
    std::array<long long, 32>, std::array<unsigned short, 32>,  \
    std::array<unsigned int, 32>, std::array<unsigned long, 32>,  \
    std::array<unsigned long long, 32>, std::array<float, 32>,  \
    std::array<double, 32>, std::array<long double, 32>,  \
    std::array<volatile char, 32>, std::array<volatile wchar_t, 32>,  \
    std::array<volatile char8_t, 32>, std::array<volatile char16_t, 32>,  \
    std::array<volatile char32_t, 32>, std::array<volatile short, 32>,  \
    std::array<volatile int, 32>, std::array<volatile long, 32>,  \
    std::array<volatile long long, 32>,  \
    std::array<volatile unsigned short, 32>,  \
    std::array<volatile unsigned int, 32>,  \
    std::array<volatile unsigned long, 32>,  \
    std::array<volatile unsigned long long, 32>,  \
    std::array<volatile float, 32>, std::array<volatile double, 32>,  \
    std::array<volatile long double, 32>, std::array<char, 33>,  \
    std::array<wchar_t, 33>, std::array<char8_t, 33>,  \
    std::array<char16_t, 33>, std::array<char32_t, 33>,  \
    std::array<short, 33>, std::array<int, 33>, std::array<long, 33>,  \
    std::array<long long, 33>, std::array<unsigned short, 33>,  \
    std::array<unsigned int, 33>, std::array<unsigned long, 33>,  \
    std::array<unsigned long long, 33>, std::array<float, 33>,  \
    std::array<double, 33>, std::array<long double, 33>,  \
    std::array<volatile char, 33>, std::array<volatile wchar_t, 33>,  \
    std::array<volatile char8_t, 33>, std::array<volatile char16_t, 33>,  \
    std::array<volatile char32_t, 33>, std::array<volatile short, 33>,  \
    std::array<volatile int, 33>, std::array<volatile long, 33>,  \
    std::array<volatile long long, 33>,  \
    std::array<volatile unsigned short, 33>,  \
    std::array<volatile unsigned int, 33>,  \
    std::array<volatile unsigned long, 33>,  \
    std::array<volatile unsigned long long, 33>,  \
    std::array<volatile float, 33>, std::array<volatile double, 33>,  \
    std::array<volatile long double, 33>, std::array<char, 34>,  \
    std::array<wchar_t, 34>, std::array<char8_t, 34>,  \
    std::array<char16_t, 34>, std::array<char32_t, 34>,  \
    std::array<short, 34>, std::array<int, 34>, std::array<long, 34>,  \
    std::array<long long, 34>, std::array<unsigned short, 34>,  \
    std::array<unsigned int, 34>, std::array<unsigned long, 34>,  \
    std::array<unsigned long long, 34>, std::array<float, 34>,  \
    std::array<double, 34>, std::array<long double, 34>,  \
    std::array<volatile char, 34>, std::array<volatile wchar_t, 34>,  \
    std::array<volatile char8_t, 34>, std::array<volatile char16_t, 34>,  \
    std::array<volatile char32_t, 34>, std::array<volatile short, 34>,  \
    std::array<volatile int, 34>, std::array<volatile long, 34>,  \
    std::array<volatile long long, 34>,  \
    std::array<volatile unsigned short, 34>,  \
    std::array<volatile unsigned int, 34>,  \
    std::array<volatile unsigned long, 34>,  \
    std::array<volatile unsigned long long, 34>,  \
    std::array<volatile float, 34>, std::array<volatile double, 34>,  \
    std::array<volatile long double, 34>, std::array<char, 35>,  \
    std::array<wchar_t, 35>, std::array<char8_t, 35>,  \
    std::array<char16_t, 35>, std::array<char32_t, 35>,  \
    std::array<short, 35>, std::array<int, 35>, std::array<long, 35>,  \
    std::array<long long, 35>, std::array<unsigned short, 35>,  \
    std::array<unsigned int, 35>, std::array<unsigned long, 35>,  \
    std::array<unsigned long long, 35>, std::array<float, 35>,  \
    std::array<double, 35>, std::array<long double, 35>,  \
    std::array<volatile char, 35>, std::array<volatile wchar_t, 35>,  \
    std::array<volatile char8_t, 35>, std::array<volatile char16_t, 35>,  \
    std::array<volatile char32_t, 35>, std::array<volatile short, 35>,  \
    std::array<volatile int, 35>, std::array<volatile long, 35>,  \
    std::array<volatile long long, 35>,  \
    std::array<volatile unsigned short, 35>,  \
    std::array<volatile unsigned int, 35>,  \
    std::array<volatile unsigned long, 35>,  \
    std::array<volatile unsigned long long, 35>,  \
    std::array<volatile float, 35>, std::array<volatile double, 35>,  \
    std::array<volatile long double, 35>, std::array<char, 36>,  \
    std::array<wchar_t, 36>, std::array<char8_t, 36>,  \
    std::array<char16_t, 36>, std::array<char32_t, 36>,  \
    std::array<short, 36>, std::array<int, 36>, std::array<long, 36>,  \
    std::array<long long, 36>, std::array<unsigned short, 36>,  \
    std::array<unsigned int, 36>, std::array<unsigned long, 36>,  \
    std::array<unsigned long long, 36>, std::array<float, 36>,  \
    std::array<double, 36>, std::array<long double, 36>,  \
    std::array<volatile char, 36>, std::array<volatile wchar_t, 36>,  \
    std::array<volatile char8_t, 36>, std::array<volatile char16_t, 36>,  \
    std::array<volatile char32_t, 36>, std::array<volatile short, 36>,  \
    std::array<volatile int, 36>, std::array<volatile long, 36>,  \
    std::array<volatile long long, 36>,  \
    std::array<volatile unsigned short, 36>,  \
    std::array<volatile unsigned int, 36>,  \
    std::array<volatile unsigned long, 36>,  \
    std::array<volatile unsigned long long, 36>,  \
    std::array<volatile float, 36>, std::array<volatile double, 36>,  \
    std::array<volatile long double, 36>, std::array<char, 37>,  \
    std::array<wchar_t, 37>, std::array<char8_t, 37>,  \
    std::array<char16_t, 37>, std::array<char32_t, 37>,  \
    std::array<short, 37>, std::array<int, 37>, std::array<long, 37>,  \
    std::array<long long, 37>, std::array<unsigned short, 37>,  \
    std::array<unsigned int, 37>, std::array<unsigned long, 37>,  \
    std::array<unsigned long long, 37>, std::array<float, 37>,  \
    std::array<double, 37>, std::array<long double, 37>,  \
    std::array<volatile char, 37>, std::array<volatile wchar_t, 37>,  \
    std::array<volatile char8_t, 37>, std::array<volatile char16_t, 37>,  \
    std::array<volatile char32_t, 37>, std::array<volatile short, 37>,  \
    std::array<volatile int, 37>, std::array<volatile long, 37>,  \
    std::array<volatile long long, 37>,  \
    std::array<volatile unsigned short, 37>,  \
    std::array<volatile unsigned int, 37>,  \
    std::array<volatile unsigned long, 37>,  \
    std::array<volatile unsigned long long, 37>,  \
    std::array<volatile float, 37>, std::array<volatile double, 37>,  \
    std::array<volatile long double, 37>, std::array<char, 38>,  \
    std::array<wchar_t, 38>, std::array<char8_t, 38>,  \
    std::array<char16_t, 38>, std::array<char32_t, 38>,  \
    std::array<short, 38>, std::array<int, 38>, std::array<long, 38>,  \
    std::array<long long, 38>, std::array<unsigned short, 38>,  \
    std::array<unsigned int, 38>, std::array<unsigned long, 38>,  \
    std::array<unsigned long long, 38>, std::array<float, 38>,  \
    std::array<double, 38>, std::array<long double, 38>,  \
    std::array<volatile char, 38>, std::array<volatile wchar_t, 38>,  \
    std::array<volatile char8_t, 38>, std::array<volatile char16_t, 38>,  \
    std::array<volatile char32_t, 38>, std::array<volatile short, 38>,  \
    std::array<volatile int, 38>, std::array<volatile long, 38>,  \
    std::array<volatile long long, 38>,  \
    std::array<volatile unsigned short, 38>,  \
    std::array<volatile unsigned int, 38>,  \
    std::array<volatile unsigned long, 38>,  \
    std::array<volatile unsigned long long, 38>,  \
    std::array<volatile float, 38>, std::array<volatile double, 38>,  \
    std::array<volatile long double, 38>, std::array<char, 39>,  \
    std::array<wchar_t, 39>, std::array<char8_t, 39>,  \
    std::array<char16_t, 39>, std::array<char32_t, 39>,  \
    std::array<short, 39>, std::array<int, 39>, std::array<long, 39>,  \
    std::array<long long, 39>, std::array<unsigned short, 39>,  \
    std::array<unsigned int, 39>, std::array<unsigned long, 39>,  \
    std::array<unsigned long long, 39>, std::array<float, 39>,  \
    std::array<double, 39>, std::array<long double, 39>,  \
    std::array<volatile char, 39>, std::array<volatile wchar_t, 39>,  \
    std::array<volatile char8_t, 39>, std::array<volatile char16_t, 39>,  \
    std::array<volatile char32_t, 39>, std::array<volatile short, 39>,  \
    std::array<volatile int, 39>, std::array<volatile long, 39>,  \
    std::array<volatile long long, 39>,  \
    std::array<volatile unsigned short, 39>,  \
    std::array<volatile unsigned int, 39>,  \
    std::array<volatile unsigned long, 39>,  \
    std::array<volatile unsigned long long, 39>,  \
    std::array<volatile float, 39>, std::array<volatile double, 39>,  \
    std::array<volatile long double, 39>, std::array<char, 40>,  \
    std::array<wchar_t, 40>, std::array<char8_t, 40>,  \
    std::array<char16_t, 40>, std::array<char32_t, 40>,  \
    std::array<short, 40>, std::array<int, 40>, std::array<long, 40>,  \
    std::array<long long, 40>, std::array<unsigned short, 40>,  \
    std::array<unsigned int, 40>, std::array<unsigned long, 40>,  \
    std::array<unsigned long long, 40>, std::array<float, 40>,  \
    std::array<double, 40>, std::array<long double, 40>,  \
    std::array<volatile char, 40>, std::array<volatile wchar_t, 40>,  \
    std::array<volatile char8_t, 40>, std::array<volatile char16_t, 40>,  \
    std::array<volatile char32_t, 40>, std::array<volatile short, 40>,  \
    std::array<volatile int, 40>, std::array<volatile long, 40>,  \
    std::array<volatile long long, 40>,  \
    std::array<volatile unsigned short, 40>,  \
    std::array<volatile unsigned int, 40>,  \
    std::array<volatile unsigned long, 40>,  \
    std::array<volatile unsigned long long, 40>,  \
    std::array<volatile float, 40>, std::array<volatile double, 40>,  \
    std::array<volatile long double, 40>, std::array<char, 41>,  \
    std::array<wchar_t, 41>, std::array<char8_t, 41>,  \
    std::array<char16_t, 41>, std::array<char32_t, 41>,  \
    std::array<short, 41>, std::array<int, 41>, std::array<long, 41>,  \
    std::array<long long, 41>, std::array<unsigned short, 41>,  \
    std::array<unsigned int, 41>, std::array<unsigned long, 41>,  \
    std::array<unsigned long long, 41>, std::array<float, 41>,  \
    std::array<double, 41>, std::array<long double, 41>,  \
    std::array<volatile char, 41>, std::array<volatile wchar_t, 41>,  \
    std::array<volatile char8_t, 41>, std::array<volatile char16_t, 41>,  \
    std::array<volatile char32_t, 41>, std::array<volatile short, 41>,  \
    std::array<volatile int, 41>, std::array<volatile long, 41>,  \
    std::array<volatile long long, 41>,  \
    std::array<volatile unsigned short, 41>,  \
    std::array<volatile unsigned int, 41>,  \
    std::array<volatile unsigned long, 41>,  \
    std::array<volatile unsigned long long, 41>,  \
    std::array<volatile float, 41>, std::array<volatile double, 41>,  \
    std::array<volatile long double, 41>, std::array<char, 42>,  \
    std::array<wchar_t, 42>, std::array<char8_t, 42>,  \
    std::array<char16_t, 42>, std::array<char32_t, 42>,  \
    std::array<short, 42>, std::array<int, 42>, std::array<long, 42>,  \
    std::array<long long, 42>, std::array<unsigned short, 42>,  \
    std::array<unsigned int, 42>, std::array<unsigned long, 42>,  \
    std::array<unsigned long long, 42>, std::array<float, 42>,  \
    std::array<double, 42>, std::array<long double, 42>,  \
    std::array<volatile char, 42>, std::array<volatile wchar_t, 42>,  \
    std::array<volatile char8_t, 42>, std::array<volatile char16_t, 42>,  \
    std::array<volatile char32_t, 42>, std::array<volatile short, 42>,  \
    std::array<volatile int, 42>, std::array<volatile long, 42>,  \
    std::array<volatile long long, 42>,  \
    std::array<volatile unsigned short, 42>,  \
    std::array<volatile unsigned int, 42>,  \
    std::array<volatile unsigned long, 42>,  \
    std::array<volatile unsigned long long, 42>,  \
    std::array<volatile float, 42>, std::array<volatile double, 42>,  \
    std::array<volatile long double, 42>, std::array<char, 43>,  \
    std::array<wchar_t, 43>, std::array<char8_t, 43>,  \
    std::array<char16_t, 43>, std::array<char32_t, 43>,  \
    std::array<short, 43>, std::array<int, 43>, std::array<long, 43>,  \
    std::array<long long, 43>, std::array<unsigned short, 43>,  \
    std::array<unsigned int, 43>, std::array<unsigned long, 43>,  \
    std::array<unsigned long long, 43>, std::array<float, 43>,  \
    std::array<double, 43>, std::array<long double, 43>,  \
    std::array<volatile char, 43>, std::array<volatile wchar_t, 43>,  \
    std::array<volatile char8_t, 43>, std::array<volatile char16_t, 43>,  \
    std::array<volatile char32_t, 43>, std::array<volatile short, 43>,  \
    std::array<volatile int, 43>, std::array<volatile long, 43>,  \
    std::array<volatile long long, 43>,  \
    std::array<volatile unsigned short, 43>,  \
    std::array<volatile unsigned int, 43>,  \
    std::array<volatile unsigned long, 43>,  \
    std::array<volatile unsigned long long, 43>,  \
    std::array<volatile float, 43>, std::array<volatile double, 43>,  \
    std::array<volatile long double, 43>, std::array<char, 44>,  \
    std::array<wchar_t, 44>, std::array<char8_t, 44>,  \
    std::array<char16_t, 44>, std::array<char32_t, 44>,  \
    std::array<short, 44>, std::array<int, 44>, std::array<long, 44>,  \
    std::array<long long, 44>, std::array<unsigned short, 44>,  \
    std::array<unsigned int, 44>, std::array<unsigned long, 44>,  \
    std::array<unsigned long long, 44>, std::array<float, 44>,  \
    std::array<double, 44>, std::array<long double, 44>,  \
    std::array<volatile char, 44>, std::array<volatile wchar_t, 44>,  \
    std::array<volatile char8_t, 44>, std::array<volatile char16_t, 44>,  \
    std::array<volatile char32_t, 44>, std::array<volatile short, 44>,  \
    std::array<volatile int, 44>, std::array<volatile long, 44>,  \
    std::array<volatile long long, 44>,  \
    std::array<volatile unsigned short, 44>,  \
    std::array<volatile unsigned int, 44>,  \
    std::array<volatile unsigned long, 44>,  \
    std::array<volatile unsigned long long, 44>,  \
    std::array<volatile float, 44>, std::array<volatile double, 44>,  \
    std::array<volatile long double, 44>, std::array<char, 45>,  \
    std::array<wchar_t, 45>, std::array<char8_t, 45>,  \
    std::array<char16_t, 45>, std::array<char32_t, 45>,  \
    std::array<short, 45>, std::array<int, 45>, std::array<long, 45>,  \
    std::array<long long, 45>, std::array<unsigned short, 45>,  \
    std::array<unsigned int, 45>, std::array<unsigned long, 45>,  \
    std::array<unsigned long long, 45>, std::array<float, 45>,  \
    std::array<double, 45>, std::array<long double, 45>,  \
    std::array<volatile char, 45>, std::array<volatile wchar_t, 45>,  \
    std::array<volatile char8_t, 45>, std::array<volatile char16_t, 45>,  \
    std::array<volatile char32_t, 45>, std::array<volatile short, 45>,  \
    std::array<volatile int, 45>, std::array<volatile long, 45>,  \
    std::array<volatile long long, 45>,  \
    std::array<volatile unsigned short, 45>,  \
    std::array<volatile unsigned int, 45>,  \
    std::array<volatile unsigned long, 45>,  \
    std::array<volatile unsigned long long, 45>,  \
    std::array<volatile float, 45>, std::array<volatile double, 45>,  \
    std::array<volatile long double, 45>, std::array<char, 46>,  \
    std::array<wchar_t, 46>, std::array<char8_t, 46>,  \
    std::array<char16_t, 46>, std::array<char32_t, 46>,  \
    std::array<short, 46>, std::array<int, 46>, std::array<long, 46>,  \
    std::array<long long, 46>, std::array<unsigned short, 46>,  \
    std::array<unsigned int, 46>, std::array<unsigned long, 46>,  \
    std::array<unsigned long long, 46>, std::array<float, 46>,  \
    std::array<double, 46>, std::array<long double, 46>,  \
    std::array<volatile char, 46>, std::array<volatile wchar_t, 46>,  \
    std::array<volatile char8_t, 46>, std::array<volatile char16_t, 46>,  \
    std::array<volatile char32_t, 46>, std::array<volatile short, 46>,  \
    std::array<volatile int, 46>, std::array<volatile long, 46>,  \
    std::array<volatile long long, 46>,  \
    std::array<volatile unsigned short, 46>,  \
    std::array<volatile unsigned int, 46>,  \
    std::array<volatile unsigned long, 46>,  \
    std::array<volatile unsigned long long, 46>,  \
    std::array<volatile float, 46>, std::array<volatile double, 46>,  \
    std::array<volatile long double, 46>, std::array<char, 47>,  \
    std::array<wchar_t, 47>, std::array<char8_t, 47>,  \
    std::array<char16_t, 47>, std::array<char32_t, 47>,  \
    std::array<short, 47>, std::array<int, 47>, std::array<long, 47>,  \
    std::array<long long, 47>, std::array<unsigned short, 47>,  \
    std::array<unsigned int, 47>, std::array<unsigned long, 47>,  \
    std::array<unsigned long long, 47>, std::array<float, 47>,  \
    std::array<double, 47>, std::array<long double, 47>,  \
    std::array<volatile char, 47>, std::array<volatile wchar_t, 47>,  \
    std::array<volatile char8_t, 47>, std::array<volatile char16_t, 47>,  \
    std::array<volatile char32_t, 47>, std::array<volatile short, 47>,  \
    std::array<volatile int, 47>, std::array<volatile long, 47>,  \
    std::array<volatile long long, 47>,  \
    std::array<volatile unsigned short, 47>,  \
    std::array<volatile unsigned int, 47>,  \
    std::array<volatile unsigned long, 47>,  \
    std::array<volatile unsigned long long, 47>,  \
    std::array<volatile float, 47>, std::array<volatile double, 47>,  \
    std::array<volatile long double, 47>, std::array<char, 48>,  \
    std::array<wchar_t, 48>, std::array<char8_t, 48>,  \
    std::array<char16_t, 48>, std::array<char32_t, 48>,  \
    std::array<short, 48>, std::array<int, 48>, std::array<long, 48>,  \
    std::array<long long, 48>, std::array<unsigned short, 48>,  \
    std::array<unsigned int, 48>, std::array<unsigned long, 48>,  \
    std::array<unsigned long long, 48>, std::array<float, 48>,  \
    std::array<double, 48>, std::array<long double, 48>,  \
    std::array<volatile char, 48>, std::array<volatile wchar_t, 48>,  \
    std::array<volatile char8_t, 48>, std::array<volatile char16_t, 48>,  \
    std::array<volatile char32_t, 48>, std::array<volatile short, 48>,  \
    std::array<volatile int, 48>, std::array<volatile long, 48>,  \
    std::array<volatile long long, 48>,  \
    std::array<volatile unsigned short, 48>,  \
    std::array<volatile unsigned int, 48>,  \
    std::array<volatile unsigned long, 48>,  \
    std::array<volatile unsigned long long, 48>,  \
    std::array<volatile float, 48>, std::array<volatile double, 48>,  \
    std::array<volatile long double, 48>, std::array<char, 49>,  \
    std::array<wchar_t, 49>, std::array<char8_t, 49>,  \
    std::array<char16_t, 49>, std::array<char32_t, 49>,  \
    std::array<short, 49>, std::array<int, 49>, std::array<long, 49>,  \
    std::array<long long, 49>, std::array<unsigned short, 49>,  \
    std::array<unsigned int, 49>, std::array<unsigned long, 49>,  \
    std::array<unsigned long long, 49>, std::array<float, 49>,  \
    std::array<double, 49>, std::array<long double, 49>,  \
    std::array<volatile char, 49>, std::array<volatile wchar_t, 49>,  \
    std::array<volatile char8_t, 49>, std::array<volatile char16_t, 49>,  \
    std::array<volatile char32_t, 49>, std::array<volatile short, 49>,  \
    std::array<volatile int, 49>, std::array<volatile long, 49>,  \
    std::array<volatile long long, 49>,  \
    std::array<volatile unsigned short, 49>,  \
    std::array<volatile unsigned int, 49>,  \
    std::array<volatile unsigned long, 49>,  \
    std::array<volatile unsigned long long, 49>,  \
    std::array<volatile float, 49>, std::array<volatile double, 49>,  \
    std::array<volatile long double, 49>, std::array<char, 50>,  \
    std::array<wchar_t, 50>, std::array<char8_t, 50>,  \
    std::array<char16_t, 50>, std::array<char32_t, 50>,  \
    std::array<short, 50>, std::array<int, 50>, std::array<long, 50>,  \
    std::array<long long, 50>, std::array<unsigned short, 50>,  \
    std::array<unsigned int, 50>, std::array<unsigned long, 50>,  \
    std::array<unsigned long long, 50>, std::array<float, 50>,  \
    std::array<double, 50>, std::array<long double, 50>,  \
    std::array<volatile char, 50>, std::array<volatile wchar_t, 50>,  \
    std::array<volatile char8_t, 50>, std::array<volatile char16_t, 50>,  \
    std::array<volatile char32_t, 50>, std::array<volatile short, 50>,  \
    std::array<volatile int, 50>, std::array<volatile long, 50>,  \
    std::array<volatile long long, 50>,  \
    std::array<volatile unsigned short, 50>,  \
    std::array<volatile unsigned int, 50>,  \
    std::array<volatile unsigned long, 50>,  \
    std::array<volatile unsigned long long, 50>,  \
    std::array<volatile float, 50>, std::array<volatile double, 50>,  \
    std::array<volatile long double, 50>, std::array<char, 51>,  \
    std::array<wchar_t, 51>, std::array<char8_t, 51>,  \
    std::array<char16_t, 51>, std::array<char32_t, 51>,  \
    std::array<short, 51>, std::array<int, 51>, std::array<long, 51>,  \
    std::array<long long, 51>, std::array<unsigned short, 51>,  \
    std::array<unsigned int, 51>, std::array<unsigned long, 51>,  \
    std::array<unsigned long long, 51>, std::array<float, 51>,  \
    std::array<double, 51>, std::array<long double, 51>,  \
    std::array<volatile char, 51>, std::array<volatile wchar_t, 51>,  \
    std::array<volatile char8_t, 51>, std::array<volatile char16_t, 51>,  \
    std::array<volatile char32_t, 51>, std::array<volatile short, 51>,  \
    std::array<volatile int, 51>, std::array<volatile long, 51>,  \
    std::array<volatile long long, 51>,  \
    std::array<volatile unsigned short, 51>,  \
    std::array<volatile unsigned int, 51>,  \
    std::array<volatile unsigned long, 51>,  \
    std::array<volatile unsigned long long, 51>,  \
    std::array<volatile float, 51>, std::array<volatile double, 51>,  \
    std::array<volatile long double, 51>, std::array<char, 52>,  \
    std::array<wchar_t, 52>, std::array<char8_t, 52>,  \
    std::array<char16_t, 52>, std::array<char32_t, 52>,  \
    std::array<short, 52>, std::array<int, 52>, std::array<long, 52>,  \
    std::array<long long, 52>, std::array<unsigned short, 52>,  \
    std::array<unsigned int, 52>, std::array<unsigned long, 52>,  \
    std::array<unsigned long long, 52>, std::array<float, 52>,  \
    std::array<double, 52>, std::array<long double, 52>,  \
    std::array<volatile char, 52>, std::array<volatile wchar_t, 52>,  \
    std::array<volatile char8_t, 52>, std::array<volatile char16_t, 52>,  \
    std::array<volatile char32_t, 52>, std::array<volatile short, 52>,  \
    std::array<volatile int, 52>, std::array<volatile long, 52>,  \
    std::array<volatile long long, 52>,  \
    std::array<volatile unsigned short, 52>,  \
    std::array<volatile unsigned int, 52>,  \
    std::array<volatile unsigned long, 52>,  \
    std::array<volatile unsigned long long, 52>,  \
    std::array<volatile float, 52>, std::array<volatile double, 52>,  \
    std::array<volatile long double, 52>, std::array<char, 53>,  \
    std::array<wchar_t, 53>, std::array<char8_t, 53>,  \
    std::array<char16_t, 53>, std::array<char32_t, 53>,  \
    std::array<short, 53>, std::array<int, 53>, std::array<long, 53>,  \
    std::array<long long, 53>, std::array<unsigned short, 53>,  \
    std::array<unsigned int, 53>, std::array<unsigned long, 53>,  \
    std::array<unsigned long long, 53>, std::array<float, 53>,  \
    std::array<double, 53>, std::array<long double, 53>,  \
    std::array<volatile char, 53>, std::array<volatile wchar_t, 53>,  \
    std::array<volatile char8_t, 53>, std::array<volatile char16_t, 53>,  \
    std::array<volatile char32_t, 53>, std::array<volatile short, 53>,  \
    std::array<volatile int, 53>, std::array<volatile long, 53>,  \
    std::array<volatile long long, 53>,  \
    std::array<volatile unsigned short, 53>,  \
    std::array<volatile unsigned int, 53>,  \
    std::array<volatile unsigned long, 53>,  \
    std::array<volatile unsigned long long, 53>,  \
    std::array<volatile float, 53>, std::array<volatile double, 53>,  \
    std::array<volatile long double, 53>, std::array<char, 54>,  \
    std::array<wchar_t, 54>, std::array<char8_t, 54>,  \
    std::array<char16_t, 54>, std::array<char32_t, 54>,  \
    std::array<short, 54>, std::array<int, 54>, std::array<long, 54>,  \
    std::array<long long, 54>, std::array<unsigned short, 54>,  \
    std::array<unsigned int, 54>, std::array<unsigned long, 54>,  \
    std::array<unsigned long long, 54>, std::array<float, 54>,  \
    std::array<double, 54>, std::array<long double, 54>,  \
    std::array<volatile char, 54>, std::array<volatile wchar_t, 54>,  \
    std::array<volatile char8_t, 54>, std::array<volatile char16_t, 54>,  \
    std::array<volatile char32_t, 54>, std::array<volatile short, 54>,  \
    std::array<volatile int, 54>, std::array<volatile long, 54>,  \
    std::array<volatile long long, 54>,  \
    std::array<volatile unsigned short, 54>,  \
    std::array<volatile unsigned int, 54>,  \
    std::array<volatile unsigned long, 54>,  \
    std::array<volatile unsigned long long, 54>,  \
    std::array<volatile float, 54>, std::array<volatile double, 54>,  \
    std::array<volatile long double, 54>, std::array<char, 55>,  \
    std::array<wchar_t, 55>, std::array<char8_t, 55>,  \
    std::array<char16_t, 55>, std::array<char32_t, 55>,  \
    std::array<short, 55>, std::array<int, 55>, std::array<long, 55>,  \
    std::array<long long, 55>, std::array<unsigned short, 55>,  \
    std::array<unsigned int, 55>, std::array<unsigned long, 55>,  \
    std::array<unsigned long long, 55>, std::array<float, 55>,  \
    std::array<double, 55>, std::array<long double, 55>,  \
    std::array<volatile char, 55>, std::array<volatile wchar_t, 55>,  \
    std::array<volatile char8_t, 55>, std::array<volatile char16_t, 55>,  \
    std::array<volatile char32_t, 55>, std::array<volatile short, 55>,  \
    std::array<volatile int, 55>, std::array<volatile long, 55>,  \
    std::array<volatile long long, 55>,  \
    std::array<volatile unsigned short, 55>,  \
    std::array<volatile unsigned int, 55>,  \
    std::array<volatile unsigned long, 55>,  \
    std::array<volatile unsigned long long, 55>,  \
    std::array<volatile float, 55>, std::array<volatile double, 55>,  \
    std::array<volatile long double, 55>, std::array<char, 56>,  \
    std::array<wchar_t, 56>, std::array<char8_t, 56>,  \
    std::array<char16_t, 56>, std::array<char32_t, 56>,  \
    std::array<short, 56>, std::array<int, 56>, std::array<long, 56>,  \
    std::array<long long, 56>, std::array<unsigned short, 56>,  \
    std::array<unsigned int, 56>, std::array<unsigned long, 56>,  \
    std::array<unsigned long long, 56>, std::array<float, 56>,  \
    std::array<double, 56>, std::array<long double, 56>,  \
    std::array<volatile char, 56>, std::array<volatile wchar_t, 56>,  \
    std::array<volatile char8_t, 56>, std::array<volatile char16_t, 56>,  \
    std::array<volatile char32_t, 56>, std::array<volatile short, 56>,  \
    std::array<volatile int, 56>, std::array<volatile long, 56>,  \
    std::array<volatile long long, 56>,  \
    std::array<volatile unsigned short, 56>,  \
    std::array<volatile unsigned int, 56>,  \
    std::array<volatile unsigned long, 56>,  \
    std::array<volatile unsigned long long, 56>,  \
    std::array<volatile float, 56>, std::array<volatile double, 56>,  \
    std::array<volatile long double, 56>, std::array<char, 57>,  \
    std::array<wchar_t, 57>, std::array<char8_t, 57>,  \
    std::array<char16_t, 57>, std::array<char32_t, 57>,  \
    std::array<short, 57>, std::array<int, 57>, std::array<long, 57>,  \
    std::array<long long, 57>, std::array<unsigned short, 57>,  \
    std::array<unsigned int, 57>, std::array<unsigned long, 57>,  \
    std::array<unsigned long long, 57>, std::array<float, 57>,  \
    std::array<double, 57>, std::array<long double, 57>,  \
    std::array<volatile char, 57>, std::array<volatile wchar_t, 57>,  \
    std::array<volatile char8_t, 57>, std::array<volatile char16_t, 57>,  \
    std::array<volatile char32_t, 57>, std::array<volatile short, 57>,  \
    std::array<volatile int, 57>, std::array<volatile long, 57>,  \
    std::array<volatile long long, 57>,  \
    std::array<volatile unsigned short, 57>,  \
    std::array<volatile unsigned int, 57>,  \
    std::array<volatile unsigned long, 57>,  \
    std::array<volatile unsigned long long, 57>,  \
    std::array<volatile float, 57>, std::array<volatile double, 57>,  \
    std::array<volatile long double, 57>, std::array<char, 58>,  \
    std::array<wchar_t, 58>, std::array<char8_t, 58>,  \
    std::array<char16_t, 58>, std::array<char32_t, 58>,  \
    std::array<short, 58>, std::array<int, 58>, std::array<long, 58>,  \
    std::array<long long, 58>, std::array<unsigned short, 58>,  \
    std::array<unsigned int, 58>, std::array<unsigned long, 58>,  \
    std::array<unsigned long long, 58>, std::array<float, 58>,  \
    std::array<double, 58>, std::array<long double, 58>,  \
    std::array<volatile char, 58>, std::array<volatile wchar_t, 58>,  \
    std::array<volatile char8_t, 58>, std::array<volatile char16_t, 58>,  \
    std::array<volatile char32_t, 58>, std::array<volatile short, 58>,  \
    std::array<volatile int, 58>, std::array<volatile long, 58>,  \
    std::array<volatile long long, 58>,  \
    std::array<volatile unsigned short, 58>,  \
    std::array<volatile unsigned int, 58>,  \
    std::array<volatile unsigned long, 58>,  \
    std::array<volatile unsigned long long, 58>,  \
    std::array<volatile float, 58>, std::array<volatile double, 58>,  \
    std::array<volatile long double, 58>, std::array<char, 59>,  \
    std::array<wchar_t, 59>, std::array<char8_t, 59>,  \
    std::array<char16_t, 59>, std::array<char32_t, 59>,  \
    std::array<short, 59>, std::array<int, 59>, std::array<long, 59>,  \
    std::array<long long, 59>, std::array<unsigned short, 59>,  \
    std::array<unsigned int, 59>, std::array<unsigned long, 59>,  \
    std::array<unsigned long long, 59>, std::array<float, 59>,  \
    std::array<double, 59>, std::array<long double, 59>,  \
    std::array<volatile char, 59>, std::array<volatile wchar_t, 59>,  \
    std::array<volatile char8_t, 59>, std::array<volatile char16_t, 59>,  \
    std::array<volatile char32_t, 59>, std::array<volatile short, 59>,  \
    std::array<volatile int, 59>, std::array<volatile long, 59>,  \
    std::array<volatile long long, 59>,  \
    std::array<volatile unsigned short, 59>,  \
    std::array<volatile unsigned int, 59>,  \
    std::array<volatile unsigned long, 59>,  \
    std::array<volatile unsigned long long, 59>,  \
    std::array<volatile float, 59>, std::array<volatile double, 59>,  \
    std::array<volatile long double, 59>, std::array<char, 60>,  \
    std::array<wchar_t, 60>, std::array<char8_t, 60>,  \
    std::array<char16_t, 60>, std::array<char32_t, 60>,  \
    std::array<short, 60>, std::array<int, 60>, std::array<long, 60>,  \
    std::array<long long, 60>, std::array<unsigned short, 60>,  \
    std::array<unsigned int, 60>, std::array<unsigned long, 60>,  \
    std::array<unsigned long long, 60>, std::array<float, 60>,  \
    std::array<double, 60>, std::array<long double, 60>,  \
    std::array<volatile char, 60>, std::array<volatile wchar_t, 60>,  \
    std::array<volatile char8_t, 60>, std::array<volatile char16_t, 60>,  \
    std::array<volatile char32_t, 60>, std::array<volatile short, 60>,  \
    std::array<volatile int, 60>, std::array<volatile long, 60>,  \
    std::array<volatile long long, 60>,  \
    std::array<volatile unsigned short, 60>,  \
    std::array<volatile unsigned int, 60>,  \
    std::array<volatile unsigned long, 60>,  \
    std::array<volatile unsigned long long, 60>,  \
    std::array<volatile float, 60>, std::array<volatile double, 60>,  \
    std::array<volatile long double, 60>, std::array<char, 61>,  \
    std::array<wchar_t, 61>, std::array<char8_t, 61>,  \
    std::array<char16_t, 61>, std::array<char32_t, 61>,  \
    std::array<short, 61>, std::array<int, 61>, std::array<long, 61>,  \
    std::array<long long, 61>, std::array<unsigned short, 61>,  \
    std::array<unsigned int, 61>, std::array<unsigned long, 61>,  \
    std::array<unsigned long long, 61>, std::array<float, 61>,  \
    std::array<double, 61>, std::array<long double, 61>,  \
    std::array<volatile char, 61>, std::array<volatile wchar_t, 61>,  \
    std::array<volatile char8_t, 61>, std::array<volatile char16_t, 61>,  \
    std::array<volatile char32_t, 61>, std::array<volatile short, 61>,  \
    std::array<volatile int, 61>, std::array<volatile long, 61>,  \
    std::array<volatile long long, 61>,  \
    std::array<volatile unsigned short, 61>,  \
    std::array<volatile unsigned int, 61>,  \
    std::array<volatile unsigned long, 61>,  \
    std::array<volatile unsigned long long, 61>,  \
    std::array<volatile float, 61>, std::array<volatile double, 61>,  \
    std::array<volatile long double, 61>, std::array<char, 62>,  \
    std::array<wchar_t, 62>, std::array<char8_t, 62>,  \
    std::array<char16_t, 62>, std::array<char32_t, 62>,  \
    std::array<short, 62>, std::array<int, 62>, std::array<long, 62>,  \
    std::array<long long, 62>, std::array<unsigned short, 62>,  \
    std::array<unsigned int, 62>, std::array<unsigned long, 62>,  \
    std::array<unsigned long long, 62>, std::array<float, 62>,  \
    std::array<double, 62>, std::array<long double, 62>,  \
    std::array<volatile char, 62>, std::array<volatile wchar_t, 62>,  \
    std::array<volatile char8_t, 62>, std::array<volatile char16_t, 62>,  \
    std::array<volatile char32_t, 62>, std::array<volatile short, 62>,  \
    std::array<volatile int, 62>, std::array<volatile long, 62>,  \
    std::array<volatile long long, 62>,  \
    std::array<volatile unsigned short, 62>,  \
    std::array<volatile unsigned int, 62>,  \
    std::array<volatile unsigned long, 62>,  \
    std::array<volatile unsigned long long, 62>,  \
    std::array<volatile float, 62>, std::array<volatile double, 62>,  \
    std::array<volatile long double, 62>, std::array<char, 63>,  \
    std::array<wchar_t, 63>, std::array<char8_t, 63>,  \
    std::array<char16_t, 63>, std::array<char32_t, 63>,  \
    std::array<short, 63>, std::array<int, 63>, std::array<long, 63>,  \
    std::array<long long, 63>, std::array<unsigned short, 63>,  \
    std::array<unsigned int, 63>, std::array<unsigned long, 63>,  \
    std::array<unsigned long long, 63>, std::array<float, 63>,  \
    std::array<double, 63>, std::array<long double, 63>,  \
    std::array<volatile char, 63>, std::array<volatile wchar_t, 63>,  \
    std::array<volatile char8_t, 63>, std::array<volatile char16_t, 63>,  \
    std::array<volatile char32_t, 63>, std::array<volatile short, 63>,  \
    std::array<volatile int, 63>, std::array<volatile long, 63>,  \
    std::array<volatile long long, 63>,  \
    std::array<volatile unsigned short, 63>,  \
    std::array<volatile unsigned int, 63>,  \
    std::array<volatile unsigned long, 63>,  \
    std::array<volatile unsigned long long, 63>,  \
    std::array<volatile float, 63>, std::array<volatile double, 63>,  \
    std::array<volatile long double, 63>, std::array<char, 64>,  \
    std::array<wchar_t, 64>, std::array<char8_t, 64>,  \
    std::array<char16_t, 64>, std::array<char32_t, 64>,  \
    std::array<short, 64>, std::array<int, 64>, std::array<long, 64>,  \
    std::array<long long, 64>, std::array<unsigned short, 64>,  \
    std::array<unsigned int, 64>, std::array<unsigned long, 64>,  \
    std::array<unsigned long long, 64>, std::array<float, 64>,  \
    std::array<double, 64>, std::array<long double, 64>,  \
    std::array<volatile char, 64>, std::array<volatile wchar_t, 64>,  \
    std::array<volatile char8_t, 64>, std::array<volatile char16_t, 64>,  \
    std::array<volatile char32_t, 64>, std::array<volatile short, 64>,  \
    std::array<volatile int, 64>, std::array<volatile long, 64>,  \
    std::array<volatile long long, 64>,  \
    std::array<volatile unsigned short, 64>,  \
    std::array<volatile unsigned int, 64>,  \
    std::array<volatile unsigned long, 64>,  \
    std::array<volatile unsigned long long, 64>,  \
    std::array<volatile float, 64>, std::array<volatile double, 64>,  \
    std::array<volatile long double, 64>, std::array<char, 65>,  \
    std::array<wchar_t, 65>, std::array<char8_t, 65>,  \
    std::array<char16_t, 65>, std::array<char32_t, 65>,  \
    std::array<short, 65>, std::array<int, 65>, std::array<long, 65>,  \
    std::array<long long, 65>, std::array<unsigned short, 65>,  \
    std::array<unsigned int, 65>, std::array<unsigned long, 65>,  \
    std::array<unsigned long long, 65>, std::array<float, 65>,  \
    std::array<double, 65>, std::array<long double, 65>,  \
    std::array<volatile char, 65>, std::array<volatile wchar_t, 65>,  \
    std::array<volatile char8_t, 65>, std::array<volatile char16_t, 65>,  \
    std::array<volatile char32_t, 65>, std::array<volatile short, 65>,  \
    std::array<volatile int, 65>, std::array<volatile long, 65>,  \
    std::array<volatile long long, 65>,  \
    std::array<volatile unsigned short, 65>,  \
    std::array<volatile unsigned int, 65>,  \
    std::array<volatile unsigned long, 65>,  \
    std::array<volatile unsigned long long, 65>,  \
    std::array<volatile float, 65>, std::array<volatile double, 65>,  \
    std::array<volatile long double, 65>, std::array<char, 66>,  \
    std::array<wchar_t, 66>, std::array<char8_t, 66>,  \
    std::array<char16_t, 66>, std::array<char32_t, 66>,  \
    std::array<short, 66>, std::array<int, 66>, std::array<long, 66>,  \
    std::array<long long, 66>, std::array<unsigned short, 66>,  \
    std::array<unsigned int, 66>, std::array<unsigned long, 66>,  \
    std::array<unsigned long long, 66>, std::array<float, 66>,  \
    std::array<double, 66>, std::array<long double, 66>,  \
    std::array<volatile char, 66>, std::array<volatile wchar_t, 66>,  \
    std::array<volatile char8_t, 66>, std::array<volatile char16_t, 66>,  \
    std::array<volatile char32_t, 66>, std::array<volatile short, 66>,  \
    std::array<volatile int, 66>, std::array<volatile long, 66>,  \
    std::array<volatile long long, 66>,  \
    std::array<volatile unsigned short, 66>,  \
    std::array<volatile unsigned int, 66>,  \
    std::array<volatile unsigned long, 66>,  \
    std::array<volatile unsigned long long, 66>,  \
    std::array<volatile float, 66>, std::array<volatile double, 66>,  \
    std::array<volatile long double, 66>, std::array<char, 67>,  \
    std::array<wchar_t, 67>, std::array<char8_t, 67>,  \
    std::array<char16_t, 67>, std::array<char32_t, 67>,  \
    std::array<short, 67>, std::array<int, 67>, std::array<long, 67>,  \
    std::array<long long, 67>, std::array<unsigned short, 67>,  \
    std::array<unsigned int, 67>, std::array<unsigned long, 67>,  \
    std::array<unsigned long long, 67>, std::array<float, 67>,  \
    std::array<double, 67>, std::array<long double, 67>,  \
    std::array<volatile char, 67>, std::array<volatile wchar_t, 67>,  \
    std::array<volatile char8_t, 67>, std::array<volatile char16_t, 67>,  \
    std::array<volatile char32_t, 67>, std::array<volatile short, 67>,  \
    std::array<volatile int, 67>, std::array<volatile long, 67>,  \
    std::array<volatile long long, 67>,  \
    std::array<volatile unsigned short, 67>,  \
    std::array<volatile unsigned int, 67>,  \
    std::array<volatile unsigned long, 67>,  \
    std::array<volatile unsigned long long, 67>,  \
    std::array<volatile float, 67>, std::array<volatile double, 67>,  \
    std::array<volatile long double, 67>, std::array<char, 68>,  \
    std::array<wchar_t, 68>, std::array<char8_t, 68>,  \
    std::array<char16_t, 68>, std::array<char32_t, 68>,  \
    std::array<short, 68>, std::array<int, 68>, std::array<long, 68>,  \
    std::array<long long, 68>, std::array<unsigned short, 68>,  \
    std::array<unsigned int, 68>, std::array<unsigned long, 68>,  \
    std::array<unsigned long long, 68>, std::array<float, 68>,  \
    std::array<double, 68>, std::array<long double, 68>,  \
    std::array<volatile char, 68>, std::array<volatile wchar_t, 68>,  \
    std::array<volatile char8_t, 68>, std::array<volatile char16_t, 68>,  \
    std::array<volatile char32_t, 68>, std::array<volatile short, 68>,  \
    std::array<volatile int, 68>, std::array<volatile long, 68>,  \
    std::array<volatile long long, 68>,  \
    std::array<volatile unsigned short, 68>,  \
    std::array<volatile unsigned int, 68>,  \
    std::array<volatile unsigned long, 68>,  \
    std::array<volatile unsigned long long, 68>,  \
    std::array<volatile float, 68>, std::array<volatile double, 68>,  \
    std::array<volatile long double, 68>, std::array<char, 69>,  \
    std::array<wchar_t, 69>, std::array<char8_t, 69>,  \
    std::array<char16_t, 69>, std::array<char32_t, 69>,  \
    std::array<short, 69>, std::array<int, 69>, std::array<long, 69>,  \
    std::array<long long, 69>, std::array<unsigned short, 69>,  \
    std::array<unsigned int, 69>, std::array<unsigned long, 69>,  \
    std::array<unsigned long long, 69>, std::array<float, 69>,  \
    std::array<double, 69>, std::array<long double, 69>,  \
    std::array<volatile char, 69>, std::array<volatile wchar_t, 69>,  \
    std::array<volatile char8_t, 69>, std::array<volatile char16_t, 69>,  \
    std::array<volatile char32_t, 69>, std::array<volatile short, 69>,  \
    std::array<volatile int, 69>, std::array<volatile long, 69>,  \
    std::array<volatile long long, 69>,  \
    std::array<volatile unsigned short, 69>,  \
    std::array<volatile unsigned int, 69>,  \
    std::array<volatile unsigned long, 69>,  \
    std::array<volatile unsigned long long, 69>,  \
    std::array<volatile float, 69>, std::array<volatile double, 69>,  \
    std::array<volatile long double, 69>, std::array<char, 70>,  \
    std::array<wchar_t, 70>, std::array<char8_t, 70>,  \
    std::array<char16_t, 70>, std::array<char32_t, 70>,  \
    std::array<short, 70>, std::array<int, 70>, std::array<long, 70>,  \
    std::array<long long, 70>, std::array<unsigned short, 70>,  \
    std::array<unsigned int, 70>, std::array<unsigned long, 70>,  \
    std::array<unsigned long long, 70>, std::array<float, 70>,  \
    std::array<double, 70>, std::array<long double, 70>,  \
    std::array<volatile char, 70>, std::array<volatile wchar_t, 70>,  \
    std::array<volatile char8_t, 70>, std::array<volatile char16_t, 70>,  \
    std::array<volatile char32_t, 70>, std::array<volatile short, 70>,  \
    std::array<volatile int, 70>, std::array<volatile long, 70>,  \
    std::array<volatile long long, 70>,  \
    std::array<volatile unsigned short, 70>,  \
    std::array<volatile unsigned int, 70>,  \
    std::array<volatile unsigned long, 70>,  \
    std::array<volatile unsigned long long, 70>,  \
    std::array<volatile float, 70>, std::array<volatile double, 70>,  \
    std::array<volatile long double, 70>, std::array<char, 71>,  \
    std::array<wchar_t, 71>, std::array<char8_t, 71>,  \
    std::array<char16_t, 71>, std::array<char32_t, 71>,  \
    std::array<short, 71>, std::array<int, 71>, std::array<long, 71>,  \
    std::array<long long, 71>, std::array<unsigned short, 71>,  \
    std::array<unsigned int, 71>, std::array<unsigned long, 71>,  \
    std::array<unsigned long long, 71>, std::array<float, 71>,  \
    std::array<double, 71>, std::array<long double, 71>,  \
    std::array<volatile char, 71>, std::array<volatile wchar_t, 71>,  \
    std::array<volatile char8_t, 71>, std::array<volatile char16_t, 71>,  \
    std::array<volatile char32_t, 71>, std::array<volatile short, 71>,  \
    std::array<volatile int, 71>, std::array<volatile long, 71>,  \
    std::array<volatile long long, 71>,  \
    std::array<volatile unsigned short, 71>,  \
    std::array<volatile unsigned int, 71>,  \
    std::array<volatile unsigned long, 71>,  \
    std::array<volatile unsigned long long, 71>,  \
    std::array<volatile float, 71>, std::array<volatile double, 71>,  \
    std::array<volatile long double, 71>, std::array<char, 72>,  \
    std::array<wchar_t, 72>, std::array<char8_t, 72>,  \
    std::array<char16_t, 72>, std::array<char32_t, 72>,  \
    std::array<short, 72>, std::array<int, 72>, std::array<long, 72>,  \
    std::array<long long, 72>, std::array<unsigned short, 72>,  \
    std::array<unsigned int, 72>, std::array<unsigned long, 72>,  \
    std::array<unsigned long long, 72>, std::array<float, 72>,  \
    std::array<double, 72>, std::array<long double, 72>,  \
    std::array<volatile char, 72>, std::array<volatile wchar_t, 72>,  \
    std::array<volatile char8_t, 72>, std::array<volatile char16_t, 72>,  \
    std::array<volatile char32_t, 72>, std::array<volatile short, 72>,  \
    std::array<volatile int, 72>, std::array<volatile long, 72>,  \
    std::array<volatile long long, 72>,  \
    std::array<volatile unsigned short, 72>,  \
    std::array<volatile unsigned int, 72>,  \
    std::array<volatile unsigned long, 72>,  \
    std::array<volatile unsigned long long, 72>,  \
    std::array<volatile float, 72>, std::array<volatile double, 72>,  \
    std::array<volatile long double, 72>, std::array<char, 73>,  \
    std::array<wchar_t, 73>, std::array<char8_t, 73>,  \
    std::array<char16_t, 73>, std::array<char32_t, 73>,  \
    std::array<short, 73>, std::array<int, 73>, std::array<long, 73>,  \
    std::array<long long, 73>, std::array<unsigned short, 73>,  \
    std::array<unsigned int, 73>, std::array<unsigned long, 73>,  \
    std::array<unsigned long long, 73>, std::array<float, 73>,  \
    std::array<double, 73>, std::array<long double, 73>,  \
    std::array<volatile char, 73>, std::array<volatile wchar_t, 73>,  \
    std::array<volatile char8_t, 73>, std::array<volatile char16_t, 73>,  \
    std::array<volatile char32_t, 73>, std::array<volatile short, 73>,  \
    std::array<volatile int, 73>, std::array<volatile long, 73>,  \
    std::array<volatile long long, 73>,  \
    std::array<volatile unsigned short, 73>,  \
    std::array<volatile unsigned int, 73>,  \
    std::array<volatile unsigned long, 73>,  \
    std::array<volatile unsigned long long, 73>,  \
    std::array<volatile float, 73>, std::array<volatile double, 73>,  \
    std::array<volatile long double, 73>, std::array<char, 74>,  \
    std::array<wchar_t, 74>, std::array<char8_t, 74>,  \
    std::array<char16_t, 74>, std::array<char32_t, 74>,  \
    std::array<short, 74>, std::array<int, 74>, std::array<long, 74>,  \
    std::array<long long, 74>, std::array<unsigned short, 74>,  \
    std::array<unsigned int, 74>, std::array<unsigned long, 74>,  \
    std::array<unsigned long long, 74>, std::array<float, 74>,  \
    std::array<double, 74>, std::array<long double, 74>,  \
    std::array<volatile char, 74>, std::array<volatile wchar_t, 74>,  \
    std::array<volatile char8_t, 74>, std::array<volatile char16_t, 74>,  \
    std::array<volatile char32_t, 74>, std::array<volatile short, 74>,  \
    std::array<volatile int, 74>, std::array<volatile long, 74>,  \
    std::array<volatile long long, 74>,  \
    std::array<volatile unsigned short, 74>,  \
    std::array<volatile unsigned int, 74>,  \
    std::array<volatile unsigned long, 74>,  \
    std::array<volatile unsigned long long, 74>,  \
    std::array<volatile float, 74>, std::array<volatile double, 74>,  \
    std::array<volatile long double, 74>, std::array<char, 75>,  \
    std::array<wchar_t, 75>, std::array<char8_t, 75>,  \
    std::array<char16_t, 75>, std::array<char32_t, 75>,  \
    std::array<short, 75>, std::array<int, 75>, std::array<long, 75>,  \
    std::array<long long, 75>, std::array<unsigned short, 75>,  \
    std::array<unsigned int, 75>, std::array<unsigned long, 75>,  \
    std::array<unsigned long long, 75>, std::array<float, 75>,  \
    std::array<double, 75>, std::array<long double, 75>,  \
    std::array<volatile char, 75>, std::array<volatile wchar_t, 75>,  \
    std::array<volatile char8_t, 75>, std::array<volatile char16_t, 75>,  \
    std::array<volatile char32_t, 75>, std::array<volatile short, 75>,  \
    std::array<volatile int, 75>, std::array<volatile long, 75>,  \
    std::array<volatile long long, 75>,  \
    std::array<volatile unsigned short, 75>,  \
    std::array<volatile unsigned int, 75>,  \
    std::array<volatile unsigned long, 75>,  \
    std::array<volatile unsigned long long, 75>,  \
    std::array<volatile float, 75>, std::array<volatile double, 75>,  \
    std::array<volatile long double, 75>, std::array<char, 76>,  \
    std::array<wchar_t, 76>, std::array<char8_t, 76>,  \
    std::array<char16_t, 76>, std::array<char32_t, 76>,  \
    std::array<short, 76>, std::array<int, 76>, std::array<long, 76>,  \
    std::array<long long, 76>, std::array<unsigned short, 76>,  \
    std::array<unsigned int, 76>, std::array<unsigned long, 76>,  \
    std::array<unsigned long long, 76>, std::array<float, 76>,  \
    std::array<double, 76>, std::array<long double, 76>,  \
    std::array<volatile char, 76>, std::array<volatile wchar_t, 76>,  \
    std::array<volatile char8_t, 76>, std::array<volatile char16_t, 76>,  \
    std::array<volatile char32_t, 76>, std::array<volatile short, 76>,  \
    std::array<volatile int, 76>, std::array<volatile long, 76>,  \
    std::array<volatile long long, 76>,  \
    std::array<volatile unsigned short, 76>,  \
    std::array<volatile unsigned int, 76>,  \
    std::array<volatile unsigned long, 76>,  \
    std::array<volatile unsigned long long, 76>,  \
    std::array<volatile float, 76>, std::array<volatile double, 76>,  \
    std::array<volatile long double, 76>, std::array<char, 77>,  \
    std::array<wchar_t, 77>, std::array<char8_t, 77>,  \
    std::array<char16_t, 77>, std::array<char32_t, 77>,  \
    std::array<short, 77>, std::array<int, 77>, std::array<long, 77>,  \
    std::array<long long, 77>, std::array<unsigned short, 77>,  \
    std::array<unsigned int, 77>, std::array<unsigned long, 77>,  \
    std::array<unsigned long long, 77>, std::array<float, 77>,  \
    std::array<double, 77>, std::array<long double, 77>,  \
    std::array<volatile char, 77>, std::array<volatile wchar_t, 77>,  \
    std::array<volatile char8_t, 77>, std::array<volatile char16_t, 77>,  \
    std::array<volatile char32_t, 77>, std::array<volatile short, 77>,  \
    std::array<volatile int, 77>, std::array<volatile long, 77>,  \
    std::array<volatile long long, 77>,  \
    std::array<volatile unsigned short, 77>,  \
    std::array<volatile unsigned int, 77>,  \
    std::array<volatile unsigned long, 77>,  \
    std::array<volatile unsigned long long, 77>,  \
    std::array<volatile float, 77>, std::array<volatile double, 77>,  \
    std::array<volatile long double, 77>, std::array<char, 78>,  \
    std::array<wchar_t, 78>, std::array<char8_t, 78>,  \
    std::array<char16_t, 78>, std::array<char32_t, 78>,  \
    std::array<short, 78>, std::array<int, 78>, std::array<long, 78>,  \
    std::array<long long, 78>, std::array<unsigned short, 78>,  \
    std::array<unsigned int, 78>, std::array<unsigned long, 78>,  \
    std::array<unsigned long long, 78>, std::array<float, 78>,  \
    std::array<double, 78>, std::array<long double, 78>,  \
    std::array<volatile char, 78>, std::array<volatile wchar_t, 78>,  \
    std::array<volatile char8_t, 78>, std::array<volatile char16_t, 78>,  \
    std::array<volatile char32_t, 78>, std::array<volatile short, 78>,  \
    std::array<volatile int, 78>, std::array<volatile long, 78>,  \
    std::array<volatile long long, 78>,  \
    std::array<volatile unsigned short, 78>,  \
    std::array<volatile unsigned int, 78>,  \
    std::array<volatile unsigned long, 78>,  \
    std::array<volatile unsigned long long, 78>,  \
    std::array<volatile float, 78>, std::array<volatile double, 78>,  \
    std::array<volatile long double, 78>, std::array<char, 79>,  \
    std::array<wchar_t, 79>, std::array<char8_t, 79>,  \
    std::array<char16_t, 79>, std::array<char32_t, 79>,  \
    std::array<short, 79>, std::array<int, 79>, std::array<long, 79>,  \
    std::array<long long, 79>, std::array<unsigned short, 79>,  \
    std::array<unsigned int, 79>, std::array<unsigned long, 79>,  \
    std::array<unsigned long long, 79>, std::array<float, 79>,  \
    std::array<double, 79>, std::array<long double, 79>,  \
    std::array<volatile char, 79>, std::array<volatile wchar_t, 79>,  \
    std::array<volatile char8_t, 79>, std::array<volatile char16_t, 79>,  \
    std::array<volatile char32_t, 79>, std::array<volatile short, 79>,  \
    std::array<volatile int, 79>, std::array<volatile long, 79>,  \
    std::array<volatile long long, 79>,  \
    std::array<volatile unsigned short, 79>,  \
    std::array<volatile unsigned int, 79>,  \
    std::array<volatile unsigned long, 79>,  \
    std::array<volatile unsigned long long, 79>,  \
    std::array<volatile float, 79>, std::array<volatile double, 79>,  \
    std::array<volatile long double, 79>, std::array<char, 80>,  \
    std::array<wchar_t, 80>, std::array<char8_t, 80>,  \
    std::array<char16_t, 80>, std::array<char32_t, 80>,  \
    std::array<short, 80>, std::array<int, 80>, std::array<long, 80>,  \
    std::array<long long, 80>, std::array<unsigned short, 80>,  \
    std::array<unsigned int, 80>, std::array<unsigned long, 80>,  \
    std::array<unsigned long long, 80>, std::array<float, 80>,  \
    std::array<double, 80>, std::array<long double, 80>,  \
    std::array<volatile char, 80>, std::array<volatile wchar_t, 80>,  \
    std::array<volatile char8_t, 80>, std::array<volatile char16_t, 80>,  \
    std::array<volatile char32_t, 80>, std::array<volatile short, 80>,  \
    std::array<volatile int, 80>, std::array<volatile long, 80>,  \
    std::array<volatile long long, 80>,  \
    std::array<volatile unsigned short, 80>,  \
    std::array<volatile unsigned int, 80>,  \
    std::array<volatile unsigned long, 80>,  \
    std::array<volatile unsigned long long, 80>,  \
    std::array<volatile float, 80>, std::array<volatile double, 80>,  \
    std::array<volatile long double, 80>, std::array<char, 81>,  \
    std::array<wchar_t, 81>, std::array<char8_t, 81>,  \
    std::array<char16_t, 81>, std::array<char32_t, 81>,  \
    std::array<short, 81>, std::array<int, 81>, std::array<long, 81>,  \
    std::array<long long, 81>, std::array<unsigned short, 81>,  \
    std::array<unsigned int, 81>, std::array<unsigned long, 81>,  \
    std::array<unsigned long long, 81>, std::array<float, 81>,  \
    std::array<double, 81>, std::array<long double, 81>,  \
    std::array<volatile char, 81>, std::array<volatile wchar_t, 81>,  \
    std::array<volatile char8_t, 81>, std::array<volatile char16_t, 81>,  \
    std::array<volatile char32_t, 81>, std::array<volatile short, 81>,  \
    std::array<volatile int, 81>, std::array<volatile long, 81>,  \
    std::array<volatile long long, 81>,  \
    std::array<volatile unsigned short, 81>,  \
    std::array<volatile unsigned int, 81>,  \
    std::array<volatile unsigned long, 81>,  \
    std::array<volatile unsigned long long, 81>,  \
    std::array<volatile float, 81>, std::array<volatile double, 81>,  \
    std::array<volatile long double, 81>, std::array<char, 82>,  \
    std::array<wchar_t, 82>, std::array<char8_t, 82>,  \
    std::array<char16_t, 82>, std::array<char32_t, 82>,  \
    std::array<short, 82>, std::array<int, 82>, std::array<long, 82>,  \
    std::array<long long, 82>, std::array<unsigned short, 82>,  \
    std::array<unsigned int, 82>, std::array<unsigned long, 82>,  \
    std::array<unsigned long long, 82>, std::array<float, 82>,  \
    std::array<double, 82>, std::array<long double, 82>,  \
    std::array<volatile char, 82>, std::array<volatile wchar_t, 82>,  \
    std::array<volatile char8_t, 82>, std::array<volatile char16_t, 82>,  \
    std::array<volatile char32_t, 82>, std::array<volatile short, 82>,  \
    std::array<volatile int, 82>, std::array<volatile long, 82>,  \
    std::array<volatile long long, 82>,  \
    std::array<volatile unsigned short, 82>,  \
    std::array<volatile unsigned int, 82>,  \
    std::array<volatile unsigned long, 82>,  \
    std::array<volatile unsigned long long, 82>,  \
    std::array<volatile float, 82>, std::array<volatile double, 82>,  \
    std::array<volatile long double, 82>, std::array<char, 83>,  \
    std::array<wchar_t, 83>, std::array<char8_t, 83>,  \
    std::array<char16_t, 83>, std::array<char32_t, 83>,  \
    std::array<short, 83>, std::array<int, 83>, std::array<long, 83>,  \
    std::array<long long, 83>, std::array<unsigned short, 83>,  \
    std::array<unsigned int, 83>, std::array<unsigned long, 83>,  \
    std::array<unsigned long long, 83>, std::array<float, 83>,  \
    std::array<double, 83>, std::array<long double, 83>,  \
    std::array<volatile char, 83>, std::array<volatile wchar_t, 83>,  \
    std::array<volatile char8_t, 83>, std::array<volatile char16_t, 83>,  \
    std::array<volatile char32_t, 83>, std::array<volatile short, 83>,  \
    std::array<volatile int, 83>, std::array<volatile long, 83>,  \
    std::array<volatile long long, 83>,  \
    std::array<volatile unsigned short, 83>,  \
    std::array<volatile unsigned int, 83>,  \
    std::array<volatile unsigned long, 83>,  \
    std::array<volatile unsigned long long, 83>,  \
    std::array<volatile float, 83>, std::array<volatile double, 83>,  \
    std::array<volatile long double, 83>, std::array<char, 84>,  \
    std::array<wchar_t, 84>, std::array<char8_t, 84>,  \
    std::array<char16_t, 84>, std::array<char32_t, 84>,  \
    std::array<short, 84>, std::array<int, 84>, std::array<long, 84>,  \
    std::array<long long, 84>, std::array<unsigned short, 84>,  \
    std::array<unsigned int, 84>, std::array<unsigned long, 84>,  \
    std::array<unsigned long long, 84>, std::array<float, 84>,  \
    std::array<double, 84>, std::array<long double, 84>,  \
    std::array<volatile char, 84>, std::array<volatile wchar_t, 84>,  \
    std::array<volatile char8_t, 84>, std::array<volatile char16_t, 84>,  \
    std::array<volatile char32_t, 84>, std::array<volatile short, 84>,  \
    std::array<volatile int, 84>, std::array<volatile long, 84>,  \
    std::array<volatile long long, 84>,  \
    std::array<volatile unsigned short, 84>,  \
    std::array<volatile unsigned int, 84>,  \
    std::array<volatile unsigned long, 84>,  \
    std::array<volatile unsigned long long, 84>,  \
    std::array<volatile float, 84>, std::array<volatile double, 84>,  \
    std::array<volatile long double, 84>, std::array<char, 85>,  \
    std::array<wchar_t, 85>, std::array<char8_t, 85>,  \
    std::array<char16_t, 85>, std::array<char32_t, 85>,  \
    std::array<short, 85>, std::array<int, 85>, std::array<long, 85>,  \
    std::array<long long, 85>, std::array<unsigned short, 85>,  \
    std::array<unsigned int, 85>, std::array<unsigned long, 85>,  \
    std::array<unsigned long long, 85>, std::array<float, 85>,  \
    std::array<double, 85>, std::array<long double, 85>,  \
    std::array<volatile char, 85>, std::array<volatile wchar_t, 85>,  \
    std::array<volatile char8_t, 85>, std::array<volatile char16_t, 85>,  \
    std::array<volatile char32_t, 85>, std::array<volatile short, 85>,  \
    std::array<volatile int, 85>, std::array<volatile long, 85>,  \
    std::array<volatile long long, 85>,  \
    std::array<volatile unsigned short, 85>,  \
    std::array<volatile unsigned int, 85>,  \
    std::array<volatile unsigned long, 85>,  \
    std::array<volatile unsigned long long, 85>,  \
    std::array<volatile float, 85>, std::array<volatile double, 85>,  \
    std::array<volatile long double, 85>, std::array<char, 86>,  \
    std::array<wchar_t, 86>, std::array<char8_t, 86>,  \
    std::array<char16_t, 86>, std::array<char32_t, 86>,  \
    std::array<short, 86>, std::array<int, 86>, std::array<long, 86>,  \
    std::array<long long, 86>, std::array<unsigned short, 86>,  \
    std::array<unsigned int, 86>, std::array<unsigned long, 86>,  \
    std::array<unsigned long long, 86>, std::array<float, 86>,  \
    std::array<double, 86>, std::array<long double, 86>,  \
    std::array<volatile char, 86>, std::array<volatile wchar_t, 86>,  \
    std::array<volatile char8_t, 86>, std::array<volatile char16_t, 86>,  \
    std::array<volatile char32_t, 86>, std::array<volatile short, 86>,  \
    std::array<volatile int, 86>, std::array<volatile long, 86>,  \
    std::array<volatile long long, 86>,  \
    std::array<volatile unsigned short, 86>,  \
    std::array<volatile unsigned int, 86>,  \
    std::array<volatile unsigned long, 86>,  \
    std::array<volatile unsigned long long, 86>,  \
    std::array<volatile float, 86>, std::array<volatile double, 86>,  \
    std::array<volatile long double, 86>, std::array<char, 87>,  \
    std::array<wchar_t, 87>, std::array<char8_t, 87>,  \
    std::array<char16_t, 87>, std::array<char32_t, 87>,  \
    std::array<short, 87>, std::array<int, 87>, std::array<long, 87>,  \
    std::array<long long, 87>, std::array<unsigned short, 87>,  \
    std::array<unsigned int, 87>, std::array<unsigned long, 87>,  \
    std::array<unsigned long long, 87>, std::array<float, 87>,  \
    std::array<double, 87>, std::array<long double, 87>,  \
    std::array<volatile char, 87>, std::array<volatile wchar_t, 87>,  \
    std::array<volatile char8_t, 87>, std::array<volatile char16_t, 87>,  \
    std::array<volatile char32_t, 87>, std::array<volatile short, 87>,  \
    std::array<volatile int, 87>, std::array<volatile long, 87>,  \
    std::array<volatile long long, 87>,  \
    std::array<volatile unsigned short, 87>,  \
    std::array<volatile unsigned int, 87>,  \
    std::array<volatile unsigned long, 87>,  \
    std::array<volatile unsigned long long, 87>,  \
    std::array<volatile float, 87>, std::array<volatile double, 87>,  \
    std::array<volatile long double, 87>, std::array<char, 88>,  \
    std::array<wchar_t, 88>, std::array<char8_t, 88>,  \
    std::array<char16_t, 88>, std::array<char32_t, 88>,  \
    std::array<short, 88>, std::array<int, 88>, std::array<long, 88>,  \
    std::array<long long, 88>, std::array<unsigned short, 88>,  \
    std::array<unsigned int, 88>, std::array<unsigned long, 88>,  \
    std::array<unsigned long long, 88>, std::array<float, 88>,  \
    std::array<double, 88>, std::array<long double, 88>,  \
    std::array<volatile char, 88>, std::array<volatile wchar_t, 88>,  \
    std::array<volatile char8_t, 88>, std::array<volatile char16_t, 88>,  \
    std::array<volatile char32_t, 88>, std::array<volatile short, 88>,  \
    std::array<volatile int, 88>, std::array<volatile long, 88>,  \
    std::array<volatile long long, 88>,  \
    std::array<volatile unsigned short, 88>,  \
    std::array<volatile unsigned int, 88>,  \
    std::array<volatile unsigned long, 88>,  \
    std::array<volatile unsigned long long, 88>,  \
    std::array<volatile float, 88>, std::array<volatile double, 88>,  \
    std::array<volatile long double, 88>, std::array<char, 89>,  \
    std::array<wchar_t, 89>, std::array<char8_t, 89>,  \
    std::array<char16_t, 89>, std::array<char32_t, 89>,  \
    std::array<short, 89>, std::array<int, 89>, std::array<long, 89>,  \
    std::array<long long, 89>, std::array<unsigned short, 89>,  \
    std::array<unsigned int, 89>, std::array<unsigned long, 89>,  \
    std::array<unsigned long long, 89>, std::array<float, 89>,  \
    std::array<double, 89>, std::array<long double, 89>,  \
    std::array<volatile char, 89>, std::array<volatile wchar_t, 89>,  \
    std::array<volatile char8_t, 89>, std::array<volatile char16_t, 89>,  \
    std::array<volatile char32_t, 89>, std::array<volatile short, 89>,  \
    std::array<volatile int, 89>, std::array<volatile long, 89>,  \
    std::array<volatile long long, 89>,  \
    std::array<volatile unsigned short, 89>,  \
    std::array<volatile unsigned int, 89>,  \
    std::array<volatile unsigned long, 89>,  \
    std::array<volatile unsigned long long, 89>,  \
    std::array<volatile float, 89>, std::array<volatile double, 89>,  \
    std::array<volatile long double, 89>, std::array<char, 90>,  \
    std::array<wchar_t, 90>, std::array<char8_t, 90>,  \
    std::array<char16_t, 90>, std::array<char32_t, 90>,  \
    std::array<short, 90>, std::array<int, 90>, std::array<long, 90>,  \
    std::array<long long, 90>, std::array<unsigned short, 90>,  \
    std::array<unsigned int, 90>, std::array<unsigned long, 90>,  \
    std::array<unsigned long long, 90>, std::array<float, 90>,  \
    std::array<double, 90>, std::array<long double, 90>,  \
    std::array<volatile char, 90>, std::array<volatile wchar_t, 90>,  \
    std::array<volatile char8_t, 90>, std::array<volatile char16_t, 90>,  \
    std::array<volatile char32_t, 90>, std::array<volatile short, 90>,  \
    std::array<volatile int, 90>, std::array<volatile long, 90>,  \
    std::array<volatile long long, 90>,  \
    std::array<volatile unsigned short, 90>,  \
    std::array<volatile unsigned int, 90>,  \
    std::array<volatile unsigned long, 90>,  \
    std::array<volatile unsigned long long, 90>,  \
    std::array<volatile float, 90>, std::array<volatile double, 90>,  \
    std::array<volatile long double, 90>, std::array<char, 91>,  \
    std::array<wchar_t, 91>, std::array<char8_t, 91>,  \
    std::array<char16_t, 91>, std::array<char32_t, 91>,  \
    std::array<short, 91>, std::array<int, 91>, std::array<long, 91>,  \
    std::array<long long, 91>, std::array<unsigned short, 91>,  \
    std::array<unsigned int, 91>, std::array<unsigned long, 91>,  \
    std::array<unsigned long long, 91>, std::array<float, 91>,  \
    std::array<double, 91>, std::array<long double, 91>,  \
    std::array<volatile char, 91>, std::array<volatile wchar_t, 91>,  \
    std::array<volatile char8_t, 91>, std::array<volatile char16_t, 91>,  \
    std::array<volatile char32_t, 91>, std::array<volatile short, 91>,  \
    std::array<volatile int, 91>, std::array<volatile long, 91>,  \
    std::array<volatile long long, 91>,  \
    std::array<volatile unsigned short, 91>,  \
    std::array<volatile unsigned int, 91>,  \
    std::array<volatile unsigned long, 91>,  \
    std::array<volatile unsigned long long, 91>,  \
    std::array<volatile float, 91>, std::array<volatile double, 91>,  \
    std::array<volatile long double, 91>, std::array<char, 92>,  \
    std::array<wchar_t, 92>, std::array<char8_t, 92>,  \
    std::array<char16_t, 92>, std::array<char32_t, 92>,  \
    std::array<short, 92>, std::array<int, 92>, std::array<long, 92>,  \
    std::array<long long, 92>, std::array<unsigned short, 92>,  \
    std::array<unsigned int, 92>, std::array<unsigned long, 92>,  \
    std::array<unsigned long long, 92>, std::array<float, 92>,  \
    std::array<double, 92>, std::array<long double, 92>,  \
    std::array<volatile char, 92>, std::array<volatile wchar_t, 92>,  \
    std::array<volatile char8_t, 92>, std::array<volatile char16_t, 92>,  \
    std::array<volatile char32_t, 92>, std::array<volatile short, 92>,  \
    std::array<volatile int, 92>, std::array<volatile long, 92>,  \
    std::array<volatile long long, 92>,  \
    std::array<volatile unsigned short, 92>,  \
    std::array<volatile unsigned int, 92>,  \
    std::array<volatile unsigned long, 92>,  \
    std::array<volatile unsigned long long, 92>,  \
    std::array<volatile float, 92>, std::array<volatile double, 92>,  \
    std::array<volatile long double, 92>, std::array<char, 93>,  \
    std::array<wchar_t, 93>, std::array<char8_t, 93>,  \
    std::array<char16_t, 93>, std::array<char32_t, 93>,  \
    std::array<short, 93>, std::array<int, 93>, std::array<long, 93>,  \
    std::array<long long, 93>, std::array<unsigned short, 93>,  \
    std::array<unsigned int, 93>, std::array<unsigned long, 93>,  \
    std::array<unsigned long long, 93>, std::array<float, 93>,  \
    std::array<double, 93>, std::array<long double, 93>,  \
    std::array<volatile char, 93>, std::array<volatile wchar_t, 93>,  \
    std::array<volatile char8_t, 93>, std::array<volatile char16_t, 93>,  \
    std::array<volatile char32_t, 93>, std::array<volatile short, 93>,  \
    std::array<volatile int, 93>, std::array<volatile long, 93>,  \
    std::array<volatile long long, 93>,  \
    std::array<volatile unsigned short, 93>,  \
    std::array<volatile unsigned int, 93>,  \
    std::array<volatile unsigned long, 93>,  \
    std::array<volatile unsigned long long, 93>,  \
    std::array<volatile float, 93>, std::array<volatile double, 93>,  \
    std::array<volatile long double, 93>, std::array<char, 94>,  \
    std::array<wchar_t, 94>, std::array<char8_t, 94>,  \
    std::array<char16_t, 94>, std::array<char32_t, 94>,  \
    std::array<short, 94>, std::array<int, 94>, std::array<long, 94>,  \
    std::array<long long, 94>, std::array<unsigned short, 94>,  \
    std::array<unsigned int, 94>, std::array<unsigned long, 94>,  \
    std::array<unsigned long long, 94>, std::array<float, 94>,  \
    std::array<double, 94>, std::array<long double, 94>,  \
    std::array<volatile char, 94>, std::array<volatile wchar_t, 94>,  \
    std::array<volatile char8_t, 94>, std::array<volatile char16_t, 94>,  \
    std::array<volatile char32_t, 94>, std::array<volatile short, 94>,  \
    std::array<volatile int, 94>, std::array<volatile long, 94>,  \
    std::array<volatile long long, 94>,  \
    std::array<volatile unsigned short, 94>,  \
    std::array<volatile unsigned int, 94>,  \
    std::array<volatile unsigned long, 94>,  \
    std::array<volatile unsigned long long, 94>,  \
    std::array<volatile float, 94>, std::array<volatile double, 94>,  \
    std::array<volatile long double, 94>, std::array<char, 95>,  \
    std::array<wchar_t, 95>, std::array<char8_t, 95>,  \
    std::array<char16_t, 95>, std::array<char32_t, 95>,  \
    std::array<short, 95>, std::array<int, 95>, std::array<long, 95>,  \
    std::array<long long, 95>, std::array<unsigned short, 95>,  \
    std::array<unsigned int, 95>, std::array<unsigned long, 95>,  \
    std::array<unsigned long long, 95>, std::array<float, 95>,  \
    std::array<double, 95>, std::array<long double, 95>,  \
    std::array<volatile char, 95>, std::array<volatile wchar_t, 95>,  \
    std::array<volatile char8_t, 95>, std::array<volatile char16_t, 95>,  \
    std::array<volatile char32_t, 95>, std::array<volatile short, 95>,  \
    std::array<volatile int, 95>, std::array<volatile long, 95>,  \
    std::array<volatile long long, 95>,  \
    std::array<volatile unsigned short, 95>,  \
    std::array<volatile unsigned int, 95>,  \
    std::array<volatile unsigned long, 95>,  \
    std::array<volatile unsigned long long, 95>,  \
    std::array<volatile float, 95>, std::array<volatile double, 95>,  \
    std::array<volatile long double, 95>, std::array<char, 96>,  \
    std::array<wchar_t, 96>, std::array<char8_t, 96>,  \
    std::array<char16_t, 96>, std::array<char32_t, 96>,  \
    std::array<short, 96>, std::array<int, 96>, std::array<long, 96>,  \
    std::array<long long, 96>, std::array<unsigned short, 96>,  \
    std::array<unsigned int, 96>, std::array<unsigned long, 96>,  \
    std::array<unsigned long long, 96>, std::array<float, 96>,  \
    std::array<double, 96>, std::array<long double, 96>,  \
    std::array<volatile char, 96>, std::array<volatile wchar_t, 96>,  \
    std::array<volatile char8_t, 96>, std::array<volatile char16_t, 96>,  \
    std::array<volatile char32_t, 96>, std::array<volatile short, 96>,  \
    std::array<volatile int, 96>, std::array<volatile long, 96>,  \
    std::array<volatile long long, 96>,  \
    std::array<volatile unsigned short, 96>,  \
    std::array<volatile unsigned int, 96>,  \
    std::array<volatile unsigned long, 96>,  \
    std::array<volatile unsigned long long, 96>,  \
    std::array<volatile float, 96>, std::array<volatile double, 96>,  \
    std::array<volatile long double, 96>, std::array<char, 97>,  \
    std::array<wchar_t, 97>, std::array<char8_t, 97>,  \
    std::array<char16_t, 97>, std::array<char32_t, 97>,  \
    std::array<short, 97>, std::array<int, 97>, std::array<long, 97>,  \
    std::array<long long, 97>, std::array<unsigned short, 97>,  \
    std::array<unsigned int, 97>, std::array<unsigned long, 97>,  \
    std::array<unsigned long long, 97>, std::array<float, 97>,  \
    std::array<double, 97>, std::array<long double, 97>,  \
    std::array<volatile char, 97>, std::array<volatile wchar_t, 97>,  \
    std::array<volatile char8_t, 97>, std::array<volatile char16_t, 97>,  \
    std::array<volatile char32_t, 97>, std::array<volatile short, 97>,  \
    std::array<volatile int, 97>, std::array<volatile long, 97>,  \
    std::array<volatile long long, 97>,  \
    std::array<volatile unsigned short, 97>,  \
    std::array<volatile unsigned int, 97>,  \
    std::array<volatile unsigned long, 97>,  \
    std::array<volatile unsigned long long, 97>,  \
    std::array<volatile float, 97>, std::array<volatile double, 97>,  \
    std::array<volatile long double, 97>, std::array<char, 98>,  \
    std::array<wchar_t, 98>, std::array<char8_t, 98>,  \
    std::array<char16_t, 98>, std::array<char32_t, 98>,  \
    std::array<short, 98>, std::array<int, 98>, std::array<long, 98>,  \
    std::array<long long, 98>, std::array<unsigned short, 98>,  \
    std::array<unsigned int, 98>, std::array<unsigned long, 98>,  \
    std::array<unsigned long long, 98>, std::array<float, 98>,  \
    std::array<double, 98>, std::array<long double, 98>,  \
    std::array<volatile char, 98>, std::array<volatile wchar_t, 98>,  \
    std::array<volatile char8_t, 98>, std::array<volatile char16_t, 98>,  \
    std::array<volatile char32_t, 98>, std::array<volatile short, 98>,  \
    std::array<volatile int, 98>, std::array<volatile long, 98>,  \
    std::array<volatile long long, 98>,  \
    std::array<volatile unsigned short, 98>,  \
    std::array<volatile unsigned int, 98>,  \
    std::array<volatile unsigned long, 98>,  \
    std::array<volatile unsigned long long, 98>,  \
    std::array<volatile float, 98>, std::array<volatile double, 98>,  \
    std::array<volatile long double, 98>, std::array<char, 99>,  \
    std::array<wchar_t, 99>, std::array<char8_t, 99>,  \
    std::array<char16_t, 99>, std::array<char32_t, 99>,  \
    std::array<short, 99>, std::array<int, 99>, std::array<long, 99>,  \
    std::array<long long, 99>, std::array<unsigned short, 99>,  \
    std::array<unsigned int, 99>, std::array<unsigned long, 99>,  \
    std::array<unsigned long long, 99>, std::array<float, 99>,  \
    std::array<double, 99>, std::array<long double, 99>,  \
    std::array<volatile char, 99>, std::array<volatile wchar_t, 99>,  \
    std::array<volatile char8_t, 99>, std::array<volatile char16_t, 99>,  \
    std::array<volatile char32_t, 99>, std::array<volatile short, 99>,  \
    std::array<volatile int, 99>, std::array<volatile long, 99>,  \
    std::array<volatile long long, 99>,  \
    std::array<volatile unsigned short, 99>,  \
    std::array<volatile unsigned int, 99>,  \
    std::array<volatile unsigned long, 99>,  \
    std::array<volatile unsigned long long, 99>,  \
    std::array<volatile float, 99>, std::array<volatile double, 99>,  \
    std::array<volatile long double, 99>, std::array<char, 100>,  \
    std::array<wchar_t, 100>, std::array<char8_t, 100>,  \
    std::array<char16_t, 100>, std::array<char32_t, 100>,  \
    std::array<short, 100>, std::array<int, 100>, std::array<long, 100>,  \
    std::array<long long, 100>, std::array<unsigned short, 100>,  \
    std::array<unsigned int, 100>, std::array<unsigned long, 100>,  \
    std::array<unsigned long long, 100>, std::array<float, 100>,  \
    std::array<double, 100>, std::array<long double, 100>,  \
    std::array<volatile char, 100>, std::array<volatile wchar_t, 100>,  \
    std::array<volatile char8_t, 100>, std::array<volatile char16_t, 100>,  \
    std::array<volatile char32_t, 100>, std::array<volatile short, 100>,  \
    std::array<volatile int, 100>, std::array<volatile long, 100>,  \
    std::array<volatile long long, 100>,  \
    std::array<volatile unsigned short, 100>,  \
    std::array<volatile unsigned int, 100>,  \
    std::array<volatile unsigned long, 100>,  \
    std::array<volatile unsigned long long, 100>,  \
    std::array<volatile float, 100>, std::array<volatile double, 100>,  \
    std::array<volatile long double, 100>, std::map<char, char>,  \
    std::map<char, wchar_t>, std::map<char, char8_t>,  \
    std::map<char, char16_t>, std::map<char, char32_t>,  \
    std::map<char, short>, std::map<char, int>, std::map<char, long>,  \
    std::map<char, long long>, std::map<char, unsigned short>,  \
    std::map<char, unsigned int>, std::map<char, unsigned long>,  \
    std::map<char, unsigned long long>, std::map<char, float>,  \
    std::map<char, double>, std::map<char, long double>,  \
    std::map<char, volatile char>, std::map<char, volatile wchar_t>,  \
    std::map<char, volatile char8_t>, std::map<char, volatile char16_t>,  \
    std::map<char, volatile char32_t>, std::map<char, volatile short>,  \
    std::map<char, volatile int>, std::map<char, volatile long>,  \
    std::map<char, volatile long long>,  \
    std::map<char, volatile unsigned short>,  \
    std::map<char, volatile unsigned int>,  \
    std::map<char, volatile unsigned long>,  \
    std::map<char, volatile unsigned long long>,  \
    std::map<char, volatile float>, std::map<char, volatile double>,  \
    std::map<char, volatile long double>, std::map<wchar_t, char>,  \
    std::map<wchar_t, wchar_t>, std::map<wchar_t, char8_t>,  \
    std::map<wchar_t, char16_t>, std::map<wchar_t, char32_t>,  \
    std::map<wchar_t, short>, std::map<wchar_t, int>,  \
    std::map<wchar_t, long>, std::map<wchar_t, long long>,  \
    std::map<wchar_t, unsigned short>, std::map<wchar_t, unsigned int>,  \
    std::map<wchar_t, unsigned long>, std::map<wchar_t, unsigned long long>,  \
    std::map<wchar_t, float>, std::map<wchar_t, double>,  \
    std::map<wchar_t, long double>, std::map<wchar_t, volatile char>,  \
    std::map<wchar_t, volatile wchar_t>,  \
    std::map<wchar_t, volatile char8_t>,  \
    std::map<wchar_t, volatile char16_t>,  \
    std::map<wchar_t, volatile char32_t>, std::map<wchar_t, volatile short>,  \
    std::map<wchar_t, volatile int>, std::map<wchar_t, volatile long>,  \
    std::map<wchar_t, volatile long long>,  \
    std::map<wchar_t, volatile unsigned short>,  \
    std::map<wchar_t, volatile unsigned int>,  \
    std::map<wchar_t, volatile unsigned long>,  \
    std::map<wchar_t, volatile unsigned long long>,  \
    std::map<wchar_t, volatile float>, std::map<wchar_t, volatile double>,  \
    std::map<wchar_t, volatile long double>, std::map<char8_t, char>,  \
    std::map<char8_t, wchar_t>, std::map<char8_t, char8_t>,  \
    std::map<char8_t, char16_t>, std::map<char8_t, char32_t>,  \
    std::map<char8_t, short>, std::map<char8_t, int>,  \
    std::map<char8_t, long>, std::map<char8_t, long long>,  \
    std::map<char8_t, unsigned short>, std::map<char8_t, unsigned int>,  \
    std::map<char8_t, unsigned long>, std::map<char8_t, unsigned long long>,  \
    std::map<char8_t, float>, std::map<char8_t, double>,  \
    std::map<char8_t, long double>, std::map<char8_t, volatile char>,  \
    std::map<char8_t, volatile wchar_t>,  \
    std::map<char8_t, volatile char8_t>,  \
    std::map<char8_t, volatile char16_t>,  \
    std::map<char8_t, volatile char32_t>, std::map<char8_t, volatile short>,  \
    std::map<char8_t, volatile int>, std::map<char8_t, volatile long>,  \
    std::map<char8_t, volatile long long>,  \
    std::map<char8_t, volatile unsigned short>,  \
    std::map<char8_t, volatile unsigned int>,  \
    std::map<char8_t, volatile unsigned long>,  \
    std::map<char8_t, volatile unsigned long long>,  \
    std::map<char8_t, volatile float>, std::map<char8_t, volatile double>,  \
    std::map<char8_t, volatile long double>, std::map<char16_t, char>,  \
    std::map<char16_t, wchar_t>, std::map<char16_t, char8_t>,  \
    std::map<char16_t, char16_t>, std::map<char16_t, char32_t>,  \
    std::map<char16_t, short>, std::map<char16_t, int>,  \
    std::map<char16_t, long>, std::map<char16_t, long long>,  \
    std::map<char16_t, unsigned short>, std::map<char16_t, unsigned int>,  \
    std::map<char16_t, unsigned long>,  \
    std::map<char16_t, unsigned long long>, std::map<char16_t, float>,  \
    std::map<char16_t, double>, std::map<char16_t, long double>,  \
    std::map<char16_t, volatile char>, std::map<char16_t, volatile wchar_t>,  \
    std::map<char16_t, volatile char8_t>,  \
    std::map<char16_t, volatile char16_t>,  \
    std::map<char16_t, volatile char32_t>,  \
    std::map<char16_t, volatile short>, std::map<char16_t, volatile int>,  \
    std::map<char16_t, volatile long>,  \
    std::map<char16_t, volatile long long>,  \
    std::map<char16_t, volatile unsigned short>,  \
    std::map<char16_t, volatile unsigned int>,  \
    std::map<char16_t, volatile unsigned long>,  \
    std::map<char16_t, volatile unsigned long long>,  \
    std::map<char16_t, volatile float>, std::map<char16_t, volatile double>,  \
    std::map<char16_t, volatile long double>, std::map<char32_t, char>,  \
    std::map<char32_t, wchar_t>, std::map<char32_t, char8_t>,  \
    std::map<char32_t, char16_t>, std::map<char32_t, char32_t>,  \
    std::map<char32_t, short>, std::map<char32_t, int>,  \
    std::map<char32_t, long>, std::map<char32_t, long long>,  \
    std::map<char32_t, unsigned short>, std::map<char32_t, unsigned int>,  \
    std::map<char32_t, unsigned long>,  \
    std::map<char32_t, unsigned long long>, std::map<char32_t, float>,  \
    std::map<char32_t, double>, std::map<char32_t, long double>,  \
    std::map<char32_t, volatile char>, std::map<char32_t, volatile wchar_t>,  \
    std::map<char32_t, volatile char8_t>,  \
    std::map<char32_t, volatile char16_t>,  \
    std::map<char32_t, volatile char32_t>,  \
    std::map<char32_t, volatile short>, std::map<char32_t, volatile int>,  \
    std::map<char32_t, volatile long>,  \
    std::map<char32_t, volatile long long>,  \
    std::map<char32_t, volatile unsigned short>,  \
    std::map<char32_t, volatile unsigned int>,  \
    std::map<char32_t, volatile unsigned long>,  \
    std::map<char32_t, volatile unsigned long long>,  \
    std::map<char32_t, volatile float>, std::map<char32_t, volatile double>,  \
    std::map<char32_t, volatile long double>, std::map<short, char>,  \
    std::map<short, wchar_t>, std::map<short, char8_t>,  \
    std::map<short, char16_t>, std::map<short, char32_t>,  \
    std::map<short, short>, std::map<short, int>, std::map<short, long>,  \
    std::map<short, long long>, std::map<short, unsigned short>,  \
    std::map<short, unsigned int>, std::map<short, unsigned long>,  \
    std::map<short, unsigned long long>, std::map<short, float>,  \
    std::map<short, double>, std::map<short, long double>,  \
    std::map<short, volatile char>, std::map<short, volatile wchar_t>,  \
    std::map<short, volatile char8_t>, std::map<short, volatile char16_t>,  \
    std::map<short, volatile char32_t>, std::map<short, volatile short>,  \
    std::map<short, volatile int>, std::map<short, volatile long>,  \
    std::map<short, volatile long long>,  \
    std::map<short, volatile unsigned short>,  \
    std::map<short, volatile unsigned int>,  \
    std::map<short, volatile unsigned long>,  \
    std::map<short, volatile unsigned long long>,  \
    std::map<short, volatile float>, std::map<short, volatile double>,  \
    std::map<short, volatile long double>, std::map<int, char>,  \
    std::map<int, wchar_t>, std::map<int, char8_t>, std::map<int, char16_t>,  \
    std::map<int, char32_t>, std::map<int, short>, std::map<int, int>,  \
    std::map<int, long>, std::map<int, long long>,  \
    std::map<int, unsigned short>, std::map<int, unsigned int>,  \
    std::map<int, unsigned long>, std::map<int, unsigned long long>,  \
    std::map<int, float>, std::map<int, double>, std::map<int, long double>,  \
    std::map<int, volatile char>, std::map<int, volatile wchar_t>,  \
    std::map<int, volatile char8_t>, std::map<int, volatile char16_t>,  \
    std::map<int, volatile char32_t>, std::map<int, volatile short>,  \
    std::map<int, volatile int>, std::map<int, volatile long>,  \
    std::map<int, volatile long long>,  \
    std::map<int, volatile unsigned short>,  \
    std::map<int, volatile unsigned int>,  \
    std::map<int, volatile unsigned long>,  \
    std::map<int, volatile unsigned long long>,  \
    std::map<int, volatile float>, std::map<int, volatile double>,  \
    std::map<int, volatile long double>, std::map<long, char>,  \
    std::map<long, wchar_t>, std::map<long, char8_t>,  \
    std::map<long, char16_t>, std::map<long, char32_t>,  \
    std::map<long, short>, std::map<long, int>, std::map<long, long>,  \
    std::map<long, long long>, std::map<long, unsigned short>,  \
    std::map<long, unsigned int>, std::map<long, unsigned long>,  \
    std::map<long, unsigned long long>, std::map<long, float>,  \
    std::map<long, double>, std::map<long, long double>,  \
    std::map<long, volatile char>, std::map<long, volatile wchar_t>,  \
    std::map<long, volatile char8_t>, std::map<long, volatile char16_t>,  \
    std::map<long, volatile char32_t>, std::map<long, volatile short>,  \
    std::map<long, volatile int>, std::map<long, volatile long>,  \
    std::map<long, volatile long long>,  \
    std::map<long, volatile unsigned short>,  \
    std::map<long, volatile unsigned int>,  \
    std::map<long, volatile unsigned long>,  \
    std::map<long, volatile unsigned long long>,  \
    std::map<long, volatile float>, std::map<long, volatile double>,  \
    std::map<long, volatile long double>, std::map<long long, char>,  \
    std::map<long long, wchar_t>, std::map<long long, char8_t>,  \
    std::map<long long, char16_t>, std::map<long long, char32_t>,  \
    std::map<long long, short>, std::map<long long, int>,  \
    std::map<long long, long>, std::map<long long, long long>,  \
    std::map<long long, unsigned short>, std::map<long long, unsigned int>,  \
    std::map<long long, unsigned long>,  \
    std::map<long long, unsigned long long>, std::map<long long, float>,  \
    std::map<long long, double>, std::map<long long, long double>,  \
    std::map<long long, volatile char>,  \
    std::map<long long, volatile wchar_t>,  \
    std::map<long long, volatile char8_t>,  \
    std::map<long long, volatile char16_t>,  \
    std::map<long long, volatile char32_t>,  \
    std::map<long long, volatile short>, std::map<long long, volatile int>,  \
    std::map<long long, volatile long>,  \
    std::map<long long, volatile long long>,  \
    std::map<long long, volatile unsigned short>,  \
    std::map<long long, volatile unsigned int>,  \
    std::map<long long, volatile unsigned long>,  \
    std::map<long long, volatile unsigned long long>,  \
    std::map<long long, volatile float>,  \
    std::map<long long, volatile double>,  \
    std::map<long long, volatile long double>,  \
    std::map<unsigned short, char>, std::map<unsigned short, wchar_t>,  \
    std::map<unsigned short, char8_t>, std::map<unsigned short, char16_t>,  \
    std::map<unsigned short, char32_t>, std::map<unsigned short, short>,  \
    std::map<unsigned short, int>, std::map<unsigned short, long>,  \
    std::map<unsigned short, long long>,  \
    std::map<unsigned short, unsigned short>,  \
    std::map<unsigned short, unsigned int>,  \
    std::map<unsigned short, unsigned long>,  \
    std::map<unsigned short, unsigned long long>,  \
    std::map<unsigned short, float>, std::map<unsigned short, double>,  \
    std::map<unsigned short, long double>,  \
    std::map<unsigned short, volatile char>,  \
    std::map<unsigned short, volatile wchar_t>,  \
    std::map<unsigned short, volatile char8_t>,  \
    std::map<unsigned short, volatile char16_t>,  \
    std::map<unsigned short, volatile char32_t>,  \
    std::map<unsigned short, volatile short>,  \
    std::map<unsigned short, volatile int>,  \
    std::map<unsigned short, volatile long>,  \
    std::map<unsigned short, volatile long long>,  \
    std::map<unsigned short, volatile unsigned short>,  \
    std::map<unsigned short, volatile unsigned int>,  \
    std::map<unsigned short, volatile unsigned long>,  \
    std::map<unsigned short, volatile unsigned long long>,  \
    std::map<unsigned short, volatile float>,  \
    std::map<unsigned short, volatile double>,  \
    std::map<unsigned short, volatile long double>,  \
    std::map<unsigned int, char>, std::map<unsigned int, wchar_t>,  \
    std::map<unsigned int, char8_t>, std::map<unsigned int, char16_t>,  \
    std::map<unsigned int, char32_t>, std::map<unsigned int, short>,  \
    std::map<unsigned int, int>, std::map<unsigned int, long>,  \
    std::map<unsigned int, long long>,  \
    std::map<unsigned int, unsigned short>,  \
    std::map<unsigned int, unsigned int>,  \
    std::map<unsigned int, unsigned long>,  \
    std::map<unsigned int, unsigned long long>,  \
    std::map<unsigned int, float>, std::map<unsigned int, double>,  \
    std::map<unsigned int, long double>,  \
    std::map<unsigned int, volatile char>,  \
    std::map<unsigned int, volatile wchar_t>,  \
    std::map<unsigned int, volatile char8_t>,  \
    std::map<unsigned int, volatile char16_t>,  \
    std::map<unsigned int, volatile char32_t>,  \
    std::map<unsigned int, volatile short>,  \
    std::map<unsigned int, volatile int>,  \
    std::map<unsigned int, volatile long>,  \
    std::map<unsigned int, volatile long long>,  \
    std::map<unsigned int, volatile unsigned short>,  \
    std::map<unsigned int, volatile unsigned int>,  \
    std::map<unsigned int, volatile unsigned long>,  \
    std::map<unsigned int, volatile unsigned long long>,  \
    std::map<unsigned int, volatile float>,  \
    std::map<unsigned int, volatile double>,  \
    std::map<unsigned int, volatile long double>,  \
    std::map<unsigned long, char>, std::map<unsigned long, wchar_t>,  \
    std::map<unsigned long, char8_t>, std::map<unsigned long, char16_t>,  \
    std::map<unsigned long, char32_t>, std::map<unsigned long, short>,  \
    std::map<unsigned long, int>, std::map<unsigned long, long>,  \
    std::map<unsigned long, long long>,  \
    std::map<unsigned long, unsigned short>,  \
    std::map<unsigned long, unsigned int>,  \
    std::map<unsigned long, unsigned long>,  \
    std::map<unsigned long, unsigned long long>,  \
    std::map<unsigned long, float>, std::map<unsigned long, double>,  \
    std::map<unsigned long, long double>,  \
    std::map<unsigned long, volatile char>,  \
    std::map<unsigned long, volatile wchar_t>,  \
    std::map<unsigned long, volatile char8_t>,  \
    std::map<unsigned long, volatile char16_t>,  \
    std::map<unsigned long, volatile char32_t>,  \
    std::map<unsigned long, volatile short>,  \
    std::map<unsigned long, volatile int>,  \
    std::map<unsigned long, volatile long>,  \
    std::map<unsigned long, volatile long long>,  \
    std::map<unsigned long, volatile unsigned short>,  \
    std::map<unsigned long, volatile unsigned int>,  \
    std::map<unsigned long, volatile unsigned long>,  \
    std::map<unsigned long, volatile unsigned long long>,  \
    std::map<unsigned long, volatile float>,  \
    std::map<unsigned long, volatile double>,  \
    std::map<unsigned long, volatile long double>,  \
    std::map<unsigned long long, char>,  \
    std::map<unsigned long long, wchar_t>,  \
    std::map<unsigned long long, char8_t>,  \
    std::map<unsigned long long, char16_t>,  \
    std::map<unsigned long long, char32_t>,  \
    std::map<unsigned long long, short>, std::map<unsigned long long, int>,  \
    std::map<unsigned long long, long>,  \
    std::map<unsigned long long, long long>,  \
    std::map<unsigned long long, unsigned short>,  \
    std::map<unsigned long long, unsigned int>,  \
    std::map<unsigned long long, unsigned long>,  \
    std::map<unsigned long long, unsigned long long>,  \
    std::map<unsigned long long, float>,  \
    std::map<unsigned long long, double>,  \
    std::map<unsigned long long, long double>,  \
    std::map<unsigned long long, volatile char>,  \
    std::map<unsigned long long, volatile wchar_t>,  \
    std::map<unsigned long long, volatile char8_t>,  \
    std::map<unsigned long long, volatile char16_t>,  \
    std::map<unsigned long long, volatile char32_t>,  \
    std::map<unsigned long long, volatile short>,  \
    std::map<unsigned long long, volatile int>,  \
    std::map<unsigned long long, volatile long>,  \
    std::map<unsigned long long, volatile long long>,  \
    std::map<unsigned long long, volatile unsigned short>,  \
    std::map<unsigned long long, volatile unsigned int>,  \
    std::map<unsigned long long, volatile unsigned long>,  \
    std::map<unsigned long long, volatile unsigned long long>,  \
    std::map<unsigned long long, volatile float>,  \
    std::map<unsigned long long, volatile double>,  \
    std::map<unsigned long long, volatile long double>,  \
    std::map<float, char>, std::map<float, wchar_t>,  \
    std::map<float, char8_t>, std::map<float, char16_t>,  \
    std::map<float, char32_t>, std::map<float, short>, std::map<float, int>,  \
    std::map<float, long>, std::map<float, long long>,  \
    std::map<float, unsigned short>, std::map<float, unsigned int>,  \
    std::map<float, unsigned long>, std::map<float, unsigned long long>,  \
    std::map<float, float>, std::map<float, double>,  \
    std::map<float, long double>, std::map<float, volatile char>,  \
    std::map<float, volatile wchar_t>, std::map<float, volatile char8_t>,  \
    std::map<float, volatile char16_t>, std::map<float, volatile char32_t>,  \
    std::map<float, volatile short>, std::map<float, volatile int>,  \
    std::map<float, volatile long>, std::map<float, volatile long long>,  \
    std::map<float, volatile unsigned short>,  \
    std::map<float, volatile unsigned int>,  \
    std::map<float, volatile unsigned long>,  \
    std::map<float, volatile unsigned long long>,  \
    std::map<float, volatile float>, std::map<float, volatile double>,  \
    std::map<float, volatile long double>, std::map<double, char>,  \
    std::map<double, wchar_t>, std::map<double, char8_t>,  \
    std::map<double, char16_t>, std::map<double, char32_t>,  \
    std::map<double, short>, std::map<double, int>, std::map<double, long>,  \
    std::map<double, long long>, std::map<double, unsigned short>,  \
    std::map<double, unsigned int>, std::map<double, unsigned long>,  \
    std::map<double, unsigned long long>, std::map<double, float>,  \
    std::map<double, double>, std::map<double, long double>,  \
    std::map<double, volatile char>, std::map<double, volatile wchar_t>,  \
    std::map<double, volatile char8_t>, std::map<double, volatile char16_t>,  \
    std::map<double, volatile char32_t>, std::map<double, volatile short>,  \
    std::map<double, volatile int>, std::map<double, volatile long>,  \
    std::map<double, volatile long long>,  \
    std::map<double, volatile unsigned short>,  \
    std::map<double, volatile unsigned int>,  \
    std::map<double, volatile unsigned long>,  \
    std::map<double, volatile unsigned long long>,  \
    std::map<double, volatile float>, std::map<double, volatile double>,  \
    std::map<double, volatile long double>, std::map<long double, char>,  \
    std::map<long double, wchar_t>, std::map<long double, char8_t>,  \
    std::map<long double, char16_t>, std::map<long double, char32_t>,  \
    std::map<long double, short>, std::map<long double, int>,  \
    std::map<long double, long>, std::map<long double, long long>,  \
    std::map<long double, unsigned short>,  \
    std::map<long double, unsigned int>,  \
    std::map<long double, unsigned long>,  \
    std::map<long double, unsigned long long>, std::map<long double, float>,  \
    std::map<long double, double>, std::map<long double, long double>,  \
    std::map<long double, volatile char>,  \
    std::map<long double, volatile wchar_t>,  \
    std::map<long double, volatile char8_t>,  \
    std::map<long double, volatile char16_t>,  \
    std::map<long double, volatile char32_t>,  \
    std::map<long double, volatile short>,  \
    std::map<long double, volatile int>,  \
    std::map<long double, volatile long>,  \
    std::map<long double, volatile long long>,  \
    std::map<long double, volatile unsigned short>,  \
    std::map<long double, volatile unsigned int>,  \
    std::map<long double, volatile unsigned long>,  \
    std::map<long double, volatile unsigned long long>,  \
    std::map<long double, volatile float>,  \
    std::map<long double, volatile double>,  \
    std::map<long double, volatile long double>,  \
    std::map<volatile char, char>, std::map<volatile char, wchar_t>,  \
    std::map<volatile char, char8_t>, std::map<volatile char, char16_t>,  \
    std::map<volatile char, char32_t>, std::map<volatile char, short>,  \
    std::map<volatile char, int>, std::map<volatile char, long>,  \
    std::map<volatile char, long long>,  \
    std::map<volatile char, unsigned short>,  \
    std::map<volatile char, unsigned int>,  \
    std::map<volatile char, unsigned long>,  \
    std::map<volatile char, unsigned long long>,  \
    std::map<volatile char, float>, std::map<volatile char, double>,  \
    std::map<volatile char, long double>,  \
    std::map<volatile char, volatile char>,  \
    std::map<volatile char, volatile wchar_t>,  \
    std::map<volatile char, volatile char8_t>,  \
    std::map<volatile char, volatile char16_t>,  \
    std::map<volatile char, volatile char32_t>,  \
    std::map<volatile char, volatile short>,  \
    std::map<volatile char, volatile int>,  \
    std::map<volatile char, volatile long>,  \
    std::map<volatile char, volatile long long>,  \
    std::map<volatile char, volatile unsigned short>,  \
    std::map<volatile char, volatile unsigned int>,  \
    std::map<volatile char, volatile unsigned long>,  \
    std::map<volatile char, volatile unsigned long long>,  \
    std::map<volatile char, volatile float>,  \
    std::map<volatile char, volatile double>,  \
    std::map<volatile char, volatile long double>,  \
    std::map<volatile wchar_t, char>, std::map<volatile wchar_t, wchar_t>,  \
    std::map<volatile wchar_t, char8_t>,  \
    std::map<volatile wchar_t, char16_t>,  \
    std::map<volatile wchar_t, char32_t>, std::map<volatile wchar_t, short>,  \
    std::map<volatile wchar_t, int>, std::map<volatile wchar_t, long>,  \
    std::map<volatile wchar_t, long long>,  \
    std::map<volatile wchar_t, unsigned short>,  \
    std::map<volatile wchar_t, unsigned int>,  \
    std::map<volatile wchar_t, unsigned long>,  \
    std::map<volatile wchar_t, unsigned long long>,  \
    std::map<volatile wchar_t, float>, std::map<volatile wchar_t, double>,  \
    std::map<volatile wchar_t, long double>,  \
    std::map<volatile wchar_t, volatile char>,  \
    std::map<volatile wchar_t, volatile wchar_t>,  \
    std::map<volatile wchar_t, volatile char8_t>,  \
    std::map<volatile wchar_t, volatile char16_t>,  \
    std::map<volatile wchar_t, volatile char32_t>,  \
    std::map<volatile wchar_t, volatile short>,  \
    std::map<volatile wchar_t, volatile int>,  \
    std::map<volatile wchar_t, volatile long>,  \
    std::map<volatile wchar_t, volatile long long>,  \
    std::map<volatile wchar_t, volatile unsigned short>,  \
    std::map<volatile wchar_t, volatile unsigned int>,  \
    std::map<volatile wchar_t, volatile unsigned long>,  \
    std::map<volatile wchar_t, volatile unsigned long long>,  \
    std::map<volatile wchar_t, volatile float>,  \
    std::map<volatile wchar_t, volatile double>,  \
    std::map<volatile wchar_t, volatile long double>,  \
    std::map<volatile char8_t, char>, std::map<volatile char8_t, wchar_t>,  \
    std::map<volatile char8_t, char8_t>,  \
    std::map<volatile char8_t, char16_t>,  \
    std::map<volatile char8_t, char32_t>, std::map<volatile char8_t, short>,  \
    std::map<volatile char8_t, int>, std::map<volatile char8_t, long>,  \
    std::map<volatile char8_t, long long>,  \
    std::map<volatile char8_t, unsigned short>,  \
    std::map<volatile char8_t, unsigned int>,  \
    std::map<volatile char8_t, unsigned long>,  \
    std::map<volatile char8_t, unsigned long long>,  \
    std::map<volatile char8_t, float>, std::map<volatile char8_t, double>,  \
    std::map<volatile char8_t, long double>,  \
    std::map<volatile char8_t, volatile char>,  \
    std::map<volatile char8_t, volatile wchar_t>,  \
    std::map<volatile char8_t, volatile char8_t>,  \
    std::map<volatile char8_t, volatile char16_t>,  \
    std::map<volatile char8_t, volatile char32_t>,  \
    std::map<volatile char8_t, volatile short>,  \
    std::map<volatile char8_t, volatile int>,  \
    std::map<volatile char8_t, volatile long>,  \
    std::map<volatile char8_t, volatile long long>,  \
    std::map<volatile char8_t, volatile unsigned short>,  \
    std::map<volatile char8_t, volatile unsigned int>,  \
    std::map<volatile char8_t, volatile unsigned long>,  \
    std::map<volatile char8_t, volatile unsigned long long>,  \
    std::map<volatile char8_t, volatile float>,  \
    std::map<volatile char8_t, volatile double>,  \
    std::map<volatile char8_t, volatile long double>,  \
    std::map<volatile char16_t, char>, std::map<volatile char16_t, wchar_t>,  \
    std::map<volatile char16_t, char8_t>,  \
    std::map<volatile char16_t, char16_t>,  \
    std::map<volatile char16_t, char32_t>,  \
    std::map<volatile char16_t, short>, std::map<volatile char16_t, int>,  \
    std::map<volatile char16_t, long>,  \
    std::map<volatile char16_t, long long>,  \
    std::map<volatile char16_t, unsigned short>,  \
    std::map<volatile char16_t, unsigned int>,  \
    std::map<volatile char16_t, unsigned long>,  \
    std::map<volatile char16_t, unsigned long long>,  \
    std::map<volatile char16_t, float>, std::map<volatile char16_t, double>,  \
    std::map<volatile char16_t, long double>,  \
    std::map<volatile char16_t, volatile char>,  \
    std::map<volatile char16_t, volatile wchar_t>,  \
    std::map<volatile char16_t, volatile char8_t>,  \
    std::map<volatile char16_t, volatile char16_t>,  \
    std::map<volatile char16_t, volatile char32_t>,  \
    std::map<volatile char16_t, volatile short>,  \
    std::map<volatile char16_t, volatile int>,  \
    std::map<volatile char16_t, volatile long>,  \
    std::map<volatile char16_t, volatile long long>,  \
    std::map<volatile char16_t, volatile unsigned short>,  \
    std::map<volatile char16_t, volatile unsigned int>,  \
    std::map<volatile char16_t, volatile unsigned long>,  \
    std::map<volatile char16_t, volatile unsigned long long>,  \
    std::map<volatile char16_t, volatile float>,  \
    std::map<volatile char16_t, volatile double>,  \
    std::map<volatile char16_t, volatile long double>,  \
    std::map<volatile char32_t, char>, std::map<volatile char32_t, wchar_t>,  \
    std::map<volatile char32_t, char8_t>,  \
    std::map<volatile char32_t, char16_t>,  \
    std::map<volatile char32_t, char32_t>,  \
    std::map<volatile char32_t, short>, std::map<volatile char32_t, int>,  \
    std::map<volatile char32_t, long>,  \
    std::map<volatile char32_t, long long>,  \
    std::map<volatile char32_t, unsigned short>,  \
    std::map<volatile char32_t, unsigned int>,  \
    std::map<volatile char32_t, unsigned long>,  \
    std::map<volatile char32_t, unsigned long long>,  \
    std::map<volatile char32_t, float>, std::map<volatile char32_t, double>,  \
    std::map<volatile char32_t, long double>,  \
    std::map<volatile char32_t, volatile char>,  \
    std::map<volatile char32_t, volatile wchar_t>,  \
    std::map<volatile char32_t, volatile char8_t>,  \
    std::map<volatile char32_t, volatile char16_t>,  \
    std::map<volatile char32_t, volatile char32_t>,  \
    std::map<volatile char32_t, volatile short>,  \
    std::map<volatile char32_t, volatile int>,  \
    std::map<volatile char32_t, volatile long>,  \
    std::map<volatile char32_t, volatile long long>,  \
    std::map<volatile char32_t, volatile unsigned short>,  \
    std::map<volatile char32_t, volatile unsigned int>,  \
    std::map<volatile char32_t, volatile unsigned long>,  \
    std::map<volatile char32_t, volatile unsigned long long>,  \
    std::map<volatile char32_t, volatile float>,  \
    std::map<volatile char32_t, volatile double>,  \
    std::map<volatile char32_t, volatile long double>,  \
    std::map<volatile short, char>, std::map<volatile short, wchar_t>,  \
    std::map<volatile short, char8_t>, std::map<volatile short, char16_t>,  \
    std::map<volatile short, char32_t>, std::map<volatile short, short>,  \
    std::map<volatile short, int>, std::map<volatile short, long>,  \
    std::map<volatile short, long long>,  \
    std::map<volatile short, unsigned short>,  \
    std::map<volatile short, unsigned int>,  \
    std::map<volatile short, unsigned long>,  \
    std::map<volatile short, unsigned long long>,  \
    std::map<volatile short, float>, std::map<volatile short, double>,  \
    std::map<volatile short, long double>,  \
    std::map<volatile short, volatile char>,  \
    std::map<volatile short, volatile wchar_t>,  \
    std::map<volatile short, volatile char8_t>,  \
    std::map<volatile short, volatile char16_t>,  \
    std::map<volatile short, volatile char32_t>,  \
    std::map<volatile short, volatile short>,  \
    std::map<volatile short, volatile int>,  \
    std::map<volatile short, volatile long>,  \
    std::map<volatile short, volatile long long>,  \
    std::map<volatile short, volatile unsigned short>,  \
    std::map<volatile short, volatile unsigned int>,  \
    std::map<volatile short, volatile unsigned long>,  \
    std::map<volatile short, volatile unsigned long long>,  \
    std::map<volatile short, volatile float>,  \
    std::map<volatile short, volatile double>,  \
    std::map<volatile short, volatile long double>,  \
    std::map<volatile int, char>, std::map<volatile int, wchar_t>,  \
    std::map<volatile int, char8_t>, std::map<volatile int, char16_t>,  \
    std::map<volatile int, char32_t>, std::map<volatile int, short>,  \
    std::map<volatile int, int>, std::map<volatile int, long>,  \
    std::map<volatile int, long long>,  \
    std::map<volatile int, unsigned short>,  \
    std::map<volatile int, unsigned int>,  \
    std::map<volatile int, unsigned long>,  \
    std::map<volatile int, unsigned long long>,  \
    std::map<volatile int, float>, std::map<volatile int, double>,  \
    std::map<volatile int, long double>,  \
    std::map<volatile int, volatile char>,  \
    std::map<volatile int, volatile wchar_t>,  \
    std::map<volatile int, volatile char8_t>,  \
    std::map<volatile int, volatile char16_t>,  \
    std::map<volatile int, volatile char32_t>,  \
    std::map<volatile int, volatile short>,  \
    std::map<volatile int, volatile int>,  \
    std::map<volatile int, volatile long>,  \
    std::map<volatile int, volatile long long>,  \
    std::map<volatile int, volatile unsigned short>,  \
    std::map<volatile int, volatile unsigned int>,  \
    std::map<volatile int, volatile unsigned long>,  \
    std::map<volatile int, volatile unsigned long long>,  \
    std::map<volatile int, volatile float>,  \
    std::map<volatile int, volatile double>,  \
    std::map<volatile int, volatile long double>,  \
    std::map<volatile long, char>, std::map<volatile long, wchar_t>,  \
    std::map<volatile long, char8_t>, std::map<volatile long, char16_t>,  \
    std::map<volatile long, char32_t>, std::map<volatile long, short>,  \
    std::map<volatile long, int>, std::map<volatile long, long>,  \
    std::map<volatile long, long long>,  \
    std::map<volatile long, unsigned short>,  \
    std::map<volatile long, unsigned int>,  \
    std::map<volatile long, unsigned long>,  \
    std::map<volatile long, unsigned long long>,  \
    std::map<volatile long, float>, std::map<volatile long, double>,  \
    std::map<volatile long, long double>,  \
    std::map<volatile long, volatile char>,  \
    std::map<volatile long, volatile wchar_t>,  \
    std::map<volatile long, volatile char8_t>,  \
    std::map<volatile long, volatile char16_t>,  \
    std::map<volatile long, volatile char32_t>,  \
    std::map<volatile long, volatile short>,  \
    std::map<volatile long, volatile int>,  \
    std::map<volatile long, volatile long>,  \
    std::map<volatile long, volatile long long>,  \
    std::map<volatile long, volatile unsigned short>,  \
    std::map<volatile long, volatile unsigned int>,  \
    std::map<volatile long, volatile unsigned long>,  \
    std::map<volatile long, volatile unsigned long long>,  \
    std::map<volatile long, volatile float>,  \
    std::map<volatile long, volatile double>,  \
    std::map<volatile long, volatile long double>,  \
    std::map<volatile long long, char>,  \
    std::map<volatile long long, wchar_t>,  \
    std::map<volatile long long, char8_t>,  \
    std::map<volatile long long, char16_t>,  \
    std::map<volatile long long, char32_t>,  \
    std::map<volatile long long, short>, std::map<volatile long long, int>,  \
    std::map<volatile long long, long>,  \
    std::map<volatile long long, long long>,  \
    std::map<volatile long long, unsigned short>,  \
    std::map<volatile long long, unsigned int>,  \
    std::map<volatile long long, unsigned long>,  \
    std::map<volatile long long, unsigned long long>,  \
    std::map<volatile long long, float>,  \
    std::map<volatile long long, double>,  \
    std::map<volatile long long, long double>,  \
    std::map<volatile long long, volatile char>,  \
    std::map<volatile long long, volatile wchar_t>,  \
    std::map<volatile long long, volatile char8_t>,  \
    std::map<volatile long long, volatile char16_t>,  \
    std::map<volatile long long, volatile char32_t>,  \
    std::map<volatile long long, volatile short>,  \
    std::map<volatile long long, volatile int>,  \
    std::map<volatile long long, volatile long>,  \
    std::map<volatile long long, volatile long long>,  \
    std::map<volatile long long, volatile unsigned short>,  \
    std::map<volatile long long, volatile unsigned int>,  \
    std::map<volatile long long, volatile unsigned long>,  \
    std::map<volatile long long, volatile unsigned long long>,  \
    std::map<volatile long long, volatile float>,  \
    std::map<volatile long long, volatile double>,  \
    std::map<volatile long long, volatile long double>,  \
    std::map<volatile unsigned short, char>,  \
    std::map<volatile unsigned short, wchar_t>,  \
    std::map<volatile unsigned short, char8_t>,  \
    std::map<volatile unsigned short, char16_t>,  \
    std::map<volatile unsigned short, char32_t>,  \
    std::map<volatile unsigned short, short>,  \
    std::map<volatile unsigned short, int>,  \
    std::map<volatile unsigned short, long>,  \
    std::map<volatile unsigned short, long long>,  \
    std::map<volatile unsigned short, unsigned short>,  \
    std::map<volatile unsigned short, unsigned int>,  \
    std::map<volatile unsigned short, unsigned long>,  \
    std::map<volatile unsigned short, unsigned long long>,  \
    std::map<volatile unsigned short, float>,  \
    std::map<volatile unsigned short, double>,  \
    std::map<volatile unsigned short, long double>,  \
    std::map<volatile unsigned short, volatile char>,  \
    std::map<volatile unsigned short, volatile wchar_t>,  \
    std::map<volatile unsigned short, volatile char8_t>,  \
    std::map<volatile unsigned short, volatile char16_t>,  \
    std::map<volatile unsigned short, volatile char32_t>,  \
    std::map<volatile unsigned short, volatile short>,  \
    std::map<volatile unsigned short, volatile int>,  \
    std::map<volatile unsigned short, volatile long>,  \
    std::map<volatile unsigned short, volatile long long>,  \
    std::map<volatile unsigned short, volatile unsigned short>,  \
    std::map<volatile unsigned short, volatile unsigned int>,  \
    std::map<volatile unsigned short, volatile unsigned long>,  \
    std::map<volatile unsigned short, volatile unsigned long long>,  \
    std::map<volatile unsigned short, volatile float>,  \
    std::map<volatile unsigned short, volatile double>,  \
    std::map<volatile unsigned short, volatile long double>,  \
    std::map<volatile unsigned int, char>,  \
    std::map<volatile unsigned int, wchar_t>,  \
    std::map<volatile unsigned int, char8_t>,  \
    std::map<volatile unsigned int, char16_t>,  \
    std::map<volatile unsigned int, char32_t>,  \
    std::map<volatile unsigned int, short>,  \
    std::map<volatile unsigned int, int>,  \
    std::map<volatile unsigned int, long>,  \
    std::map<volatile unsigned int, long long>,  \
    std::map<volatile unsigned int, unsigned short>,  \
    std::map<volatile unsigned int, unsigned int>,  \
    std::map<volatile unsigned int, unsigned long>,  \
    std::map<volatile unsigned int, unsigned long long>,  \
    std::map<volatile unsigned int, float>,  \
    std::map<volatile unsigned int, double>,  \
    std::map<volatile unsigned int, long double>,  \
    std::map<volatile unsigned int, volatile char>,  \
    std::map<volatile unsigned int, volatile wchar_t>,  \
    std::map<volatile unsigned int, volatile char8_t>,  \
    std::map<volatile unsigned int, volatile char16_t>,  \
    std::map<volatile unsigned int, volatile char32_t>,  \
    std::map<volatile unsigned int, volatile short>,  \
    std::map<volatile unsigned int, volatile int>,  \
    std::map<volatile unsigned int, volatile long>,  \
    std::map<volatile unsigned int, volatile long long>,  \
    std::map<volatile unsigned int, volatile unsigned short>,  \
    std::map<volatile unsigned int, volatile unsigned int>,  \
    std::map<volatile unsigned int, volatile unsigned long>,  \
    std::map<volatile unsigned int, volatile unsigned long long>,  \
    std::map<volatile unsigned int, volatile float>,  \
    std::map<volatile unsigned int, volatile double>,  \
    std::map<volatile unsigned int, volatile long double>,  \
    std::map<volatile unsigned long, char>,  \
    std::map<volatile unsigned long, wchar_t>,  \
    std::map<volatile unsigned long, char8_t>,  \
    std::map<volatile unsigned long, char16_t>,  \
    std::map<volatile unsigned long, char32_t>,  \
    std::map<volatile unsigned long, short>,  \
    std::map<volatile unsigned long, int>,  \
    std::map<volatile unsigned long, long>,  \
    std::map<volatile unsigned long, long long>,  \
    std::map<volatile unsigned long, unsigned short>,  \
    std::map<volatile unsigned long, unsigned int>,  \
    std::map<volatile unsigned long, unsigned long>,  \
    std::map<volatile unsigned long, unsigned long long>,  \
    std::map<volatile unsigned long, float>,  \
    std::map<volatile unsigned long, double>,  \
    std::map<volatile unsigned long, long double>,  \
    std::map<volatile unsigned long, volatile char>,  \
    std::map<volatile unsigned long, volatile wchar_t>,  \
    std::map<volatile unsigned long, volatile char8_t>,  \
    std::map<volatile unsigned long, volatile char16_t>,  \
    std::map<volatile unsigned long, volatile char32_t>,  \
    std::map<volatile unsigned long, volatile short>,  \
    std::map<volatile unsigned long, volatile int>,  \
    std::map<volatile unsigned long, volatile long>,  \
    std::map<volatile unsigned long, volatile long long>,  \
    std::map<volatile unsigned long, volatile unsigned short>,  \
    std::map<volatile unsigned long, volatile unsigned int>,  \
    std::map<volatile unsigned long, volatile unsigned long>,  \
    std::map<volatile unsigned long, volatile unsigned long long>,  \
    std::map<volatile unsigned long, volatile float>,  \
    std::map<volatile unsigned long, volatile double>,  \
    std::map<volatile unsigned long, volatile long double>,  \
    std::map<volatile unsigned long long, char>,  \
    std::map<volatile unsigned long long, wchar_t>,  \
    std::map<volatile unsigned long long, char8_t>,  \
    std::map<volatile unsigned long long, char16_t>,  \
    std::map<volatile unsigned long long, char32_t>,  \
    std::map<volatile unsigned long long, short>,  \
    std::map<volatile unsigned long long, int>,  \
    std::map<volatile unsigned long long, long>,  \
    std::map<volatile unsigned long long, long long>,  \
    std::map<volatile unsigned long long, unsigned short>,  \
    std::map<volatile unsigned long long, unsigned int>,  \
    std::map<volatile unsigned long long, unsigned long>,  \
    std::map<volatile unsigned long long, unsigned long long>,  \
    std::map<volatile unsigned long long, float>,  \
    std::map<volatile unsigned long long, double>,  \
    std::map<volatile unsigned long long, long double>,  \
    std::map<volatile unsigned long long, volatile char>,  \
    std::map<volatile unsigned long long, volatile wchar_t>,  \
    std::map<volatile unsigned long long, volatile char8_t>,  \
    std::map<volatile unsigned long long, volatile char16_t>,  \
    std::map<volatile unsigned long long, volatile char32_t>,  \
    std::map<volatile unsigned long long, volatile short>,  \
    std::map<volatile unsigned long long, volatile int>,  \
    std::map<volatile unsigned long long, volatile long>,  \
    std::map<volatile unsigned long long, volatile long long>,  \
    std::map<volatile unsigned long long, volatile unsigned short>,  \
    std::map<volatile unsigned long long, volatile unsigned int>,  \
    std::map<volatile unsigned long long, volatile unsigned long>,  \
    std::map<volatile unsigned long long, volatile unsigned long long>,  \
    std::map<volatile unsigned long long, volatile float>,  \
    std::map<volatile unsigned long long, volatile double>,  \
    std::map<volatile unsigned long long, volatile long double>,  \
    std::map<volatile float, char>, std::map<volatile float, wchar_t>,  \
    std::map<volatile float, char8_t>, std::map<volatile float, char16_t>,  \
    std::map<volatile float, char32_t>, std::map<volatile float, short>,  \
    std::map<volatile float, int>, std::map<volatile float, long>,  \
    std::map<volatile float, long long>,  \
    std::map<volatile float, unsigned short>,  \
    std::map<volatile float, unsigned int>,  \
    std::map<volatile float, unsigned long>,  \
    std::map<volatile float, unsigned long long>,  \
    std::map<volatile float, float>, std::map<volatile float, double>,  \
    std::map<volatile float, long double>,  \
    std::map<volatile float, volatile char>,  \
    std::map<volatile float, volatile wchar_t>,  \
    std::map<volatile float, volatile char8_t>,  \
    std::map<volatile float, volatile char16_t>,  \
    std::map<volatile float, volatile char32_t>,  \
    std::map<volatile float, volatile short>,  \
    std::map<volatile float, volatile int>,  \
    std::map<volatile float, volatile long>,  \
    std::map<volatile float, volatile long long>,  \
    std::map<volatile float, volatile unsigned short>,  \
    std::map<volatile float, volatile unsigned int>,  \
    std::map<volatile float, volatile unsigned long>,  \
    std::map<volatile float, volatile unsigned long long>,  \
    std::map<volatile float, volatile float>,  \
    std::map<volatile float, volatile double>,  \
    std::map<volatile float, volatile long double>,  \
    std::map<volatile double, char>, std::map<volatile double, wchar_t>,  \
    std::map<volatile double, char8_t>, std::map<volatile double, char16_t>,  \
    std::map<volatile double, char32_t>, std::map<volatile double, short>,  \
    std::map<volatile double, int>, std::map<volatile double, long>,  \
    std::map<volatile double, long long>,  \
    std::map<volatile double, unsigned short>,  \
    std::map<volatile double, unsigned int>,  \
    std::map<volatile double, unsigned long>,  \
    std::map<volatile double, unsigned long long>,  \
    std::map<volatile double, float>, std::map<volatile double, double>,  \
    std::map<volatile double, long double>,  \
    std::map<volatile double, volatile char>,  \
    std::map<volatile double, volatile wchar_t>,  \
    std::map<volatile double, volatile char8_t>,  \
    std::map<volatile double, volatile char16_t>,  \
    std::map<volatile double, volatile char32_t>,  \
    std::map<volatile double, volatile short>,  \
    std::map<volatile double, volatile int>,  \
    std::map<volatile double, volatile long>,  \
    std::map<volatile double, volatile long long>,  \
    std::map<volatile double, volatile unsigned short>,  \
    std::map<volatile double, volatile unsigned int>,  \
    std::map<volatile double, volatile unsigned long>,  \
    std::map<volatile double, volatile unsigned long long>,  \
    std::map<volatile double, volatile float>,  \
    std::map<volatile double, volatile double>,  \
    std::map<volatile double, volatile long double>,  \
    std::map<volatile long double, char>,  \
    std::map<volatile long double, wchar_t>,  \
    std::map<volatile long double, char8_t>,  \
    std::map<volatile long double, char16_t>,  \
    std::map<volatile long double, char32_t>,  \
    std::map<volatile long double, short>,  \
    std::map<volatile long double, int>,  \
    std::map<volatile long double, long>,  \
    std::map<volatile long double, long long>,  \
    std::map<volatile long double, unsigned short>,  \
    std::map<volatile long double, unsigned int>,  \
    std::map<volatile long double, unsigned long>,  \
    std::map<volatile long double, unsigned long long>,  \
    std::map<volatile long double, float>,  \
    std::map<volatile long double, double>,  \
    std::map<volatile long double, long double>,  \
    std::map<volatile long double, volatile char>,  \
    std::map<volatile long double, volatile wchar_t>,  \
    std::map<volatile long double, volatile char8_t>,  \
    std::map<volatile long double, volatile char16_t>,  \
    std::map<volatile long double, volatile char32_t>,  \
    std::map<volatile long double, volatile short>,  \
    std::map<volatile long double, volatile int>,  \
    std::map<volatile long double, volatile long>,  \
    std::map<volatile long double, volatile long long>,  \
    std::map<volatile long double, volatile unsigned short>,  \
    std::map<volatile long double, volatile unsigned int>,  \
    std::map<volatile long double, volatile unsigned long>,  \
    std::map<volatile long double, volatile unsigned long long>,  \
    std::map<volatile long double, volatile float>,  \
    std::map<volatile long double, volatile double>,  \
    std::map<volatile long double, volatile long double>,  \
    std::unordered_map<char, char>, std::unordered_map<char, wchar_t>,  \
    std::unordered_map<char, char8_t>, std::unordered_map<char, char16_t>,  \
    std::unordered_map<char, char32_t>, std::unordered_map<char, short>,  \
    std::unordered_map<char, int>, std::unordered_map<char, long>,  \
    std::unordered_map<char, long long>,  \
    std::unordered_map<char, unsigned short>,  \
    std::unordered_map<char, unsigned int>,  \
    std::unordered_map<char, unsigned long>,  \
    std::unordered_map<char, unsigned long long>,  \
    std::unordered_map<char, float>, std::unordered_map<char, double>,  \
    std::unordered_map<char, long double>,  \
    std::unordered_map<char, volatile char>,  \
    std::unordered_map<char, volatile wchar_t>,  \
    std::unordered_map<char, volatile char8_t>,  \
    std::unordered_map<char, volatile char16_t>,  \
    std::unordered_map<char, volatile char32_t>,  \
    std::unordered_map<char, volatile short>,  \
    std::unordered_map<char, volatile int>,  \
    std::unordered_map<char, volatile long>,  \
    std::unordered_map<char, volatile long long>,  \
    std::unordered_map<char, volatile unsigned short>,  \
    std::unordered_map<char, volatile unsigned int>,  \
    std::unordered_map<char, volatile unsigned long>,  \
    std::unordered_map<char, volatile unsigned long long>,  \
    std::unordered_map<char, volatile float>,  \
    std::unordered_map<char, volatile double>,  \
    std::unordered_map<char, volatile long double>,  \
    std::unordered_map<wchar_t, char>, std::unordered_map<wchar_t, wchar_t>,  \
    std::unordered_map<wchar_t, char8_t>,  \
    std::unordered_map<wchar_t, char16_t>,  \
    std::unordered_map<wchar_t, char32_t>,  \
    std::unordered_map<wchar_t, short>, std::unordered_map<wchar_t, int>,  \
    std::unordered_map<wchar_t, long>,  \
    std::unordered_map<wchar_t, long long>,  \
    std::unordered_map<wchar_t, unsigned short>,  \
    std::unordered_map<wchar_t, unsigned int>,  \
    std::unordered_map<wchar_t, unsigned long>,  \
    std::unordered_map<wchar_t, unsigned long long>,  \
    std::unordered_map<wchar_t, float>, std::unordered_map<wchar_t, double>,  \
    std::unordered_map<wchar_t, long double>,  \
    std::unordered_map<wchar_t, volatile char>,  \
    std::unordered_map<wchar_t, volatile wchar_t>,  \
    std::unordered_map<wchar_t, volatile char8_t>,  \
    std::unordered_map<wchar_t, volatile char16_t>,  \
    std::unordered_map<wchar_t, volatile char32_t>,  \
    std::unordered_map<wchar_t, volatile short>,  \
    std::unordered_map<wchar_t, volatile int>,  \
    std::unordered_map<wchar_t, volatile long>,  \
    std::unordered_map<wchar_t, volatile long long>,  \
    std::unordered_map<wchar_t, volatile unsigned short>,  \
    std::unordered_map<wchar_t, volatile unsigned int>,  \
    std::unordered_map<wchar_t, volatile unsigned long>,  \
    std::unordered_map<wchar_t, volatile unsigned long long>,  \
    std::unordered_map<wchar_t, volatile float>,  \
    std::unordered_map<wchar_t, volatile double>,  \
    std::unordered_map<wchar_t, volatile long double>,  \
    std::unordered_map<char8_t, char>, std::unordered_map<char8_t, wchar_t>,  \
    std::unordered_map<char8_t, char8_t>,  \
    std::unordered_map<char8_t, char16_t>,  \
    std::unordered_map<char8_t, char32_t>,  \
    std::unordered_map<char8_t, short>, std::unordered_map<char8_t, int>,  \
    std::unordered_map<char8_t, long>,  \
    std::unordered_map<char8_t, long long>,  \
    std::unordered_map<char8_t, unsigned short>,  \
    std::unordered_map<char8_t, unsigned int>,  \
    std::unordered_map<char8_t, unsigned long>,  \
    std::unordered_map<char8_t, unsigned long long>,  \
    std::unordered_map<char8_t, float>, std::unordered_map<char8_t, double>,  \
    std::unordered_map<char8_t, long double>,  \
    std::unordered_map<char8_t, volatile char>,  \
    std::unordered_map<char8_t, volatile wchar_t>,  \
    std::unordered_map<char8_t, volatile char8_t>,  \
    std::unordered_map<char8_t, volatile char16_t>,  \
    std::unordered_map<char8_t, volatile char32_t>,  \
    std::unordered_map<char8_t, volatile short>,  \
    std::unordered_map<char8_t, volatile int>,  \
    std::unordered_map<char8_t, volatile long>,  \
    std::unordered_map<char8_t, volatile long long>,  \
    std::unordered_map<char8_t, volatile unsigned short>,  \
    std::unordered_map<char8_t, volatile unsigned int>,  \
    std::unordered_map<char8_t, volatile unsigned long>,  \
    std::unordered_map<char8_t, volatile unsigned long long>,  \
    std::unordered_map<char8_t, volatile float>,  \
    std::unordered_map<char8_t, volatile double>,  \
    std::unordered_map<char8_t, volatile long double>,  \
    std::unordered_map<char16_t, char>,  \
    std::unordered_map<char16_t, wchar_t>,  \
    std::unordered_map<char16_t, char8_t>,  \
    std::unordered_map<char16_t, char16_t>,  \
    std::unordered_map<char16_t, char32_t>,  \
    std::unordered_map<char16_t, short>, std::unordered_map<char16_t, int>,  \
    std::unordered_map<char16_t, long>,  \
    std::unordered_map<char16_t, long long>,  \
    std::unordered_map<char16_t, unsigned short>,  \
    std::unordered_map<char16_t, unsigned int>,  \
    std::unordered_map<char16_t, unsigned long>,  \
    std::unordered_map<char16_t, unsigned long long>,  \
    std::unordered_map<char16_t, float>,  \
    std::unordered_map<char16_t, double>,  \
    std::unordered_map<char16_t, long double>,  \
    std::unordered_map<char16_t, volatile char>,  \
    std::unordered_map<char16_t, volatile wchar_t>,  \
    std::unordered_map<char16_t, volatile char8_t>,  \
    std::unordered_map<char16_t, volatile char16_t>,  \
    std::unordered_map<char16_t, volatile char32_t>,  \
    std::unordered_map<char16_t, volatile short>,  \
    std::unordered_map<char16_t, volatile int>,  \
    std::unordered_map<char16_t, volatile long>,  \
    std::unordered_map<char16_t, volatile long long>,  \
    std::unordered_map<char16_t, volatile unsigned short>,  \
    std::unordered_map<char16_t, volatile unsigned int>,  \
    std::unordered_map<char16_t, volatile unsigned long>,  \
    std::unordered_map<char16_t, volatile unsigned long long>,  \
    std::unordered_map<char16_t, volatile float>,  \
    std::unordered_map<char16_t, volatile double>,  \
    std::unordered_map<char16_t, volatile long double>,  \
    std::unordered_map<char32_t, char>,  \
    std::unordered_map<char32_t, wchar_t>,  \
    std::unordered_map<char32_t, char8_t>,  \
    std::unordered_map<char32_t, char16_t>,  \
    std::unordered_map<char32_t, char32_t>,  \
    std::unordered_map<char32_t, short>, std::unordered_map<char32_t, int>,  \
    std::unordered_map<char32_t, long>,  \
    std::unordered_map<char32_t, long long>,  \
    std::unordered_map<char32_t, unsigned short>,  \
    std::unordered_map<char32_t, unsigned int>,  \
    std::unordered_map<char32_t, unsigned long>,  \
    std::unordered_map<char32_t, unsigned long long>,  \
    std::unordered_map<char32_t, float>,  \
    std::unordered_map<char32_t, double>,  \
    std::unordered_map<char32_t, long double>,  \
    std::unordered_map<char32_t, volatile char>,  \
    std::unordered_map<char32_t, volatile wchar_t>,  \
    std::unordered_map<char32_t, volatile char8_t>,  \
    std::unordered_map<char32_t, volatile char16_t>,  \
    std::unordered_map<char32_t, volatile char32_t>,  \
    std::unordered_map<char32_t, volatile short>,  \
    std::unordered_map<char32_t, volatile int>,  \
    std::unordered_map<char32_t, volatile long>,  \
    std::unordered_map<char32_t, volatile long long>,  \
    std::unordered_map<char32_t, volatile unsigned short>,  \
    std::unordered_map<char32_t, volatile unsigned int>,  \
    std::unordered_map<char32_t, volatile unsigned long>,  \
    std::unordered_map<char32_t, volatile unsigned long long>,  \
    std::unordered_map<char32_t, volatile float>,  \
    std::unordered_map<char32_t, volatile double>,  \
    std::unordered_map<char32_t, volatile long double>,  \
    std::unordered_map<short, char>, std::unordered_map<short, wchar_t>,  \
    std::unordered_map<short, char8_t>, std::unordered_map<short, char16_t>,  \
    std::unordered_map<short, char32_t>, std::unordered_map<short, short>,  \
    std::unordered_map<short, int>, std::unordered_map<short, long>,  \
    std::unordered_map<short, long long>,  \
    std::unordered_map<short, unsigned short>,  \
    std::unordered_map<short, unsigned int>,  \
    std::unordered_map<short, unsigned long>,  \
    std::unordered_map<short, unsigned long long>,  \
    std::unordered_map<short, float>, std::unordered_map<short, double>,  \
    std::unordered_map<short, long double>,  \
    std::unordered_map<short, volatile char>,  \
    std::unordered_map<short, volatile wchar_t>,  \
    std::unordered_map<short, volatile char8_t>,  \
    std::unordered_map<short, volatile char16_t>,  \
    std::unordered_map<short, volatile char32_t>,  \
    std::unordered_map<short, volatile short>,  \
    std::unordered_map<short, volatile int>,  \
    std::unordered_map<short, volatile long>,  \
    std::unordered_map<short, volatile long long>,  \
    std::unordered_map<short, volatile unsigned short>,  \
    std::unordered_map<short, volatile unsigned int>,  \
    std::unordered_map<short, volatile unsigned long>,  \
    std::unordered_map<short, volatile unsigned long long>,  \
    std::unordered_map<short, volatile float>,  \
    std::unordered_map<short, volatile double>,  \
    std::unordered_map<short, volatile long double>,  \
    std::unordered_map<int, char>, std::unordered_map<int, wchar_t>,  \
    std::unordered_map<int, char8_t>, std::unordered_map<int, char16_t>,  \
    std::unordered_map<int, char32_t>, std::unordered_map<int, short>,  \
    std::unordered_map<int, int>, std::unordered_map<int, long>,  \
    std::unordered_map<int, long long>,  \
    std::unordered_map<int, unsigned short>,  \
    std::unordered_map<int, unsigned int>,  \
    std::unordered_map<int, unsigned long>,  \
    std::unordered_map<int, unsigned long long>,  \
    std::unordered_map<int, float>, std::unordered_map<int, double>,  \
    std::unordered_map<int, long double>,  \
    std::unordered_map<int, volatile char>,  \
    std::unordered_map<int, volatile wchar_t>,  \
    std::unordered_map<int, volatile char8_t>,  \
    std::unordered_map<int, volatile char16_t>,  \
    std::unordered_map<int, volatile char32_t>,  \
    std::unordered_map<int, volatile short>,  \
    std::unordered_map<int, volatile int>,  \
    std::unordered_map<int, volatile long>,  \
    std::unordered_map<int, volatile long long>,  \
    std::unordered_map<int, volatile unsigned short>,  \
    std::unordered_map<int, volatile unsigned int>,  \
    std::unordered_map<int, volatile unsigned long>,  \
    std::unordered_map<int, volatile unsigned long long>,  \
    std::unordered_map<int, volatile float>,  \
    std::unordered_map<int, volatile double>,  \
    std::unordered_map<int, volatile long double>,  \
    std::unordered_map<long, char>, std::unordered_map<long, wchar_t>,  \
    std::unordered_map<long, char8_t>, std::unordered_map<long, char16_t>,  \
    std::unordered_map<long, char32_t>, std::unordered_map<long, short>,  \
    std::unordered_map<long, int>, std::unordered_map<long, long>,  \
    std::unordered_map<long, long long>,  \
    std::unordered_map<long, unsigned short>,  \
    std::unordered_map<long, unsigned int>,  \
    std::unordered_map<long, unsigned long>,  \
    std::unordered_map<long, unsigned long long>,  \
    std::unordered_map<long, float>, std::unordered_map<long, double>,  \
    std::unordered_map<long, long double>,  \
    std::unordered_map<long, volatile char>,  \
    std::unordered_map<long, volatile wchar_t>,  \
    std::unordered_map<long, volatile char8_t>,  \
    std::unordered_map<long, volatile char16_t>,  \
    std::unordered_map<long, volatile char32_t>,  \
    std::unordered_map<long, volatile short>,  \
    std::unordered_map<long, volatile int>,  \
    std::unordered_map<long, volatile long>,  \
    std::unordered_map<long, volatile long long>,  \
    std::unordered_map<long, volatile unsigned short>,  \
    std::unordered_map<long, volatile unsigned int>,  \
    std::unordered_map<long, volatile unsigned long>,  \
    std::unordered_map<long, volatile unsigned long long>,  \
    std::unordered_map<long, volatile float>,  \
    std::unordered_map<long, volatile double>,  \
    std::unordered_map<long, volatile long double>,  \
    std::unordered_map<long long, char>,  \
    std::unordered_map<long long, wchar_t>,  \
    std::unordered_map<long long, char8_t>,  \
    std::unordered_map<long long, char16_t>,  \
    std::unordered_map<long long, char32_t>,  \
    std::unordered_map<long long, short>,  \
    std::unordered_map<long long, int>, std::unordered_map<long long, long>,  \
    std::unordered_map<long long, long long>,  \
    std::unordered_map<long long, unsigned short>,  \
    std::unordered_map<long long, unsigned int>,  \
    std::unordered_map<long long, unsigned long>,  \
    std::unordered_map<long long, unsigned long long>,  \
    std::unordered_map<long long, float>,  \
    std::unordered_map<long long, double>,  \
    std::unordered_map<long long, long double>,  \
    std::unordered_map<long long, volatile char>,  \
    std::unordered_map<long long, volatile wchar_t>,  \
    std::unordered_map<long long, volatile char8_t>,  \
    std::unordered_map<long long, volatile char16_t>,  \
    std::unordered_map<long long, volatile char32_t>,  \
    std::unordered_map<long long, volatile short>,  \
    std::unordered_map<long long, volatile int>,  \
    std::unordered_map<long long, volatile long>,  \
    std::unordered_map<long long, volatile long long>,  \
    std::unordered_map<long long, volatile unsigned short>,  \
    std::unordered_map<long long, volatile unsigned int>,  \
    std::unordered_map<long long, volatile unsigned long>,  \
    std::unordered_map<long long, volatile unsigned long long>,  \
    std::unordered_map<long long, volatile float>,  \
    std::unordered_map<long long, volatile double>,  \
    std::unordered_map<long long, volatile long double>,  \
    std::unordered_map<unsigned short, char>,  \
    std::unordered_map<unsigned short, wchar_t>,  \
    std::unordered_map<unsigned short, char8_t>,  \
    std::unordered_map<unsigned short, char16_t>,  \
    std::unordered_map<unsigned short, char32_t>,  \
    std::unordered_map<unsigned short, short>,  \
    std::unordered_map<unsigned short, int>,  \
    std::unordered_map<unsigned short, long>,  \
    std::unordered_map<unsigned short, long long>,  \
    std::unordered_map<unsigned short, unsigned short>,  \
    std::unordered_map<unsigned short, unsigned int>,  \
    std::unordered_map<unsigned short, unsigned long>,  \
    std::unordered_map<unsigned short, unsigned long long>,  \
    std::unordered_map<unsigned short, float>,  \
    std::unordered_map<unsigned short, double>,  \
    std::unordered_map<unsigned short, long double>,  \
    std::unordered_map<unsigned short, volatile char>,  \
    std::unordered_map<unsigned short, volatile wchar_t>,  \
    std::unordered_map<unsigned short, volatile char8_t>,  \
    std::unordered_map<unsigned short, volatile char16_t>,  \
    std::unordered_map<unsigned short, volatile char32_t>,  \
    std::unordered_map<unsigned short, volatile short>,  \
    std::unordered_map<unsigned short, volatile int>,  \
    std::unordered_map<unsigned short, volatile long>,  \
    std::unordered_map<unsigned short, volatile long long>,  \
    std::unordered_map<unsigned short, volatile unsigned short>,  \
    std::unordered_map<unsigned short, volatile unsigned int>,  \
    std::unordered_map<unsigned short, volatile unsigned long>,  \
    std::unordered_map<unsigned short, volatile unsigned long long>,  \
    std::unordered_map<unsigned short, volatile float>,  \
    std::unordered_map<unsigned short, volatile double>,  \
    std::unordered_map<unsigned short, volatile long double>,  \
    std::unordered_map<unsigned int, char>,  \
    std::unordered_map<unsigned int, wchar_t>,  \
    std::unordered_map<unsigned int, char8_t>,  \
    std::unordered_map<unsigned int, char16_t>,  \
    std::unordered_map<unsigned int, char32_t>,  \
    std::unordered_map<unsigned int, short>,  \
    std::unordered_map<unsigned int, int>,  \
    std::unordered_map<unsigned int, long>,  \
    std::unordered_map<unsigned int, long long>,  \
    std::unordered_map<unsigned int, unsigned short>,  \
    std::unordered_map<unsigned int, unsigned int>,  \
    std::unordered_map<unsigned int, unsigned long>,  \
    std::unordered_map<unsigned int, unsigned long long>,  \
    std::unordered_map<unsigned int, float>,  \
    std::unordered_map<unsigned int, double>,  \
    std::unordered_map<unsigned int, long double>,  \
    std::unordered_map<unsigned int, volatile char>,  \
    std::unordered_map<unsigned int, volatile wchar_t>,  \
    std::unordered_map<unsigned int, volatile char8_t>,  \
    std::unordered_map<unsigned int, volatile char16_t>,  \
    std::unordered_map<unsigned int, volatile char32_t>,  \
    std::unordered_map<unsigned int, volatile short>,  \
    std::unordered_map<unsigned int, volatile int>,  \
    std::unordered_map<unsigned int, volatile long>,  \
    std::unordered_map<unsigned int, volatile long long>,  \
    std::unordered_map<unsigned int, volatile unsigned short>,  \
    std::unordered_map<unsigned int, volatile unsigned int>,  \
    std::unordered_map<unsigned int, volatile unsigned long>,  \
    std::unordered_map<unsigned int, volatile unsigned long long>,  \
    std::unordered_map<unsigned int, volatile float>,  \
    std::unordered_map<unsigned int, volatile double>,  \
    std::unordered_map<unsigned int, volatile long double>,  \
    std::unordered_map<unsigned long, char>,  \
    std::unordered_map<unsigned long, wchar_t>,  \
    std::unordered_map<unsigned long, char8_t>,  \
    std::unordered_map<unsigned long, char16_t>,  \
    std::unordered_map<unsigned long, char32_t>,  \
    std::unordered_map<unsigned long, short>,  \
    std::unordered_map<unsigned long, int>,  \
    std::unordered_map<unsigned long, long>,  \
    std::unordered_map<unsigned long, long long>,  \
    std::unordered_map<unsigned long, unsigned short>,  \
    std::unordered_map<unsigned long, unsigned int>,  \
    std::unordered_map<unsigned long, unsigned long>,  \
    std::unordered_map<unsigned long, unsigned long long>,  \
    std::unordered_map<unsigned long, float>,  \
    std::unordered_map<unsigned long, double>,  \
    std::unordered_map<unsigned long, long double>,  \
    std::unordered_map<unsigned long, volatile char>,  \
    std::unordered_map<unsigned long, volatile wchar_t>,  \
    std::unordered_map<unsigned long, volatile char8_t>,  \
    std::unordered_map<unsigned long, volatile char16_t>,  \
    std::unordered_map<unsigned long, volatile char32_t>,  \
    std::unordered_map<unsigned long, volatile short>,  \
    std::unordered_map<unsigned long, volatile int>,  \
    std::unordered_map<unsigned long, volatile long>,  \
    std::unordered_map<unsigned long, volatile long long>,  \
    std::unordered_map<unsigned long, volatile unsigned short>,  \
    std::unordered_map<unsigned long, volatile unsigned int>,  \
    std::unordered_map<unsigned long, volatile unsigned long>,  \
    std::unordered_map<unsigned long, volatile unsigned long long>,  \
    std::unordered_map<unsigned long, volatile float>,  \
    std::unordered_map<unsigned long, volatile double>,  \
    std::unordered_map<unsigned long, volatile long double>,  \
    std::unordered_map<unsigned long long, char>,  \
    std::unordered_map<unsigned long long, wchar_t>,  \
    std::unordered_map<unsigned long long, char8_t>,  \
    std::unordered_map<unsigned long long, char16_t>,  \
    std::unordered_map<unsigned long long, char32_t>,  \
    std::unordered_map<unsigned long long, short>,  \
    std::unordered_map<unsigned long long, int>,  \
    std::unordered_map<unsigned long long, long>,  \
    std::unordered_map<unsigned long long, long long>,  \
    std::unordered_map<unsigned long long, unsigned short>,  \
    std::unordered_map<unsigned long long, unsigned int>,  \
    std::unordered_map<unsigned long long, unsigned long>,  \
    std::unordered_map<unsigned long long, unsigned long long>,  \
    std::unordered_map<unsigned long long, float>,  \
    std::unordered_map<unsigned long long, double>,  \
    std::unordered_map<unsigned long long, long double>,  \
    std::unordered_map<unsigned long long, volatile char>,  \
    std::unordered_map<unsigned long long, volatile wchar_t>,  \
    std::unordered_map<unsigned long long, volatile char8_t>,  \
    std::unordered_map<unsigned long long, volatile char16_t>,  \
    std::unordered_map<unsigned long long, volatile char32_t>,  \
    std::unordered_map<unsigned long long, volatile short>,  \
    std::unordered_map<unsigned long long, volatile int>,  \
    std::unordered_map<unsigned long long, volatile long>,  \
    std::unordered_map<unsigned long long, volatile long long>,  \
    std::unordered_map<unsigned long long, volatile unsigned short>,  \
    std::unordered_map<unsigned long long, volatile unsigned int>,  \
    std::unordered_map<unsigned long long, volatile unsigned long>,  \
    std::unordered_map<unsigned long long, volatile unsigned long long>,  \
    std::unordered_map<unsigned long long, volatile float>,  \
    std::unordered_map<unsigned long long, volatile double>,  \
    std::unordered_map<unsigned long long, volatile long double>,  \
    std::unordered_map<float, char>, std::unordered_map<float, wchar_t>,  \
    std::unordered_map<float, char8_t>, std::unordered_map<float, char16_t>,  \
    std::unordered_map<float, char32_t>, std::unordered_map<float, short>,  \
    std::unordered_map<float, int>, std::unordered_map<float, long>,  \
    std::unordered_map<float, long long>,  \
    std::unordered_map<float, unsigned short>,  \
    std::unordered_map<float, unsigned int>,  \
    std::unordered_map<float, unsigned long>,  \
    std::unordered_map<float, unsigned long long>,  \
    std::unordered_map<float, float>, std::unordered_map<float, double>,  \
    std::unordered_map<float, long double>,  \
    std::unordered_map<float, volatile char>,  \
    std::unordered_map<float, volatile wchar_t>,  \
    std::unordered_map<float, volatile char8_t>,  \
    std::unordered_map<float, volatile char16_t>,  \
    std::unordered_map<float, volatile char32_t>,  \
    std::unordered_map<float, volatile short>,  \
    std::unordered_map<float, volatile int>,  \
    std::unordered_map<float, volatile long>,  \
    std::unordered_map<float, volatile long long>,  \
    std::unordered_map<float, volatile unsigned short>,  \
    std::unordered_map<float, volatile unsigned int>,  \
    std::unordered_map<float, volatile unsigned long>,  \
    std::unordered_map<float, volatile unsigned long long>,  \
    std::unordered_map<float, volatile float>,  \
    std::unordered_map<float, volatile double>,  \
    std::unordered_map<float, volatile long double>,  \
    std::unordered_map<double, char>, std::unordered_map<double, wchar_t>,  \
    std::unordered_map<double, char8_t>,  \
    std::unordered_map<double, char16_t>,  \
    std::unordered_map<double, char32_t>, std::unordered_map<double, short>,  \
    std::unordered_map<double, int>, std::unordered_map<double, long>,  \
    std::unordered_map<double, long long>,  \
    std::unordered_map<double, unsigned short>,  \
    std::unordered_map<double, unsigned int>,  \
    std::unordered_map<double, unsigned long>,  \
    std::unordered_map<double, unsigned long long>,  \
    std::unordered_map<double, float>, std::unordered_map<double, double>,  \
    std::unordered_map<double, long double>,  \
    std::unordered_map<double, volatile char>,  \
    std::unordered_map<double, volatile wchar_t>,  \
    std::unordered_map<double, volatile char8_t>,  \
    std::unordered_map<double, volatile char16_t>,  \
    std::unordered_map<double, volatile char32_t>,  \
    std::unordered_map<double, volatile short>,  \
    std::unordered_map<double, volatile int>,  \
    std::unordered_map<double, volatile long>,  \
    std::unordered_map<double, volatile long long>,  \
    std::unordered_map<double, volatile unsigned short>,  \
    std::unordered_map<double, volatile unsigned int>,  \
    std::unordered_map<double, volatile unsigned long>,  \
    std::unordered_map<double, volatile unsigned long long>,  \
    std::unordered_map<double, volatile float>,  \
    std::unordered_map<double, volatile double>,  \
    std::unordered_map<double, volatile long double>,  \
    std::unordered_map<long double, char>,  \
    std::unordered_map<long double, wchar_t>,  \
    std::unordered_map<long double, char8_t>,  \
    std::unordered_map<long double, char16_t>,  \
    std::unordered_map<long double, char32_t>,  \
    std::unordered_map<long double, short>,  \
    std::unordered_map<long double, int>,  \
    std::unordered_map<long double, long>,  \
    std::unordered_map<long double, long long>,  \
    std::unordered_map<long double, unsigned short>,  \
    std::unordered_map<long double, unsigned int>,  \
    std::unordered_map<long double, unsigned long>,  \
    std::unordered_map<long double, unsigned long long>,  \
    std::unordered_map<long double, float>,  \
    std::unordered_map<long double, double>,  \
    std::unordered_map<long double, long double>,  \
    std::unordered_map<long double, volatile char>,  \
    std::unordered_map<long double, volatile wchar_t>,  \
    std::unordered_map<long double, volatile char8_t>,  \
    std::unordered_map<long double, volatile char16_t>,  \
    std::unordered_map<long double, volatile char32_t>,  \
    std::unordered_map<long double, volatile short>,  \
    std::unordered_map<long double, volatile int>,  \
    std::unordered_map<long double, volatile long>,  \
    std::unordered_map<long double, volatile long long>,  \
    std::unordered_map<long double, volatile unsigned short>,  \
    std::unordered_map<long double, volatile unsigned int>,  \
    std::unordered_map<long double, volatile unsigned long>,  \
    std::unordered_map<long double, volatile unsigned long long>,  \
    std::unordered_map<long double, volatile float>,  \
    std::unordered_map<long double, volatile double>,  \
    std::unordered_map<long double, volatile long double>,  \
    std::unordered_map<volatile char, char>,  \
    std::unordered_map<volatile char, wchar_t>,  \
    std::unordered_map<volatile char, char8_t>,  \
    std::unordered_map<volatile char, char16_t>,  \
    std::unordered_map<volatile char, char32_t>,  \
    std::unordered_map<volatile char, short>,  \
    std::unordered_map<volatile char, int>,  \
    std::unordered_map<volatile char, long>,  \
    std::unordered_map<volatile char, long long>,  \
    std::unordered_map<volatile char, unsigned short>,  \
    std::unordered_map<volatile char, unsigned int>,  \
    std::unordered_map<volatile char, unsigned long>,  \
    std::unordered_map<volatile char, unsigned long long>,  \
    std::unordered_map<volatile char, float>,  \
    std::unordered_map<volatile char, double>,  \
    std::unordered_map<volatile char, long double>,  \
    std::unordered_map<volatile char, volatile char>,  \
    std::unordered_map<volatile char, volatile wchar_t>,  \
    std::unordered_map<volatile char, volatile char8_t>,  \
    std::unordered_map<volatile char, volatile char16_t>,  \
    std::unordered_map<volatile char, volatile char32_t>,  \
    std::unordered_map<volatile char, volatile short>,  \
    std::unordered_map<volatile char, volatile int>,  \
    std::unordered_map<volatile char, volatile long>,  \
    std::unordered_map<volatile char, volatile long long>,  \
    std::unordered_map<volatile char, volatile unsigned short>,  \
    std::unordered_map<volatile char, volatile unsigned int>,  \
    std::unordered_map<volatile char, volatile unsigned long>,  \
    std::unordered_map<volatile char, volatile unsigned long long>,  \
    std::unordered_map<volatile char, volatile float>,  \
    std::unordered_map<volatile char, volatile double>,  \
    std::unordered_map<volatile char, volatile long double>,  \
    std::unordered_map<volatile wchar_t, char>,  \
    std::unordered_map<volatile wchar_t, wchar_t>,  \
    std::unordered_map<volatile wchar_t, char8_t>,  \
    std::unordered_map<volatile wchar_t, char16_t>,  \
    std::unordered_map<volatile wchar_t, char32_t>,  \
    std::unordered_map<volatile wchar_t, short>,  \
    std::unordered_map<volatile wchar_t, int>,  \
    std::unordered_map<volatile wchar_t, long>,  \
    std::unordered_map<volatile wchar_t, long long>,  \
    std::unordered_map<volatile wchar_t, unsigned short>,  \
    std::unordered_map<volatile wchar_t, unsigned int>,  \
    std::unordered_map<volatile wchar_t, unsigned long>,  \
    std::unordered_map<volatile wchar_t, unsigned long long>,  \
    std::unordered_map<volatile wchar_t, float>,  \
    std::unordered_map<volatile wchar_t, double>,  \
    std::unordered_map<volatile wchar_t, long double>,  \
    std::unordered_map<volatile wchar_t, volatile char>,  \
    std::unordered_map<volatile wchar_t, volatile wchar_t>,  \
    std::unordered_map<volatile wchar_t, volatile char8_t>,  \
    std::unordered_map<volatile wchar_t, volatile char16_t>,  \
    std::unordered_map<volatile wchar_t, volatile char32_t>,  \
    std::unordered_map<volatile wchar_t, volatile short>,  \
    std::unordered_map<volatile wchar_t, volatile int>,  \
    std::unordered_map<volatile wchar_t, volatile long>,  \
    std::unordered_map<volatile wchar_t, volatile long long>,  \
    std::unordered_map<volatile wchar_t, volatile unsigned short>,  \
    std::unordered_map<volatile wchar_t, volatile unsigned int>,  \
    std::unordered_map<volatile wchar_t, volatile unsigned long>,  \
    std::unordered_map<volatile wchar_t, volatile unsigned long long>,  \
    std::unordered_map<volatile wchar_t, volatile float>,  \
    std::unordered_map<volatile wchar_t, volatile double>,  \
    std::unordered_map<volatile wchar_t, volatile long double>,  \
    std::unordered_map<volatile char8_t, char>,  \
    std::unordered_map<volatile char8_t, wchar_t>,  \
    std::unordered_map<volatile char8_t, char8_t>,  \
    std::unordered_map<volatile char8_t, char16_t>,  \
    std::unordered_map<volatile char8_t, char32_t>,  \
    std::unordered_map<volatile char8_t, short>,  \
    std::unordered_map<volatile char8_t, int>,  \
    std::unordered_map<volatile char8_t, long>,  \
    std::unordered_map<volatile char8_t, long long>,  \
    std::unordered_map<volatile char8_t, unsigned short>,  \
    std::unordered_map<volatile char8_t, unsigned int>,  \
    std::unordered_map<volatile char8_t, unsigned long>,  \
    std::unordered_map<volatile char8_t, unsigned long long>,  \
    std::unordered_map<volatile char8_t, float>,  \
    std::unordered_map<volatile char8_t, double>,  \
    std::unordered_map<volatile char8_t, long double>,  \
    std::unordered_map<volatile char8_t, volatile char>,  \
    std::unordered_map<volatile char8_t, volatile wchar_t>,  \
    std::unordered_map<volatile char8_t, volatile char8_t>,  \
    std::unordered_map<volatile char8_t, volatile char16_t>,  \
    std::unordered_map<volatile char8_t, volatile char32_t>,  \
    std::unordered_map<volatile char8_t, volatile short>,  \
    std::unordered_map<volatile char8_t, volatile int>,  \
    std::unordered_map<volatile char8_t, volatile long>,  \
    std::unordered_map<volatile char8_t, volatile long long>,  \
    std::unordered_map<volatile char8_t, volatile unsigned short>,  \
    std::unordered_map<volatile char8_t, volatile unsigned int>,  \
    std::unordered_map<volatile char8_t, volatile unsigned long>,  \
    std::unordered_map<volatile char8_t, volatile unsigned long long>,  \
    std::unordered_map<volatile char8_t, volatile float>,  \
    std::unordered_map<volatile char8_t, volatile double>,  \
    std::unordered_map<volatile char8_t, volatile long double>,  \
    std::unordered_map<volatile char16_t, char>,  \
    std::unordered_map<volatile char16_t, wchar_t>,  \
    std::unordered_map<volatile char16_t, char8_t>,  \
    std::unordered_map<volatile char16_t, char16_t>,  \
    std::unordered_map<volatile char16_t, char32_t>,  \
    std::unordered_map<volatile char16_t, short>,  \
    std::unordered_map<volatile char16_t, int>,  \
    std::unordered_map<volatile char16_t, long>,  \
    std::unordered_map<volatile char16_t, long long>,  \
    std::unordered_map<volatile char16_t, unsigned short>,  \
    std::unordered_map<volatile char16_t, unsigned int>,  \
    std::unordered_map<volatile char16_t, unsigned long>,  \
    std::unordered_map<volatile char16_t, unsigned long long>,  \
    std::unordered_map<volatile char16_t, float>,  \
    std::unordered_map<volatile char16_t, double>,  \
    std::unordered_map<volatile char16_t, long double>,  \
    std::unordered_map<volatile char16_t, volatile char>,  \
    std::unordered_map<volatile char16_t, volatile wchar_t>,  \
    std::unordered_map<volatile char16_t, volatile char8_t>,  \
    std::unordered_map<volatile char16_t, volatile char16_t>,  \
    std::unordered_map<volatile char16_t, volatile char32_t>,  \
    std::unordered_map<volatile char16_t, volatile short>,  \
    std::unordered_map<volatile char16_t, volatile int>,  \
    std::unordered_map<volatile char16_t, volatile long>,  \
    std::unordered_map<volatile char16_t, volatile long long>,  \
    std::unordered_map<volatile char16_t, volatile unsigned short>,  \
    std::unordered_map<volatile char16_t, volatile unsigned int>,  \
    std::unordered_map<volatile char16_t, volatile unsigned long>,  \
    std::unordered_map<volatile char16_t, volatile unsigned long long>,  \
    std::unordered_map<volatile char16_t, volatile float>,  \
    std::unordered_map<volatile char16_t, volatile double>,  \
    std::unordered_map<volatile char16_t, volatile long double>,  \
    std::unordered_map<volatile char32_t, char>,  \
    std::unordered_map<volatile char32_t, wchar_t>,  \
    std::unordered_map<volatile char32_t, char8_t>,  \
    std::unordered_map<volatile char32_t, char16_t>,  \
    std::unordered_map<volatile char32_t, char32_t>,  \
    std::unordered_map<volatile char32_t, short>,  \
    std::unordered_map<volatile char32_t, int>,  \
    std::unordered_map<volatile char32_t, long>,  \
    std::unordered_map<volatile char32_t, long long>,  \
    std::unordered_map<volatile char32_t, unsigned short>,  \
    std::unordered_map<volatile char32_t, unsigned int>,  \
    std::unordered_map<volatile char32_t, unsigned long>,  \
    std::unordered_map<volatile char32_t, unsigned long long>,  \
    std::unordered_map<volatile char32_t, float>,  \
    std::unordered_map<volatile char32_t, double>,  \
    std::unordered_map<volatile char32_t, long double>,  \
    std::unordered_map<volatile char32_t, volatile char>,  \
    std::unordered_map<volatile char32_t, volatile wchar_t>,  \
    std::unordered_map<volatile char32_t, volatile char8_t>,  \
    std::unordered_map<volatile char32_t, volatile char16_t>,  \
    std::unordered_map<volatile char32_t, volatile char32_t>,  \
    std::unordered_map<volatile char32_t, volatile short>,  \
    std::unordered_map<volatile char32_t, volatile int>,  \
    std::unordered_map<volatile char32_t, volatile long>,  \
    std::unordered_map<volatile char32_t, volatile long long>,  \
    std::unordered_map<volatile char32_t, volatile unsigned short>,  \
    std::unordered_map<volatile char32_t, volatile unsigned int>,  \
    std::unordered_map<volatile char32_t, volatile unsigned long>,  \
    std::unordered_map<volatile char32_t, volatile unsigned long long>,  \
    std::unordered_map<volatile char32_t, volatile float>,  \
    std::unordered_map<volatile char32_t, volatile double>,  \
    std::unordered_map<volatile char32_t, volatile long double>,  \
    std::unordered_map<volatile short, char>,  \
    std::unordered_map<volatile short, wchar_t>,  \
    std::unordered_map<volatile short, char8_t>,  \
    std::unordered_map<volatile short, char16_t>,  \
    std::unordered_map<volatile short, char32_t>,  \
    std::unordered_map<volatile short, short>,  \
    std::unordered_map<volatile short, int>,  \
    std::unordered_map<volatile short, long>,  \
    std::unordered_map<volatile short, long long>,  \
    std::unordered_map<volatile short, unsigned short>,  \
    std::unordered_map<volatile short, unsigned int>,  \
    std::unordered_map<volatile short, unsigned long>,  \
    std::unordered_map<volatile short, unsigned long long>,  \
    std::unordered_map<volatile short, float>,  \
    std::unordered_map<volatile short, double>,  \
    std::unordered_map<volatile short, long double>,  \
    std::unordered_map<volatile short, volatile char>,  \
    std::unordered_map<volatile short, volatile wchar_t>,  \
    std::unordered_map<volatile short, volatile char8_t>,  \
    std::unordered_map<volatile short, volatile char16_t>,  \
    std::unordered_map<volatile short, volatile char32_t>,  \
    std::unordered_map<volatile short, volatile short>,  \
    std::unordered_map<volatile short, volatile int>,  \
    std::unordered_map<volatile short, volatile long>,  \
    std::unordered_map<volatile short, volatile long long>,  \
    std::unordered_map<volatile short, volatile unsigned short>,  \
    std::unordered_map<volatile short, volatile unsigned int>,  \
    std::unordered_map<volatile short, volatile unsigned long>,  \
    std::unordered_map<volatile short, volatile unsigned long long>,  \
    std::unordered_map<volatile short, volatile float>,  \
    std::unordered_map<volatile short, volatile double>,  \
    std::unordered_map<volatile short, volatile long double>,  \
    std::unordered_map<volatile int, char>,  \
    std::unordered_map<volatile int, wchar_t>,  \
    std::unordered_map<volatile int, char8_t>,  \
    std::unordered_map<volatile int, char16_t>,  \
    std::unordered_map<volatile int, char32_t>,  \
    std::unordered_map<volatile int, short>,  \
    std::unordered_map<volatile int, int>,  \
    std::unordered_map<volatile int, long>,  \
    std::unordered_map<volatile int, long long>,  \
    std::unordered_map<volatile int, unsigned short>,  \
    std::unordered_map<volatile int, unsigned int>,  \
    std::unordered_map<volatile int, unsigned long>,  \
    std::unordered_map<volatile int, unsigned long long>,  \
    std::unordered_map<volatile int, float>,  \
    std::unordered_map<volatile int, double>,  \
    std::unordered_map<volatile int, long double>,  \
    std::unordered_map<volatile int, volatile char>,  \
    std::unordered_map<volatile int, volatile wchar_t>,  \
    std::unordered_map<volatile int, volatile char8_t>,  \
    std::unordered_map<volatile int, volatile char16_t>,  \
    std::unordered_map<volatile int, volatile char32_t>,  \
    std::unordered_map<volatile int, volatile short>,  \
    std::unordered_map<volatile int, volatile int>,  \
    std::unordered_map<volatile int, volatile long>,  \
    std::unordered_map<volatile int, volatile long long>,  \
    std::unordered_map<volatile int, volatile unsigned short>,  \
    std::unordered_map<volatile int, volatile unsigned int>,  \
    std::unordered_map<volatile int, volatile unsigned long>,  \
    std::unordered_map<volatile int, volatile unsigned long long>,  \
    std::unordered_map<volatile int, volatile float>,  \
    std::unordered_map<volatile int, volatile double>,  \
    std::unordered_map<volatile int, volatile long double>,  \
    std::unordered_map<volatile long, char>,  \
    std::unordered_map<volatile long, wchar_t>,  \
    std::unordered_map<volatile long, char8_t>,  \
    std::unordered_map<volatile long, char16_t>,  \
    std::unordered_map<volatile long, char32_t>,  \
    std::unordered_map<volatile long, short>,  \
    std::unordered_map<volatile long, int>,  \
    std::unordered_map<volatile long, long>,  \
    std::unordered_map<volatile long, long long>,  \
    std::unordered_map<volatile long, unsigned short>,  \
    std::unordered_map<volatile long, unsigned int>,  \
    std::unordered_map<volatile long, unsigned long>,  \
    std::unordered_map<volatile long, unsigned long long>,  \
    std::unordered_map<volatile long, float>,  \
    std::unordered_map<volatile long, double>,  \
    std::unordered_map<volatile long, long double>,  \
    std::unordered_map<volatile long, volatile char>,  \
    std::unordered_map<volatile long, volatile wchar_t>,  \
    std::unordered_map<volatile long, volatile char8_t>,  \
    std::unordered_map<volatile long, volatile char16_t>,  \
    std::unordered_map<volatile long, volatile char32_t>,  \
    std::unordered_map<volatile long, volatile short>,  \
    std::unordered_map<volatile long, volatile int>,  \
    std::unordered_map<volatile long, volatile long>,  \
    std::unordered_map<volatile long, volatile long long>,  \
    std::unordered_map<volatile long, volatile unsigned short>,  \
    std::unordered_map<volatile long, volatile unsigned int>,  \
    std::unordered_map<volatile long, volatile unsigned long>,  \
    std::unordered_map<volatile long, volatile unsigned long long>,  \
    std::unordered_map<volatile long, volatile float>,  \
    std::unordered_map<volatile long, volatile double>,  \
    std::unordered_map<volatile long, volatile long double>,  \
    std::unordered_map<volatile long long, char>,  \
    std::unordered_map<volatile long long, wchar_t>,  \
    std::unordered_map<volatile long long, char8_t>,  \
    std::unordered_map<volatile long long, char16_t>,  \
    std::unordered_map<volatile long long, char32_t>,  \
    std::unordered_map<volatile long long, short>,  \
    std::unordered_map<volatile long long, int>,  \
    std::unordered_map<volatile long long, long>,  \
    std::unordered_map<volatile long long, long long>,  \
    std::unordered_map<volatile long long, unsigned short>,  \
    std::unordered_map<volatile long long, unsigned int>,  \
    std::unordered_map<volatile long long, unsigned long>,  \
    std::unordered_map<volatile long long, unsigned long long>,  \
    std::unordered_map<volatile long long, float>,  \
    std::unordered_map<volatile long long, double>,  \
    std::unordered_map<volatile long long, long double>,  \
    std::unordered_map<volatile long long, volatile char>,  \
    std::unordered_map<volatile long long, volatile wchar_t>,  \
    std::unordered_map<volatile long long, volatile char8_t>,  \
    std::unordered_map<volatile long long, volatile char16_t>,  \
    std::unordered_map<volatile long long, volatile char32_t>,  \
    std::unordered_map<volatile long long, volatile short>,  \
    std::unordered_map<volatile long long, volatile int>,  \
    std::unordered_map<volatile long long, volatile long>,  \
    std::unordered_map<volatile long long, volatile long long>,  \
    std::unordered_map<volatile long long, volatile unsigned short>,  \
    std::unordered_map<volatile long long, volatile unsigned int>,  \
    std::unordered_map<volatile long long, volatile unsigned long>,  \
    std::unordered_map<volatile long long, volatile unsigned long long>,  \
    std::unordered_map<volatile long long, volatile float>,  \
    std::unordered_map<volatile long long, volatile double>,  \
    std::unordered_map<volatile long long, volatile long double>,  \
    std::unordered_map<volatile unsigned short, char>,  \
    std::unordered_map<volatile unsigned short, wchar_t>,  \
    std::unordered_map<volatile unsigned short, char8_t>,  \
    std::unordered_map<volatile unsigned short, char16_t>,  \
    std::unordered_map<volatile unsigned short, char32_t>,  \
    std::unordered_map<volatile unsigned short, short>,  \
    std::unordered_map<volatile unsigned short, int>,  \
    std::unordered_map<volatile unsigned short, long>,  \
    std::unordered_map<volatile unsigned short, long long>,  \
    std::unordered_map<volatile unsigned short, unsigned short>,  \
    std::unordered_map<volatile unsigned short, unsigned int>,  \
    std::unordered_map<volatile unsigned short, unsigned long>,  \
    std::unordered_map<volatile unsigned short, unsigned long long>,  \
    std::unordered_map<volatile unsigned short, float>,  \
    std::unordered_map<volatile unsigned short, double>,  \
    std::unordered_map<volatile unsigned short, long double>,  \
    std::unordered_map<volatile unsigned short, volatile char>,  \
    std::unordered_map<volatile unsigned short, volatile wchar_t>,  \
    std::unordered_map<volatile unsigned short, volatile char8_t>,  \
    std::unordered_map<volatile unsigned short, volatile char16_t>,  \
    std::unordered_map<volatile unsigned short, volatile char32_t>,  \
    std::unordered_map<volatile unsigned short, volatile short>,  \
    std::unordered_map<volatile unsigned short, volatile int>,  \
    std::unordered_map<volatile unsigned short, volatile long>,  \
    std::unordered_map<volatile unsigned short, volatile long long>,  \
    std::unordered_map<volatile unsigned short, volatile unsigned short>,  \
    std::unordered_map<volatile unsigned short, volatile unsigned int>,  \
    std::unordered_map<volatile unsigned short, volatile unsigned long>,  \
    std::unordered_map<volatile unsigned short, volatile unsigned long long>,  \
    std::unordered_map<volatile unsigned short, volatile float>,  \
    std::unordered_map<volatile unsigned short, volatile double>,  \
    std::unordered_map<volatile unsigned short, volatile long double>,  \
    std::unordered_map<volatile unsigned int, char>,  \
    std::unordered_map<volatile unsigned int, wchar_t>,  \
    std::unordered_map<volatile unsigned int, char8_t>,  \
    std::unordered_map<volatile unsigned int, char16_t>,  \
    std::unordered_map<volatile unsigned int, char32_t>,  \
    std::unordered_map<volatile unsigned int, short>,  \
    std::unordered_map<volatile unsigned int, int>,  \
    std::unordered_map<volatile unsigned int, long>,  \
    std::unordered_map<volatile unsigned int, long long>,  \
    std::unordered_map<volatile unsigned int, unsigned short>,  \
    std::unordered_map<volatile unsigned int, unsigned int>,  \
    std::unordered_map<volatile unsigned int, unsigned long>,  \
    std::unordered_map<volatile unsigned int, unsigned long long>,  \
    std::unordered_map<volatile unsigned int, float>,  \
    std::unordered_map<volatile unsigned int, double>,  \
    std::unordered_map<volatile unsigned int, long double>,  \
    std::unordered_map<volatile unsigned int, volatile char>,  \
    std::unordered_map<volatile unsigned int, volatile wchar_t>,  \
    std::unordered_map<volatile unsigned int, volatile char8_t>,  \
    std::unordered_map<volatile unsigned int, volatile char16_t>,  \
    std::unordered_map<volatile unsigned int, volatile char32_t>,  \
    std::unordered_map<volatile unsigned int, volatile short>,  \
    std::unordered_map<volatile unsigned int, volatile int>,  \
    std::unordered_map<volatile unsigned int, volatile long>,  \
    std::unordered_map<volatile unsigned int, volatile long long>,  \
    std::unordered_map<volatile unsigned int, volatile unsigned short>,  \
    std::unordered_map<volatile unsigned int, volatile unsigned int>,  \
    std::unordered_map<volatile unsigned int, volatile unsigned long>,  \
    std::unordered_map<volatile unsigned int, volatile unsigned long long>,  \
    std::unordered_map<volatile unsigned int, volatile float>,  \
    std::unordered_map<volatile unsigned int, volatile double>,  \
    std::unordered_map<volatile unsigned int, volatile long double>,  \
    std::unordered_map<volatile unsigned long, char>,  \
    std::unordered_map<volatile unsigned long, wchar_t>,  \
    std::unordered_map<volatile unsigned long, char8_t>,  \
    std::unordered_map<volatile unsigned long, char16_t>,  \
    std::unordered_map<volatile unsigned long, char32_t>,  \
    std::unordered_map<volatile unsigned long, short>,  \
    std::unordered_map<volatile unsigned long, int>,  \
    std::unordered_map<volatile unsigned long, long>,  \
    std::unordered_map<volatile unsigned long, long long>,  \
    std::unordered_map<volatile unsigned long, unsigned short>,  \
    std::unordered_map<volatile unsigned long, unsigned int>,  \
    std::unordered_map<volatile unsigned long, unsigned long>,  \
    std::unordered_map<volatile unsigned long, unsigned long long>,  \
    std::unordered_map<volatile unsigned long, float>,  \
    std::unordered_map<volatile unsigned long, double>,  \
    std::unordered_map<volatile unsigned long, long double>,  \
    std::unordered_map<volatile unsigned long, volatile char>,  \
    std::unordered_map<volatile unsigned long, volatile wchar_t>,  \
    std::unordered_map<volatile unsigned long, volatile char8_t>,  \
    std::unordered_map<volatile unsigned long, volatile char16_t>,  \
    std::unordered_map<volatile unsigned long, volatile char32_t>,  \
    std::unordered_map<volatile unsigned long, volatile short>,  \
    std::unordered_map<volatile unsigned long, volatile int>,  \
    std::unordered_map<volatile unsigned long, volatile long>,  \
    std::unordered_map<volatile unsigned long, volatile long long>,  \
    std::unordered_map<volatile unsigned long, volatile unsigned short>,  \
    std::unordered_map<volatile unsigned long, volatile unsigned int>,  \
    std::unordered_map<volatile unsigned long, volatile unsigned long>,  \
    std::unordered_map<volatile unsigned long, volatile unsigned long long>,  \
    std::unordered_map<volatile unsigned long, volatile float>,  \
    std::unordered_map<volatile unsigned long, volatile double>,  \
    std::unordered_map<volatile unsigned long, volatile long double>,  \
    std::unordered_map<volatile unsigned long long, char>,  \
    std::unordered_map<volatile unsigned long long, wchar_t>,  \
    std::unordered_map<volatile unsigned long long, char8_t>,  \
    std::unordered_map<volatile unsigned long long, char16_t>,  \
    std::unordered_map<volatile unsigned long long, char32_t>,  \
    std::unordered_map<volatile unsigned long long, short>,  \
    std::unordered_map<volatile unsigned long long, int>,  \
    std::unordered_map<volatile unsigned long long, long>,  \
    std::unordered_map<volatile unsigned long long, long long>,  \
    std::unordered_map<volatile unsigned long long, unsigned short>,  \
    std::unordered_map<volatile unsigned long long, unsigned int>,  \
    std::unordered_map<volatile unsigned long long, unsigned long>,  \
    std::unordered_map<volatile unsigned long long, unsigned long long>,  \
    std::unordered_map<volatile unsigned long long, float>,  \
    std::unordered_map<volatile unsigned long long, double>,  \
    std::unordered_map<volatile unsigned long long, long double>,  \
    std::unordered_map<volatile unsigned long long, volatile char>,  \
    std::unordered_map<volatile unsigned long long, volatile wchar_t>,  \
    std::unordered_map<volatile unsigned long long, volatile char8_t>,  \
    std::unordered_map<volatile unsigned long long, volatile char16_t>,  \
    std::unordered_map<volatile unsigned long long, volatile char32_t>,  \
    std::unordered_map<volatile unsigned long long, volatile short>,  \
    std::unordered_map<volatile unsigned long long, volatile int>,  \
    std::unordered_map<volatile unsigned long long, volatile long>,  \
    std::unordered_map<volatile unsigned long long, volatile long long>,  \
    std::unordered_map<volatile unsigned long long, volatile unsigned short>,  \
    std::unordered_map<volatile unsigned long long, volatile unsigned int>,  \
    std::unordered_map<volatile unsigned long long, volatile unsigned long>,  \
    std::unordered_map<volatile unsigned long long, volatile unsigned long long>,  \
    std::unordered_map<volatile unsigned long long, volatile float>,  \
    std::unordered_map<volatile unsigned long long, volatile double>,  \
    std::unordered_map<volatile unsigned long long, volatile long double>,  \
    std::unordered_map<volatile float, char>,  \
    std::unordered_map<volatile float, wchar_t>,  \
    std::unordered_map<volatile float, char8_t>,  \
    std::unordered_map<volatile float, char16_t>,  \
    std::unordered_map<volatile float, char32_t>,  \
    std::unordered_map<volatile float, short>,  \
    std::unordered_map<volatile float, int>,  \
    std::unordered_map<volatile float, long>,  \
    std::unordered_map<volatile float, long long>,  \
    std::unordered_map<volatile float, unsigned short>,  \
    std::unordered_map<volatile float, unsigned int>,  \
    std::unordered_map<volatile float, unsigned long>,  \
    std::unordered_map<volatile float, unsigned long long>,  \
    std::unordered_map<volatile float, float>,  \
    std::unordered_map<volatile float, double>,  \
    std::unordered_map<volatile float, long double>,  \
    std::unordered_map<volatile float, volatile char>,  \
    std::unordered_map<volatile float, volatile wchar_t>,  \
    std::unordered_map<volatile float, volatile char8_t>,  \
    std::unordered_map<volatile float, volatile char16_t>,  \
    std::unordered_map<volatile float, volatile char32_t>,  \
    std::unordered_map<volatile float, volatile short>,  \
    std::unordered_map<volatile float, volatile int>,  \
    std::unordered_map<volatile float, volatile long>,  \
    std::unordered_map<volatile float, volatile long long>,  \
    std::unordered_map<volatile float, volatile unsigned short>,  \
    std::unordered_map<volatile float, volatile unsigned int>,  \
    std::unordered_map<volatile float, volatile unsigned long>,  \
    std::unordered_map<volatile float, volatile unsigned long long>,  \
    std::unordered_map<volatile float, volatile float>,  \
    std::unordered_map<volatile float, volatile double>,  \
    std::unordered_map<volatile float, volatile long double>,  \
    std::unordered_map<volatile double, char>,  \
    std::unordered_map<volatile double, wchar_t>,  \
    std::unordered_map<volatile double, char8_t>,  \
    std::unordered_map<volatile double, char16_t>,  \
    std::unordered_map<volatile double, char32_t>,  \
    std::unordered_map<volatile double, short>,  \
    std::unordered_map<volatile double, int>,  \
    std::unordered_map<volatile double, long>,  \
    std::unordered_map<volatile double, long long>,  \
    std::unordered_map<volatile double, unsigned short>,  \
    std::unordered_map<volatile double, unsigned int>,  \
    std::unordered_map<volatile double, unsigned long>,  \
    std::unordered_map<volatile double, unsigned long long>,  \
    std::unordered_map<volatile double, float>,  \
    std::unordered_map<volatile double, double>,  \
    std::unordered_map<volatile double, long double>,  \
    std::unordered_map<volatile double, volatile char>,  \
    std::unordered_map<volatile double, volatile wchar_t>,  \
    std::unordered_map<volatile double, volatile char8_t>,  \
    std::unordered_map<volatile double, volatile char16_t>,  \
    std::unordered_map<volatile double, volatile char32_t>,  \
    std::unordered_map<volatile double, volatile short>,  \
    std::unordered_map<volatile double, volatile int>,  \
    std::unordered_map<volatile double, volatile long>,  \
    std::unordered_map<volatile double, volatile long long>,  \
    std::unordered_map<volatile double, volatile unsigned short>,  \
    std::unordered_map<volatile double, volatile unsigned int>,  \
    std::unordered_map<volatile double, volatile unsigned long>,  \
    std::unordered_map<volatile double, volatile unsigned long long>,  \
    std::unordered_map<volatile double, volatile float>,  \
    std::unordered_map<volatile double, volatile double>,  \
    std::unordered_map<volatile double, volatile long double>,  \
    std::unordered_map<volatile long double, char>,  \
    std::unordered_map<volatile long double, wchar_t>,  \
    std::unordered_map<volatile long double, char8_t>,  \
    std::unordered_map<volatile long double, char16_t>,  \
    std::unordered_map<volatile long double, char32_t>,  \
    std::unordered_map<volatile long double, short>,  \
    std::unordered_map<volatile long double, int>,  \
    std::unordered_map<volatile long double, long>,  \
    std::unordered_map<volatile long double, long long>,  \
    std::unordered_map<volatile long double, unsigned short>,  \
    std::unordered_map<volatile long double, unsigned int>,  \
    std::unordered_map<volatile long double, unsigned long>,  \
    std::unordered_map<volatile long double, unsigned long long>,  \
    std::unordered_map<volatile long double, float>,  \
    std::unordered_map<volatile long double, double>,  \
    std::unordered_map<volatile long double, long double>,  \
    std::unordered_map<volatile long double, volatile char>,  \
    std::unordered_map<volatile long double, volatile wchar_t>,  \
    std::unordered_map<volatile long double, volatile char8_t>,  \
    std::unordered_map<volatile long double, volatile char16_t>,  \
    std::unordered_map<volatile long double, volatile char32_t>,  \
    std::unordered_map<volatile long double, volatile short>,  \
    std::unordered_map<volatile long double, volatile int>,  \
    std::unordered_map<volatile long double, volatile long>,  \
    std::unordered_map<volatile long double, volatile long long>,  \
    std::unordered_map<volatile long double, volatile unsigned short>,  \
    std::unordered_map<volatile long double, volatile unsigned int>,  \
    std::unordered_map<volatile long double, volatile unsigned long>,  \
    std::unordered_map<volatile long double, volatile unsigned long long>,  \
    std::unordered_map<volatile long double, volatile float>,  \
    std::unordered_map<volatile long double, volatile double>

#define ALL_STD_NONRANGE_COLLECTIONS std::forward_list<char>,  \
    std::forward_list<wchar_t>, std::forward_list<char8_t>,  \
    std::forward_list<char16_t>, std::forward_list<char32_t>,  \
    std::forward_list<short>, std::forward_list<int>,  \
    std::forward_list<long>, std::forward_list<long long>,  \
    std::forward_list<unsigned short>, std::forward_list<unsigned int>,  \
    std::forward_list<unsigned long>, std::forward_list<unsigned long long>,  \
    std::forward_list<float>, std::forward_list<double>,  \
    std::forward_list<long double>, std::forward_list<volatile char>,  \
    std::forward_list<volatile wchar_t>,  \
    std::forward_list<volatile char8_t>,  \
    std::forward_list<volatile char16_t>,  \
    std::forward_list<volatile char32_t>, std::forward_list<volatile short>,  \
    std::forward_list<volatile int>, std::forward_list<volatile long>,  \
    std::forward_list<volatile long long>,  \
    std::forward_list<volatile unsigned short>,  \
    std::forward_list<volatile unsigned int>,  \
    std::forward_list<volatile unsigned long>,  \
    std::forward_list<volatile unsigned long long>,  \
    std::forward_list<volatile float>, std::forward_list<volatile double>,  \
    std::forward_list<volatile long double>, std::queue<char>,  \
    std::queue<wchar_t>, std::queue<char8_t>, std::queue<char16_t>,  \
    std::queue<char32_t>, std::queue<short>, std::queue<int>,  \
    std::queue<long>, std::queue<long long>, std::queue<unsigned short>,  \
    std::queue<unsigned int>, std::queue<unsigned long>,  \
    std::queue<unsigned long long>, std::queue<float>, std::queue<double>,  \
    std::queue<long double>, std::queue<volatile char>,  \
    std::queue<volatile wchar_t>, std::queue<volatile char8_t>,  \
    std::queue<volatile char16_t>, std::queue<volatile char32_t>,  \
    std::queue<volatile short>, std::queue<volatile int>,  \
    std::queue<volatile long>, std::queue<volatile long long>,  \
    std::queue<volatile unsigned short>, std::queue<volatile unsigned int>,  \
    std::queue<volatile unsigned long>,  \
    std::queue<volatile unsigned long long>, std::queue<volatile float>,  \
    std::queue<volatile double>, std::queue<volatile long double>,  \
    std::priority_queue<char>, std::priority_queue<wchar_t>,  \
    std::priority_queue<char8_t>, std::priority_queue<char16_t>,  \
    std::priority_queue<char32_t>, std::priority_queue<short>,  \
    std::priority_queue<int>, std::priority_queue<long>,  \
    std::priority_queue<long long>, std::priority_queue<unsigned short>,  \
    std::priority_queue<unsigned int>, std::priority_queue<unsigned long>,  \
    std::priority_queue<unsigned long long>, std::priority_queue<float>,  \
    std::priority_queue<double>, std::priority_queue<long double>,  \
    std::priority_queue<volatile char>,  \
    std::priority_queue<volatile wchar_t>,  \
    std::priority_queue<volatile char8_t>,  \
    std::priority_queue<volatile char16_t>,  \
    std::priority_queue<volatile char32_t>,  \
    std::priority_queue<volatile short>, std::priority_queue<volatile int>,  \
    std::priority_queue<volatile long>,  \
    std::priority_queue<volatile long long>,  \
    std::priority_queue<volatile unsigned short>,  \
    std::priority_queue<volatile unsigned int>,  \
    std::priority_queue<volatile unsigned long>,  \
    std::priority_queue<volatile unsigned long long>,  \
    std::priority_queue<volatile float>,  \
    std::priority_queue<volatile double>,  \
    std::priority_queue<volatile long double>, std::stack<char>,  \
    std::stack<wchar_t>, std::stack<char8_t>, std::stack<char16_t>,  \
    std::stack<char32_t>, std::stack<short>, std::stack<int>,  \
    std::stack<long>, std::stack<long long>, std::stack<unsigned short>,  \
    std::stack<unsigned int>, std::stack<unsigned long>,  \
    std::stack<unsigned long long>, std::stack<float>, std::stack<double>,  \
    std::stack<long double>, std::stack<volatile char>,  \
    std::stack<volatile wchar_t>, std::stack<volatile char8_t>,  \
    std::stack<volatile char16_t>, std::stack<volatile char32_t>,  \
    std::stack<volatile short>, std::stack<volatile int>,  \
    std::stack<volatile long>, std::stack<volatile long long>,  \
    std::stack<volatile unsigned short>, std::stack<volatile unsigned int>,  \
    std::stack<volatile unsigned long>,  \
    std::stack<volatile unsigned long long>, std::stack<volatile float>

#define ALL_STD_COLLECTIONS std::vector<char>, std::vector<wchar_t>,  \
    std::vector<char8_t>, std::vector<char16_t>, std::vector<char32_t>,  \
    std::vector<short>, std::vector<int>, std::vector<long>,  \
    std::vector<long long>, std::vector<unsigned short>,  \
    std::vector<unsigned int>, std::vector<unsigned long>,  \
    std::vector<unsigned long long>, std::vector<float>,  \
    std::vector<double>, std::vector<long double>,  \
    std::vector<volatile char>, std::vector<volatile wchar_t>,  \
    std::vector<volatile char8_t>, std::vector<volatile char16_t>,  \
    std::vector<volatile char32_t>, std::vector<volatile short>,  \
    std::vector<volatile int>, std::vector<volatile long>,  \
    std::vector<volatile long long>, std::vector<volatile unsigned short>,  \
    std::vector<volatile unsigned int>, std::vector<volatile unsigned long>,  \
    std::vector<volatile unsigned long long>, std::vector<volatile float>,  \
    std::vector<volatile double>, std::vector<volatile long double>,  \
    std::list<char>, std::list<wchar_t>, std::list<char8_t>,  \
    std::list<char16_t>, std::list<char32_t>, std::list<short>,  \
    std::list<int>, std::list<long>, std::list<long long>,  \
    std::list<unsigned short>, std::list<unsigned int>,  \
    std::list<unsigned long>, std::list<unsigned long long>,  \
    std::list<float>, std::list<double>, std::list<long double>,  \
    std::list<volatile char>, std::list<volatile wchar_t>,  \
    std::list<volatile char8_t>, std::list<volatile char16_t>,  \
    std::list<volatile char32_t>, std::list<volatile short>,  \
    std::list<volatile int>, std::list<volatile long>,  \
    std::list<volatile long long>, std::list<volatile unsigned short>,  \
    std::list<volatile unsigned int>, std::list<volatile unsigned long>,  \
    std::list<volatile unsigned long long>, std::list<volatile float>,  \
    std::list<volatile double>, std::list<volatile long double>,  \
    std::forward_list<char>, std::forward_list<wchar_t>,  \
    std::forward_list<char8_t>, std::forward_list<char16_t>,  \
    std::forward_list<char32_t>, std::forward_list<short>,  \
    std::forward_list<int>, std::forward_list<long>,  \
    std::forward_list<long long>, std::forward_list<unsigned short>,  \
    std::forward_list<unsigned int>, std::forward_list<unsigned long>,  \
    std::forward_list<unsigned long long>, std::forward_list<float>,  \
    std::forward_list<double>, std::forward_list<long double>,  \
    std::forward_list<volatile char>, std::forward_list<volatile wchar_t>,  \
    std::forward_list<volatile char8_t>,  \
    std::forward_list<volatile char16_t>,  \
    std::forward_list<volatile char32_t>, std::forward_list<volatile short>,  \
    std::forward_list<volatile int>, std::forward_list<volatile long>,  \
    std::forward_list<volatile long long>,  \
    std::forward_list<volatile unsigned short>,  \
    std::forward_list<volatile unsigned int>,  \
    std::forward_list<volatile unsigned long>,  \
    std::forward_list<volatile unsigned long long>,  \
    std::forward_list<volatile float>, std::forward_list<volatile double>,  \
    std::forward_list<volatile long double>, std::set<char>,  \
    std::set<wchar_t>, std::set<char8_t>, std::set<char16_t>,  \
    std::set<char32_t>, std::set<short>, std::set<int>, std::set<long>,  \
    std::set<long long>, std::set<unsigned short>, std::set<unsigned int>,  \
    std::set<unsigned long>, std::set<unsigned long long>, std::set<float>,  \
    std::set<double>, std::set<long double>, std::set<volatile char>,  \
    std::set<volatile wchar_t>, std::set<volatile char8_t>,  \
    std::set<volatile char16_t>, std::set<volatile char32_t>,  \
    std::set<volatile short>, std::set<volatile int>,  \
    std::set<volatile long>, std::set<volatile long long>,  \
    std::set<volatile unsigned short>, std::set<volatile unsigned int>,  \
    std::set<volatile unsigned long>, std::set<volatile unsigned long long>,  \
    std::set<volatile float>, std::set<volatile double>,  \
    std::set<volatile long double>, std::unordered_set<char>,  \
    std::unordered_set<wchar_t>, std::unordered_set<char8_t>,  \
    std::unordered_set<char16_t>, std::unordered_set<char32_t>,  \
    std::unordered_set<short>, std::unordered_set<int>,  \
    std::unordered_set<long>, std::unordered_set<long long>,  \
    std::unordered_set<unsigned short>, std::unordered_set<unsigned int>,  \
    std::unordered_set<unsigned long>,  \
    std::unordered_set<unsigned long long>, std::unordered_set<float>,  \
    std::unordered_set<double>, std::unordered_set<long double>,  \
    std::unordered_set<volatile char>, std::unordered_set<volatile wchar_t>,  \
    std::unordered_set<volatile char8_t>,  \
    std::unordered_set<volatile char16_t>,  \
    std::unordered_set<volatile char32_t>,  \
    std::unordered_set<volatile short>, std::unordered_set<volatile int>,  \
    std::unordered_set<volatile long>,  \
    std::unordered_set<volatile long long>,  \
    std::unordered_set<volatile unsigned short>,  \
    std::unordered_set<volatile unsigned int>,  \
    std::unordered_set<volatile unsigned long>,  \
    std::unordered_set<volatile unsigned long long>,  \
    std::unordered_set<volatile float>, std::unordered_set<volatile double>,  \
    std::unordered_set<volatile long double>, std::queue<char>,  \
    std::queue<wchar_t>, std::queue<char8_t>, std::queue<char16_t>,  \
    std::queue<char32_t>, std::queue<short>, std::queue<int>,  \
    std::queue<long>, std::queue<long long>, std::queue<unsigned short>,  \
    std::queue<unsigned int>, std::queue<unsigned long>,  \
    std::queue<unsigned long long>, std::queue<float>, std::queue<double>,  \
    std::queue<long double>, std::queue<volatile char>,  \
    std::queue<volatile wchar_t>, std::queue<volatile char8_t>,  \
    std::queue<volatile char16_t>, std::queue<volatile char32_t>,  \
    std::queue<volatile short>, std::queue<volatile int>,  \
    std::queue<volatile long>, std::queue<volatile long long>,  \
    std::queue<volatile unsigned short>, std::queue<volatile unsigned int>,  \
    std::queue<volatile unsigned long>,  \
    std::queue<volatile unsigned long long>, std::queue<volatile float>,  \
    std::queue<volatile double>, std::queue<volatile long double>,  \
    std::priority_queue<char>, std::priority_queue<wchar_t>,  \
    std::priority_queue<char8_t>, std::priority_queue<char16_t>,  \
    std::priority_queue<char32_t>, std::priority_queue<short>,  \
    std::priority_queue<int>, std::priority_queue<long>,  \
    std::priority_queue<long long>, std::priority_queue<unsigned short>,  \
    std::priority_queue<unsigned int>, std::priority_queue<unsigned long>,  \
    std::priority_queue<unsigned long long>, std::priority_queue<float>,  \
    std::priority_queue<double>, std::priority_queue<long double>,  \
    std::priority_queue<volatile char>,  \
    std::priority_queue<volatile wchar_t>,  \
    std::priority_queue<volatile char8_t>,  \
    std::priority_queue<volatile char16_t>,  \
    std::priority_queue<volatile char32_t>,  \
    std::priority_queue<volatile short>, std::priority_queue<volatile int>,  \
    std::priority_queue<volatile long>,  \
    std::priority_queue<volatile long long>,  \
    std::priority_queue<volatile unsigned short>,  \
    std::priority_queue<volatile unsigned int>,  \
    std::priority_queue<volatile unsigned long>,  \
    std::priority_queue<volatile unsigned long long>,  \
    std::priority_queue<volatile float>,  \
    std::priority_queue<volatile double>,  \
    std::priority_queue<volatile long double>, std::deque<char>,  \
    std::deque<wchar_t>, std::deque<char8_t>, std::deque<char16_t>,  \
    std::deque<char32_t>, std::deque<short>, std::deque<int>,  \
    std::deque<long>, std::deque<long long>, std::deque<unsigned short>,  \
    std::deque<unsigned int>, std::deque<unsigned long>,  \
    std::deque<unsigned long long>, std::deque<float>, std::deque<double>,  \
    std::deque<long double>, std::deque<volatile char>,  \
    std::deque<volatile wchar_t>, std::deque<volatile char8_t>,  \
    std::deque<volatile char16_t>, std::deque<volatile char32_t>,  \
    std::deque<volatile short>, std::deque<volatile int>,  \
    std::deque<volatile long>, std::deque<volatile long long>,  \
    std::deque<volatile unsigned short>, std::deque<volatile unsigned int>,  \
    std::deque<volatile unsigned long>,  \
    std::deque<volatile unsigned long long>, std::deque<volatile float>,  \
    std::deque<volatile double>, std::deque<volatile long double>,  \
    std::stack<char>, std::stack<wchar_t>, std::stack<char8_t>,  \
    std::stack<char16_t>, std::stack<char32_t>, std::stack<short>,  \
    std::stack<int>, std::stack<long>, std::stack<long long>,  \
    std::stack<unsigned short>, std::stack<unsigned int>,  \
    std::stack<unsigned long>, std::stack<unsigned long long>,  \
    std::stack<float>, std::stack<double>, std::stack<long double>,  \
    std::stack<volatile char>, std::stack<volatile wchar_t>,  \
    std::stack<volatile char8_t>, std::stack<volatile char16_t>,  \
    std::stack<volatile char32_t>, std::stack<volatile short>,  \
    std::stack<volatile int>, std::stack<volatile long>,  \
    std::stack<volatile long long>, std::stack<volatile unsigned short>,  \
    std::stack<volatile unsigned int>, std::stack<volatile unsigned long>,  \
    std::stack<volatile unsigned long long>, std::stack<volatile float>,  \
    std::stack<volatile double>, std::stack<volatile long double>,  \
    std::array<char, 1>, std::array<wchar_t, 1>, std::array<char8_t, 1>,  \
    std::array<char16_t, 1>, std::array<char32_t, 1>, std::array<short, 1>,  \
    std::array<int, 1>, std::array<long, 1>, std::array<long long, 1>,  \
    std::array<unsigned short, 1>, std::array<unsigned int, 1>,  \
    std::array<unsigned long, 1>, std::array<unsigned long long, 1>,  \
    std::array<float, 1>, std::array<double, 1>, std::array<long double, 1>,  \
    std::array<volatile char, 1>, std::array<volatile wchar_t, 1>,  \
    std::array<volatile char8_t, 1>, std::array<volatile char16_t, 1>,  \
    std::array<volatile char32_t, 1>, std::array<volatile short, 1>,  \
    std::array<volatile int, 1>, std::array<volatile long, 1>,  \
    std::array<volatile long long, 1>,  \
    std::array<volatile unsigned short, 1>,  \
    std::array<volatile unsigned int, 1>,  \
    std::array<volatile unsigned long, 1>,  \
    std::array<volatile unsigned long long, 1>,  \
    std::array<volatile float, 1>, std::array<volatile double, 1>,  \
    std::array<volatile long double, 1>, std::array<char, 2>,  \
    std::array<wchar_t, 2>, std::array<char8_t, 2>, std::array<char16_t, 2>,  \
    std::array<char32_t, 2>, std::array<short, 2>, std::array<int, 2>,  \
    std::array<long, 2>, std::array<long long, 2>,  \
    std::array<unsigned short, 2>, std::array<unsigned int, 2>,  \
    std::array<unsigned long, 2>, std::array<unsigned long long, 2>,  \
    std::array<float, 2>, std::array<double, 2>, std::array<long double, 2>,  \
    std::array<volatile char, 2>, std::array<volatile wchar_t, 2>,  \
    std::array<volatile char8_t, 2>, std::array<volatile char16_t, 2>,  \
    std::array<volatile char32_t, 2>, std::array<volatile short, 2>,  \
    std::array<volatile int, 2>, std::array<volatile long, 2>,  \
    std::array<volatile long long, 2>,  \
    std::array<volatile unsigned short, 2>,  \
    std::array<volatile unsigned int, 2>,  \
    std::array<volatile unsigned long, 2>,  \
    std::array<volatile unsigned long long, 2>,  \
    std::array<volatile float, 2>, std::array<volatile double, 2>,  \
    std::array<volatile long double, 2>, std::array<char, 3>,  \
    std::array<wchar_t, 3>, std::array<char8_t, 3>, std::array<char16_t, 3>,  \
    std::array<char32_t, 3>, std::array<short, 3>, std::array<int, 3>,  \
    std::array<long, 3>, std::array<long long, 3>,  \
    std::array<unsigned short, 3>, std::array<unsigned int, 3>,  \
    std::array<unsigned long, 3>, std::array<unsigned long long, 3>,  \
    std::array<float, 3>, std::array<double, 3>, std::array<long double, 3>,  \
    std::array<volatile char, 3>, std::array<volatile wchar_t, 3>,  \
    std::array<volatile char8_t, 3>, std::array<volatile char16_t, 3>,  \
    std::array<volatile char32_t, 3>, std::array<volatile short, 3>,  \
    std::array<volatile int, 3>, std::array<volatile long, 3>,  \
    std::array<volatile long long, 3>,  \
    std::array<volatile unsigned short, 3>,  \
    std::array<volatile unsigned int, 3>,  \
    std::array<volatile unsigned long, 3>,  \
    std::array<volatile unsigned long long, 3>,  \
    std::array<volatile float, 3>, std::array<volatile double, 3>,  \
    std::array<volatile long double, 3>, std::array<char, 4>,  \
    std::array<wchar_t, 4>, std::array<char8_t, 4>, std::array<char16_t, 4>,  \
    std::array<char32_t, 4>, std::array<short, 4>, std::array<int, 4>,  \
    std::array<long, 4>, std::array<long long, 4>,  \
    std::array<unsigned short, 4>, std::array<unsigned int, 4>,  \
    std::array<unsigned long, 4>, std::array<unsigned long long, 4>,  \
    std::array<float, 4>, std::array<double, 4>, std::array<long double, 4>,  \
    std::array<volatile char, 4>, std::array<volatile wchar_t, 4>,  \
    std::array<volatile char8_t, 4>, std::array<volatile char16_t, 4>,  \
    std::array<volatile char32_t, 4>, std::array<volatile short, 4>,  \
    std::array<volatile int, 4>, std::array<volatile long, 4>,  \
    std::array<volatile long long, 4>,  \
    std::array<volatile unsigned short, 4>,  \
    std::array<volatile unsigned int, 4>,  \
    std::array<volatile unsigned long, 4>,  \
    std::array<volatile unsigned long long, 4>,  \
    std::array<volatile float, 4>, std::array<volatile double, 4>,  \
    std::array<volatile long double, 4>, std::array<char, 5>,  \
    std::array<wchar_t, 5>, std::array<char8_t, 5>, std::array<char16_t, 5>,  \
    std::array<char32_t, 5>, std::array<short, 5>, std::array<int, 5>,  \
    std::array<long, 5>, std::array<long long, 5>,  \
    std::array<unsigned short, 5>, std::array<unsigned int, 5>,  \
    std::array<unsigned long, 5>, std::array<unsigned long long, 5>,  \
    std::array<float, 5>, std::array<double, 5>, std::array<long double, 5>,  \
    std::array<volatile char, 5>, std::array<volatile wchar_t, 5>,  \
    std::array<volatile char8_t, 5>, std::array<volatile char16_t, 5>,  \
    std::array<volatile char32_t, 5>, std::array<volatile short, 5>,  \
    std::array<volatile int, 5>, std::array<volatile long, 5>,  \
    std::array<volatile long long, 5>,  \
    std::array<volatile unsigned short, 5>,  \
    std::array<volatile unsigned int, 5>,  \
    std::array<volatile unsigned long, 5>,  \
    std::array<volatile unsigned long long, 5>,  \
    std::array<volatile float, 5>, std::array<volatile double, 5>,  \
    std::array<volatile long double, 5>, std::array<char, 6>,  \
    std::array<wchar_t, 6>, std::array<char8_t, 6>, std::array<char16_t, 6>,  \
    std::array<char32_t, 6>, std::array<short, 6>, std::array<int, 6>,  \
    std::array<long, 6>, std::array<long long, 6>,  \
    std::array<unsigned short, 6>, std::array<unsigned int, 6>,  \
    std::array<unsigned long, 6>, std::array<unsigned long long, 6>,  \
    std::array<float, 6>, std::array<double, 6>, std::array<long double, 6>,  \
    std::array<volatile char, 6>, std::array<volatile wchar_t, 6>,  \
    std::array<volatile char8_t, 6>, std::array<volatile char16_t, 6>,  \
    std::array<volatile char32_t, 6>, std::array<volatile short, 6>,  \
    std::array<volatile int, 6>, std::array<volatile long, 6>,  \
    std::array<volatile long long, 6>,  \
    std::array<volatile unsigned short, 6>,  \
    std::array<volatile unsigned int, 6>,  \
    std::array<volatile unsigned long, 6>,  \
    std::array<volatile unsigned long long, 6>,  \
    std::array<volatile float, 6>, std::array<volatile double, 6>,  \
    std::array<volatile long double, 6>, std::array<char, 7>,  \
    std::array<wchar_t, 7>, std::array<char8_t, 7>, std::array<char16_t, 7>,  \
    std::array<char32_t, 7>, std::array<short, 7>, std::array<int, 7>,  \
    std::array<long, 7>, std::array<long long, 7>,  \
    std::array<unsigned short, 7>, std::array<unsigned int, 7>,  \
    std::array<unsigned long, 7>, std::array<unsigned long long, 7>,  \
    std::array<float, 7>, std::array<double, 7>, std::array<long double, 7>,  \
    std::array<volatile char, 7>, std::array<volatile wchar_t, 7>,  \
    std::array<volatile char8_t, 7>, std::array<volatile char16_t, 7>,  \
    std::array<volatile char32_t, 7>, std::array<volatile short, 7>,  \
    std::array<volatile int, 7>, std::array<volatile long, 7>,  \
    std::array<volatile long long, 7>,  \
    std::array<volatile unsigned short, 7>,  \
    std::array<volatile unsigned int, 7>,  \
    std::array<volatile unsigned long, 7>,  \
    std::array<volatile unsigned long long, 7>,  \
    std::array<volatile float, 7>, std::array<volatile double, 7>,  \
    std::array<volatile long double, 7>, std::array<char, 8>,  \
    std::array<wchar_t, 8>, std::array<char8_t, 8>, std::array<char16_t, 8>,  \
    std::array<char32_t, 8>, std::array<short, 8>, std::array<int, 8>,  \
    std::array<long, 8>, std::array<long long, 8>,  \
    std::array<unsigned short, 8>, std::array<unsigned int, 8>,  \
    std::array<unsigned long, 8>, std::array<unsigned long long, 8>,  \
    std::array<float, 8>, std::array<double, 8>, std::array<long double, 8>,  \
    std::array<volatile char, 8>, std::array<volatile wchar_t, 8>,  \
    std::array<volatile char8_t, 8>, std::array<volatile char16_t, 8>,  \
    std::array<volatile char32_t, 8>, std::array<volatile short, 8>,  \
    std::array<volatile int, 8>, std::array<volatile long, 8>,  \
    std::array<volatile long long, 8>,  \
    std::array<volatile unsigned short, 8>,  \
    std::array<volatile unsigned int, 8>,  \
    std::array<volatile unsigned long, 8>,  \
    std::array<volatile unsigned long long, 8>,  \
    std::array<volatile float, 8>, std::array<volatile double, 8>,  \
    std::array<volatile long double, 8>, std::array<char, 9>,  \
    std::array<wchar_t, 9>, std::array<char8_t, 9>, std::array<char16_t, 9>,  \
    std::array<char32_t, 9>, std::array<short, 9>, std::array<int, 9>,  \
    std::array<long, 9>, std::array<long long, 9>,  \
    std::array<unsigned short, 9>, std::array<unsigned int, 9>,  \
    std::array<unsigned long, 9>, std::array<unsigned long long, 9>,  \
    std::array<float, 9>, std::array<double, 9>, std::array<long double, 9>,  \
    std::array<volatile char, 9>, std::array<volatile wchar_t, 9>,  \
    std::array<volatile char8_t, 9>, std::array<volatile char16_t, 9>,  \
    std::array<volatile char32_t, 9>, std::array<volatile short, 9>,  \
    std::array<volatile int, 9>, std::array<volatile long, 9>,  \
    std::array<volatile long long, 9>,  \
    std::array<volatile unsigned short, 9>,  \
    std::array<volatile unsigned int, 9>,  \
    std::array<volatile unsigned long, 9>,  \
    std::array<volatile unsigned long long, 9>,  \
    std::array<volatile float, 9>, std::array<volatile double, 9>,  \
    std::array<volatile long double, 9>, std::array<char, 10>,  \
    std::array<wchar_t, 10>, std::array<char8_t, 10>,  \
    std::array<char16_t, 10>, std::array<char32_t, 10>,  \
    std::array<short, 10>, std::array<int, 10>, std::array<long, 10>,  \
    std::array<long long, 10>, std::array<unsigned short, 10>,  \
    std::array<unsigned int, 10>, std::array<unsigned long, 10>,  \
    std::array<unsigned long long, 10>, std::array<float, 10>,  \
    std::array<double, 10>, std::array<long double, 10>,  \
    std::array<volatile char, 10>, std::array<volatile wchar_t, 10>,  \
    std::array<volatile char8_t, 10>, std::array<volatile char16_t, 10>,  \
    std::array<volatile char32_t, 10>, std::array<volatile short, 10>,  \
    std::array<volatile int, 10>, std::array<volatile long, 10>,  \
    std::array<volatile long long, 10>,  \
    std::array<volatile unsigned short, 10>,  \
    std::array<volatile unsigned int, 10>,  \
    std::array<volatile unsigned long, 10>,  \
    std::array<volatile unsigned long long, 10>,  \
    std::array<volatile float, 10>, std::array<volatile double, 10>,  \
    std::array<volatile long double, 10>, std::array<char, 11>,  \
    std::array<wchar_t, 11>, std::array<char8_t, 11>,  \
    std::array<char16_t, 11>, std::array<char32_t, 11>,  \
    std::array<short, 11>, std::array<int, 11>, std::array<long, 11>,  \
    std::array<long long, 11>, std::array<unsigned short, 11>,  \
    std::array<unsigned int, 11>, std::array<unsigned long, 11>,  \
    std::array<unsigned long long, 11>, std::array<float, 11>,  \
    std::array<double, 11>, std::array<long double, 11>,  \
    std::array<volatile char, 11>, std::array<volatile wchar_t, 11>,  \
    std::array<volatile char8_t, 11>, std::array<volatile char16_t, 11>,  \
    std::array<volatile char32_t, 11>, std::array<volatile short, 11>,  \
    std::array<volatile int, 11>, std::array<volatile long, 11>,  \
    std::array<volatile long long, 11>,  \
    std::array<volatile unsigned short, 11>,  \
    std::array<volatile unsigned int, 11>,  \
    std::array<volatile unsigned long, 11>,  \
    std::array<volatile unsigned long long, 11>,  \
    std::array<volatile float, 11>, std::array<volatile double, 11>,  \
    std::array<volatile long double, 11>, std::array<char, 12>,  \
    std::array<wchar_t, 12>, std::array<char8_t, 12>,  \
    std::array<char16_t, 12>, std::array<char32_t, 12>,  \
    std::array<short, 12>, std::array<int, 12>, std::array<long, 12>,  \
    std::array<long long, 12>, std::array<unsigned short, 12>,  \
    std::array<unsigned int, 12>, std::array<unsigned long, 12>,  \
    std::array<unsigned long long, 12>, std::array<float, 12>,  \
    std::array<double, 12>, std::array<long double, 12>,  \
    std::array<volatile char, 12>, std::array<volatile wchar_t, 12>,  \
    std::array<volatile char8_t, 12>, std::array<volatile char16_t, 12>,  \
    std::array<volatile char32_t, 12>, std::array<volatile short, 12>,  \
    std::array<volatile int, 12>, std::array<volatile long, 12>,  \
    std::array<volatile long long, 12>,  \
    std::array<volatile unsigned short, 12>,  \
    std::array<volatile unsigned int, 12>,  \
    std::array<volatile unsigned long, 12>,  \
    std::array<volatile unsigned long long, 12>,  \
    std::array<volatile float, 12>, std::array<volatile double, 12>,  \
    std::array<volatile long double, 12>, std::array<char, 13>,  \
    std::array<wchar_t, 13>, std::array<char8_t, 13>,  \
    std::array<char16_t, 13>, std::array<char32_t, 13>,  \
    std::array<short, 13>, std::array<int, 13>, std::array<long, 13>,  \
    std::array<long long, 13>, std::array<unsigned short, 13>,  \
    std::array<unsigned int, 13>, std::array<unsigned long, 13>,  \
    std::array<unsigned long long, 13>, std::array<float, 13>,  \
    std::array<double, 13>, std::array<long double, 13>,  \
    std::array<volatile char, 13>, std::array<volatile wchar_t, 13>,  \
    std::array<volatile char8_t, 13>, std::array<volatile char16_t, 13>,  \
    std::array<volatile char32_t, 13>, std::array<volatile short, 13>,  \
    std::array<volatile int, 13>, std::array<volatile long, 13>,  \
    std::array<volatile long long, 13>,  \
    std::array<volatile unsigned short, 13>,  \
    std::array<volatile unsigned int, 13>,  \
    std::array<volatile unsigned long, 13>,  \
    std::array<volatile unsigned long long, 13>,  \
    std::array<volatile float, 13>, std::array<volatile double, 13>,  \
    std::array<volatile long double, 13>, std::array<char, 14>,  \
    std::array<wchar_t, 14>, std::array<char8_t, 14>,  \
    std::array<char16_t, 14>, std::array<char32_t, 14>,  \
    std::array<short, 14>, std::array<int, 14>, std::array<long, 14>,  \
    std::array<long long, 14>, std::array<unsigned short, 14>,  \
    std::array<unsigned int, 14>, std::array<unsigned long, 14>,  \
    std::array<unsigned long long, 14>, std::array<float, 14>,  \
    std::array<double, 14>, std::array<long double, 14>,  \
    std::array<volatile char, 14>, std::array<volatile wchar_t, 14>,  \
    std::array<volatile char8_t, 14>, std::array<volatile char16_t, 14>,  \
    std::array<volatile char32_t, 14>, std::array<volatile short, 14>,  \
    std::array<volatile int, 14>, std::array<volatile long, 14>,  \
    std::array<volatile long long, 14>,  \
    std::array<volatile unsigned short, 14>,  \
    std::array<volatile unsigned int, 14>,  \
    std::array<volatile unsigned long, 14>,  \
    std::array<volatile unsigned long long, 14>,  \
    std::array<volatile float, 14>, std::array<volatile double, 14>,  \
    std::array<volatile long double, 14>, std::array<char, 15>,  \
    std::array<wchar_t, 15>, std::array<char8_t, 15>,  \
    std::array<char16_t, 15>, std::array<char32_t, 15>,  \
    std::array<short, 15>, std::array<int, 15>, std::array<long, 15>,  \
    std::array<long long, 15>, std::array<unsigned short, 15>,  \
    std::array<unsigned int, 15>, std::array<unsigned long, 15>,  \
    std::array<unsigned long long, 15>, std::array<float, 15>,  \
    std::array<double, 15>, std::array<long double, 15>,  \
    std::array<volatile char, 15>, std::array<volatile wchar_t, 15>,  \
    std::array<volatile char8_t, 15>, std::array<volatile char16_t, 15>,  \
    std::array<volatile char32_t, 15>, std::array<volatile short, 15>,  \
    std::array<volatile int, 15>, std::array<volatile long, 15>,  \
    std::array<volatile long long, 15>,  \
    std::array<volatile unsigned short, 15>,  \
    std::array<volatile unsigned int, 15>,  \
    std::array<volatile unsigned long, 15>,  \
    std::array<volatile unsigned long long, 15>,  \
    std::array<volatile float, 15>, std::array<volatile double, 15>,  \
    std::array<volatile long double, 15>, std::array<char, 16>,  \
    std::array<wchar_t, 16>, std::array<char8_t, 16>,  \
    std::array<char16_t, 16>, std::array<char32_t, 16>,  \
    std::array<short, 16>, std::array<int, 16>, std::array<long, 16>,  \
    std::array<long long, 16>, std::array<unsigned short, 16>,  \
    std::array<unsigned int, 16>, std::array<unsigned long, 16>,  \
    std::array<unsigned long long, 16>, std::array<float, 16>,  \
    std::array<double, 16>, std::array<long double, 16>,  \
    std::array<volatile char, 16>, std::array<volatile wchar_t, 16>,  \
    std::array<volatile char8_t, 16>, std::array<volatile char16_t, 16>,  \
    std::array<volatile char32_t, 16>, std::array<volatile short, 16>,  \
    std::array<volatile int, 16>, std::array<volatile long, 16>,  \
    std::array<volatile long long, 16>,  \
    std::array<volatile unsigned short, 16>,  \
    std::array<volatile unsigned int, 16>,  \
    std::array<volatile unsigned long, 16>,  \
    std::array<volatile unsigned long long, 16>,  \
    std::array<volatile float, 16>, std::array<volatile double, 16>,  \
    std::array<volatile long double, 16>, std::array<char, 17>,  \
    std::array<wchar_t, 17>, std::array<char8_t, 17>,  \
    std::array<char16_t, 17>, std::array<char32_t, 17>,  \
    std::array<short, 17>, std::array<int, 17>, std::array<long, 17>,  \
    std::array<long long, 17>, std::array<unsigned short, 17>,  \
    std::array<unsigned int, 17>, std::array<unsigned long, 17>,  \
    std::array<unsigned long long, 17>, std::array<float, 17>,  \
    std::array<double, 17>, std::array<long double, 17>,  \
    std::array<volatile char, 17>, std::array<volatile wchar_t, 17>,  \
    std::array<volatile char8_t, 17>, std::array<volatile char16_t, 17>,  \
    std::array<volatile char32_t, 17>, std::array<volatile short, 17>,  \
    std::array<volatile int, 17>, std::array<volatile long, 17>,  \
    std::array<volatile long long, 17>,  \
    std::array<volatile unsigned short, 17>,  \
    std::array<volatile unsigned int, 17>,  \
    std::array<volatile unsigned long, 17>,  \
    std::array<volatile unsigned long long, 17>,  \
    std::array<volatile float, 17>, std::array<volatile double, 17>,  \
    std::array<volatile long double, 17>, std::array<char, 18>,  \
    std::array<wchar_t, 18>, std::array<char8_t, 18>,  \
    std::array<char16_t, 18>, std::array<char32_t, 18>,  \
    std::array<short, 18>, std::array<int, 18>, std::array<long, 18>,  \
    std::array<long long, 18>, std::array<unsigned short, 18>,  \
    std::array<unsigned int, 18>, std::array<unsigned long, 18>,  \
    std::array<unsigned long long, 18>, std::array<float, 18>,  \
    std::array<double, 18>, std::array<long double, 18>,  \
    std::array<volatile char, 18>, std::array<volatile wchar_t, 18>,  \
    std::array<volatile char8_t, 18>, std::array<volatile char16_t, 18>,  \
    std::array<volatile char32_t, 18>, std::array<volatile short, 18>,  \
    std::array<volatile int, 18>, std::array<volatile long, 18>,  \
    std::array<volatile long long, 18>,  \
    std::array<volatile unsigned short, 18>,  \
    std::array<volatile unsigned int, 18>,  \
    std::array<volatile unsigned long, 18>,  \
    std::array<volatile unsigned long long, 18>,  \
    std::array<volatile float, 18>, std::array<volatile double, 18>,  \
    std::array<volatile long double, 18>, std::array<char, 19>,  \
    std::array<wchar_t, 19>, std::array<char8_t, 19>,  \
    std::array<char16_t, 19>, std::array<char32_t, 19>,  \
    std::array<short, 19>, std::array<int, 19>, std::array<long, 19>,  \
    std::array<long long, 19>, std::array<unsigned short, 19>,  \
    std::array<unsigned int, 19>, std::array<unsigned long, 19>,  \
    std::array<unsigned long long, 19>, std::array<float, 19>,  \
    std::array<double, 19>, std::array<long double, 19>,  \
    std::array<volatile char, 19>, std::array<volatile wchar_t, 19>,  \
    std::array<volatile char8_t, 19>, std::array<volatile char16_t, 19>,  \
    std::array<volatile char32_t, 19>, std::array<volatile short, 19>,  \
    std::array<volatile int, 19>, std::array<volatile long, 19>,  \
    std::array<volatile long long, 19>,  \
    std::array<volatile unsigned short, 19>,  \
    std::array<volatile unsigned int, 19>,  \
    std::array<volatile unsigned long, 19>,  \
    std::array<volatile unsigned long long, 19>,  \
    std::array<volatile float, 19>, std::array<volatile double, 19>,  \
    std::array<volatile long double, 19>, std::array<char, 20>,  \
    std::array<wchar_t, 20>, std::array<char8_t, 20>,  \
    std::array<char16_t, 20>, std::array<char32_t, 20>,  \
    std::array<short, 20>, std::array<int, 20>, std::array<long, 20>,  \
    std::array<long long, 20>, std::array<unsigned short, 20>,  \
    std::array<unsigned int, 20>, std::array<unsigned long, 20>,  \
    std::array<unsigned long long, 20>, std::array<float, 20>,  \
    std::array<double, 20>, std::array<long double, 20>,  \
    std::array<volatile char, 20>, std::array<volatile wchar_t, 20>,  \
    std::array<volatile char8_t, 20>, std::array<volatile char16_t, 20>,  \
    std::array<volatile char32_t, 20>, std::array<volatile short, 20>,  \
    std::array<volatile int, 20>, std::array<volatile long, 20>,  \
    std::array<volatile long long, 20>,  \
    std::array<volatile unsigned short, 20>,  \
    std::array<volatile unsigned int, 20>,  \
    std::array<volatile unsigned long, 20>,  \
    std::array<volatile unsigned long long, 20>,  \
    std::array<volatile float, 20>, std::array<volatile double, 20>,  \
    std::array<volatile long double, 20>, std::array<char, 21>,  \
    std::array<wchar_t, 21>, std::array<char8_t, 21>,  \
    std::array<char16_t, 21>, std::array<char32_t, 21>,  \
    std::array<short, 21>, std::array<int, 21>, std::array<long, 21>,  \
    std::array<long long, 21>, std::array<unsigned short, 21>,  \
    std::array<unsigned int, 21>, std::array<unsigned long, 21>,  \
    std::array<unsigned long long, 21>, std::array<float, 21>,  \
    std::array<double, 21>, std::array<long double, 21>,  \
    std::array<volatile char, 21>, std::array<volatile wchar_t, 21>,  \
    std::array<volatile char8_t, 21>, std::array<volatile char16_t, 21>,  \
    std::array<volatile char32_t, 21>, std::array<volatile short, 21>,  \
    std::array<volatile int, 21>, std::array<volatile long, 21>,  \
    std::array<volatile long long, 21>,  \
    std::array<volatile unsigned short, 21>,  \
    std::array<volatile unsigned int, 21>,  \
    std::array<volatile unsigned long, 21>,  \
    std::array<volatile unsigned long long, 21>,  \
    std::array<volatile float, 21>, std::array<volatile double, 21>,  \
    std::array<volatile long double, 21>, std::array<char, 22>,  \
    std::array<wchar_t, 22>, std::array<char8_t, 22>,  \
    std::array<char16_t, 22>, std::array<char32_t, 22>,  \
    std::array<short, 22>, std::array<int, 22>, std::array<long, 22>,  \
    std::array<long long, 22>, std::array<unsigned short, 22>,  \
    std::array<unsigned int, 22>, std::array<unsigned long, 22>,  \
    std::array<unsigned long long, 22>, std::array<float, 22>,  \
    std::array<double, 22>, std::array<long double, 22>,  \
    std::array<volatile char, 22>, std::array<volatile wchar_t, 22>,  \
    std::array<volatile char8_t, 22>, std::array<volatile char16_t, 22>,  \
    std::array<volatile char32_t, 22>, std::array<volatile short, 22>,  \
    std::array<volatile int, 22>, std::array<volatile long, 22>,  \
    std::array<volatile long long, 22>,  \
    std::array<volatile unsigned short, 22>,  \
    std::array<volatile unsigned int, 22>,  \
    std::array<volatile unsigned long, 22>,  \
    std::array<volatile unsigned long long, 22>,  \
    std::array<volatile float, 22>, std::array<volatile double, 22>,  \
    std::array<volatile long double, 22>, std::array<char, 23>,  \
    std::array<wchar_t, 23>, std::array<char8_t, 23>,  \
    std::array<char16_t, 23>, std::array<char32_t, 23>,  \
    std::array<short, 23>, std::array<int, 23>, std::array<long, 23>,  \
    std::array<long long, 23>, std::array<unsigned short, 23>,  \
    std::array<unsigned int, 23>, std::array<unsigned long, 23>,  \
    std::array<unsigned long long, 23>, std::array<float, 23>,  \
    std::array<double, 23>, std::array<long double, 23>,  \
    std::array<volatile char, 23>, std::array<volatile wchar_t, 23>,  \
    std::array<volatile char8_t, 23>, std::array<volatile char16_t, 23>,  \
    std::array<volatile char32_t, 23>, std::array<volatile short, 23>,  \
    std::array<volatile int, 23>, std::array<volatile long, 23>,  \
    std::array<volatile long long, 23>,  \
    std::array<volatile unsigned short, 23>,  \
    std::array<volatile unsigned int, 23>,  \
    std::array<volatile unsigned long, 23>,  \
    std::array<volatile unsigned long long, 23>,  \
    std::array<volatile float, 23>, std::array<volatile double, 23>,  \
    std::array<volatile long double, 23>, std::array<char, 24>,  \
    std::array<wchar_t, 24>, std::array<char8_t, 24>,  \
    std::array<char16_t, 24>, std::array<char32_t, 24>,  \
    std::array<short, 24>, std::array<int, 24>, std::array<long, 24>,  \
    std::array<long long, 24>, std::array<unsigned short, 24>,  \
    std::array<unsigned int, 24>, std::array<unsigned long, 24>,  \
    std::array<unsigned long long, 24>, std::array<float, 24>,  \
    std::array<double, 24>, std::array<long double, 24>,  \
    std::array<volatile char, 24>, std::array<volatile wchar_t, 24>,  \
    std::array<volatile char8_t, 24>, std::array<volatile char16_t, 24>,  \
    std::array<volatile char32_t, 24>, std::array<volatile short, 24>,  \
    std::array<volatile int, 24>, std::array<volatile long, 24>,  \
    std::array<volatile long long, 24>,  \
    std::array<volatile unsigned short, 24>,  \
    std::array<volatile unsigned int, 24>,  \
    std::array<volatile unsigned long, 24>,  \
    std::array<volatile unsigned long long, 24>,  \
    std::array<volatile float, 24>, std::array<volatile double, 24>,  \
    std::array<volatile long double, 24>, std::array<char, 25>,  \
    std::array<wchar_t, 25>, std::array<char8_t, 25>,  \
    std::array<char16_t, 25>, std::array<char32_t, 25>,  \
    std::array<short, 25>, std::array<int, 25>, std::array<long, 25>,  \
    std::array<long long, 25>, std::array<unsigned short, 25>,  \
    std::array<unsigned int, 25>, std::array<unsigned long, 25>,  \
    std::array<unsigned long long, 25>, std::array<float, 25>,  \
    std::array<double, 25>, std::array<long double, 25>,  \
    std::array<volatile char, 25>, std::array<volatile wchar_t, 25>,  \
    std::array<volatile char8_t, 25>, std::array<volatile char16_t, 25>,  \
    std::array<volatile char32_t, 25>, std::array<volatile short, 25>,  \
    std::array<volatile int, 25>, std::array<volatile long, 25>,  \
    std::array<volatile long long, 25>,  \
    std::array<volatile unsigned short, 25>,  \
    std::array<volatile unsigned int, 25>,  \
    std::array<volatile unsigned long, 25>,  \
    std::array<volatile unsigned long long, 25>,  \
    std::array<volatile float, 25>, std::array<volatile double, 25>,  \
    std::array<volatile long double, 25>, std::array<char, 26>,  \
    std::array<wchar_t, 26>, std::array<char8_t, 26>,  \
    std::array<char16_t, 26>, std::array<char32_t, 26>,  \
    std::array<short, 26>, std::array<int, 26>, std::array<long, 26>,  \
    std::array<long long, 26>, std::array<unsigned short, 26>,  \
    std::array<unsigned int, 26>, std::array<unsigned long, 26>,  \
    std::array<unsigned long long, 26>, std::array<float, 26>,  \
    std::array<double, 26>, std::array<long double, 26>,  \
    std::array<volatile char, 26>, std::array<volatile wchar_t, 26>,  \
    std::array<volatile char8_t, 26>, std::array<volatile char16_t, 26>,  \
    std::array<volatile char32_t, 26>, std::array<volatile short, 26>,  \
    std::array<volatile int, 26>, std::array<volatile long, 26>,  \
    std::array<volatile long long, 26>,  \
    std::array<volatile unsigned short, 26>,  \
    std::array<volatile unsigned int, 26>,  \
    std::array<volatile unsigned long, 26>,  \
    std::array<volatile unsigned long long, 26>,  \
    std::array<volatile float, 26>, std::array<volatile double, 26>,  \
    std::array<volatile long double, 26>, std::array<char, 27>,  \
    std::array<wchar_t, 27>, std::array<char8_t, 27>,  \
    std::array<char16_t, 27>, std::array<char32_t, 27>,  \
    std::array<short, 27>, std::array<int, 27>, std::array<long, 27>,  \
    std::array<long long, 27>, std::array<unsigned short, 27>,  \
    std::array<unsigned int, 27>, std::array<unsigned long, 27>,  \
    std::array<unsigned long long, 27>, std::array<float, 27>,  \
    std::array<double, 27>, std::array<long double, 27>,  \
    std::array<volatile char, 27>, std::array<volatile wchar_t, 27>,  \
    std::array<volatile char8_t, 27>, std::array<volatile char16_t, 27>,  \
    std::array<volatile char32_t, 27>, std::array<volatile short, 27>,  \
    std::array<volatile int, 27>, std::array<volatile long, 27>,  \
    std::array<volatile long long, 27>,  \
    std::array<volatile unsigned short, 27>,  \
    std::array<volatile unsigned int, 27>,  \
    std::array<volatile unsigned long, 27>,  \
    std::array<volatile unsigned long long, 27>,  \
    std::array<volatile float, 27>, std::array<volatile double, 27>,  \
    std::array<volatile long double, 27>, std::array<char, 28>,  \
    std::array<wchar_t, 28>, std::array<char8_t, 28>,  \
    std::array<char16_t, 28>, std::array<char32_t, 28>,  \
    std::array<short, 28>, std::array<int, 28>, std::array<long, 28>,  \
    std::array<long long, 28>, std::array<unsigned short, 28>,  \
    std::array<unsigned int, 28>, std::array<unsigned long, 28>,  \
    std::array<unsigned long long, 28>, std::array<float, 28>,  \
    std::array<double, 28>, std::array<long double, 28>,  \
    std::array<volatile char, 28>, std::array<volatile wchar_t, 28>,  \
    std::array<volatile char8_t, 28>, std::array<volatile char16_t, 28>,  \
    std::array<volatile char32_t, 28>, std::array<volatile short, 28>,  \
    std::array<volatile int, 28>, std::array<volatile long, 28>,  \
    std::array<volatile long long, 28>,  \
    std::array<volatile unsigned short, 28>,  \
    std::array<volatile unsigned int, 28>,  \
    std::array<volatile unsigned long, 28>,  \
    std::array<volatile unsigned long long, 28>,  \
    std::array<volatile float, 28>, std::array<volatile double, 28>,  \
    std::array<volatile long double, 28>, std::array<char, 29>,  \
    std::array<wchar_t, 29>, std::array<char8_t, 29>,  \
    std::array<char16_t, 29>, std::array<char32_t, 29>,  \
    std::array<short, 29>, std::array<int, 29>, std::array<long, 29>,  \
    std::array<long long, 29>, std::array<unsigned short, 29>,  \
    std::array<unsigned int, 29>, std::array<unsigned long, 29>,  \
    std::array<unsigned long long, 29>, std::array<float, 29>,  \
    std::array<double, 29>, std::array<long double, 29>,  \
    std::array<volatile char, 29>, std::array<volatile wchar_t, 29>,  \
    std::array<volatile char8_t, 29>, std::array<volatile char16_t, 29>,  \
    std::array<volatile char32_t, 29>, std::array<volatile short, 29>,  \
    std::array<volatile int, 29>, std::array<volatile long, 29>,  \
    std::array<volatile long long, 29>,  \
    std::array<volatile unsigned short, 29>,  \
    std::array<volatile unsigned int, 29>,  \
    std::array<volatile unsigned long, 29>,  \
    std::array<volatile unsigned long long, 29>,  \
    std::array<volatile float, 29>, std::array<volatile double, 29>,  \
    std::array<volatile long double, 29>, std::array<char, 30>,  \
    std::array<wchar_t, 30>, std::array<char8_t, 30>,  \
    std::array<char16_t, 30>, std::array<char32_t, 30>,  \
    std::array<short, 30>, std::array<int, 30>, std::array<long, 30>,  \
    std::array<long long, 30>, std::array<unsigned short, 30>,  \
    std::array<unsigned int, 30>, std::array<unsigned long, 30>,  \
    std::array<unsigned long long, 30>, std::array<float, 30>,  \
    std::array<double, 30>, std::array<long double, 30>,  \
    std::array<volatile char, 30>, std::array<volatile wchar_t, 30>,  \
    std::array<volatile char8_t, 30>, std::array<volatile char16_t, 30>,  \
    std::array<volatile char32_t, 30>, std::array<volatile short, 30>,  \
    std::array<volatile int, 30>, std::array<volatile long, 30>,  \
    std::array<volatile long long, 30>,  \
    std::array<volatile unsigned short, 30>,  \
    std::array<volatile unsigned int, 30>,  \
    std::array<volatile unsigned long, 30>,  \
    std::array<volatile unsigned long long, 30>,  \
    std::array<volatile float, 30>, std::array<volatile double, 30>,  \
    std::array<volatile long double, 30>, std::array<char, 31>,  \
    std::array<wchar_t, 31>, std::array<char8_t, 31>,  \
    std::array<char16_t, 31>, std::array<char32_t, 31>,  \
    std::array<short, 31>, std::array<int, 31>, std::array<long, 31>,  \
    std::array<long long, 31>, std::array<unsigned short, 31>,  \
    std::array<unsigned int, 31>, std::array<unsigned long, 31>,  \
    std::array<unsigned long long, 31>, std::array<float, 31>,  \
    std::array<double, 31>, std::array<long double, 31>,  \
    std::array<volatile char, 31>, std::array<volatile wchar_t, 31>,  \
    std::array<volatile char8_t, 31>, std::array<volatile char16_t, 31>,  \
    std::array<volatile char32_t, 31>, std::array<volatile short, 31>,  \
    std::array<volatile int, 31>, std::array<volatile long, 31>,  \
    std::array<volatile long long, 31>,  \
    std::array<volatile unsigned short, 31>,  \
    std::array<volatile unsigned int, 31>,  \
    std::array<volatile unsigned long, 31>,  \
    std::array<volatile unsigned long long, 31>,  \
    std::array<volatile float, 31>, std::array<volatile double, 31>,  \
    std::array<volatile long double, 31>, std::array<char, 32>,  \
    std::array<wchar_t, 32>, std::array<char8_t, 32>,  \
    std::array<char16_t, 32>, std::array<char32_t, 32>,  \
    std::array<short, 32>, std::array<int, 32>, std::array<long, 32>,  \
    std::array<long long, 32>, std::array<unsigned short, 32>,  \
    std::array<unsigned int, 32>, std::array<unsigned long, 32>,  \
    std::array<unsigned long long, 32>, std::array<float, 32>,  \
    std::array<double, 32>, std::array<long double, 32>,  \
    std::array<volatile char, 32>, std::array<volatile wchar_t, 32>,  \
    std::array<volatile char8_t, 32>, std::array<volatile char16_t, 32>,  \
    std::array<volatile char32_t, 32>, std::array<volatile short, 32>,  \
    std::array<volatile int, 32>, std::array<volatile long, 32>,  \
    std::array<volatile long long, 32>,  \
    std::array<volatile unsigned short, 32>,  \
    std::array<volatile unsigned int, 32>,  \
    std::array<volatile unsigned long, 32>,  \
    std::array<volatile unsigned long long, 32>,  \
    std::array<volatile float, 32>, std::array<volatile double, 32>,  \
    std::array<volatile long double, 32>, std::array<char, 33>,  \
    std::array<wchar_t, 33>, std::array<char8_t, 33>,  \
    std::array<char16_t, 33>, std::array<char32_t, 33>,  \
    std::array<short, 33>, std::array<int, 33>, std::array<long, 33>,  \
    std::array<long long, 33>, std::array<unsigned short, 33>,  \
    std::array<unsigned int, 33>, std::array<unsigned long, 33>,  \
    std::array<unsigned long long, 33>, std::array<float, 33>,  \
    std::array<double, 33>, std::array<long double, 33>,  \
    std::array<volatile char, 33>, std::array<volatile wchar_t, 33>,  \
    std::array<volatile char8_t, 33>, std::array<volatile char16_t, 33>,  \
    std::array<volatile char32_t, 33>, std::array<volatile short, 33>,  \
    std::array<volatile int, 33>, std::array<volatile long, 33>,  \
    std::array<volatile long long, 33>,  \
    std::array<volatile unsigned short, 33>,  \
    std::array<volatile unsigned int, 33>,  \
    std::array<volatile unsigned long, 33>,  \
    std::array<volatile unsigned long long, 33>,  \
    std::array<volatile float, 33>, std::array<volatile double, 33>,  \
    std::array<volatile long double, 33>, std::array<char, 34>,  \
    std::array<wchar_t, 34>, std::array<char8_t, 34>,  \
    std::array<char16_t, 34>, std::array<char32_t, 34>,  \
    std::array<short, 34>, std::array<int, 34>, std::array<long, 34>,  \
    std::array<long long, 34>, std::array<unsigned short, 34>,  \
    std::array<unsigned int, 34>, std::array<unsigned long, 34>,  \
    std::array<unsigned long long, 34>, std::array<float, 34>,  \
    std::array<double, 34>, std::array<long double, 34>,  \
    std::array<volatile char, 34>, std::array<volatile wchar_t, 34>,  \
    std::array<volatile char8_t, 34>, std::array<volatile char16_t, 34>,  \
    std::array<volatile char32_t, 34>, std::array<volatile short, 34>,  \
    std::array<volatile int, 34>, std::array<volatile long, 34>,  \
    std::array<volatile long long, 34>,  \
    std::array<volatile unsigned short, 34>,  \
    std::array<volatile unsigned int, 34>,  \
    std::array<volatile unsigned long, 34>,  \
    std::array<volatile unsigned long long, 34>,  \
    std::array<volatile float, 34>, std::array<volatile double, 34>,  \
    std::array<volatile long double, 34>, std::array<char, 35>,  \
    std::array<wchar_t, 35>, std::array<char8_t, 35>,  \
    std::array<char16_t, 35>, std::array<char32_t, 35>,  \
    std::array<short, 35>, std::array<int, 35>, std::array<long, 35>,  \
    std::array<long long, 35>, std::array<unsigned short, 35>,  \
    std::array<unsigned int, 35>, std::array<unsigned long, 35>,  \
    std::array<unsigned long long, 35>, std::array<float, 35>,  \
    std::array<double, 35>, std::array<long double, 35>,  \
    std::array<volatile char, 35>, std::array<volatile wchar_t, 35>,  \
    std::array<volatile char8_t, 35>, std::array<volatile char16_t, 35>,  \
    std::array<volatile char32_t, 35>, std::array<volatile short, 35>,  \
    std::array<volatile int, 35>, std::array<volatile long, 35>,  \
    std::array<volatile long long, 35>,  \
    std::array<volatile unsigned short, 35>,  \
    std::array<volatile unsigned int, 35>,  \
    std::array<volatile unsigned long, 35>,  \
    std::array<volatile unsigned long long, 35>,  \
    std::array<volatile float, 35>, std::array<volatile double, 35>,  \
    std::array<volatile long double, 35>, std::array<char, 36>,  \
    std::array<wchar_t, 36>, std::array<char8_t, 36>,  \
    std::array<char16_t, 36>, std::array<char32_t, 36>,  \
    std::array<short, 36>, std::array<int, 36>, std::array<long, 36>,  \
    std::array<long long, 36>, std::array<unsigned short, 36>,  \
    std::array<unsigned int, 36>, std::array<unsigned long, 36>,  \
    std::array<unsigned long long, 36>, std::array<float, 36>,  \
    std::array<double, 36>, std::array<long double, 36>,  \
    std::array<volatile char, 36>, std::array<volatile wchar_t, 36>,  \
    std::array<volatile char8_t, 36>, std::array<volatile char16_t, 36>,  \
    std::array<volatile char32_t, 36>, std::array<volatile short, 36>,  \
    std::array<volatile int, 36>, std::array<volatile long, 36>,  \
    std::array<volatile long long, 36>,  \
    std::array<volatile unsigned short, 36>,  \
    std::array<volatile unsigned int, 36>,  \
    std::array<volatile unsigned long, 36>,  \
    std::array<volatile unsigned long long, 36>,  \
    std::array<volatile float, 36>, std::array<volatile double, 36>,  \
    std::array<volatile long double, 36>, std::array<char, 37>,  \
    std::array<wchar_t, 37>, std::array<char8_t, 37>,  \
    std::array<char16_t, 37>, std::array<char32_t, 37>,  \
    std::array<short, 37>, std::array<int, 37>, std::array<long, 37>,  \
    std::array<long long, 37>, std::array<unsigned short, 37>,  \
    std::array<unsigned int, 37>, std::array<unsigned long, 37>,  \
    std::array<unsigned long long, 37>, std::array<float, 37>,  \
    std::array<double, 37>, std::array<long double, 37>,  \
    std::array<volatile char, 37>, std::array<volatile wchar_t, 37>,  \
    std::array<volatile char8_t, 37>, std::array<volatile char16_t, 37>,  \
    std::array<volatile char32_t, 37>, std::array<volatile short, 37>,  \
    std::array<volatile int, 37>, std::array<volatile long, 37>,  \
    std::array<volatile long long, 37>,  \
    std::array<volatile unsigned short, 37>,  \
    std::array<volatile unsigned int, 37>,  \
    std::array<volatile unsigned long, 37>,  \
    std::array<volatile unsigned long long, 37>,  \
    std::array<volatile float, 37>, std::array<volatile double, 37>,  \
    std::array<volatile long double, 37>, std::array<char, 38>,  \
    std::array<wchar_t, 38>, std::array<char8_t, 38>,  \
    std::array<char16_t, 38>, std::array<char32_t, 38>,  \
    std::array<short, 38>, std::array<int, 38>, std::array<long, 38>,  \
    std::array<long long, 38>, std::array<unsigned short, 38>,  \
    std::array<unsigned int, 38>, std::array<unsigned long, 38>,  \
    std::array<unsigned long long, 38>, std::array<float, 38>,  \
    std::array<double, 38>, std::array<long double, 38>,  \
    std::array<volatile char, 38>, std::array<volatile wchar_t, 38>,  \
    std::array<volatile char8_t, 38>, std::array<volatile char16_t, 38>,  \
    std::array<volatile char32_t, 38>, std::array<volatile short, 38>,  \
    std::array<volatile int, 38>, std::array<volatile long, 38>,  \
    std::array<volatile long long, 38>,  \
    std::array<volatile unsigned short, 38>,  \
    std::array<volatile unsigned int, 38>,  \
    std::array<volatile unsigned long, 38>,  \
    std::array<volatile unsigned long long, 38>,  \
    std::array<volatile float, 38>, std::array<volatile double, 38>,  \
    std::array<volatile long double, 38>, std::array<char, 39>,  \
    std::array<wchar_t, 39>, std::array<char8_t, 39>,  \
    std::array<char16_t, 39>, std::array<char32_t, 39>,  \
    std::array<short, 39>, std::array<int, 39>, std::array<long, 39>,  \
    std::array<long long, 39>, std::array<unsigned short, 39>,  \
    std::array<unsigned int, 39>, std::array<unsigned long, 39>,  \
    std::array<unsigned long long, 39>, std::array<float, 39>,  \
    std::array<double, 39>, std::array<long double, 39>,  \
    std::array<volatile char, 39>, std::array<volatile wchar_t, 39>,  \
    std::array<volatile char8_t, 39>, std::array<volatile char16_t, 39>,  \
    std::array<volatile char32_t, 39>, std::array<volatile short, 39>,  \
    std::array<volatile int, 39>, std::array<volatile long, 39>,  \
    std::array<volatile long long, 39>,  \
    std::array<volatile unsigned short, 39>,  \
    std::array<volatile unsigned int, 39>,  \
    std::array<volatile unsigned long, 39>,  \
    std::array<volatile unsigned long long, 39>,  \
    std::array<volatile float, 39>, std::array<volatile double, 39>,  \
    std::array<volatile long double, 39>, std::array<char, 40>,  \
    std::array<wchar_t, 40>, std::array<char8_t, 40>,  \
    std::array<char16_t, 40>, std::array<char32_t, 40>,  \
    std::array<short, 40>, std::array<int, 40>, std::array<long, 40>,  \
    std::array<long long, 40>, std::array<unsigned short, 40>,  \
    std::array<unsigned int, 40>, std::array<unsigned long, 40>,  \
    std::array<unsigned long long, 40>, std::array<float, 40>,  \
    std::array<double, 40>, std::array<long double, 40>,  \
    std::array<volatile char, 40>, std::array<volatile wchar_t, 40>,  \
    std::array<volatile char8_t, 40>, std::array<volatile char16_t, 40>,  \
    std::array<volatile char32_t, 40>, std::array<volatile short, 40>,  \
    std::array<volatile int, 40>, std::array<volatile long, 40>,  \
    std::array<volatile long long, 40>,  \
    std::array<volatile unsigned short, 40>,  \
    std::array<volatile unsigned int, 40>,  \
    std::array<volatile unsigned long, 40>,  \
    std::array<volatile unsigned long long, 40>,  \
    std::array<volatile float, 40>, std::array<volatile double, 40>,  \
    std::array<volatile long double, 40>, std::array<char, 41>,  \
    std::array<wchar_t, 41>, std::array<char8_t, 41>,  \
    std::array<char16_t, 41>, std::array<char32_t, 41>,  \
    std::array<short, 41>, std::array<int, 41>, std::array<long, 41>,  \
    std::array<long long, 41>, std::array<unsigned short, 41>,  \
    std::array<unsigned int, 41>, std::array<unsigned long, 41>,  \
    std::array<unsigned long long, 41>, std::array<float, 41>,  \
    std::array<double, 41>, std::array<long double, 41>,  \
    std::array<volatile char, 41>, std::array<volatile wchar_t, 41>,  \
    std::array<volatile char8_t, 41>, std::array<volatile char16_t, 41>,  \
    std::array<volatile char32_t, 41>, std::array<volatile short, 41>,  \
    std::array<volatile int, 41>, std::array<volatile long, 41>,  \
    std::array<volatile long long, 41>,  \
    std::array<volatile unsigned short, 41>,  \
    std::array<volatile unsigned int, 41>,  \
    std::array<volatile unsigned long, 41>,  \
    std::array<volatile unsigned long long, 41>,  \
    std::array<volatile float, 41>, std::array<volatile double, 41>,  \
    std::array<volatile long double, 41>, std::array<char, 42>,  \
    std::array<wchar_t, 42>, std::array<char8_t, 42>,  \
    std::array<char16_t, 42>, std::array<char32_t, 42>,  \
    std::array<short, 42>, std::array<int, 42>, std::array<long, 42>,  \
    std::array<long long, 42>, std::array<unsigned short, 42>,  \
    std::array<unsigned int, 42>, std::array<unsigned long, 42>,  \
    std::array<unsigned long long, 42>, std::array<float, 42>,  \
    std::array<double, 42>, std::array<long double, 42>,  \
    std::array<volatile char, 42>, std::array<volatile wchar_t, 42>,  \
    std::array<volatile char8_t, 42>, std::array<volatile char16_t, 42>,  \
    std::array<volatile char32_t, 42>, std::array<volatile short, 42>,  \
    std::array<volatile int, 42>, std::array<volatile long, 42>,  \
    std::array<volatile long long, 42>,  \
    std::array<volatile unsigned short, 42>,  \
    std::array<volatile unsigned int, 42>,  \
    std::array<volatile unsigned long, 42>,  \
    std::array<volatile unsigned long long, 42>,  \
    std::array<volatile float, 42>, std::array<volatile double, 42>,  \
    std::array<volatile long double, 42>, std::array<char, 43>,  \
    std::array<wchar_t, 43>, std::array<char8_t, 43>,  \
    std::array<char16_t, 43>, std::array<char32_t, 43>,  \
    std::array<short, 43>, std::array<int, 43>, std::array<long, 43>,  \
    std::array<long long, 43>, std::array<unsigned short, 43>,  \
    std::array<unsigned int, 43>, std::array<unsigned long, 43>,  \
    std::array<unsigned long long, 43>, std::array<float, 43>,  \
    std::array<double, 43>, std::array<long double, 43>,  \
    std::array<volatile char, 43>, std::array<volatile wchar_t, 43>,  \
    std::array<volatile char8_t, 43>, std::array<volatile char16_t, 43>,  \
    std::array<volatile char32_t, 43>, std::array<volatile short, 43>,  \
    std::array<volatile int, 43>, std::array<volatile long, 43>,  \
    std::array<volatile long long, 43>,  \
    std::array<volatile unsigned short, 43>,  \
    std::array<volatile unsigned int, 43>,  \
    std::array<volatile unsigned long, 43>,  \
    std::array<volatile unsigned long long, 43>,  \
    std::array<volatile float, 43>, std::array<volatile double, 43>,  \
    std::array<volatile long double, 43>, std::array<char, 44>,  \
    std::array<wchar_t, 44>, std::array<char8_t, 44>,  \
    std::array<char16_t, 44>, std::array<char32_t, 44>,  \
    std::array<short, 44>, std::array<int, 44>, std::array<long, 44>,  \
    std::array<long long, 44>, std::array<unsigned short, 44>,  \
    std::array<unsigned int, 44>, std::array<unsigned long, 44>,  \
    std::array<unsigned long long, 44>, std::array<float, 44>,  \
    std::array<double, 44>, std::array<long double, 44>,  \
    std::array<volatile char, 44>, std::array<volatile wchar_t, 44>,  \
    std::array<volatile char8_t, 44>, std::array<volatile char16_t, 44>,  \
    std::array<volatile char32_t, 44>, std::array<volatile short, 44>,  \
    std::array<volatile int, 44>, std::array<volatile long, 44>,  \
    std::array<volatile long long, 44>,  \
    std::array<volatile unsigned short, 44>,  \
    std::array<volatile unsigned int, 44>,  \
    std::array<volatile unsigned long, 44>,  \
    std::array<volatile unsigned long long, 44>,  \
    std::array<volatile float, 44>, std::array<volatile double, 44>,  \
    std::array<volatile long double, 44>, std::array<char, 45>,  \
    std::array<wchar_t, 45>, std::array<char8_t, 45>,  \
    std::array<char16_t, 45>, std::array<char32_t, 45>,  \
    std::array<short, 45>, std::array<int, 45>, std::array<long, 45>,  \
    std::array<long long, 45>, std::array<unsigned short, 45>,  \
    std::array<unsigned int, 45>, std::array<unsigned long, 45>,  \
    std::array<unsigned long long, 45>, std::array<float, 45>,  \
    std::array<double, 45>, std::array<long double, 45>,  \
    std::array<volatile char, 45>, std::array<volatile wchar_t, 45>,  \
    std::array<volatile char8_t, 45>, std::array<volatile char16_t, 45>,  \
    std::array<volatile char32_t, 45>, std::array<volatile short, 45>,  \
    std::array<volatile int, 45>, std::array<volatile long, 45>,  \
    std::array<volatile long long, 45>,  \
    std::array<volatile unsigned short, 45>,  \
    std::array<volatile unsigned int, 45>,  \
    std::array<volatile unsigned long, 45>,  \
    std::array<volatile unsigned long long, 45>,  \
    std::array<volatile float, 45>, std::array<volatile double, 45>,  \
    std::array<volatile long double, 45>, std::array<char, 46>,  \
    std::array<wchar_t, 46>, std::array<char8_t, 46>,  \
    std::array<char16_t, 46>, std::array<char32_t, 46>,  \
    std::array<short, 46>, std::array<int, 46>, std::array<long, 46>,  \
    std::array<long long, 46>, std::array<unsigned short, 46>,  \
    std::array<unsigned int, 46>, std::array<unsigned long, 46>,  \
    std::array<unsigned long long, 46>, std::array<float, 46>,  \
    std::array<double, 46>, std::array<long double, 46>,  \
    std::array<volatile char, 46>, std::array<volatile wchar_t, 46>,  \
    std::array<volatile char8_t, 46>, std::array<volatile char16_t, 46>,  \
    std::array<volatile char32_t, 46>, std::array<volatile short, 46>,  \
    std::array<volatile int, 46>, std::array<volatile long, 46>,  \
    std::array<volatile long long, 46>,  \
    std::array<volatile unsigned short, 46>,  \
    std::array<volatile unsigned int, 46>,  \
    std::array<volatile unsigned long, 46>,  \
    std::array<volatile unsigned long long, 46>,  \
    std::array<volatile float, 46>, std::array<volatile double, 46>,  \
    std::array<volatile long double, 46>, std::array<char, 47>,  \
    std::array<wchar_t, 47>, std::array<char8_t, 47>,  \
    std::array<char16_t, 47>, std::array<char32_t, 47>,  \
    std::array<short, 47>, std::array<int, 47>, std::array<long, 47>,  \
    std::array<long long, 47>, std::array<unsigned short, 47>,  \
    std::array<unsigned int, 47>, std::array<unsigned long, 47>,  \
    std::array<unsigned long long, 47>, std::array<float, 47>,  \
    std::array<double, 47>, std::array<long double, 47>,  \
    std::array<volatile char, 47>, std::array<volatile wchar_t, 47>,  \
    std::array<volatile char8_t, 47>, std::array<volatile char16_t, 47>,  \
    std::array<volatile char32_t, 47>, std::array<volatile short, 47>,  \
    std::array<volatile int, 47>, std::array<volatile long, 47>,  \
    std::array<volatile long long, 47>,  \
    std::array<volatile unsigned short, 47>,  \
    std::array<volatile unsigned int, 47>,  \
    std::array<volatile unsigned long, 47>,  \
    std::array<volatile unsigned long long, 47>,  \
    std::array<volatile float, 47>, std::array<volatile double, 47>,  \
    std::array<volatile long double, 47>, std::array<char, 48>,  \
    std::array<wchar_t, 48>, std::array<char8_t, 48>,  \
    std::array<char16_t, 48>, std::array<char32_t, 48>,  \
    std::array<short, 48>, std::array<int, 48>, std::array<long, 48>,  \
    std::array<long long, 48>, std::array<unsigned short, 48>,  \
    std::array<unsigned int, 48>, std::array<unsigned long, 48>,  \
    std::array<unsigned long long, 48>, std::array<float, 48>,  \
    std::array<double, 48>, std::array<long double, 48>,  \
    std::array<volatile char, 48>, std::array<volatile wchar_t, 48>,  \
    std::array<volatile char8_t, 48>, std::array<volatile char16_t, 48>,  \
    std::array<volatile char32_t, 48>, std::array<volatile short, 48>,  \
    std::array<volatile int, 48>, std::array<volatile long, 48>,  \
    std::array<volatile long long, 48>,  \
    std::array<volatile unsigned short, 48>,  \
    std::array<volatile unsigned int, 48>,  \
    std::array<volatile unsigned long, 48>,  \
    std::array<volatile unsigned long long, 48>,  \
    std::array<volatile float, 48>, std::array<volatile double, 48>,  \
    std::array<volatile long double, 48>, std::array<char, 49>,  \
    std::array<wchar_t, 49>, std::array<char8_t, 49>,  \
    std::array<char16_t, 49>, std::array<char32_t, 49>,  \
    std::array<short, 49>, std::array<int, 49>, std::array<long, 49>,  \
    std::array<long long, 49>, std::array<unsigned short, 49>,  \
    std::array<unsigned int, 49>, std::array<unsigned long, 49>,  \
    std::array<unsigned long long, 49>, std::array<float, 49>,  \
    std::array<double, 49>, std::array<long double, 49>,  \
    std::array<volatile char, 49>, std::array<volatile wchar_t, 49>,  \
    std::array<volatile char8_t, 49>, std::array<volatile char16_t, 49>,  \
    std::array<volatile char32_t, 49>, std::array<volatile short, 49>,  \
    std::array<volatile int, 49>, std::array<volatile long, 49>,  \
    std::array<volatile long long, 49>,  \
    std::array<volatile unsigned short, 49>,  \
    std::array<volatile unsigned int, 49>,  \
    std::array<volatile unsigned long, 49>,  \
    std::array<volatile unsigned long long, 49>,  \
    std::array<volatile float, 49>, std::array<volatile double, 49>,  \
    std::array<volatile long double, 49>, std::array<char, 50>,  \
    std::array<wchar_t, 50>, std::array<char8_t, 50>,  \
    std::array<char16_t, 50>, std::array<char32_t, 50>,  \
    std::array<short, 50>, std::array<int, 50>, std::array<long, 50>,  \
    std::array<long long, 50>, std::array<unsigned short, 50>,  \
    std::array<unsigned int, 50>, std::array<unsigned long, 50>,  \
    std::array<unsigned long long, 50>, std::array<float, 50>,  \
    std::array<double, 50>, std::array<long double, 50>,  \
    std::array<volatile char, 50>, std::array<volatile wchar_t, 50>,  \
    std::array<volatile char8_t, 50>, std::array<volatile char16_t, 50>,  \
    std::array<volatile char32_t, 50>, std::array<volatile short, 50>,  \
    std::array<volatile int, 50>, std::array<volatile long, 50>,  \
    std::array<volatile long long, 50>,  \
    std::array<volatile unsigned short, 50>,  \
    std::array<volatile unsigned int, 50>,  \
    std::array<volatile unsigned long, 50>,  \
    std::array<volatile unsigned long long, 50>,  \
    std::array<volatile float, 50>, std::array<volatile double, 50>,  \
    std::array<volatile long double, 50>, std::array<char, 51>,  \
    std::array<wchar_t, 51>, std::array<char8_t, 51>,  \
    std::array<char16_t, 51>, std::array<char32_t, 51>,  \
    std::array<short, 51>, std::array<int, 51>, std::array<long, 51>,  \
    std::array<long long, 51>, std::array<unsigned short, 51>,  \
    std::array<unsigned int, 51>, std::array<unsigned long, 51>,  \
    std::array<unsigned long long, 51>, std::array<float, 51>,  \
    std::array<double, 51>, std::array<long double, 51>,  \
    std::array<volatile char, 51>, std::array<volatile wchar_t, 51>,  \
    std::array<volatile char8_t, 51>, std::array<volatile char16_t, 51>,  \
    std::array<volatile char32_t, 51>, std::array<volatile short, 51>,  \
    std::array<volatile int, 51>, std::array<volatile long, 51>,  \
    std::array<volatile long long, 51>,  \
    std::array<volatile unsigned short, 51>,  \
    std::array<volatile unsigned int, 51>,  \
    std::array<volatile unsigned long, 51>,  \
    std::array<volatile unsigned long long, 51>,  \
    std::array<volatile float, 51>, std::array<volatile double, 51>,  \
    std::array<volatile long double, 51>, std::array<char, 52>,  \
    std::array<wchar_t, 52>, std::array<char8_t, 52>,  \
    std::array<char16_t, 52>, std::array<char32_t, 52>,  \
    std::array<short, 52>, std::array<int, 52>, std::array<long, 52>,  \
    std::array<long long, 52>, std::array<unsigned short, 52>,  \
    std::array<unsigned int, 52>, std::array<unsigned long, 52>,  \
    std::array<unsigned long long, 52>, std::array<float, 52>,  \
    std::array<double, 52>, std::array<long double, 52>,  \
    std::array<volatile char, 52>, std::array<volatile wchar_t, 52>,  \
    std::array<volatile char8_t, 52>, std::array<volatile char16_t, 52>,  \
    std::array<volatile char32_t, 52>, std::array<volatile short, 52>,  \
    std::array<volatile int, 52>, std::array<volatile long, 52>,  \
    std::array<volatile long long, 52>,  \
    std::array<volatile unsigned short, 52>,  \
    std::array<volatile unsigned int, 52>,  \
    std::array<volatile unsigned long, 52>,  \
    std::array<volatile unsigned long long, 52>,  \
    std::array<volatile float, 52>, std::array<volatile double, 52>,  \
    std::array<volatile long double, 52>, std::array<char, 53>,  \
    std::array<wchar_t, 53>, std::array<char8_t, 53>,  \
    std::array<char16_t, 53>, std::array<char32_t, 53>,  \
    std::array<short, 53>, std::array<int, 53>, std::array<long, 53>,  \
    std::array<long long, 53>, std::array<unsigned short, 53>,  \
    std::array<unsigned int, 53>, std::array<unsigned long, 53>,  \
    std::array<unsigned long long, 53>, std::array<float, 53>,  \
    std::array<double, 53>, std::array<long double, 53>,  \
    std::array<volatile char, 53>, std::array<volatile wchar_t, 53>,  \
    std::array<volatile char8_t, 53>, std::array<volatile char16_t, 53>,  \
    std::array<volatile char32_t, 53>, std::array<volatile short, 53>,  \
    std::array<volatile int, 53>, std::array<volatile long, 53>,  \
    std::array<volatile long long, 53>,  \
    std::array<volatile unsigned short, 53>,  \
    std::array<volatile unsigned int, 53>,  \
    std::array<volatile unsigned long, 53>,  \
    std::array<volatile unsigned long long, 53>,  \
    std::array<volatile float, 53>, std::array<volatile double, 53>,  \
    std::array<volatile long double, 53>, std::array<char, 54>,  \
    std::array<wchar_t, 54>, std::array<char8_t, 54>,  \
    std::array<char16_t, 54>, std::array<char32_t, 54>,  \
    std::array<short, 54>, std::array<int, 54>, std::array<long, 54>,  \
    std::array<long long, 54>, std::array<unsigned short, 54>,  \
    std::array<unsigned int, 54>, std::array<unsigned long, 54>,  \
    std::array<unsigned long long, 54>, std::array<float, 54>,  \
    std::array<double, 54>, std::array<long double, 54>,  \
    std::array<volatile char, 54>, std::array<volatile wchar_t, 54>,  \
    std::array<volatile char8_t, 54>, std::array<volatile char16_t, 54>,  \
    std::array<volatile char32_t, 54>, std::array<volatile short, 54>,  \
    std::array<volatile int, 54>, std::array<volatile long, 54>,  \
    std::array<volatile long long, 54>,  \
    std::array<volatile unsigned short, 54>,  \
    std::array<volatile unsigned int, 54>,  \
    std::array<volatile unsigned long, 54>,  \
    std::array<volatile unsigned long long, 54>,  \
    std::array<volatile float, 54>, std::array<volatile double, 54>,  \
    std::array<volatile long double, 54>, std::array<char, 55>,  \
    std::array<wchar_t, 55>, std::array<char8_t, 55>,  \
    std::array<char16_t, 55>, std::array<char32_t, 55>,  \
    std::array<short, 55>, std::array<int, 55>, std::array<long, 55>,  \
    std::array<long long, 55>, std::array<unsigned short, 55>,  \
    std::array<unsigned int, 55>, std::array<unsigned long, 55>,  \
    std::array<unsigned long long, 55>, std::array<float, 55>,  \
    std::array<double, 55>, std::array<long double, 55>,  \
    std::array<volatile char, 55>, std::array<volatile wchar_t, 55>,  \
    std::array<volatile char8_t, 55>, std::array<volatile char16_t, 55>,  \
    std::array<volatile char32_t, 55>, std::array<volatile short, 55>,  \
    std::array<volatile int, 55>, std::array<volatile long, 55>,  \
    std::array<volatile long long, 55>,  \
    std::array<volatile unsigned short, 55>,  \
    std::array<volatile unsigned int, 55>,  \
    std::array<volatile unsigned long, 55>,  \
    std::array<volatile unsigned long long, 55>,  \
    std::array<volatile float, 55>, std::array<volatile double, 55>,  \
    std::array<volatile long double, 55>, std::array<char, 56>,  \
    std::array<wchar_t, 56>, std::array<char8_t, 56>,  \
    std::array<char16_t, 56>, std::array<char32_t, 56>,  \
    std::array<short, 56>, std::array<int, 56>, std::array<long, 56>,  \
    std::array<long long, 56>, std::array<unsigned short, 56>,  \
    std::array<unsigned int, 56>, std::array<unsigned long, 56>,  \
    std::array<unsigned long long, 56>, std::array<float, 56>,  \
    std::array<double, 56>, std::array<long double, 56>,  \
    std::array<volatile char, 56>, std::array<volatile wchar_t, 56>,  \
    std::array<volatile char8_t, 56>, std::array<volatile char16_t, 56>,  \
    std::array<volatile char32_t, 56>, std::array<volatile short, 56>,  \
    std::array<volatile int, 56>, std::array<volatile long, 56>,  \
    std::array<volatile long long, 56>,  \
    std::array<volatile unsigned short, 56>,  \
    std::array<volatile unsigned int, 56>,  \
    std::array<volatile unsigned long, 56>,  \
    std::array<volatile unsigned long long, 56>,  \
    std::array<volatile float, 56>, std::array<volatile double, 56>,  \
    std::array<volatile long double, 56>, std::array<char, 57>,  \
    std::array<wchar_t, 57>, std::array<char8_t, 57>,  \
    std::array<char16_t, 57>, std::array<char32_t, 57>,  \
    std::array<short, 57>, std::array<int, 57>, std::array<long, 57>,  \
    std::array<long long, 57>, std::array<unsigned short, 57>,  \
    std::array<unsigned int, 57>, std::array<unsigned long, 57>,  \
    std::array<unsigned long long, 57>, std::array<float, 57>,  \
    std::array<double, 57>, std::array<long double, 57>,  \
    std::array<volatile char, 57>, std::array<volatile wchar_t, 57>,  \
    std::array<volatile char8_t, 57>, std::array<volatile char16_t, 57>,  \
    std::array<volatile char32_t, 57>, std::array<volatile short, 57>,  \
    std::array<volatile int, 57>, std::array<volatile long, 57>,  \
    std::array<volatile long long, 57>,  \
    std::array<volatile unsigned short, 57>,  \
    std::array<volatile unsigned int, 57>,  \
    std::array<volatile unsigned long, 57>,  \
    std::array<volatile unsigned long long, 57>,  \
    std::array<volatile float, 57>, std::array<volatile double, 57>,  \
    std::array<volatile long double, 57>, std::array<char, 58>,  \
    std::array<wchar_t, 58>, std::array<char8_t, 58>,  \
    std::array<char16_t, 58>, std::array<char32_t, 58>,  \
    std::array<short, 58>, std::array<int, 58>, std::array<long, 58>,  \
    std::array<long long, 58>, std::array<unsigned short, 58>,  \
    std::array<unsigned int, 58>, std::array<unsigned long, 58>,  \
    std::array<unsigned long long, 58>, std::array<float, 58>,  \
    std::array<double, 58>, std::array<long double, 58>,  \
    std::array<volatile char, 58>, std::array<volatile wchar_t, 58>,  \
    std::array<volatile char8_t, 58>, std::array<volatile char16_t, 58>,  \
    std::array<volatile char32_t, 58>, std::array<volatile short, 58>,  \
    std::array<volatile int, 58>, std::array<volatile long, 58>,  \
    std::array<volatile long long, 58>,  \
    std::array<volatile unsigned short, 58>,  \
    std::array<volatile unsigned int, 58>,  \
    std::array<volatile unsigned long, 58>,  \
    std::array<volatile unsigned long long, 58>,  \
    std::array<volatile float, 58>, std::array<volatile double, 58>,  \
    std::array<volatile long double, 58>, std::array<char, 59>,  \
    std::array<wchar_t, 59>, std::array<char8_t, 59>,  \
    std::array<char16_t, 59>, std::array<char32_t, 59>,  \
    std::array<short, 59>, std::array<int, 59>, std::array<long, 59>,  \
    std::array<long long, 59>, std::array<unsigned short, 59>,  \
    std::array<unsigned int, 59>, std::array<unsigned long, 59>,  \
    std::array<unsigned long long, 59>, std::array<float, 59>,  \
    std::array<double, 59>, std::array<long double, 59>,  \
    std::array<volatile char, 59>, std::array<volatile wchar_t, 59>,  \
    std::array<volatile char8_t, 59>, std::array<volatile char16_t, 59>,  \
    std::array<volatile char32_t, 59>, std::array<volatile short, 59>,  \
    std::array<volatile int, 59>, std::array<volatile long, 59>,  \
    std::array<volatile long long, 59>,  \
    std::array<volatile unsigned short, 59>,  \
    std::array<volatile unsigned int, 59>,  \
    std::array<volatile unsigned long, 59>,  \
    std::array<volatile unsigned long long, 59>,  \
    std::array<volatile float, 59>, std::array<volatile double, 59>,  \
    std::array<volatile long double, 59>, std::array<char, 60>,  \
    std::array<wchar_t, 60>, std::array<char8_t, 60>,  \
    std::array<char16_t, 60>, std::array<char32_t, 60>,  \
    std::array<short, 60>, std::array<int, 60>, std::array<long, 60>,  \
    std::array<long long, 60>, std::array<unsigned short, 60>,  \
    std::array<unsigned int, 60>, std::array<unsigned long, 60>,  \
    std::array<unsigned long long, 60>, std::array<float, 60>,  \
    std::array<double, 60>, std::array<long double, 60>,  \
    std::array<volatile char, 60>, std::array<volatile wchar_t, 60>,  \
    std::array<volatile char8_t, 60>, std::array<volatile char16_t, 60>,  \
    std::array<volatile char32_t, 60>, std::array<volatile short, 60>,  \
    std::array<volatile int, 60>, std::array<volatile long, 60>,  \
    std::array<volatile long long, 60>,  \
    std::array<volatile unsigned short, 60>,  \
    std::array<volatile unsigned int, 60>,  \
    std::array<volatile unsigned long, 60>,  \
    std::array<volatile unsigned long long, 60>,  \
    std::array<volatile float, 60>, std::array<volatile double, 60>,  \
    std::array<volatile long double, 60>, std::array<char, 61>,  \
    std::array<wchar_t, 61>, std::array<char8_t, 61>,  \
    std::array<char16_t, 61>, std::array<char32_t, 61>,  \
    std::array<short, 61>, std::array<int, 61>, std::array<long, 61>,  \
    std::array<long long, 61>, std::array<unsigned short, 61>,  \
    std::array<unsigned int, 61>, std::array<unsigned long, 61>,  \
    std::array<unsigned long long, 61>, std::array<float, 61>,  \
    std::array<double, 61>, std::array<long double, 61>,  \
    std::array<volatile char, 61>, std::array<volatile wchar_t, 61>,  \
    std::array<volatile char8_t, 61>, std::array<volatile char16_t, 61>,  \
    std::array<volatile char32_t, 61>, std::array<volatile short, 61>,  \
    std::array<volatile int, 61>, std::array<volatile long, 61>,  \
    std::array<volatile long long, 61>,  \
    std::array<volatile unsigned short, 61>,  \
    std::array<volatile unsigned int, 61>,  \
    std::array<volatile unsigned long, 61>,  \
    std::array<volatile unsigned long long, 61>,  \
    std::array<volatile float, 61>, std::array<volatile double, 61>,  \
    std::array<volatile long double, 61>, std::array<char, 62>,  \
    std::array<wchar_t, 62>, std::array<char8_t, 62>,  \
    std::array<char16_t, 62>, std::array<char32_t, 62>,  \
    std::array<short, 62>, std::array<int, 62>, std::array<long, 62>,  \
    std::array<long long, 62>, std::array<unsigned short, 62>,  \
    std::array<unsigned int, 62>, std::array<unsigned long, 62>,  \
    std::array<unsigned long long, 62>, std::array<float, 62>,  \
    std::array<double, 62>, std::array<long double, 62>,  \
    std::array<volatile char, 62>, std::array<volatile wchar_t, 62>,  \
    std::array<volatile char8_t, 62>, std::array<volatile char16_t, 62>,  \
    std::array<volatile char32_t, 62>, std::array<volatile short, 62>,  \
    std::array<volatile int, 62>, std::array<volatile long, 62>,  \
    std::array<volatile long long, 62>,  \
    std::array<volatile unsigned short, 62>,  \
    std::array<volatile unsigned int, 62>,  \
    std::array<volatile unsigned long, 62>,  \
    std::array<volatile unsigned long long, 62>,  \
    std::array<volatile float, 62>, std::array<volatile double, 62>,  \
    std::array<volatile long double, 62>, std::array<char, 63>,  \
    std::array<wchar_t, 63>, std::array<char8_t, 63>,  \
    std::array<char16_t, 63>, std::array<char32_t, 63>,  \
    std::array<short, 63>, std::array<int, 63>, std::array<long, 63>,  \
    std::array<long long, 63>, std::array<unsigned short, 63>,  \
    std::array<unsigned int, 63>, std::array<unsigned long, 63>,  \
    std::array<unsigned long long, 63>, std::array<float, 63>,  \
    std::array<double, 63>, std::array<long double, 63>,  \
    std::array<volatile char, 63>, std::array<volatile wchar_t, 63>,  \
    std::array<volatile char8_t, 63>, std::array<volatile char16_t, 63>,  \
    std::array<volatile char32_t, 63>, std::array<volatile short, 63>,  \
    std::array<volatile int, 63>, std::array<volatile long, 63>,  \
    std::array<volatile long long, 63>,  \
    std::array<volatile unsigned short, 63>,  \
    std::array<volatile unsigned int, 63>,  \
    std::array<volatile unsigned long, 63>,  \
    std::array<volatile unsigned long long, 63>,  \
    std::array<volatile float, 63>, std::array<volatile double, 63>,  \
    std::array<volatile long double, 63>, std::array<char, 64>,  \
    std::array<wchar_t, 64>, std::array<char8_t, 64>,  \
    std::array<char16_t, 64>, std::array<char32_t, 64>,  \
    std::array<short, 64>, std::array<int, 64>, std::array<long, 64>,  \
    std::array<long long, 64>, std::array<unsigned short, 64>,  \
    std::array<unsigned int, 64>, std::array<unsigned long, 64>,  \
    std::array<unsigned long long, 64>, std::array<float, 64>,  \
    std::array<double, 64>, std::array<long double, 64>,  \
    std::array<volatile char, 64>, std::array<volatile wchar_t, 64>,  \
    std::array<volatile char8_t, 64>, std::array<volatile char16_t, 64>,  \
    std::array<volatile char32_t, 64>, std::array<volatile short, 64>,  \
    std::array<volatile int, 64>, std::array<volatile long, 64>,  \
    std::array<volatile long long, 64>,  \
    std::array<volatile unsigned short, 64>,  \
    std::array<volatile unsigned int, 64>,  \
    std::array<volatile unsigned long, 64>,  \
    std::array<volatile unsigned long long, 64>,  \
    std::array<volatile float, 64>, std::array<volatile double, 64>,  \
    std::array<volatile long double, 64>, std::array<char, 65>,  \
    std::array<wchar_t, 65>, std::array<char8_t, 65>,  \
    std::array<char16_t, 65>, std::array<char32_t, 65>,  \
    std::array<short, 65>, std::array<int, 65>, std::array<long, 65>,  \
    std::array<long long, 65>, std::array<unsigned short, 65>,  \
    std::array<unsigned int, 65>, std::array<unsigned long, 65>,  \
    std::array<unsigned long long, 65>, std::array<float, 65>,  \
    std::array<double, 65>, std::array<long double, 65>,  \
    std::array<volatile char, 65>, std::array<volatile wchar_t, 65>,  \
    std::array<volatile char8_t, 65>, std::array<volatile char16_t, 65>,  \
    std::array<volatile char32_t, 65>, std::array<volatile short, 65>,  \
    std::array<volatile int, 65>, std::array<volatile long, 65>,  \
    std::array<volatile long long, 65>,  \
    std::array<volatile unsigned short, 65>,  \
    std::array<volatile unsigned int, 65>,  \
    std::array<volatile unsigned long, 65>,  \
    std::array<volatile unsigned long long, 65>,  \
    std::array<volatile float, 65>, std::array<volatile double, 65>,  \
    std::array<volatile long double, 65>, std::array<char, 66>,  \
    std::array<wchar_t, 66>, std::array<char8_t, 66>,  \
    std::array<char16_t, 66>, std::array<char32_t, 66>,  \
    std::array<short, 66>, std::array<int, 66>, std::array<long, 66>,  \
    std::array<long long, 66>, std::array<unsigned short, 66>,  \
    std::array<unsigned int, 66>, std::array<unsigned long, 66>,  \
    std::array<unsigned long long, 66>, std::array<float, 66>,  \
    std::array<double, 66>, std::array<long double, 66>,  \
    std::array<volatile char, 66>, std::array<volatile wchar_t, 66>,  \
    std::array<volatile char8_t, 66>, std::array<volatile char16_t, 66>,  \
    std::array<volatile char32_t, 66>, std::array<volatile short, 66>,  \
    std::array<volatile int, 66>, std::array<volatile long, 66>,  \
    std::array<volatile long long, 66>,  \
    std::array<volatile unsigned short, 66>,  \
    std::array<volatile unsigned int, 66>,  \
    std::array<volatile unsigned long, 66>,  \
    std::array<volatile unsigned long long, 66>,  \
    std::array<volatile float, 66>, std::array<volatile double, 66>,  \
    std::array<volatile long double, 66>, std::array<char, 67>,  \
    std::array<wchar_t, 67>, std::array<char8_t, 67>,  \
    std::array<char16_t, 67>, std::array<char32_t, 67>,  \
    std::array<short, 67>, std::array<int, 67>, std::array<long, 67>,  \
    std::array<long long, 67>, std::array<unsigned short, 67>,  \
    std::array<unsigned int, 67>, std::array<unsigned long, 67>,  \
    std::array<unsigned long long, 67>, std::array<float, 67>,  \
    std::array<double, 67>, std::array<long double, 67>,  \
    std::array<volatile char, 67>, std::array<volatile wchar_t, 67>,  \
    std::array<volatile char8_t, 67>, std::array<volatile char16_t, 67>,  \
    std::array<volatile char32_t, 67>, std::array<volatile short, 67>,  \
    std::array<volatile int, 67>, std::array<volatile long, 67>,  \
    std::array<volatile long long, 67>,  \
    std::array<volatile unsigned short, 67>,  \
    std::array<volatile unsigned int, 67>,  \
    std::array<volatile unsigned long, 67>,  \
    std::array<volatile unsigned long long, 67>,  \
    std::array<volatile float, 67>, std::array<volatile double, 67>,  \
    std::array<volatile long double, 67>, std::array<char, 68>,  \
    std::array<wchar_t, 68>, std::array<char8_t, 68>,  \
    std::array<char16_t, 68>, std::array<char32_t, 68>,  \
    std::array<short, 68>, std::array<int, 68>, std::array<long, 68>,  \
    std::array<long long, 68>, std::array<unsigned short, 68>,  \
    std::array<unsigned int, 68>, std::array<unsigned long, 68>,  \
    std::array<unsigned long long, 68>, std::array<float, 68>,  \
    std::array<double, 68>, std::array<long double, 68>,  \
    std::array<volatile char, 68>, std::array<volatile wchar_t, 68>,  \
    std::array<volatile char8_t, 68>, std::array<volatile char16_t, 68>,  \
    std::array<volatile char32_t, 68>, std::array<volatile short, 68>,  \
    std::array<volatile int, 68>, std::array<volatile long, 68>,  \
    std::array<volatile long long, 68>,  \
    std::array<volatile unsigned short, 68>,  \
    std::array<volatile unsigned int, 68>,  \
    std::array<volatile unsigned long, 68>,  \
    std::array<volatile unsigned long long, 68>,  \
    std::array<volatile float, 68>, std::array<volatile double, 68>,  \
    std::array<volatile long double, 68>, std::array<char, 69>,  \
    std::array<wchar_t, 69>, std::array<char8_t, 69>,  \
    std::array<char16_t, 69>, std::array<char32_t, 69>,  \
    std::array<short, 69>, std::array<int, 69>, std::array<long, 69>,  \
    std::array<long long, 69>, std::array<unsigned short, 69>,  \
    std::array<unsigned int, 69>, std::array<unsigned long, 69>,  \
    std::array<unsigned long long, 69>, std::array<float, 69>,  \
    std::array<double, 69>, std::array<long double, 69>,  \
    std::array<volatile char, 69>, std::array<volatile wchar_t, 69>,  \
    std::array<volatile char8_t, 69>, std::array<volatile char16_t, 69>,  \
    std::array<volatile char32_t, 69>, std::array<volatile short, 69>,  \
    std::array<volatile int, 69>, std::array<volatile long, 69>,  \
    std::array<volatile long long, 69>,  \
    std::array<volatile unsigned short, 69>,  \
    std::array<volatile unsigned int, 69>,  \
    std::array<volatile unsigned long, 69>,  \
    std::array<volatile unsigned long long, 69>,  \
    std::array<volatile float, 69>, std::array<volatile double, 69>,  \
    std::array<volatile long double, 69>, std::array<char, 70>,  \
    std::array<wchar_t, 70>, std::array<char8_t, 70>,  \
    std::array<char16_t, 70>, std::array<char32_t, 70>,  \
    std::array<short, 70>, std::array<int, 70>, std::array<long, 70>,  \
    std::array<long long, 70>, std::array<unsigned short, 70>,  \
    std::array<unsigned int, 70>, std::array<unsigned long, 70>,  \
    std::array<unsigned long long, 70>, std::array<float, 70>,  \
    std::array<double, 70>, std::array<long double, 70>,  \
    std::array<volatile char, 70>, std::array<volatile wchar_t, 70>,  \
    std::array<volatile char8_t, 70>, std::array<volatile char16_t, 70>,  \
    std::array<volatile char32_t, 70>, std::array<volatile short, 70>,  \
    std::array<volatile int, 70>, std::array<volatile long, 70>,  \
    std::array<volatile long long, 70>,  \
    std::array<volatile unsigned short, 70>,  \
    std::array<volatile unsigned int, 70>,  \
    std::array<volatile unsigned long, 70>,  \
    std::array<volatile unsigned long long, 70>,  \
    std::array<volatile float, 70>, std::array<volatile double, 70>,  \
    std::array<volatile long double, 70>, std::array<char, 71>,  \
    std::array<wchar_t, 71>, std::array<char8_t, 71>,  \
    std::array<char16_t, 71>, std::array<char32_t, 71>,  \
    std::array<short, 71>, std::array<int, 71>, std::array<long, 71>,  \
    std::array<long long, 71>, std::array<unsigned short, 71>,  \
    std::array<unsigned int, 71>, std::array<unsigned long, 71>,  \
    std::array<unsigned long long, 71>, std::array<float, 71>,  \
    std::array<double, 71>, std::array<long double, 71>,  \
    std::array<volatile char, 71>, std::array<volatile wchar_t, 71>,  \
    std::array<volatile char8_t, 71>, std::array<volatile char16_t, 71>,  \
    std::array<volatile char32_t, 71>, std::array<volatile short, 71>,  \
    std::array<volatile int, 71>, std::array<volatile long, 71>,  \
    std::array<volatile long long, 71>,  \
    std::array<volatile unsigned short, 71>,  \
    std::array<volatile unsigned int, 71>,  \
    std::array<volatile unsigned long, 71>,  \
    std::array<volatile unsigned long long, 71>,  \
    std::array<volatile float, 71>, std::array<volatile double, 71>,  \
    std::array<volatile long double, 71>, std::array<char, 72>,  \
    std::array<wchar_t, 72>, std::array<char8_t, 72>,  \
    std::array<char16_t, 72>, std::array<char32_t, 72>,  \
    std::array<short, 72>, std::array<int, 72>, std::array<long, 72>,  \
    std::array<long long, 72>, std::array<unsigned short, 72>,  \
    std::array<unsigned int, 72>, std::array<unsigned long, 72>,  \
    std::array<unsigned long long, 72>, std::array<float, 72>,  \
    std::array<double, 72>, std::array<long double, 72>,  \
    std::array<volatile char, 72>, std::array<volatile wchar_t, 72>,  \
    std::array<volatile char8_t, 72>, std::array<volatile char16_t, 72>,  \
    std::array<volatile char32_t, 72>, std::array<volatile short, 72>,  \
    std::array<volatile int, 72>, std::array<volatile long, 72>,  \
    std::array<volatile long long, 72>,  \
    std::array<volatile unsigned short, 72>,  \
    std::array<volatile unsigned int, 72>,  \
    std::array<volatile unsigned long, 72>,  \
    std::array<volatile unsigned long long, 72>,  \
    std::array<volatile float, 72>, std::array<volatile double, 72>,  \
    std::array<volatile long double, 72>, std::array<char, 73>,  \
    std::array<wchar_t, 73>, std::array<char8_t, 73>,  \
    std::array<char16_t, 73>, std::array<char32_t, 73>,  \
    std::array<short, 73>, std::array<int, 73>, std::array<long, 73>,  \
    std::array<long long, 73>, std::array<unsigned short, 73>,  \
    std::array<unsigned int, 73>, std::array<unsigned long, 73>,  \
    std::array<unsigned long long, 73>, std::array<float, 73>,  \
    std::array<double, 73>, std::array<long double, 73>,  \
    std::array<volatile char, 73>, std::array<volatile wchar_t, 73>,  \
    std::array<volatile char8_t, 73>, std::array<volatile char16_t, 73>,  \
    std::array<volatile char32_t, 73>, std::array<volatile short, 73>,  \
    std::array<volatile int, 73>, std::array<volatile long, 73>,  \
    std::array<volatile long long, 73>,  \
    std::array<volatile unsigned short, 73>,  \
    std::array<volatile unsigned int, 73>,  \
    std::array<volatile unsigned long, 73>,  \
    std::array<volatile unsigned long long, 73>,  \
    std::array<volatile float, 73>, std::array<volatile double, 73>,  \
    std::array<volatile long double, 73>, std::array<char, 74>,  \
    std::array<wchar_t, 74>, std::array<char8_t, 74>,  \
    std::array<char16_t, 74>, std::array<char32_t, 74>,  \
    std::array<short, 74>, std::array<int, 74>, std::array<long, 74>,  \
    std::array<long long, 74>, std::array<unsigned short, 74>,  \
    std::array<unsigned int, 74>, std::array<unsigned long, 74>,  \
    std::array<unsigned long long, 74>, std::array<float, 74>,  \
    std::array<double, 74>, std::array<long double, 74>,  \
    std::array<volatile char, 74>, std::array<volatile wchar_t, 74>,  \
    std::array<volatile char8_t, 74>, std::array<volatile char16_t, 74>,  \
    std::array<volatile char32_t, 74>, std::array<volatile short, 74>,  \
    std::array<volatile int, 74>, std::array<volatile long, 74>,  \
    std::array<volatile long long, 74>,  \
    std::array<volatile unsigned short, 74>,  \
    std::array<volatile unsigned int, 74>,  \
    std::array<volatile unsigned long, 74>,  \
    std::array<volatile unsigned long long, 74>,  \
    std::array<volatile float, 74>, std::array<volatile double, 74>,  \
    std::array<volatile long double, 74>, std::array<char, 75>,  \
    std::array<wchar_t, 75>, std::array<char8_t, 75>,  \
    std::array<char16_t, 75>, std::array<char32_t, 75>,  \
    std::array<short, 75>, std::array<int, 75>, std::array<long, 75>,  \
    std::array<long long, 75>, std::array<unsigned short, 75>,  \
    std::array<unsigned int, 75>, std::array<unsigned long, 75>,  \
    std::array<unsigned long long, 75>, std::array<float, 75>,  \
    std::array<double, 75>, std::array<long double, 75>,  \
    std::array<volatile char, 75>, std::array<volatile wchar_t, 75>,  \
    std::array<volatile char8_t, 75>, std::array<volatile char16_t, 75>,  \
    std::array<volatile char32_t, 75>, std::array<volatile short, 75>,  \
    std::array<volatile int, 75>, std::array<volatile long, 75>,  \
    std::array<volatile long long, 75>,  \
    std::array<volatile unsigned short, 75>,  \
    std::array<volatile unsigned int, 75>,  \
    std::array<volatile unsigned long, 75>,  \
    std::array<volatile unsigned long long, 75>,  \
    std::array<volatile float, 75>, std::array<volatile double, 75>,  \
    std::array<volatile long double, 75>, std::array<char, 76>,  \
    std::array<wchar_t, 76>, std::array<char8_t, 76>,  \
    std::array<char16_t, 76>, std::array<char32_t, 76>,  \
    std::array<short, 76>, std::array<int, 76>, std::array<long, 76>,  \
    std::array<long long, 76>, std::array<unsigned short, 76>,  \
    std::array<unsigned int, 76>, std::array<unsigned long, 76>,  \
    std::array<unsigned long long, 76>, std::array<float, 76>,  \
    std::array<double, 76>, std::array<long double, 76>,  \
    std::array<volatile char, 76>, std::array<volatile wchar_t, 76>,  \
    std::array<volatile char8_t, 76>, std::array<volatile char16_t, 76>,  \
    std::array<volatile char32_t, 76>, std::array<volatile short, 76>,  \
    std::array<volatile int, 76>, std::array<volatile long, 76>,  \
    std::array<volatile long long, 76>,  \
    std::array<volatile unsigned short, 76>,  \
    std::array<volatile unsigned int, 76>,  \
    std::array<volatile unsigned long, 76>,  \
    std::array<volatile unsigned long long, 76>,  \
    std::array<volatile float, 76>, std::array<volatile double, 76>,  \
    std::array<volatile long double, 76>, std::array<char, 77>,  \
    std::array<wchar_t, 77>, std::array<char8_t, 77>,  \
    std::array<char16_t, 77>, std::array<char32_t, 77>,  \
    std::array<short, 77>, std::array<int, 77>, std::array<long, 77>,  \
    std::array<long long, 77>, std::array<unsigned short, 77>,  \
    std::array<unsigned int, 77>, std::array<unsigned long, 77>,  \
    std::array<unsigned long long, 77>, std::array<float, 77>,  \
    std::array<double, 77>, std::array<long double, 77>,  \
    std::array<volatile char, 77>, std::array<volatile wchar_t, 77>,  \
    std::array<volatile char8_t, 77>, std::array<volatile char16_t, 77>,  \
    std::array<volatile char32_t, 77>, std::array<volatile short, 77>,  \
    std::array<volatile int, 77>, std::array<volatile long, 77>,  \
    std::array<volatile long long, 77>,  \
    std::array<volatile unsigned short, 77>,  \
    std::array<volatile unsigned int, 77>,  \
    std::array<volatile unsigned long, 77>,  \
    std::array<volatile unsigned long long, 77>,  \
    std::array<volatile float, 77>, std::array<volatile double, 77>,  \
    std::array<volatile long double, 77>, std::array<char, 78>,  \
    std::array<wchar_t, 78>, std::array<char8_t, 78>,  \
    std::array<char16_t, 78>, std::array<char32_t, 78>,  \
    std::array<short, 78>, std::array<int, 78>, std::array<long, 78>,  \
    std::array<long long, 78>, std::array<unsigned short, 78>,  \
    std::array<unsigned int, 78>, std::array<unsigned long, 78>,  \
    std::array<unsigned long long, 78>, std::array<float, 78>,  \
    std::array<double, 78>, std::array<long double, 78>,  \
    std::array<volatile char, 78>, std::array<volatile wchar_t, 78>,  \
    std::array<volatile char8_t, 78>, std::array<volatile char16_t, 78>,  \
    std::array<volatile char32_t, 78>, std::array<volatile short, 78>,  \
    std::array<volatile int, 78>, std::array<volatile long, 78>,  \
    std::array<volatile long long, 78>,  \
    std::array<volatile unsigned short, 78>,  \
    std::array<volatile unsigned int, 78>,  \
    std::array<volatile unsigned long, 78>,  \
    std::array<volatile unsigned long long, 78>,  \
    std::array<volatile float, 78>, std::array<volatile double, 78>,  \
    std::array<volatile long double, 78>, std::array<char, 79>,  \
    std::array<wchar_t, 79>, std::array<char8_t, 79>,  \
    std::array<char16_t, 79>, std::array<char32_t, 79>,  \
    std::array<short, 79>, std::array<int, 79>, std::array<long, 79>,  \
    std::array<long long, 79>, std::array<unsigned short, 79>,  \
    std::array<unsigned int, 79>, std::array<unsigned long, 79>,  \
    std::array<unsigned long long, 79>, std::array<float, 79>,  \
    std::array<double, 79>, std::array<long double, 79>,  \
    std::array<volatile char, 79>, std::array<volatile wchar_t, 79>,  \
    std::array<volatile char8_t, 79>, std::array<volatile char16_t, 79>,  \
    std::array<volatile char32_t, 79>, std::array<volatile short, 79>,  \
    std::array<volatile int, 79>, std::array<volatile long, 79>,  \
    std::array<volatile long long, 79>,  \
    std::array<volatile unsigned short, 79>,  \
    std::array<volatile unsigned int, 79>,  \
    std::array<volatile unsigned long, 79>,  \
    std::array<volatile unsigned long long, 79>,  \
    std::array<volatile float, 79>, std::array<volatile double, 79>,  \
    std::array<volatile long double, 79>, std::array<char, 80>,  \
    std::array<wchar_t, 80>, std::array<char8_t, 80>,  \
    std::array<char16_t, 80>, std::array<char32_t, 80>,  \
    std::array<short, 80>, std::array<int, 80>, std::array<long, 80>,  \
    std::array<long long, 80>, std::array<unsigned short, 80>,  \
    std::array<unsigned int, 80>, std::array<unsigned long, 80>,  \
    std::array<unsigned long long, 80>, std::array<float, 80>,  \
    std::array<double, 80>, std::array<long double, 80>,  \
    std::array<volatile char, 80>, std::array<volatile wchar_t, 80>,  \
    std::array<volatile char8_t, 80>, std::array<volatile char16_t, 80>,  \
    std::array<volatile char32_t, 80>, std::array<volatile short, 80>,  \
    std::array<volatile int, 80>, std::array<volatile long, 80>,  \
    std::array<volatile long long, 80>,  \
    std::array<volatile unsigned short, 80>,  \
    std::array<volatile unsigned int, 80>,  \
    std::array<volatile unsigned long, 80>,  \
    std::array<volatile unsigned long long, 80>,  \
    std::array<volatile float, 80>, std::array<volatile double, 80>,  \
    std::array<volatile long double, 80>, std::array<char, 81>,  \
    std::array<wchar_t, 81>, std::array<char8_t, 81>,  \
    std::array<char16_t, 81>, std::array<char32_t, 81>,  \
    std::array<short, 81>, std::array<int, 81>, std::array<long, 81>,  \
    std::array<long long, 81>, std::array<unsigned short, 81>,  \
    std::array<unsigned int, 81>, std::array<unsigned long, 81>,  \
    std::array<unsigned long long, 81>, std::array<float, 81>,  \
    std::array<double, 81>, std::array<long double, 81>,  \
    std::array<volatile char, 81>, std::array<volatile wchar_t, 81>,  \
    std::array<volatile char8_t, 81>, std::array<volatile char16_t, 81>,  \
    std::array<volatile char32_t, 81>, std::array<volatile short, 81>,  \
    std::array<volatile int, 81>, std::array<volatile long, 81>,  \
    std::array<volatile long long, 81>,  \
    std::array<volatile unsigned short, 81>,  \
    std::array<volatile unsigned int, 81>,  \
    std::array<volatile unsigned long, 81>,  \
    std::array<volatile unsigned long long, 81>,  \
    std::array<volatile float, 81>, std::array<volatile double, 81>,  \
    std::array<volatile long double, 81>, std::array<char, 82>,  \
    std::array<wchar_t, 82>, std::array<char8_t, 82>,  \
    std::array<char16_t, 82>, std::array<char32_t, 82>,  \
    std::array<short, 82>, std::array<int, 82>, std::array<long, 82>,  \
    std::array<long long, 82>, std::array<unsigned short, 82>,  \
    std::array<unsigned int, 82>, std::array<unsigned long, 82>,  \
    std::array<unsigned long long, 82>, std::array<float, 82>,  \
    std::array<double, 82>, std::array<long double, 82>,  \
    std::array<volatile char, 82>, std::array<volatile wchar_t, 82>,  \
    std::array<volatile char8_t, 82>, std::array<volatile char16_t, 82>,  \
    std::array<volatile char32_t, 82>, std::array<volatile short, 82>,  \
    std::array<volatile int, 82>, std::array<volatile long, 82>,  \
    std::array<volatile long long, 82>,  \
    std::array<volatile unsigned short, 82>,  \
    std::array<volatile unsigned int, 82>,  \
    std::array<volatile unsigned long, 82>,  \
    std::array<volatile unsigned long long, 82>,  \
    std::array<volatile float, 82>, std::array<volatile double, 82>,  \
    std::array<volatile long double, 82>, std::array<char, 83>,  \
    std::array<wchar_t, 83>, std::array<char8_t, 83>,  \
    std::array<char16_t, 83>, std::array<char32_t, 83>,  \
    std::array<short, 83>, std::array<int, 83>, std::array<long, 83>,  \
    std::array<long long, 83>, std::array<unsigned short, 83>,  \
    std::array<unsigned int, 83>, std::array<unsigned long, 83>,  \
    std::array<unsigned long long, 83>, std::array<float, 83>,  \
    std::array<double, 83>, std::array<long double, 83>,  \
    std::array<volatile char, 83>, std::array<volatile wchar_t, 83>,  \
    std::array<volatile char8_t, 83>, std::array<volatile char16_t, 83>,  \
    std::array<volatile char32_t, 83>, std::array<volatile short, 83>,  \
    std::array<volatile int, 83>, std::array<volatile long, 83>,  \
    std::array<volatile long long, 83>,  \
    std::array<volatile unsigned short, 83>,  \
    std::array<volatile unsigned int, 83>,  \
    std::array<volatile unsigned long, 83>,  \
    std::array<volatile unsigned long long, 83>,  \
    std::array<volatile float, 83>, std::array<volatile double, 83>,  \
    std::array<volatile long double, 83>, std::array<char, 84>,  \
    std::array<wchar_t, 84>, std::array<char8_t, 84>,  \
    std::array<char16_t, 84>, std::array<char32_t, 84>,  \
    std::array<short, 84>, std::array<int, 84>, std::array<long, 84>,  \
    std::array<long long, 84>, std::array<unsigned short, 84>,  \
    std::array<unsigned int, 84>, std::array<unsigned long, 84>,  \
    std::array<unsigned long long, 84>, std::array<float, 84>,  \
    std::array<double, 84>, std::array<long double, 84>,  \
    std::array<volatile char, 84>, std::array<volatile wchar_t, 84>,  \
    std::array<volatile char8_t, 84>, std::array<volatile char16_t, 84>,  \
    std::array<volatile char32_t, 84>, std::array<volatile short, 84>,  \
    std::array<volatile int, 84>, std::array<volatile long, 84>,  \
    std::array<volatile long long, 84>,  \
    std::array<volatile unsigned short, 84>,  \
    std::array<volatile unsigned int, 84>,  \
    std::array<volatile unsigned long, 84>,  \
    std::array<volatile unsigned long long, 84>,  \
    std::array<volatile float, 84>, std::array<volatile double, 84>,  \
    std::array<volatile long double, 84>, std::array<char, 85>,  \
    std::array<wchar_t, 85>, std::array<char8_t, 85>,  \
    std::array<char16_t, 85>, std::array<char32_t, 85>,  \
    std::array<short, 85>, std::array<int, 85>, std::array<long, 85>,  \
    std::array<long long, 85>, std::array<unsigned short, 85>,  \
    std::array<unsigned int, 85>, std::array<unsigned long, 85>,  \
    std::array<unsigned long long, 85>, std::array<float, 85>,  \
    std::array<double, 85>, std::array<long double, 85>,  \
    std::array<volatile char, 85>, std::array<volatile wchar_t, 85>,  \
    std::array<volatile char8_t, 85>, std::array<volatile char16_t, 85>,  \
    std::array<volatile char32_t, 85>, std::array<volatile short, 85>,  \
    std::array<volatile int, 85>, std::array<volatile long, 85>,  \
    std::array<volatile long long, 85>,  \
    std::array<volatile unsigned short, 85>,  \
    std::array<volatile unsigned int, 85>,  \
    std::array<volatile unsigned long, 85>,  \
    std::array<volatile unsigned long long, 85>,  \
    std::array<volatile float, 85>, std::array<volatile double, 85>,  \
    std::array<volatile long double, 85>, std::array<char, 86>,  \
    std::array<wchar_t, 86>, std::array<char8_t, 86>,  \
    std::array<char16_t, 86>, std::array<char32_t, 86>,  \
    std::array<short, 86>, std::array<int, 86>, std::array<long, 86>,  \
    std::array<long long, 86>, std::array<unsigned short, 86>,  \
    std::array<unsigned int, 86>, std::array<unsigned long, 86>,  \
    std::array<unsigned long long, 86>, std::array<float, 86>,  \
    std::array<double, 86>, std::array<long double, 86>,  \
    std::array<volatile char, 86>, std::array<volatile wchar_t, 86>,  \
    std::array<volatile char8_t, 86>, std::array<volatile char16_t, 86>,  \
    std::array<volatile char32_t, 86>, std::array<volatile short, 86>,  \
    std::array<volatile int, 86>, std::array<volatile long, 86>,  \
    std::array<volatile long long, 86>,  \
    std::array<volatile unsigned short, 86>,  \
    std::array<volatile unsigned int, 86>,  \
    std::array<volatile unsigned long, 86>,  \
    std::array<volatile unsigned long long, 86>,  \
    std::array<volatile float, 86>, std::array<volatile double, 86>,  \
    std::array<volatile long double, 86>, std::array<char, 87>,  \
    std::array<wchar_t, 87>, std::array<char8_t, 87>,  \
    std::array<char16_t, 87>, std::array<char32_t, 87>,  \
    std::array<short, 87>, std::array<int, 87>, std::array<long, 87>,  \
    std::array<long long, 87>, std::array<unsigned short, 87>,  \
    std::array<unsigned int, 87>, std::array<unsigned long, 87>,  \
    std::array<unsigned long long, 87>, std::array<float, 87>,  \
    std::array<double, 87>, std::array<long double, 87>,  \
    std::array<volatile char, 87>, std::array<volatile wchar_t, 87>,  \
    std::array<volatile char8_t, 87>, std::array<volatile char16_t, 87>,  \
    std::array<volatile char32_t, 87>, std::array<volatile short, 87>,  \
    std::array<volatile int, 87>, std::array<volatile long, 87>,  \
    std::array<volatile long long, 87>,  \
    std::array<volatile unsigned short, 87>,  \
    std::array<volatile unsigned int, 87>,  \
    std::array<volatile unsigned long, 87>,  \
    std::array<volatile unsigned long long, 87>,  \
    std::array<volatile float, 87>, std::array<volatile double, 87>,  \
    std::array<volatile long double, 87>, std::array<char, 88>,  \
    std::array<wchar_t, 88>, std::array<char8_t, 88>,  \
    std::array<char16_t, 88>, std::array<char32_t, 88>,  \
    std::array<short, 88>, std::array<int, 88>, std::array<long, 88>,  \
    std::array<long long, 88>, std::array<unsigned short, 88>,  \
    std::array<unsigned int, 88>, std::array<unsigned long, 88>,  \
    std::array<unsigned long long, 88>, std::array<float, 88>,  \
    std::array<double, 88>, std::array<long double, 88>,  \
    std::array<volatile char, 88>, std::array<volatile wchar_t, 88>,  \
    std::array<volatile char8_t, 88>, std::array<volatile char16_t, 88>,  \
    std::array<volatile char32_t, 88>, std::array<volatile short, 88>,  \
    std::array<volatile int, 88>, std::array<volatile long, 88>,  \
    std::array<volatile long long, 88>,  \
    std::array<volatile unsigned short, 88>,  \
    std::array<volatile unsigned int, 88>,  \
    std::array<volatile unsigned long, 88>,  \
    std::array<volatile unsigned long long, 88>,  \
    std::array<volatile float, 88>, std::array<volatile double, 88>,  \
    std::array<volatile long double, 88>, std::array<char, 89>,  \
    std::array<wchar_t, 89>, std::array<char8_t, 89>,  \
    std::array<char16_t, 89>, std::array<char32_t, 89>,  \
    std::array<short, 89>, std::array<int, 89>, std::array<long, 89>,  \
    std::array<long long, 89>, std::array<unsigned short, 89>,  \
    std::array<unsigned int, 89>, std::array<unsigned long, 89>,  \
    std::array<unsigned long long, 89>, std::array<float, 89>,  \
    std::array<double, 89>, std::array<long double, 89>,  \
    std::array<volatile char, 89>, std::array<volatile wchar_t, 89>,  \
    std::array<volatile char8_t, 89>, std::array<volatile char16_t, 89>,  \
    std::array<volatile char32_t, 89>, std::array<volatile short, 89>,  \
    std::array<volatile int, 89>, std::array<volatile long, 89>,  \
    std::array<volatile long long, 89>,  \
    std::array<volatile unsigned short, 89>,  \
    std::array<volatile unsigned int, 89>,  \
    std::array<volatile unsigned long, 89>,  \
    std::array<volatile unsigned long long, 89>,  \
    std::array<volatile float, 89>, std::array<volatile double, 89>,  \
    std::array<volatile long double, 89>, std::array<char, 90>,  \
    std::array<wchar_t, 90>, std::array<char8_t, 90>,  \
    std::array<char16_t, 90>, std::array<char32_t, 90>,  \
    std::array<short, 90>, std::array<int, 90>, std::array<long, 90>,  \
    std::array<long long, 90>, std::array<unsigned short, 90>,  \
    std::array<unsigned int, 90>, std::array<unsigned long, 90>,  \
    std::array<unsigned long long, 90>, std::array<float, 90>,  \
    std::array<double, 90>, std::array<long double, 90>,  \
    std::array<volatile char, 90>, std::array<volatile wchar_t, 90>,  \
    std::array<volatile char8_t, 90>, std::array<volatile char16_t, 90>,  \
    std::array<volatile char32_t, 90>, std::array<volatile short, 90>,  \
    std::array<volatile int, 90>, std::array<volatile long, 90>,  \
    std::array<volatile long long, 90>,  \
    std::array<volatile unsigned short, 90>,  \
    std::array<volatile unsigned int, 90>,  \
    std::array<volatile unsigned long, 90>,  \
    std::array<volatile unsigned long long, 90>,  \
    std::array<volatile float, 90>, std::array<volatile double, 90>,  \
    std::array<volatile long double, 90>, std::array<char, 91>,  \
    std::array<wchar_t, 91>, std::array<char8_t, 91>,  \
    std::array<char16_t, 91>, std::array<char32_t, 91>,  \
    std::array<short, 91>, std::array<int, 91>, std::array<long, 91>,  \
    std::array<long long, 91>, std::array<unsigned short, 91>,  \
    std::array<unsigned int, 91>, std::array<unsigned long, 91>,  \
    std::array<unsigned long long, 91>, std::array<float, 91>,  \
    std::array<double, 91>, std::array<long double, 91>,  \
    std::array<volatile char, 91>, std::array<volatile wchar_t, 91>,  \
    std::array<volatile char8_t, 91>, std::array<volatile char16_t, 91>,  \
    std::array<volatile char32_t, 91>, std::array<volatile short, 91>,  \
    std::array<volatile int, 91>, std::array<volatile long, 91>,  \
    std::array<volatile long long, 91>,  \
    std::array<volatile unsigned short, 91>,  \
    std::array<volatile unsigned int, 91>,  \
    std::array<volatile unsigned long, 91>,  \
    std::array<volatile unsigned long long, 91>,  \
    std::array<volatile float, 91>, std::array<volatile double, 91>,  \
    std::array<volatile long double, 91>, std::array<char, 92>,  \
    std::array<wchar_t, 92>, std::array<char8_t, 92>,  \
    std::array<char16_t, 92>, std::array<char32_t, 92>,  \
    std::array<short, 92>, std::array<int, 92>, std::array<long, 92>,  \
    std::array<long long, 92>, std::array<unsigned short, 92>,  \
    std::array<unsigned int, 92>, std::array<unsigned long, 92>,  \
    std::array<unsigned long long, 92>, std::array<float, 92>,  \
    std::array<double, 92>, std::array<long double, 92>,  \
    std::array<volatile char, 92>, std::array<volatile wchar_t, 92>,  \
    std::array<volatile char8_t, 92>, std::array<volatile char16_t, 92>,  \
    std::array<volatile char32_t, 92>, std::array<volatile short, 92>,  \
    std::array<volatile int, 92>, std::array<volatile long, 92>,  \
    std::array<volatile long long, 92>,  \
    std::array<volatile unsigned short, 92>,  \
    std::array<volatile unsigned int, 92>,  \
    std::array<volatile unsigned long, 92>,  \
    std::array<volatile unsigned long long, 92>,  \
    std::array<volatile float, 92>, std::array<volatile double, 92>,  \
    std::array<volatile long double, 92>, std::array<char, 93>,  \
    std::array<wchar_t, 93>, std::array<char8_t, 93>,  \
    std::array<char16_t, 93>, std::array<char32_t, 93>,  \
    std::array<short, 93>, std::array<int, 93>, std::array<long, 93>,  \
    std::array<long long, 93>, std::array<unsigned short, 93>,  \
    std::array<unsigned int, 93>, std::array<unsigned long, 93>,  \
    std::array<unsigned long long, 93>, std::array<float, 93>,  \
    std::array<double, 93>, std::array<long double, 93>,  \
    std::array<volatile char, 93>, std::array<volatile wchar_t, 93>,  \
    std::array<volatile char8_t, 93>, std::array<volatile char16_t, 93>,  \
    std::array<volatile char32_t, 93>, std::array<volatile short, 93>,  \
    std::array<volatile int, 93>, std::array<volatile long, 93>,  \
    std::array<volatile long long, 93>,  \
    std::array<volatile unsigned short, 93>,  \
    std::array<volatile unsigned int, 93>,  \
    std::array<volatile unsigned long, 93>,  \
    std::array<volatile unsigned long long, 93>,  \
    std::array<volatile float, 93>, std::array<volatile double, 93>,  \
    std::array<volatile long double, 93>, std::array<char, 94>,  \
    std::array<wchar_t, 94>, std::array<char8_t, 94>,  \
    std::array<char16_t, 94>, std::array<char32_t, 94>,  \
    std::array<short, 94>, std::array<int, 94>, std::array<long, 94>,  \
    std::array<long long, 94>, std::array<unsigned short, 94>,  \
    std::array<unsigned int, 94>, std::array<unsigned long, 94>,  \
    std::array<unsigned long long, 94>, std::array<float, 94>,  \
    std::array<double, 94>, std::array<long double, 94>,  \
    std::array<volatile char, 94>, std::array<volatile wchar_t, 94>,  \
    std::array<volatile char8_t, 94>, std::array<volatile char16_t, 94>,  \
    std::array<volatile char32_t, 94>, std::array<volatile short, 94>,  \
    std::array<volatile int, 94>, std::array<volatile long, 94>,  \
    std::array<volatile long long, 94>,  \
    std::array<volatile unsigned short, 94>,  \
    std::array<volatile unsigned int, 94>,  \
    std::array<volatile unsigned long, 94>,  \
    std::array<volatile unsigned long long, 94>,  \
    std::array<volatile float, 94>, std::array<volatile double, 94>,  \
    std::array<volatile long double, 94>, std::array<char, 95>,  \
    std::array<wchar_t, 95>, std::array<char8_t, 95>,  \
    std::array<char16_t, 95>, std::array<char32_t, 95>,  \
    std::array<short, 95>, std::array<int, 95>, std::array<long, 95>,  \
    std::array<long long, 95>, std::array<unsigned short, 95>,  \
    std::array<unsigned int, 95>, std::array<unsigned long, 95>,  \
    std::array<unsigned long long, 95>, std::array<float, 95>,  \
    std::array<double, 95>, std::array<long double, 95>,  \
    std::array<volatile char, 95>, std::array<volatile wchar_t, 95>,  \
    std::array<volatile char8_t, 95>, std::array<volatile char16_t, 95>,  \
    std::array<volatile char32_t, 95>, std::array<volatile short, 95>,  \
    std::array<volatile int, 95>, std::array<volatile long, 95>,  \
    std::array<volatile long long, 95>,  \
    std::array<volatile unsigned short, 95>,  \
    std::array<volatile unsigned int, 95>,  \
    std::array<volatile unsigned long, 95>,  \
    std::array<volatile unsigned long long, 95>,  \
    std::array<volatile float, 95>, std::array<volatile double, 95>,  \
    std::array<volatile long double, 95>, std::array<char, 96>,  \
    std::array<wchar_t, 96>, std::array<char8_t, 96>,  \
    std::array<char16_t, 96>, std::array<char32_t, 96>,  \
    std::array<short, 96>, std::array<int, 96>, std::array<long, 96>,  \
    std::array<long long, 96>, std::array<unsigned short, 96>,  \
    std::array<unsigned int, 96>, std::array<unsigned long, 96>,  \
    std::array<unsigned long long, 96>, std::array<float, 96>,  \
    std::array<double, 96>, std::array<long double, 96>,  \
    std::array<volatile char, 96>, std::array<volatile wchar_t, 96>,  \
    std::array<volatile char8_t, 96>, std::array<volatile char16_t, 96>,  \
    std::array<volatile char32_t, 96>, std::array<volatile short, 96>,  \
    std::array<volatile int, 96>, std::array<volatile long, 96>,  \
    std::array<volatile long long, 96>,  \
    std::array<volatile unsigned short, 96>,  \
    std::array<volatile unsigned int, 96>,  \
    std::array<volatile unsigned long, 96>,  \
    std::array<volatile unsigned long long, 96>,  \
    std::array<volatile float, 96>, std::array<volatile double, 96>,  \
    std::array<volatile long double, 96>, std::array<char, 97>,  \
    std::array<wchar_t, 97>, std::array<char8_t, 97>,  \
    std::array<char16_t, 97>, std::array<char32_t, 97>,  \
    std::array<short, 97>, std::array<int, 97>, std::array<long, 97>,  \
    std::array<long long, 97>, std::array<unsigned short, 97>,  \
    std::array<unsigned int, 97>, std::array<unsigned long, 97>,  \
    std::array<unsigned long long, 97>, std::array<float, 97>,  \
    std::array<double, 97>, std::array<long double, 97>,  \
    std::array<volatile char, 97>, std::array<volatile wchar_t, 97>,  \
    std::array<volatile char8_t, 97>, std::array<volatile char16_t, 97>,  \
    std::array<volatile char32_t, 97>, std::array<volatile short, 97>,  \
    std::array<volatile int, 97>, std::array<volatile long, 97>,  \
    std::array<volatile long long, 97>,  \
    std::array<volatile unsigned short, 97>,  \
    std::array<volatile unsigned int, 97>,  \
    std::array<volatile unsigned long, 97>,  \
    std::array<volatile unsigned long long, 97>,  \
    std::array<volatile float, 97>, std::array<volatile double, 97>,  \
    std::array<volatile long double, 97>, std::array<char, 98>,  \
    std::array<wchar_t, 98>, std::array<char8_t, 98>,  \
    std::array<char16_t, 98>, std::array<char32_t, 98>,  \
    std::array<short, 98>, std::array<int, 98>, std::array<long, 98>,  \
    std::array<long long, 98>, std::array<unsigned short, 98>,  \
    std::array<unsigned int, 98>, std::array<unsigned long, 98>,  \
    std::array<unsigned long long, 98>, std::array<float, 98>,  \
    std::array<double, 98>, std::array<long double, 98>,  \
    std::array<volatile char, 98>, std::array<volatile wchar_t, 98>,  \
    std::array<volatile char8_t, 98>, std::array<volatile char16_t, 98>,  \
    std::array<volatile char32_t, 98>, std::array<volatile short, 98>,  \
    std::array<volatile int, 98>, std::array<volatile long, 98>,  \
    std::array<volatile long long, 98>,  \
    std::array<volatile unsigned short, 98>,  \
    std::array<volatile unsigned int, 98>,  \
    std::array<volatile unsigned long, 98>,  \
    std::array<volatile unsigned long long, 98>,  \
    std::array<volatile float, 98>, std::array<volatile double, 98>,  \
    std::array<volatile long double, 98>, std::array<char, 99>,  \
    std::array<wchar_t, 99>, std::array<char8_t, 99>,  \
    std::array<char16_t, 99>, std::array<char32_t, 99>,  \
    std::array<short, 99>, std::array<int, 99>, std::array<long, 99>,  \
    std::array<long long, 99>, std::array<unsigned short, 99>,  \
    std::array<unsigned int, 99>, std::array<unsigned long, 99>,  \
    std::array<unsigned long long, 99>, std::array<float, 99>,  \
    std::array<double, 99>, std::array<long double, 99>,  \
    std::array<volatile char, 99>, std::array<volatile wchar_t, 99>,  \
    std::array<volatile char8_t, 99>, std::array<volatile char16_t, 99>,  \
    std::array<volatile char32_t, 99>, std::array<volatile short, 99>,  \
    std::array<volatile int, 99>, std::array<volatile long, 99>,  \
    std::array<volatile long long, 99>,  \
    std::array<volatile unsigned short, 99>,  \
    std::array<volatile unsigned int, 99>,  \
    std::array<volatile unsigned long, 99>,  \
    std::array<volatile unsigned long long, 99>,  \
    std::array<volatile float, 99>, std::array<volatile double, 99>,  \
    std::array<volatile long double, 99>, std::array<char, 100>,  \
    std::array<wchar_t, 100>, std::array<char8_t, 100>,  \
    std::array<char16_t, 100>, std::array<char32_t, 100>,  \
    std::array<short, 100>, std::array<int, 100>, std::array<long, 100>,  \
    std::array<long long, 100>, std::array<unsigned short, 100>,  \
    std::array<unsigned int, 100>, std::array<unsigned long, 100>,  \
    std::array<unsigned long long, 100>, std::array<float, 100>,  \
    std::array<double, 100>, std::array<long double, 100>,  \
    std::array<volatile char, 100>, std::array<volatile wchar_t, 100>,  \
    std::array<volatile char8_t, 100>, std::array<volatile char16_t, 100>,  \
    std::array<volatile char32_t, 100>, std::array<volatile short, 100>,  \
    std::array<volatile int, 100>, std::array<volatile long, 100>,  \
    std::array<volatile long long, 100>,  \
    std::array<volatile unsigned short, 100>,  \
    std::array<volatile unsigned int, 100>,  \
    std::array<volatile unsigned long, 100>,  \
    std::array<volatile unsigned long long, 100>,  \
    std::array<volatile float, 100>, std::array<volatile double, 100>,  \
    std::array<volatile long double, 100>, std::map<char, char>,  \
    std::map<char, wchar_t>, std::map<char, char8_t>,  \
    std::map<char, char16_t>, std::map<char, char32_t>,  \
    std::map<char, short>, std::map<char, int>, std::map<char, long>,  \
    std::map<char, long long>, std::map<char, unsigned short>,  \
    std::map<char, unsigned int>, std::map<char, unsigned long>,  \
    std::map<char, unsigned long long>, std::map<char, float>,  \
    std::map<char, double>, std::map<char, long double>,  \
    std::map<char, volatile char>, std::map<char, volatile wchar_t>,  \
    std::map<char, volatile char8_t>, std::map<char, volatile char16_t>,  \
    std::map<char, volatile char32_t>, std::map<char, volatile short>,  \
    std::map<char, volatile int>, std::map<char, volatile long>,  \
    std::map<char, volatile long long>,  \
    std::map<char, volatile unsigned short>,  \
    std::map<char, volatile unsigned int>,  \
    std::map<char, volatile unsigned long>,  \
    std::map<char, volatile unsigned long long>,  \
    std::map<char, volatile float>, std::map<char, volatile double>,  \
    std::map<char, volatile long double>, std::map<wchar_t, char>,  \
    std::map<wchar_t, wchar_t>, std::map<wchar_t, char8_t>,  \
    std::map<wchar_t, char16_t>, std::map<wchar_t, char32_t>,  \
    std::map<wchar_t, short>, std::map<wchar_t, int>,  \
    std::map<wchar_t, long>, std::map<wchar_t, long long>,  \
    std::map<wchar_t, unsigned short>, std::map<wchar_t, unsigned int>,  \
    std::map<wchar_t, unsigned long>, std::map<wchar_t, unsigned long long>,  \
    std::map<wchar_t, float>, std::map<wchar_t, double>,  \
    std::map<wchar_t, long double>, std::map<wchar_t, volatile char>,  \
    std::map<wchar_t, volatile wchar_t>,  \
    std::map<wchar_t, volatile char8_t>,  \
    std::map<wchar_t, volatile char16_t>,  \
    std::map<wchar_t, volatile char32_t>, std::map<wchar_t, volatile short>,  \
    std::map<wchar_t, volatile int>, std::map<wchar_t, volatile long>,  \
    std::map<wchar_t, volatile long long>,  \
    std::map<wchar_t, volatile unsigned short>,  \
    std::map<wchar_t, volatile unsigned int>,  \
    std::map<wchar_t, volatile unsigned long>,  \
    std::map<wchar_t, volatile unsigned long long>,  \
    std::map<wchar_t, volatile float>, std::map<wchar_t, volatile double>,  \
    std::map<wchar_t, volatile long double>, std::map<char8_t, char>,  \
    std::map<char8_t, wchar_t>, std::map<char8_t, char8_t>,  \
    std::map<char8_t, char16_t>, std::map<char8_t, char32_t>,  \
    std::map<char8_t, short>, std::map<char8_t, int>,  \
    std::map<char8_t, long>, std::map<char8_t, long long>,  \
    std::map<char8_t, unsigned short>, std::map<char8_t, unsigned int>,  \
    std::map<char8_t, unsigned long>, std::map<char8_t, unsigned long long>,  \
    std::map<char8_t, float>, std::map<char8_t, double>,  \
    std::map<char8_t, long double>, std::map<char8_t, volatile char>,  \
    std::map<char8_t, volatile wchar_t>,  \
    std::map<char8_t, volatile char8_t>,  \
    std::map<char8_t, volatile char16_t>,  \
    std::map<char8_t, volatile char32_t>, std::map<char8_t, volatile short>,  \
    std::map<char8_t, volatile int>, std::map<char8_t, volatile long>,  \
    std::map<char8_t, volatile long long>,  \
    std::map<char8_t, volatile unsigned short>,  \
    std::map<char8_t, volatile unsigned int>,  \
    std::map<char8_t, volatile unsigned long>,  \
    std::map<char8_t, volatile unsigned long long>,  \
    std::map<char8_t, volatile float>, std::map<char8_t, volatile double>,  \
    std::map<char8_t, volatile long double>, std::map<char16_t, char>,  \
    std::map<char16_t, wchar_t>, std::map<char16_t, char8_t>,  \
    std::map<char16_t, char16_t>, std::map<char16_t, char32_t>,  \
    std::map<char16_t, short>, std::map<char16_t, int>,  \
    std::map<char16_t, long>, std::map<char16_t, long long>,  \
    std::map<char16_t, unsigned short>, std::map<char16_t, unsigned int>,  \
    std::map<char16_t, unsigned long>,  \
    std::map<char16_t, unsigned long long>, std::map<char16_t, float>,  \
    std::map<char16_t, double>, std::map<char16_t, long double>,  \
    std::map<char16_t, volatile char>, std::map<char16_t, volatile wchar_t>,  \
    std::map<char16_t, volatile char8_t>,  \
    std::map<char16_t, volatile char16_t>,  \
    std::map<char16_t, volatile char32_t>,  \
    std::map<char16_t, volatile short>, std::map<char16_t, volatile int>,  \
    std::map<char16_t, volatile long>,  \
    std::map<char16_t, volatile long long>,  \
    std::map<char16_t, volatile unsigned short>,  \
    std::map<char16_t, volatile unsigned int>,  \
    std::map<char16_t, volatile unsigned long>,  \
    std::map<char16_t, volatile unsigned long long>,  \
    std::map<char16_t, volatile float>, std::map<char16_t, volatile double>,  \
    std::map<char16_t, volatile long double>, std::map<char32_t, char>,  \
    std::map<char32_t, wchar_t>, std::map<char32_t, char8_t>,  \
    std::map<char32_t, char16_t>, std::map<char32_t, char32_t>,  \
    std::map<char32_t, short>, std::map<char32_t, int>,  \
    std::map<char32_t, long>, std::map<char32_t, long long>,  \
    std::map<char32_t, unsigned short>, std::map<char32_t, unsigned int>,  \
    std::map<char32_t, unsigned long>,  \
    std::map<char32_t, unsigned long long>, std::map<char32_t, float>,  \
    std::map<char32_t, double>, std::map<char32_t, long double>,  \
    std::map<char32_t, volatile char>, std::map<char32_t, volatile wchar_t>,  \
    std::map<char32_t, volatile char8_t>,  \
    std::map<char32_t, volatile char16_t>,  \
    std::map<char32_t, volatile char32_t>,  \
    std::map<char32_t, volatile short>, std::map<char32_t, volatile int>,  \
    std::map<char32_t, volatile long>,  \
    std::map<char32_t, volatile long long>,  \
    std::map<char32_t, volatile unsigned short>,  \
    std::map<char32_t, volatile unsigned int>,  \
    std::map<char32_t, volatile unsigned long>,  \
    std::map<char32_t, volatile unsigned long long>,  \
    std::map<char32_t, volatile float>, std::map<char32_t, volatile double>,  \
    std::map<char32_t, volatile long double>, std::map<short, char>,  \
    std::map<short, wchar_t>, std::map<short, char8_t>,  \
    std::map<short, char16_t>, std::map<short, char32_t>,  \
    std::map<short, short>, std::map<short, int>, std::map<short, long>,  \
    std::map<short, long long>, std::map<short, unsigned short>,  \
    std::map<short, unsigned int>, std::map<short, unsigned long>,  \
    std::map<short, unsigned long long>, std::map<short, float>,  \
    std::map<short, double>, std::map<short, long double>,  \
    std::map<short, volatile char>, std::map<short, volatile wchar_t>,  \
    std::map<short, volatile char8_t>, std::map<short, volatile char16_t>,  \
    std::map<short, volatile char32_t>, std::map<short, volatile short>,  \
    std::map<short, volatile int>, std::map<short, volatile long>,  \
    std::map<short, volatile long long>,  \
    std::map<short, volatile unsigned short>,  \
    std::map<short, volatile unsigned int>,  \
    std::map<short, volatile unsigned long>,  \
    std::map<short, volatile unsigned long long>,  \
    std::map<short, volatile float>, std::map<short, volatile double>,  \
    std::map<short, volatile long double>, std::map<int, char>,  \
    std::map<int, wchar_t>, std::map<int, char8_t>, std::map<int, char16_t>,  \
    std::map<int, char32_t>, std::map<int, short>, std::map<int, int>,  \
    std::map<int, long>, std::map<int, long long>,  \
    std::map<int, unsigned short>, std::map<int, unsigned int>,  \
    std::map<int, unsigned long>, std::map<int, unsigned long long>,  \
    std::map<int, float>, std::map<int, double>, std::map<int, long double>,  \
    std::map<int, volatile char>, std::map<int, volatile wchar_t>,  \
    std::map<int, volatile char8_t>, std::map<int, volatile char16_t>,  \
    std::map<int, volatile char32_t>, std::map<int, volatile short>,  \
    std::map<int, volatile int>, std::map<int, volatile long>,  \
    std::map<int, volatile long long>,  \
    std::map<int, volatile unsigned short>,  \
    std::map<int, volatile unsigned int>,  \
    std::map<int, volatile unsigned long>,  \
    std::map<int, volatile unsigned long long>,  \
    std::map<int, volatile float>, std::map<int, volatile double>,  \
    std::map<int, volatile long double>, std::map<long, char>,  \
    std::map<long, wchar_t>, std::map<long, char8_t>,  \
    std::map<long, char16_t>, std::map<long, char32_t>,  \
    std::map<long, short>, std::map<long, int>, std::map<long, long>,  \
    std::map<long, long long>, std::map<long, unsigned short>,  \
    std::map<long, unsigned int>, std::map<long, unsigned long>,  \
    std::map<long, unsigned long long>, std::map<long, float>,  \
    std::map<long, double>, std::map<long, long double>,  \
    std::map<long, volatile char>, std::map<long, volatile wchar_t>,  \
    std::map<long, volatile char8_t>, std::map<long, volatile char16_t>,  \
    std::map<long, volatile char32_t>, std::map<long, volatile short>,  \
    std::map<long, volatile int>, std::map<long, volatile long>,  \
    std::map<long, volatile long long>,  \
    std::map<long, volatile unsigned short>,  \
    std::map<long, volatile unsigned int>,  \
    std::map<long, volatile unsigned long>,  \
    std::map<long, volatile unsigned long long>,  \
    std::map<long, volatile float>, std::map<long, volatile double>,  \
    std::map<long, volatile long double>, std::map<long long, char>,  \
    std::map<long long, wchar_t>, std::map<long long, char8_t>,  \
    std::map<long long, char16_t>, std::map<long long, char32_t>,  \
    std::map<long long, short>, std::map<long long, int>,  \
    std::map<long long, long>, std::map<long long, long long>,  \
    std::map<long long, unsigned short>, std::map<long long, unsigned int>,  \
    std::map<long long, unsigned long>,  \
    std::map<long long, unsigned long long>, std::map<long long, float>,  \
    std::map<long long, double>, std::map<long long, long double>,  \
    std::map<long long, volatile char>,  \
    std::map<long long, volatile wchar_t>,  \
    std::map<long long, volatile char8_t>,  \
    std::map<long long, volatile char16_t>,  \
    std::map<long long, volatile char32_t>,  \
    std::map<long long, volatile short>, std::map<long long, volatile int>,  \
    std::map<long long, volatile long>,  \
    std::map<long long, volatile long long>,  \
    std::map<long long, volatile unsigned short>,  \
    std::map<long long, volatile unsigned int>,  \
    std::map<long long, volatile unsigned long>,  \
    std::map<long long, volatile unsigned long long>,  \
    std::map<long long, volatile float>,  \
    std::map<long long, volatile double>,  \
    std::map<long long, volatile long double>,  \
    std::map<unsigned short, char>, std::map<unsigned short, wchar_t>,  \
    std::map<unsigned short, char8_t>, std::map<unsigned short, char16_t>,  \
    std::map<unsigned short, char32_t>, std::map<unsigned short, short>,  \
    std::map<unsigned short, int>, std::map<unsigned short, long>,  \
    std::map<unsigned short, long long>,  \
    std::map<unsigned short, unsigned short>,  \
    std::map<unsigned short, unsigned int>,  \
    std::map<unsigned short, unsigned long>,  \
    std::map<unsigned short, unsigned long long>,  \
    std::map<unsigned short, float>, std::map<unsigned short, double>,  \
    std::map<unsigned short, long double>,  \
    std::map<unsigned short, volatile char>,  \
    std::map<unsigned short, volatile wchar_t>,  \
    std::map<unsigned short, volatile char8_t>,  \
    std::map<unsigned short, volatile char16_t>,  \
    std::map<unsigned short, volatile char32_t>,  \
    std::map<unsigned short, volatile short>,  \
    std::map<unsigned short, volatile int>,  \
    std::map<unsigned short, volatile long>,  \
    std::map<unsigned short, volatile long long>,  \
    std::map<unsigned short, volatile unsigned short>,  \
    std::map<unsigned short, volatile unsigned int>,  \
    std::map<unsigned short, volatile unsigned long>,  \
    std::map<unsigned short, volatile unsigned long long>,  \
    std::map<unsigned short, volatile float>,  \
    std::map<unsigned short, volatile double>,  \
    std::map<unsigned short, volatile long double>,  \
    std::map<unsigned int, char>, std::map<unsigned int, wchar_t>,  \
    std::map<unsigned int, char8_t>, std::map<unsigned int, char16_t>,  \
    std::map<unsigned int, char32_t>, std::map<unsigned int, short>,  \
    std::map<unsigned int, int>, std::map<unsigned int, long>,  \
    std::map<unsigned int, long long>,  \
    std::map<unsigned int, unsigned short>,  \
    std::map<unsigned int, unsigned int>,  \
    std::map<unsigned int, unsigned long>,  \
    std::map<unsigned int, unsigned long long>,  \
    std::map<unsigned int, float>, std::map<unsigned int, double>,  \
    std::map<unsigned int, long double>,  \
    std::map<unsigned int, volatile char>,  \
    std::map<unsigned int, volatile wchar_t>,  \
    std::map<unsigned int, volatile char8_t>,  \
    std::map<unsigned int, volatile char16_t>,  \
    std::map<unsigned int, volatile char32_t>,  \
    std::map<unsigned int, volatile short>,  \
    std::map<unsigned int, volatile int>,  \
    std::map<unsigned int, volatile long>,  \
    std::map<unsigned int, volatile long long>,  \
    std::map<unsigned int, volatile unsigned short>,  \
    std::map<unsigned int, volatile unsigned int>,  \
    std::map<unsigned int, volatile unsigned long>,  \
    std::map<unsigned int, volatile unsigned long long>,  \
    std::map<unsigned int, volatile float>,  \
    std::map<unsigned int, volatile double>,  \
    std::map<unsigned int, volatile long double>,  \
    std::map<unsigned long, char>, std::map<unsigned long, wchar_t>,  \
    std::map<unsigned long, char8_t>, std::map<unsigned long, char16_t>,  \
    std::map<unsigned long, char32_t>, std::map<unsigned long, short>,  \
    std::map<unsigned long, int>, std::map<unsigned long, long>,  \
    std::map<unsigned long, long long>,  \
    std::map<unsigned long, unsigned short>,  \
    std::map<unsigned long, unsigned int>,  \
    std::map<unsigned long, unsigned long>,  \
    std::map<unsigned long, unsigned long long>,  \
    std::map<unsigned long, float>, std::map<unsigned long, double>,  \
    std::map<unsigned long, long double>,  \
    std::map<unsigned long, volatile char>,  \
    std::map<unsigned long, volatile wchar_t>,  \
    std::map<unsigned long, volatile char8_t>,  \
    std::map<unsigned long, volatile char16_t>,  \
    std::map<unsigned long, volatile char32_t>,  \
    std::map<unsigned long, volatile short>,  \
    std::map<unsigned long, volatile int>,  \
    std::map<unsigned long, volatile long>,  \
    std::map<unsigned long, volatile long long>,  \
    std::map<unsigned long, volatile unsigned short>,  \
    std::map<unsigned long, volatile unsigned int>,  \
    std::map<unsigned long, volatile unsigned long>,  \
    std::map<unsigned long, volatile unsigned long long>,  \
    std::map<unsigned long, volatile float>,  \
    std::map<unsigned long, volatile double>,  \
    std::map<unsigned long, volatile long double>,  \
    std::map<unsigned long long, char>,  \
    std::map<unsigned long long, wchar_t>,  \
    std::map<unsigned long long, char8_t>,  \
    std::map<unsigned long long, char16_t>,  \
    std::map<unsigned long long, char32_t>,  \
    std::map<unsigned long long, short>, std::map<unsigned long long, int>,  \
    std::map<unsigned long long, long>,  \
    std::map<unsigned long long, long long>,  \
    std::map<unsigned long long, unsigned short>,  \
    std::map<unsigned long long, unsigned int>,  \
    std::map<unsigned long long, unsigned long>,  \
    std::map<unsigned long long, unsigned long long>,  \
    std::map<unsigned long long, float>,  \
    std::map<unsigned long long, double>,  \
    std::map<unsigned long long, long double>,  \
    std::map<unsigned long long, volatile char>,  \
    std::map<unsigned long long, volatile wchar_t>,  \
    std::map<unsigned long long, volatile char8_t>,  \
    std::map<unsigned long long, volatile char16_t>,  \
    std::map<unsigned long long, volatile char32_t>,  \
    std::map<unsigned long long, volatile short>,  \
    std::map<unsigned long long, volatile int>,  \
    std::map<unsigned long long, volatile long>,  \
    std::map<unsigned long long, volatile long long>,  \
    std::map<unsigned long long, volatile unsigned short>,  \
    std::map<unsigned long long, volatile unsigned int>,  \
    std::map<unsigned long long, volatile unsigned long>,  \
    std::map<unsigned long long, volatile unsigned long long>,  \
    std::map<unsigned long long, volatile float>,  \
    std::map<unsigned long long, volatile double>,  \
    std::map<unsigned long long, volatile long double>,  \
    std::map<float, char>, std::map<float, wchar_t>,  \
    std::map<float, char8_t>, std::map<float, char16_t>,  \
    std::map<float, char32_t>, std::map<float, short>, std::map<float, int>,  \
    std::map<float, long>, std::map<float, long long>,  \
    std::map<float, unsigned short>, std::map<float, unsigned int>,  \
    std::map<float, unsigned long>, std::map<float, unsigned long long>,  \
    std::map<float, float>, std::map<float, double>,  \
    std::map<float, long double>, std::map<float, volatile char>,  \
    std::map<float, volatile wchar_t>, std::map<float, volatile char8_t>,  \
    std::map<float, volatile char16_t>, std::map<float, volatile char32_t>,  \
    std::map<float, volatile short>, std::map<float, volatile int>,  \
    std::map<float, volatile long>, std::map<float, volatile long long>,  \
    std::map<float, volatile unsigned short>,  \
    std::map<float, volatile unsigned int>,  \
    std::map<float, volatile unsigned long>,  \
    std::map<float, volatile unsigned long long>,  \
    std::map<float, volatile float>, std::map<float, volatile double>,  \
    std::map<float, volatile long double>, std::map<double, char>,  \
    std::map<double, wchar_t>, std::map<double, char8_t>,  \
    std::map<double, char16_t>, std::map<double, char32_t>,  \
    std::map<double, short>, std::map<double, int>, std::map<double, long>,  \
    std::map<double, long long>, std::map<double, unsigned short>,  \
    std::map<double, unsigned int>, std::map<double, unsigned long>,  \
    std::map<double, unsigned long long>, std::map<double, float>,  \
    std::map<double, double>, std::map<double, long double>,  \
    std::map<double, volatile char>, std::map<double, volatile wchar_t>,  \
    std::map<double, volatile char8_t>, std::map<double, volatile char16_t>,  \
    std::map<double, volatile char32_t>, std::map<double, volatile short>,  \
    std::map<double, volatile int>, std::map<double, volatile long>,  \
    std::map<double, volatile long long>,  \
    std::map<double, volatile unsigned short>,  \
    std::map<double, volatile unsigned int>,  \
    std::map<double, volatile unsigned long>,  \
    std::map<double, volatile unsigned long long>,  \
    std::map<double, volatile float>, std::map<double, volatile double>,  \
    std::map<double, volatile long double>, std::map<long double, char>,  \
    std::map<long double, wchar_t>, std::map<long double, char8_t>,  \
    std::map<long double, char16_t>, std::map<long double, char32_t>,  \
    std::map<long double, short>, std::map<long double, int>,  \
    std::map<long double, long>, std::map<long double, long long>,  \
    std::map<long double, unsigned short>,  \
    std::map<long double, unsigned int>,  \
    std::map<long double, unsigned long>,  \
    std::map<long double, unsigned long long>, std::map<long double, float>,  \
    std::map<long double, double>, std::map<long double, long double>,  \
    std::map<long double, volatile char>,  \
    std::map<long double, volatile wchar_t>,  \
    std::map<long double, volatile char8_t>,  \
    std::map<long double, volatile char16_t>,  \
    std::map<long double, volatile char32_t>,  \
    std::map<long double, volatile short>,  \
    std::map<long double, volatile int>,  \
    std::map<long double, volatile long>,  \
    std::map<long double, volatile long long>,  \
    std::map<long double, volatile unsigned short>,  \
    std::map<long double, volatile unsigned int>,  \
    std::map<long double, volatile unsigned long>,  \
    std::map<long double, volatile unsigned long long>,  \
    std::map<long double, volatile float>,  \
    std::map<long double, volatile double>,  \
    std::map<long double, volatile long double>,  \
    std::map<volatile char, char>, std::map<volatile char, wchar_t>,  \
    std::map<volatile char, char8_t>, std::map<volatile char, char16_t>,  \
    std::map<volatile char, char32_t>, std::map<volatile char, short>,  \
    std::map<volatile char, int>, std::map<volatile char, long>,  \
    std::map<volatile char, long long>,  \
    std::map<volatile char, unsigned short>,  \
    std::map<volatile char, unsigned int>,  \
    std::map<volatile char, unsigned long>,  \
    std::map<volatile char, unsigned long long>,  \
    std::map<volatile char, float>, std::map<volatile char, double>,  \
    std::map<volatile char, long double>,  \
    std::map<volatile char, volatile char>,  \
    std::map<volatile char, volatile wchar_t>,  \
    std::map<volatile char, volatile char8_t>,  \
    std::map<volatile char, volatile char16_t>,  \
    std::map<volatile char, volatile char32_t>,  \
    std::map<volatile char, volatile short>,  \
    std::map<volatile char, volatile int>,  \
    std::map<volatile char, volatile long>,  \
    std::map<volatile char, volatile long long>,  \
    std::map<volatile char, volatile unsigned short>,  \
    std::map<volatile char, volatile unsigned int>,  \
    std::map<volatile char, volatile unsigned long>,  \
    std::map<volatile char, volatile unsigned long long>,  \
    std::map<volatile char, volatile float>,  \
    std::map<volatile char, volatile double>,  \
    std::map<volatile char, volatile long double>,  \
    std::map<volatile wchar_t, char>, std::map<volatile wchar_t, wchar_t>,  \
    std::map<volatile wchar_t, char8_t>,  \
    std::map<volatile wchar_t, char16_t>,  \
    std::map<volatile wchar_t, char32_t>, std::map<volatile wchar_t, short>,  \
    std::map<volatile wchar_t, int>, std::map<volatile wchar_t, long>,  \
    std::map<volatile wchar_t, long long>,  \
    std::map<volatile wchar_t, unsigned short>,  \
    std::map<volatile wchar_t, unsigned int>,  \
    std::map<volatile wchar_t, unsigned long>,  \
    std::map<volatile wchar_t, unsigned long long>,  \
    std::map<volatile wchar_t, float>, std::map<volatile wchar_t, double>,  \
    std::map<volatile wchar_t, long double>,  \
    std::map<volatile wchar_t, volatile char>,  \
    std::map<volatile wchar_t, volatile wchar_t>,  \
    std::map<volatile wchar_t, volatile char8_t>,  \
    std::map<volatile wchar_t, volatile char16_t>,  \
    std::map<volatile wchar_t, volatile char32_t>,  \
    std::map<volatile wchar_t, volatile short>,  \
    std::map<volatile wchar_t, volatile int>,  \
    std::map<volatile wchar_t, volatile long>,  \
    std::map<volatile wchar_t, volatile long long>,  \
    std::map<volatile wchar_t, volatile unsigned short>,  \
    std::map<volatile wchar_t, volatile unsigned int>,  \
    std::map<volatile wchar_t, volatile unsigned long>,  \
    std::map<volatile wchar_t, volatile unsigned long long>,  \
    std::map<volatile wchar_t, volatile float>,  \
    std::map<volatile wchar_t, volatile double>,  \
    std::map<volatile wchar_t, volatile long double>,  \
    std::map<volatile char8_t, char>, std::map<volatile char8_t, wchar_t>,  \
    std::map<volatile char8_t, char8_t>,  \
    std::map<volatile char8_t, char16_t>,  \
    std::map<volatile char8_t, char32_t>, std::map<volatile char8_t, short>,  \
    std::map<volatile char8_t, int>, std::map<volatile char8_t, long>,  \
    std::map<volatile char8_t, long long>,  \
    std::map<volatile char8_t, unsigned short>,  \
    std::map<volatile char8_t, unsigned int>,  \
    std::map<volatile char8_t, unsigned long>,  \
    std::map<volatile char8_t, unsigned long long>,  \
    std::map<volatile char8_t, float>, std::map<volatile char8_t, double>,  \
    std::map<volatile char8_t, long double>,  \
    std::map<volatile char8_t, volatile char>,  \
    std::map<volatile char8_t, volatile wchar_t>,  \
    std::map<volatile char8_t, volatile char8_t>,  \
    std::map<volatile char8_t, volatile char16_t>,  \
    std::map<volatile char8_t, volatile char32_t>,  \
    std::map<volatile char8_t, volatile short>,  \
    std::map<volatile char8_t, volatile int>,  \
    std::map<volatile char8_t, volatile long>,  \
    std::map<volatile char8_t, volatile long long>,  \
    std::map<volatile char8_t, volatile unsigned short>,  \
    std::map<volatile char8_t, volatile unsigned int>,  \
    std::map<volatile char8_t, volatile unsigned long>,  \
    std::map<volatile char8_t, volatile unsigned long long>,  \
    std::map<volatile char8_t, volatile float>,  \
    std::map<volatile char8_t, volatile double>,  \
    std::map<volatile char8_t, volatile long double>,  \
    std::map<volatile char16_t, char>, std::map<volatile char16_t, wchar_t>,  \
    std::map<volatile char16_t, char8_t>,  \
    std::map<volatile char16_t, char16_t>,  \
    std::map<volatile char16_t, char32_t>,  \
    std::map<volatile char16_t, short>, std::map<volatile char16_t, int>,  \
    std::map<volatile char16_t, long>,  \
    std::map<volatile char16_t, long long>,  \
    std::map<volatile char16_t, unsigned short>,  \
    std::map<volatile char16_t, unsigned int>,  \
    std::map<volatile char16_t, unsigned long>,  \
    std::map<volatile char16_t, unsigned long long>,  \
    std::map<volatile char16_t, float>, std::map<volatile char16_t, double>,  \
    std::map<volatile char16_t, long double>,  \
    std::map<volatile char16_t, volatile char>,  \
    std::map<volatile char16_t, volatile wchar_t>,  \
    std::map<volatile char16_t, volatile char8_t>,  \
    std::map<volatile char16_t, volatile char16_t>,  \
    std::map<volatile char16_t, volatile char32_t>,  \
    std::map<volatile char16_t, volatile short>,  \
    std::map<volatile char16_t, volatile int>,  \
    std::map<volatile char16_t, volatile long>,  \
    std::map<volatile char16_t, volatile long long>,  \
    std::map<volatile char16_t, volatile unsigned short>,  \
    std::map<volatile char16_t, volatile unsigned int>,  \
    std::map<volatile char16_t, volatile unsigned long>,  \
    std::map<volatile char16_t, volatile unsigned long long>,  \
    std::map<volatile char16_t, volatile float>,  \
    std::map<volatile char16_t, volatile double>,  \
    std::map<volatile char16_t, volatile long double>,  \
    std::map<volatile char32_t, char>, std::map<volatile char32_t, wchar_t>,  \
    std::map<volatile char32_t, char8_t>,  \
    std::map<volatile char32_t, char16_t>,  \
    std::map<volatile char32_t, char32_t>,  \
    std::map<volatile char32_t, short>, std::map<volatile char32_t, int>,  \
    std::map<volatile char32_t, long>,  \
    std::map<volatile char32_t, long long>,  \
    std::map<volatile char32_t, unsigned short>,  \
    std::map<volatile char32_t, unsigned int>,  \
    std::map<volatile char32_t, unsigned long>,  \
    std::map<volatile char32_t, unsigned long long>,  \
    std::map<volatile char32_t, float>, std::map<volatile char32_t, double>,  \
    std::map<volatile char32_t, long double>,  \
    std::map<volatile char32_t, volatile char>,  \
    std::map<volatile char32_t, volatile wchar_t>,  \
    std::map<volatile char32_t, volatile char8_t>,  \
    std::map<volatile char32_t, volatile char16_t>,  \
    std::map<volatile char32_t, volatile char32_t>,  \
    std::map<volatile char32_t, volatile short>,  \
    std::map<volatile char32_t, volatile int>,  \
    std::map<volatile char32_t, volatile long>,  \
    std::map<volatile char32_t, volatile long long>,  \
    std::map<volatile char32_t, volatile unsigned short>,  \
    std::map<volatile char32_t, volatile unsigned int>,  \
    std::map<volatile char32_t, volatile unsigned long>,  \
    std::map<volatile char32_t, volatile unsigned long long>,  \
    std::map<volatile char32_t, volatile float>,  \
    std::map<volatile char32_t, volatile double>,  \
    std::map<volatile char32_t, volatile long double>,  \
    std::map<volatile short, char>, std::map<volatile short, wchar_t>,  \
    std::map<volatile short, char8_t>, std::map<volatile short, char16_t>,  \
    std::map<volatile short, char32_t>, std::map<volatile short, short>,  \
    std::map<volatile short, int>, std::map<volatile short, long>,  \
    std::map<volatile short, long long>,  \
    std::map<volatile short, unsigned short>,  \
    std::map<volatile short, unsigned int>,  \
    std::map<volatile short, unsigned long>,  \
    std::map<volatile short, unsigned long long>,  \
    std::map<volatile short, float>, std::map<volatile short, double>,  \
    std::map<volatile short, long double>,  \
    std::map<volatile short, volatile char>,  \
    std::map<volatile short, volatile wchar_t>,  \
    std::map<volatile short, volatile char8_t>,  \
    std::map<volatile short, volatile char16_t>,  \
    std::map<volatile short, volatile char32_t>,  \
    std::map<volatile short, volatile short>,  \
    std::map<volatile short, volatile int>,  \
    std::map<volatile short, volatile long>,  \
    std::map<volatile short, volatile long long>,  \
    std::map<volatile short, volatile unsigned short>,  \
    std::map<volatile short, volatile unsigned int>,  \
    std::map<volatile short, volatile unsigned long>,  \
    std::map<volatile short, volatile unsigned long long>,  \
    std::map<volatile short, volatile float>,  \
    std::map<volatile short, volatile double>,  \
    std::map<volatile short, volatile long double>,  \
    std::map<volatile int, char>, std::map<volatile int, wchar_t>,  \
    std::map<volatile int, char8_t>, std::map<volatile int, char16_t>,  \
    std::map<volatile int, char32_t>, std::map<volatile int, short>,  \
    std::map<volatile int, int>, std::map<volatile int, long>,  \
    std::map<volatile int, long long>,  \
    std::map<volatile int, unsigned short>,  \
    std::map<volatile int, unsigned int>,  \
    std::map<volatile int, unsigned long>,  \
    std::map<volatile int, unsigned long long>,  \
    std::map<volatile int, float>, std::map<volatile int, double>,  \
    std::map<volatile int, long double>,  \
    std::map<volatile int, volatile char>,  \
    std::map<volatile int, volatile wchar_t>,  \
    std::map<volatile int, volatile char8_t>,  \
    std::map<volatile int, volatile char16_t>,  \
    std::map<volatile int, volatile char32_t>,  \
    std::map<volatile int, volatile short>,  \
    std::map<volatile int, volatile int>,  \
    std::map<volatile int, volatile long>,  \
    std::map<volatile int, volatile long long>,  \
    std::map<volatile int, volatile unsigned short>,  \
    std::map<volatile int, volatile unsigned int>,  \
    std::map<volatile int, volatile unsigned long>,  \
    std::map<volatile int, volatile unsigned long long>,  \
    std::map<volatile int, volatile float>,  \
    std::map<volatile int, volatile double>,  \
    std::map<volatile int, volatile long double>,  \
    std::map<volatile long, char>, std::map<volatile long, wchar_t>,  \
    std::map<volatile long, char8_t>, std::map<volatile long, char16_t>,  \
    std::map<volatile long, char32_t>, std::map<volatile long, short>,  \
    std::map<volatile long, int>, std::map<volatile long, long>,  \
    std::map<volatile long, long long>,  \
    std::map<volatile long, unsigned short>,  \
    std::map<volatile long, unsigned int>,  \
    std::map<volatile long, unsigned long>,  \
    std::map<volatile long, unsigned long long>,  \
    std::map<volatile long, float>, std::map<volatile long, double>,  \
    std::map<volatile long, long double>,  \
    std::map<volatile long, volatile char>,  \
    std::map<volatile long, volatile wchar_t>,  \
    std::map<volatile long, volatile char8_t>,  \
    std::map<volatile long, volatile char16_t>,  \
    std::map<volatile long, volatile char32_t>,  \
    std::map<volatile long, volatile short>,  \
    std::map<volatile long, volatile int>,  \
    std::map<volatile long, volatile long>,  \
    std::map<volatile long, volatile long long>,  \
    std::map<volatile long, volatile unsigned short>,  \
    std::map<volatile long, volatile unsigned int>,  \
    std::map<volatile long, volatile unsigned long>,  \
    std::map<volatile long, volatile unsigned long long>,  \
    std::map<volatile long, volatile float>,  \
    std::map<volatile long, volatile double>,  \
    std::map<volatile long, volatile long double>,  \
    std::map<volatile long long, char>,  \
    std::map<volatile long long, wchar_t>,  \
    std::map<volatile long long, char8_t>,  \
    std::map<volatile long long, char16_t>,  \
    std::map<volatile long long, char32_t>,  \
    std::map<volatile long long, short>, std::map<volatile long long, int>,  \
    std::map<volatile long long, long>,  \
    std::map<volatile long long, long long>,  \
    std::map<volatile long long, unsigned short>,  \
    std::map<volatile long long, unsigned int>,  \
    std::map<volatile long long, unsigned long>,  \
    std::map<volatile long long, unsigned long long>,  \
    std::map<volatile long long, float>,  \
    std::map<volatile long long, double>,  \
    std::map<volatile long long, long double>,  \
    std::map<volatile long long, volatile char>,  \
    std::map<volatile long long, volatile wchar_t>,  \
    std::map<volatile long long, volatile char8_t>,  \
    std::map<volatile long long, volatile char16_t>,  \
    std::map<volatile long long, volatile char32_t>,  \
    std::map<volatile long long, volatile short>,  \
    std::map<volatile long long, volatile int>,  \
    std::map<volatile long long, volatile long>,  \
    std::map<volatile long long, volatile long long>,  \
    std::map<volatile long long, volatile unsigned short>,  \
    std::map<volatile long long, volatile unsigned int>,  \
    std::map<volatile long long, volatile unsigned long>,  \
    std::map<volatile long long, volatile unsigned long long>,  \
    std::map<volatile long long, volatile float>,  \
    std::map<volatile long long, volatile double>,  \
    std::map<volatile long long, volatile long double>,  \
    std::map<volatile unsigned short, char>,  \
    std::map<volatile unsigned short, wchar_t>,  \
    std::map<volatile unsigned short, char8_t>,  \
    std::map<volatile unsigned short, char16_t>,  \
    std::map<volatile unsigned short, char32_t>,  \
    std::map<volatile unsigned short, short>,  \
    std::map<volatile unsigned short, int>,  \
    std::map<volatile unsigned short, long>,  \
    std::map<volatile unsigned short, long long>,  \
    std::map<volatile unsigned short, unsigned short>,  \
    std::map<volatile unsigned short, unsigned int>,  \
    std::map<volatile unsigned short, unsigned long>,  \
    std::map<volatile unsigned short, unsigned long long>,  \
    std::map<volatile unsigned short, float>,  \
    std::map<volatile unsigned short, double>,  \
    std::map<volatile unsigned short, long double>,  \
    std::map<volatile unsigned short, volatile char>,  \
    std::map<volatile unsigned short, volatile wchar_t>,  \
    std::map<volatile unsigned short, volatile char8_t>,  \
    std::map<volatile unsigned short, volatile char16_t>,  \
    std::map<volatile unsigned short, volatile char32_t>,  \
    std::map<volatile unsigned short, volatile short>,  \
    std::map<volatile unsigned short, volatile int>,  \
    std::map<volatile unsigned short, volatile long>,  \
    std::map<volatile unsigned short, volatile long long>,  \
    std::map<volatile unsigned short, volatile unsigned short>,  \
    std::map<volatile unsigned short, volatile unsigned int>,  \
    std::map<volatile unsigned short, volatile unsigned long>,  \
    std::map<volatile unsigned short, volatile unsigned long long>,  \
    std::map<volatile unsigned short, volatile float>,  \
    std::map<volatile unsigned short, volatile double>,  \
    std::map<volatile unsigned short, volatile long double>,  \
    std::map<volatile unsigned int, char>,  \
    std::map<volatile unsigned int, wchar_t>,  \
    std::map<volatile unsigned int, char8_t>,  \
    std::map<volatile unsigned int, char16_t>,  \
    std::map<volatile unsigned int, char32_t>,  \
    std::map<volatile unsigned int, short>,  \
    std::map<volatile unsigned int, int>,  \
    std::map<volatile unsigned int, long>,  \
    std::map<volatile unsigned int, long long>,  \
    std::map<volatile unsigned int, unsigned short>,  \
    std::map<volatile unsigned int, unsigned int>,  \
    std::map<volatile unsigned int, unsigned long>,  \
    std::map<volatile unsigned int, unsigned long long>,  \
    std::map<volatile unsigned int, float>,  \
    std::map<volatile unsigned int, double>,  \
    std::map<volatile unsigned int, long double>,  \
    std::map<volatile unsigned int, volatile char>,  \
    std::map<volatile unsigned int, volatile wchar_t>,  \
    std::map<volatile unsigned int, volatile char8_t>,  \
    std::map<volatile unsigned int, volatile char16_t>,  \
    std::map<volatile unsigned int, volatile char32_t>,  \
    std::map<volatile unsigned int, volatile short>,  \
    std::map<volatile unsigned int, volatile int>,  \
    std::map<volatile unsigned int, volatile long>,  \
    std::map<volatile unsigned int, volatile long long>,  \
    std::map<volatile unsigned int, volatile unsigned short>,  \
    std::map<volatile unsigned int, volatile unsigned int>,  \
    std::map<volatile unsigned int, volatile unsigned long>,  \
    std::map<volatile unsigned int, volatile unsigned long long>,  \
    std::map<volatile unsigned int, volatile float>,  \
    std::map<volatile unsigned int, volatile double>,  \
    std::map<volatile unsigned int, volatile long double>,  \
    std::map<volatile unsigned long, char>,  \
    std::map<volatile unsigned long, wchar_t>,  \
    std::map<volatile unsigned long, char8_t>,  \
    std::map<volatile unsigned long, char16_t>,  \
    std::map<volatile unsigned long, char32_t>,  \
    std::map<volatile unsigned long, short>,  \
    std::map<volatile unsigned long, int>,  \
    std::map<volatile unsigned long, long>,  \
    std::map<volatile unsigned long, long long>,  \
    std::map<volatile unsigned long, unsigned short>,  \
    std::map<volatile unsigned long, unsigned int>,  \
    std::map<volatile unsigned long, unsigned long>,  \
    std::map<volatile unsigned long, unsigned long long>,  \
    std::map<volatile unsigned long, float>,  \
    std::map<volatile unsigned long, double>,  \
    std::map<volatile unsigned long, long double>,  \
    std::map<volatile unsigned long, volatile char>,  \
    std::map<volatile unsigned long, volatile wchar_t>,  \
    std::map<volatile unsigned long, volatile char8_t>,  \
    std::map<volatile unsigned long, volatile char16_t>,  \
    std::map<volatile unsigned long, volatile char32_t>,  \
    std::map<volatile unsigned long, volatile short>,  \
    std::map<volatile unsigned long, volatile int>,  \
    std::map<volatile unsigned long, volatile long>,  \
    std::map<volatile unsigned long, volatile long long>,  \
    std::map<volatile unsigned long, volatile unsigned short>,  \
    std::map<volatile unsigned long, volatile unsigned int>,  \
    std::map<volatile unsigned long, volatile unsigned long>,  \
    std::map<volatile unsigned long, volatile unsigned long long>,  \
    std::map<volatile unsigned long, volatile float>,  \
    std::map<volatile unsigned long, volatile double>,  \
    std::map<volatile unsigned long, volatile long double>,  \
    std::map<volatile unsigned long long, char>,  \
    std::map<volatile unsigned long long, wchar_t>,  \
    std::map<volatile unsigned long long, char8_t>,  \
    std::map<volatile unsigned long long, char16_t>,  \
    std::map<volatile unsigned long long, char32_t>,  \
    std::map<volatile unsigned long long, short>,  \
    std::map<volatile unsigned long long, int>,  \
    std::map<volatile unsigned long long, long>,  \
    std::map<volatile unsigned long long, long long>,  \
    std::map<volatile unsigned long long, unsigned short>,  \
    std::map<volatile unsigned long long, unsigned int>,  \
    std::map<volatile unsigned long long, unsigned long>,  \
    std::map<volatile unsigned long long, unsigned long long>,  \
    std::map<volatile unsigned long long, float>,  \
    std::map<volatile unsigned long long, double>,  \
    std::map<volatile unsigned long long, long double>,  \
    std::map<volatile unsigned long long, volatile char>,  \
    std::map<volatile unsigned long long, volatile wchar_t>,  \
    std::map<volatile unsigned long long, volatile char8_t>,  \
    std::map<volatile unsigned long long, volatile char16_t>,  \
    std::map<volatile unsigned long long, volatile char32_t>,  \
    std::map<volatile unsigned long long, volatile short>,  \
    std::map<volatile unsigned long long, volatile int>,  \
    std::map<volatile unsigned long long, volatile long>,  \
    std::map<volatile unsigned long long, volatile long long>,  \
    std::map<volatile unsigned long long, volatile unsigned short>,  \
    std::map<volatile unsigned long long, volatile unsigned int>,  \
    std::map<volatile unsigned long long, volatile unsigned long>,  \
    std::map<volatile unsigned long long, volatile unsigned long long>,  \
    std::map<volatile unsigned long long, volatile float>,  \
    std::map<volatile unsigned long long, volatile double>,  \
    std::map<volatile unsigned long long, volatile long double>,  \
    std::map<volatile float, char>, std::map<volatile float, wchar_t>,  \
    std::map<volatile float, char8_t>, std::map<volatile float, char16_t>,  \
    std::map<volatile float, char32_t>, std::map<volatile float, short>,  \
    std::map<volatile float, int>, std::map<volatile float, long>,  \
    std::map<volatile float, long long>,  \
    std::map<volatile float, unsigned short>,  \
    std::map<volatile float, unsigned int>,  \
    std::map<volatile float, unsigned long>,  \
    std::map<volatile float, unsigned long long>,  \
    std::map<volatile float, float>, std::map<volatile float, double>,  \
    std::map<volatile float, long double>,  \
    std::map<volatile float, volatile char>,  \
    std::map<volatile float, volatile wchar_t>,  \
    std::map<volatile float, volatile char8_t>,  \
    std::map<volatile float, volatile char16_t>,  \
    std::map<volatile float, volatile char32_t>,  \
    std::map<volatile float, volatile short>,  \
    std::map<volatile float, volatile int>,  \
    std::map<volatile float, volatile long>,  \
    std::map<volatile float, volatile long long>,  \
    std::map<volatile float, volatile unsigned short>,  \
    std::map<volatile float, volatile unsigned int>,  \
    std::map<volatile float, volatile unsigned long>,  \
    std::map<volatile float, volatile unsigned long long>,  \
    std::map<volatile float, volatile float>,  \
    std::map<volatile float, volatile double>,  \
    std::map<volatile float, volatile long double>,  \
    std::map<volatile double, char>, std::map<volatile double, wchar_t>,  \
    std::map<volatile double, char8_t>, std::map<volatile double, char16_t>,  \
    std::map<volatile double, char32_t>, std::map<volatile double, short>,  \
    std::map<volatile double, int>, std::map<volatile double, long>,  \
    std::map<volatile double, long long>,  \
    std::map<volatile double, unsigned short>,  \
    std::map<volatile double, unsigned int>,  \
    std::map<volatile double, unsigned long>,  \
    std::map<volatile double, unsigned long long>,  \
    std::map<volatile double, float>, std::map<volatile double, double>,  \
    std::map<volatile double, long double>,  \
    std::map<volatile double, volatile char>,  \
    std::map<volatile double, volatile wchar_t>,  \
    std::map<volatile double, volatile char8_t>,  \
    std::map<volatile double, volatile char16_t>,  \
    std::map<volatile double, volatile char32_t>,  \
    std::map<volatile double, volatile short>,  \
    std::map<volatile double, volatile int>,  \
    std::map<volatile double, volatile long>,  \
    std::map<volatile double, volatile long long>,  \
    std::map<volatile double, volatile unsigned short>,  \
    std::map<volatile double, volatile unsigned int>,  \
    std::map<volatile double, volatile unsigned long>,  \
    std::map<volatile double, volatile unsigned long long>,  \
    std::map<volatile double, volatile float>,  \
    std::map<volatile double, volatile double>,  \
    std::map<volatile double, volatile long double>,  \
    std::map<volatile long double, char>,  \
    std::map<volatile long double, wchar_t>,  \
    std::map<volatile long double, char8_t>,  \
    std::map<volatile long double, char16_t>,  \
    std::map<volatile long double, char32_t>,  \
    std::map<volatile long double, short>,  \
    std::map<volatile long double, int>,  \
    std::map<volatile long double, long>,  \
    std::map<volatile long double, long long>,  \
    std::map<volatile long double, unsigned short>,  \
    std::map<volatile long double, unsigned int>,  \
    std::map<volatile long double, unsigned long>,  \
    std::map<volatile long double, unsigned long long>,  \
    std::map<volatile long double, float>,  \
    std::map<volatile long double, double>,  \
    std::map<volatile long double, long double>,  \
    std::map<volatile long double, volatile char>,  \
    std::map<volatile long double, volatile wchar_t>,  \
    std::map<volatile long double, volatile char8_t>,  \
    std::map<volatile long double, volatile char16_t>,  \
    std::map<volatile long double, volatile char32_t>,  \
    std::map<volatile long double, volatile short>,  \
    std::map<volatile long double, volatile int>,  \
    std::map<volatile long double, volatile long>,  \
    std::map<volatile long double, volatile long long>,  \
    std::map<volatile long double, volatile unsigned short>,  \
    std::map<volatile long double, volatile unsigned int>,  \
    std::map<volatile long double, volatile unsigned long>,  \
    std::map<volatile long double, volatile unsigned long long>,  \
    std::map<volatile long double, volatile float>,  \
    std::map<volatile long double, volatile double>,  \
    std::map<volatile long double, volatile long double>,  \
    std::unordered_map<char, char>, std::unordered_map<char, wchar_t>,  \
    std::unordered_map<char, char8_t>, std::unordered_map<char, char16_t>,  \
    std::unordered_map<char, char32_t>, std::unordered_map<char, short>,  \
    std::unordered_map<char, int>, std::unordered_map<char, long>,  \
    std::unordered_map<char, long long>,  \
    std::unordered_map<char, unsigned short>,  \
    std::unordered_map<char, unsigned int>,  \
    std::unordered_map<char, unsigned long>,  \
    std::unordered_map<char, unsigned long long>,  \
    std::unordered_map<char, float>, std::unordered_map<char, double>,  \
    std::unordered_map<char, long double>,  \
    std::unordered_map<char, volatile char>,  \
    std::unordered_map<char, volatile wchar_t>,  \
    std::unordered_map<char, volatile char8_t>,  \
    std::unordered_map<char, volatile char16_t>,  \
    std::unordered_map<char, volatile char32_t>,  \
    std::unordered_map<char, volatile short>,  \
    std::unordered_map<char, volatile int>,  \
    std::unordered_map<char, volatile long>,  \
    std::unordered_map<char, volatile long long>,  \
    std::unordered_map<char, volatile unsigned short>,  \
    std::unordered_map<char, volatile unsigned int>,  \
    std::unordered_map<char, volatile unsigned long>,  \
    std::unordered_map<char, volatile unsigned long long>,  \
    std::unordered_map<char, volatile float>,  \
    std::unordered_map<char, volatile double>,  \
    std::unordered_map<char, volatile long double>,  \
    std::unordered_map<wchar_t, char>, std::unordered_map<wchar_t, wchar_t>,  \
    std::unordered_map<wchar_t, char8_t>,  \
    std::unordered_map<wchar_t, char16_t>,  \
    std::unordered_map<wchar_t, char32_t>,  \
    std::unordered_map<wchar_t, short>, std::unordered_map<wchar_t, int>,  \
    std::unordered_map<wchar_t, long>,  \
    std::unordered_map<wchar_t, long long>,  \
    std::unordered_map<wchar_t, unsigned short>,  \
    std::unordered_map<wchar_t, unsigned int>,  \
    std::unordered_map<wchar_t, unsigned long>,  \
    std::unordered_map<wchar_t, unsigned long long>,  \
    std::unordered_map<wchar_t, float>, std::unordered_map<wchar_t, double>,  \
    std::unordered_map<wchar_t, long double>,  \
    std::unordered_map<wchar_t, volatile char>,  \
    std::unordered_map<wchar_t, volatile wchar_t>,  \
    std::unordered_map<wchar_t, volatile char8_t>,  \
    std::unordered_map<wchar_t, volatile char16_t>,  \
    std::unordered_map<wchar_t, volatile char32_t>,  \
    std::unordered_map<wchar_t, volatile short>,  \
    std::unordered_map<wchar_t, volatile int>,  \
    std::unordered_map<wchar_t, volatile long>,  \
    std::unordered_map<wchar_t, volatile long long>,  \
    std::unordered_map<wchar_t, volatile unsigned short>,  \
    std::unordered_map<wchar_t, volatile unsigned int>,  \
    std::unordered_map<wchar_t, volatile unsigned long>,  \
    std::unordered_map<wchar_t, volatile unsigned long long>,  \
    std::unordered_map<wchar_t, volatile float>,  \
    std::unordered_map<wchar_t, volatile double>,  \
    std::unordered_map<wchar_t, volatile long double>,  \
    std::unordered_map<char8_t, char>, std::unordered_map<char8_t, wchar_t>,  \
    std::unordered_map<char8_t, char8_t>,  \
    std::unordered_map<char8_t, char16_t>,  \
    std::unordered_map<char8_t, char32_t>,  \
    std::unordered_map<char8_t, short>, std::unordered_map<char8_t, int>,  \
    std::unordered_map<char8_t, long>,  \
    std::unordered_map<char8_t, long long>,  \
    std::unordered_map<char8_t, unsigned short>,  \
    std::unordered_map<char8_t, unsigned int>,  \
    std::unordered_map<char8_t, unsigned long>,  \
    std::unordered_map<char8_t, unsigned long long>,  \
    std::unordered_map<char8_t, float>, std::unordered_map<char8_t, double>,  \
    std::unordered_map<char8_t, long double>,  \
    std::unordered_map<char8_t, volatile char>,  \
    std::unordered_map<char8_t, volatile wchar_t>,  \
    std::unordered_map<char8_t, volatile char8_t>,  \
    std::unordered_map<char8_t, volatile char16_t>,  \
    std::unordered_map<char8_t, volatile char32_t>,  \
    std::unordered_map<char8_t, volatile short>,  \
    std::unordered_map<char8_t, volatile int>,  \
    std::unordered_map<char8_t, volatile long>,  \
    std::unordered_map<char8_t, volatile long long>,  \
    std::unordered_map<char8_t, volatile unsigned short>,  \
    std::unordered_map<char8_t, volatile unsigned int>,  \
    std::unordered_map<char8_t, volatile unsigned long>,  \
    std::unordered_map<char8_t, volatile unsigned long long>,  \
    std::unordered_map<char8_t, volatile float>,  \
    std::unordered_map<char8_t, volatile double>,  \
    std::unordered_map<char8_t, volatile long double>,  \
    std::unordered_map<char16_t, char>,  \
    std::unordered_map<char16_t, wchar_t>,  \
    std::unordered_map<char16_t, char8_t>,  \
    std::unordered_map<char16_t, char16_t>,  \
    std::unordered_map<char16_t, char32_t>,  \
    std::unordered_map<char16_t, short>, std::unordered_map<char16_t, int>,  \
    std::unordered_map<char16_t, long>,  \
    std::unordered_map<char16_t, long long>,  \
    std::unordered_map<char16_t, unsigned short>,  \
    std::unordered_map<char16_t, unsigned int>,  \
    std::unordered_map<char16_t, unsigned long>,  \
    std::unordered_map<char16_t, unsigned long long>,  \
    std::unordered_map<char16_t, float>,  \
    std::unordered_map<char16_t, double>,  \
    std::unordered_map<char16_t, long double>,  \
    std::unordered_map<char16_t, volatile char>,  \
    std::unordered_map<char16_t, volatile wchar_t>,  \
    std::unordered_map<char16_t, volatile char8_t>,  \
    std::unordered_map<char16_t, volatile char16_t>,  \
    std::unordered_map<char16_t, volatile char32_t>,  \
    std::unordered_map<char16_t, volatile short>,  \
    std::unordered_map<char16_t, volatile int>,  \
    std::unordered_map<char16_t, volatile long>,  \
    std::unordered_map<char16_t, volatile long long>,  \
    std::unordered_map<char16_t, volatile unsigned short>,  \
    std::unordered_map<char16_t, volatile unsigned int>,  \
    std::unordered_map<char16_t, volatile unsigned long>,  \
    std::unordered_map<char16_t, volatile unsigned long long>,  \
    std::unordered_map<char16_t, volatile float>,  \
    std::unordered_map<char16_t, volatile double>,  \
    std::unordered_map<char16_t, volatile long double>,  \
    std::unordered_map<char32_t, char>,  \
    std::unordered_map<char32_t, wchar_t>,  \
    std::unordered_map<char32_t, char8_t>,  \
    std::unordered_map<char32_t, char16_t>,  \
    std::unordered_map<char32_t, char32_t>,  \
    std::unordered_map<char32_t, short>, std::unordered_map<char32_t, int>,  \
    std::unordered_map<char32_t, long>,  \
    std::unordered_map<char32_t, long long>,  \
    std::unordered_map<char32_t, unsigned short>,  \
    std::unordered_map<char32_t, unsigned int>,  \
    std::unordered_map<char32_t, unsigned long>,  \
    std::unordered_map<char32_t, unsigned long long>,  \
    std::unordered_map<char32_t, float>,  \
    std::unordered_map<char32_t, double>,  \
    std::unordered_map<char32_t, long double>,  \
    std::unordered_map<char32_t, volatile char>,  \
    std::unordered_map<char32_t, volatile wchar_t>,  \
    std::unordered_map<char32_t, volatile char8_t>,  \
    std::unordered_map<char32_t, volatile char16_t>,  \
    std::unordered_map<char32_t, volatile char32_t>,  \
    std::unordered_map<char32_t, volatile short>,  \
    std::unordered_map<char32_t, volatile int>,  \
    std::unordered_map<char32_t, volatile long>,  \
    std::unordered_map<char32_t, volatile long long>,  \
    std::unordered_map<char32_t, volatile unsigned short>,  \
    std::unordered_map<char32_t, volatile unsigned int>,  \
    std::unordered_map<char32_t, volatile unsigned long>,  \
    std::unordered_map<char32_t, volatile unsigned long long>,  \
    std::unordered_map<char32_t, volatile float>,  \
    std::unordered_map<char32_t, volatile double>,  \
    std::unordered_map<char32_t, volatile long double>,  \
    std::unordered_map<short, char>, std::unordered_map<short, wchar_t>,  \
    std::unordered_map<short, char8_t>, std::unordered_map<short, char16_t>,  \
    std::unordered_map<short, char32_t>, std::unordered_map<short, short>,  \
    std::unordered_map<short, int>, std::unordered_map<short, long>,  \
    std::unordered_map<short, long long>,  \
    std::unordered_map<short, unsigned short>,  \
    std::unordered_map<short, unsigned int>,  \
    std::unordered_map<short, unsigned long>,  \
    std::unordered_map<short, unsigned long long>,  \
    std::unordered_map<short, float>, std::unordered_map<short, double>,  \
    std::unordered_map<short, long double>,  \
    std::unordered_map<short, volatile char>,  \
    std::unordered_map<short, volatile wchar_t>,  \
    std::unordered_map<short, volatile char8_t>,  \
    std::unordered_map<short, volatile char16_t>,  \
    std::unordered_map<short, volatile char32_t>,  \
    std::unordered_map<short, volatile short>,  \
    std::unordered_map<short, volatile int>,  \
    std::unordered_map<short, volatile long>,  \
    std::unordered_map<short, volatile long long>,  \
    std::unordered_map<short, volatile unsigned short>,  \
    std::unordered_map<short, volatile unsigned int>,  \
    std::unordered_map<short, volatile unsigned long>,  \
    std::unordered_map<short, volatile unsigned long long>,  \
    std::unordered_map<short, volatile float>,  \
    std::unordered_map<short, volatile double>,  \
    std::unordered_map<short, volatile long double>,  \
    std::unordered_map<int, char>, std::unordered_map<int, wchar_t>,  \
    std::unordered_map<int, char8_t>, std::unordered_map<int, char16_t>,  \
    std::unordered_map<int, char32_t>, std::unordered_map<int, short>,  \
    std::unordered_map<int, int>, std::unordered_map<int, long>,  \
    std::unordered_map<int, long long>,  \
    std::unordered_map<int, unsigned short>,  \
    std::unordered_map<int, unsigned int>,  \
    std::unordered_map<int, unsigned long>,  \
    std::unordered_map<int, unsigned long long>,  \
    std::unordered_map<int, float>, std::unordered_map<int, double>,  \
    std::unordered_map<int, long double>,  \
    std::unordered_map<int, volatile char>,  \
    std::unordered_map<int, volatile wchar_t>,  \
    std::unordered_map<int, volatile char8_t>,  \
    std::unordered_map<int, volatile char16_t>,  \
    std::unordered_map<int, volatile char32_t>,  \
    std::unordered_map<int, volatile short>,  \
    std::unordered_map<int, volatile int>,  \
    std::unordered_map<int, volatile long>,  \
    std::unordered_map<int, volatile long long>,  \
    std::unordered_map<int, volatile unsigned short>,  \
    std::unordered_map<int, volatile unsigned int>,  \
    std::unordered_map<int, volatile unsigned long>,  \
    std::unordered_map<int, volatile unsigned long long>,  \
    std::unordered_map<int, volatile float>,  \
    std::unordered_map<int, volatile double>,  \
    std::unordered_map<int, volatile long double>,  \
    std::unordered_map<long, char>, std::unordered_map<long, wchar_t>,  \
    std::unordered_map<long, char8_t>, std::unordered_map<long, char16_t>,  \
    std::unordered_map<long, char32_t>, std::unordered_map<long, short>,  \
    std::unordered_map<long, int>, std::unordered_map<long, long>,  \
    std::unordered_map<long, long long>,  \
    std::unordered_map<long, unsigned short>,  \
    std::unordered_map<long, unsigned int>,  \
    std::unordered_map<long, unsigned long>,  \
    std::unordered_map<long, unsigned long long>,  \
    std::unordered_map<long, float>, std::unordered_map<long, double>,  \
    std::unordered_map<long, long double>,  \
    std::unordered_map<long, volatile char>,  \
    std::unordered_map<long, volatile wchar_t>,  \
    std::unordered_map<long, volatile char8_t>,  \
    std::unordered_map<long, volatile char16_t>,  \
    std::unordered_map<long, volatile char32_t>,  \
    std::unordered_map<long, volatile short>,  \
    std::unordered_map<long, volatile int>,  \
    std::unordered_map<long, volatile long>,  \
    std::unordered_map<long, volatile long long>,  \
    std::unordered_map<long, volatile unsigned short>,  \
    std::unordered_map<long, volatile unsigned int>,  \
    std::unordered_map<long, volatile unsigned long>,  \
    std::unordered_map<long, volatile unsigned long long>,  \
    std::unordered_map<long, volatile float>,  \
    std::unordered_map<long, volatile double>,  \
    std::unordered_map<long, volatile long double>,  \
    std::unordered_map<long long, char>,  \
    std::unordered_map<long long, wchar_t>,  \
    std::unordered_map<long long, char8_t>,  \
    std::unordered_map<long long, char16_t>,  \
    std::unordered_map<long long, char32_t>,  \
    std::unordered_map<long long, short>,  \
    std::unordered_map<long long, int>, std::unordered_map<long long, long>,  \
    std::unordered_map<long long, long long>,  \
    std::unordered_map<long long, unsigned short>,  \
    std::unordered_map<long long, unsigned int>,  \
    std::unordered_map<long long, unsigned long>,  \
    std::unordered_map<long long, unsigned long long>,  \
    std::unordered_map<long long, float>,  \
    std::unordered_map<long long, double>,  \
    std::unordered_map<long long, long double>,  \
    std::unordered_map<long long, volatile char>,  \
    std::unordered_map<long long, volatile wchar_t>,  \
    std::unordered_map<long long, volatile char8_t>,  \
    std::unordered_map<long long, volatile char16_t>,  \
    std::unordered_map<long long, volatile char32_t>,  \
    std::unordered_map<long long, volatile short>,  \
    std::unordered_map<long long, volatile int>,  \
    std::unordered_map<long long, volatile long>,  \
    std::unordered_map<long long, volatile long long>,  \
    std::unordered_map<long long, volatile unsigned short>,  \
    std::unordered_map<long long, volatile unsigned int>,  \
    std::unordered_map<long long, volatile unsigned long>,  \
    std::unordered_map<long long, volatile unsigned long long>,  \
    std::unordered_map<long long, volatile float>,  \
    std::unordered_map<long long, volatile double>,  \
    std::unordered_map<long long, volatile long double>,  \
    std::unordered_map<unsigned short, char>,  \
    std::unordered_map<unsigned short, wchar_t>,  \
    std::unordered_map<unsigned short, char8_t>,  \
    std::unordered_map<unsigned short, char16_t>,  \
    std::unordered_map<unsigned short, char32_t>,  \
    std::unordered_map<unsigned short, short>,  \
    std::unordered_map<unsigned short, int>,  \
    std::unordered_map<unsigned short, long>,  \
    std::unordered_map<unsigned short, long long>,  \
    std::unordered_map<unsigned short, unsigned short>,  \
    std::unordered_map<unsigned short, unsigned int>,  \
    std::unordered_map<unsigned short, unsigned long>,  \
    std::unordered_map<unsigned short, unsigned long long>,  \
    std::unordered_map<unsigned short, float>,  \
    std::unordered_map<unsigned short, double>,  \
    std::unordered_map<unsigned short, long double>,  \
    std::unordered_map<unsigned short, volatile char>,  \
    std::unordered_map<unsigned short, volatile wchar_t>,  \
    std::unordered_map<unsigned short, volatile char8_t>,  \
    std::unordered_map<unsigned short, volatile char16_t>,  \
    std::unordered_map<unsigned short, volatile char32_t>,  \
    std::unordered_map<unsigned short, volatile short>,  \
    std::unordered_map<unsigned short, volatile int>,  \
    std::unordered_map<unsigned short, volatile long>,  \
    std::unordered_map<unsigned short, volatile long long>,  \
    std::unordered_map<unsigned short, volatile unsigned short>,  \
    std::unordered_map<unsigned short, volatile unsigned int>,  \
    std::unordered_map<unsigned short, volatile unsigned long>,  \
    std::unordered_map<unsigned short, volatile unsigned long long>,  \
    std::unordered_map<unsigned short, volatile float>,  \
    std::unordered_map<unsigned short, volatile double>,  \
    std::unordered_map<unsigned short, volatile long double>,  \
    std::unordered_map<unsigned int, char>,  \
    std::unordered_map<unsigned int, wchar_t>,  \
    std::unordered_map<unsigned int, char8_t>,  \
    std::unordered_map<unsigned int, char16_t>,  \
    std::unordered_map<unsigned int, char32_t>,  \
    std::unordered_map<unsigned int, short>,  \
    std::unordered_map<unsigned int, int>,  \
    std::unordered_map<unsigned int, long>,  \
    std::unordered_map<unsigned int, long long>,  \
    std::unordered_map<unsigned int, unsigned short>,  \
    std::unordered_map<unsigned int, unsigned int>,  \
    std::unordered_map<unsigned int, unsigned long>,  \
    std::unordered_map<unsigned int, unsigned long long>,  \
    std::unordered_map<unsigned int, float>,  \
    std::unordered_map<unsigned int, double>,  \
    std::unordered_map<unsigned int, long double>,  \
    std::unordered_map<unsigned int, volatile char>,  \
    std::unordered_map<unsigned int, volatile wchar_t>,  \
    std::unordered_map<unsigned int, volatile char8_t>,  \
    std::unordered_map<unsigned int, volatile char16_t>,  \
    std::unordered_map<unsigned int, volatile char32_t>,  \
    std::unordered_map<unsigned int, volatile short>,  \
    std::unordered_map<unsigned int, volatile int>,  \
    std::unordered_map<unsigned int, volatile long>,  \
    std::unordered_map<unsigned int, volatile long long>,  \
    std::unordered_map<unsigned int, volatile unsigned short>,  \
    std::unordered_map<unsigned int, volatile unsigned int>,  \
    std::unordered_map<unsigned int, volatile unsigned long>,  \
    std::unordered_map<unsigned int, volatile unsigned long long>,  \
    std::unordered_map<unsigned int, volatile float>,  \
    std::unordered_map<unsigned int, volatile double>,  \
    std::unordered_map<unsigned int, volatile long double>,  \
    std::unordered_map<unsigned long, char>,  \
    std::unordered_map<unsigned long, wchar_t>,  \
    std::unordered_map<unsigned long, char8_t>,  \
    std::unordered_map<unsigned long, char16_t>,  \
    std::unordered_map<unsigned long, char32_t>,  \
    std::unordered_map<unsigned long, short>,  \
    std::unordered_map<unsigned long, int>,  \
    std::unordered_map<unsigned long, long>,  \
    std::unordered_map<unsigned long, long long>,  \
    std::unordered_map<unsigned long, unsigned short>,  \
    std::unordered_map<unsigned long, unsigned int>,  \
    std::unordered_map<unsigned long, unsigned long>,  \
    std::unordered_map<unsigned long, unsigned long long>,  \
    std::unordered_map<unsigned long, float>,  \
    std::unordered_map<unsigned long, double>,  \
    std::unordered_map<unsigned long, long double>,  \
    std::unordered_map<unsigned long, volatile char>,  \
    std::unordered_map<unsigned long, volatile wchar_t>,  \
    std::unordered_map<unsigned long, volatile char8_t>,  \
    std::unordered_map<unsigned long, volatile char16_t>,  \
    std::unordered_map<unsigned long, volatile char32_t>,  \
    std::unordered_map<unsigned long, volatile short>,  \
    std::unordered_map<unsigned long, volatile int>,  \
    std::unordered_map<unsigned long, volatile long>,  \
    std::unordered_map<unsigned long, volatile long long>,  \
    std::unordered_map<unsigned long, volatile unsigned short>,  \
    std::unordered_map<unsigned long, volatile unsigned int>,  \
    std::unordered_map<unsigned long, volatile unsigned long>,  \
    std::unordered_map<unsigned long, volatile unsigned long long>,  \
    std::unordered_map<unsigned long, volatile float>,  \
    std::unordered_map<unsigned long, volatile double>,  \
    std::unordered_map<unsigned long, volatile long double>,  \
    std::unordered_map<unsigned long long, char>,  \
    std::unordered_map<unsigned long long, wchar_t>,  \
    std::unordered_map<unsigned long long, char8_t>,  \
    std::unordered_map<unsigned long long, char16_t>,  \
    std::unordered_map<unsigned long long, char32_t>,  \
    std::unordered_map<unsigned long long, short>,  \
    std::unordered_map<unsigned long long, int>,  \
    std::unordered_map<unsigned long long, long>,  \
    std::unordered_map<unsigned long long, long long>,  \
    std::unordered_map<unsigned long long, unsigned short>,  \
    std::unordered_map<unsigned long long, unsigned int>,  \
    std::unordered_map<unsigned long long, unsigned long>,  \
    std::unordered_map<unsigned long long, unsigned long long>,  \
    std::unordered_map<unsigned long long, float>,  \
    std::unordered_map<unsigned long long, double>,  \
    std::unordered_map<unsigned long long, long double>,  \
    std::unordered_map<unsigned long long, volatile char>,  \
    std::unordered_map<unsigned long long, volatile wchar_t>,  \
    std::unordered_map<unsigned long long, volatile char8_t>,  \
    std::unordered_map<unsigned long long, volatile char16_t>,  \
    std::unordered_map<unsigned long long, volatile char32_t>,  \
    std::unordered_map<unsigned long long, volatile short>,  \
    std::unordered_map<unsigned long long, volatile int>,  \
    std::unordered_map<unsigned long long, volatile long>,  \
    std::unordered_map<unsigned long long, volatile long long>,  \
    std::unordered_map<unsigned long long, volatile unsigned short>,  \
    std::unordered_map<unsigned long long, volatile unsigned int>,  \
    std::unordered_map<unsigned long long, volatile unsigned long>,  \
    std::unordered_map<unsigned long long, volatile unsigned long long>,  \
    std::unordered_map<unsigned long long, volatile float>,  \
    std::unordered_map<unsigned long long, volatile double>,  \
    std::unordered_map<unsigned long long, volatile long double>,  \
    std::unordered_map<float, char>, std::unordered_map<float, wchar_t>,  \
    std::unordered_map<float, char8_t>, std::unordered_map<float, char16_t>,  \
    std::unordered_map<float, char32_t>, std::unordered_map<float, short>,  \
    std::unordered_map<float, int>, std::unordered_map<float, long>,  \
    std::unordered_map<float, long long>,  \
    std::unordered_map<float, unsigned short>,  \
    std::unordered_map<float, unsigned int>,  \
    std::unordered_map<float, unsigned long>,  \
    std::unordered_map<float, unsigned long long>,  \
    std::unordered_map<float, float>, std::unordered_map<float, double>,  \
    std::unordered_map<float, long double>,  \
    std::unordered_map<float, volatile char>,  \
    std::unordered_map<float, volatile wchar_t>,  \
    std::unordered_map<float, volatile char8_t>,  \
    std::unordered_map<float, volatile char16_t>,  \
    std::unordered_map<float, volatile char32_t>,  \
    std::unordered_map<float, volatile short>,  \
    std::unordered_map<float, volatile int>,  \
    std::unordered_map<float, volatile long>,  \
    std::unordered_map<float, volatile long long>,  \
    std::unordered_map<float, volatile unsigned short>,  \
    std::unordered_map<float, volatile unsigned int>,  \
    std::unordered_map<float, volatile unsigned long>,  \
    std::unordered_map<float, volatile unsigned long long>,  \
    std::unordered_map<float, volatile float>,  \
    std::unordered_map<float, volatile double>,  \
    std::unordered_map<float, volatile long double>,  \
    std::unordered_map<double, char>, std::unordered_map<double, wchar_t>,  \
    std::unordered_map<double, char8_t>,  \
    std::unordered_map<double, char16_t>,  \
    std::unordered_map<double, char32_t>, std::unordered_map<double, short>,  \
    std::unordered_map<double, int>, std::unordered_map<double, long>,  \
    std::unordered_map<double, long long>,  \
    std::unordered_map<double, unsigned short>,  \
    std::unordered_map<double, unsigned int>,  \
    std::unordered_map<double, unsigned long>,  \
    std::unordered_map<double, unsigned long long>,  \
    std::unordered_map<double, float>, std::unordered_map<double, double>,  \
    std::unordered_map<double, long double>,  \
    std::unordered_map<double, volatile char>,  \
    std::unordered_map<double, volatile wchar_t>,  \
    std::unordered_map<double, volatile char8_t>,  \
    std::unordered_map<double, volatile char16_t>,  \
    std::unordered_map<double, volatile char32_t>,  \
    std::unordered_map<double, volatile short>,  \
    std::unordered_map<double, volatile int>,  \
    std::unordered_map<double, volatile long>,  \
    std::unordered_map<double, volatile long long>,  \
    std::unordered_map<double, volatile unsigned short>,  \
    std::unordered_map<double, volatile unsigned int>,  \
    std::unordered_map<double, volatile unsigned long>,  \
    std::unordered_map<double, volatile unsigned long long>,  \
    std::unordered_map<double, volatile float>,  \
    std::unordered_map<double, volatile double>,  \
    std::unordered_map<double, volatile long double>,  \
    std::unordered_map<long double, char>,  \
    std::unordered_map<long double, wchar_t>,  \
    std::unordered_map<long double, char8_t>,  \
    std::unordered_map<long double, char16_t>,  \
    std::unordered_map<long double, char32_t>,  \
    std::unordered_map<long double, short>,  \
    std::unordered_map<long double, int>,  \
    std::unordered_map<long double, long>,  \
    std::unordered_map<long double, long long>,  \
    std::unordered_map<long double, unsigned short>,  \
    std::unordered_map<long double, unsigned int>,  \
    std::unordered_map<long double, unsigned long>,  \
    std::unordered_map<long double, unsigned long long>,  \
    std::unordered_map<long double, float>,  \
    std::unordered_map<long double, double>,  \
    std::unordered_map<long double, long double>,  \
    std::unordered_map<long double, volatile char>,  \
    std::unordered_map<long double, volatile wchar_t>,  \
    std::unordered_map<long double, volatile char8_t>,  \
    std::unordered_map<long double, volatile char16_t>,  \
    std::unordered_map<long double, volatile char32_t>,  \
    std::unordered_map<long double, volatile short>,  \
    std::unordered_map<long double, volatile int>,  \
    std::unordered_map<long double, volatile long>,  \
    std::unordered_map<long double, volatile long long>,  \
    std::unordered_map<long double, volatile unsigned short>,  \
    std::unordered_map<long double, volatile unsigned int>,  \
    std::unordered_map<long double, volatile unsigned long>,  \
    std::unordered_map<long double, volatile unsigned long long>,  \
    std::unordered_map<long double, volatile float>,  \
    std::unordered_map<long double, volatile double>,  \
    std::unordered_map<long double, volatile long double>,  \
    std::unordered_map<volatile char, char>,  \
    std::unordered_map<volatile char, wchar_t>,  \
    std::unordered_map<volatile char, char8_t>,  \
    std::unordered_map<volatile char, char16_t>,  \
    std::unordered_map<volatile char, char32_t>,  \
    std::unordered_map<volatile char, short>,  \
    std::unordered_map<volatile char, int>,  \
    std::unordered_map<volatile char, long>,  \
    std::unordered_map<volatile char, long long>,  \
    std::unordered_map<volatile char, unsigned short>,  \
    std::unordered_map<volatile char, unsigned int>,  \
    std::unordered_map<volatile char, unsigned long>,  \
    std::unordered_map<volatile char, unsigned long long>,  \
    std::unordered_map<volatile char, float>,  \
    std::unordered_map<volatile char, double>,  \
    std::unordered_map<volatile char, long double>,  \
    std::unordered_map<volatile char, volatile char>,  \
    std::unordered_map<volatile char, volatile wchar_t>,  \
    std::unordered_map<volatile char, volatile char8_t>,  \
    std::unordered_map<volatile char, volatile char16_t>,  \
    std::unordered_map<volatile char, volatile char32_t>,  \
    std::unordered_map<volatile char, volatile short>,  \
    std::unordered_map<volatile char, volatile int>,  \
    std::unordered_map<volatile char, volatile long>,  \
    std::unordered_map<volatile char, volatile long long>,  \
    std::unordered_map<volatile char, volatile unsigned short>,  \
    std::unordered_map<volatile char, volatile unsigned int>,  \
    std::unordered_map<volatile char, volatile unsigned long>,  \
    std::unordered_map<volatile char, volatile unsigned long long>,  \
    std::unordered_map<volatile char, volatile float>,  \
    std::unordered_map<volatile char, volatile double>,  \
    std::unordered_map<volatile char, volatile long double>,  \
    std::unordered_map<volatile wchar_t, char>,  \
    std::unordered_map<volatile wchar_t, wchar_t>,  \
    std::unordered_map<volatile wchar_t, char8_t>,  \
    std::unordered_map<volatile wchar_t, char16_t>,  \
    std::unordered_map<volatile wchar_t, char32_t>,  \
    std::unordered_map<volatile wchar_t, short>,  \
    std::unordered_map<volatile wchar_t, int>,  \
    std::unordered_map<volatile wchar_t, long>,  \
    std::unordered_map<volatile wchar_t, long long>,  \
    std::unordered_map<volatile wchar_t, unsigned short>,  \
    std::unordered_map<volatile wchar_t, unsigned int>,  \
    std::unordered_map<volatile wchar_t, unsigned long>,  \
    std::unordered_map<volatile wchar_t, unsigned long long>,  \
    std::unordered_map<volatile wchar_t, float>,  \
    std::unordered_map<volatile wchar_t, double>,  \
    std::unordered_map<volatile wchar_t, long double>,  \
    std::unordered_map<volatile wchar_t, volatile char>,  \
    std::unordered_map<volatile wchar_t, volatile wchar_t>,  \
    std::unordered_map<volatile wchar_t, volatile char8_t>,  \
    std::unordered_map<volatile wchar_t, volatile char16_t>,  \
    std::unordered_map<volatile wchar_t, volatile char32_t>,  \
    std::unordered_map<volatile wchar_t, volatile short>,  \
    std::unordered_map<volatile wchar_t, volatile int>,  \
    std::unordered_map<volatile wchar_t, volatile long>,  \
    std::unordered_map<volatile wchar_t, volatile long long>,  \
    std::unordered_map<volatile wchar_t, volatile unsigned short>,  \
    std::unordered_map<volatile wchar_t, volatile unsigned int>,  \
    std::unordered_map<volatile wchar_t, volatile unsigned long>,  \
    std::unordered_map<volatile wchar_t, volatile unsigned long long>,  \
    std::unordered_map<volatile wchar_t, volatile float>,  \
    std::unordered_map<volatile wchar_t, volatile double>,  \
    std::unordered_map<volatile wchar_t, volatile long double>,  \
    std::unordered_map<volatile char8_t, char>,  \
    std::unordered_map<volatile char8_t, wchar_t>,  \
    std::unordered_map<volatile char8_t, char8_t>,  \
    std::unordered_map<volatile char8_t, char16_t>,  \
    std::unordered_map<volatile char8_t, char32_t>,  \
    std::unordered_map<volatile char8_t, short>,  \
    std::unordered_map<volatile char8_t, int>,  \
    std::unordered_map<volatile char8_t, long>,  \
    std::unordered_map<volatile char8_t, long long>,  \
    std::unordered_map<volatile char8_t, unsigned short>,  \
    std::unordered_map<volatile char8_t, unsigned int>,  \
    std::unordered_map<volatile char8_t, unsigned long>,  \
    std::unordered_map<volatile char8_t, unsigned long long>,  \
    std::unordered_map<volatile char8_t, float>,  \
    std::unordered_map<volatile char8_t, double>,  \
    std::unordered_map<volatile char8_t, long double>,  \
    std::unordered_map<volatile char8_t, volatile char>,  \
    std::unordered_map<volatile char8_t, volatile wchar_t>,  \
    std::unordered_map<volatile char8_t, volatile char8_t>,  \
    std::unordered_map<volatile char8_t, volatile char16_t>,  \
    std::unordered_map<volatile char8_t, volatile char32_t>,  \
    std::unordered_map<volatile char8_t, volatile short>,  \
    std::unordered_map<volatile char8_t, volatile int>,  \
    std::unordered_map<volatile char8_t, volatile long>,  \
    std::unordered_map<volatile char8_t, volatile long long>,  \
    std::unordered_map<volatile char8_t, volatile unsigned short>,  \
    std::unordered_map<volatile char8_t, volatile unsigned int>,  \
    std::unordered_map<volatile char8_t, volatile unsigned long>,  \
    std::unordered_map<volatile char8_t, volatile unsigned long long>,  \
    std::unordered_map<volatile char8_t, volatile float>,  \
    std::unordered_map<volatile char8_t, volatile double>,  \
    std::unordered_map<volatile char8_t, volatile long double>,  \
    std::unordered_map<volatile char16_t, char>,  \
    std::unordered_map<volatile char16_t, wchar_t>,  \
    std::unordered_map<volatile char16_t, char8_t>,  \
    std::unordered_map<volatile char16_t, char16_t>,  \
    std::unordered_map<volatile char16_t, char32_t>,  \
    std::unordered_map<volatile char16_t, short>,  \
    std::unordered_map<volatile char16_t, int>,  \
    std::unordered_map<volatile char16_t, long>,  \
    std::unordered_map<volatile char16_t, long long>,  \
    std::unordered_map<volatile char16_t, unsigned short>,  \
    std::unordered_map<volatile char16_t, unsigned int>,  \
    std::unordered_map<volatile char16_t, unsigned long>,  \
    std::unordered_map<volatile char16_t, unsigned long long>,  \
    std::unordered_map<volatile char16_t, float>,  \
    std::unordered_map<volatile char16_t, double>,  \
    std::unordered_map<volatile char16_t, long double>,  \
    std::unordered_map<volatile char16_t, volatile char>,  \
    std::unordered_map<volatile char16_t, volatile wchar_t>,  \
    std::unordered_map<volatile char16_t, volatile char8_t>,  \
    std::unordered_map<volatile char16_t, volatile char16_t>,  \
    std::unordered_map<volatile char16_t, volatile char32_t>,  \
    std::unordered_map<volatile char16_t, volatile short>,  \
    std::unordered_map<volatile char16_t, volatile int>,  \
    std::unordered_map<volatile char16_t, volatile long>,  \
    std::unordered_map<volatile char16_t, volatile long long>,  \
    std::unordered_map<volatile char16_t, volatile unsigned short>,  \
    std::unordered_map<volatile char16_t, volatile unsigned int>,  \
    std::unordered_map<volatile char16_t, volatile unsigned long>,  \
    std::unordered_map<volatile char16_t, volatile unsigned long long>,  \
    std::unordered_map<volatile char16_t, volatile float>,  \
    std::unordered_map<volatile char16_t, volatile double>,  \
    std::unordered_map<volatile char16_t, volatile long double>,  \
    std::unordered_map<volatile char32_t, char>,  \
    std::unordered_map<volatile char32_t, wchar_t>,  \
    std::unordered_map<volatile char32_t, char8_t>,  \
    std::unordered_map<volatile char32_t, char16_t>,  \
    std::unordered_map<volatile char32_t, char32_t>,  \
    std::unordered_map<volatile char32_t, short>,  \
    std::unordered_map<volatile char32_t, int>,  \
    std::unordered_map<volatile char32_t, long>,  \
    std::unordered_map<volatile char32_t, long long>,  \
    std::unordered_map<volatile char32_t, unsigned short>,  \
    std::unordered_map<volatile char32_t, unsigned int>,  \
    std::unordered_map<volatile char32_t, unsigned long>,  \
    std::unordered_map<volatile char32_t, unsigned long long>,  \
    std::unordered_map<volatile char32_t, float>,  \
    std::unordered_map<volatile char32_t, double>,  \
    std::unordered_map<volatile char32_t, long double>,  \
    std::unordered_map<volatile char32_t, volatile char>,  \
    std::unordered_map<volatile char32_t, volatile wchar_t>,  \
    std::unordered_map<volatile char32_t, volatile char8_t>,  \
    std::unordered_map<volatile char32_t, volatile char16_t>,  \
    std::unordered_map<volatile char32_t, volatile char32_t>,  \
    std::unordered_map<volatile char32_t, volatile short>,  \
    std::unordered_map<volatile char32_t, volatile int>,  \
    std::unordered_map<volatile char32_t, volatile long>,  \
    std::unordered_map<volatile char32_t, volatile long long>,  \
    std::unordered_map<volatile char32_t, volatile unsigned short>,  \
    std::unordered_map<volatile char32_t, volatile unsigned int>,  \
    std::unordered_map<volatile char32_t, volatile unsigned long>,  \
    std::unordered_map<volatile char32_t, volatile unsigned long long>,  \
    std::unordered_map<volatile char32_t, volatile float>,  \
    std::unordered_map<volatile char32_t, volatile double>,  \
    std::unordered_map<volatile char32_t, volatile long double>,  \
    std::unordered_map<volatile short, char>,  \
    std::unordered_map<volatile short, wchar_t>,  \
    std::unordered_map<volatile short, char8_t>,  \
    std::unordered_map<volatile short, char16_t>,  \
    std::unordered_map<volatile short, char32_t>,  \
    std::unordered_map<volatile short, short>,  \
    std::unordered_map<volatile short, int>,  \
    std::unordered_map<volatile short, long>,  \
    std::unordered_map<volatile short, long long>,  \
    std::unordered_map<volatile short, unsigned short>,  \
    std::unordered_map<volatile short, unsigned int>,  \
    std::unordered_map<volatile short, unsigned long>,  \
    std::unordered_map<volatile short, unsigned long long>,  \
    std::unordered_map<volatile short, float>,  \
    std::unordered_map<volatile short, double>,  \
    std::unordered_map<volatile short, long double>,  \
    std::unordered_map<volatile short, volatile char>,  \
    std::unordered_map<volatile short, volatile wchar_t>,  \
    std::unordered_map<volatile short, volatile char8_t>,  \
    std::unordered_map<volatile short, volatile char16_t>,  \
    std::unordered_map<volatile short, volatile char32_t>,  \
    std::unordered_map<volatile short, volatile short>,  \
    std::unordered_map<volatile short, volatile int>,  \
    std::unordered_map<volatile short, volatile long>,  \
    std::unordered_map<volatile short, volatile long long>,  \
    std::unordered_map<volatile short, volatile unsigned short>,  \
    std::unordered_map<volatile short, volatile unsigned int>,  \
    std::unordered_map<volatile short, volatile unsigned long>,  \
    std::unordered_map<volatile short, volatile unsigned long long>,  \
    std::unordered_map<volatile short, volatile float>,  \
    std::unordered_map<volatile short, volatile double>,  \
    std::unordered_map<volatile short, volatile long double>,  \
    std::unordered_map<volatile int, char>,  \
    std::unordered_map<volatile int, wchar_t>,  \
    std::unordered_map<volatile int, char8_t>,  \
    std::unordered_map<volatile int, char16_t>,  \
    std::unordered_map<volatile int, char32_t>,  \
    std::unordered_map<volatile int, short>,  \
    std::unordered_map<volatile int, int>,  \
    std::unordered_map<volatile int, long>,  \
    std::unordered_map<volatile int, long long>,  \
    std::unordered_map<volatile int, unsigned short>,  \
    std::unordered_map<volatile int, unsigned int>,  \
    std::unordered_map<volatile int, unsigned long>,  \
    std::unordered_map<volatile int, unsigned long long>,  \
    std::unordered_map<volatile int, float>,  \
    std::unordered_map<volatile int, double>,  \
    std::unordered_map<volatile int, long double>,  \
    std::unordered_map<volatile int, volatile char>,  \
    std::unordered_map<volatile int, volatile wchar_t>,  \
    std::unordered_map<volatile int, volatile char8_t>,  \
    std::unordered_map<volatile int, volatile char16_t>,  \
    std::unordered_map<volatile int, volatile char32_t>,  \
    std::unordered_map<volatile int, volatile short>,  \
    std::unordered_map<volatile int, volatile int>,  \
    std::unordered_map<volatile int, volatile long>,  \
    std::unordered_map<volatile int, volatile long long>,  \
    std::unordered_map<volatile int, volatile unsigned short>,  \
    std::unordered_map<volatile int, volatile unsigned int>,  \
    std::unordered_map<volatile int, volatile unsigned long>,  \
    std::unordered_map<volatile int, volatile unsigned long long>,  \
    std::unordered_map<volatile int, volatile float>,  \
    std::unordered_map<volatile int, volatile double>,  \
    std::unordered_map<volatile int, volatile long double>,  \
    std::unordered_map<volatile long, char>,  \
    std::unordered_map<volatile long, wchar_t>,  \
    std::unordered_map<volatile long, char8_t>,  \
    std::unordered_map<volatile long, char16_t>,  \
    std::unordered_map<volatile long, char32_t>,  \
    std::unordered_map<volatile long, short>,  \
    std::unordered_map<volatile long, int>,  \
    std::unordered_map<volatile long, long>,  \
    std::unordered_map<volatile long, long long>,  \
    std::unordered_map<volatile long, unsigned short>,  \
    std::unordered_map<volatile long, unsigned int>,  \
    std::unordered_map<volatile long, unsigned long>,  \
    std::unordered_map<volatile long, unsigned long long>,  \
    std::unordered_map<volatile long, float>,  \
    std::unordered_map<volatile long, double>,  \
    std::unordered_map<volatile long, long double>,  \
    std::unordered_map<volatile long, volatile char>,  \
    std::unordered_map<volatile long, volatile wchar_t>,  \
    std::unordered_map<volatile long, volatile char8_t>,  \
    std::unordered_map<volatile long, volatile char16_t>,  \
    std::unordered_map<volatile long, volatile char32_t>,  \
    std::unordered_map<volatile long, volatile short>,  \
    std::unordered_map<volatile long, volatile int>,  \
    std::unordered_map<volatile long, volatile long>,  \
    std::unordered_map<volatile long, volatile long long>,  \
    std::unordered_map<volatile long, volatile unsigned short>,  \
    std::unordered_map<volatile long, volatile unsigned int>,  \
    std::unordered_map<volatile long, volatile unsigned long>,  \
    std::unordered_map<volatile long, volatile unsigned long long>,  \
    std::unordered_map<volatile long, volatile float>,  \
    std::unordered_map<volatile long, volatile double>,  \
    std::unordered_map<volatile long, volatile long double>,  \
    std::unordered_map<volatile long long, char>,  \
    std::unordered_map<volatile long long, wchar_t>,  \
    std::unordered_map<volatile long long, char8_t>,  \
    std::unordered_map<volatile long long, char16_t>,  \
    std::unordered_map<volatile long long, char32_t>,  \
    std::unordered_map<volatile long long, short>,  \
    std::unordered_map<volatile long long, int>,  \
    std::unordered_map<volatile long long, long>,  \
    std::unordered_map<volatile long long, long long>,  \
    std::unordered_map<volatile long long, unsigned short>,  \
    std::unordered_map<volatile long long, unsigned int>,  \
    std::unordered_map<volatile long long, unsigned long>,  \
    std::unordered_map<volatile long long, unsigned long long>,  \
    std::unordered_map<volatile long long, float>,  \
    std::unordered_map<volatile long long, double>,  \
    std::unordered_map<volatile long long, long double>,  \
    std::unordered_map<volatile long long, volatile char>,  \
    std::unordered_map<volatile long long, volatile wchar_t>,  \
    std::unordered_map<volatile long long, volatile char8_t>,  \
    std::unordered_map<volatile long long, volatile char16_t>,  \
    std::unordered_map<volatile long long, volatile char32_t>,  \
    std::unordered_map<volatile long long, volatile short>,  \
    std::unordered_map<volatile long long, volatile int>,  \
    std::unordered_map<volatile long long, volatile long>,  \
    std::unordered_map<volatile long long, volatile long long>,  \
    std::unordered_map<volatile long long, volatile unsigned short>,  \
    std::unordered_map<volatile long long, volatile unsigned int>,  \
    std::unordered_map<volatile long long, volatile unsigned long>,  \
    std::unordered_map<volatile long long, volatile unsigned long long>,  \
    std::unordered_map<volatile long long, volatile float>,  \
    std::unordered_map<volatile long long, volatile double>,  \
    std::unordered_map<volatile long long, volatile long double>,  \
    std::unordered_map<volatile unsigned short, char>,  \
    std::unordered_map<volatile unsigned short, wchar_t>,  \
    std::unordered_map<volatile unsigned short, char8_t>,  \
    std::unordered_map<volatile unsigned short, char16_t>,  \
    std::unordered_map<volatile unsigned short, char32_t>,  \
    std::unordered_map<volatile unsigned short, short>,  \
    std::unordered_map<volatile unsigned short, int>,  \
    std::unordered_map<volatile unsigned short, long>,  \
    std::unordered_map<volatile unsigned short, long long>,  \
    std::unordered_map<volatile unsigned short, unsigned short>,  \
    std::unordered_map<volatile unsigned short, unsigned int>,  \
    std::unordered_map<volatile unsigned short, unsigned long>,  \
    std::unordered_map<volatile unsigned short, unsigned long long>,  \
    std::unordered_map<volatile unsigned short, float>,  \
    std::unordered_map<volatile unsigned short, double>,  \
    std::unordered_map<volatile unsigned short, long double>,  \
    std::unordered_map<volatile unsigned short, volatile char>,  \
    std::unordered_map<volatile unsigned short, volatile wchar_t>,  \
    std::unordered_map<volatile unsigned short, volatile char8_t>,  \
    std::unordered_map<volatile unsigned short, volatile char16_t>,  \
    std::unordered_map<volatile unsigned short, volatile char32_t>,  \
    std::unordered_map<volatile unsigned short, volatile short>,  \
    std::unordered_map<volatile unsigned short, volatile int>,  \
    std::unordered_map<volatile unsigned short, volatile long>,  \
    std::unordered_map<volatile unsigned short, volatile long long>,  \
    std::unordered_map<volatile unsigned short, volatile unsigned short>,  \
    std::unordered_map<volatile unsigned short, volatile unsigned int>,  \
    std::unordered_map<volatile unsigned short, volatile unsigned long>,  \
    std::unordered_map<volatile unsigned short, volatile unsigned long long>,  \
    std::unordered_map<volatile unsigned short, volatile float>,  \
    std::unordered_map<volatile unsigned short, volatile double>,  \
    std::unordered_map<volatile unsigned short, volatile long double>,  \
    std::unordered_map<volatile unsigned int, char>,  \
    std::unordered_map<volatile unsigned int, wchar_t>,  \
    std::unordered_map<volatile unsigned int, char8_t>,  \
    std::unordered_map<volatile unsigned int, char16_t>,  \
    std::unordered_map<volatile unsigned int, char32_t>,  \
    std::unordered_map<volatile unsigned int, short>,  \
    std::unordered_map<volatile unsigned int, int>,  \
    std::unordered_map<volatile unsigned int, long>,  \
    std::unordered_map<volatile unsigned int, long long>,  \
    std::unordered_map<volatile unsigned int, unsigned short>,  \
    std::unordered_map<volatile unsigned int, unsigned int>,  \
    std::unordered_map<volatile unsigned int, unsigned long>,  \
    std::unordered_map<volatile unsigned int, unsigned long long>,  \
    std::unordered_map<volatile unsigned int, float>,  \
    std::unordered_map<volatile unsigned int, double>,  \
    std::unordered_map<volatile unsigned int, long double>,  \
    std::unordered_map<volatile unsigned int, volatile char>,  \
    std::unordered_map<volatile unsigned int, volatile wchar_t>,  \
    std::unordered_map<volatile unsigned int, volatile char8_t>,  \
    std::unordered_map<volatile unsigned int, volatile char16_t>,  \
    std::unordered_map<volatile unsigned int, volatile char32_t>,  \
    std::unordered_map<volatile unsigned int, volatile short>,  \
    std::unordered_map<volatile unsigned int, volatile int>,  \
    std::unordered_map<volatile unsigned int, volatile long>,  \
    std::unordered_map<volatile unsigned int, volatile long long>,  \
    std::unordered_map<volatile unsigned int, volatile unsigned short>,  \
    std::unordered_map<volatile unsigned int, volatile unsigned int>,  \
    std::unordered_map<volatile unsigned int, volatile unsigned long>,  \
    std::unordered_map<volatile unsigned int, volatile unsigned long long>,  \
    std::unordered_map<volatile unsigned int, volatile float>,  \
    std::unordered_map<volatile unsigned int, volatile double>,  \
    std::unordered_map<volatile unsigned int, volatile long double>,  \
    std::unordered_map<volatile unsigned long, char>,  \
    std::unordered_map<volatile unsigned long, wchar_t>,  \
    std::unordered_map<volatile unsigned long, char8_t>,  \
    std::unordered_map<volatile unsigned long, char16_t>,  \
    std::unordered_map<volatile unsigned long, char32_t>,  \
    std::unordered_map<volatile unsigned long, short>,  \
    std::unordered_map<volatile unsigned long, int>,  \
    std::unordered_map<volatile unsigned long, long>,  \
    std::unordered_map<volatile unsigned long, long long>,  \
    std::unordered_map<volatile unsigned long, unsigned short>,  \
    std::unordered_map<volatile unsigned long, unsigned int>,  \
    std::unordered_map<volatile unsigned long, unsigned long>,  \
    std::unordered_map<volatile unsigned long, unsigned long long>,  \
    std::unordered_map<volatile unsigned long, float>,  \
    std::unordered_map<volatile unsigned long, double>,  \
    std::unordered_map<volatile unsigned long, long double>,  \
    std::unordered_map<volatile unsigned long, volatile char>,  \
    std::unordered_map<volatile unsigned long, volatile wchar_t>,  \
    std::unordered_map<volatile unsigned long, volatile char8_t>,  \
    std::unordered_map<volatile unsigned long, volatile char16_t>,  \
    std::unordered_map<volatile unsigned long, volatile char32_t>,  \
    std::unordered_map<volatile unsigned long, volatile short>,  \
    std::unordered_map<volatile unsigned long, volatile int>,  \
    std::unordered_map<volatile unsigned long, volatile long>,  \
    std::unordered_map<volatile unsigned long, volatile long long>,  \
    std::unordered_map<volatile unsigned long, volatile unsigned short>,  \
    std::unordered_map<volatile unsigned long, volatile unsigned int>,  \
    std::unordered_map<volatile unsigned long, volatile unsigned long>,  \
    std::unordered_map<volatile unsigned long, volatile unsigned long long>,  \
    std::unordered_map<volatile unsigned long, volatile float>,  \
    std::unordered_map<volatile unsigned long, volatile double>,  \
    std::unordered_map<volatile unsigned long, volatile long double>,  \
    std::unordered_map<volatile unsigned long long, char>,  \
    std::unordered_map<volatile unsigned long long, wchar_t>,  \
    std::unordered_map<volatile unsigned long long, char8_t>,  \
    std::unordered_map<volatile unsigned long long, char16_t>,  \
    std::unordered_map<volatile unsigned long long, char32_t>,  \
    std::unordered_map<volatile unsigned long long, short>,  \
    std::unordered_map<volatile unsigned long long, int>,  \
    std::unordered_map<volatile unsigned long long, long>,  \
    std::unordered_map<volatile unsigned long long, long long>,  \
    std::unordered_map<volatile unsigned long long, unsigned short>,  \
    std::unordered_map<volatile unsigned long long, unsigned int>,  \
    std::unordered_map<volatile unsigned long long, unsigned long>,  \
    std::unordered_map<volatile unsigned long long, unsigned long long>,  \
    std::unordered_map<volatile unsigned long long, float>,  \
    std::unordered_map<volatile unsigned long long, double>,  \
    std::unordered_map<volatile unsigned long long, long double>,  \
    std::unordered_map<volatile unsigned long long, volatile char>,  \
    std::unordered_map<volatile unsigned long long, volatile wchar_t>,  \
    std::unordered_map<volatile unsigned long long, volatile char8_t>,  \
    std::unordered_map<volatile unsigned long long, volatile char16_t>,  \
    std::unordered_map<volatile unsigned long long, volatile char32_t>,  \
    std::unordered_map<volatile unsigned long long, volatile short>,  \
    std::unordered_map<volatile unsigned long long, volatile int>,  \
    std::unordered_map<volatile unsigned long long, volatile long>,  \
    std::unordered_map<volatile unsigned long long, volatile long long>,  \
    std::unordered_map<volatile unsigned long long, volatile unsigned short>,  \
    std::unordered_map<volatile unsigned long long, volatile unsigned int>,  \
    std::unordered_map<volatile unsigned long long, volatile unsigned long>,  \
    std::unordered_map<volatile unsigned long long, volatile unsigned long long>,  \
    std::unordered_map<volatile unsigned long long, volatile float>,  \
    std::unordered_map<volatile unsigned long long, volatile double>,  \
    std::unordered_map<volatile unsigned long long, volatile long double>,  \
    std::unordered_map<volatile float, char>,  \
    std::unordered_map<volatile float, wchar_t>,  \
    std::unordered_map<volatile float, char8_t>,  \
    std::unordered_map<volatile float, char16_t>,  \
    std::unordered_map<volatile float, char32_t>,  \
    std::unordered_map<volatile float, short>,  \
    std::unordered_map<volatile float, int>,  \
    std::unordered_map<volatile float, long>,  \
    std::unordered_map<volatile float, long long>,  \
    std::unordered_map<volatile float, unsigned short>,  \
    std::unordered_map<volatile float, unsigned int>,  \
    std::unordered_map<volatile float, unsigned long>,  \
    std::unordered_map<volatile float, unsigned long long>,  \
    std::unordered_map<volatile float, float>,  \
    std::unordered_map<volatile float, double>,  \
    std::unordered_map<volatile float, long double>,  \
    std::unordered_map<volatile float, volatile char>,  \
    std::unordered_map<volatile float, volatile wchar_t>,  \
    std::unordered_map<volatile float, volatile char8_t>,  \
    std::unordered_map<volatile float, volatile char16_t>,  \
    std::unordered_map<volatile float, volatile char32_t>,  \
    std::unordered_map<volatile float, volatile short>,  \
    std::unordered_map<volatile float, volatile int>,  \
    std::unordered_map<volatile float, volatile long>,  \
    std::unordered_map<volatile float, volatile long long>,  \
    std::unordered_map<volatile float, volatile unsigned short>,  \
    std::unordered_map<volatile float, volatile unsigned int>,  \
    std::unordered_map<volatile float, volatile unsigned long>,  \
    std::unordered_map<volatile float, volatile unsigned long long>,  \
    std::unordered_map<volatile float, volatile float>,  \
    std::unordered_map<volatile float, volatile double>,  \
    std::unordered_map<volatile float, volatile long double>,  \
    std::unordered_map<volatile double, char>,  \
    std::unordered_map<volatile double, wchar_t>,  \
    std::unordered_map<volatile double, char8_t>,  \
    std::unordered_map<volatile double, char16_t>,  \
    std::unordered_map<volatile double, char32_t>,  \
    std::unordered_map<volatile double, short>,  \
    std::unordered_map<volatile double, int>,  \
    std::unordered_map<volatile double, long>,  \
    std::unordered_map<volatile double, long long>,  \
    std::unordered_map<volatile double, unsigned short>,  \
    std::unordered_map<volatile double, unsigned int>,  \
    std::unordered_map<volatile double, unsigned long>,  \
    std::unordered_map<volatile double, unsigned long long>,  \
    std::unordered_map<volatile double, float>,  \
    std::unordered_map<volatile double, double>,  \
    std::unordered_map<volatile double, long double>,  \
    std::unordered_map<volatile double, volatile char>,  \
    std::unordered_map<volatile double, volatile wchar_t>,  \
    std::unordered_map<volatile double, volatile char8_t>,  \
    std::unordered_map<volatile double, volatile char16_t>,  \
    std::unordered_map<volatile double, volatile char32_t>,  \
    std::unordered_map<volatile double, volatile short>,  \
    std::unordered_map<volatile double, volatile int>,  \
    std::unordered_map<volatile double, volatile long>,  \
    std::unordered_map<volatile double, volatile long long>,  \
    std::unordered_map<volatile double, volatile unsigned short>,  \
    std::unordered_map<volatile double, volatile unsigned int>,  \
    std::unordered_map<volatile double, volatile unsigned long>,  \
    std::unordered_map<volatile double, volatile unsigned long long>,  \
    std::unordered_map<volatile double, volatile float>,  \
    std::unordered_map<volatile double, volatile double>,  \
    std::unordered_map<volatile double, volatile long double>,  \
    std::unordered_map<volatile long double, char>,  \
    std::unordered_map<volatile long double, wchar_t>,  \
    std::unordered_map<volatile long double, char8_t>,  \
    std::unordered_map<volatile long double, char16_t>,  \
    std::unordered_map<volatile long double, char32_t>,  \
    std::unordered_map<volatile long double, short>,  \
    std::unordered_map<volatile long double, int>,  \
    std::unordered_map<volatile long double, long>,  \
    std::unordered_map<volatile long double, long long>,  \
    std::unordered_map<volatile long double, unsigned short>,  \
    std::unordered_map<volatile long double, unsigned int>,  \
    std::unordered_map<volatile long double, unsigned long>,  \
    std::unordered_map<volatile long double, unsigned long long>,  \
    std::unordered_map<volatile long double, float>,  \
    std::unordered_map<volatile long double, double>,  \
    std::unordered_map<volatile long double, long double>,  \
    std::unordered_map<volatile long double, volatile char>,  \
    std::unordered_map<volatile long double, volatile wchar_t>,  \
    std::unordered_map<volatile long double, volatile char8_t>,  \
    std::unordered_map<volatile long double, volatile char16_t>,  \
    std::unordered_map<volatile long double, volatile char32_t>,  \
    std::unordered_map<volatile long double, volatile short>,  \
    std::unordered_map<volatile long double, volatile int>,  \
    std::unordered_map<volatile long double, volatile long>,  \
    std::unordered_map<volatile long double, volatile long long>,  \
    std::unordered_map<volatile long double, volatile unsigned short>,  \
    std::unordered_map<volatile long double, volatile unsigned int>,  \
    std::unordered_map<volatile long double, volatile unsigned long>,  \
    std::unordered_map<volatile long double, volatile unsigned long long>,  \
    std::unordered_map<volatile long double, volatile float>,  \
    std::unordered_map<volatile long double, volatile double>

