#include "MateriaSource.hpp"
#include "Ice.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource Default Constructor Called" << std::endl;
	_inventoryCount = 0;
	for (size_t i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Destructor Called" << std::endl;
	for (size_t i = 0; i < 4; i++)
		delete _inventory[i];
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (copy._inventory[i])
			_inventory[i] = copy._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& opt) {
	if(this != &opt)
	{
		for(int i = 0; i < 4; ++i)
		{
			if(_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}
		}
		_inventoryCount = opt._inventoryCount;
		for(int i = 0; i < 4; ++i)
		{
			if(opt._inventory[i])
				_inventory[i] = opt._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return *this;
}

// learnMateria
void MateriaSource::learnMateria(AMateria* m)
{
	if(!m)
		return;
	if(_inventoryCount >= 4)
		return ;
	for(int i = 0; i < 4; ++i)
	{
		if(_inventory[i] == NULL)
		{
			_inventory[i] = m->clone();// Materia'nın bir kopyasını al
			_inventoryCount++;
			delete m;
			// std::cout << "Materia learned and stored in slot " << i << std::endl;
			return ;
		}
	}
}

// createMateria
AMateria* MateriaSource::createMateria(const std::string& type)
{
	for(int i = 0; i < 4; ++i)
	{
		if(_inventory[i] && _inventory[i]->getType() == type)
		{
			return _inventory[i]->clone(); // Bulunan Materia'nın bir kopyasını döndür
		}
	}
	return NULL;
}
/*
1. learnMateria Fonksiyonu
Parametre: AMateria* m – öğrenmek istediğiniz Materia.
İşlev: Envanterdeki ilk boş slota (nullptr olan) materyayı ekler.
 Materia'nın bir kopyasını (clone()) alır ve saklar. Eğer envanter
 doluysa veya geçersiz bir Materia verilmişse, hiçbir şey yapmaz.

2.createMateria Fonksiyonu
Parametre: const std::string& type – oluşturmak istediğiniz Materia türü.
İşlev: Envanterde öğrenilmiş olan Materia'lar arasında verilen türle (type) eşleşen bir Materia arar.
Bulursa, bu Materia'nın bir kopyasını (clone()) döndürür. Bulamazsa, nullptr döndürür.


*/
