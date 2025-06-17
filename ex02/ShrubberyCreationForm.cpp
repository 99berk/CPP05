#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("Default")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), target(other.target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		this->target = other.target;
	std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm parameterized constructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();

	std::string str("_shrubberry");
	std::ofstream file((this->target + str).c_str());
	if (!file.is_open())
	{
		std::cerr << "Error! file couln't created: " << this->target << "_shrubbery" << std::endl;
		return;
	}

	file << "        _-_-_\n";
	file << "      /~~   ~~\\\n";
	file << "   /~~         ~~\\\n";
	file << "  {               }\n";
	file << "   \\  _-_-_-_-_  /\n";
	file << "     ~-_______-~\n";

	file.close();
	std::cout << "Shrubbery created for target: " << this->target << std::endl;
}