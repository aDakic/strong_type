#pragma once

#include "../strip.hpp"

namespace strong_type
{
    namespace details
    {
        template<typename StrongT, typename otherOperandT = StrongT>
        struct bitwiseable
        {
            friend constexpr bool operator&(const StrongT &lhs, const otherOperandT &rhs) noexcept
            {
                return lhs.get() & strip(rhs);
            }

            friend constexpr bool operator|(const StrongT &lhs, const otherOperandT &rhs) noexcept
            {
                return lhs.get() | strip(rhs);
            }

            friend constexpr bool operator^(const StrongT &lhs, const otherOperandT &rhs) noexcept
            {
                return lhs.get() ^ strip(rhs);
            }
        };
    }  // namespace details

    struct bitwiseable
    {
        template<typename StrongT>
        using type = details::bitwiseable<StrongT>;
    };
}  // namespace strong_type