#pragma once

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const &copy);
        ~PresidentialPardonForm();
        // PresidentialPardonForm &operator=(PresidentialPardonForm &copy);
        void    execute(Bureaucrat const &executor) const;

        class FormNotSigned : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};