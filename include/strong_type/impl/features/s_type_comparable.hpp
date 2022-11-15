#pragma once

#include "../strip.hpp"

namespace strong_type
{
    namespace details
    {
        template<typename StrongT, typename otherOperandT = StrongT>
        struct comparable
        {
            friend constexpr bool operator==(const StrongT &lhs, const otherOperandT &rhs) noexcept
            {
                return lhs.get() == strip(rhs);
            }

            friend constexpr auto operator<=>(const StrongT &lhs, const otherOperandT &rhs) noexcept
            {
                return lhs.get() <=> strip(rhs);
            }
        };
    }  // namespace details

    struct comparable
    {
        template<typename StrongT>
        using type = details::comparable<StrongT>;
    };
}  // namespace strong_type