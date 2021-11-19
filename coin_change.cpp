// coin_change.cpp
// 18-Nov-2021
////
//// Coin Change, Part 1
//// May 17, 2013
////

#include <iostream>

using u32 = uint32_t;

int main(int argc, char** argv)
{
	const u32 quarter = 25;
	const u32 dime = 10;
	const u32 nickle = 5;
	const u32 penny = 1;

	if (argc != 2) {std::cout << "usage: <program> <total amount>\n"; return 1;}
    const u32 amount = strtoul(argv[1], nullptr, 10);

	u32 count = 1;
	for (u32 q = 0; q <= amount; q += quarter)
	{
		u32 amount_left_after_q = amount - q;
		for (u32 d = 0; d <= amount_left_after_q; d += dime)
		{
			u32 amount_left_after_d = amount_left_after_q - d;
			for (u32 n = 0; n <= amount_left_after_d; n += nickle)
			{
				u32 amount_left_after_n = amount_left_after_d - n;
				std::cout << count << ". Q=" << q/quarter << ", "
					<< "D=" << d/dime << ", "
					<< "N=" << n/nickle << ", "
					<< "P=" << amount_left_after_n << '\n';
				++count;
			}
		}
	}
}
