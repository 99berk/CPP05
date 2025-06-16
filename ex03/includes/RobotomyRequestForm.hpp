#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
    public:
        RobotomyRequestForm(std::string target = "Target");
        RobotomyRequestForm(RobotomyRequestForm const &copy);
        ~RobotomyRequestForm();
        RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);

        void    execute(Bureaucrat const &executor) const;

        class FormNotSigned : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};