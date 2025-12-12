#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook
{

	public:

		PhoneBook();
		~PhoneBook();

		void add_contact();
		void search_contact();
};

#endif