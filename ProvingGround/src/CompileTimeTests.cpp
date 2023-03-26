#include "AuxMacros.hpp"

#include "Misc.hpp"

CONCEPT_CTG(constRange)
CONCEPT_CTG(stringable)
CONCEPT_CTG(stringType)

void testMiscConcepts()
{
	constexpr auto constRangeTest =
		constRangeCTG<ALL_PRIMITIVES, ALL_STD_NONRANGE_COLLECTIONS>(false) &&
		constRangeCTG<ALL_STD_RANGE_COLLECTIONS>(true);
	constexpr auto stringableTest =
		stringableCTG<ALL_STD_COLLECTIONS>(false) &&
		stringableCTG<ALL_PRIMITIVES>(true);
	constexpr auto stringTypeTest =
		stringTypeCTG<ALL_PRIMITIVES, ALL_STD_COLLECTIONS>(false) &&
		stringTypeCTG<ALL_STD_STRINGS>(true);

	static_assert(constRangeTest);
	static_assert(stringableTest);
	static_assert(stringTypeTest);
}