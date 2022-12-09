#pragma once

#include <random>

namespace eqx
{
	/**
	 * @brief Random Number Generator API
	 */
	class Random
	{
	public:
		Random(const Random& r) = delete;
		void operator =(const Random& r) = delete;

		/**
		 * @brief Generate A Random Integer
		 * 
		 * @param lowerBound Lowest Possible Value
		 * @param upperBound Highest Possible Value
		 * @returns Random Integer
		 */
		static int randInt(int lowerBound, int upperBound);

		/**
		 * @brief Generate A Random Double
		 * 
		 * @param lowerBound Lowest Possible Value
		 * @param upperBound Highest Possible Value
		 * @returns Random Double
		*/
		static double randDouble(double lowerBound, double upperBound);

		/**
		 * @brief Generate A Random Seed
		 * 
		 * @returns Seed
		*/
		static unsigned int generateSeed();

	private:
		Random();

		static Random& getInstance();

		std::default_random_engine engine;
		std::uniform_int_distribution<int> uniInt;
		std::uniform_real_distribution<double> uniDouble;
	};
}