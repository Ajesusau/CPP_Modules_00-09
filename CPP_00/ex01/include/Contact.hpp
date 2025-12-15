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

		void	setContact(std::string firstName, std::string lastName,
			std::string nickname, std::string phoneNumber, std::string secret);

		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		std::string	getPhoneNumber() const;
		std::string	getSecret() const;
		
		bool		is_empty() const;
};

#endif