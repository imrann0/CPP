#ifndef SHRUBBERYCREATIONFORM
# define SHRUBBERYCREATIONFORM

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(std::string _target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &opt);

		void execute(const Bureaucrat& executor) const;
		std::string getTarget() const;
	private:
		std::string _target;
};
std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a);


#endif
