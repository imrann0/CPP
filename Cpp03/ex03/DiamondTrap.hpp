#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(const DiamondTrap &copy);
		DiamondTrap(std::string name);
		DiamondTrap& operator=( const DiamondTrap &opt);

		~DiamondTrap();
		void attack(const std::string &target);
		void whoAmI(void);

	private:
		std::string _name;
};

#endif
