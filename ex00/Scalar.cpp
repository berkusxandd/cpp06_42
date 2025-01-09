#include "Scalar.hpp"

Scalar::Scalar(std::string &str) : _str(str)
{
    if (str.empty())
        throw EmptyInputException();
    if (str == "-inff" || str == "-inf")
        
}

const char * Scalar::EmptyInputException::what() const throw()
{
    return("Input cannot be invalid.");
}

const char * Scalar::InvalidInputException::what() const throw()
{
    return("Input is invalid.");
}