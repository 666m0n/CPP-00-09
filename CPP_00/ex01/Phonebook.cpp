#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

Contact createContact() {
	Contact contact;
	std::string input;

	std::cout << "Enter First Name: ";
	std::getline(std::cin, input);
	contact.setFirstName(input);

	std::cout << "Enter Last Name: ";
	std::getline(std::cin, input);
	contact.setLastName(input);

	std::cout << "Enter Nickname: ";
	std::getline(std::cin, input);
	contact.setNickName(input);

	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, input);
	contact.setPhoneNumber(input);

	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, input);
	contact.setDarkestSecret(input);

	return contact;
}

int	main() {
	PhoneBook	phoneBook;
	std::string	command;

	while (true) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

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