#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm() {}
RobotomyRequestForm::RobotomyRequestForm():
	AForm("Robotomy Request", 72, 45) {}
RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("Robotomy Request", 72, 45) {this->_target = target;}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& copy):
	AForm("Robotomy Request", 72, 45) { *this = copy; }

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& copy) {
	if (this != &copy)
		this->_target = copy.getTarget();
	return *this;
}

void RobotomyRequestForm::action() const {
	std::cout << "* The Neighbour at 8am a sunday *" << std::endl;
	if (std::rand() % 2)
		std::cout << this->_target << " Robotomy was a success!" << std::endl;
	else std::cout << "What a fail :(" << std::endl;
}
