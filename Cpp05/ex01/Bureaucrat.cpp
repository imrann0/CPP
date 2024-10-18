#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	std::cout << "Bureaucrat Default Constructor Called" << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (grade <= 0)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::~Bureaucrat() throw()
{
	std::cout << "Bureaucrat Destructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy._name)
{
	std::cout << "Bureaucrat Copy Constructor Called" << std::endl;
	_grade = copy._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &opt)
{
	std::cout << "Bureaucrat Copy Assignment Operator Called" << std::endl;
	if (this != &opt)
	{
		_grade = opt._grade;
	}
	return (*this);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

const std::string Bureaucrat::getName() const
{
	return (_name);
}

void Bureaucrat::decrementGrade()
{
	if ((_grade - 1) <= 0)
		throw (Bureaucrat::GradeTooLowException());
	_grade--;
}

void	Bureaucrat::incrementGrade()
{
	if ((_grade + 1) > 150)
		throw (Bureaucrat::GradeTooHighException());
	_grade++;
}

void Bureaucrat::signForm(Form &Form)
{
	try
	{
		Form.beSigned(*this);
		std::cout << this->getName() << " signs " << Form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{

		std::cerr << this->getName() << " cannot sign " <<		Form.getName() << " because " << e.what() << std::endl;
	}

}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException: Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException: Grade is too low!";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}
