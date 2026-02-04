#pragma once

#	include <string>
#	include <exception>
#	include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_signGrade;
		int const			_execGrade;
	public:
		Form();
		Form(std::string const name, int signGrade, int execGrade);
		Form(Form const &copy);
		Form&	operator=(Form const &copy);
		virtual ~Form();

		void	beSigned(Bureaucrat& bureaucrat);

		std::string const	getName() const;
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
};

std::ostream&	operator<<(std::ostream &o, Form& form);