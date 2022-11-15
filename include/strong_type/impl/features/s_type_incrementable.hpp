#pragma once

#include "../strip.hpp"

namespace strong_type
{
    namespace details
    {
        template<typename StrongT>
        struct incrementable
        {
            friend constexpr StrongT &operator++(StrongT &st) noexcept
            {
                ++st.get();
                return st;
            }

            friend constexpr StrongT operator++(StrongT &st, int) noexcept
            {
                StrongT ret(st);

                ++st.get();
                return ret;
            }
        };
    }  // namespace details

    struct incrementable
    {
        template<typename StrongT>
        using type = details::incrementable<StrongT>;
    };
}  // namespace strong_type