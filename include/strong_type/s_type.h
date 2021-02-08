#pragma once

#include <type_traits>
#include <utility>

namespace strong_type
{

    template <typename T>
    class s_type_base
    {
    public:
        explicit constexpr s_type_base() = default;
        explicit constexpr s_type_base(const s_type_base &) = default;
        explicit constexpr s_type_base(s_type_base &&) noexcept(std::is_nothrow_move_constructible_v<T>) = default;
        constexpr s_type_base& operator=(const s_type_base&) = default;
        constexpr s_type_base& operator=(s_type_base&&) noexcept(std::is_nothrow_move_assignable_v<T>) = default;

        explicit constexpr s_type_base(const T& t) : _t(t) {}
        explicit constexpr s_type_base(T&& t) : _t(std::move(t)) {}

        constexpr const T& get() const & noexcept { return _t; }
        constexpr T& get() & noexcept { return _t; }
        constexpr const T&& get() const && noexcept { return std::move(_t); }
        constexpr T&& get() && noexcept { return std::move(_t); }

    private:
        T _t;
    };
}