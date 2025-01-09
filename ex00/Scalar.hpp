#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <string>
#include <stdexcept>
#include <iostream>
#include <cstdlib>
class Scalar
{

    public:
        Scalar(std::string &str);
    private:
        std::string &_str;
        char charVal;
        int intVal;
        double doubleVal;
        float fVal;
        void inputCheck(std::string &str);
        enum {cType, intType, fType, dType} type;
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
};



#endif