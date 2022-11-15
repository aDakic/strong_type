#pragma once

#include <type_traits>

namespace strong_type
{
    namespace details
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
    }  // namespace details

    // clang-format off
    template<typename T>
    concept StrongTypeConcept = details::is_strong_type_v<std::remove_cvref_t<T>> &&
                                requires(T t)
                                {
                                    { t.get() } noexcept;
                                };
    //clang-format on

}  // namespace strong_type::traits