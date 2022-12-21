#include "Random.h"

#include "Log.h"
#include "Mathematics.h"

namespace eqx
{
	int Random::randInt(int lowerBound, int upperBound)
	{
		if (lowerBound >= upperBound)
		{
			eqx::Log::log(Log::Level::error, "Lower Bound Larger Than Upper Bound!", eqx::Log::Type::runtimeError);
			return 0;
		}
		else
		{
			Random::getInstance().uniInt = std::uniform_int_distribution<int>(lowerBound, upperBound);
			return Random::getInstance().uniInt(Random::getInstance().engine);
		}
	}

	unsigned int Random::randUnsignedInt(unsigned int lowerBound, unsigned int upperBound)
	{
		if (lowerBound >= upperBound)
		{
			eqx::Log::log(Log::Level::error, "Lower Bound Larger Than Upper Bound!", eqx::Log::Type::runtimeError);
			return 0U;
		}
		else
		{
			Random::getInstance().uniUInt = std::uniform_int_distribution<unsigned int>(lowerBound, upperBound);
			return Random::getInstance().uniUInt(Random::getInstance().engine);
		}
	}

	double Random::randDouble(double lowerBound, double upperBound)
	{
		if (lowerBound >= upperBound)
		{
			eqx::Log::log(Log::Level::error, "Lower Bound Larger Than Upper Bound!", eqx::Log::Type::runtimeError);
			return 0.0;
		}
		else if (lowerBound <= 0.0 && upperBound <= 0.0 ||
				 lowerBound >= 0.0 && upperBound >= 0.0)
		{
			double newBound = 0.0;
			double generatedNumber = 0.0;
			if (upperBound == std::numeric_limits<double>::max())
			{
				newBound = std::nexttoward(lowerBound, std::numeric_limits<double>::lowest());
				Random::getInstance().uniDouble = std::uniform_real_distribution<double>(newBound, upperBound);
				generatedNumber = Random::getInstance().uniDouble(Random::getInstance().engine);
				if (generatedNumber == newBound)
				{
					return std::numeric_limits<double>::max();
				}
				else
				{
					return generatedNumber;
				}
			}
			else if (lowerBound == std::numeric_limits<double>::lowest() && upperBound == 0.0)
			{
				return randDouble(lowerBound, std::nexttoward(upperBound, std::numeric_limits<double>::max()));
			}
			else
			{
				newBound = std::nexttoward(upperBound, std::numeric_limits<double>::max());
				Random::getInstance().uniDouble = std::uniform_real_distribution<double>(lowerBound, newBound);
				generatedNumber = Random::getInstance().uniDouble(Random::getInstance().engine);
				return generatedNumber;
			}
		}
		else if (lowerBound <= 0.0 && upperBound >= 0.0)
		{
			double offset = (-lowerBound - upperBound) / 2.0;
			double negVal = randDouble(lowerBound + offset, 0.0);
			double posVal = randDouble(std::nexttoward(0.0, std::numeric_limits<double>::max()), upperBound + offset);
			return (flipCoin() ? negVal : posVal) - offset;
		}
		else
		{
			eqx::Log::log(eqx::Log::Level::error, "randDouble should not reach this condition", eqx::Log::Type::unreachableCodeError);
			return 0.0;
		}
	}

	int Random::flipCoin()
	{
		return randInt(0, 1);
	}

	unsigned int Random::rollDice(unsigned int sides)
	{
		if (sides == 0U || sides == 1U)
		{
			eqx::Log::log(eqx::Log::Level::error, "Dice should have at least two sides", eqx::Log::Type::runtimeError);
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

	Random::Random()
		:
		engine(Random::generateSeed()),
		uniInt(),
		uniUInt(),
		uniDouble()
	{

	}

	Random& Random::getInstance()
	{
		static Random instance;
		return instance;
	}
}