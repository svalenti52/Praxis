//
// A Number Puzzle
// 21-Jul-2015
// Created by svale on 10/25/2021.
//

#include <vector>
#include <iostream>

void number_from_digits(const std::vector<uint64_t>& digits,
                            std::vector<uint64_t>& num_seq)
{

    for (uint64_t ix = 1; ix <= 10; ++ix)
    {
        num_seq[ix-1] = 0;
        for (uint64_t jx =0; jx < ix-1; ++jx)
            num_seq[ix-1] = (digits[jx]+num_seq[ix-1]) * 10;
        num_seq[ix-1] += digits[ix-1];
    }
}

bool perfectly_divisible_in_sequence(const std::vector<uint64_t>& num_seq)
{
    for (uint64_t divisor = 1; divisor <= 10; ++divisor)
        if (num_seq[divisor-1] % divisor != 0)
            return false;
    return true;
}

int main()
{
    std::vector<uint64_t> digits {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<uint64_t> numbers_from_digit_sequence(10, 0);

    do
    {
        number_from_digits(digits, numbers_from_digit_sequence);

        if (perfectly_divisible_in_sequence(numbers_from_digit_sequence))
            std::cout << "number is = " << numbers_from_digit_sequence[9] << '\n';

    } while (std::next_permutation(digits.begin(), digits.end()));
}