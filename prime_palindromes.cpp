//
// Created by svale on 10/27/2021.
// Praxis
// Prime Palindromes - 26-Oct-2021
//

#include <iostream>
#include <val/montecarlo/Combinatorics.h>

int main()
{
    const size_t ub = 1'000'000;

    primes_list primesList(ub);

    int pp_index = 0;
    int prime_index = 0;

    for (uint64_t number = 0; number < ub && pp_index < 100; ++number) {
        if (primesList.is_prime(number)) {
            ++prime_index;
            if (is_numeric_palindrome(number)) {
                ++pp_index;
                std::cout << "is_palindrome = " << pp_index << ". " << number << "\n";
            }
        }
    }
}
