#pragma once

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
class Character: public ICharacter
{
	public:
		Character();
		~Character();
		Character(const std::string name);
		Character(const Character &copy);
		Character& operator=(const Character &opt);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		void _expandGarbageInventory();
	private:
		AMateria	**_garbage_inventory;
		AMateria	*_inventory[4];
		std::string	_name;
		int _garbageIndex;
		int _garbageCapacity;
};
#endif
