#pragma once

#include "s_type_traits.h"

namespace strong_type
{
    namespace details
    {
        template<typename T>
        struct decrementable
        {
            friend constexpr T &operator--(T &t) noexcept
            {
                --t.get();
                return t;
            }

            friend constexpr const T operator--(T &t, int) noexcept
            {
                T ret(t);

                --t.get();
                return ret;
            }
        };
    }  // namespace details

    struct decrementable
    {
        template<typename T>
        using type = details::decrementable<T>;
    };
}  // namespace strong_type