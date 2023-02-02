#include "Random.h"

#include "Log.h"
#include "Mathematics.h"

namespace eqx
{
	std::mt19937_64 Random::s_Engine{ generateSeed() };
	std::uniform_int_distribution<int> Random::s_UniInt;
	std::uniform_int_distribution<unsigned int> Random::s_UniUInt;
	std::uniform_real_distribution<double> Random::s_UniDouble;

	int Random::randInt(int lowerBound, int upperBound)
	{
		if (lowerBound >= upperBound)
		{
			eqx::Log::log(Log::Level::error, 
				"Lower Bound Larger Than Upper Bound!", 
				eqx::Log::Type::runtimeError);
			return 0;
		}
		else
		{
			if (lowerBound != s_UniInt.min() || upperBound != s_UniInt.max())
			{
				s_UniInt = 
					std::uniform_int_distribution<int>(lowerBound, upperBound);
			}
			return s_UniInt(s_Engine);
		}
	}

	unsigned int Random::randUnsignedInt(unsigned int lowerBound, 
		unsigned int upperBound)
	{
		if (lowerBound >= upperBound)
		{
			eqx::Log::log(Log::Level::error, 
				"Lower Bound Larger Than Upper Bound!", 
				eqx::Log::Type::runtimeError);
			return 0U;
		}
		else
		{
			s_UniUInt = 
				std::uniform_int_distribution<unsigned int>(
					lowerBound, upperBound);
			return s_UniUInt(s_Engine);
		}
	}

	double Random::randDouble(double lowerBound, double upperBound)
	{
		if (lowerBound >= upperBound)
		{
			eqx::Log::log(Log::Level::error, 
				"Lower Bound Larger Than Upper Bound!", 
				eqx::Log::Type::runtimeError);
			return 0.0;
		}
		else if (lowerBound <= 0.0 && upperBound <= 0.0 ||
				 lowerBound >= 0.0 && upperBound >= 0.0)
		{
			double newBound = 0.0;
			double generatedNumber = 0.0;
			if (upperBound == std::numeric_limits<double>::max() &&
				lowerBound == 0.0)
			{
				newBound = 
					std::nexttoward(lowerBound, 
						std::numeric_limits<double>::lowest());
				s_UniDouble = 
					std::uniform_real_distribution<double>(newBound, 
						upperBound);
				generatedNumber = s_UniDouble(s_Engine);
				if (generatedNumber == newBound)
				{
					return std::numeric_limits<double>::max();
				}
				else
				{
					return generatedNumber;
				}
			}
			else if (lowerBound == std::numeric_limits<double>::lowest() && 
					 upperBound == 0.0)
			{
				return randDouble(lowerBound, 
					std::nexttoward(upperBound, 
						std::numeric_limits<double>::max()));
			}
			else
			{
				newBound = 
					std::nexttoward(upperBound, 
						std::numeric_limits<double>::max());
				s_UniDouble = 
					std::uniform_real_distribution<double>(lowerBound, 
						newBound);
				generatedNumber = s_UniDouble(s_Engine);
				return generatedNumber;
			}
		}
		else if (lowerBound <= 0.0 && upperBound >= 0.0)
		{
			double offset = (-lowerBound - upperBound) / 2.0;
			double negVal = randDouble(lowerBound + offset, 0.0);
			double posVal = 
				randDouble(std::nexttoward(0.0, 
					std::numeric_limits<double>::max()), upperBound + offset);
			return (flipCoin() ? negVal : posVal) - offset;
		}
		else
		{
			eqx::Log::log(eqx::Log::Level::error, 
				"randDouble should not reach this condition", 
				eqx::Log::Type::unreachableCodeError);
			return 0.0;
		}
	}

	int Random::flipCoin()
	{
		return randInt(0, 1);
	}

	unsigned int Random::rollDice(unsigned int sides)
	{
		if (sides < 2U)
		{
			eqx::Log::log(eqx::Log::Level::warning, 
				"Dice should have at least two side", 
				eqx::Log::Type::runtimeWarning);
			return 0U;
		}
		else
		{
			return randUnsignedInt(1U, sides);
		}
		
	}

	unsigned int Random::generateSeed()
	{
		static std::random_device rd;
		return rd();
	}
}