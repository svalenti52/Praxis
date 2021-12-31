//
// Created by svalenti on 12/30/2021.
//

////
//// International Mathematical Olympiad
////        July 17, 2009
//// IMO 1962 Problem 01
////
////    Find the smallest natural number n which has the following properties:
////
////    (a) Its decimal representation has 6 as the last digit.
////    (b) If the last digit 6 is erased and placed in front of the remaining digits,
////        the resulting number is four times as large as the original number n.
////

#include <iostream>
#include <string>

int main()
{
    for (int ix = 1; ix<1'000'000; ++ix)
    {
        std::string after_6_str = std::to_string(ix);
        std::string before_6_str{after_6_str};
        after_6_str.append("6");
        before_6_str.insert(0, 1, '6');

        int before_6 = std::stoi(before_6_str, nullptr, 10);
        int after_6 = std::stoi(after_6_str, nullptr, 10);

        if (4*after_6==before_6)
        {
            std::cout << "Minimum value with property = " << after_6_str << '\n';
            break;
        }
    }
}
