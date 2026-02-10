/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 01:09:45 by soraya            #+#    #+#             */
/*   Updated: 2026/02/11 00:46:42 by soraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include "Base.hpp"

// Genera aleatoriamente A, B o C y devuelve como Base*
Base* generate(void)
{
    int r = std::rand() % 3;
    if (r == 0)
        return (new A);
    else if (r == 1)
        return (new B);
    else
        return (new C);
}

// Identifica tipo usando puntero
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

// Identifica tipo usando referencia (sin puntero dentro)
void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a; // evitar warning
        std::cout << "A" << std::endl;
        return;
    }
    catch (...) {}

    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    }
    catch (...) {}

    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    }
    catch (...) {}
}

int main()
{
    std::srand(std::time(NULL));

    for (int i = 0; i < 10; ++i)
    {
        Base* obj = generate();

        std::cout << "identify(Base*): ";
        identify(obj);

        std::cout << "identify(Base&): ";
        identify(*obj);

        delete (obj);
    }

    return (0);
}
