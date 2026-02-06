#pragma once

#	include "AForm.hpp"

class AForm;

class PresidentialPardonForm: public AForm {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const& copy);
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm&	operator=(PresidentialPardonForm const& copy);

		void	action() const;
};