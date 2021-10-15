Praxis

Problems taken from the website Programming Praxis.

Project Euler 12 - 29-Mar-2019

    Take the subset of natural numbers that are the triangle numbers.
    Find the least member of the triangle numbers such that the number
    of divisors is greater than 500. The number of divisors includes
    1 and the number itself.
    
    Note that a triangle number is of the form n(n+1)/2, with n being
    a member of the natural numbers.
    
    Another way of computing the sequence of triangle numbers is:
    1: 1
    2: 1 + 2
    3: 1 + 2 + 3
    4: 1 + 2 + 3 + 4
    5: 1 + 2 + 3 + 4 + 5
    etc.

Penniless Pilgrim - 10-Aug-2019

    The basis of this problem is a square 5 by 5 grid. This represents a
    map of Duonia and the title of the problem has to do with having a pilgrim
    traverse the grid from the upper left hand corner to the lower right
    corner. Traversing the grid has an attendant cost calculated as follows:
    Traveling right (east) adds a cost of 2 units.
    Traveling left (west) subtracts a cost of 2 units.
    Traveling down (south) multiplies the current cost by 2.
    Traveling up (north) divides the current cost by 2.
    Once a segment is traversed between adjacent grid points, it may not be
    taken again.
    The adjective in the title has do with finding a path such that the total
    cost is zero. The problem starts with the fact the penniless pilgrim
    has taken two grid steps to the east and so carries a cost of 4.0 so far...

Perfect Totient Numbers - 9-Jan-2019

    List all the perfect totient numbers less than 10,000.  A totient number is
    the iterated sum of the number's totients.  A perfect totient number is a
    totient number that is equal to the number itself.
    But what are totients?  The totient of N is defined to be numbers less than
    N and also coprime to N (note, 1 is coprime to all N).
    Finally, to get back to what is meant by "iterated sum of the number's totients":
    Letting the number be 327 and T be the totient function, we have that sum being
    T(327) + T(216) + T(72) + T(24) + T(8) + T(4) + T(2) = 216 + 72 + 24 + 8 + 4 +
    2 + 1 = 327 (which means 327 is a perfect totient number).  Note that the iterated
    sum for the number 327 is derived from T(327) = 216, T(216) = 72, T(72) = 24, etc.

Almost Prime - 19-Apr-2019

    A k-almost-prime is a number > 1 that is product of k primes.  A squarefree
    k-almost-prime is a number that is the product of k distinct primes.
    Find the set of the first 10 k-almost-prime numbers, then the set of the first
    squarefree k-almost-prime numbers, where k is taken from the range [1, 5].

Collatz Primes - 1-May-2015

    A Collatz Sequence is one that starts with a given natural number, N.  It then
    proceeds by N/2 if N is even, 3N+1 if N is odd.  The Collatz Sequence terminates
    when reaches the value 1.  The Collatz Conjecture is that all Collatz Sequences
    terminate.
    Find the first Collatz Sequence that contains 65 or more primes.

Hailstones - 17-Feb-2012

    This is to do with the Collatz Sequence.  Its tendency to go up-and-down repeatedly
    like hailstones in a thundercloud suggests the title for this article.
    For this item, selected the task of finding the number with the maximum sized
    Collatz Sequence for the range 1..1,600,000.

Approximate Squaring - 8-Jun-2021

    Take a fraction n/d with n > d > 1 and let c be the ceiling of the fraction (the
    ceiling is the smallest integer greater than or equal to the fraction).  If d does
    not divide n evenly, then multiply the fraction by c giving a new value for n.
    Repeat the process of the last sentence until d does divide n evenly.
    The map f(n/d) = n/d * c where c is the ceiling of n/d, is referred to as the
    approximate squaring map for obvious reasons.  It is conjectured but not proven
    that the iterative mapping process will always terminate (i.e., d will eventually
    divide n evenly).
    As reported in the original Programming Praxis article, the number of iterations
    is chaotic:  8/7 terminates in 3 steps resulting in a final value of 48,
    6/5 terminates in 18 steps with a final value that is 57735 digits long, and
    200/199 goes to a number with 10^435 digits (I think I will pass on this one...).
    Implements a naive algorithm for now, no attempt at reducing due to common factors
    and other possible improvements.  Uses Boost multiprecision library.  Using Boost
    1.66.0, it doesn't seem to compile with gcc option -std=c++20, but it does work with
    -std=c++17.

Motzkin Numbers - 14-Sep-2021

    I have an easier time understanding the following definition of Motzkin numbers:
    For a given natural number N, the number of distinct grid paths leading from
    point (0,0) to (N,0) using as steps (1,-1), (1,0), or (1,1) with the proviso that
    the path never wander into negative territory.  For example, starting at (0,0) we
    add (1,1) end up at (1,1); if we add (1,1) again, we arrive at (2,2).  If instead
    we add (1,-1) to (0,0) we get (1,-1) - this path is not allowed (see above proviso).
