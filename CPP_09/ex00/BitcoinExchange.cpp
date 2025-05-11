#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	*this = src;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
	if (this != &src) {
		this->_database = src._database;
	}
	return *this;
}

void BitcoinExchange::loadDatabase(const std::string &filename) {
	std::ifstream file(filename.c_str());

	if (!file.is_open()) {
		throw std::runtime_error("Could not open database file");
	}

	std::string line;
    // Ignorer la première ligne (en-tête)
	std::getline(file, line);

	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::string date;
		std::string rateStr;

		// Lire la date et le taux
		if (std::getline(iss, date, ',') && std::getline(iss, rateStr)) {
			float rate;
			std::istringstream(rateStr) >> rate;

            // Stocker dans la map
			_database[date] = rate;
		}
	}

	file.close();
}

bool BitcoinExchange::isValidDate(const std::string &date) const {
    // Vérifier le format YYYY-MM-DD
	if (date.length() != 10)
		return false;

	if (date[4] != '-' || date[7] != '-')
		return false;

    // Vérifier que les caractères sont des chiffres
	for (int i = 0; i < 10; i++) {
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return false;
	}

    // Convertir les composants en nombres
	int year, month, day;
	std::istringstream(date.substr(0, 4)) >> year;
	std::istringstream(date.substr(5, 2)) >> month;
	std::istringstream(date.substr(8, 2)) >> day;

    // Vérifier les valeurs
	if (month < 1 || month > 12)
		return false;

	if (day < 1 || day > 31)
		return false;

    // Vérifier les mois avec 30 jours
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;

    // Vérifier février
	if (month == 2) {
		bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > (isLeapYear ? 29 : 28))
			return false;
	}

	return true;
}

bool BitcoinExchange::isValidValue(const float value) const {
	return value >= 0 && value <= 1000;
}

float BitcoinExchange::getExchangeRate(const std::string &date) const {
    // Trouver la date exacte ou la date antérieure la plus proche
	std::map<std::string, float>::const_iterator it = _database.lower_bound(date);

    // Si la date existe exactement, retourner son taux
	if (it != _database.end() && it->first == date) {
		return it->second;
	}

    // Si la date est avant la première entrée de la base, lancer une exception
	if (it == _database.begin()) {
		throw std::runtime_error("Date too early, no exchange rate available");
	}

    // Sinon, retourner la date antérieure la plus proche
	--it;
	return it->second;
}

void BitcoinExchange::processInput(const std::string &filename) {
	std::ifstream file(filename.c_str());

	if (!file.is_open()) {
		throw std::runtime_error("Could not open input file");
	}

	std::string line;
    // Ignorer la première ligne (en-tête)
	std::getline(file, line);

	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::string dateStr;
		std::string valueStr;

        // Vérifier le format "date | value"
		size_t pipePos = line.find(" | ");
		if (pipePos == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		dateStr = line.substr(0, pipePos);
		valueStr = line.substr(pipePos + 3);

        // Vérifier la validité de la date
		if (!isValidDate(dateStr)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

        // Convertir et vérifier la validité de la valeur
		float value;
		try {
			value = std::stof(valueStr);
		} catch (const std::exception &e) {
			std::cerr << "Error: not a number." << std::endl;
			continue;
		}

		if (value < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}

		if (value > 1000) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		try {
            // Obtenir le taux de change et calculer la valeur
			float rate = getExchangeRate(dateStr);
			float result = value * rate;

            // Afficher le résultat
			std::cout << dateStr << " => " << value << " = " << result << std::endl;
		} catch (const std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}

	file.close();
}