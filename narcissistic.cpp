//
// Created by svale on 12/14/2021.
//

#include <iostream>
#include <vector>
#include <val/montecarlo/Combinatorics.h>

using u32 = uint32_t;

bool passes_muster(std::vector<u32>& v)
{
    u32 number = 0;
    u32 narcissistic = 0;
    if (v[0] == 0) return false;
    for (auto x = v.begin(); x != v.end(); ++x)
         narcissistic += static_cast<u32>(pow(*x, v.size()));
    for (auto x = 0; x < v.size(); ++x)
        number += v[x] * static_cast<u32>(pow(10.0, static_cast<double>(v.size() - x - 1)));
    if (narcissistic == number)
        return true;
    return false;
}

std::ostream& operator << (std::ostream& o, std::vector<u32>& v) {
    o << '(';
    for (u32 ix : v)
        o << ix << ", ";
    o << ")\n";
    return o;
}

std::ostream& operator << (std::ostream& o, std::vector<std::vector<u32>>& vofv) {
    for (std::vector<u32>& v : vofv)
        o << v;
    return o;
}


int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "usage: NARCISSISTIC <number_of_digits>" << '\n';
        return 1;
    }

    const int total_number_digits = strtol(argv[1], nullptr, 10);
    std::vector<u32> digits {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::vector<std::vector<u32>> vset;
    std::vector<u32> permutation;

    create_combinatorial_element_set<u32>(digits, vset, permutation, 0, total_number_digits,
                                     passes_muster, permutations_with_repetition<u32>);

    std::cout << vset;
}
