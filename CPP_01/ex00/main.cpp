#include <iostream>

#include "Zombie.hpp"

int main (void)
{
	Zombie	*zombie;
	
	std::cout << "-------------------TEST_1-------------------" << std::endl;
	zombie = newZombie("Zombie_1");
	zombie->announce();
	delete zombie;
	std::cout << "-------------------TEST_2-------------------" << std::endl;
	randomChump("Zombie_2");
	return 0;
}
