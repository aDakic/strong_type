#pragma once

namespace strong_type
{
    namespace details
    {
        template <typename T, typename otherOperandT = T, typename ReturnT = T>
        struct dividable
        {
            friend constexpr ReturnT operator/(const T &lhs, const otherOperandT &rhs) noexcept
            {
                return ReturnT(lhs.get() / strip(rhs));
            }
        };
    }

    struct dividable
    {
        template <typename T>
        using type = details::dividable<T>;
    };

    template <typename OtherOperand>
    struct dividable_by
    {
        template <typename T>
        using type = details::dividable<T, OtherOperand>;
    };
}