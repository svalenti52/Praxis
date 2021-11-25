// coin_change_2.cpp
// 19-Nov-2021
////
//// Coin Change, Part 2
//// May 21, 2013
////

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using u32 = uint32_t;

using coin_sets = std::tuple<u32, u32, u32, u32>;

bool compare_elements(coin_sets& lhs, coin_sets& rhs)
{
	using namespace std;

	u32 lhs_count = get<0>(lhs) + get<1>(lhs) + get<2>(lhs) + get<3>(lhs);
	u32 rhs_count = get<0>(rhs) + get<1>(rhs) + get<2>(rhs) + get<3>(rhs);
	
	return lhs_count < rhs_count;
}

std::ostream& operator << (std::ostream& o, coin_sets& c)
{
	o << "Q=" << std::get<0>(c) << ", "
		<< "D=" << std::get<1>(c) << ", "
		<< "N=" << std::get<2>(c) << ", "
		<< "P=" << std::get<3>(c);
	return o;
}

int main(int argc, char** argv)
{
	using namespace std;
	tuple<u32, u32, u32, u32> coin_set;
	vector<tuple<u32, u32, u32, u32>> coins;  // count of <quarters, dimes, nickels, pennies>
	const u32 quarter = 25;
	const u32 dime = 10;
	const u32 nickel = 5;
	const u32 penny = 1;

	if (argc != 2) {std::cout << "usage: <program> <total amount>\n"; return 1;}
    const u32 amount = strtoul(argv[1], nullptr, 10);

	for (u32 q = 0; q <= amount; q += quarter)
	{
		u32 amount_left_after_q = amount - q;
		for (u32 d = 0; d <= amount_left_after_q; d += dime)
		{
			u32 amount_left_after_d = amount_left_after_q - d;
			for (u32 n = 0; n <= amount_left_after_d; n += nickel)
			{
				u32 amount_left_after_n = amount_left_after_d - n;
				
				coin_set = make_tuple(q/quarter, d/dime, n/nickel, amount_left_after_n);
				coins.push_back(coin_set);
			}
		}
	}
	
	auto p =
		min_element(coins.begin(), coins.end(), compare_elements);

	cout << "Minimum set of coins required = " << *p << '\n';
}
