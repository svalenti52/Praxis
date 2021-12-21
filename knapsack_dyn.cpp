//
// Created by svalenti on 12/20/2021.
//

////
//// Knapsack - August 23, 2011
//// Now the dynamic programming approach
//// We derive a matrix using the recurrence relation
//// V[i, w] = max(V[i-1, w], v_sub_i + V[i-1, w-w_sub_i])
////     where w is taken from 0<= w <= W (W is the knapsack capacity)
////     and V[0, w] = 0
////
//// This code is contributed by Debojyoti Mandal
//// Modifying some to use more C++ features
//// Also including the ability to identify the items by name
//// instead of just returning the max value WIP
////

#include <iostream>
#include <vector>
#include <array>

// A dynamic programming based
// solution for 0-1 Knapsack problem
using namespace std;

const int items_size = 3;

// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, array<int, items_size>& wt, array<int, items_size>& val, int n)
{
    int i, w;
    vector<vector<int>> K(n+1, vector<int>(W+1));

    // Build table K[][] in bottom up manner
    for (i = 0; i<=n; i++)
    {
        for (w = 0; w<=W; w++)
        {
            if (i==0 || w==0)
                K[i][w] = 0;
            else if (wt[i-1]<=w)
                K[i][w] = max(val[i-1]+
                                K[i-1][w-wt[i-1]],
                        K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }
    return K[n][W];
}

// Driver Code
int main()
{
    string nm{"ABC"};
    std::array<int, items_size> val{60, 100, 120};
    std::array<int, items_size> wt{10, 20, 30};
    int W = 50;
    int n = val.size();

    cout << knapSack(W, wt, val, n);

    return 0;
}

// This code is contributed by Debojyoti Mandal