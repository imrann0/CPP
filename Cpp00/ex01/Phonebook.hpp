/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:17:44 by albozkur          #+#    #+#             */
/*   Updated: 2024/08/16 12:17:46 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class Phonebook
{
	private:
		int		i;
		Contact con[8];
	public:
		Phonebook();
		void Add();
		void print_contact();
		void print_id(Contact con);
		void Search();
};

#endif
