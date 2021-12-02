//
// Created by svale on 12/2/2021.
//
////
//// Reciprocal Palindromes
//// 30-Nov-2021
//// Takes about 116 seconds to compute for 1,000,000,000 on my computer
////

#include <cstdint>
#include <vector>
#include <val/montecarlo/Primes.h>
#include <val/montecarlo/Chronology.h>
#include <numeric>
#include <iomanip>

using u64 = uint64_t;

int main()
{
    std::vector<u64> v;
    std::vector<double> inverted;

    StopWatch s;

    for (u64 ix = 1; ix < 1'000'000'000; ++ix)
        if (is_numeric_palindrome(ix))
            v.push_back(ix);

    std::cout << "count of palindromes is " << v.size() << '\n';

    for (u64 u : v)
        inverted.push_back(1.0 / static_cast<double>(u));

    double converge = std::accumulate(inverted.begin(), inverted.end(), 0.0);

    std::cout << "Reciprocal palindromes converge to " << std::setprecision(17) << converge << '\n';

    s.stop();
}
