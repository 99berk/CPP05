#pragma once

#include <ostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool              isSigned;
        const int         gradeToSign;
        const int         gradeToExecute;

    public:
        AForm();
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();
        AForm(const std::string name, int gradeToSign, int gradeToExecute);

        std::string getName() const;
        bool        getIsSigned() const;
        int         getGradeToSign() const;
        int         getGradeToExecute() const;

        void         beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const &executor) const = 0;

        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class FormNotSignedException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);
