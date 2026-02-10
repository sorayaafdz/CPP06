/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 00:58:16 by soraya            #+#    #+#             */
/*   Updated: 2026/02/10 01:21:35 by soraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data
{
	int number;
	std::string text;

	Data() : number(0), text("default") {}
    Data(int n, const std::string& t) : number(n), text(t) {}
};

#endif
