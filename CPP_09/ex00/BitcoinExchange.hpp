#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class BitcoinExchange {
private:
	std::map<std::string, float> _database;  // Stockage des taux de change par date

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &src);
	~BitcoinExchange();
	BitcoinExchange &operator=(const BitcoinExchange &src);

	// Initialise la base de données à partir du fichier CSV
	void loadDatabase(const std::string &filename);

    // Traite le fichier d'entrée et affiche les résultats
	void processInput(const std::string &filename);

    // Valide le format de la date (YYYY-MM-DD)
	bool isValidDate(const std::string &date) const;

    // Valide la valeur (entre 0 et 1000)
	bool isValidValue(const float value) const;

    // Trouve le taux de change pour une date donnée
	float getExchangeRate(const std::string &date) const;
};

#endif