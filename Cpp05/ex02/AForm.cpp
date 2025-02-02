#include "AForm.hpp"

AForm::AForm() : _name("AForm"), _requiredsigngrade(150), _requiredexecutegrade(150)
{
	std::cout << "AForm Default Constructor Called" << std::endl;
	_issigned = false;
}

AForm::AForm(int requiredsigngrade, int requiredexecutegrade): _name("AForm"), _requiredsigngrade(requiredsigngrade), _requiredexecutegrade(requiredexecutegrade)
{
	std::cout << "AForm Parameterized Constructor Called" << std::endl;
	if (requiredexecutegrade > 150 || requiredsigngrade > 150)
		throw AForm::GradeTooHighException();
	else if (requiredexecutegrade < 1 || requiredsigngrade < 1)
		throw AForm::GradeTooLowException();
	_issigned = false;
}

AForm::AForm(std::string name, int requiredsigngrade, int requiredexecutegrade) : _name(name), _requiredsigngrade(requiredsigngrade), _requiredexecutegrade(requiredexecutegrade)
{
	std::cout << "AForm Parameterized Constructor Called" << std::endl;
	if (requiredexecutegrade > 150 || requiredsigngrade > 150)
		throw AForm::GradeTooHighException();
	else if (requiredexecutegrade < 1 || requiredsigngrade < 1)
		throw AForm::GradeTooLowException();
	_issigned = false;
}

AForm::~AForm()
{
	std::cout << "AForm Destructor Called" << std::endl;
}

AForm::AForm(const AForm &copy): _name(copy._name), _requiredsigngrade(copy._requiredsigngrade), _requiredexecutegrade(copy._requiredexecutegrade)
{
	std::cout << "AForm Copy Constructor Called" << std::endl;
	this->_issigned = copy._issigned;
}

AForm& AForm::operator=(const AForm &opt)
{
	std::cout << "AForm Copy Assignment Operator Called" << std::endl;
	if (this != &opt)
	{
		this->_issigned = opt._issigned;
	}
	return (*this);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getSignGrade() )
		throw AForm::GradeTooLowException();
	else if (this->getIsSigned() == false)
		_issigned = true;
	else
		throw AForm::AFormAlreadySignedException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too High");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too Low");
}

const char* AForm::AFormAlreadySignedException::what() const throw() {
	return "The AForm is already signed!";
}

const char* AForm::AFormNotBeenSigned::what() const throw() {
	return "This Form Has Not Been Signed!";
}

/* Getter */
const std::string AForm::getName() const
{
	return (_name);
}

bool	AForm::getIsSigned() const
{
	return (_issigned);
}

int		AForm::getSignGrade() const
{
	return (_requiredsigngrade);
}

int		AForm::getExecuteGrade() const
{
	return (_requiredexecutegrade);
}

std::ostream	&operator<<(std::ostream &o, AForm *AForm)
{
	o << "AForm " << AForm->getName() <<
	":\n\tsign-grade:\t" << AForm->getSignGrade() <<
	"\n\texecute-grade:\t" << AForm->getExecuteGrade() <<
	"\n\tis signed:\t" << AForm->getIsSigned() <<
	std::endl;
	return (o);
}
