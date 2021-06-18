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
