#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
}

AForm::AForm(std::string name, bool sign, int gradeToSign, int gradeToExec) : _name(name), _signed(sign), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) 
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec)
{
}

AForm::~AForm()
{
}

AForm	&AForm::operator=(const AForm &copy)
{
	if (this != &copy)
		_signed = copy._signed;
	return (*this);
}

std::string	AForm::getName() const
{
	return (_name);
}

int	AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int	AForm::getGradeToExec() const
{
	return (_gradeToExec);
}

bool	AForm::getSigned() const
{
	return (_signed);
}

void	AForm::beSigned(const Bureaucrat &b)
{
	if (_signed)
		throw FormAlreadySignedException();
	if (b.getGrade() > getGradeToSign())
		throw GradeTooLowException();
 	_signed = true;
}

const char * AForm::FormAlreadySignedException::what() const throw()
{
	return ("form is already signed");
}

const char * AForm::FormNotSignedException::what() const throw()
{
	return ("form is not signed");
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

std::ostream	&operator<<(std::ostream &out, const AForm &form)
{
	std::string word;

	if (form.getSigned())
		word = "YES";
	else
		word = "NOT";
	out << "AForm Name          : " << form.getName() << std::endl;
	out << "   Signed State    : " << word << std::endl;
	out << "   Grade to sign   : " << form.getGradeToSign()	<< std::endl;
	out << "   Grade to execute: " << form.getGradeToExec()	<< std::endl << std::endl;
	return (out);
}
