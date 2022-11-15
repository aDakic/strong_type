#pragma once

#include <type_traits>

namespace strong_type::traits
{
    template<typename T>
    struct is_strong_type : std::false_type
    {
    };

    template<typename T, static_string Tag, typename... Feature>
    struct is_strong_type<strong_type<T, Tag, Feature...>> : std::true_type
    {
    };

    template<typename T>
    constexpr inline bool is_strong_type_v = is_strong_type<T>::value;
}  // namespace strong_type::traits