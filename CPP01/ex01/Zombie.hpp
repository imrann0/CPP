
#ifndef ZOMBİE_H
# define ZOMBİE_H

#include <iostream>

class Zombie
{
	public:
		Zombie(void);
		~Zombie();
		Zombie(std::string name);
		void	SetName(std::string name);
		void	announce( void );
	private:
		std::string _name;
};


#endif
