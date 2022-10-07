#include <gtest/gtest.h>

#include "strong_type/strong_type.h"

TEST(test_st, multiplicable_traits)
{
    using long_t = strong_type::strong_type<long, struct multiplicable_st_tag, strong_type::multiplicable,
                                            strong_type::multiplicable_with<long>>;

    long_t four(long_t(2) * long_t(2));
    ASSERT_EQ(four.get(), 4);

    ASSERT_EQ(long_t(3).get() * 2, 6);

    long_t nine(long_t(3) * 3);
    ASSERT_EQ(nine.get(), 9);

    long_t sixteen = 4 * four;
    ASSERT_EQ(sixteen.get(), 16);
}