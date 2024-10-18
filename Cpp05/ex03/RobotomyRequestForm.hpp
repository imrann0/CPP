#ifndef ROBOTOMYREQUESTFORM
# define ROBOTOMYREQUESTFORM

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(std::string _target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &opt);

		void execute(const Bureaucrat& executor) const;
		std::string getTarget() const;
	private:
		std::string _target;
};
std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a);


#endif
