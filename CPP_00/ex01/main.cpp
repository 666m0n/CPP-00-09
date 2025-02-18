#include "PhoneBook.hpp"
#include <iomanip>
#include <string>
#include <iostream>
#include <cstdlib>

Contact createContact() {
	Contact contact;
	std::string input;

	std::cout << "Enter First Name: ";
	if (!std::getline(std::cin, input) || input.empty()) {
		std::cout << "\nExiting program" << std::endl;
		exit(0);
	}
	contact.setFirstName(input);

	std::cout << "Enter Last Name: ";
	if (!std::getline(std::cin, input) || input.empty()) {
		std::cout << "\nExiting program" << std::endl;
		exit(0);
	}
	contact.setLastName(input);

	std::cout << "Enter Nickname: ";
	if (!std::getline(std::cin, input) || input.empty()) {
		std::cout << "\nExiting program" << std::endl;
		exit(0);
	}
	contact.setNickName(input);

	std::cout << "Enter Phone Number: ";
	if (!std::getline(std::cin, input) || input.empty()) {
		std::cout << "\nExiting program" << std::endl;
		exit(0);
	}
	contact.setPhoneNumber(input);

	std::cout << "Enter Darkest Secret: ";
	if (!std::getline(std::cin, input) || input.empty()) {
		std::cout << "\nExiting program" << std::endl;
		exit(0);
	}
	contact.setDarkestSecret(input);

	return contact;
}

int	main() {
	PhoneBook	phoneBook;
	std::string	command;

	while (true) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command)) {
			std::cout << "\nExiting program" << std::endl;
			break;
		}

		if (command == "ADD") {
			Contact newContact = createContact();
			phoneBook.addContact(newContact);
		}
		else if (command == "SEARCH") {
			phoneBook.searchContact();
		}
		else if (command == "EXIT") {
			break;
		}
	}
	return 0;
}