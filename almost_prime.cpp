// almost_prime.cpp
// praxis 19-Apr-2019

#include <iostream>
#include <vector>
#include <tuple>
#include <sstream>

using namespace std;

void print_almost_primes(vector<vector<int>>& v)
{
	int index = 1;
	for (vector<int>& vi : v)
	{
		cout << "First 10 " << index++ << "-Almost-Prime:  ";
		for (int ix : vi)
			cout << ix << ' ';
		cout << '\n';
	}
}

int number_of_prime_factors(int candidate) {

    vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43};

    int nr_factors = 0;
    for (int p : primes)
    {
        int t = candidate;
        while (t % p == 0)
        {
            t /= p;
            ++nr_factors;
        }
        if (t == 1) break;
    }
    return nr_factors;
}

std::tuple<bool, int> number_of_distinct_prime_factors(int candidate) {

    vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43};

    int nr_factors = 0;
    bool square_free = true;
    for (int p : primes)
    {
        int t = candidate;
        int inner_loop = 0;
        while (t % p == 0)
        {
            t /= p;
            ++nr_factors;
            ++inner_loop;
            if (inner_loop > 1)
                square_free = false;
        }
        if (t == 1)
            break;
    }
    return make_tuple(square_free, nr_factors);
}

int main(int argc, char** argv)
{
    if (argc != 2) {cout << "usage: argument is 'd' for distinct, 'r' for repeated"; return 1; }

	vector<int> vi;

	vector<vector<int>> almost_primes{vi, vi, vi, vi, vi};
	bool square_free = true;
	int nr_factors;

	for (int ix = 2; ix < 10'000; ++ix)
	{
	    ostringstream oss;
	    oss << argv[1];
        if (oss.str() == "d")
		    tie(square_free, nr_factors) = number_of_distinct_prime_factors(ix);
        else if (oss.str() == "r")
            nr_factors = number_of_prime_factors(ix);
        else
        {
            cout << oss.str() << '\n';
            return 2;
        }

		if (square_free)
		{
            switch (nr_factors) {
                case 1:
                    if (almost_primes[0].size() < 10)
                        almost_primes[0].push_back(ix);
                    break;
                case 2:
                    if (almost_primes[1].size() < 10)
                        almost_primes[1].push_back(ix);
                    break;
                case 3:
                    if (almost_primes[2].size() < 10)
                        almost_primes[2].push_back(ix);
                    break;
                case 4:
                    if (almost_primes[3].size() < 10)
                        almost_primes[3].push_back(ix);
                    break;
                case 5:
                    almost_primes[4].push_back(ix);
                    break;
                default:
                    break;
            }
        }
		
		if (almost_primes[4].size() == 10) break;
	}
	
	print_almost_primes(almost_primes);
}
