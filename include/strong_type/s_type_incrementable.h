#pragma once

namespace strong_type
{
    namespace details
    {
        template <typename T>
        struct incrementable
        {
            friend constexpr T &operator++(T &t) noexcept
            {
                ++t.get();
                return t;
            }

            friend constexpr const T operator++(T &t, int) noexcept
            {
                T ret(t);

                ++t.get();
                return ret;
            }
        };
    }

    struct incrementable
    {
        template <typename T>
        using type = details::incrementable<T>;
    };
}