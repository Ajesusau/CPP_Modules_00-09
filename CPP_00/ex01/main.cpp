#include <iostream>
#include <unistd.h>
#include <limits>
#include "PhoneBook.hpp"


void title_img()
{
	std::cout << "╔═══════════════════════════════════════════════════════════════════════════════════════════╗" << std::endl;
	std::cout << "║                                                                                           ║" << std::endl;
	std::cout << "║       ██████╗ ██╗  ██╗ ██████╗ ███╗   ██╗███████╗██████╗  ██████╗  ██████╗ ██╗  ██╗       ║" << std::endl;
	std::cout << "║       ██╔══██╗██║  ██║██╔═══██╗████╗  ██║██╔════╝██╔══██╗██╔═══██╗██╔═══██╗██║ ██╔╝       ║" << std::endl;
	std::cout << "║       ██████╔╝███████║██║   ██║██╔██╗ ██║█████╗  ██████╔╝██║   ██║██║   ██║█████╔╝        ║" << std::endl;
	std::cout << "║       ██╔═══╝ ██╔══██║██║   ██║██║╚██╗██║██╔══╝  ██╔══██╗██║   ██║██║   ██║██╔═██╗        ║" << std::endl;
	std::cout << "║       ██║     ██║  ██║╚██████╔╝██║ ╚████║███████╗██████╔╝╚██████╔╝╚██████╔╝██║  ██╗       ║" << std::endl;
	std::cout << "║       ╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚═════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝       ║" << std::endl;
	std::cout << "║                                                                                           ║" << std::endl;
	std::cout << "╚═══════════════════════════════════════════════════════════════════════════════════════════╝" << std::endl;
}

void clearScreen()
{
	std::cout << "\033[2J\033[2;1H";
}

void commands_menu()
{
	std::cout << "┌───────────────────────────────────────────────────────────────────────────────────────────┐" << std::endl;
	std::cout << "│                                           OPTIONS                                         │" << std::endl;
	std::cout << "├───────────────────────────────────────────────────────────────────────────────────────────┤" << std::endl;
	std::cout << "│                                                                                           │" << std::endl;
	std::cout << "│  ADD     → Add a new contact to your phonebook                                            │" << std::endl;
	std::cout << "│            Parameters: First Name, Last Name, Nickname, Phone Number, and Darkest Secret  │" << std::endl;
	std::cout << "│            Note: Maximum 8 contacts. New contacts will replace the oldest ones!           │" << std::endl;
	std::cout << "│                                                                                           │" << std::endl;
	std::cout << "│  SEARCH  → Display all contacts and view detailed information                             │" << std::endl;
	std::cout << "│                                                                                           │" << std::endl;
	std::cout << "│  EXIT    → Close the phonebook                                                            │" << std::endl;
	std::cout << "│            All contacts will be permanently deleted !!!                                   │" << std::endl;
	std::cout << "│                                                                                           │" << std::endl;
	std::cout << "└───────────────────────────────────────────────────────────────────────────────────────────┘" << std::endl;
}

int main()
{
	std::string	option;
	PhoneBook	phonebook;

	clearScreen();
	title_img();
	sleep(2);
	
	while (option != "EXIT")
	{
		clearScreen();
		commands_menu();
		std::cout << std::endl;
		std::cout << "Select an option: ";
		std::getline(std::cin, option);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			std::cout << "Phone book closed." << std::endl;
			return (1);
		}
		else if (option == "ADD")
		{
			phonebook.add_contact();
			sleep(2);

		}
		else if (option == "SEARCH")
		{
			phonebook.search_contact();
			sleep(2);
		}
		else if (option == "EXIT")
			continue;
		else
		{
			std::cout << "Invalid option." << std::endl;
			sleep(2);
		}
	}
	std::cout << "Phone book closed." << std::endl;
	return 0;
}