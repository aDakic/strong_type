#include "catch2/catch_all.hpp"
#include "strong_type/strong_type.hpp"

TEST_CASE("Test difference of the two strong types", "[strong_type_subtractable]")
{
    using integer_t = strong_type::strong_type<int, "integer_t", strong_type::subtractable>;

    integer_t two = integer_t{ 4 } - integer_t{ 2 };
    REQUIRE(two.get() == 2);
}

TEST_CASE("Test sum of the strong type and integer", "[strong_type_subtractable]")
{
    using integer_t =
        strong_type::strong_type<int, "integer_t", strong_type::subtractable, strong_type::subtractable_to<int>>;

    integer_t one{ 1 };
    integer_t zero = one - 1;
    REQUIRE(zero.get() == 0);

    integer_t two = 3 - one;
    REQUIRE(two.get() == 2);
}