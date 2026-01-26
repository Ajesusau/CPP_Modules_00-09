#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap a("Assassin");
	FragTrap f("HighFive");

	std::cout << std::endl;
	a.attack("HighFive");
	f.attack("Assassin");
	f.highFivesGuys();
	std::cout << std::endl;

	return 0;
}
