#include "ShrubberyCreationForm.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy)
{
	std::cout << "ShrubberyCreationForm Copy Constructor Called" << std::endl;
	this->_target = copy._target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor Called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &opt)
{
	if (this != &opt)
	{
		AForm::operator=(opt);
		this->_target = opt._target;
	}
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() <= this->getExecuteGrade())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getIsSigned() == false)
		throw (AForm::AFormNotBeenSigned());
	std::string file = this->getTarget() + "_shrubbery";
	std::ofstream	output;
	output.open(file);
	if (!output.good())
	{
		std::cout << "file could not be opened" << std::endl;
		return ;
	}
	output << "	               _{\\ _{\\{\\/}/}/}__  " << std::endl
<< "              {/{/\\}{/{/\\}(\\}{/\\} _  " << std::endl
<< "             {/{/\\}{/{/\\}(_)\\}{/{/\\}  _  " << std::endl
<< "          {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}  " << std::endl
<< "         {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}  " << std::endl
<< "        _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}  " << std::endl
<< "       {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}  " << std::endl
<< "       _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}  " << std::endl
<< "      {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}  " << std::endl
<< "       {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}  " << std::endl
<< "        {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)  " << std::endl
<< "       {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}  " << std::endl
<< "        {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}  " << std::endl
<< "          {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}  " << std::endl
<< "           (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)  " << std::endl
<< "             {/{/{\\{\\/}{/{\\{\\{\\(_)/}  " << std::endl
<< "              {/{\\{\\{\\/}/}{\\{\\\\}/}  " << std::endl
<< "               {){/ {\\/}{\\/} \\}\\}  " << std::endl
<< "               (_)  \\.-'.-/  " << std::endl
<< "           __...--- |'-.-'| --...__  " << std::endl
<< "    _...--\"   .-'  |'-.-'|  ' -.  ""--..__  " << std::endl
<< "  -\"    ' .  . '   |.'-._| '  . .  '        " << std::endl
<< "  .  '-  '    .--'  | '-.'|    .  '  . '  " << std::endl
<< "           ' ..     |'-_.-|  " << std::endl
<< "   .  '  .       _.-|-._ -|-._  .  '  .  " << std::endl
<< "               .'   |'- .-|   '.  " << std::endl
<< "   ..-'   ' .  '.   `-._.-�   .'  '  - .  " << std::endl
<< "    .-' '        '-._______.-'     '  .  " << std::endl
<< "         .      ~,  " << std::endl
<< "     .       .   |\\   .    ' '-.  " << std::endl
<< "     ___________/  \\____________  " << std::endl
<< "    /  Why is it, when you want \\  " << std::endl
<< "   |  something, it is so damn   |  " << std::endl
<< "   |    much work to get it?     |   " << std::endl
<< "    \\___________________________/ " << std::endl;
}

std::ostream& operator<<(std::ostream &o, const ShrubberyCreationForm& a)
{
	o << "Form " << a.getName() <<
	":\n\tsign-grade:\t" << a.getSignGrade() <<
	"\n\texec-grade:\t" << a.getExecuteGrade() <<
	"\n\tis signed:\t" << a.getIsSigned() <<
	std::endl;
	return (o);
}
