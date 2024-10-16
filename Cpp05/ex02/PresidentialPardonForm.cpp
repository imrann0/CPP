#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5)
{
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy)
{
	std::cout << "PresidentialPardonForm Copy Constructor Called" << std::endl;
	this->_target = copy._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &opt)
{
	if (this != &opt)
	{
		AForm::operator=(opt);
		this->_target = opt._target;
	}
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() <= this->getExecuteGrade())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getIsSigned() == false)
		throw (AForm::AFormNotBeenSigned());
	else
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream& operator<<(std::ostream &o, const PresidentialPardonForm& a)
{
	o << "Form " << a.getName() <<
	":\n\tsign-grade:\t" << a.getSignGrade() <<
	"\n\texec-grade:\t" << a.getExecuteGrade() <<
	"\n\tis signed:\t" << a.getIsSigned() <<
	std::endl;
	return (o);
}
