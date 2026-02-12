/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofernan <sofernan@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 01:01:52 by soraya            #+#    #+#             */
/*   Updated: 2026/02/12 16:46:07 by sofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data data;
	data.number = 42;
	data.s = "Hello Serialization";

    std::cout << "Original Data address: " << &data<< std::endl;
    std::cout << "Original Data content: " << data.number << ", " << data.s << std::endl;

    uintptr_t ptrRaw = Serializer::serialize(&data);
    std::cout << "Serialized value: " << ptrRaw << std::endl;

    Data* restored = Serializer::deserialize(ptrRaw);
    std::cout << "Deserialized Data address: " << restored << std::endl;
    std::cout << "Deserialized Data content: " << restored->number << ", " << restored->s << std::endl;

    if (restored == &data)
	{
		std::cout << "Success: deserialized pointer matches original" << std::endl;
	}
	else
	{
		std::cout << "Error: deserialized pointer does not match original" << std::endl;
	}

	return (0);
}
