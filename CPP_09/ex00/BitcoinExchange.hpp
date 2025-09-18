#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <limits>
#include <string>
#include <sstream>
#include <fstream>

#define ERR_OPEN_FILE "Error: could not open file."
#define ERR_NB "Error: invalid number."
#define ERR_NON_POSITIVE "Error: not a positive number."
#define ERR_DATE "Error: bad input => "
#define ERR_LARGE_NB "Error: too large a number."

enum eError
{
    OPEN_FILE,
    NON_POSITIVE,
    LARGE_NB,
    INVALID_NB
};

class BitcoinExchange
{
    private:
        std::map<std::string, float> _data;

        static bool isValidDate(const std::string& date);
        static bool isValidValue(const std::string& value);

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(const BitcoinExchange &src);
        ~BitcoinExchange();

        const std::map<std::string, float>& getData() const;

        void loadData(const std::string& filename);
        void parseInputFile(const std::string& fileName);
        bool parseFileContent(const std::string& line, std::string& date, float& value);

        void printError(eError error);
        void printResult(const std::string& date, float value, float result) const;
};

#endif
