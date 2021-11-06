//
// Created by svale on 11/2/2021.
//
// Counting Primes Using Legendre’s Formula
// 22-Jul-2011
//

#include <iostream>
#include <val/montecarlo/Primes.h>

using u64 = uint64_t;

u64 phi(u64 number, u64 prime_count_sieve, Primes& v)
{
    if (prime_count_sieve == 1)
        return static_cast<u64>(ceil(static_cast<double>(number)/ 2.0));

    return phi(number, prime_count_sieve - 1, v) -
           phi(number/v.get_ith_prime(prime_count_sieve - 1), prime_count_sieve - 1, v);
}

u64 n(u64 x, Primes& p)
{
    if (x == 2) return 1;
    if (x == 3) return 2;
    u64 floor_sqrt_x = static_cast<uint64_t>(floor(sqrt(x)));
    std::cout << "floor_sqrt_x = " << floor_sqrt_x << '\n';
    u64 intermediate_n_result = n(floor_sqrt_x, p);
    u64 add1 = phi(x, intermediate_n_result, p);
    u64 add2 = intermediate_n_result;
    std::cout << "add1 = " << add1 << "  add2 = " << add2 << '\n';
    u64 sum = add1 + add2 - 1;
    return sum;
}

int main()
{
    Primes_List primesList(1'000'000);

    Primes primes(primesList, 1'000'000);

    Partial_Primes_List p(200, 3);

    std::cout << "Number un-sieved = " << p.get_initial_prime_count() << "\n";

    p.list_potential_primes();

    const u64 number = 1'000;

    u64 number_of_primes_less_than_or_equal = n(number, primes);

    std::cout << "\nPrime count for " << number << " = " << number_of_primes_less_than_or_equal << "\n\n";
}
