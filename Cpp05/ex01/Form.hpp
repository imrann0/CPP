#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	public:
		Form();
		~Form();
		Form(const Form &copy);
		Form& operator=(const Form &opt);

		std::string	getName() const;
		bool		getStatus() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;

		void	beSigned(const Bureaucrat& bureaucrat);
	private:
		std::string	_name;
		bool		_issigned;
		int			_requiredsigngrade;
		int			_requiredexecutegrade;
};
#endif
