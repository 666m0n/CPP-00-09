#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) : _data(src._data){}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
    if (this != &src)
        _data = src._data;
    return *this;
}

BitcoinExchange::~BitcoinExchange(){}

const std::map<std::string, float>& BitcoinExchange::getData() const { return _data; }

void BitcoinExchange::loadData(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error(ERR_OPEN_FILE);

    std::string line;
    getline(file, line);

    while (std::getline(file, line))
    {
        size_t comma = line.find(',');
        if (comma != std::string::npos)
        {
            //extract from 0 to comma
            std::string date = line.substr(0, comma);
            if (!isValidDate(date))
            {
                std::cerr << ERR_DATE << date << std::endl;
                return ;
            }

            std::string priceStr = line.substr(comma + 1);
            float price;
            std::istringstream(priceStr) >> price;
            _data[date] = price;
        }
    }
    file.close();
}

bool BitcoinExchange::parseFileContent(const std::string& line, std::string& date, float& value)
{

    //find | -> split date & value
    size_t pipe = line.find('|');
    if (!line.empty() && pipe == std::string::npos)
    {
        std::cerr << ERR_DATE << line << std::endl;
        return false;
    }
    date = line.substr(0, pipe);
    std::string valueStr = line.substr(pipe + 1);

    // Trim spaces
    date.erase(0, date.find_first_not_of(" \t"));
    date.erase(date.find_last_not_of(" \t") + 1);
    valueStr.erase(0, valueStr.find_first_not_of(" \t"));
    valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

    //check date
    if (!isValidDate(date))
    {
        std::cerr << ERR_DATE << date << std::endl;
        return false;
    }

    //check value if valid nb (behind |)
    if (!isValidValue(valueStr))
    {
        printError(INVALID_NB);
        return false;
    }

    //covert valueStr to float
    std::istringstream(valueStr) >> value;

    if (value < 0)
    {
        printError(NON_POSITIVE);
        return false;
    }
    if (value > 1000)
    {
        printError(LARGE_NB);
        return false;
    }

    //iterate map to find the closest match date
	std::map<std::string, float>::iterator it = _data.upper_bound(date);
	it--;

    printResult(date, value, value * it->second);
    return true;
}

void BitcoinExchange::parseInputFile(const std::string& fileName)
{
    //open
    std::ifstream file(fileName.c_str());
    if (!file.is_open())
        throw std::runtime_error(ERR_OPEN_FILE);

    //parse/read
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::string date;
        float value = 0.0f;
        parseFileContent(line, date, value);
    }
    file.close();
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
    //format YYYY-MM-DD
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < date.length(); i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
            return false;
    }

    int year, month, day;

    std::istringstream y(date.substr(0, 4));
    y >> year;

    std::istringstream m(date.substr(5, 2));
    m >> month;

    std::istringstream d(date.substr(8, 2));
    d >> day;

    if (month < 0 || month > 12 || day < 1 || day > 31)
        return false;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;

    if (month == 2)
    {
        if (day > 29)
            return false;
        if (day == 29)
        {
            if ((year % 4 != 0) || (year % 100 == 0 && year % 400 != 0)) //count leap year!!
                return false;
        }
    }

    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr)
{

    std::istringstream iss(valueStr);
    float value;
    iss >> value;

    // Check if the conversion was successful
    if (iss.fail() || !iss.eof())
        return false;
    return true;
}

void BitcoinExchange::printError(eError error)
{
    switch (error)
    {
        case OPEN_FILE:
            std::cerr << ERR_OPEN_FILE << std::endl;
            break;
        case NON_POSITIVE:
            std::cerr << ERR_NON_POSITIVE << std::endl;
            break;
        case LARGE_NB:
            std::cerr << ERR_LARGE_NB << std::endl;
            break;
        case INVALID_NB:
            std::cerr << ERR_NB << std::endl;
            break;
        default:
            std::cerr << "Unknown error." << std::endl;
    }
}

void BitcoinExchange::printResult(const std::string& date, float value, float result) const
{
    std::cout << date << " => " << value << " = " << result << std::endl;
}