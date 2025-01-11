/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:22:24 by bince             #+#    #+#             */
/*   Updated: 2025/01/11 18:22:25 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _str("undefined"), _value(0)
{}

Data::Data(std::string str, int value) : _str(str), _value(value)
{

}

Data::~Data()
{

}

Data::Data(const Data &src)
{
    *this = src;
}

Data & Data::operator=(Data const &rhs)
{
    if (this != &rhs)
    {
        this->_str = rhs.getStr();
        this->_value = rhs.getVal();
    }
    return (*this);
}

std::string Data::getStr() const
{
    return (this->_str);
}

int Data::getVal() const
{
    return (this->_value);
}