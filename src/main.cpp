#include <iostream>

#include "cli/cli.h"
#include "cisco_ios/loginmode.h"

int main()
{
    CLI my_cli;
    my_cli.transition_mode(std::make_shared<LoginMode>(&my_cli));

    while (true)
        my_cli.loop();

    return 0;
}