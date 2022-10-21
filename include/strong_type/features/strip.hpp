#pragma once

#include "s_type_traits.hpp"

namespace strong_type
{
    // Gets underlying type
    template<typename T>
    constexpr inline decltype(auto) strip(T &&t)
    {
        if constexpr (traits::is_strong_type_v<std::remove_cvref_t<T>>)
        {
            return std::forward<T>(t).get();
        }
        else
        {
            return std::forward<T>(t);
        }
    }
}  // namespace strong_type