#include "catch2/catch_all.hpp"
#include "strong_type/strong_type.h"

TEST_CASE("Test the multiplication of two strong types", "[strong_type_multiplicable]")
{
    using integer_t = strong_type::strong_type<int, struct multiplicable_st_tag, strong_type::multiplicable>;
    integer_t one{ 1 };
    integer_t two{ 2 };

    integer_t result = one * two;
    REQUIRE(result.get() == 2);
}

TEST_CASE("Test the multiplication of the strong type and integer", "[strong_type_multiplicable]")
{
    using integer_t = strong_type::strong_type<int, struct multiplicable_st_tag, strong_type::multiplicable,
                                               strong_type::multiplicable_with<int>>;

    integer_t two{ 2 };

    integer_t result = 2 * two;
    REQUIRE(result.get() == 4);

    integer_t result1 = two * 2;
    REQUIRE(result1.get() == 4);
}