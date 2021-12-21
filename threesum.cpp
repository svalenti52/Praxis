//
// Created by svalenti on 12/21/2021.
//

#include <vector>
#include <iostream>
#include <val/montecarlo/Combinatorics.h>
#include <numeric>

bool select_three_sum(std::vector<int>& v)
{
    int three = std::accumulate(v.begin(), v.end(), 0);
    return three==3;
}

int accumulate_if(std::vector<int>& numbers, std::vector<int>& selector)
{
    int sum = 0;
    for (int ix = 0; ix<numbers.size(); ++ix)
    {
        if (selector[ix]==1)
            sum += numbers[ix];
    }
    return sum;
}

int main()
{
    std::vector<int> items{8, -25, 4, 10, -10, -7, 2, -3};

    std::vector<int> symbols{0, 1};
    std::vector<int> permutation;
    std::vector<std::vector<int>> permutations;

    create_combinatorial_element_set<int>(symbols, permutations, permutation, 0, items.size(),
            select_three_sum, permutations_with_repetition<int>);

    for (std::vector selector: permutations)
    {
        int x = accumulate_if(items, selector);
        if (x==0)
        {
            std::cout << "sums to zero: ";
            for (int ix = 0; ix<selector.size(); ++ix)
            {
                if (selector[ix]==1)
                    std::cout << items[ix] << ", ";
            }
            std::cout << '\n';
        }
    }
}
