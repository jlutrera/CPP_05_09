#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << GREEN << "* Bureaucrat " << getName() << " is born. *" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		if (grade > 150)
			throw GradeTooLowException();
	}
	catch (const Bureaucrat::GradeTooLowException & e)
	{
		_grade = 150;
		std::cerr << RED << e.what() << RESET << '\n';
	}
	catch(const Bureaucrat::GradeTooHighException & e)
	{
		_grade = 1;
		std::cerr << RED << e.what() << RESET << '\n';
	}
	std::cout << GREEN << "* Bureaucrat " << getName() << " is born. *" << RESET << std::endl;	
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << YELLOW << "Bureaucrat copy constructor called." << RESET << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << MAGENTA << "* Bureaucrat " << getName() << " is destroyed. *" << RESET << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << YELLOW << "Bureaucrat assignation constructor called." << RESET << std::endl;
	if (this != &copy)
		_grade = copy._grade;
	return (*this);
}

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	try
	{
		if (_grade == 1)
			throw GradeTooHighException();
		_grade--;
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
}

void		Bureaucrat::decrementGrade()
{
	try
	{
		if (_grade == 150)
			throw GradeTooLowException();
		_grade++;
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade is too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade is too low");
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &Bureaucrat)
{
	out << CYAN << Bureaucrat.getName() << " has grade " << Bureaucrat.getGrade() << RESET;
	return (out);
}
