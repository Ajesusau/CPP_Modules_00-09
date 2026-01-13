#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL){}

HumanB::~HumanB(){}

void	HumanB::attack()
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon to attack" << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}
