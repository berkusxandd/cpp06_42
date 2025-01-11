/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:22:48 by bince             #+#    #+#             */
/*   Updated: 2025/01/11 18:22:49 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <string>
#include <stdexcept>
#include <ctime>
#include <cstdlib>

void identify(Base &basePtrRef)
{
    std::cout << "Base identification from reference is started..." << std::endl;
    try
    {
        A &a = dynamic_cast<A &>(basePtrRef);
        std::cout << "Identification from Reference: Type of the pointer is A." << std::endl;
        (void)a;
    }
    catch(const std::exception& e)
    {
        std::cerr << "A: " << e.what() << '\n';
    }

    try
    {
        B &b = dynamic_cast<B &>(basePtrRef);
        std::cout << "Identification from Reference: Type of the pointer is B." << std::endl;
        (void)b;
    }
    catch(const std::exception& e)
    {
        std::cerr << "B: " << e.what() << '\n';
    }

    try
    {
        C &c = dynamic_cast<C &>(basePtrRef);
        std::cout << "Identification from Reference: Type of the pointer is C." << std::endl;
        (void)c;
    }
    catch(const std::exception& e)
    {
        std::cerr << "C: " << e.what() << '\n';
    }
}

void identify(Base *basePtr)
{
    if (dynamic_cast<A *>(basePtr))
        std::cout << "Identification from Pointer: Type of the pointer is A." << std::endl;
    if (dynamic_cast<B *>(basePtr))
        std::cout << "Identification from Pointer: Type of the pointer is B." << std::endl;
    if (dynamic_cast<C *>(basePtr))
        std::cout << "Identification from Pointer: Type of the pointer is C." << std::endl;
}

Base *generate()
{
    Base * basePtr;
    srand(time(NULL));

    int n = rand() % 3;

    if (n == 0)
    {
        basePtr = new A;
        std::cout << "A is chosen." << std::endl;
    }
    if (n == 1)
    {
        basePtr = new B;
        std::cout << "B is chosen." << std::endl;
    }
    if (n == 2)
    {
        basePtr = new C;
        std::cout << "C is chosen." << std::endl;
    }
    std::cout << std::endl;
    return basePtr;
}

int main()
{
    Base* basePtr = generate();
    identify(basePtr);
    identify(*basePtr);
    delete basePtr; 
}