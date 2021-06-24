#include <gtest/gtest.h>
#include "strong_type/strong_type.h"

TEST(test_st, addable_traits)
{
    using integer_t = strong_type::strong_type<int, struct addable_st_tag,  strong_type::addable,
                                                                            strong_type::addable_with<int>>;

    integer_t two (integer_t(1) + integer_t(1));
    //ASSERT_EQ(two.get(), 2);

    //ASSERT_EQ(integer_t(1).get() + 1, 2);

    //integer_t tree(two + 1);
    //ASSERT_EQ(tree.get(), 3);

    //integer_t four = 2 + two;
    //ASSERT_EQ(four.get(), 4);
}