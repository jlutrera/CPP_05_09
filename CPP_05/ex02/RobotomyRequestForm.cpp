#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
}
RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target)
{
	std::cout << YELLOW << "RobotomyRequestForm copy constructor is called." << RESET << std::endl;
	
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this != &copy)
		_target = copy._target;
	return (*this);
}

std::string	RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (executor.getGrade() > getGradeToExec())
			throw GradeTooLowException();
		if (!getSigned())
			throw FormNotSignedException();
		std::cout << "Drilling noises... " << std::endl;
		if (rand() % 2)
			std::cout << _target << " has been robotomized successfully" << std::endl;
		else
			std::cout << _target << " robotomization failed" << std::endl;
	}
	catch (const  FormNotSignedException & e)
	{
		std::cerr << executor.getName() << " cannot execute " << getName() << " because ";
		std::cerr << e.what() << std::endl;
	}
	catch (const GradeTooLowException & e)
	{
		std::cerr << executor.getName() << " cannot execute " << getName() << " because ";
		std::cerr << e.what() << std::endl;
	}
}
