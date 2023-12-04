#ifndef __CLI_EXCEPTIONS_H__
#define __CLI_EXCEPTIONS_H__

#include <string>

class CLIException
{
private:
    std::string __message;

public:
    CLIException(const std::string message);
    const std::string what() const;
};

class CLIExceptionError : public CLIException
{
public:
    CLIExceptionError(const std::string message);
};

#endif