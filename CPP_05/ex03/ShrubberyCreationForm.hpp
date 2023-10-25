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
	~ShrubberyCreationForm();
	std::string getTarget() const;
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &copy);
	void	execute(Bureaucrat const &executor) const;
private:
	std::string	_target;
};

# endif
