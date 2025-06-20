#include "Bureaucrat.hpp"

int main()
{  
    try {
        Bureaucrat b1("Berk", 50);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        std::cout << "After increment: " << b1 << std::endl;
        b1.decrementGrade();
        std::cout << "After decrement: " << b1 << std::endl;
    
        std::cout << std::endl;

        Bureaucrat b2("Emin", 150);
        std::cout << b2 << std::endl;
        b2.incrementGrade();
        std::cout << "After increment: " << b2 << std::endl;
        b2.decrementGrade();
        b2.decrementGrade();
        std::cout << "After decrement: " << b2 << std::endl;
        
        std::cout << std::endl;

        Bureaucrat b3("Enes", 0);
    
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        Bureaucrat b4("Ali", 1);
        std::cout << b4 << std::endl;
        b4.incrementGrade();

    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        Bureaucrat b5("Ensar", 160);
        std::cout << b5 << std::endl;
        b5.decrementGrade();
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}