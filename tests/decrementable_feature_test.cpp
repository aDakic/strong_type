#include <gtest/gtest.h>

#include "strong_type/strong_type.h"

TEST(test_st, decrementable_traits)
{
    using int_t =
        strong_type::strong_type<int, struct decrementable_st_tag, strong_type::comparable, strong_type::decrementable>;

    int_t number(4);
    int_t two(2);
    int_t three(3);
    int_t four(4);

    ASSERT_EQ(number--, four);
    ASSERT_EQ(number, three);
    ASSERT_EQ(--number, two);
}