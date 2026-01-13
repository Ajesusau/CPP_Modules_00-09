#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	int	index = -1;
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*function[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for(int i = 0; i < 4; i++)
	{
		if(levels[i] == level)
		{
			index = i;
			break;
		}
	}
	switch (index)
	{
		case 0: 
			(this->*function[0])();
			// fall through
		case 1: 
			(this->*function[1])();
			// fall through
		case 2: 
			(this->*function[2])();
			// fall through
		case 3: 
			(this->*function[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
