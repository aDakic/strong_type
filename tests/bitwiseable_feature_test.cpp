#include <gtest/gtest.h>

#include "strong_type/strong_type.h"

TEST(test_st, bitable_traits)
{
    using short_t = strong_type::strong_type<short, struct bitwiseable_st_tag, strong_type::bitwiseable>;

    short_t zero(short_t(1) & short_t(0));
    ASSERT_EQ(zero.get(), 0);

    short_t one(short_t(1) | short_t(1));
    ASSERT_EQ(one.get(), 1);

    short_t zeroo(short_t(1) ^ short_t(1));
    ASSERT_EQ(zeroo.get(), 0);
}