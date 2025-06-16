#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat berk("Berk", 50);
		Form formA("Form A", 45, 30);
		Form formB("Form B", 60, 20);

		std::cout << std::endl;

		std::cout << berk << std::endl;
		std::cout << formA << std::endl;
		std::cout << formB << std::endl;

		std::cout << std::endl;

		berk.signForm(formA);
		berk.signForm(formB);

		std::cout << std::endl;

		std::cout << formA << std::endl;
		std::cout << formB << std::endl;

		std::cout << std::endl;

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}