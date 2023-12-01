#ifndef __CLI_H__
#define __CLI_H__

#include <iostream>
#include <memory>
#include <string>

#include "cli_exceptions.h"
#include "climode.h"
#include "loginmode.h"

class CLI
{
private:
    std::shared_ptr<CLIMode> __mode;

public:
    // Constructors
    CLI();

    // Needed functions for the loop
    void loop();

    // Output methods
    void output(const std::string output) const;
    void error(const std::string output) const;
    void notice(const std::string output) const;

    // Mode methods
    void transition_mode(std::shared_ptr<CLIMode> mode);
};

#endif