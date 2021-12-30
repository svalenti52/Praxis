//
// Created by svalenti on 12/30/2021.
//

#include <iostream>
#include <string>

int main()
{
    for (int ix = 1; ix<1'000'000; ++ix)
    {
        std::string appended_str = std::to_string(ix);
        std::string prepended_str{appended_str};
        appended_str.append("6");
        prepended_str.insert(0, 1, '6');

        int prepended = std::stoi(prepended_str, nullptr, 10);
        int appended = std::stoi(appended_str, nullptr, 10);

        if (4*appended==prepended)
        {
            std::cout << "Minimum value with property = " << appended_str << '\n';
            break;
        }
    }
}
