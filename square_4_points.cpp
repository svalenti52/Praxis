//
// Created by svale on 10/26/2021.
// Praxis
// Four Points Determine A Square - 2-Jan-2013
// Apparently one of the comments was true
// i.e., there was one comment that the original solution
// worked if applied to three different points (I tried with
// two, but it was a simple matter to come up with a test
// that defeated it).  Have now changed to integers for
// the "square distance" since it all that is needed (as suggested
// in the original solution).

#include <iostream>
#include <vector>

void square_distance_from_anchor_point(std::vector<std::pair<int,int>>& points,
                                       std::vector<int>& distances,
                                       int anchor_index)
{
    int points_index = 0;  // 4 of these
    int distance_index = 0; // 3 of these
    for (std::pair<int,int>& p : points)
    {
        if (points_index == anchor_index) {
            ++points_index;
            continue;
        }
        int first_component = points[points_index].first - points[anchor_index].first;
        int second_component = points[points_index].second - points[anchor_index].second;
        distances[distance_index] = first_component*first_component + second_component*second_component;
        ++points_index;
        ++distance_index;
    }
}

bool is_square(std::vector<std::pair<int,int>>& points)
{
    if (points.size() != 4) return false;

    std::vector<int> distances(3,0);

    square_distance_from_anchor_point(points, distances, 0);
    std::sort(distances.begin(), distances.end());
    if (distances[0] != distances[1]) return false;
    if (distances[0] + distances[1] != distances[2]) return false;

    square_distance_from_anchor_point(points, distances, 1);
    std::sort(distances.begin(), distances.end());
    if (distances[0] != distances[1]) return false;
    if (distances[0] + distances[1] != distances[2]) return false;

    square_distance_from_anchor_point(points, distances, 2);
    std::sort(distances.begin(), distances.end());
    if (distances[0] != distances[1]) return false;
    if (distances[0] + distances[1] != distances[2]) return false;

    return true;
}

int main()
{
    std::vector<std::pair<std::vector<std::pair<int,int>>, std::string>> quad_set {
            {{{0,0}, {0, 1}, {1,1}, {1,0}}, "{0,0}, {0,1}, {1,1}, {1,0}"},
            {{{0,0}, {2, 1}, {3,-1}, {1,-2}}, "{0,0}, {2,1}, {3,-1}, {1,-2}"},
            {{{0,0}, {1, 1}, {0,1}, {1,0}}, "{0,0}, {1,1}, {0,1}, {1,0}"},
            {{{0,0}, {0, 2}, {3,2}, {3,0}}, "{0,0}, {0,2}, {3,2}, {3,0}"},
            {{{0,0}, {3, 4}, {8,4}, {5,0}}, "{0,0}, {3,4}, {8,4}, {5,0}"},
            {{{0,0}, {0, 0}, {1,1}, {0,0}}, "{0,0}, {0,0}, {1,1}, {0,0}"},
            {{{0,0}, {0, 0}, {1,0}, {0,1}}, "{0,0}, {0,0}, {1,0}, {0,1}"},
            {{{0,0}, {1, 0}, {0,1}, {-1,-1}}, "{0,0}, {1,0}, {0,1}, {-1,-1}"},
            {{{0,0}, {1,0}, {1,0}, {1,1}}, "{0,0}, {1,0}, {1,0}, {1,1}"},
            {{{0,0}, {1,1}, {1,0}, {1,0}}, "{0,0}, {1,1}, {1,0}, {1,0}"},
            {{{0,0}, {1,1}, {1,0}, {1,0}}, "{1,1}, {0,0}, {1,0}, {1,0}"}

    };

    auto print_is_square = [](std::vector<std::pair<int,int>>& points, std::string& s)
    {
        if (is_square(points))
            std::cout << "Rectangle " << s << " = TRUE\n";
        else
            std::cout << "Rectangle " << s << " = FALSE\n";
    };

    for (std::pair<std::vector<std::pair<int,int>>, std::string>& q : quad_set)
        print_is_square(q.first, q.second);
}
