#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const &copy);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(ShrubberyCreationForm &copy);
        void    execute(Bureaucrat const &executor) const;

        class FormNotSigned : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};