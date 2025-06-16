#include "includes/Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "\e[1;31m Grade too high!\e[0m";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "\e[1;31m Grade too low!\e[0m";
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
    std::cout << "Bureaucrat Default constructor called" << std::endl;

     if (grade > 150)
     {
         throw(Bureaucrat::GradeTooLowException());
     }
     else if (grade < 1)
     {
         throw(Bureaucrat::GradeTooHighException());
     }
    
}

Bureaucrat::Bureaucrat(int grade): _name("Default"), _grade(grade)
{
    std::cout << "Bureaucrat Default constructor called" << std::endl;

    if (grade > 150)
    {
        throw(Bureaucrat::GradeTooLowException());
    }
    else if (grade < 1)
    {
        throw(Bureaucrat::GradeTooHighException());
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
    *this = copy;
    std::cout << "Bureaucrat Copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat const &Bureaucrat::operator=(Bureaucrat const &copy)
{
    std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
    this->_grade = copy._grade;
    return *this;
}

std::string const Bureaucrat::getName( void ) const
{
    return this->_name;
}

int Bureaucrat::getGrade( void ) const
{
    return this->_grade;
}

void    Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade == 1)
        throw(Bureaucrat::GradeTooHighException());
    else
        this->_grade--;

}

void Bureaucrat::decrementGrade()
{
    if (this->_grade == 150)
        throw(Bureaucrat::GradeTooLowException());
    else
        this->_grade++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &print)
{
    return (os << print.getName() << ", Bureaucrat grade " << print.getGrade());
}