#ifndef __LOGINMODE_H__
#define __LOGINMODE_H__

#include <string>

#include "cli_exceptions.h"
#include "cli.h"
#include "climode.h"

#include "usermode.h"

class Credentials
{
public:
    std::string username;
    std::string password;

    bool operator==(const Credentials credentials) const
    {
        return username == credentials.username && password == credentials.password;
    }

    void clear()
    {
        username.clear();
        password.clear();
    }
};

class LoginMode : public CLIMode
{
private:
    Credentials __entered_credentials;

public:
    //  Constructors
    LoginMode(CLI *cli_instance);

    // Input/output methods
    std::string get_prompt() const;
    void handle_input(const std::string input);

    // Mode specific methods
    void check_credentials();
};

#endif