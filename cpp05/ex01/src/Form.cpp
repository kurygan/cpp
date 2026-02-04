#include "Form.hpp"

Form::Form(): _signGrade(0), _execGrade(0) {}
Form::~Form() {}

Form::Form(std::string const name, int signGrade, int execGrade):
	_name(name),
	_isSigned(false),
	_signGrade(signGrade),
	_execGrade(execGrade) {
		if (this->_signGrade > 150 || this->_execGrade > 150) throw GradeTooLowException();
		if (this->_signGrade < 1 || this->_execGrade < 1) throw GradeTooHighException();
	}
Form::Form(Form const& copy): 
	_name(copy.getName()),
	_isSigned(copy.ifSigned()),
	_signGrade(copy.getSignGrade()),
	_execGrade(copy.getExecGrade()) {}
Form&	Form::operator=(Form const& copy) {
	if (this != &copy)
		this->_isSigned = copy.ifSigned();
	return *this;
}

void	Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->_signGrade) throw GradeTooLowException();
	this->_isSigned = true;
}

std::string const Form::getName() const {return this->_name;}
bool Form::ifSigned() const {return this->_isSigned;}
int Form::getSignGrade() const {return this->_signGrade;}
int Form::getExecGrade() const {return this->_execGrade;}

std::ostream& operator<<(std::ostream &o, Form& form) {
	o << "Form Name: " << form.getName() << \
	"\nGrade Required to Sign: " << form.getSignGrade() << \
	"\nGrade Required to Execute: " << form.getExecGrade() << \
	"\nIs the Form Signed: ";
	if (form.ifSigned()) o << "Yes!";
	else o << "No!";
	o << std::endl;
	return o;
}