#pragma once

#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <limits>
#include <cmath>
#include <iomanip> // precision output , fixed empeche nota scientifique

class BitcoinExchange {
	private:
		std::map<std::string, double> _dataBase;
		std::string const& _input;
		BitcoinExchange();
		void	loadCSV();
		void	parseInput();
		double	getNearest(std::string const& string);

	public:
		BitcoinExchange(std::string const& string);
		BitcoinExchange(BitcoinExchange const& copy);
		~BitcoinExchange(){}
		BitcoinExchange& operator=(BitcoinExchange const& rhs);
};