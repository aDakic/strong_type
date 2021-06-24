#pragma once

#include "s_type_traits.h"

namespace strong_type
{
    namespace details
    {
        template <typename T, typename otherOperandT = T>
        struct bitwiseable
        {
            friend constexpr bool operator&(const T &lhs, const otherOperandT &rhs) noexcept
            {
                return lhs.get() & strip(rhs);
            }

            friend constexpr bool operator|(const T &lhs, const otherOperandT &rhs) noexcept
            {
                return lhs.get() | strip(rhs);
            }

            friend constexpr bool operator^(const T &lhs, const otherOperandT &rhs) noexcept
            {
                return lhs.get() ^ strip(rhs);
            }
        };
    }

    struct bitwiseable
    {
        template <typename T>
        using type = details::bitwiseable<T>;
    };
}