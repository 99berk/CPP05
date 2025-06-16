#include "includes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137)
{
    
    this->_target = target;
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy): AForm(copy), _target(copy._target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &copy)
{
    if (this == &copy)
        return *this;
    return *this;
}

const char *ShrubberyCreationForm::FormNotSigned::what() const throw()
{
    return "Form is not signed!";
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!this->isSigned())
        throw(FormNotSigned());
    else if (this->getGradeToExecute() < executor.getGrade())
        throw(GradeTooLowException());
    else
    {
        std::string str("_shrubberry");
        std::string str2 = this->_target + str;
        std::ofstream outfile(str2.c_str());
        if (!outfile)
        {
            std::cerr << "Error! file couln't created" << std::endl;
            return ;
        }
        if (!outfile.is_open())
            return ;
        outfile << "       *" << std::endl;
        outfile << "      ***      \n";
        outfile << "     *****     \n";
        outfile << "    *******    \n";
        outfile << "   *********   \n";
        outfile << "  ***********  \n";
        outfile << " ************* \n";
        outfile << "      |||      \n";
        outfile << "      |||      \n";
        outfile.close();
    }
}