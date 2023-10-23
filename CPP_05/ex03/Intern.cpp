#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern::~Intern()
{
}

Intern	&Intern::operator=(const Intern &copy)
{
	(void)copy;
	return (*this);
}

AForm *Intern::RobotomyRequest(std::string target)
{
	return (new RobotomyRequestForm(target));
}

void Intern::ShurbberyCreation(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(std::string const &name, std::string const &target)
{
	ptrf functions[] = { &RobotomyRequest, &ShurbberyCreation, &PresidentPardon};
	std::string names[] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	
	int i = 0;
	while (i < 4 && names[i].compare(name))
		i++;
	if (i < 4)
	{
		std::cout << "Intern creates " + name << std::endl;
		return(this->*functions[i](target));
	}
	if (name == "robotomy request")
	{
		
		
	}
	else if (name == "shrubbery creation")
	{
		std::cout << "Intern creates " + name << std::endl;
		
	}
	else if (name == "presidential pardon")
	{
		std::cout << "Intern creates " + name << std::endl;
		return (new PresidentialPardonForm(target));
	}
	else
		std::cerr << "Form not found" << std::endl;
}
