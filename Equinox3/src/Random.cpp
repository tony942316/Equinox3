#include "Random.h"

#include <chrono>

namespace eqx
{
	int Random::randInt(int lowerBound, int upperBound)
	{
		Random::getInstance().uniInt = std::uniform_int_distribution<int>(lowerBound, upperBound);
		return Random::getInstance().uniInt(Random::getInstance().engine);
	}

	double Random::randDouble(double lowerBound, double upperBound)
	{
		Random::getInstance().uniDouble = std::uniform_real_distribution<double>(lowerBound, upperBound);
		return Random::getInstance().uniDouble(Random::getInstance().engine);
	}

	unsigned int Random::generateSeed()
	{
		return static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());
	}

	Random::Random()
		:
		engine(Random::generateSeed()),
		uniInt(),
		uniDouble()
	{

	}

	Random& Random::getInstance()
	{
		static Random instance;
		return instance;
	}
}