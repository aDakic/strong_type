#pragma once

#include <type_traits>

namespace strong_type
{
    template <typename T>
    struct is_strong_type : std::false_type {};

    template <typename T, typename Tag, typename... Feature>
    struct is_strong_type<strong_type<T, Tag, Feature...>> : std::true_type {};

    template <typename T>
    constexpr bool is_strong_type_v = is_strong_type<T>::value;

    template<typename T>
    struct remove_cvref
    {
        using type = std::remove_cv_t<std::remove_reference_t<T>>;
    };

    template<typename T>
    using remove_cvref_t = typename remove_cvref<T>::type;

    template<typename T>
    constexpr inline decltype(auto) strip(T&& t)
    {
        if constexpr (is_strong_type_v<remove_cvref_t<T>>)
        {
            return std::forward<T>(t).get();
        }
        else
        {
            return std::forward<T>(t);
        }
    }
}