#include "loginmode.h"

LoginMode::LoginMode(CLI *cli_instance)
    : CLIMode(cli_instance)
{
}

std::string LoginMode::get_prompt() const
{
    if (__entered_credentials.username.empty())
        return "Username: ";
    return "Password: ";
}

void LoginMode::handle_input(const std::string input)
{
    if (__entered_credentials.username.empty())
    {
        __entered_credentials.username = input;
        return;
    }
    __entered_credentials.password = input;
    check_credentials();
}

void LoginMode::check_credentials()
{
    // TODO: make sure these credentials can be changed
    Credentials default_credentials = {"cisco", "cisco"};
    if (!(__entered_credentials == default_credentials))
    {
        __entered_credentials.clear();
        throw CLIExceptionError("Username or password is incorrect!");
    }
    // Transition to a new state
    _cli_instance->output("\n");
    _cli_instance->transition_mode(std::make_shared<UserMode>(_cli_instance));
}