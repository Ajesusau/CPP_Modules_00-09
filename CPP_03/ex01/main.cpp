#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp" 

int main(void)
{
	ClapTrap a("Assassin");
	ScavTrap s("Guardian");

	std::cout << std::endl;
	a.attack("Guardian");
	s.attack("Assassin");
	s.guardGate();
	std::cout << std::endl;

	return 0;
}
