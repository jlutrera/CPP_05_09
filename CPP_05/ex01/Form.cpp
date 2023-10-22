#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(1), _gradeToExec(1)
{
}

Form::Form(std::string name, bool sign, int gradeToSign, int gradeToExec) : _name(name), _signed(sign), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) 
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
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

void	Form::beSigned(const Bureaucrat &b)
{
	if (_signed)
		throw FormAlreadySignedException();
	else if (b.getGrade() <= getGradeToSign())
 		_signed = true;	
	else
 		throw GradeTooLowException();
}

const char * Form::FormAlreadySignedException::what() const throw()
{
	return ("form is already signed");
}
const char	*Form::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

std::ostream	&operator<<(std::ostream &out, const Form &form)
{
	std::string word;

	if (form.getSigned())
		word = "YES";
	else
		word = "NOT";
	out << "Form Name          : " << form.getName() << std::endl;
	out << "   Signed State    : " << word << std::endl;
	out << "   Grade to sign   : " << form.getGradeToSign()	<< std::endl;
	out << "   Grade to execute: " << form.getGradeToExec()	<< std::endl << std::endl;
	return (out);
}
