cmake_minimum_required(VERSION 3.10)
project(stats_lib_tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add test executables
add_executable(distribution_tests distribution_tests.cpp)
add_executable(estimation_tests estimation_tests.cpp)
add_executable(rng_tests rng_tests.cpp)
add_executable(sampling_tests sampling_tests.cpp)

# Link against the main library
target_link_libraries(distribution_tests stats_lib)
target_link_libraries(estimation_tests stats_lib)
target_link_libraries(rng_tests stats_lib)
target_link_libraries(sampling_tests stats_lib)

# Add tests to CTest
add_test(NAME distribution_tests COMMAND distribution_tests)
add_test(NAME estimation_tests COMMAND estimation_tests)
add_test(NAME rng_tests COMMAND rng_tests)
add_test(NAME sampling_tests COMMAND sampling_tests) 