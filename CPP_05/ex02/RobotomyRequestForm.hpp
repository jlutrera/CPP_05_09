#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &copy);
	virtual std::string	getTarget() const;
	virtual void	execute(Bureaucrat const &executor) const;

private:
	std::string	_target;
};

# endif
