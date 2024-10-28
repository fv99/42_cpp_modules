#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const std::string path)
{
	loadExchangeRates(path);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : _db(src._db) {}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    if (this != &src)
    {
        _db = src._db;
    }
    return *this;
}

// open .csv file, read and split each line
// convert rate to double and store in map
void BitcoinExchange::loadExchangeRates(const std::string &filename)
{
	std::ifstream _file(filename.c_str());
	if (!_file.is_open())
		throw std::runtime_error("Error: Cannot open file");

	std::string line;
	std::getline(_file, line);

	while (std::getline(_file, line))
	{
		std::istringstream ss(line);
		std::string date, rate;

		if (std::getline(ss, date, ',') && std::getline(ss, rate))
		{
			double ex = std::atof(rate.c_str());
			_db[date] = ex;
		}
	}
	_file.close();
}

// read input file
void BitcoinExchange::processInput(const std::string &filename) const
{
    std::ifstream input(filename.c_str());
    if (!input.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(input, line); // Skip header if present

    while (std::getline(input, line))
    {
        // Remove whitespace
        line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
        size_t delimiterPos = line.find('|');
        if (delimiterPos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string dateStr = line.substr(0, delimiterPos);
        std::string valueStr = line.substr(delimiterPos + 1);

        if (!validateDate(dateStr))
            continue;

        double value;
        if (!validateRate(valueStr, value))
            continue;

        double rate = getRate(dateStr);
        if (rate == 0.0)
            continue;

        double result = rate * value;
        std::cout << dateStr << " => " << value << " = " << result << std::endl;
    }
    input.close();
}

double BitcoinExchange::getRate(const std::string &datestr) const
{
	std::map<std::string, double>::const_iterator it = _db.find(datestr); // iterates to find exchange rate equal to datestr
	
	if (it != _db.end()) // means we found the exact date
		return it->second; // return the second element of map

	// if not found, find the closest earlier date
    it = _db.lower_bound(datestr); // lower_bound returns first date greater than exact date
    if (it != _db.begin())	// increment it down to get the closest earlier date
    {
		--it;
		return it->second;
	} 
	else
    {
        std::cerr << "Error: no exchange rate available for date " << datestr << std::endl;
        return 0.0;
    }
}

bool BitcoinExchange::validateDate(const std::string &datestr) const
{
    if (datestr.length() != 10 || datestr[4] != '-' || datestr[7] != '-')
    {
        std::cerr << "Error: bad input => " << datestr << std::endl;
        return false;
    }

    std::string yearstr = datestr.substr(0, 4);
    std::string monthstr = datestr.substr(5, 2);
    std::string daystr = datestr.substr(8, 2);

    int month = std::atoi(monthstr.c_str());
    int day = std::atoi(daystr.c_str());

    if (month < 1 || month > 12)
    {
        std::cerr << "Error: bad input => " << datestr << std::endl;
        return false;
    }
    if (day < 1 || day > 31)
    {
        std::cerr << "Error: bad input => " << datestr << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::validateRate(const std::string &valuestr, double &value) const
{
    char *end;
    value = std::strtod(valuestr.c_str(), &end);

    if (*end != '\0')
    {
        std::cerr << "Error: invalid value" << std::endl;
        return false;
    }
    if (value < 0)
    {
        std::cerr << "Error: value is negative" << std::endl;
        return false;
    }
    if (value > 1000)
    {
        std::cerr << "Error: value too large" << std::endl;
        return false;
    }
    return true;
}
