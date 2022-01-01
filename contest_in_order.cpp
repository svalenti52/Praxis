//
// Created by svalenti on 12/31/2021.
//


//// International Mathematical Olympiad
////        July 17, 2009
////
//// IMO 1963 Problem 06
////
//// Five students, A,B,C,D,E, took part in a contest. One prediction was that the contestants would finish in the order ABCDE.
//// This prediction was very poor. In fact no contestant finished in the position predicted, and no two contestants predicted
//// to finish consecutively actually did so. A second prediction had the contestants finishing in the order DAECB.
//// This prediction was better. Exactly two of the contestants finished in the places predicted, and two disjoint pairs of
//// students predicted to finish consecutively actually did so. Determine the order in which the contestants finished.

#include <vector>
#include <string>
#include <iostream>

// ------------------------------------------------------------------

bool passes_poor_prediction(const std::vector<char>& candidate)
{
    const std::string poor_prediction{'A', 'B', 'C', 'D', 'E'};
    std::string proposed;
    for (char c: candidate)
        proposed.push_back(c);

    for (int ix = 0; ix<poor_prediction.size(); ++ix)
    {
        if (poor_prediction[ix]==proposed[ix])
            return false;
        if (ix==poor_prediction.size()-1)
            break;
        if (proposed.find(poor_prediction.substr(ix, 2), 0)!=std::string::npos)
            return false;
    }
    return true;
}

// ------------------------------------------------------------------

bool passes_better_prediction(const std::vector<char>& candidate)
{
    const std::string better_prediction{'D', 'A', 'E', 'C', 'B'};
    std::string proposed;
    for (char c: candidate)
        proposed.push_back(c);

    int exact_order_count = 0;
    int exact_2_consecutive_order_count = 0;
    for (int ix = 0; ix<better_prediction.size(); ++ix)
    {
        if (better_prediction[ix]==proposed[ix])
            ++exact_order_count;
        if (ix==better_prediction.size()-1)
            break;
        if (proposed.find(better_prediction.substr(ix, 2), 0)!=std::string::npos)
            ++exact_2_consecutive_order_count;
    }
    if (exact_order_count==2 && exact_2_consecutive_order_count==2)
        return true;
    return false;
}

// ------------------------------------------------------------------

int main()
{
    std::vector<char> symbols{'A', 'B', 'C', 'D', 'E'};

    std::cout << '\n';
    do
    {
        if (passes_poor_prediction(symbols) && passes_better_prediction(symbols))
        {
            for (char c: symbols)
                std::cout << c;
            std::cout << '\n';
        }
    }
    while (std::next_permutation(symbols.begin(), symbols.end()));
}
