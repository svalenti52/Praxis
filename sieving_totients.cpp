// sieving_totients.cpp
// 10-Jul-2012
// Created by svalenti on 5/30/2021.
//

#include <vector>
#include <iostream>
#include <numeric>

int main()
{
    using namespace std;

    const uint64_t upper_bound = 100;

    vector<uint64_t> totient(upper_bound, 0);
    iota(totient.begin(), totient.end(), 0);

    for (uint64_t ix = 2; ix<upper_bound; ++ix)
    {
        if (totient[ix]==ix)
            for (uint64_t jx = ix; jx<upper_bound; jx += ix)
                totient[jx] = (ix-1)*totient[jx]/ix;
    }

    for (uint64_t ix = 0; ix<upper_bound; ++ix)
        cout << '(' << ix << ", " << totient[ix] << ") ";
}

