#include "Bureaucrat.hpp"

std::ostream&	operator<<(std::ostream& o, Bureaucrat const &bureaucrat) {
	o << "Identity: " << bureaucrat.getName() << \
	"\nGrade: " << bureaucrat.getGrade();
	return o;
}

Bureaucrat::Bureaucrat() {}
Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const &copy): _name(copy._name) {
	*this = copy;
}
Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &copy) {
	if (this != &copy)
		this->_grade = copy.getGrade();
	return *this;
}
Bureaucrat::Bureaucrat(std::string const name, int grade): _name(name) {
	if (grade < 1) throw GradeTooHighException();
	if (grade > 150) throw GradeTooLowException();
	this->_grade = grade;
}

void	Bureaucrat::incrementGrade() {
	int i = this->_grade - 1;
	if (i < 1) throw GradeTooHighException();
	else this->_grade = i;
}
void	Bureaucrat::decrementGrade() {
	int i = this->_grade + 1;
	if (i > 150) throw GradeTooLowException();
	else this->_grade = i;
}
void	Bureaucrat::signForm(Form& form) {
	try {
		bool alreadySigned = form.ifSigned();
		form.beSigned(*this);
		if (alreadySigned)
			std::cout << form.getName() << " is already signed!" << std::endl;
		else
			std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch(std::exception& e) {
		std::cout << this->_name << " couldn't sign " << form.getName() << \
		" because " << e.what() << std::endl;
	}
}

std::string const	Bureaucrat::getName() const {return this->_name;}
int					Bureaucrat::getGrade() const {return this->_grade;}