#include <gtest/gtest.h>
#include "strong_type/strong_type.h"

TEST(test_st, dividable_traits)
{
    using int_t = strong_type::strong_type<int, struct dividable_st_tag, strong_type::dividable,
                                                                          strong_type::dividable_by<int>>;

    int_t four (int_t(8) / int_t(2));
    ASSERT_EQ(four.get(), 4);

    ASSERT_EQ(int_t(12).get() / 2, 6);

    int_t nine(int_t(27) / 3);
    ASSERT_EQ(nine.get(), 9);
}