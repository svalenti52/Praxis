// pandigital.cpp
// praxis 30-Oct-2012
// Created by svalenti on 5/30/2021.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    using namespace std;

    vector<uint64_t> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    uint64_t ix = 1;
    do
    {
        uint64_t add1 = 100*v[0]+10*v[1]+v[2];
        uint64_t add2 = 100*v[3]+10*v[4]+v[5];
        uint64_t sum = 1000*v[6]+100*v[7]+10*v[8]+v[9];

        if (add1+add2 == sum && add1 < add2)
        {
            cout << ix << ". " << add1 << " + " << add2 << " = " << sum << '\n';
            ++ix;
        }

    }
    while (next_permutation(v.begin(), v.end()));
}
