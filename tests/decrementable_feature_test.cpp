#include "catch2/catch_all.hpp"
#include "strong_type/strong_type.h"

TEST_CASE("Test decrement operator of the strong type", "[strong_type_decrementable]")
{
    using integer_t =
        strong_type::strong_type<int, struct decrementable_st_tag, strong_type::comparable, strong_type::decrementable>;

    integer_t number{ 4 };
    integer_t two{ 2 };
    integer_t three{ 3 };
    integer_t four{ 4 };

    REQUIRE(number-- == four);
    REQUIRE(number == three);
    REQUIRE(--number == two);
}