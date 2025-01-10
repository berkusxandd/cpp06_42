/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:22:00 by bince             #+#    #+#             */
/*   Updated: 2025/01/10 14:22:01 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "Scalar.hpp"
#include <limits>
int main(int ac, char **av)
{
    if (ac > 1)
    {
        try
        {
            std::string str = std::string(av[1]);
            Scalar scalar(str);
            std::cout << scalar;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    else
        std::cout << "error";
}