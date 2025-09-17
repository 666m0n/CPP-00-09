#include "BitcoinExchange.hpp"

////CONSTRUCTOR & DESTRUCTOR
BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) : _data(src._data){}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
    if (this != &src)
        _data = src._data;
    return *this;
}

BitcoinExchange::~BitcoinExchange(){}


////MEMBER FUNCS
//getter
const std::map<std::string, float>& BitcoinExchange::getData() const { return _data; }

/** LOAD DATA
 * 1 open and parse input file
 * 2 Open the exchange rate CSV file
 * @note std::istringstream : Creates an input string stream from the line / extract the two fields (date, rateStr) from that line
 * @note std::string::npos : normally used to indicate that a string was not found
 */
void BitcoinExchange::loadData(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error(ERR_OPEN_FILE);
    
    //Skip header line: "date,exchange_rate"!!
    std::string line;
    getline(file, line);

    //Reads the file line by line -> stored in the line string
    while (std::getline(file, line))
    {
        size_t comma = line.find(',');
        if (comma != std::string::npos)
        {
            //extract frm 0 to comma
            std::string date = line.substr(0, comma);
            if (!isValidDate(date))
            {
                std::cerr << ERR_DATE << date << std::endl;
                return ;
            }

            //extract frm after comma to end
            //Convert the string to a float //c+98 cannot do std::stod(priceStr);
            std::string priceStr = line.substr(comma + 1);
            float price;
            std::istringstream(priceStr) >> price;
            _data[date] = price;
        }
    }
    file.close();
}

//pase file content
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

    //iternate map to find the closest match date
    std::map<std::string, float>::iterator it = _data.lower_bound(date);
    if (it == _data.end() || it->first != date)
    {
        if (it == _data.begin())
        {
            std::cerr << ERR_DATE << date << std::endl;
        }
        --it;
    }

    printResult(date, value, value * it->second);
    return true;
}


/** PARSE INPUT FILE
 * Apply it to the user input
 * @note std::getline(file, line); // Skip header line: "date | value"
 */
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

//CHECKERS
/** IS VALID DATE
 * static -> check dates
 * data content : 2009-01-02,0
 * check format first! YYYY-MM-DD!! 
 * 1 year
 * 2 month
 * 3 date
*/
bool BitcoinExchange::isValidDate(const std::string& date)
{
    //format YYYY-MM-DD
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
        // case DATE:
        //     std::cerr << ERR_DATE;
        //     break;
    //check if all digit
    for (size_t i = 0; i < date.length(); i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
            return false;
    }

    //parse checks
    int year, month, day;
    
    std::istringstream y(date.substr(0, 4));
    y >> year;

    std::istringstream m(date.substr(5, 2));
    m >> month;

    std::istringstream d(date.substr(8, 2));
    d >> day;

    //basic range check
    if (month < 0 || month > 12 || day < 1 || day > 31)
        return false;
    
    //check month with only 30 days
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;

    //check leap year!!
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

/**
 * @note std::stod -> convert str to float
 * @note std::istringstream : Creates an input string stream from the line / extract the two fields (date, rateStr) from that line
 * @note iss.fail() → the extraction failed (not a number)
 * @note iss.eof() →  there are extra characters after the number
 * @note iss >> value; //Convert the string to a float
 * 
 * @return  return value must be within this range!! //value >= 0.0f && value <= 1000.0f
 */
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

//// PRINT ERROR
//printer
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

//PRINT RESULT
void BitcoinExchange::printResult(const std::string& date, float value, float result) const
{
    std::cout << date << " => " << value << " = " << result << std::endl;
}