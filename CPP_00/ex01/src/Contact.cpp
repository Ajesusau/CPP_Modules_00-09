#include "Contact.hpp"

Contact::Contact(){}

Contact::~Contact(){}

void	Contact::setContact(std::string firstName ,std::string lastName, 
			std::string nickname, std::string phoneNumber, std::string secret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickname = nickname;
	this->phoneNumber = phoneNumber;
	this->secret = secret;
}

std::string	Contact::getFirstName() const { return firstName; }

std::string Contact::getLastName() const { return lastName; }

std::string Contact::getNickname() const { return nickname; }

std::string Contact::getPhoneNumber() const { return phoneNumber; }

std::string Contact::getSecret() const { return secret; }

bool		Contact::is_empty() const
{
	if (firstName.empty() && lastName.empty() && nickname.empty()
		&& phoneNumber.empty() && secret.empty())
		return true;
	return false;
}
