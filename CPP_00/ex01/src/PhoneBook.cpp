#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook(){}

static bool	is_number(std::string phoneNumber)
{
	size_t	i = 0;

	while(i < phoneNumber.length())
	{
		if(phoneNumber[i] < '0' || phoneNumber[i] > '9')
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

	std::cout << "Fill in the contact details:" << std::endl;
	while(firstName.empty() || firstName.length() > 20)
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
	while(lastName.empty() || lastName.length() > 20)
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
	while(nickname.empty() || nickname.length() > 20)
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
	while(phoneNumber.empty() || phoneNumber.length() > 9 || !is_number(phoneNumber))
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
	while(secret.empty() || secret.length() > 50)
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
}

void PhoneBook::search_contact()
{
	std::cout << "busca loco" << std::endl;	
}