#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator=(const ScavTrap& other);
		~ScavTrap();
		void		attack(const std::string& target);
		void		guardGate();
/******************************************************************************/
		std::string	getName();
		int			getHit();
		int			getEnergy();
		int			getDamage();
};

#endif
