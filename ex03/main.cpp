#include "includes/Bureaucrat.hpp"
#include "includes/Intern.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"

int main()
{  

      
    try
    {
        Bureaucrat Bruce("Bruce", 1);

        Intern intern;
        AForm *form = intern.makeForm("Presidential form", "papa");

        std::cout << std::endl << "------------------------" << std::endl << std::endl;

        AForm *form2 = intern.makeForm("Shrubbery form", "home");

        std::cout << std::endl << "------------------------" << std::endl << std::endl;

        Bruce.signForm(*form);
        Bruce.executeForm(*form);

        std::cout << std::endl << "------------------------" << std::endl << std::endl;

        Bruce.executeForm(*form2);
        Bruce.signForm(*form2);
        Bruce.executeForm(*form2);

        std::cout << std::endl << "------------------------" << std::endl << std::endl;
        delete form;
        delete form2;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}