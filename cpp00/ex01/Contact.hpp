#ifndef CONTACT_H
#	define CONTACT_H

#	include <string>

class Contact{
	public:
		Contact();
		~Contact();

		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		std::string	getPhoneNum() const;
		std::string	getSecret() const;

		void	setFirstName(std::string name);
		void	setLastName(std::string name);
		void	setNickname(std::string name);
		void	setPhoneNum(std::string name);
		void	setSecret(std::string name);

	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNum;
		std::string	_secret;
};

#endif