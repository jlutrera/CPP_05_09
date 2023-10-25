#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target)
{
	std::cout << YELLOW << "ShrubberyCreationForm copy constructor is called." << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (this != &copy)
		_target = copy._target;
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (executor.getGrade() > getGradeToExec())
			throw GradeTooLowException();
		if (!getSigned())
			throw FormNotSignedException();
		std::ofstream file;
		file.open((_target + "_shrubbery").c_str());

	 	file << "                                              ." << std::endl;
	    file << "                                   .         ;" << std::endl;
	    file << "      .              .              ;%     ;;" << std::endl;
	    file << "        ,           ,                :;%  %;" << std::endl;
	    file << "         :         ;                   :;%;'     .," << std::endl;
	    file << ",.        %;     %;            ;        %;'    ,;" << std::endl;
	    file << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
	    file << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl;
	    file << "    ;%;      %;        ;%;        % ;%;  ,%;" << std::endl;
	    file << "     `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
	    file << "      `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
	    file << "         `:%;.  :;bd%;          %;@%;'" << std::endl;
	    file << "           `@%:.  :;%.         ;@@%;" << std::endl;
	    file << "             `@%.  `;@%.      ;@@%;" << std::endl;
   	 	file << "               `@%%. `@%%    ;@@%;" << std::endl;
   	 	file << "                 ;@%. :@%%  %@@%;" << std::endl;
    	file << "                   %@bd%%%bd%%:;" << std::endl;
    	file << "                     #@%%%%%:;;" << std::endl;
    	file << "                     %@@%%%::;" << std::endl;
    	file << "                     %@@@%(o);  . '" << std::endl;
    	file << "                     %@@@o%;:(.,'" << std::endl;
    	file << "                 `.. %@@@o%::;" << std::endl;
    	file << "                    `)@@@o%::;" << std::endl;
    	file << "                     %@@(o)::;" << std::endl;
    	file << "                    .%@@@@%::;" << std::endl;
    	file << "                    ;%@@@@%::;." << std::endl;
    	file << "               ...;%@@@@@%%:;;;." << std::endl;
		file.close();

		std::cout << executor.getName() << " executes " << getName() << std::endl;
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
