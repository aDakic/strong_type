#pragma once

#include <type_traits>

namespace strong_type
{
    namespace details
    {
        // strong type trait
        template<typename T>
        struct is_strong_type : std::false_type
        {
        };

        template<typename T, typename Tag, typename... Feature>
        struct is_strong_type<strong_type<T, Tag, Feature...>> : std::true_type
        {
        };

        template<typename T>
        constexpr inline bool is_strong_type_v = is_strong_type<T>::value;

        // Remove references and const-volatile qualifiers
        template<typename T>
        struct remove_cvref
        {
            using type = std::remove_cv_t<std::remove_reference_t<T>>;
        };

        template<typename T>
        using remove_cvref_t = typename remove_cvref<T>::type;
    }  // namespace details

    // Gets underlying type
    template<typename T>
    constexpr inline decltype(auto) strip(T &&t)
    {
        if constexpr (details::is_strong_type_v<details::remove_cvref_t<T>>)
        {
            return std::forward<T>(t).get();
        }
        else
        {
            return std::forward<T>(t);
        }
    }
}  // namespace strong_type