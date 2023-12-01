#include "cli_exceptions.h"

CLIException::CLIException(const std::string message) : __message(message)
{
}

const std::string CLIException::what() const
{
    return __message;
}

CLIExceptionError::CLIExceptionError(const std::string message)
    : CLIException(message)
{
}