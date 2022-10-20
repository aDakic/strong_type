#pragma once

#include "strip.hpp"

namespace strong_type
{
    namespace details
    {
        template<typename T, typename otherOperandT = T, typename ReturnT = T>
        struct multiplicable
        {
            friend constexpr ReturnT operator*(const T &lhs, const otherOperandT &rhs) noexcept
            {
                return ReturnT(lhs.get() * strip(rhs));
            }

            template<typename U = T, typename otherOperandU = otherOperandT,
                     typename = std::enable_if_t<!std::is_same_v<U, otherOperandU>>>
            friend constexpr ReturnT operator*(const otherOperandT &lhs, const T &rhs) noexcept
            {
                return ReturnT(strip(lhs) * rhs.get());
            }
        };
    }  // namespace details

    struct multiplicable
    {
        template<typename T>
        using type = details::multiplicable<T>;
    };

    template<typename OtherOperand>
    struct multiplicable_with
    {
        template<typename T>
        using type = details::multiplicable<T, OtherOperand>;
    };

}  // namespace strong_type