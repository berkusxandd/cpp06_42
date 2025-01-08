#include "Scalar.hpp"

Scalar::Scalar(std::string &str) : _str(str)
{
    if (str.empty())
        throw Scalar::EmptyInputException();
}

const char * Scalar::EmptyInputException::what() const throw()
{
    return("Input cannot be invalid.");
}

const char * Scalar::InvalidInputException::what() const throw()
{
    return("Input is invalid.");
}