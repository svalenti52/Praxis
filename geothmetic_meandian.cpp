//
// Created by svale on 7/12/2021.
// Programming Praxis 13-Apr-2021
//

#include <complex>
#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>

int main()
{
    double a, b;

    a = 24.0;
    b = 6.0;

    double arithmetic_mean = (a + b) / 2;
    double geometric_mean = std::sqrt(a * b);

    while (std::abs(arithmetic_mean-geometric_mean) > 1.0E-8)
    {
        const auto am = arithmetic_mean;
        const auto gm = geometric_mean;

        arithmetic_mean = (am + gm) / 2;
        geometric_mean = std::sqrt(am * gm);
    }

    std::cout << "arithmetic geometric mean = " << std::setprecision(10) << arithmetic_mean << "\n\n";

    ///////////////////////////////////////////

    std::vector<double> list_of_numbers = {1.0, 1.0, 2.0, 3.0, 5.0};
    // Don't assume that the list is in order
    std::sort(list_of_numbers.begin(), list_of_numbers.end());

    double a_mean = std::accumulate(list_of_numbers.begin(), list_of_numbers.end(), 0.0) / list_of_numbers.size();
    double g_mean = std::pow(accumulate(list_of_numbers.begin(), list_of_numbers.end(), 1.0,
                                          std::multiplies<double>()), 1.0/list_of_numbers.size());
    double median;

    if (list_of_numbers.size() % 2 == 0)
        median = (list_of_numbers[list_of_numbers.size()/2-1] + list_of_numbers[list_of_numbers.size()/2]) / 2;
    else
        median = list_of_numbers[list_of_numbers.size()/2];

    while (std::abs(a_mean-g_mean) > 1.0E-8 || std::abs(g_mean-median) > 1.0E-8)
    {
        std::vector<double> gm = {a_mean, g_mean, median};
        std::sort(gm.begin(), gm.end()); // median is middle element of 3 now (index = 1)
        a_mean = std::accumulate(gm.begin(), gm.end(), 0.0) / gm.size();
        g_mean = std::pow(std::accumulate(gm.begin(), gm.end(), 1.0,
                                          std::multiplies<double>()), 1.0/gm.size());
        median = gm[1];
    }

    std::cout << "geothmetic meandian = " << std::setprecision(10) << a_mean;
}