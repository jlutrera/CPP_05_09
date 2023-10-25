#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _target(copy._target)
{
	std::cout << YELLOW << "PresidentialPardonForm copy constructor is called." << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{

	if (this != &copy)
		_target = copy._target;
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (executor.getGrade() > getGradeToExec())
			throw GradeTooLowException();
		if (!getSigned())
			throw FormNotSignedException();
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
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
