//
// Created by svale on 10/11/2021.
//

#include <iostream>
#include <vector>
#include <numeric>
#include <val/montecarlo/Chronology.h>
#include <val/montecarlo/Combinatorics.h>

std::vector<int32_t> steps{-1, 0, 1};

bool passes_muster(std::vector<int>& v) {
    std::vector<int> ps;
    auto lt_zero = [](int x) { return x < 0;};

    std::partial_sum(v.begin(), v.end(), std::back_inserter(ps));
    if (std::any_of(ps.begin(), ps.end(), lt_zero)) return false;
    if (*(ps.end() - 1) != 0) return false;
    return true;
}

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

    if (argc != 2)
    {
        std::cout << "usage: motzkin <number>" << '\n';
        return 1;
    }

    int number = std::strtol(argv[1], nullptr, 10);

    std::cout << "number = " << number << "\n\n";

    StopWatch s;

    create_permutations<int>(steps, permutations, permutation, 0, number, passes_muster);

    std::cout << permutations << '\n';

    std::cout << "For number -> " << number <<  "  Motzkin number = " << permutations.size() << '\n';

    s.stop();
}