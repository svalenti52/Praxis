//
// Created by svale on 11/10/2021.
//
//// 14-Apr-2009 - Google Treasure Hunt 2008 Puzzle 4
////

#include <iostream>
#include <val/montecarlo/Primes.h>
#include <numeric>

using u64 = uint64_t;

int main()
{
    const u64 upper_bound = 10'000'000;
    Primes_List primesList(upper_bound);
    Primes primes(primesList, upper_bound);

    u64 begin541 = 0, end541 = 541;
    u64 begin41 = 0, end41 = 41;
    u64 begin17 = 0, end17 = 17;
    u64 begin7 = 0, end7 = 7;
    bool found_prime = false;
    u64 sum541;
    u64 sum41 = 0;
    u64 sum17 = 0;
    u64 sum7 = 0;

    while (!found_prime)
    {
        sum541 = std::accumulate(primes.get_pos(begin541), primes.get_pos(end541), static_cast<u64>(0));
        if (primesList.is_prime(sum541)) {
            while (sum41 < sum541) {
                sum41 = std::accumulate(primes.get_pos(begin41), primes.get_pos(end41), static_cast<u64>(0));
                ++begin41, ++end41;
            }
            if (sum41 == sum541)
            {
                while (sum17 < sum541)
                {
                    sum17 = std::accumulate(primes.get_pos(begin17), primes.get_pos(end17), static_cast<u64>(0));
                    ++begin17, ++end17;
                }
                if (sum17 == sum541) {
                    while (sum7 < sum541) {
                        sum7 = std::accumulate(primes.get_pos(begin7), primes.get_pos(end7), static_cast<u64>(0));
                        ++begin7, ++end7;
                    }
                    if (sum7 == sum541)
                        found_prime = true;
                }
            }
        }
        ++begin541, ++end541;
    }

    std::cout << "Least Prime meeting requirements = " << sum541 << "\n";
}
