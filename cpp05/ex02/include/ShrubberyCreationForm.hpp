#pragma once

#	include <fstream>
#	include "AForm.hpp"

class AForm;

class ShrubberyCreationForm: public AForm {
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const& copy);
		~ShrubberyCreationForm();
		ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& copy);

		void	action() const;
};