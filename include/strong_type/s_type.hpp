#pragma once

#include <type_traits>
#include <utility>

#include "static_string.hpp"

namespace strong_type
{
    template<typename T>
    requires(not std::is_reference_v<T>) class s_type_base
    {
    public:
        explicit constexpr s_type_base(const T &t) noexcept(std::is_nothrow_copy_constructible_v<T>) : _t(t) { }
        explicit constexpr s_type_base(T &&t) noexcept(std::is_nothrow_move_constructible_v<T>) : _t(std::move(t)) { }

        [[nodiscard]] constexpr const T &get() const &noexcept { return _t; }
        [[nodiscard]] constexpr const T &&get() const &&noexcept { return std::move(_t); }
        [[nodiscard]] constexpr T &get() &noexcept { return _t; }
        [[nodiscard]] constexpr T &&get() &&noexcept { return std::move(_t); }

    private:
        T _t;
    };

    template<typename T, typename Tag, typename... Features>
    struct strong_type : Features::template type<strong_type<T, Tag, Features...>>..., s_type_base<T>
    {
        using s_type_base<T>::s_type_base;
    };
}  // namespace strong_type