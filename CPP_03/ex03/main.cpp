#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap d("Monster");
	
	std::cout << std::endl;
	d.whoAmI();
	d.attack("Enemy");
	d.guardGate(); 
	d.highFivesGuys();
	std::cout << std::endl;

	return 0;
}
