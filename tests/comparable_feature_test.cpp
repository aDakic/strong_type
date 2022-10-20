#include "catch2/catch_all.hpp"
#include "strong_type/strong_type.hpp"

TEST_CASE("Test comparability of the two strong types", "[strong_type_comparable]")
{
    using integer_t = strong_type::strong_type<int, struct comparable_st_tag, strong_type::comparable>;

    integer_t one{ 1 };
    integer_t two{ 2 };
    integer_t three{ 3 };

    REQUIRE(one == integer_t{ 1 });
    REQUIRE(one != three);
    REQUIRE(one < three);
    REQUIRE(three > two);
    REQUIRE(one <= two);
    REQUIRE(three >= two);
}