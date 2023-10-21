#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(1), _gradeToExec(1)
{
}

Form::Form(std::string name, bool sign, int gradeToSign, int gradeToExec) : _name(name), _signed(sign), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) 
{
}

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec)
{
}

Form::~Form()
{
}

Form	&Form::operator=(const Form &copy)
{
	if (this != &copy)
		_signed = copy._signed;
	return (*this);
}

std::string	Form::getName() const
{
	return (_name);
}

int	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int	Form::getGradeToExec() const
{
	return (_gradeToExec);
}

bool	Form::getSigned() const
{
	return (_signed);
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

// void	Form::beSigned(const Bureaucrat &b)
// {
// 	if (b.getGrade() <= getGradeToSign())
// 		_signed = true;
// 	else
// 		throw GradeTooLowException();
// }

std::ostream	&operator<<(std::ostream &out, const Form &form)
{
	out << "Bureaucrat Name    : " << form.getName();
	out << "   Signed          : " << form.getSigned();
	out << "   Grade to sign   : " << form.getGradeToSign();
	out << "   Grade to execute: " << form.getGradeToExec();
	out	<< std::endl;
	return (out);
}
