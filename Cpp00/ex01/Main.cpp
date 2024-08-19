/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:54:11 by albozkur          #+#    #+#             */
/*   Updated: 2024/08/19 11:54:12 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Phonebook.hpp"

std::string stringToUpper(std::string str)
{
	int i = 0;
	std::string new_str;

	new_str.resize(str.length());
	while (str[i])
	{
		while (i < (int)str.length())
		{
			new_str[i] = toupper(str[i]);
			i++;
		}
	}
	return (new_str);
}

int	main(void)
{
	Phonebook book;
	std::string str;

	while(str != "EXIT")
	{
		if (std::cin.eof())
			return (0);
		std::cout << "Enter Value: (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, str);
		if (std::cin.eof())
		{
			std::cout << "\nControl ^D Exiting phonebook" << std::endl;
			return (0);
		}
		str = stringToUpper(str);
		if (str == "ADD")
			book.Add();
		else if (str == "SEARCH")
			book.Search();
		else if (str != "EXIT")
			std::cout << "The entered value was not found. Please try again." << std::endl;
	}
}
