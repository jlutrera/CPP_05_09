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
	~RobotomyRequestForm();
	std::string getTarget() const;
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &copy);
	void	execute(Bureaucrat const &executor) const;
private:
	std::string	_target;
};

# endif
