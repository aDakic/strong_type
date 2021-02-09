#pragma once

#include "s_type.h"
#include "s_type_traits.h"

namespace strong_type
{
    namespace details
    {
        template <typename T, typename otherOperandT = T, typename ReturnT = T>
        struct subtractable
        {
            friend constexpr ReturnT operator-(const T &lhs, const otherOperandT &rhs) noexcept
            {
                return ReturnT(lhs.get() - strip(rhs));
            }
        };
    }

    struct subtractable
    {
        template <typename T>
        using type = details::subtractable<T>;
    };

    template <typename OtherOperand>
    struct subtractable_to
    {
        template <typename T>
        using type = details::subtractable<T, OtherOperand>;
    };
}
