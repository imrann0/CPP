/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:07:20 by albozkur          #+#    #+#             */
/*   Updated: 2024/08/19 11:53:23 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::get_name(void)
{
	return (this->name);
}

std::string Contact::get_surname(void)
{
	return (this->surname);
}

std::string Contact::get_nick_name(void)
{
	return (this->nick_name);
}

std::string Contact::get_phone_number(void)
{
	return (this->pohne_number);
}

std::string Contact::get_secret(void)
{
	return (this->secret);
}

void	Contact::set_name(std::string name)
{
	this->name = name;
}

void	Contact::set_surname(std::string surname)
{
	this->surname = surname;
}

void	Contact::set_nick_name(std::string nick)
{
	this->nick_name = nick;
}

void	Contact::set_phone_number(std::string phone)
{
	this->pohne_number = phone;
}

void	Contact::set_secret(std::string secret)
{
	this->secret = secret;
}
