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
		/**
		 * Pure Static Class Is Not Ment To Be Constructed Or Copied
		 */
		Random() = delete;
		Random(const Random& r) = delete;
		Random(Random&&) = delete;
		void operator= (const Random&) = delete;
		Random& operator= (Random&&) = delete;
		~Random() = delete;

		/**
		 * @brief Generate A Random Integer
		 * 
		 * @param lowerBound Lowest Possible Value
		 * @param upperBound Highest Possible Value
		 * 
		 * @returns Random Integer In Range [lowerBound, upperBound]
		 */
		static int randInt(int lowerBound, int upperBound);

		/**
		 * @brief Generate A Random Unsigned Integer
		 *
		 * @param lowerBound Lowest Possible Value
		 * @param upperBound Highest Possible Value
		 * 
		 * @returns Random Unsigned Integer In Range [lowerBound, upperBound]
		 */
		static unsigned int randUnsignedInt(unsigned int lowerBound, 
			unsigned int upperBound);

		/**
		 * @brief Generate A Random Double
		 * 
		 * @param lowerBound Lowest Possible Value
		 * @param upperBound Highest Possible Value
		 * 
		 * @returns Random Double In Range [lowerBound, upperBound]
		*/
		static double randDouble(double lowerBound, double upperBound);

		/**
		 * @brief Simulate A Coin Flip
		 * 
		 * @returns Either 1 Or 0
		 */
		static int flipCoin();

		/**
		 * @brief Simulate A Dice Roll
		 * 
		 * @param sides Number Of Sides On The Dice
		 * 
		 * @returns An Unsigned Int In Range [1, sides]
		 */
		static unsigned int rollDice(unsigned int sides = 6);

		/**
		 * @brief Generate A Random Seed
		 * 
		 * @returns Seed
		*/
		static unsigned int generateSeed();

	private:
		static std::mt19937_64 s_Engine;
		static std::uniform_int_distribution<int> s_UniInt;
		static std::uniform_int_distribution<unsigned int> s_UniUInt;
		static std::uniform_real_distribution<double> s_UniDouble;
	};
}