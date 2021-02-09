#include <gtest/gtest.h>
#include "strong_type/strong_type.h"

TEST(test_st, subtractable_traits)
{
    using long_t = strong_type::strong_type<long, struct subtractable_st_tag, strong_type::subtractable,
                                                                              strong_type::subtractable_to<long>>;

    long_t two (long_t(3) - long_t(1));
    ASSERT_EQ(two.get(), 2);

    ASSERT_EQ(long_t(3).get() - 1, 2);

    long_t tree(5 - two.get());
    ASSERT_EQ(tree.get(), 3);
}