#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP


#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat(std::string name, int grade);
		~Bureaucrat() throw();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat& operator=(const Bureaucrat &opt);

		std::string	getName() const;
		int		getGrade() const ;
		void	incrementGrade();
		void	decrementGrade();
		void signForm(Form &form);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char * what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public:
				virtual const char * what() const throw();
		};
	private:
		std::string	_name;
		size_t		_grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
