#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : currentIndex(0), totalContacts(0) {}
PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact(const Contact &contact) {
	contacts[currentIndex] = contact;
	currentIndex = (currentIndex + 1) % 8;
	if (totalContacts < 8)
		totalContacts++;
}

void	PhoneBook::displayContactList() const {
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	std::cout << std::string(43, '-') << std::endl;

	for (int i = 0; i < totalContacts; i++) {
		std::cout << std::setw(10) << i << "|";

		std::string firstName = contacts[i].getFirstName();
		if (firstName.length() > 10)
			firstName = firstName.substr(0, 9) + ".";
		std::cout << std::setw(10) << firstName << "|";

		std::string lastName = contacts[i].getLastName();
		if (lastName.length() > 10)
			lastName = lastName.substr(0, 9) + ".";
		std::cout << std::setw(10) << lastName << "|";

		std::string nickname = contacts[i].getNickname();
		if (nickname.length() > 10)
			nickname = nickname.substr(0, 9) + ".";
		std::cout << std::setw(10) << nickname << std::endl;
	}
}

void	PhoneBook::displayContact(int index) const {
	if (index < 0 || index >= totalContacts) {
		std::cout << "Error: Invalid index" << std::endl;
	}
	std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

void	PhoneBook::searchContact() const {
	if (totalContacts == 0) {
		std::cout << "No contacts in phonebook" << std::endl;
		return ;
	}
	displayContactList();
	int index;
	std::cout << "Enter index to display: ";
	if (!(std::cin >> index)) {
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Error: Invalid input" << std::endl;
	}
	displayContact(index);
}
