/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 23:50:18 by soraya            #+#    #+#             */
/*   Updated: 2026/02/11 23:50:20 by soraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <cctype>

namespace
{
    enum LiteralType
    {
        TYPE_CHAR,
        TYPE_INT,
        TYPE_FLOAT,
        TYPE_DOUBLE,
        TYPE_PSEUDO,
        TYPE_UNKNOWN
    };

    bool isPseudoLiteral(const std::string& s)
    {
        return (s == "nan" || s == "+inf" || s == "-inf" ||
                s == "nanf" || s == "+inff" || s == "-inff");
    }

    bool isCharLiteral(const std::string& s)
    {
        return (s.length() == 1 && !std::isdigit(s[0]));
    }

    bool isIntLiteral(const std::string& s)
    {
        std::istringstream iss(s);
        int value;
        iss >> value;
        return (!iss.fail() && iss.eof());
    }

    bool isFloatLiteral(const std::string& s)
    {
        if (s.empty() || s[s.length() - 1] != 'f')
            return false;

        std::string core = s.substr(0, s.length() - 1);
        std::istringstream iss(core);
        float value;
        iss >> value;
        return (!iss.fail() && iss.eof());
    }

    bool isDoubleLiteral(const std::string& s)
    {
        std::istringstream iss(s);
        double value;
        iss >> value;
        return (!iss.fail() && iss.eof());
    }

    LiteralType detectType(const std::string& literal)
    {
        if (isPseudoLiteral(literal))
            return TYPE_PSEUDO;
        if (isCharLiteral(literal))
            return TYPE_CHAR;
        if (isIntLiteral(literal))
            return TYPE_INT;
        if (isFloatLiteral(literal))
            return TYPE_FLOAT;
        if (isDoubleLiteral(literal))
            return TYPE_DOUBLE;
        return TYPE_UNKNOWN;
    }

    void printFromChar(char c)
    {
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
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
        std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
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

        std::cout << "float: " << f;
        if (f == static_cast<int>(f))
            std::cout << ".0";
        std::cout << "f" << std::endl;

        std::cout << "double: " << static_cast<double>(f);
        if (f == static_cast<int>(f))
            std::cout << ".0";
        std::cout << std::endl;
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

        std::cout << "float: " << static_cast<float>(d);
        if (d == static_cast<int>(d))
            std::cout << ".0";
        std::cout << "f" << std::endl;

        std::cout << "double: " << d;
        if (d == static_cast<int>(d))
            std::cout << ".0";
        std::cout << std::endl;
    }
}

void ScalarConverter::convert(const std::string& literal)
{
    LiteralType type = detectType(literal);

    switch (type)
    {
        case TYPE_CHAR:
        {
            char c = literal[0];
            printFromChar(c);
            break;
        }
        case TYPE_INT:
        {
            int i = std::atoi(literal.c_str());
            printFromInt(i);
            break;
        }
        case TYPE_FLOAT:
        {
            float f = std::atof(literal.c_str());
            printFromFloat(f);
            break;
        }
        case TYPE_DOUBLE:
        {
            double d = std::atof(literal.c_str());
            printFromDouble(d);
            break;
        }
        case TYPE_PSEUDO:
        {
            double d = std::atof(literal.c_str());
            printFromDouble(d);
            break;
        }
        default:
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
        }
    }
}
