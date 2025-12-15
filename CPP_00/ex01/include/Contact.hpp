#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
	private:

		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	secret;

	public:

		Contact();
		~Contact();

		void	setContact(std::string firstName ,std::string secondName, 
			std::string nickname, std::string phoneNumber, std::string secret);

		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickname();
		std::string	getPhoneNumber();
		std::string	getSecret();
		
		bool		is_empity();
};

#endif