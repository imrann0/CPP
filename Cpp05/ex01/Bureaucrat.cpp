#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	std::cout << "Bureaucrat Default Constructor Called" << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (grade <= 0)
		throw Bureaucrat::GradeTooLowException();
	_name = name;
	_grade = grade;
}

Bureaucrat::~Bureaucrat() throw()
{
	std::cout << "Bureaucrat Destructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	std::cout << "Bureaucrat Copy Constructor Called" << std::endl;
	_name = copy._name;
	_grade = copy._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &opt)
{
	std::cout << "Bureaucrat Copy Assignment Operator Called" << std::endl;
	if (this != &opt)
	{
		_name = opt._name;
		_grade = opt._grade;
	}
	return (*this);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

void Bureaucrat::decrementGrade()
{
	_grade--;
}

void	Bureaucrat::incrementGrade()
{
	_grade++;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signs " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " cannot sign " <<
			form.getName() << " because " << e.what() << std::endl;
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
