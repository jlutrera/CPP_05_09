#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExec;

public:
	AForm();
	AForm(std::string name, bool sign, int gradeToSign, int gradeToExec);
	AForm(const AForm &copy);
	virtual ~AForm();
	virtual AForm	&operator=(const AForm &copy);
	std::string	getName() const;
	virtual int			getGradeToSign() const;
	virtual int			getGradeToExec() const;
	virtual bool		getSigned() const;
	virtual void		beSigned(const Bureaucrat &b);
	virtual void 		execute(Bureaucrat const &executor) const = 0;
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
	class FormNotSignedException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, const AForm &form);

# endif
