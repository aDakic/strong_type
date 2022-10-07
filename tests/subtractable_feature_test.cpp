#include <gtest/gtest.h>

#include "strong_type/strong_type.h"

TEST(test_st, subtractable_traits)
{
    using int_t = strong_type::strong_type<int, struct subtractable_st_tag, strong_type::subtractable,
                                           strong_type::subtractable_to<int>>;

    int_t two(int_t(3) - int_t(1));
    ASSERT_EQ(two.get(), 2);

    ASSERT_EQ(int_t(3).get() - 1, 2);

    int_t one(two - 1);
    ASSERT_EQ(one.get(), 1);

    int_t four = 5 - int_t(1);
    ASSERT_EQ(four.get(), 4);
}