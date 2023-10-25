#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &copy);
	virtual std::string	getTarget() const;
	virtual void	execute(Bureaucrat const &executor) const;
	
private:
	std::string	_target;
};

# endif
