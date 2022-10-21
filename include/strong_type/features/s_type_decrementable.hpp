#pragma once

#include "strip.hpp"

namespace strong_type
{
    namespace details
    {
        template<typename StrongT>
        struct decrementable
        {
            friend constexpr StrongT &operator--(StrongT &t) noexcept
            {
                --t.get();
                return t;
            }

            friend constexpr StrongT operator--(StrongT &t, int) noexcept
            {
                StrongT ret(t);

                --t.get();
                return ret;
            }
        };
    }  // namespace details

    struct decrementable
    {
        template<typename StrongT>
        using type = details::decrementable<StrongT>;
    };
}  // namespace strong_type