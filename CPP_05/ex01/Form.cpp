#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(1), _gradeToExec(1)
{
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) 
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

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec)
{
	std::cout << YELLOW << "Form copy constructor is called." << RESET << std::endl;
}

Form::~Form()
{
	std::cout << MAGENTA << "* Form " << getName() << " is destroyed. *" << RESET << std::endl;
}

Form	&Form::operator=(const Form &copy)
{
	std::cout << YELLOW << "Form assignation operator is called." << RESET << std::endl;
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
	catch(Form::FormAlreadySignedException& e)
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

const char * Form::FormAlreadySignedException::what() const throw()
{
	return ("Form is already signed");
}
const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low");
}

std::ostream	&operator<<(std::ostream &out, const Form &form)
{
	std::string word;

	if (form.getSigned())
		word = "YES";
	else
		word = "NOT";
	out << CYAN; 
	out << "Form Name          : " << form.getName() << std::endl;
	out << "   Signed State    : " << word << std::endl;
	out << "   Grade to sign   : " << form.getGradeToSign()	<< std::endl;
	out << "   Grade to execute: " << form.getGradeToExec();
	out	<< RESET;
	return (out);
}
