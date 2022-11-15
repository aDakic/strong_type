#pragma once

#include <array>

namespace strong_type
{
    template<std::size_t N>
    struct static_string
    {
        constexpr static_string(const char (&str)[N]) : value_{ std::to_array(str) } { }

        std::array<char, N> value_;
    };
}  // namespace strong_type