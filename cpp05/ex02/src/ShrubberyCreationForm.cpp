#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("Shrubbery Creation", 145, 137) {}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("Shrubbery Creation", 145, 137) { this->_target = target; }
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& copy):
	AForm("Shrubbery Creation", 145, 137) { *this = copy; }
ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& copy){
	if (this != &copy)
		this->_target = copy.getTarget();
	return *this;
}

void	ShrubberyCreationForm::action() const {
	std::string fileName = this->_target + "_shrubbery";
	std::ofstream ofs(fileName.c_str());
	if (!ofs.is_open()) {
		std::cerr << "Error: Unable to create \"" << fileName << "\"" << std::endl;
		return;
	}

	ofs << "." << std::endl;
	ofs << "├── include" << std::endl;
	ofs << "│   ├── AForm.hpp" << std::endl;
	ofs << "│   ├── Bureaucrat.hpp" << std::endl;
	ofs << "│   ├── PresidentialPardonForm.hpp" << std::endl;
	ofs << "│   ├── RobotomyRequestForm.hpp" << std::endl;
	ofs << "│   └── ShrubberyCreationForm.hpp" << std::endl;
	ofs << "├── main.cpp" << std::endl;
	ofs << "├── Makefile" << std::endl;
	ofs << "└── src" << std::endl;
	ofs << "    ├── AForm.cpp" << std::endl;
	ofs << "    ├── Bureaucrat.cpp" << std::endl;
	ofs << "    ├── PresidentialPardonForm.cp" << std::endl;
	ofs << "    ├── RobotomyRequestForm.cpp" << std::endl;
	ofs << "    └── ShrubberyCreationForm.cpp" << std::endl;

	ofs.close();
}