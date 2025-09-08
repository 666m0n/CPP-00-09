#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string const& string) : _input(string){
	loadCSV();
	parseInput();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& copy) : _dataBase(copy._dataBase), _input(copy._input){
	loadCSV();
	parseInput();
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& rhs){
	if (this != &rhs)
	{
		this->_dataBase = rhs._dataBase;
	}
	return *this;
}

void	BitcoinExchange::loadCSV(){
	std::ifstream infile("data.csv");
	if (!infile)
	{
		std::cerr << "Error: could not open file" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string line;
	std::string header;
	std::getline(infile, header);
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		std::string date;
		std::string rate;
		if (getline(iss, date, ',') && getline(iss, rate))
		{
			try {
				char *end;

				double nb = strtod(rate.c_str(), &end);
				_dataBase[date] = nb;
			}
			catch (std::exception &e) {
				std::cerr << "Cannot convert lign : " << e.what() << std::endl;
			}
		}
	}

	// TO PRINT THE CSV
	// std::map<std::string, double>::iterator it = _dataBase.begin();
	// std::map<std::string, double>::iterator ite = _dataBase.end();
	// for (; it != ite; it++){
	// 	std::cout << std::fixed << std::setprecision(2);
	// 	std::cout << it->first << " : " << it->second << std::endl;
	// }
}

static bool isAllowed(char c)
{
	return ((c >= '0' && c <= '9') || (c == '-') || (c == ' '));
}

static bool isValid(std::string const& date)
{
	for (size_t i = 0; i < date.size() ; i++)
		if (!isAllowed(date[i]))
			return 0;
	return 1;
}

static bool validDate(std::string const& date)
{
	if (date.empty())
		return std::cerr << "Error: empty date." << std::endl, 0;
	if (date.length() != 11 || date[4] != '-' || date[7] != '-')
		return std::cerr << "Error: wrong format." << std::endl, 0;
	if (!isValid(date))
		return std::cerr << "Error: wrong character." << std::endl, 0;

	std::istringstream iss(date);
	std::string year, month, day;
	if (getline(iss, year, '-') && getline(iss, month, '-') && getline(iss, day))
	{
		if (!(atoi(year.c_str()) > 2008 && atoi(year.c_str()) < 2026))
			return std::cerr << "Error: bitcoin rate does not exist at this date." << std::endl, 0;
		if (!(atoi(month.c_str()) > 0 || atoi(month.c_str()) < 13))
			return std::cerr << "Error: bad input => " << date << std::endl, 0;
		if (!(atoi(day.c_str()) > 0 && atoi(day.c_str()) < 32))
			return std::cerr << "Error: bad input => " << date << std::endl, 0;
		if (atoi(year.c_str()) == 2025 && atoi(month.c_str()) == 4 && atoi(day.c_str()) > 15)
			return std::cerr << "Error: bitcoin rate does not exist at this date." << std::endl, 0;
	}
	return 1;
}

static bool validRate(double rate)
{
	if (rate < 0)
		return std::cerr << "Error: not a positive number." << std::endl, 0;
	if (rate > 1000)
		return std::cerr << "Error: too large number." << std::endl, 0;
	return 1;
}

double BitcoinExchange::getNearest(std::string const& date){
	std::map<std::string, double>::iterator it = _dataBase.upper_bound(date);
	it--;
	return it->second;
}

void	BitcoinExchange::parseInput(){
	std::ifstream infile(_input.c_str());
	if (!infile)
	{
		std::cerr << "Error: could not open file" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string line;
	std::string header;
	std::getline(infile, header);
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		std::string date;
		std::string rate;
		if (getline(iss, date, '|') && getline(iss, rate))
		{
			char *end;

			double nb = strtod(rate.c_str(), &end);
			if (*end != '\0')
				std::cerr << "Error: convertion from str to double failed." << std::endl;
			if (validDate(date) && validRate(nb))
				std::cout << date << "=>" << rate << " => " << getNearest(date) * nb << std::endl;
		}
		else
			std::cerr << "Error: bad input => " << date << std::endl;
	}
}
