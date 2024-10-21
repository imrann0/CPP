#ifndef Form_HPP
# define Form_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(int requiredsigngrade, int requiredexecutegrade);
		Form(std::string name, int requiredsigngrade, int requiredexecutegrade);
		~Form();
		Form(const Form &copy);
		Form& operator=(const Form &opt);

		const std::string	getName() const;
		bool		getIsSigned() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;

		void	beSigned(const Bureaucrat& bureaucrat);

		class GradeTooLowException : public std::exception {
			public:
				const char * what() const throw();
		};

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class FormAlreadySignedException : public std::exception {
			public:
				const char* what() const throw();
		};
	private:
		const std::string	_name;
		bool		_issigned;
		const int			_requiredsigngrade;
		const int			_requiredexecutegrade;
};

std::ostream	&operator<<(std::ostream &o, Form *Form);
#endif
