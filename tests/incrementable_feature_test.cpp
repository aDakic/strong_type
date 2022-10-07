#include <gtest/gtest.h>

#include "strong_type/strong_type.h"

TEST(test_st, incrementable_traits)
{
    using int_t =
        strong_type::strong_type<int, struct incrementable_st_tag, strong_type::comparable, strong_type::incrementable>;

    int_t number(4);
    int_t four(4);
    int_t five(5);
    int_t six(6);

    ASSERT_EQ(number++, four);
    ASSERT_EQ(number, five);
    ASSERT_EQ(++number, six);
}