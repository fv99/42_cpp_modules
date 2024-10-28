#pragma once

#include <iostream>
#include <map>
#include <stdexcept>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

// using map container

class BitcoinExchange
{
	private:
		std::map<std::string, double> _db;

	public:
		BitcoinExchange(void);
		BitcoinExchange(const std::string path);
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange(void);
		
		BitcoinExchange &operator=(const BitcoinExchange &src);

		void loadExchangeRates(const std::string &filename);
		void processInput(const std::string &filename) const;

		double getRate(const std::string &datestr) const;
		bool validateRate(const std::string &valuestr, double &value) const;
		bool validateDate(const std::string &datestr) const;

};
