//
// Created by svale on 5/21/2022.
//
//// Actually this is a copy of Matthew's code as
//// listed on the Programming Praxis website.
//// (the first column includes the Kahan summation, the second is the "naive" straightforward sum)
//// Reciprocal Palindromes
//// 30-Nov-2021

#include <vector>
#include <cstdlib>
#include <cstdio>

void nextpal(std::vector<int> &s) {
    auto len = s.size();
    for (auto n = (len+1)/2; n > 0; n--) {
        if (s[n-1] < 9) {
            s[len-n] = s[n-1] = s[n-1]+1;
            return;
        } else {
            s[len-n] = s[n-1] = 0;
        }
    }
    // wrap around to all zero, so extend
    s[0] = 1;
    s.push_back(1);
}

double todouble(std::vector<int>& s) {
    double x = 0.0, r = 1.0;
    // Going from smaller to larger should be accurate
    // here, so no fancy summation needed.
    for (auto i = s.begin(); i != s.end(); i++) {
        x += (*i)*r;
        r *= 10.0;
    }
    return x;
}

int main(int argc, char *argv[]) {
    long count = std::strtol(argv[1],0,0);
    std::vector<int> s = { 1 };
    double sum = 0, sum0 = 0;
    double c = 0; // Compensation
    for (long i = 1; ; i++) {
        if (i%count == 0) {
            std::printf("%20.18f %20.18f %ld\n", sum, sum0, i);
        }
        double y = 1/todouble(s);
        sum0 += y; // Add in to naive sum
        y -= c;    // Subtract correction
        double t = sum + y; // Add to sum
        c = (t - sum) - y;  // New compensation
        sum = t; // New sum
        nextpal(s);
    }
}
