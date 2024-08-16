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
		void print_contact(Contact contact);
		void Search();
};

#endif
