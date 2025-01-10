#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <string>
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
class Scalar
{

    public:
        Scalar(std::string &str);
        ~Scalar();
        char getCharVal() const;
        int getIntVal();
        float getFVal();
        double getDVal();
    private:
        std::string &_str;
        char charVal;
        int intVal;
        double doubleVal;
        float fVal;
        enum {cType, intType, fType, dType, impossible} type;
    class EmptyInputException : public std::exception
    {
        public:
            virtual const char * what() const throw();
    };
    class InvalidInputException : public std::exception
    {
        public:
            virtual const char * what() const throw();
    };
    class NonDisplayableException : public std::exception
    {
        public:
            virtual const char * what() const throw();
    };
};

std::ostream & operator<<(std::ostream& o, const Scalar& rhs);

#endif