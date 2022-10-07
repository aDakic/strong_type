#pragma once

#include "s_type_traits.h"

namespace strong_type
{
    namespace details
    {
        template<typename T, typename OtherOperandT = T, typename ReturnT = T>
        struct addable
        {
            friend constexpr ReturnT operator+(const T &lhs, const OtherOperandT &rhs) noexcept
            {
                return ReturnT(lhs.get() + strip(rhs));
            }

            template<typename U = T, typename OtherOperandU = OtherOperandT,
                     typename = std::enable_if_t<!std::is_same_v<U, OtherOperandU>>>
            friend constexpr ReturnT operator+(const OtherOperandT &lhs, const T &rhs) noexcept
            {
                return ReturnT(strip(lhs) + rhs.get());
            }
        };
    }  // namespace details

    struct addable
    {
        template<typename T>
        using type = details::addable<T>;
    };

    template<typename OtherOperand>
    struct addable_with
    {
        template<typename T>
        using type = details::addable<T, OtherOperand>;
    };
}  // namespace strong_type