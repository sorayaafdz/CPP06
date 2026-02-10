/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 00:28:11 by soraya            #+#    #+#             */
/*   Updated: 2026/02/10 00:43:40 by soraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <cctype>

static bool isCharLiteral(const std::string& s)
{
	return (s.length() == 1 && !std::isdigit(s[0]));
}

static bool isIntLiteral(const std::string& s)
{
	char* end;
	std::strtol(s.c_str(), &end, 10);
	return (*end == '\0');
}

static bool isFloatLiteral(const std::string& s)
{
	if (s == "nanf" || s == "+inff" || s == "-inff")
		return (true);

	char* end;
	std::strtod(s.c_str(), &end);
	return (*end == 'f' && *(end + 1) == '\0');
}

static bool isDoubleLiteral(const std::string& s)
{
	if (s == "nan" || s == "+inf" || s == "-inf")
		return true;

	char* end;
	std::strtod(s.c_str(), &end);
	return (*end == '\0');
}

void ScalarConverter::convert(const std::string& literal)
{
	double value;

	// PARSEO 
	if (isCharLiteral(literal))
		value = static_cast<double>(literal[0]);
	else if (isIntLiteral(literal))
		value = static_cast<double>(std::atoi(literal.c_str()));
	else if (isFloatLiteral(literal))
		value = std::strtod(literal.c_str(), NULL);
	else if (isDoubleLiteral(literal))
		value = std::strtod(literal.c_str(), NULL);
	else
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return;
	}

	// CHAR 
	std::cout << "char: ";
	if (std::isnan(value) || std::isinf(value)
		|| value < 0 || value > 127)
		std::cout << "impossible\n";
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << static_cast<char>(value) << "'\n";

	// INT 
	std::cout << "int: ";
	if (std::isnan(value) || std::isinf(value)
		|| value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max())
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(value) << "\n";

	// FLOAT 
	std::cout << "float: ";
	float f = static_cast<float>(value);
	if (std::isnan(f))
		std::cout << "nanf\n";
    else if (std::isinf(f))
    {
        if (f > 0)
            std::cout << "+inff\n";
        else
            std::cout << "-inff\n";
    }
	else
	{
		std::cout << f;
		if (f == static_cast<int>(f))
			std::cout << ".0";
		std::cout << "f\n";
	}

	// DOUBLE 
	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << "nan\n";
    else if (std::isinf(value))
    {
        if (value > 0)
            std::cout << "+inf\n";
        else
            std::cout << "-inf\n";
    }
	else
	{
		std::cout << value;
		if (value == static_cast<int>(value))
			std::cout << ".0";
		std::cout << "\n";
	}
}
