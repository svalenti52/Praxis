// collatz_prime.cpp
// Created by svalenti on 11/30/2019.
// Programming Praxis 1-May-2015

#include <iostream>
#include <vector>
#include <tuple>
#include <numeric>
#include <cmath>
#include <algorithm>
#include "prime_list.hpp"

auto is_prime(uint64_t number)
{
    if (number==1)
        return false;
    double d = std::sqrt(static_cast<double>(number));
    for (auto ix = primes_list.begin(); *ix<=d; ++ix)
        if (number%*ix==0)
            return false;
    return true;
}

auto collatz_prime_count(int number)
{
    auto even([](uint64_t z) { return z%2==0; });
    uint64_t x = number;
    int y = 0;

    while (x!=1)
    {
        if (is_prime(x))
            ++y;
        even(x) ? (x /= 2) : (x = 3*x+1);
    }
    return std::make_tuple(y, number);
}

void collatz_primes_list(uint64_t x, std::vector<uint64_t>& v)
{
    auto even([](uint64_t z) { return z%2==0; });
    while (x!=1)
    {
        if (is_prime(x))
            v.push_back(x);
        even(x) ? (x /= 2) : (x = 3*x+1);
    }
}

int main()
{
    int max_collatz_sequence_count = 0;
    int collatz_num = 0;
    std::vector<int> v(2'000'000, 0);
    std::iota(v.begin(), v.end(), 1);

//    for (auto ixx : primes_list);
//       std::cout << ixx << ", ";
    std::cout << '\n';

    for (int ix : v)
    {
        auto[max_sequence_count, number] = collatz_prime_count(ix);
        if (max_collatz_sequence_count<max_sequence_count)
        {
            max_collatz_sequence_count = max_sequence_count;
            collatz_num = number;
            if (max_collatz_sequence_count>=65)
                break;
        }
    }

    std::cout << "Max Collatz Prime Count = " << max_collatz_sequence_count << " at number = " << collatz_num << '\n';

    std::vector<uint64_t> w;
    collatz_primes_list(collatz_num, w);

    std::sort(w.begin(), w.end());
    for (uint64_t ix : w)
        std::cout << ix << ", ";
    std::cout << '\n';
    std::cout << "Size of vector = " << w.size() << " elements\n";
}
