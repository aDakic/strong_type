#pragma once

#include "s_type_traits.h"

namespace strong_type
{
    namespace details
    {
        template<typename T, typename otherOperandT = T, typename ReturnT = T>
        struct subtractable
        {
            friend constexpr ReturnT operator-(const T &lhs, const otherOperandT &rhs) noexcept
            {
                return ReturnT(lhs.get() - strip(rhs));
            }

            template<typename U = T, typename otherOperandU = otherOperandT,
                     typename = std::enable_if_t<!std::is_same_v<U, otherOperandU>>>
            friend constexpr ReturnT operator-(const otherOperandT &lhs, const T &rhs) noexcept
            {
                return ReturnT(strip(lhs) - rhs.get());
            }
        };
    }  // namespace details

    struct subtractable
    {
        template<typename T>
        using type = details::subtractable<T>;
    };

    template<typename OtherOperand>
    struct subtractable_to
    {
        template<typename T>
        using type = details::subtractable<T, OtherOperand>;
    };
}  // namespace strong_type
