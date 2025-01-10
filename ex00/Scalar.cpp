#include "Scalar.hpp"

Scalar::Scalar(std::string &str) : _str(str), type(impossible)
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
            return;
    }
    else
    {
        char *lRes;
        long lValue = strtol(str.c_str(),&lRes, 10);
        if (*lRes)
        {
            char *dRes;
            double dValue = strtod(str.c_str(),&dRes);

            if (!*dRes)
            {
                this->type = dType;
                this->doubleVal = dValue;
            }
            else if (dRes[0] == 'f' && !dRes[1])
            {
                this->type = fType;
                this->fVal = static_cast<float>(dValue);
            }
            else
                return;
        }
        else
        {
            if (lValue > __INT_MAX__ || lValue < __WINT_MIN__)
                return ;
            this->type = intType;
            this->intVal = static_cast<int>(lValue);
        }
    }
}

Scalar::~Scalar()
{}

char Scalar::getCharVal() const
{
    switch (this->type)
    {
        case cType:
            return this->charVal;
        case intType:
        {
            if (this->intVal > static_cast<int>(std::numeric_limits<char>::max()) || this->intVal < static_cast<int>(std::numeric_limits<char>::min()))
                throw InvalidInputException();
            char c = static_cast<char>(this->intVal);
            if (!isprint(c))
                throw Scalar::NonDisplayableException();
            else
                return (c);
        }
        case fType:
        {
            if (this->fVal > static_cast<float>(std::numeric_limits<char>::max()) || this->fVal < static_cast<float>(std::numeric_limits<char>::min()) || std::isnan(this->fVal) || std::isinf(this->fVal))
                throw InvalidInputException();
            char c = static_cast<char>(this->fVal);
            return (c);
        }
        case dType:
        {
            if (this->doubleVal > static_cast<double>(std::numeric_limits<char>::max()) || this->doubleVal < static_cast<double>(std::numeric_limits<char>::min()) || std::isnan(this->doubleVal) || std::isinf(this->doubleVal))
                throw InvalidInputException();
            char c = static_cast<char>(this->doubleVal);
            return (c);
        }
        default:
            throw InvalidInputException();
    }
}

const char * Scalar::EmptyInputException::what() const throw()
{
    return("Input cannot be invalid.");
}

const char * Scalar::InvalidInputException::what() const throw()
{
    return("impossible");
}

const char * Scalar::NonDisplayableException::what() const throw()
{
    return("Non displayable");
}

std::ostream& operator<<(std::ostream& o, const Scalar& rhs)
{
    o << "char: ";
    try
    {
        char cVal = rhs.getCharVal();
        o << cVal << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return o;
}