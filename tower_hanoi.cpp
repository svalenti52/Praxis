
//// tower_hanoi.cpp
//// 13-Dec-2021
//// Tower Of Hanoi - 11-Oct-2011

//// This is code is contributed by rathbhupendra
//// Give credit where credit is due.
//// Changed names from "rod" to "tower"
//// 'A' to "src"
//// 'B' to "alt"
//// 'C' to "dst"

//// Actually I have since changed it to print out the internal values of the towers at each move
//// '0' represents no disk in the current location (all '0's represent no disks on a given tower)
//// numbers 1 through n appear in their corresponding position within the tower, with 1 representing the smallest disk
////

#include <iostream>
#include <vector>
#include <numeric>

// C++ recursive function to
// solve tower of hanoi puzzle
using namespace std;

enum class Absolute_Location
{
    Source,
    Destination,
    Alternate
};

using Tower = pair<Absolute_Location, vector<int>>;

static int counter = 0;

void select_tower_location(Tower& role_tower, Tower** first_tower, Tower** second_tower, Tower** third_tower)
{
    switch (role_tower.first) {
        case Absolute_Location::Source:
            *first_tower = &role_tower;
            break;
        case Absolute_Location::Destination:
            *second_tower = &role_tower;
            break;
        default:
            *third_tower = &role_tower;
            break;
    }
}

void print_towers(Tower& from_tower, Tower& to_tower, Tower& alt_tower)
{
    ++counter;
    Tower* first_tower;
    Tower* second_tower;
    Tower* third_tower;

    select_tower_location(from_tower, &first_tower, &second_tower, &third_tower);

    select_tower_location(to_tower, &first_tower, &second_tower, &third_tower);

    select_tower_location(alt_tower, &first_tower, &second_tower, &third_tower);

    for (int x : first_tower->second)
        cout << x << ", ";
    cout << "    ";
    for (int x : second_tower->second)
        cout << x << ", ";
    cout << "    ";
    for (int x : third_tower->second)
        cout << x << ", ";
    cout << '\n';
}

void towerOfHanoi(int n, Tower& from_tower_role,
                  Tower& to_tower_role, Tower& alt_tower_role)
{
    if (n == 0) return;
    towerOfHanoi(n - 1, from_tower_role, alt_tower_role, to_tower_role);
    from_tower_role.second[n - 1] = 0;
    to_tower_role.second[n - 1] = n;
    print_towers(from_tower_role, to_tower_role, alt_tower_role);
    towerOfHanoi(n - 1, alt_tower_role, to_tower_role, from_tower_role);
}

int main()
{
    const int n = 12; // Number of disks
    vector<int> v(n, 0);
    Tower src{Absolute_Location::Source, v},
        dst{Absolute_Location::Destination, v},
        alt{Absolute_Location::Alternate, v};
    iota(src.second.begin(), src.second.end(), 1);  // numbers the disks from 1 to n representing the disks

    towerOfHanoi(n, src, dst, alt);
    cout << "\nNumber of disk moves = " << counter << '\n';
}
