//
// Created by svale on 10/18/2021.
//

#include <iostream>
#include <numeric>
#include <val/montecarlo/Chronology.h>
#include <val/montecarlo/Combinatorics.h>

std::vector<int32_t> steps(19, 0);

bool passes_muster(std::vector<int>& v)
{ return true; }

std::ostream& operator << (std::ostream& o, std::vector<int>& v) {
    o << '(';
    for (int ix : v)
        o << ix << ", ";
    o << ")\n";
    return o;
}

std::ostream& operator << (std::ostream& o, std::vector<std::vector<int>>& vofv) {
    for (std::vector<int>& v : vofv)
        o << v;
    return o;
}

int main(int argc, char** argv)
{
    std::vector<std::vector<int>> permutations;
    std::vector<int> permutation;

    std::iota(steps.begin(), steps.end(), 0);

    if (argc != 2)
    {
        std::cout << "usage: motzkin <number>" << '\n';
        return 1;
    }

    int number = std::strtol(argv[1], nullptr, 10);

    std::cout << "number = " << number << "\n\n";

    StopWatch s;

    create_combinatorial_element_set<int>(steps, permutations,
                                             permutation, 0,
                                             number, passes_muster,
                                             combinations_without_repetition<int>);

    // std::cout << permutations << '\n';

    std::cout << "For " << steps.size() << " items taken " << number << " at a time gives "
        << permutations.size() << " combinations without repetition\n\n";

    s.stop();
}