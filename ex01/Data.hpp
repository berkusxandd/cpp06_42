/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:22:27 by bince             #+#    #+#             */
/*   Updated: 2025/01/11 18:22:28 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data
{
    public:
        Data();
        Data(std::string str, int value);
        ~Data();
        Data(Data const &src);
        Data &operator=(Data const &rhs);
        std::string getStr() const;
        int getVal() const;
    private:
        std::string _str;
        int _value;
    
};

#endif