#include "Contact.hpp"

Contact::Contact(){
	return;
}
Contact::~Contact(){
	return;
}

std::string Contact::getFirstName(){
	return this->_firstName;
}
std::string Contact::getLastName(){
	return this->_lastName;
}
std::string Contact::getNickname(){
	return this->_nickname;
}
std::string Contact::getPhoneNum(){
	return this->_phoneNum;
}
std::string Contact::getSecret(){
	return this->_secret;
}

void Contact::setFirstName(std::string name){
	this->_firstName = name;
	return;
}
void Contact::setLastName(std::string name){
	this->_lastName = name;
	return;
}
void Contact::setNickname(std::string name){
	this->_nickname = name;
	return;
}
void Contact::setPhoneNum(std::string name){
	this->_phoneNum = name;
	return;
}
void Contact::setSecret(std::string name){
	this->_secret = name;
	return;
}
