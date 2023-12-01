#include "cli.h"

CLI::CLI()
{
    this->transition_mode(std::make_shared<LoginMode>(this));
}

void CLI::loop()
{
    // Print the prompt
    this->output(__mode->get_prompt());

    // Retrieve the user input
    std::string input;
    std::getline(std::cin, input);

    try
    {
        __mode->handle_input(input);
    }
    catch (const CLIException &error)
    {
        this->error(error.what());
    }
}

void CLI::output(const std::string output) const
{
    std::cout << output;
}

void CLI::error(const std::string output) const
{
    std::cerr << "\n\n";
    std::cerr << "ERROR: " << output << "\n";
    std::cerr << "\n\n";
}

void CLI::notice(const std::string output) const
{
    std::cout << output << "\n\n";
}

void CLI::transition_mode(std::shared_ptr<CLIMode> mode)
{
    __mode = mode;
}