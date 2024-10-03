#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():ClapTrap("deafult_clap_name")
{
	this->_name ="Default";
	_hit = FragTrap::_hit;
	_energy =ScavTrap::_energy;
	_damage = FragTrap::_damage;
	std::cout << "DiamondTrap Default Constructor Called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
	this->_name = name;
	_hit = FragTrap::_hit;
	_energy =ScavTrap::_energy;
	_damage = FragTrap::_damage;
	std::cout << "DiamondTrap Name Constructor Called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
	std::cout << "DimondTrap Copy Constructor Called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &opt)
{
	ClapTrap::operator=(opt);
	ScavTrap::operator=(opt);
	FragTrap::operator=(opt);
	this->_name = opt._name;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor  Called" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap Name: " << this->_name << " ClapTrap Name: " << ClapTrap::_name << std::endl;
}
