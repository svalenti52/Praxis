
//// tower_hanoi.cpp
//// 13-Dec-2021
//// Tower Of Hanoi - 11-Oct-2011

//// This is code is contributed by rathbhupendra
//// Give credit where credit is due.
//// Changed names from "rod" to "tower"
//// 'A' to "src"
//// 'B' to "alt"
//// 'C' to "dst"

#include <iostream>
#include <string>

// C++ recursive function to
// solve tower of hanoi puzzle
using namespace std;

void print_move(int n, string& from_tower, string& to_tower)
{
    static int counter = 0;
    cout << ++counter << ". Move disk " << n << " from " << from_tower <<
         " to " << to_tower << endl;
}

void towerOfHanoi(int n, string& from_tower,
                  string& to_tower, string& alt_tower)
{
    if (n == 1)
    {
        print_move(n, from_tower, to_tower);
        return;
    }
    towerOfHanoi(n - 1, from_tower, alt_tower, to_tower);
    print_move(n, from_tower, to_tower);
    towerOfHanoi(n - 1, alt_tower, to_tower, from_tower);
}

int main()
{
    int n = 4; // Number of disks
    string s {"src"}, d{"dst"}, a{"alt"};
    towerOfHanoi(n, s, d, a); // A, B and C are names of rods
    return 0;
}