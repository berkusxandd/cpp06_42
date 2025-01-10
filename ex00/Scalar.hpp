/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:22:05 by bince             #+#    #+#             */
/*   Updated: 2025/01/10 16:24:31 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        static void convert(std::string &param);
    private:
        Scalar();
        Scalar(Scalar const &src);
        Scalar &operator=(Scalar const &rhs);
        ~Scalar();
    class EmptyInputException : public std::exception
    {
        public:
            virtual const char * what() const throw();
    };
};

enum {cType, intType, fType, dType, impossible} type;

#endif