#pragma once
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Aform;

class Intern
{
    public:
        Intern();
        Intern(Intern const &copy);
        ~Intern();
        Intern &operator=(Intern const &copy);

        AForm   *makeForm(std::string formName, std::string target = "default");
};