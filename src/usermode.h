#ifndef __USERMODE_H__
#define __USERMODE_H__

#include <string>

#include "cli_exceptions.h"
#include "climode.h"
#include "cli.h"

class UserMode : public CLIMode
{
public:
    //  Constructors
    UserMode(CLI *cli_instance);

    // Input/output methods
    std::string get_prompt() const;
    void handle_input(const std::string input);

    // Mode specific methods
    void help() const;
    void enable() const;
};

#endif