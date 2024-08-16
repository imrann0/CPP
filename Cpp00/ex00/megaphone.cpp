/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:07:15 by albozkur          #+#    #+#             */
/*   Updated: 2024/08/16 12:07:15 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ar, char **av)
{
	int	i;
	int	j;

	if (ar == 1)
	{
		std::string empty = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		std::cout << empty << std::endl;
	}
	else
	{
		i = 1;
		while (av[i])
		{
			std::string str = av[i];
			j = 0;
			while (j < (int)str.length())
			{
				std::cout << (char)toupper(av[i][j]);
				j++;
			}
			std::cout << " ";
			i++;
		}
		std::cout << std::endl;
	}

}
