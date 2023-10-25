#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const &target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm	&operator=(const PresidentialPardonForm &copy);
	virtual std::string	getTarget() const;
	virtual void	execute(Bureaucrat const &executor) const;
private:
	std::string	_target;
};

# endif
