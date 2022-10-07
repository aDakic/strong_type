#include "catch2/catch_all.hpp"
#include "strong_type/strong_type.h"

TEST_CASE("Test the division of two strong types", "[strong_type_dividable]")
{
    using integer_t = strong_type::strong_type<int, struct dividable_st_tag, strong_type::dividable>;
    integer_t two{ 2 };
    integer_t four{ 4 };

    integer_t result = four / two;
    REQUIRE(result.get() == 2);
}

TEST_CASE("Test the division of the strong type and integer", "[strong_type_dividable]")
{
    using integer_t =
        strong_type::strong_type<int, struct dividable_st_tag, strong_type::dividable, strong_type::dividable_by<int>>;

    integer_t four{ 4 };
    integer_t result = four / 2;
    REQUIRE(result.get() == 2);

    integer_t two{ 2 };
    integer_t result_2 = 4 / two;
    REQUIRE(result_2.get() == 2);
}