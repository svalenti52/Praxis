//
// Created by svale on 12/14/2021.
//

#include <iostream>
#include <vector>
#include <val/montecarlo/Combinatorics.h>
#include <val/montecarlo/Chronology.h>

using u64 = uint64_t;

bool narcissism_test(std::vector<u64>& v)
{
    u64 number = 0;
    u64 narcissistic = 0;
    if (v[0] == 0) return false;
    for (u64 x : v)
        narcissistic += static_cast<u64>(pow(x, v.size()));
    for (auto x = 0; x < v.size(); ++x)
        number += v[x] * static_cast<u64>(pow(10.0, static_cast<double>(v.size() - x - 1)));
    if (narcissistic == number)
        return true;
    return false;
}

std::ostream& operator << (std::ostream& o, std::vector<u64>& v) {
    o << '(';
    for (u64 ix : v)
        o << ix << ", ";
    o << ")\n";
    return o;
}

std::ostream& operator << (std::ostream& o, std::vector<std::vector<u64>>& vofv) {
    for (std::vector<u64>& v : vofv)
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
    std::vector<u64> digits {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::vector<std::vector<u64>> permutations;
    std::vector<u64> permutation;

    StopWatch s;

    create_combinatorial_element_set<u64>(digits, permutations, permutation, 0, total_number_digits,
                                          narcissism_test, permutations_with_repetition<u64>);

    std::cout << permutations;

    s.stop();
}
