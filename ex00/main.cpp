/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 00:29:06 by soraya            #+#    #+#             */
/*   Updated: 2026/02/11 23:35:10 by soraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Expected: ./convert <int|float|double|char>\n";
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
