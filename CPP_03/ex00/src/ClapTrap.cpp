#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->_name = "unnamed";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << "ClapTrap constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " can't attack because is dead!" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " can't attack because it doesn't have energy points!" << std::endl;
	else {
		std::cout << "ClapTrap "<< this->_name <<" attacks "<< target
			<<", causing " << this->_attackDamage <<" points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void		ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " was already dead!" << std::endl;
	else {
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
		this->_hitPoints -= amount;
		if(this->_hitPoints < 0)
			this->_hitPoints = 0;
	}
}

void		ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " can't be repaired because is dead!" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " can't be repaired because it doesn't have energy points!" << std::endl;
	else {
		std::cout << "ClapTrap " << this->_name << " regains " << amount << " hit points!" << std::endl;
		this->_energyPoints--;
		this->_hitPoints += amount;
	}
}
