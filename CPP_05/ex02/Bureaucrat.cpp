#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
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
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &Bureaucrat)
{
	out << "Bureaucrat Name    : " << Bureaucrat.getName() << std::endl;
	out << "   Grade           : " << Bureaucrat.getGrade() << std::endl;
	return (out);
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signs " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << getName() << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << getName() << " executes " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << getName() << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
	}
}