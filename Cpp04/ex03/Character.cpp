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

Character::Character(const Character &copy)
{
	_name = copy._name;

	for (int i = 0; i < 4; i++)
	{
		if (copy._inventory[i])
			this->_inventory[i] = copy._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character &opt)
{
	if (this != &opt)
	{
		_name = opt._name;
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			if (copy._inventory[i])
				this->_inventory[i] = copy._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return *this;
}


Character::~Character()
{
	for(int i = 0; i < 4; ++i)
	{
		if(_inventory[i]) {
			delete _inventory[i];
			_inventory[i] = nullptr;
		}
	}
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (m)
	{
		for(int i = 0; i < 4; i++)
		{
			if (this->_inventory[i] == NULL)
			{
				_inventory[i] = m;
				std::cout << "Materia equipped in slot " << i << std::endl;
				return ;
			}
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 && idx > 4)
		return ;
	if (this->_inventory[idx] != NULL)
	{
		// bu kaldırılcak unutma sikme işlemini başka türlü yapıcan
		delete _inventory[idx];
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 && idx > 4)
		return ;
	if (_inventory[idx] != NULL)
	{
		_inventory[idx]->use(target);
	}

}
