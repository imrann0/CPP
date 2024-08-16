/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:07:30 by albozkur          #+#    #+#             */
/*   Updated: 2024/08/16 12:07:31 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Phonebook.hpp"

int	main(void)
{
	Phonebook book;
	std::string str;

	while(str != "EXIT")
	{
		std::cout << "Değer Giriniz: (ADD)" << std::endl;
		std::getline(std::cin, str);
		if (str == "ADD")
			book.Add();
		else if (str == "SEARCH")
			book.Search();
		else
			std::cout << "Girilen Değer Yok Lütfen Tekrear Deneyiniz" << std::endl;
	}
}
