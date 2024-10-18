#ifndef AForm_HPP
# define AForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(int requiredsigngrade, int requiredexecutegrade);
		AForm(std::string name, int requiredsigngrade, int requiredexecutegrade);
		virtual ~AForm();
		AForm(const AForm &copy);
		AForm& operator=(const AForm &opt);

		const std::string	getName() const;
		bool		getIsSigned() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;

		void	beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(const Bureaucrat& executor) const = 0;

		class GradeTooLowException : public std::exception {
			public:
				virtual const char * what() const throw();
		};

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class AFormAlreadySignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class AFormNotBeenSigned : public std::exception{
			public:
				virtual const char* what() const throw();
		};
	protected:
		const std::string	_name;
		bool		_issigned;
		const int			_requiredsigngrade;
		const int			_requiredexecutegrade;
};

std::ostream	&operator<<(std::ostream &o, AForm *AForm);
#endif
