#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	private:

		std::string	firstName;
		std::string	lastName;
		std::string	nikname;
		std::string	phoneNumber;
		std::string	secret;

	public:

		Contact();
		~Contact();

		void	setContact(std::string firstName ,std::string secondName, 
			std::string nikname, std::string phoneNumber, std::string secret);

		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNikname();
		std::string	getPhoneNumber();
		std::string	getSecret();
};

#endif