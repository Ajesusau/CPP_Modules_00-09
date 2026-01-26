#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (this->_hitPoints == 0)
		std::cout << "ScavTrap " << this->_name << " can't attack because is dead!" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ScavTrap " << this->_name << " can't attack because it doesn't have energy points!" << std::endl;
	else {
		std::cout << "ScavTrap "<< this->_name <<" attacks "<< target
			<<", causing " << this->_attackDamage <<" points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode!" << std::endl;
}

/******************************************************************************/
std::string		ScavTrap::getName() {
	return	this->_name;
}

int				ScavTrap::getHit() {
	return	this->_hitPoints;
}


int				ScavTrap::getEnergy() {
	return	this->_energyPoints;
}

int				ScavTrap::getDamage() {
	return	this->_attackDamage;
}
