//
// Created by svalenti on 12/22/2021.
//

////
//// Dutch National Flag - March 5, 2013
////

#include <iostream>
#include <vector>

using Flag_t = std::vector<char>;

void print_flag(Flag_t& flag)
{
    for (char color: flag)
        std::cout << color << ", ";
    std::cout << '\n';
}

int main()
{
    Flag_t dutch_flag{'B', 'W', 'B', 'R', 'W', 'R', 'B'};
    // Flag_t dutch_flag {'B', 'B', 'B', 'R', 'W', 'R', 'B', 'W', 'R'};

    auto red = 0;
    auto white = 0;
    auto blue = dutch_flag.size()-1;

    int ix = 0;

    while (white<=blue)
    {
        switch (dutch_flag[ix])
        {
        case 'R':
            std::swap(dutch_flag[red], dutch_flag[ix]);
            ++red;
            ++white;
            ++ix;
            break;
        case 'W':
            ++white;
            ++ix;
            break;
        default:  // blue
            std::swap(dutch_flag[blue], dutch_flag[ix]);
            --blue;
            break;
        }
        print_flag(dutch_flag);
    }

    std::cout << "dutch flag\n";
    print_flag(dutch_flag);
}
