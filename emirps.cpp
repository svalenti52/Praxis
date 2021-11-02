//
// Created by svale on 10/29/2021.
//

#include <iostream>
#include <val/montecarlo/Combinatorics.h>

int main()
{
    const size_t ub1 = 20'000;
    const size_t lb2 = 30'000;
    const size_t ub2 = 40'000;
    const size_t lb3 = 70'000;
    const size_t ub3 = 80'000;
    const size_t lb4 = 90'000;
    const size_t ub4 = 100'000;
    const size_t ub = 1'000'000;
    auto first_digit_divisible = [](uint64_t number)
            {
                bool result = false;
                uint64_t x = number;
                uint64_t y = 0;
                while(x >= 10) {
                    x /= 10;
                    ++y;
                }
                switch (x)
                {
                    case 0:
                    case 2:
                    case 4:
                    case 5:
                    case 6:
                    case 8:
                        result = true;
                        break;
                }
                uint64_t z = 1;
                while (y > 0) {
                    z *= 10;
                    --y;
                }
                return std::make_pair(result, z);
            };

    uint64_t emirps_count = 0;
    for (int ix = 1; ix < ub; ++ix)
    {
        primes_list p(ub);

        auto [result, ix_to_skip] = first_digit_divisible(ix);
        if (result){
            if (ix_to_skip > 1)
                ix += ix_to_skip - 1;
            continue;
        }

        if (p.is_prime(ix))
        {
            uint64_t reversed_number = reverse(ix);
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
}
