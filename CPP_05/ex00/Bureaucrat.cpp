#include "Bureaucrat.hpp"

BureauCrat::BureauCrat() : _name("default"), _grade(150)
{
}

BureauCrat::BureauCrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

BureauCrat::BureauCrat(const BureauCrat &copy) : _name(copy._name), _grade(copy._grade)
{
}

BureauCrat::~BureauCrat()
{
}

BureauCrat	&BureauCrat::operator=(const BureauCrat &copy)
{
	if (this == &copy)
		return (*this);
	BureauCrat	*tmp = new BureauCrat(copy);
	return (*tmp);
}

std::string	BureauCrat::getName() const
{
	return (_name);
}

int			BureauCrat::getGrade() const
{
	return (_grade);
}

void		BureauCrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void		BureauCrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

const char	*BureauCrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*BureauCrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream	&operator<<(std::ostream &out, const BureauCrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (out);
}
