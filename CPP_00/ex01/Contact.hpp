#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
	private:
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string PhoneNumber;
		std::string DarkestSecret;

	public:
		Contact();
		~Contact();
//setters
		void setFirstName(const std::string &name);
		void setLastName(const std::string &name);
		void setNickName(const std::string &nick);
		void setPhoneNumber(const std::string &number);
		void setDarkestSecret(const std::string &secret);
//getters
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
};

#endif