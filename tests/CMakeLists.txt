set(test_sources
    st_methods_test.cpp
    addable_feature_test.cpp
    bitwiseable_feature_test.cpp
    comparable_feature_test.cpp
    decrementable_feature_test.cpp
    dividable_feature_test.cpp
    incrementable_feature_test.cpp
    multiplicable_feature_test.cpp
    subtractable_feature_test.cpp)

find_package(Catch2 REQUIRED)

add_executable(tests ${test_sources})
target_compile_features(tests PUBLIC cxx_std_17)
target_link_libraries(tests PUBLIC Catch2::Catch2WithMain strong_type::strong_type)

add_test(NAME tests COMMAND tests)