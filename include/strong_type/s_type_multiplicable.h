#pragma once

namespace strong_type
{
    namespace details
    {
        template <typename T, typename otherOperandT = T, typename ReturnT = T>
        struct multiplicable
        {
            friend constexpr ReturnT operator*(const T &lhs, const otherOperandT &rhs) noexcept
            {
                return ReturnT(lhs.get() * strip(rhs));
            }
        };
    }

    struct multiplicable
    {
        template <typename T>
        using type = details::multiplicable<T>;
    };

    template <typename OtherOperand>
    struct multiplicable_with
    {
        template <typename T>
        using type = details::multiplicable<T, OtherOperand>;
    };

}