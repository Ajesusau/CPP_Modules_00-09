#include <iostream>

#include "Zombie.hpp"

int main (void)
{
	Zombie	*horde;
	
	std::cout << "-------------------TEST_1-------------------" << std::endl;
	horde = zombieHorde(3, "Horde_1");
	for(int i = 0; i < 3; i++)
		horde[i].announce();
	std::cout << std::endl;
	delete[] horde;
	std::cout << "-------------------TEST_1-------------------" << std::endl;
	horde = zombieHorde(7, "Horde_2");
	for(int i = 0; i < 7; i++)
		horde[i].announce();
	std::cout << std::endl;
	delete[] horde;
	return 0;
}
