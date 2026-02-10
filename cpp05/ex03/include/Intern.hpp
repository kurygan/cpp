#pragma once

#	include "AForm.hpp"
#	include "PresidentialPardonForm.hpp"
#	include "RobotomyRequestForm.hpp"
#	include "ShrubberyCreationForm.hpp"

class AForm;

class Intern {
	private:
		AForm* shrubbery(std::string target);
		AForm* robotomy(std::string target);
		AForm* presidential(std::string target);
	public:
		Intern();
		Intern(Intern const& copy);
		~Intern();
		Intern& operator=(Intern const& copy);

		AForm* makeForm(std::string formName, std::string target);

		class FormNotFoundException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Form not found!";
				}
		};
};