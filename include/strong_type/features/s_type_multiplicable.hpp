#pragma once

#include "strip.hpp"

namespace strong_type
{
    namespace details
    {
        template<typename StrongT, typename OtherOperandT = StrongT, typename ReturnT = StrongT>
        struct multiplicable
        {
            friend constexpr ReturnT operator*(const StrongT &lhs, const OtherOperandT &rhs) noexcept
            {
                return ReturnT(lhs.get() * strip(rhs));
            }

            friend constexpr ReturnT operator*(const OtherOperandT &lhs, const StrongT &rhs) noexcept
                requires(not std::same_as<StrongT, OtherOperandT>)
            {
                return ReturnT(strip(lhs) * rhs.get());
            }
        };
    }  // namespace details

    struct multiplicable
    {
        template<typename StrongT>
        using type = details::multiplicable<StrongT>;
    };

    template<typename OtherOperand>
    struct multiplicable_with
    {
        template<typename StrongT>
        using type = details::multiplicable<StrongT, OtherOperand>;
    };

}  // namespace strong_type