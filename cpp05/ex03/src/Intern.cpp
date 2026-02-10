#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(Intern const& copy) { (void)copy; }
Intern::~Intern() {}
Intern& Intern::operator=(Intern const& copy) { (void)copy; return *this; }

AForm* Intern::shrubbery(std::string target) {
	AForm* ret = new ShrubberyCreationForm(target);
	return ret;
}
AForm* Intern::robotomy(std::string target) {
	AForm* ret = new RobotomyRequestForm(target);
	return ret;
}
AForm* Intern::presidential(std::string target) {
	AForm* ret = new PresidentialPardonForm(target);
	return ret;
}

AForm* Intern::makeForm(std::string formName, std::string target) {
	std::string names[] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	AForm* (Intern::*func[])(std::string target) = {
		&Intern::presidential,
		&Intern::robotomy,
		&Intern::shrubbery
	};

	for(u_char i = 0; i < 3; i++) {
		if (formName == names[i])
			return (this->*func[i])(target);
	}
	throw FormNotFoundException();
	return NULL;
}