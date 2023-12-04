#include "usermode.h"

UserMode::UserMode(CLI *cli_instance)
    : CLIMode(cli_instance)
{
}

std::string UserMode::get_prompt() const
{
    return "Device> ";
}

void UserMode::handle_input(const std::string input)
{
    if (input == "help" || input == "?")
        return help();
    if (input == "enable")
        return enable();
}

void UserMode::help() const
{
    _cli_instance->notice("Help is not available in this edition of the software. Please migrate to a verison that includes HELP commands.");
}

void UserMode::enable() const
{
    _cli_instance->notice("Not build yet!");
}