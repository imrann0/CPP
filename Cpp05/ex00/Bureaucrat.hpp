#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP


#include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat(std::string name, int grade);
		~Bureaucrat() throw();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat& operator=(const Bureaucrat &opt);

		const std::string	getName() const;
		int		getGrade() const ;
		void	incrementGrade();
		void	decrementGrade();

		class GradeTooHighException : public std::exception {
			public:
				const char * what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public:
				const char * what() const throw();
		};
	private:
		const std::string	_name;
		size_t		_grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
