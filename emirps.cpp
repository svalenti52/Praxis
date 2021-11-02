//
// Created by svale on 10/29/2021.
//

#include <iostream>
#include <val/montecarlo/Combinatorics.h>
#include <val/montecarlo/Chronology.h>

int main()
{
    const size_t ub = 1'000'000;
    uint64_t emirps_count = 0;
    primes_list p(ub);  // for one-time creation of primes_list
    // had placed in loop and wondered at emirps performance (very slow)!

    StopWatch stop_watch;

    for (int ix = 1; ix < ub; ++ix)
    {
        if (p.is_prime(ix))
        {
            uint64_t reversed_number = numeric_digits_reversed(ix);
            if (p.is_prime(reversed_number))
            {
                if (!is_numeric_palindrome(reversed_number)) {
                    std::cout << "emirps = " << ix << '\n';
                    ++emirps_count;
                }
            }
        }
    }
    std::cout << "emirps count = " << emirps_count << '\n';
    stop_watch.stop();
}
