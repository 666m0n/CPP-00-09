#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

void	Contact::setFirstName(const std::string &name) {
	FirstName = name;
}

void	Contact::setLastName(const std::string &name) {
	LastName = name;
}

void	Contact::setNickName(const std::string &nick) {
	NickName = nick;
}

void	Contact::setPhoneNumber(const std::string &number) {
	PhoneNumber = number;
}

void	Contact::setDarkestSecret(const std::string &secret) {
	DarkestSecret = secret;
}

std::string Contact::getFirstName() const {
	return FirstName;
}

std::string Contact::getLastName() const {
	return LastName;
}

std::string Contact::getNickname() const {
	return NickName;
}

std::string Contact::getPhoneNumber() const {
	return PhoneNumber;
}

std::string Contact::getDarkestSecret() const {
	return DarkestSecret;
}