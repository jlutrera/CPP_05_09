#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExec;

public:
	Form();
	Form(std::string name, bool sign, int gradeToSign, int gradeToExec);
	Form(const Form &copy);
	~Form();
	Form	&operator=(const Form &copy);
	std::string	getName() const;
	int			getGradeToSign() const;
	int			getGradeToExec() const;
	bool		getSigned() const;
	void		beSigned(const Bureaucrat &b);

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class FormAlreadySignedException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, const Form &form);

# endif
