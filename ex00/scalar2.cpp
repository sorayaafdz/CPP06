/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar2.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 23:51:40 by soraya            #+#    #+#             */
/*   Updated: 2026/02/11 23:52:45 by soraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ScalarConverter::convert(const std::string& literal)
{
    if (isCharLiteral(literal))
    {
        char c = literal[0];

        std::cout << "char: '" << c << "'\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << "float: " << static_cast<float>(c) << ".0f\n";
        std::cout << "double: " << static_cast<double>(c) << ".0\n";
        return;
    }

    if (isIntLiteral(literal))
    {
        int i = std::atoi(literal.c_str());

        std::cout << "char: ";
        if (i < 0 || i > 127)
            std::cout << "impossible\n";
        else if (!std::isprint(i))
            std::cout << "Non displayable\n";
        else
            std::cout << "'" << static_cast<char>(i) << "'\n";

        std::cout << "int: " << i << "\n";
        std::cout << "float: " << static_cast<float>(i) << ".0f\n";
        std::cout << "double: " << static_cast<double>(i) << ".0\n";
        return;
    }

    if (isFloatLiteral(literal))
    {
        float f = std::strtof(literal.c_str(), NULL);

        std::cout << "char: ";
        if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127)
            std::cout << "impossible\n";
        else if (!std::isprint(static_cast<int>(f)))
            std::cout << "Non displayable\n";
        else
            std::cout << "'" << static_cast<char>(f) << "'\n";

        std::cout << "int: ";
        if (std::isnan(f) || std::isinf(f) ||
            f < std::numeric_limits<int>::min() ||
            f > std::numeric_limits<int>::max())
            std::cout << "impossible\n";
        else
            std::cout << static_cast<int>(f) << "\n";

        std::cout << "float: " << f;
        if (f == static_cast<int>(f))
            std::cout << ".0";
        std::cout << "f\n";

        std::cout << "double: " << static_cast<double>(f);
        if (f == static_cast<int>(f))
            std::cout << ".0";
        std::cout << "\n";
        return;
    }

    if (isDoubleLiteral(literal))
    {
        double d = std::strtod(literal.c_str(), NULL);

        std::cout << "char: ";
        if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
            std::cout << "impossible\n";
        else if (!std::isprint(static_cast<int>(d)))
            std::cout << "Non displayable\n";
        else
            std::cout << "'" << static_cast<char>(d) << "'\n";

        std::cout << "int: ";
        if (std::isnan(d) || std::isinf(d) ||
            d < std::numeric_limits<int>::min() ||
            d > std::numeric_limits<int>::max())
            std::cout << "impossible\n";
        else
            std::cout << static_cast<int>(d) << "\n";

        std::cout << "float: " << static_cast<float>(d);
        if (d == static_cast<int>(d))
            std::cout << ".0";
        std::cout << "f\n";

        std::cout << "double: " << d;
        if (d == static_cast<int>(d))
            std::cout << ".0";
        std::cout << "\n";
        return;
    }

    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: impossible\n";
    std::cout << "double: impossible\n";
}
