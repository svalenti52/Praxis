// collatz.cpp
// Created by svalenti on 11/30/2019.
//

#include <iostream>
#include <vector>
#include <tuple>
#include <numeric>

auto collatz_sequence_count(int number)
{
    auto even([](uint64_t z) { return z%2==0; });
    uint64_t x = number;
    int y = 1;

    while (x!=1)
    {
        even(x) ? (x /= 2) : (x = 3*x+1);
        ++y;
    }
    return std::make_tuple(y, number);
}

int main()
{
    int max_collatz_sequence_count = 0;
    int collatz_num = 0;
    std::vector<int> v(1'600'000, 0);
    std::iota(v.begin(), v.end(), 1);

    for (int ix : v)
    {
        auto[max_sequence_count, number] = collatz_sequence_count(ix);
        if (max_collatz_sequence_count<max_sequence_count)
        {
            max_collatz_sequence_count = max_sequence_count;
            collatz_num = number;
        }
    }

    std::cout << "Max Collatz Count = " << max_collatz_sequence_count << " at number = " << collatz_num << '\n';
}