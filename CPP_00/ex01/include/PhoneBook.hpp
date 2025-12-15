#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook
{
	private:

	Contact contact[8];

	public:

		PhoneBook();
		~PhoneBook();

		void	add_contact();
		void	display_contact_resume(Contact contact, int index);
		void	display_contact_info(Contact contact);
		void	search_contact();
};

#endif