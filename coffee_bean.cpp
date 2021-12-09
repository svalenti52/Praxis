/**
 * \file coffee_bean.cpp
 * \date 8-Dec-2021
 *
 * Praxis
 * David Gries’ Coffee Can Problem - 22-Oct-2013
 * \brief
 */

#include <algorithm>
#include <val/montecarlo/Chronology.h>
#include <val/montecarlo/MonteCarloSim_beta.h>

class Bean
{
public:
    bool black;
    bool removed;
    Bean(bool is_black) : black(is_black), removed(false) {}
};

bool operator == (Bean lhs, Bean rhs)
{
    return lhs.black == rhs.black;
}

int main(int argc, char** argv) {

    if (argc != 3)
    {
        std::cout << "usage: COFFEEBEAN <total_number_beans> <number_white_beans>" << '\n';
        return 1;
    }

    const int total_number_beans = strtol(argv[1], nullptr, 10);
    const int number_white_beans = strtol(argv[2], nullptr, 10);
    int number_black_beans = total_number_beans - number_white_beans;
    Distribution<int, int, std::uniform_int_distribution> can_actuation(0, total_number_beans-1, 2);

    //-------------------------------------------------------------------------
    auto condition_met = [total_number_beans, number_black_beans]
            (Distribution<int, int, std::uniform_int_distribution>& _can,
             double& is_black_bean,
             DRE& dre) -> bool
    {
        std::vector<Bean> can(total_number_beans, Bean(true));
        for (auto ix = can.begin()+number_black_beans; ix != can.end(); ++ix)
            ix->black = false;

        while (std::count_if(can.begin(), can.end(),
                             [](Bean& bean) {return !bean.removed;}) != 1)
        {
            // The same bean selected twice not allowed, try again
            if (_can.events[0] == _can.events[1])
            {
                _can.reload_random_values(dre);
                continue;
            }
            // Removed beans not allowed, try again
            if (can[_can.events[0]].removed || can[_can.events[1]].removed)
            {
                _can.reload_random_values(dre);
                continue;
            }

            if (can[_can.events[0]] == can[_can.events[1]])
            {
                can[_can.events[0]].black = true;
                can[_can.events[1]].removed = true;
            }
            // _can.events[0] != _can.events[1]
            else {
                // remove the black bean
                if (can[_can.events[0]].black)
                    can[_can.events[0]].removed = true;
                else
                    can[_can.events[1]].removed = true;
            }
        }

        auto the_bean = std::find_if(can.begin(), can.end(), [](Bean& bean) {return !bean.removed;});
        is_black_bean = 0.0;
        if (the_bean != can.end()) {
            if (the_bean->black) {
                is_black_bean = 1.0;
            }
        }
        return true;
    };
    //-------------------------------------------------------------------------

    MonteCarloSimulation<int, double, int, std::uniform_int_distribution> monteCarloSimulation(
            1000, ///> number of trials
            1,          ///> seed for dre
            condition_met,  ///> condition met?
            can_actuation);  ///> distribution

    StopWatch stopWatch;

    monteCarloSimulation.run();

    stopWatch.stop();

    monteCarloSimulation.change_message("Probability of black bean remaining is ");

    monteCarloSimulation.print_result();
}
