#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b("Bureaucrat", 140);
		Bureaucrat b2("Bureaucrat2", 64);
		ShrubberyCreationForm s("Home");
		RobotomyRequestForm r("Robot");
		PresidentialPardonForm p("President");

		b.signForm(s);
		b2.signForm(s);
		b.executeForm(s);
		b2.executeForm(s);
		b.signForm(r);
		b2.signForm(r);
		b.executeForm(r);
		b2.executeForm(r);
		b.signForm(p);
		b2.signForm(p);
		b.executeForm(p);
		b2.executeForm(p);
}