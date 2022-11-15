#pragma once

#include "s_type_concpts.hpp"

namespace strong_type
{
    // Gets underlying value
    template<typename T>
    constexpr inline decltype(auto) strip(T &&t)
    {
        if constexpr (StrongTypeConcept<T>)
        {
            return std::forward<T>(t).get();
        }
        else
        {
            return std::forward<T>(t);
        }
    }
}  // namespace strong_type