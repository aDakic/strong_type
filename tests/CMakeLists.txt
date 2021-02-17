set(test_sources
    addable_feature_test.cpp
    subtractable_feature_test.cpp
    multiplicable_feature_test.cpp
    dividable_feature_test.cpp
    comparable_feature_test.cpp
    incrementable_feature_test.cpp)

add_executable(test ${test_sources})

target_compile_features(
   test
   PUBLIC
   cxx_std_17
)

find_package(GTest REQUIRED)

target_link_libraries(
  test
  PUBLIC
  GTest::GTest
  GTest::Main
  strong_type::strong_type
)