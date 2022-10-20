#include "catch2/catch_all.hpp"
#include "strong_type/strong_type.hpp"

TEST_CASE("Test sum of the two strong types", "[strong_type_addable]")
{
    using integer_t = strong_type::strong_type<int, struct addable_st_tag, strong_type::addable>;

    integer_t two = integer_t{ 1 } + integer_t{ 1 };
    REQUIRE(two.get() == 2);
}

TEST_CASE("Test sum of the strong type and integer", "[strong_type_addable]")
{
    using integer_t =
        strong_type::strong_type<int, struct addable_st_tag, strong_type::addable, strong_type::addable_with<int>>;

    integer_t one{ 1 };
    integer_t two = one + 1;
    REQUIRE(two.get() == 2);

    integer_t tree = 1 + two;
    REQUIRE(tree.get() == 3);
}