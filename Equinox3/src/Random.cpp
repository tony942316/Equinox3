#include "Random.hpp"

#include "Misc.hpp"

namespace eqx
{
	std::mt19937_64 Random::s_Engine(generateSeed());
	std::uniform_int_distribution<int> Random::s_UniInt;
	std::uniform_int_distribution<unsigned int> Random::s_UniUInt;
	std::uniform_real_distribution<double> Random::s_UniDouble;

	int Random::randInt(int lowerBound, int upperBound)
	{
		eqx_dynamic_assert(upperBound >= lowerBound, 
			"Lower Bound Is Larger Than UpperBound!");

		if (lowerBound != s_UniInt.min() || upperBound != s_UniInt.max())
		{
			s_UniInt = 
				std::uniform_int_distribution<int>(lowerBound, upperBound);
		}
		return s_UniInt(s_Engine);
	}

	unsigned int Random::randUnsignedInt(unsigned int lowerBound, 
		unsigned int upperBound)
	{
		eqx_dynamic_assert(upperBound >= lowerBound,
			"Lower Bound Larger Than Upper Bound!");

		if (lowerBound != s_UniUInt.min() || upperBound != s_UniUInt.max())
		{
			s_UniUInt = std::uniform_int_distribution<unsigned int>(
				lowerBound, upperBound);
		}
		return s_UniUInt(s_Engine);
	}

	double Random::randDouble(double lowerBound, double upperBound)
	{
		eqx_dynamic_assert(upperBound >= lowerBound,
			"Lower Bound Is Larger Than UpperBound!");

		if (lowerBound >= 0.0 && upperBound >= 0.0)
		{
			double decoyValue = std::nexttoward(lowerBound,
				std::numeric_limits<double>::lowest());
			s_UniDouble = std::uniform_real_distribution<double>(
				decoyValue, upperBound);
			double producedValue = s_UniDouble(s_Engine);
			if (producedValue == decoyValue)
			{
				return upperBound;
			}
			else
			{
				return producedValue;
			}
		}
		else if (lowerBound <= 0.0 && upperBound <= 0.0)
		{
			return -randDouble(-upperBound, -lowerBound);
		}
		else if (lowerBound < 0.0 && upperBound > 0.0)
		{
			double offset = -upperBound - lowerBound;
			if (flipCoin())
			{
				return randDouble(lowerBound + offset, 0.0) - offset;
			}
			else
			{
				return randDouble(0.0, upperBound + offset) - offset;
			}
		}
		else
		{
			eqx_dynamic_assert(false, "Code Should Never Reach This!");
			return 0.0;
		}
	}

	int Random::flipCoin()
	{
		return randInt(0, 1);
	}

	unsigned int Random::rollDice(unsigned int sides)
	{
		eqx_dynamic_assert(sides >= 2U,
			"A Dice Should Have At Least Two Sides!");

		return randUnsignedInt(1U, sides);
	}

	unsigned int Random::generateSeed()
	{
		static std::random_device rd;
		return rd();
	}
}