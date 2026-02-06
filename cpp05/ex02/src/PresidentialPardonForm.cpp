#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
	AForm("Presidential Pardon", 25, 5) {}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& copy):
	AForm("Presidential Pardon", 25, 5) { *this = copy; }
PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("Presidential Pardon", 25, 5) { this->_target = target; }
PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& copy) {
	if (this != &copy)
		this->_target = copy.getTarget();
	return *this;
}

void PresidentialPardonForm::action() const {
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}