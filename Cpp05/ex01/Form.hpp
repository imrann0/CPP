#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	public:
		Form();
		Form(int requiredsigngrade, int requiredexecutegrade);
		~Form();
		Form(const Form &copy);
		Form& operator=(const Form &opt);

		std::string	getName() const;
		bool		getStatus() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;

		void	beSigned(const Bureaucrat& bureaucrat);

		class GradeTooLowException : public std::exception {
			public:
				virtual const char * what() const throw();
		};

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		std::string	_name;
		bool		_issigned;
		int			_requiredsigngrade;
		int			_requiredexecutegrade;
};
#endif
