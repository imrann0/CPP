#include "Form.hpp"

Form::Form()
{
	std::cout << "Form Default Constructor Called" << std::endl;
	_name = "Form";
	_issigned = false;
	_requiredsigngrade = 0;
	_requiredexecutegrade = 0;
}

Form::Form(int requiredsigngrade, int requiredexecutegrade)
{
	std::cout << "Form Parameterized Constructor Called" << std::endl;
	_name = "Form";
	_issigned = false;
	_requiredsigngrade = requiredsigngrade;
	_requiredexecutegrade = requiredexecutegrade;
}

Form::~Form()
{
	std::cout << "Form Destructor Called" << std::endl;
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
	if (this->getSignGrade() <= bureaucrat.getGrade())

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
