#include <iostream>

#include "cli.h"

int main()
{
    CLI my_cli;

    while (true)
        my_cli.loop();

    return 0;
}