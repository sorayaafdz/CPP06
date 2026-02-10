/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 01:01:52 by soraya            #+#    #+#             */
/*   Updated: 2026/02/10 01:35:32 by soraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data original(42, "Hello Serialization");

    std::cout << "Original Data address: " << &original << std::endl;
    std::cout << "Original Data content: " << original.number << ", " << original.text << std::endl;

    unsigned long ptrRaw = Serializer::serialize(&original);
    std::cout << "Serialized value: " << ptrRaw << std::endl;

    Data* restored = Serializer::deserialize(ptrRaw);
    std::cout << "Deserialized Data address: " << restored << std::endl;
    std::cout << "Deserialized Data content: " << restored->number << ", " << restored->text << std::endl;

    if (restored == &original)
	{
		std::cout << "Success: deserialized pointer matches original!" << std::endl;
	}
	else
	{
		std::cout << "Error: deserialized pointer does not match original!" << std::endl;
	}

	return (0);
}
