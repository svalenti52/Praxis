//
// Created by svalenti on 1/1/2022.
//

#include <iostream>
#include <val/montecarlo/Primes.h>
#include <numeric>
#include "prime_list.hpp"

using u64 = u_int64_t;

u64 fibo(u64 n)
{
    if (n<=1)
        return n;
    return fibo(n-1)+fibo(n-2);
}

int main()
{
    const u64 lower_bound = 227000;
    u64 fibonacci = fibo(5);

    Primes_List primesList(1'000'000);
    bool is_prime = false;

    for (u64 ix = 0; ix<=35; ++ix)
        if ((fibonacci = fibo(ix))>lower_bound)
            if (primesList.is_prime(fibonacci))
                break;

    u64 number_to_factor = fibonacci+1;
    std::vector<u64> factors;

    for (int ix = 0; ix<sqrt(static_cast<double>(number_to_factor)); ++ix)
    {
        if (number_to_factor%primes_list[ix]==0)
        {
            factors.push_back(primes_list[ix]);
            number_to_factor /= primes_list[ix];
        }
    }

    factors.push_back(number_to_factor);

    is_prime = primesList.is_prime(number_to_factor);

    std::cout << "factored number is " << number_to_factor << "   is prime=" << is_prime << '\n';
    for (u64 f: factors)
        std::cout << f << ", ";
    std::cout << '\n';

    u64 answer = std::accumulate<std::vector<u64>::iterator, u64>(factors.begin(), factors.end(), 0);
    std::cout << "factors sum = " << answer << '\n';
}
