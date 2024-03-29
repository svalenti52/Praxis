// penny.cpp

#include <iostream>
// #include <fstream>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <tuple>
#include <stack>

std::map<int, char> alpha_map
	{
		{0, 'A'},
		{1, 'B'},
		{2, 'C'},
		{3, 'D'},
		{4, 'E'},
		{5, 'F'},
		{6, 'G'},
		{7, 'H'},
		{8, 'I'},
		{9, 'K'},
		{10, 'L'},
		{11, 'M'},
		{12, 'N'},
		{13, 'O'},
		{14, 'P'},
		{15, 'Q'},
		{16, 'R'},
		{17, 'S'},
		{18, 'T'},
		{19, 'U'},
		{20, 'V'},
		{21, 'W'},
		{22, 'X'},
		{23, 'Y'},
		{24, 'Z'}
	};

std::string beta_map("ABCDEFGHIKLMNOPQRSTUVWXYZ");

struct State_Stack
{
	int state;
	int transition_to_state;
	double cost;
	State_Stack(int s, int t, double c) : state(s), transition_to_state(t), cost(c) {}
};

std::stack<State_Stack> state_stack;
std::stack<State_Stack> print_order_stack;

class Segments
{
    std::set<std::pair<int, int>> segments;

    static auto make_ordered_pair(int i, int j)
    {
        if (i<j)
            return std::make_pair(i, j);
        else
            return std::make_pair(j, i);
    }

public:
    Segments()
            :segments({std::make_pair(0, 1), std::make_pair(1, 2)}) { }

	void Store(int x, int y)
	{
	    auto ordered_pair = make_ordered_pair(x, y);
	    segments.insert(ordered_pair);
	}

	bool Find(int x, int y)
	{
		auto segment = make_ordered_pair(x,y);
		return
			find(segments.begin(), segments.end(),
				segment) != segments.end();
	}

	void Delete(int x, int y)
    {
        auto segment = make_ordered_pair(x,y);
		segments.erase(segment);
	}
};

double calc_cost(int state, int tx, double i_cost)
{
	double cost = i_cost;
	if (state - 5 == tx)
		cost /= 2;
	else if (state - 1 == tx)
		cost -= 2;
	else if (state + 1 == tx)
		cost += 2;
	else if (state + 5 == tx)
		cost *= 2;
	return cost;
}

class StateMachine
{
	std::vector<int> states{};
	int from_state;
	double cost;
	int count;
	Segments duplicate_edge;
public:
	std::vector<std::vector<int>> transitions;

    StateMachine()
            : transitions(25, states), from_state(2), cost(4.0), count(0)
	{
		transitions[0] = {};
        transitions[1] = {};
		transitions[2] = {3, 7};
		transitions[3] = {4, 8}; // 2 could not arrive at end from_state 24
		transitions[4] = {3, 9};

		transitions[5] = {6, 10};
		transitions[6] = {5, 7, 11};
		transitions[7] = {6, 8, 12}; // 2 could not arrive at end from_state 24
		transitions[8] = {3, 7, 9, 13};
		transitions[9] = {4, 8, 14};

        transitions[10] = {5, 11, 15};
        transitions[11] = {6, 10, 12, 16};
        transitions[12] = {7, 11, 13, 17};
        transitions[13] = {8, 12, 14, 18};
        transitions[14] = {9, 13, 19};

        transitions[15] = {10, 16, 20};
        transitions[16] = {11, 15, 17, 21};
        transitions[17] = {12, 16, 18, 22};
        transitions[18] = {13, 17, 19, 23};
        transitions[19] = {14, 18, 24};

        transitions[20] = {15, 21};
        transitions[21] = {16, 20, 22};
        transitions[22] = {17, 21, 23};
        transitions[23] = {18, 22, 24};
        transitions[24] = {};
    }

    static void print_stack()
    {
        while (!state_stack.empty())
        {
            State_Stack s = state_stack.top();
            print_order_stack.push(s);
            state_stack.pop();
        }

        while (!print_order_stack.empty())
        {
            State_Stack s = print_order_stack.top();
            state_stack.push(s);
            print_order_stack.pop();
            int diff = s.transition_to_state - s.state;
            switch (diff)
            {
            case -5:
                std::cout << 'n';
                break;
            case -1:
                std::cout << 'w';
                break;
            case 1:
                std::cout << 'e';
                break;
            case 5:
                std::cout << 's';
                break;
            default:
                std::cout << 'X';
                break;
            }
        }
    }

    static void print_stack_nodes()
    {
        while (!state_stack.empty())
        {
            State_Stack s = state_stack.top();
            print_order_stack.push(s);
            state_stack.pop();
        }

        while (!print_order_stack.empty())
        {
            State_Stack s = print_order_stack.top();
            state_stack.push(s);
            print_order_stack.pop();
            std::cout << beta_map[s.transition_to_state] << ' ';
        }
        std::cout << '\n';
    }

    void transit_states()
    {

        if (from_state == 24)
        {
            // ++count;
            if (cost<=00.0)
            {
                ++count;
                std::cout << count << ". reached 24 at cost of " << cost << '\n';
                print_stack();
                // print_stack_nodes(); // for alternate representation;
                std::cout << '\n';
            }
            return;
        }
		for (auto to_state : transitions[from_state])
		{
			if (duplicate_edge.Find(from_state, to_state)) continue;

			Push(from_state, to_state, cost); // before to_state cost

			cost = calc_cost(from_state, to_state, cost); // after to_state cost

			from_state = to_state;

			transit_states();

			State_Stack s = Pop();
            from_state = s.state;
			cost = s.cost;
		}
	}
	
	void Push(int s, int t, double c)
	{
		State_Stack z(s, t, c);
		state_stack.push(z);
		duplicate_edge.Store(z.state, z.transition_to_state);
	}
	
	State_Stack Pop()
	{
		State_Stack s = state_stack.top();
		state_stack.pop();
		duplicate_edge.Delete(s.state, s.transition_to_state);
		return s;
	}
	
	friend std::ostream& operator << (std::ostream& o, const StateMachine& t);
};

std::ostream& operator << (std::ostream& o, const StateMachine& t)
{
	o << t.transitions.size() << '\n';
	for (auto& ix : t.transitions)
		o << ix.size() << " ";
	return o;
}

int main(int argc, char** argv)
{
	using namespace std;
	
	StateMachine sm;
	
	sm.transit_states();
}
