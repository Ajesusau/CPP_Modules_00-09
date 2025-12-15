#include "Contact.hpp"

Contact::Contact(){}

Contact::~Contact(){}

void	Contact::setContact(std::string firstName ,std::string lastName, 
			std::string nickname, std::string phoneNumber, std::string secret)
{
	Contact::firstName = firstName;
	Contact::lastName = lastName;
	Contact::nickname = nickname;
	Contact::phoneNumber = phoneNumber;
	Contact::secret = secret;

}

std::string	Contact::getFirstName() { return firstName; }

std::string Contact::getLastName() { return lastName; }

std::string Contact::getNickname() { return nickname; }

std::string Contact::getPhoneNumber() { return phoneNumber; }

std::string Contact::getSecret() { return secret; }

bool		Contact::is_empity()
{
	if(firstName.empty() && lastName.empty() && nickname.empty()
		&& phoneNumber.empty() && secret.empty())
		return true;
	return false;
}