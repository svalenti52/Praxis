//
// Created by svale on 11/25/2021.
//

#include <iostream>
#include <numeric>
#include <val/montecarlo/Combinatorics.h>

using u32 = uint32_t;

using Permutation = std::vector<u32>;
using Permutations = std::vector<std::vector<u32>>;

u32 number = 0;

bool equal_to(Permutation& p)
{
    return number == std::accumulate(p.begin(), p.end(), static_cast<u32>(0));
}

std::ostream& operator << (std::ostream& o, Permutations& vofv)
{
    for (Permutation p : vofv)
    {
        o << "(";
        for (u32 u : p)
        {
            o << u << ", ";
        }
        o << "), ";
    }
    o << '\n';
    return o;
}

int main(int argc, char** argv)
{
    if (argc != 2) {std::cout << "usage: <program> <total amount>\n"; return 1;}
    number = strtoul(argv[1], nullptr, 10);

    std::vector<u32> steps(number, 0);
    std::iota(steps.begin(), steps.end(), 1);

    Permutation  permutation;
    Permutations permutations;

    for (u32 nr_items = 1; nr_items <= number; ++nr_items)
    {
        create_combinatorial_element_set<u32>(steps, permutations, permutation,
                                              0, nr_items, equal_to,
                                              combinations_without_repetition<u32>);

    }

    std::cout << permutations;
}
