set(test_sources
    addable_feature_test.cpp
    subtractable_feature_test.cpp
    multiplicable_feature_test.cpp
    dividable_feature_test.cpp
    comparable_feature_test.cpp
    incrementable_feature_test.cpp
    decrementable_feature_test.cpp
    bitwiseable_feature_test.cpp)

add_executable(tests ${test_sources})

target_compile_features(
  tests
   PUBLIC
   cxx_std_17
)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

#find_package(GTest CONFIG REQUIRED)

include(GoogleTest)
gtest_discover_tests(tests)

target_link_libraries(
  tests
  PUBLIC
gtest_main
  strong_type::strong_type
)

add_test(
  NAME tests
  COMMAND tests)