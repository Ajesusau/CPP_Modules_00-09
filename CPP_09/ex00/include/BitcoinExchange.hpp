#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <exception>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <map>


class BitcoinExchange
{
	private:
		std::string strTrim(const std::string& str);
		std::map<std::string, float> _dataBase;
		void	saveDataBase();
		bool	checkFormatDate(std::string date);
		bool	isNumber(const std::string str);
		bool	isInteger(const std::string str);
		bool	isValidDate(long year, long month, long day);

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		void	execute(const std::string& file);

		class	InaccessibleDataBaseException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		class	InaccessibleFileException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

};
#endif
