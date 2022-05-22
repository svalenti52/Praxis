//
// Created by svale on 5/20/2022.
//
////
//// Reciprocal Palindromes
//// 30-Nov-2021
//// Takes about 116 seconds to compute for 1,000,000,000 on my computer
////
//// Attempting to do parallel processing...
//// Able to calculate for 160,000,000,000 in 188 seconds for converging to 3.370278613
//// Also, this accounts for a seqeunce of 1,319,998 palindromes
//// This is without the Kahan summation
//// Also this appears less efficient than the method shown in the solution
//// given by Matthew; he actually generates the palindromes while looping,
//// dispensing with checking for non-palindromes

#include <cstdint>
#include <vector>
#include <val/montecarlo/Chronology.h>
#include <iomanip>
#include <future>
#include <mutex>

using u64 = uint64_t;

u64 nr_palindromes = 0;

std::mutex m;

static auto process_palindrome(u64 number)
{
    u64 straight = number;
    u64 reversed = 0;

    while(number != 0)
    {
        reversed = (reversed * 10) + (number % 10);
        number = number / 10;
    }
    if (straight == reversed) {
        std::lock_guard lk(m);
        ++nr_palindromes;
        return 1.0 / static_cast<double>(straight);
    }
    return static_cast<double>(0);
}

struct thread_spec
{
    u64 nr_palindromes;
    u64 begin_ix;
    u64 end_ix;
    std::future<double> partial_sum;
    thread_spec(u64 b, u64 e) : begin_ix(b), end_ix(e), nr_palindromes(0) {}
};

int main()
{
    const u64 ub = 16'000'000'000;
    const int nr_threads = 16;

    auto process_pal([](u64 begin_ix, u64 end_ix) {
        //auto s = std::async(std::launch::deferred, process_palindrome, i);
        double sum = 0;
        for (u64 ix = begin_ix; ix < end_ix; ++ix)
            sum += process_palindrome(ix);
        return sum;
    });

    u64 diff_ix = ub / 16;
    std::vector<thread_spec> threads;
    for (int ix = 0; ix < nr_threads; ++ix)
        threads.emplace_back(thread_spec(ix*diff_ix+1, ix*diff_ix+1+diff_ix));

    StopWatch s;

    for (thread_spec& t : threads)
        t.partial_sum = std::async(std::launch::async, process_pal, t.begin_ix, t.end_ix);

    double sum = 0;
    for (thread_spec& t : threads)
        sum += t.partial_sum.get();

    std::cout << "Reciprocal palindromes converge to " << std::setprecision(10) << sum << '\n';

    std::cout << "count of palindromes is " << nr_palindromes << '\n';

    s.stop();
}
