#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): AForm(copy)
{
	this->_target = copy._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &opt)
{
	AForm::operator=(opt);
	this->_target = opt._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor Called" << std::endl;
}


std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}


void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() <= this->getExecuteGrade())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getIsSigned() == false)
		throw (AForm::AFormNotBeenSigned());

	std::cout << "Bzzzzzz... Vrrrrr..." << std::endl;
	if (std::rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed for " << this->getTarget() << "." << std::endl;
}


std::ostream& operator<<(std::ostream &o, const RobotomyRequestForm& a)
{
	o << "Form " << a.getName() <<
	":\n\tsign-grade:\t" << a.getSignGrade() <<
	"\n\texec-grade:\t" << a.getExecuteGrade() <<
	"\n\tis signed:\t" << a.getIsSigned() <<
	std::endl;
	return (o);
}
