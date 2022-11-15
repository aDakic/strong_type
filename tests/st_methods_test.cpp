#include "catch2/catch_all.hpp"
#include "strong_type/strong_type.hpp"

TEST_CASE("Test get methods of strong type", "[strong_type_methods]")
{
    using integer_t = strong_type::strong_type<int, "integer_t">;

    integer_t number{ 3 };
    const integer_t const_num{ 4 };

    STATIC_CHECK(std::is_same_v<decltype(number.get()), int&>);
    STATIC_CHECK(std::is_same_v<decltype(const_num.get()), const int&>);
    STATIC_CHECK(std::is_same_v<decltype(integer_t{ 5 }.get()), int&&>);

    REQUIRE(number.get() == 3);
    REQUIRE(const_num.get() == 4);
    REQUIRE(integer_t{ 5 }.get() == 5);
}

TEST_CASE("Test get methods of strong type in compile time", "[strong_type_methods]")
{
    using integer_t = strong_type::strong_type<int, "integer_t">;

    constexpr integer_t number{ 3 };
    STATIC_REQUIRE(number.get() == 3);
}