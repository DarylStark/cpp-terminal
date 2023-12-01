#ifndef __CLIMODE_H__
#define __CLIMODE_H__

#include <string>

class CLI;

class CLIMode
{
protected:
    CLI *_cli_instance; // TODO: migrate this to a reference

public:
    CLIMode(CLI *cli_instance);
    // Input/output methods
    virtual std::string get_prompt() const = 0;
    virtual void handle_input(const std::string input) = 0;
};

#endif