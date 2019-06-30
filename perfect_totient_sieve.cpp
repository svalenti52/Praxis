// perfect_totient_sieve.cpp
// perfect totient number is where the sum of its iterated totients are equal to the number
// a totient is the count of numbers less than that number that are coprime to it
// totative of a number is a number that is both less than and coprime
// another way to defining a totient is the number of totatives

#include <iostream>
#include <vector>
#include <numeric>

int main(int argc, char** argv)
{
    using namespace std;
    using U = uint32_t;

    U number = 10'000;

    if (argc>2) return 1;
    else if (argc>1) number = strtoul(argv[1], nullptr, 10);

    vector<int> v(number);
    iota(v.begin(), v.end(), 0); // v <- {0, 1, 2, 3, 4, ..., 9999} in the 10'000 case
    v[1] = 0; // special case, because of sieving

    for (U p = 2; p<number; ++p)
    {
        if (v[p]==p) // effectively only primes are going to satisfy this condition
            for (U q = p; q<number; q += p)
                v[q] = (p-1)*(v[q]/p); // because all composites are going to get sieved!
        // i.e., the totient function reduces so v[p] != p
        v[p] += v[v[p]]; // and every sum_totient of the prior is in position
        // by the time we get to the later
        if (v[p]==p)
            cout << p << ", ";
    }

    cout << '\n';
}
