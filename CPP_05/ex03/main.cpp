#include "Intern.hpp"

int main()
{
	Intern randomIntern;
	std::string target[4] = {"dog", "cat", "fish", "no"};

	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "                     Intern creates forms                      " << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	AForm* form1 = randomIntern.makeForm("presidential pardon", target[0]);
	AForm* form2 = randomIntern.makeForm("robotomy request", target[1]);
	AForm* form3 = randomIntern.makeForm("shrubbery creation", target[2]);
	AForm* form4 = randomIntern.makeForm("shrubbery", target[3]);

	std::cout << "\n---------------------------------------------------------------" << std::endl;
	std::cout << "                     Intern target forms                       " << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	
	std::cout << YELLOW  << form1->getName() << RESET;
	std::cout << " is created to target ";
	std::cout << YELLOW << form1->getTarget() << RESET << std::endl;
	std::cout << YELLOW << form2->getName() << RESET;
	std::cout << " is created to target ";
	std::cout << YELLOW << form2->getTarget() << RESET << std::endl;
	std::cout << YELLOW << form3->getName() << RESET;
	std::cout << " is created to target ";
	std::cout << YELLOW << form3->getTarget() << RESET << std::endl;

	std::cout << "\n---------------------- Destroying Intern forms ------------------" << std::endl;
	delete form1;
	delete form2;
	delete form3;
	delete form4;

	std::cout << "\n-------------------- TESTING Bureaucrat and Forms ----------------" << std::endl;

	Bureaucrat bureaucrat("ash", 82);
    ShrubberyCreationForm form5("Shrubbery");
    RobotomyRequestForm form6("Robotomy");
    PresidentialPardonForm form7("President");

	std::cout << "\n------------------------ Form 5 ( Shrubbery ) --------------------" << std::endl;
    bureaucrat.signForm(form5);
    bureaucrat.executeForm(form5);

    std::cout << "\n------------------------ Form 6 ( Robotomy ) ---------------------" << std::endl;
    bureaucrat.signForm(form6);
    bureaucrat.executeForm(form6);
	bureaucrat.executeForm(form6);
    bureaucrat.executeForm(form6);
    bureaucrat.executeForm(form6);
    std::cout << "\n------------------------ Form 7 ( President ) --------------------" << std::endl;
    bureaucrat.signForm(form7);
    bureaucrat.executeForm(form7);
}
