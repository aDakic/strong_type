#include "strong_type/static_string.hpp"

#include "catch2/catch_all.hpp"

TEST_CASE("Test static string", "[static_string]")
{
    constexpr strong_type::static_string str{ "string" };

    STATIC_REQUIRE(str.value_.size() == 7);

    STATIC_REQUIRE(str.value_[0] == 's');
    STATIC_REQUIRE(str.value_[1] == 't');
    STATIC_REQUIRE(str.value_[2] == 'r');
    STATIC_REQUIRE(str.value_[3] == 'i');
    STATIC_REQUIRE(str.value_[4] == 'n');
    STATIC_REQUIRE(str.value_[5] == 'g');
    STATIC_REQUIRE(str.value_[6] == '\0');
}