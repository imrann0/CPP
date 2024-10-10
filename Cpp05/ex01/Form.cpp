#include "Form.hpp"

Form::Form()
{
	_name = "Form";
	_issigned = 0;
	_requiredsigngrade = 0;
	_requiredexecutegrade = 0;
	std::cout << "Form Default Constructor Called" << std::endl;
}

Form::~Form()
{
	std::cout << "Destructor Called" << std::endl;
}

Form::Form(const Form &copy)
{
	std::cout << "Form Copy Constructor Called" << std::endl;
	this->_name = copy._name;
	this->_issigned = copy._issigned;
}

Form& Form::operator=(const Form &opt)
{
	std::cout << "Form Copy Assignment Operator Called" << std::endl;
	if (this != &opt)
	{
		this->_name = opt._name;
		this->_issigned = opt._issigned;
	}
	return (*this);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->getSignGrade() < bureaucrat.getGrade())
		_issigned = true;
}

/* Getter */
std::string Form::getName() const
{
	return (_name);
}

bool	Form::getStatus() const
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
