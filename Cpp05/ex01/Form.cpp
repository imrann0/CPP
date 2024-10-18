#include "Form.hpp"

Form::Form() : _name("Form"), _requiredsigngrade(150), _requiredexecutegrade(150)
{
	std::cout << "Form Default Constructor Called" << std::endl;
	_issigned = false;
}

Form::Form(int requiredsigngrade, int requiredexecutegrade): _name("Form"), _requiredsigngrade(requiredsigngrade), _requiredexecutegrade(requiredexecutegrade)
{
	std::cout << "Form Parameterized Constructor Called" << std::endl;
	if (requiredexecutegrade > 150 || requiredsigngrade > 150)
		throw Form::GradeTooHighException();
	else if (requiredexecutegrade < 1 || requiredsigngrade < 1)
		throw Form::GradeTooLowException();
	_issigned = false;
}

Form::Form(std::string name, int requiredsigngrade, int requiredexecutegrade): _name(name), _requiredsigngrade(requiredsigngrade), _requiredexecutegrade(requiredexecutegrade)
{
	std::cout << "Form Parameterized Constructor Called" << std::endl;
	if (requiredexecutegrade > 150 || requiredsigngrade > 150)
		throw Form::GradeTooHighException();
	else if (requiredexecutegrade < 1 || requiredsigngrade < 1)
		throw Form::GradeTooLowException();
	_issigned = false;
}

Form::~Form()
{
	std::cout << "Form Destructor Called" << std::endl;
}

Form::Form(const Form &copy): _name(copy._name), _requiredsigngrade(copy._requiredsigngrade), _requiredexecutegrade(copy._requiredexecutegrade)
{
	std::cout << "Form Copy Constructor Called" << std::endl;
	this->_issigned = copy._issigned;
}

Form& Form::operator=(const Form &opt)
{
	std::cout << "Form Copy Assignment Operator Called" << std::endl;
	if (this != &opt)
	{
		this->_issigned = opt._issigned;
	}
	return (*this);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getSignGrade() )
		throw Form::GradeTooLowException();
	else if (this->getIsSigned() == true)
		throw Form::FormAlreadySignedException();
	else if (this->getIsSigned() == false)
		_issigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too High");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too Low");
}

const char* Form::FormAlreadySignedException::what() const throw() {
	return "The Form is already signed!";
}

/* Getter */
const std::string Form::getName() const
{
	return (_name);
}

bool	Form::getIsSigned() const
{
	return (_issigned);
}

int		Form::getSignGrade() const
{
	return (_requiredsigngrade);
}

int		Form::getExecuteGrade() const
{
	return (_requiredexecutegrade);
}

std::ostream	&operator<<(std::ostream &o, Form *Form)
{
	o << "Form " << Form->getName() <<
	":\n\tsign-grade:\t" << Form->getSignGrade() <<
	"\n\texecute-grade:\t" << Form->getExecuteGrade() <<
	"\n\tis signed:\t" << Form->getIsSigned() <<
	std::endl;
	return (o);
}
