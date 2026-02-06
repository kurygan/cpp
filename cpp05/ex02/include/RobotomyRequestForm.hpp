#pragma once

#	include "AForm.hpp"
#	include <cstdlib>

class AForm;

class RobotomyRequestForm: public AForm {
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const& copy);
		~RobotomyRequestForm();
		RobotomyRequestForm&	operator=(RobotomyRequestForm const& copy);

		void	action() const;
};