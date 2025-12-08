#ifndef CONTACT_H
#	define CONTACT_H

#	include <string>

class Contact{
	public:
		Contact();
		~Contact();

		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickname();
		std::string	getPhoneNum();
		std::string	getSecret();

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