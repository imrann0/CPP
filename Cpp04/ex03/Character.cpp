#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
{
	_name = "(null)";
	for (size_t i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const std::string name)
{
	_name = name;
	for (size_t i = 0; i < 4; i++)
		_inventory[i] = NULL;
}
