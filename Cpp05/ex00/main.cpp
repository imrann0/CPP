#include "Bureaucrat.hpp"
#include <iostream>

int main() {

	try{
		Bureaucrat kuk("kuk", 150);
		kuk.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooLowException& e){
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try{
		Bureaucrat kuk("kuk", 150);
		kuk.decrementGrade();
	}
	catch (const Bureaucrat::GradeTooLowException& e){
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	try {
		Bureaucrat bob("Bob", 0);
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat alice("Alice", 200);
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat charlie("Charlie", 100);
		std::cout << charlie << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
