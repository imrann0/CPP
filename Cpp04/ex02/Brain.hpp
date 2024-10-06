#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];
	public:
		Brain();
		~Brain();
		Brain(const Brain &copy);
		Brain& operator=(const Brain &opt);
		std::string getIdeas(size_t i) const;
		void	setIdeas(size_t i, std::string ideas);
};

#endif
