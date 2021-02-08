#pragma once

#include "s_type.h"
#include "s_type_traits.h"

namespace strong_type
{
    namespace details
    {
        template <typename T, typename otherOperandT = T, typename ReturnT = T>
        struct addable
        {
            friend constexpr ReturnT operator+(const T &lhs, const otherOperandT &rhs) noexcept
            {
                return ReturnT(lhs.get() + strip(rhs));
            }
        };
    }
}