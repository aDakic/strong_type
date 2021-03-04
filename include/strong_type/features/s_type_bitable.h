#pragma once

namespace strong_type
{
    namespace details
    {
        template <typename T, typename otherOperandT = T>
        struct bitable
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
                return lhs.get() | strip(rhs);
            }

            friend constexpr T operator~(const T &lhs) noexcept
            {
                return T(~lhs.get());
            }
        };
    }

    struct bitable
    {
        template <typename T>
        using type = details::bitable<T>;
    };
}