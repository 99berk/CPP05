#include "includes/Bureaucrat.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"

int main()
{
    try
    {
        ShrubberyCreationForm shrubbery("home");
        std::cout << shrubbery << std::endl;
        
        std::cout << std::endl << "------------------------" << std::endl << std::endl;
        
        RobotomyRequestForm robert("Robert");
        std::cout << robert << std::endl;
        
        std::cout << std::endl << "------------------------" << std::endl << std::endl;
        
        Bureaucrat Ons("Ons", 2);
        std::cout << Ons << std::endl;
       
        std::cout << std::endl << "------------------------" << std::endl << std::endl;
        
        Bureaucrat Korn("Korn", 149);
        std::cout << Korn << std::endl;
        
        std::cout << std::endl << "------------------------" << std::endl << std::endl;
        
        Korn.signForm(shrubbery);
        std::cout << shrubbery << std::endl;
        std::cout << std::endl << "------------------------" << std::endl << std::endl;
        Ons.signForm(shrubbery);
        std::cout << shrubbery << std::endl;
        Ons.executeForm(shrubbery);
        std::cout << std::endl << "------------------------" << std::endl << std::endl;
        Ons.signForm(robert);
        Ons.executeForm(robert);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}