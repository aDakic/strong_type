#include "catch2/catch_all.hpp"
#include "strong_type/strong_type.hpp"

TEST_CASE("Test increment operator of the strong type", "[strong_type_incrementable]")
{
    using integer_t =
        strong_type::strong_type<int, struct incrementable_st_tag, strong_type::comparable, strong_type::incrementable>;

    integer_t number{ 1 };
    integer_t one{ 1 };
    integer_t two{ 2 };
    integer_t three{ 3 };

    REQUIRE(number++ == one);
    REQUIRE(number == two);
    REQUIRE(++number == three);
}