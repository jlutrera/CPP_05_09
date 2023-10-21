#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class BureauCrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	BureauCrat();
	BureauCrat(std::string name, int grade);
	BureauCrat(const BureauCrat &copy);
	~BureauCrat();
	BureauCrat	&operator=(const BureauCrat &copy);
	std::string	getName() const;
	int			getGrade() const;
	void		incrementGrade();
	void		decrementGrade();
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, const BureauCrat &bureaucrat);

# endif // BUREAUCRAT_HPP