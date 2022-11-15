#include "catch2/catch_all.hpp"
#include "strong_type/strong_type.hpp"

TEST_CASE("Test logical and of the two strong types", "[strong_type_bitwiseable]")
{
    using integer_t = strong_type::strong_type<int, "integer_t", strong_type::bitwiseable>;

    integer_t zero{ 0 };
    integer_t one{ 1 };

    bool result = one & zero;
    REQUIRE_FALSE(result);
}

TEST_CASE("Test logical or of the two strong types", "[strong_type_bitwiseable]")
{
    using integer_t = strong_type::strong_type<int, "integer_t", strong_type::bitwiseable>;

    integer_t one{ 1 };

    bool result = one & integer_t{ 1 };
    REQUIRE(result);
}

TEST_CASE("Test logical xor of the two strong types", "[strong_type_bitwiseable]")
{
    using integer_t = strong_type::strong_type<int, "integer_t", strong_type::bitwiseable>;

    integer_t one{ 1 };

    bool result = one ^ integer_t { 1 };
    REQUIRE_FALSE(result);
}