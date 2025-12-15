#include "Contact.hpp"

Contact::Contact(){}

Contact::~Contact(){}

void	Contact::setContact(std::string firstName ,std::string lastName, 
			std::string nikname, std::string phoneNumber, std::string secret)
{
	Contact::firstName = firstName;
	Contact::lastName = lastName;
	Contact::nikname = nikname;
	Contact::phoneNumber = phoneNumber;
	Contact::secret = secret;

}

std::string	Contact::getFirstName() { return firstName; }

std::string Contact::getLastName() { return lastName; }

std::string Contact::getNikname() { return nikname; }

std::string Contact::getPhoneNumber() { return phoneNumber; }

std::string Contact::getSecret() { return secret; }

