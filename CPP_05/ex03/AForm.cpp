#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	try
	{
		if (gradeToSign < 1 || gradeToExec < 1)
			throw GradeTooHighException();
		if (gradeToSign > 150 || gradeToExec > 150)
			throw GradeTooLowException();
	}
	catch (const GradeTooHighException & e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	catch (const GradeTooLowException & e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << GREEN << "* Form " << getName() << " is created with " << getGradeToSign() << " grade to sign and " << getGradeToExec() << " to execute. *" << RESET << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec)
{
	std::cout << YELLOW << "Form copy constructor is called." << RESET << std::endl;
}

AForm::~AForm()
{
	std::cout << MAGENTA << "* Form " << getName() << " is destroyed. *" << RESET << std::endl;
}

AForm	&AForm::operator=(const AForm &copy)
{
	std::cout << YELLOW << "Form assignation operator is called." << RESET << std::endl;
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
	try
	{
		if (b.getGrade() <= getGradeToSign())
		{
			if (_signed)
				throw FormAlreadySignedException();
			else
			{
 				_signed = true;
				std::cout << CYAN << b.getName() << " signs " << this->getName() << RESET << std::endl;
			}
		}
		else
 			throw Bureaucrat::GradeTooLowException();
	}
	catch(AForm::FormAlreadySignedException& e)
	{
		std::cerr << getName() << " ";
		std::cerr << e.what() << '\n';
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << b.getName() << " ";
		std::cerr << e.what() << '\n';
	}
}

const char * AForm::FormAlreadySignedException::what() const throw()
{
	return ("Form is already signed");
}

const char * AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low");
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
