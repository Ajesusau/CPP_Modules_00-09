#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook(){}

static bool	is_number(std::string number)
{
	size_t	i = 0;

	while (i < number.length())
	{
		if(number[i] < '0' || number[i] > '9')
			return false;
		i++;
	}
	return true;
}

void PhoneBook::add_contact()
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	secret;
	static int	index = 0;

	std::cout << "Fill in the contact details:" << std::endl;
	while (firstName.empty() || firstName.length() > 20)
	{
		std::cout << "First name (20 char max): ";
		std::getline(std::cin, firstName);
		if (std::cin.eof())
		{
				std::cout << std::endl;
				std::cout << "Phone book closed." << std::endl;
				exit(1);
		}
	}
	while (lastName.empty() || lastName.length() > 20)
	{
		std::cout << "Last name (20 char max): ";
		std::getline(std::cin, lastName);
		if (std::cin.eof())
		{
				std::cout << std::endl;
				std::cout << "Phone book closed." << std::endl;
				exit(1);
		}
	}
	while (nickname.empty() || nickname.length() > 20)
	{
		std::cout << "Nickname (20 char max): ";
		std::getline(std::cin, nickname);
		if (std::cin.eof())
		{
				std::cout << std::endl;
				std::cout << "Phone book closed." << std::endl;
				exit(1);
		}
	}
	while (phoneNumber.empty() || phoneNumber.length() > 9 || !is_number(phoneNumber))
	{
		std::cout << "Phone number (9 numbers max): ";
		std::getline(std::cin, phoneNumber);
		if (std::cin.eof())
		{
				std::cout << std::endl;
				std::cout << "Phone book closed." << std::endl;
				exit(1);
		}
	}
	while (secret.empty() || secret.length() > 50)
	{
		std::cout << "Darck Secret (50 char max): ";
		std::getline(std::cin, secret);
		if (std::cin.eof())
		{
				std::cout << std::endl;
				std::cout << "Phone book closed." << std::endl;
				exit(1);
		}
	}
	if(index == 8)
		index = 0;
	contact[index].setContact(firstName, lastName, nickname, phoneNumber, secret);
	index++;
	std::cout << "Contact saved successfully!" << std::endl;	
}

void	PhoneBook::display_contact_info(Contact contact)
{
	std::cout << "CONTACT INFORMATION" << std::endl;
	std::cout << "First Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last Name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact.getSecret() << std::endl;
}

std::string formatField(std::string field)
{
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	return field;
}

void	PhoneBook::display_contact_resume(Contact contact, int index)
{
	std::cout << "|" << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << formatField(contact.getFirstName());
	std::cout << "|" << std::setw(10) << formatField(contact.getLastName());
	std::cout << "|" << std::setw(10) << formatField(contact.getNickname());
	std::cout << "|" << std::endl;
}

void PhoneBook::search_contact()
{
	std::string	index;
	int 		i = 0;

	if(contact[0].is_empity())
		std::cout << "Phone book is empity!" << std::endl;
	else
	{
		std::cout << "|" << std::setw(10) << "Index";
		std::cout << "|" << std::setw(10) << "First Name";
		std::cout << "|" << std::setw(10) << "Last Name";
		std::cout << "|" << std::setw(10) << "Nickname";
		std::cout << "|" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		while(i < 8 && !contact[i].is_empity())
		{
			display_contact_resume(contact[i], i);
			i++;
		}
		std::cout << "Select a contact index: ";
		std::getline(std::cin, index);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			std::cout << "Phone book closed." << std::endl;
			exit(1);
		}
		if(index.length() == 1 && is_number(index) && !contact[index[0] - '0'].is_empity())
		{
			std::cout << std::endl;
			display_contact_info(contact[index[0] - '0']);
		}
		else
			std::cout << "Invalid index." << std::endl;

	}
}