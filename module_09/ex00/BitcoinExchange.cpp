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
	std::map<std::string, double>::iterator it;
	for (it = this->_db.begin(); it != this->_db.end(); ++it)
		this->_db[it->first] = it->second;
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

void BitcoinExchange::processInput(const std::string &filename) const
{
	std::ifstream input(filename.c_str());
	if (!input.is_open())
		throw std::runtime_error("Error: Cannot open file");

	std::string line;
	std::getline(input, line);

	while (std::getline(input, line))
}
