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

#include "eqx_Random.hpp"

namespace eqx::Random
{
	std::mt19937_64 p_engine(generateSeed());

	unsigned int flipCoin()
	{
		return randomNumber(0, 1);
	}

	unsigned int rollDice(unsigned int sides)
	{
		eqx::runtimeAssert(sides > 2U,
			"Dice Should Have At Least 3 Sides!");

		return randomNumber(1U, sides);
	}

	unsigned int generateSeed()
	{
		static std::random_device rd;
		return static_cast<unsigned int>(rd());
	}
}