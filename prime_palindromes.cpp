//
// Created by svale on 10/27/2021.
// Praxis
// Prime Palindromes - 26-Oct-2021
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

class primes_list
{
    std::vector<bool> prime_list;
public:
    explicit primes_list(uint64_t upper_bound)
    {
        auto sqrt_ub = static_cast<uint64_t>(std::ceil(std::sqrt(upper_bound)));
        for (int ix = 0; ix < upper_bound; ++ix)
            prime_list.push_back(true);
        prime_list[0] = false;
        prime_list[1] = false;
        for (int ix = 2; ix < sqrt_ub; ++ix) {
            if (prime_list[ix])
                for (int jx = ix + ix; jx < upper_bound; jx += ix)
                    prime_list[jx] = false;

        }
    }

    bool is_prime(uint64_t number) {
        return prime_list[number];
    }
};

bool is_numeric_palindrome(uint64_t number)
{
    std::string s = std::to_string(number);
    std::string::const_reverse_iterator ri = s.crbegin();
    for (char digit : s)
    {
        if (digit != *ri++)
            return false;
    }
    return true;
}

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
