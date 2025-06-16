#pragma once

#include <ostream>
#include "Bureaucrat.hpp"

#define RED "\e[1;31m"
#define reset "\e[0m"

class Bureaucrat;

class AForm
{
    private:
        std::string const _name;
        bool        _isSigned;
        int const   _gradeToSign;
        int const   _gradeToExecute;
    public:
        AForm(std::string name = "Default", int gradeToSign = 150, int gradeToExecute = 150);
        AForm(AForm const &copy);
        virtual ~AForm();
        AForm &operator=(AForm const &copy);
        void beSigned(Bureaucrat& bureaucrat);
        virtual void execute(Bureaucrat const &executor) const = 0;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        std::string getName() const;
        bool isSigned() const;

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, AForm &print);