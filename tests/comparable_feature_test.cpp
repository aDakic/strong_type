#include <gtest/gtest.h>
#include "strong_type/strong_type.h"

TEST(test_st, comparable_traits)
{
    using comparable_st = strong_type::strong_type<int, struct comparable_st_tag, strong_type::comparable>;

    ASSERT_EQ(comparable_st(1), comparable_st(1));
    ASSERT_NE(comparable_st(1), comparable_st(5));
    ASSERT_GE(comparable_st(5), comparable_st(1));
    ASSERT_GT(comparable_st(5), comparable_st(1));
    ASSERT_LE(comparable_st(1), comparable_st(5));
    ASSERT_LT(comparable_st(1), comparable_st(5));
}