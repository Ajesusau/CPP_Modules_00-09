#include <iostream>
#include "ClapTrap.hpp" 

int main(void)
{
	ClapTrap A("Assassin");
	ClapTrap D("Victim");
	ClapTrap R("Patient");

	std::cout << std::endl << "---------- ATTACK ----------" << std::endl;
	std::cout << std::endl << "- Normal attack:" << std::endl;
	A.attack("Victim");
	std::cout << std::endl << "- Attack without energy:" << std::endl;
	for (int i = 0; i < 10; i++)
		A.attack("Victim");
	std::cout << std::endl << "- Attack when dead:" << std::endl;
	A.takeDamage(15);
	A.attack("Victim");	

	std::cout << std::endl << "---------- DAMAGE ----------" << std::endl;
	std::cout << std::endl << "- Normal Damage:" << std::endl;
	D.takeDamage(3);
	std::cout << std::endl << "- Damage > Hit:" << std::endl;
	D.takeDamage(15);
	std::cout << std::endl << "- Dead ClapTrap:" << std::endl;
	D.takeDamage(5);

	std::cout << std::endl << "---------- REPARE ----------" << std::endl;
	std::cout << std::endl << "- Normal Repare:" << std::endl;
	R.beRepaired(5);
	std::cout << std::endl << "- Repair without energy:" << std::endl;
	for (int i = 0; i < 10; i++)
		R.beRepaired(1);
	std::cout << std::endl << "- Repair when dead:" << std::endl;
	R.takeDamage(10);
    R.beRepaired(5);
	
	std::cout << std::endl;

	return 0;
}
