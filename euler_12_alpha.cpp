// euler_12.cpp

#include <iostream>

using u64 = uint64_t;

u64 number_of_divisors(u64 low_factor)
{
	// triangular numbers are of the form (index * (index+1)) / 2
	u64 count1 = 2; // initialized to account for 1 and index
	u64 count2 = 2; // initialized to account for 1 and index+1

	u64 ofactor = low_factor + 1;

	if (low_factor % 2 == 0) low_factor /= 2; // get the divide by 2 out of the way
	else ofactor /= 2;
	
	for (u64 ix = 2; ix <= low_factor/2; ++ix)
		if (low_factor % ix == 0)
			++count1;

	for (u64 ix = 2; ix <= ofactor/2; ++ix)
		if (ofactor % ix == 0)
			++count2;

	// we are also using the fact that two numbers index and (index+1) are coprime
	// i.e., the factors of one are completely different than the factors of the other
	return count1 * count2;
}

//-----------------------------------------------------------------------------


int main(int argc, char** argv)
{
	u64 i = 0;
	u64 x = 0;
	
	for (u64 ix = 1; ix <= 13'000; ++ix)
	{
		
		u64 c = number_of_divisors(ix);
		
		if ( c > x)
		{
			x = c;
			i = ix;
			if (c > 500) break;
		}

		std::cout << ix << " gives " << c << " divisors\n";
	}
	
	std::cout << "\n\nFor " << i << " the number of divisors is " << x << '\n';
}
