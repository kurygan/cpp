#pragma once

#	include <string>
#	include <exception>
#	include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	protected:
		virtual void	action() const = 0;
		std::string		_target;
	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_signGrade;
		int const			_execGrade;
	public:
		AForm();
		AForm(std::string const name, int signGrade, int execGrade);
		AForm(AForm const &copy);
		AForm&	operator=(AForm const &copy);
		virtual ~AForm();

		void	beSigned(Bureaucrat& bureaucrat);
		void	execute(Bureaucrat const& executor) const;

		std::string const	getName() const;
		std::string			getTarget() const;
		bool				ifSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;

		class GradeTooHighException: public std::exception{
			public:
				virtual const char* what() const throw() {
					return "Grade is too high!";
				}
		};
		class GradeTooLowException: public std::exception{
			public:
				virtual const char* what() const throw() {
					return "Grade is too low!";
				}
		};
		class FormNotSignedException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Form is not signed!";
				}
		};
};

std::ostream&	operator<<(std::ostream &o, AForm& form);