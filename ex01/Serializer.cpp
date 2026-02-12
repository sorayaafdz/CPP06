/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofernan <sofernan@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 01:01:06 by soraya            #+#    #+#             */
/*   Updated: 2026/02/12 16:53:24 by sofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer default constructor" << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
	(void)other;
	std::cout << "Serializer copy constructor" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	std::cout << "Serializer copy assignment operator" << std::endl;
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << "Serializer destructor" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}
