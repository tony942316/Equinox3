#include "Random.hpp"

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