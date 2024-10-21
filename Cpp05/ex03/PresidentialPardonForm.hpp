#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm :public AForm
{
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm &opt);

		std::string getTarget() const;
		void execute(const Bureaucrat& executor) const;
	private:
		std::string _target;
};
std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm *a);

#endif
