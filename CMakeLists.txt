cmake_minimum_required(VERSION 3.7)
project(Praxis)

set(CMAKE_CXX_STANDARD 17)

add_executable(PENNY_BETA penny_beta.cpp)
add_executable(EULER_12 euler_12_alpha.cpp)
add_executable(PENNY_THREAD penny_thread.cpp)
add_executable(PERFECT_TOTIENT_SIEVE perfect_totient_sieve.cpp)
add_executable(COLLATZ collatz.cpp)
add_executable(COLLATZ_PRIME collatz_prime.cpp)
