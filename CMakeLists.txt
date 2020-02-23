cmake_minimum_required(VERSION 3.13)
project(_Infotecs)

set(CMAKE_CXX_STANDARD 11)

enable_testing()

add_subdirectory(googletest)

add_executable(primes_test Test.cpp Primes.cpp)
add_executable(_Infotecs main.cpp Primes.cpp)

target_link_libraries(primes_test PUBLIC gtest_main)

add_test(
        NAME primes_test
        COMMAND primes_test
)
