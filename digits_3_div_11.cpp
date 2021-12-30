//
// Created by svalenti on 12/28/2021.
//

////
//// International Mathematical Olympiad
////        July 17, 2009
//// This taken from 1960, problem 1
////

#include <iostream>
#include <vector>
#include <numeric>
#include <val/montecarlo/Primes.h>

int main()
{
    for (int ix = 12; ix<=90; ++ix)
    {
        int number = ix*11;
        std::vector<int> digits;
        digits_from_number(number, digits);
        if (ix==std::inner_product(digits.begin(), digits.end(), digits.begin(), 0))
            std::cout << "Answer = " << number << '\n';
    }
}
