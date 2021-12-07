//
// Created by svale on 12/7/2021.
//
//// $7.11 - 27-Nov-2009
////

#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

using u32 = uint32_t;

int main()

{
    std::vector<u32> price (4, 0);
    bool found = false;

    const u32 target = 711'000'000; // decimal place moved over to account for multiplication
                                    // i.e., 7.11 => 711,000,000 for multiplying 4 whole numbers

    for (price[0] = 79; price[0] < 711 && !found; price[0] += 79) // 79 is prime factor of target
    {
        for (price[1] = 25; price[1] < 711 - price[0] && !found; price[1] += 25) // 5^5 split among remaining 3 factors
                                                                                // (don't know apriori if a 5 is factor
                                                                                // of price[0])
        {
            for (price[2] = 5; price[2] <= 711 - price[0] - price[1] && !found; price[2] += 5) // at least one five to another...
            {
                price[3] = 711 - (price[0] + price[1] + price[2]);  // price[3] is determined once the other 3 are known

                u32 product = std::accumulate(price.begin(), price.end(), 1, std::multiplies<>());

                if (product == target) {
                    found = true;
                    std::cout << "1=" << price[0] << "  "
                              << "2=" << price[1] << "  "
                              << "3=" << price[2] << "  "
                              << "4=" << price[3] << '\n';
                }
            }
        }
    }

}
