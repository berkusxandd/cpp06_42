/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:22:03 by bince             #+#    #+#             */
/*   Updated: 2025/01/10 16:22:57 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

static void putDVal(char charVal, int intVal, float fVal, double doubleVal)
{
    switch (type)
    {
        case cType:
        {
            double d = static_cast<double>(charVal);
            std::cout << d << std::endl;
            break;
        }
        case intType:
        {
            double d = static_cast<double>(intVal);
            std::cout << d << std::endl;
            break;
        }
        case fType:
        {
            double d = static_cast<double>(fVal);
            std::cout << d << std::endl;
            break;
        }
        case dType:
        {
            std::cout << doubleVal << std::endl;
            break;
        }
        case impossible:
        {
            std::cout << "impossible" << std::endl;
            break;
        }
    }
}

static void putFVal(char charVal, int intVal, float fVal, double doubleVal)
{
    switch (type)
    {
        case cType:
        {
            float f = static_cast<float>(charVal);
            std::cout << f << "f"<< std::endl;
            break;
        }
        case intType:
        {
            float f = static_cast<float>(intVal);
            std::cout << f << "f" << std::endl;
            break;
        }
        case fType:
        {
            std::cout << fVal << "f" << std::endl;
            break;
        }
        case dType:
        {
            float f = static_cast<float>(doubleVal);
            std::cout << f << "f" << std::endl;
            break;
        }
        case impossible:
        {
            std::cout << "impossible" << std::endl;
            break;
        }
    }
}

static void putIntVal(char charVal, int intVal, float fVal, double doubleVal)
{
    switch (type)
    {
        case cType:
        {
            int i = static_cast<int>(charVal);
            std::cout << i << std::endl;
            break;
        }
        case intType:
        {
            std::cout << intVal << std::endl;
            break;
        }
        case fType:
        {
            if (fVal > static_cast<float>(std::numeric_limits<int>::max()) || fVal < static_cast<float>(std::numeric_limits<int>::min()) || std::isnan(fVal) || std::isinf(fVal))
            { 
                std::cout << "impossible" << std::endl;
                break;
            }
            int i = static_cast<int>(fVal);
            std::cout << i << std::endl;
            break;
        }
        case dType:
        {
            if (doubleVal > static_cast<double>(std::numeric_limits<int>::max()) || doubleVal < static_cast<double>(std::numeric_limits<int>::min()) || std::isnan(doubleVal) || std::isinf(doubleVal))
            { 
                std::cout << "impossible" << std::endl;
                break;
            }
            int i = static_cast<int>(doubleVal);
            std::cout << i << std::endl;
            break;
        }
        case impossible:
        {
            std::cout << "impossible" << std::endl;
            break;
        }
    }
}

static void putCharVal(char charVal, int intVal, float fVal, double doubleVal)
{
    switch (type)
    {
        case cType:
        {
            std::cout << charVal << std::endl;
            break;
        }
        case intType:
        {
            if (intVal > static_cast<int>(std::numeric_limits<char>::max()) || intVal < static_cast<int>(std::numeric_limits<char>::min()))
            {
                std::cout << "impossible" << std::endl;
                break;
            }
            char c = static_cast<char>(intVal);
            if (!isprint(intVal))
            {
                std::cout << "non displayable" << std::endl;
                break;
            }
            std::cout << c << std::endl;
            break;
        }
        case fType:
        {
            if (fVal > static_cast<float>(std::numeric_limits<char>::max()) || fVal < static_cast<float>(std::numeric_limits<char>::min()) || std::isnan(fVal) || std::isinf(fVal))
            { 
                std::cout << "impossible" << std::endl;
                break;
            }
            char c = static_cast<char>(fVal);
            if (!isprint(c))
            {
                std::cout << "non displayable" << std::endl;
                break;
            }
            std::cout << c << std::endl;
            break;
        }
        case dType:
        {
            if (doubleVal > static_cast<double>(std::numeric_limits<char>::max()) || doubleVal < static_cast<double>(std::numeric_limits<char>::min()) || std::isnan(doubleVal) || std::isinf(doubleVal))
            { 
                std::cout << "impossible" << std::endl;
                break;
            }
            char c = static_cast<char>(doubleVal);
            if (!isprint(c))
            {
                std::cout << "non displayable" << std::endl;
                break;
            }
            std::cout << c << std::endl;
            break;
        }
        case impossible:
        {
            std::cout << "impossible" << std::endl;
            break;
        }
    }
}


const char * Scalar::EmptyInputException::what() const throw()
{
    return("Input cannot be invalid.");
}

void Scalar::convert(std::string &param)
{
    type = impossible;
    char charVal = 0;
    int intVal = 0;
    float fVal = 0;
    double doubleVal = 0;
    
    if (param.empty())
        throw EmptyInputException();
    if (param.size() == 1)
    {
        if (isdigit(param.c_str()[0]))
        {
            type = intType;
            intVal = static_cast<int>(strtol(param.c_str(),NULL,10));
        }
        else if (isprint(param.c_str()[0]))
        {
            type = cType;
            charVal = param.c_str()[0];
        }
        else
            return;
    }
    else
    {
        char *lRes;
        long lValue = strtol(param.c_str(),&lRes, 10);
        if (*lRes)
        {
            char *dRes;
            double dValue = strtod(param.c_str(),&dRes);

            if (!*dRes)
            {
                type = dType;
                doubleVal = dValue;
            }
            else if (dRes[0] == 'f' && !dRes[1])
            {
                type = fType;
                fVal = static_cast<float>(dValue);
            }
        }
        else
        {
            if (lValue <= 2147483647 && lValue >= -2147483648)
            {
            type = intType;
            intVal = static_cast<int>(lValue);
            }
        }
    }
    std::cout << "char: ";
    putCharVal(charVal,intVal,fVal,doubleVal);
    std::cout << "int: ";
    putIntVal(charVal,intVal,fVal,doubleVal);
    std::cout << "float: ";
    putFVal(charVal,intVal,fVal,doubleVal);
    std::cout << "double: ";
    putDVal(charVal,intVal,fVal,doubleVal);
}