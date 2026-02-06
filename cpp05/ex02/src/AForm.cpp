#include "AForm.hpp"

AForm::AForm(): _signGrade(0), _execGrade(0) {}
AForm::~AForm() {}

AForm::AForm(std::string const name, int signGrade, int execGrade):
	_name(name),
	_isSigned(false),
	_signGrade(signGrade),
	_execGrade(execGrade) {
		if (this->_signGrade > 150 || this->_execGrade > 150) throw GradeTooLowException();
		if (this->_signGrade < 1 || this->_execGrade < 1) throw GradeTooHighException();
	}
AForm::AForm(AForm const& copy): 
	_name(copy.getName()),
	_isSigned(copy.ifSigned()),
	_signGrade(copy.getSignGrade()),
	_execGrade(copy.getExecGrade()) {}
AForm&	AForm::operator=(AForm const& copy) {
	if (this != &copy)
		this->_isSigned = copy.ifSigned();
	return *this;
}

void	AForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->_signGrade) throw GradeTooLowException();
	this->_isSigned = true;
}
void	AForm::execute(Bureaucrat const& executor) const {
	if (!this->_isSigned) throw FormNotSignedException();
	if (executor.getGrade() > this->_execGrade) throw GradeTooLowException();
	action();
}

std::string const AForm::getName() const {return this->_name;}
std::string AForm::getTarget() const {return this->_target;}
bool AForm::ifSigned() const {return this->_isSigned;}
int AForm::getSignGrade() const {return this->_signGrade;}
int AForm::getExecGrade() const {return this->_execGrade;}

std::ostream& operator<<(std::ostream &o, AForm& form) {
	o << "Form Name: " << form.getName() << \
	"\nGrade Required to Sign: " << form.getSignGrade() << \
	"\nGrade Required to Execute: " << form.getExecGrade() << \
	"\nIs the Form Signed: ";
	if (form.ifSigned()) o << "Yes!";
	else o << "No!";
	o << std::endl;
	return o;
}