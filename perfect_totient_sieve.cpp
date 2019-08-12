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
    using U32 = uint32_t;

    U32 number = 10'000;

    if (argc>2) return 1;
    else if (argc>1) number = strtoul(argv[1], nullptr, 10);

    vector<int> sum_totient(number);
    iota(sum_totient.begin(), sum_totient.end(), 0); // sum_totient <- {0, 1, 2, 3, 4, ..., 9999} in the 10'000 case
    sum_totient[1] = 0; // special case, because of sieving

    for (U32 p = 2; p<number; ++p)
    {
        if (sum_totient[p]==p) // effectively only primes are going to satisfy this condition
            for (U32 q = p; q<number; q += p)
                sum_totient[q] = (p-1)*(sum_totient[q]/p); // because all composites are going to get sieved!
        // i.e., the totient function reduces so sum_totient[p] != p
        sum_totient[p] += sum_totient[sum_totient[p]]; // and every sum_totient of the prior is in position
        // by the time we get to the later
        if (sum_totient[p]==p)
            cout << p << ", ";
    }

    cout << '\n';
}
