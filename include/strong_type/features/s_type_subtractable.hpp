#pragma once

#include "strip.hpp"

namespace strong_type
{
    namespace details
    {
        template<typename StrongT, typename OtherOperandT = StrongT, typename ReturnT = StrongT>
        struct subtractable
        {
            friend constexpr ReturnT operator-(const StrongT &lhs, const OtherOperandT &rhs) noexcept
            {
                return ReturnT(lhs.get() - strip(rhs));
            }

            friend constexpr ReturnT operator-(const OtherOperandT &lhs, const StrongT &rhs) noexcept
                requires(not std::same_as<StrongT, OtherOperandT>)
            {
                return ReturnT(strip(lhs) - rhs.get());
            }
        };
    }  // namespace details

    struct subtractable
    {
        template<typename StrongT>
        using type = details::subtractable<StrongT>;
    };

    template<typename OtherOperand>
    struct subtractable_to
    {
        template<typename StrongT>
        using type = details::subtractable<StrongT, OtherOperand>;
    };
}  // namespace strong_type
