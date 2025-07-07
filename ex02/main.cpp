#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	std::cout << "=== Testing with high-grade bureaucrat ===" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Berk", 1);
		std::cout << bureaucrat << std::endl;

		std::cout << std::endl;

		ShrubberyCreationForm shrubberyForm("Ensar");
		std::cout << shrubberyForm << std::endl;
		
		std::cout << std::endl;

		RobotomyRequestForm robotomyForm("Ali");
		std::cout << robotomyForm << std::endl;
		
		std::cout << std::endl;

		PresidentialPardonForm pardonForm("Enes");
		std::cout << pardonForm << std::endl;

		std::cout << std::endl;

		bureaucrat.signForm(shrubberyForm);
		bureaucrat.signForm(robotomyForm);
		bureaucrat.signForm(pardonForm);

		std::cout << std::endl;

		std::cout << "After signing forms:" << std::endl;
		std::cout << shrubberyForm << std::endl;
		std::cout << robotomyForm << std::endl;
		std::cout << pardonForm << std::endl;

		std::cout << std::endl;

		bureaucrat.executeForm(shrubberyForm);
		std::cout << std::endl;
		bureaucrat.executeForm(robotomyForm);
		std::cout << std::endl;
		bureaucrat.executeForm(pardonForm);

		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing with low-grade bureaucrat ===" << std::endl;
	try
	{
		Bureaucrat lowGradeBureaucrat("John", 150);
		std::cout << lowGradeBureaucrat << std::endl;
		
		std::cout << std::endl;
		
		ShrubberyCreationForm shrubberyForm2("Garden");
		std::cout << shrubberyForm2 << std::endl;

		std::cout << std::endl;

		lowGradeBureaucrat.signForm(shrubberyForm2);
		
		lowGradeBureaucrat.executeForm(shrubberyForm2);

		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing Presidential Pardon with insufficient grade ===" << std::endl;
	try
	{
		Bureaucrat midGradeBureaucrat("Charlie", 10);
		std::cout << midGradeBureaucrat << std::endl;

		std::cout << std::endl;
		
		PresidentialPardonForm pardonForm2("Criminal");
		std::cout << pardonForm2 << std::endl;

		std::cout << std::endl;
		
		midGradeBureaucrat.signForm(pardonForm2);
		std::cout << "After signing:\n" << pardonForm2 << std::endl;
		
		std::cout << std::endl;

		midGradeBureaucrat.executeForm(pardonForm2);

		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing execution of unsigned form ===" << std::endl;
	try
	{
		Bureaucrat topBureaucrat("Supreme", 1);
		std::cout << topBureaucrat << std::endl;
		
		std::cout << std::endl;

		ShrubberyCreationForm unsignedForm("Unsigned");
		std::cout << unsignedForm << std::endl;

		std::cout << std::endl;

		topBureaucrat.executeForm(unsignedForm);

		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
