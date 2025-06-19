#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{  
	Bureaucrat berk("Berk", 1);
	std::cout << berk << std::endl;
	Bureaucrat mert("Mert", 150);
	std::cout << mert << std::endl;

	std::cout << std::endl;

	Intern intern;

	std::cout << std::endl;

	AForm* form1 = intern.makeForm("shrubbery form", "home");

	std::cout << std::endl;

	AForm* form2 = intern.makeForm("robotomy form", "robot");

	std::cout << std::endl;

	AForm* form3 = intern.makeForm("presidential form", "target");

	std::cout << std::endl;

	if (form1)
	{
		berk.signForm(*form1);
		berk.executeForm(*form1);
		delete form1;
	}

	std::cout << std::endl;

	if (form2)
	{
		mert.signForm(*form2);
		mert.executeForm(*form2);
		delete form2;
	}

	std::cout << std::endl;

	if (form3)
	{
		berk.signForm(*form3);
		berk.executeForm(*form3);
		delete form3;
	}

	std::cout << std::endl;

	return 0;
}