#include "Scalar.hpp"

Scalar::Scalar(std::string &str) : _str(str)
{
    if (str.empty())
        throw EmptyInputException();
    if (str.size() == 1)
    {
        if (isdigit(str.c_str()[0]))
        {
            this->type = intType;
            this->intVal = static_cast<int>(strtol(str.c_str(),NULL,10));
        }
        else if (isprint(str.c_str()[0]))
        {
            this->type = cType;
            this->charVal = str.c_str()[0];
        }
        else
        {
            throw Scalar::InvalidInputException();
        }
    }
    else
    {
        char *lRes;
        long lValue = strtol(str.c_str(),&lRes, 10);
        if (*lRes)
        {
            // it is not int
            char *dRes;
            double dValue = strtod(str.c_str(),&dRes);
            if (*dRes != 'f')
            {
                this->type = dType;
                this->doubleVal = dValue;
            }
            else
            {
                this->type = fType;
                this->fVal = static_cast<float>(dValue);
            }
        }
        else
        {
            //it is int
            //add limits checker
            this->type = intType;
            this->intVal = static_cast<int>(lValue);
        }
    }
}

const char * Scalar::EmptyInputException::what() const throw()
{
    return("Input cannot be invalid.");
}

const char * Scalar::InvalidInputException::what() const throw()
{
    return("Input is invalid.");
}