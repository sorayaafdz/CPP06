/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofernan <sofernan@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 23:50:18 by soraya            #+#    #+#             */
/*   Updated: 2026/02/12 16:35:27 by sofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
	std::cout << "ScalarConverter copy constructor" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	std::cout << "ScalarConverter copy assignment operator" << std::endl;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor" << std::endl;
}


bool isPseudoLiteral(const std::string& s)
{
    return (s == "nan" || s == "+inf" || s == "-inf" || s == "nanf" || s == "+inff" || s == "-inff");
}

bool isCharLiteral(const std::string& s)
{
    if (s.length() == 1 && !std::isdigit(s[0]))
        return (true);

    if (s.length() == 3 && s[0] == '\'' && s[2] == '\'')
        return (true);

    return (false);
}

bool isIntLiteral(const std::string& s)
{
    char* end;
    long value = std::strtol(s.c_str(), &end, 10);

    if (*end != '\0')
        return (false);

    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        return (false);

    return (true);
}

bool isFloatLiteral(const std::string& s)
{
    if (s.empty() || s[s.length() - 1] != 'f')
        return (false);

    std::string core = s.substr(0, s.length() - 1);

    char* end;
    std::strtof(core.c_str(), &end);

    if (*end != '\0')
        return (false);

    return (true);
}

bool isDoubleLiteral(const std::string& s)
{
    if (s.empty())
        return (false);

    char* end;
    std::strtod(s.c_str(), &end);

    if (*end != '\0')
        return (false);

    return (true);
}

void printFromChar(char c)
{
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;

    std::cout << std::fixed << std::setprecision(1); 
    
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void printFromInt(int i)
{
    std::cout << "char: ";
    if (i < 0 || i > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(i))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(i) << "'" << std::endl;

    std::cout << "int: " << i << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    
    std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void printFromFloat(float f)
{
    std::cout << "char: ";
    if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(f)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(f) << "'" << std::endl;

    std::cout << "int: ";
    if (std::isnan(f) || std::isinf(f) ||
        f < std::numeric_limits<int>::min() ||
        f > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(f) << std::endl;

    std::cout << std::fixed << std::setprecision(1);

    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void printFromDouble(double d)
{
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(d)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;

    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) ||
        d < std::numeric_limits<int>::min() ||
        d > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
       std::cout << static_cast<int>(d) << std::endl;

    std::cout << std::fixed << std::setprecision(1);

    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
    if (isPseudoLiteral(literal))
    {
        double d = std::atof(literal.c_str());
        printFromDouble(d);
    }
    else if (isCharLiteral(literal))
    {
        char c;
        if (literal.length() == 1)
            c = literal[0];
        else
            c = literal[1];

        printFromChar(c);
    }
    else if (isIntLiteral(literal))
    {
        long value = std::strtol(literal.c_str(), NULL, 10);
        int i = static_cast<int>(value);
        printFromInt(i);
    }
    else if (isFloatLiteral(literal))
    {
        float f = std::atof(literal.c_str());
        printFromFloat(f);
    }
    else if (isDoubleLiteral(literal))
    {
        double d = std::atof(literal.c_str());
        printFromDouble(d);
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}
