#pragma once

#include <iostream>
#include <map>
#include <stdexcept>
#include <fstream>
#include <string>
#include <sstream>

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

};