#pragma once

#include <random>

namespace eqx
{
	class Random
	{
	public:
		Random(const Random& r) = delete;
		void operator= (const Random& r) = delete;

		static int randInt(int lowerBound, int upperBound);
		static double randDouble(double lowerBound, double upperBound);

		static unsigned int generateSeed();

	private:
		Random();

		static Random& getInstance();

		std::default_random_engine engine;
		std::uniform_int_distribution<int> uniInt;
		std::uniform_real_distribution<double> uniDouble;
	};
}