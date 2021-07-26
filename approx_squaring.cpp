//
// Created by svale on 7/23/2021.
// Programming Praxis 8-Jun-2021
//


#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;


int main(int argc, char** argv)
{
    if (argc != 3) { std::cout << "usage: approx_squaring <numerator> <denominator>"; return 1; }
    cpp_int numerator = std::strtol(argv[1], nullptr, 10);
    cpp_int denominator = std::strtol(argv[2], nullptr, 10);

    if (numerator <= denominator)
    {
        std::cout << "numerator must be greater than denominator\n";
        return 1;
    }

    if (denominator == 0)
    {
        std::cout << "denominator must not be zero\n";
        return 1;
    }

    if (numerator % denominator == 0)
    {
        numerator /= denominator;
        denominator = 1;
    }

    int step = 1;
    while (denominator != 1)
    {
        auto coefficient = numerator / denominator + 1;

        numerator = numerator * coefficient;

        std::cout << step << ". intermediate result = " << numerator << '\n';
        ++step;

        if (numerator % denominator == 0) {
            numerator /= denominator;
            denominator = 1;
        }
    }

    std::cout << "\napproximate squaring results in " << numerator << '\n';
}
