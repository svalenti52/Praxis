//
// Created by svale on 12/16/2021.
//

////
//// Knapsack - August 23, 2011
//// The brute force approach first
//// We compute the possible permutations that don't violate the weight capacity
//// and then compute the best value out of that subset
////


#include <iostream>
#include <random>
#include <val/montecarlo/Combinatorics.h>

using u32 = uint32_t;

struct Item
{
    char name;
    u32 weight;
    u32 value;
    Item(const char c, u32 i_weight, u32 i_value) : name(c), weight(i_weight), value(i_value){}
};

bool operator < (Item& lhs, Item& rhs)
{
    return lhs.weight < rhs.weight;
}

u32 operator + (Item& lhs, Item& rhs)
{
    return lhs.weight + rhs.weight;
}

u32 add_value(Item& lhs, Item& rhs)
{
    return lhs.value + rhs.value;
}

std::vector<Item> items;
const u32 knapsack_weight_capacity = 25;

bool candidate_items_selector(std::vector<u32>& v)
{
    u32 total_weight = 0;
    for (u32 ix = 0; ix < v.size(); ++ix) {
        if (v[ix] == 0) continue;
        total_weight += items[ix].weight;
    }
    if (total_weight > knapsack_weight_capacity)
        return false;
    return true;
}

std::ostream& operator << (std::ostream& oss, Item& item)
{
    oss << item.name << ", weight=" << item.weight << ", value=" << item.value << '\n';
    return oss;
}

int main()
{
    std::default_random_engine dre(0);
    std::uniform_int_distribution<u32> weight(1, 20);
    std::uniform_int_distribution<u32> value(1, 50);

    std::string names {"ABCDEFGHIJ"};
    std::vector<u32> weight_fixed {12, 1, 4, 2, 1};
    std::vector<u32> value_fixed{4, 2, 10, 2, 1};
    const u32 number_of_items = names.size();

    for (int ix = 0; ix != names.size(); ++ix)
    {
        items.emplace_back(Item(names[ix], weight(dre), value(dre)));
    }

    std::sort(items.begin(), items.end());

    for (Item i : items)
    {
        std::cout << i;
    }

    //-----------------------------------------------------------------

    std::vector<u32> symbols {0, 1};

    std::vector<std::vector<u32>> candidate_solutions;
    std::vector<u32> indicators;

    // This calculates the candidate permutations that don't exceed the weight maximum
    // A '0' indicates that the item is not included, a '1' indicates that the item is included
    create_combinatorial_element_set<u32>(symbols, candidate_solutions, indicators, 0, number_of_items,
                                          candidate_items_selector, permutations_with_repetition<u32>);

    u32 maximum_value = 0;
    u32 max_item_set_index = 0;

    // And this calculates the maximum value from the candidate permutations
    for (u32 set_ix = 0; set_ix < candidate_solutions.size(); ++set_ix)
    {
        u32 current_value = 0;
        for (u32 item_ix = 0; item_ix < items.size(); ++item_ix)
        {
            if (candidate_solutions[set_ix][item_ix] == 1)
                current_value += items[item_ix].value;
        }
        if (current_value > maximum_value) {
            maximum_value = current_value;
            max_item_set_index = set_ix;
        }
    }

    std::cout << "Index = " << max_item_set_index << '\n';

    std::vector<u32> items_maximum_value_indicator = candidate_solutions[max_item_set_index];

    for (u32 item_ix = 0; item_ix < items.size(); ++item_ix)
        if (items_maximum_value_indicator[item_ix] == 1)
            std::cout << items[item_ix];
}
