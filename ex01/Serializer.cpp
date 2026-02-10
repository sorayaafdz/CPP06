/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 01:01:06 by soraya            #+#    #+#             */
/*   Updated: 2026/02/10 01:28:23 by soraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer default constructor" << std::endl;
}

unsigned long Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<unsigned long>(ptr));
}

Data* Serializer::deserialize(unsigned long raw)
{
    return (reinterpret_cast<Data*>(raw));
}
