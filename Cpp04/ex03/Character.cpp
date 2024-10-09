#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
{
	_name = "(null)";
	for (size_t i = 0; i < 4; i++)
		_inventory[i] = NULL;

	_garbageCapacity = 10;
	_garbageIndex = 0;
	_garbage_inventory = new AMateria*[_garbageCapacity];
	for (int i = 0; i < _garbageCapacity; i++)
		_garbage_inventory[i] = NULL;
}

Character::Character(const std::string name)
{
	_name = name;
	for (size_t i = 0; i < 4; i++)
		_inventory[i] = NULL;

	_garbageCapacity = 10;
	_garbageIndex = 0;
	_garbage_inventory = new AMateria*[_garbageCapacity];
	for (int i = 0; i < _garbageCapacity; i++)
		_garbage_inventory[i] = NULL;
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

	_garbageCapacity = copy._garbageCapacity;
	_garbageIndex = copy._garbageIndex;
	_garbage_inventory = new AMateria*[_garbageCapacity];
	for (int i = 0; i < _garbageCapacity; i++)
	{
		if (i < _garbageIndex)
			_garbage_inventory[i] = copy._garbage_inventory[i];
		else
			_garbage_inventory[i] = NULL;
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
			if (opt._inventory[i])
				this->_inventory[i] = opt._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}

		delete[] _garbage_inventory;

		_garbageCapacity = opt._garbageCapacity;
		_garbageIndex = opt._garbageIndex;

		_garbage_inventory = new AMateria*[_garbageCapacity];
		for (int i = 0; i < _garbageCapacity; i++)
		{
			if (i < _garbageIndex)
				_garbage_inventory[i] = opt._garbage_inventory[i];
			else
				_garbage_inventory[i] = NULL;
		}
	}
	return *this;
}


Character::~Character()
{
	for(int i = 0; i < 4; ++i)
	{
		if(_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	for (size_t i = 0; i < 4 && _garbage_inventory[i] != NULL; i++)
		delete _garbage_inventory[i];
	delete[] _garbage_inventory;
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
	if (idx < 0 && idx < 4)
		return ;
	if (this->_inventory[idx] != NULL)
	{
		if (_garbageIndex >= _garbageCapacity)
		{
			_expandGarbageInventory();
		}
		_garbage_inventory[_garbageIndex] = _inventory[idx];
		_garbageIndex++;
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 && idx < 4)
		return ;
	if (_inventory[idx] != NULL)
	{
		_inventory[idx]->use(target);
	}

}

void Character::_expandGarbageInventory()
{
	int new_capacity = _garbageCapacity * 2;

	AMateria **materia = new AMateria*[new_capacity];

	for (int i = 0; i < _garbageCapacity; i++)
		materia[i] = _garbage_inventory[i];

	delete[] _garbage_inventory;

	_garbage_inventory = materia;
	_garbageCapacity = new_capacity;
}
