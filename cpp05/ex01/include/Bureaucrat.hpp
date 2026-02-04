#pragma once

#	include <iostream>
#	include <string>
#	include <exception>
#	include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		std::string const	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat&	operator=(Bureaucrat const &copy);
		virtual ~Bureaucrat();

		void	incrementGrade();
		void	decrementGrade();
		void	signForm(Form& form);

		std::string const	getName() const;
		int					getGrade() const;

		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Grade is too high!";
				}
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Grade is too low";
				}
		};
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const &bureaucrat);
