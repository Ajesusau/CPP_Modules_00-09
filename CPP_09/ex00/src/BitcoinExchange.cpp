#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	std::cout << "BitcoinExchange copy constructor called" << std::endl;
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	std::cout << "BitcoinExchange copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_dataBase = other._dataBase;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << "BitcoinExchange destructor called" << std::endl;
}

void	BitcoinExchange::execute(const std::string& file) {
	saveDataBase();
	std::string	line;
	std::string	date;
	std::string strValue;
	size_t		pos;
	double		value;
	bool		firstline = true;

	std::ifstream fileInput(file.c_str());
	if (!fileInput.is_open()) 
		throw InaccessibleFileException();
	while (std::getline(fileInput, line)) {
		if (firstline) {
			firstline = false;
			if (line == "date | value")
				continue;	
		}
		pos = line.find('|');
		date = strTrim(line.substr(0, pos));
		strValue = line.substr(pos + 1);
		value = std::atof(strValue.c_str());
		if(pos == std::string::npos || !checkFormatDate(date) || !isNumber(strTrim(strValue)))
			std::cerr << "Error: bad input => " << line << std::endl;
		else if (value < 0)
			std::cerr << "Error: not a positive number." << std::endl;
		else if (value > 1000)
			std::cerr << "Error: too large a number." << std::endl;
		else {
			std::map<std::string, float>::iterator it = _dataBase.lower_bound(date);
			if (it != _dataBase.end() && it->first == date)
				std::cout << date << " => " << value << " = " << value * it->second << std::endl;
			else if (it != _dataBase.begin()) {
				--it;
				std::cout << date << " => " << value << " = " << value * it->second << std::endl;
			} else
				std::cerr << "Error: no previous date in database." << std::endl;
		}
	}
}

void	BitcoinExchange::saveDataBase(){
	std::string	line;
	size_t		pos;

	std::ifstream fileInput("db/data.csv");
	if (!fileInput.is_open()) 
		throw InaccessibleDataBaseException();
	while (std::getline(fileInput, line)) {
		pos = line.find(',');
		this->_dataBase[line.substr(0,pos)] = std::atof(line.substr(pos + 1).c_str());
	}
}

std::string BitcoinExchange::strTrim(const std::string& str) {
    size_t start = 0;
    size_t end = str.length();
    
    while (start < end && std::isspace(str[start]))
        start++;
    while (end > start && std::isspace(str[end - 1]))
        end--;
    
    return str.substr(start, end - start);
}

bool	BitcoinExchange::checkFormatDate(std::string date) {
	long		month = -1;
	long		year = -1;
	long		day = -1;
	std::string	aux;
	size_t		pos;

	if (date.empty())
		return false;
	else {
		while (year == -1 || month == -1 || day == -1) {
			pos = date.find('-');
			if (pos == std::string::npos && (year == -1 || month == -1))
				return false;
			else {
				if (year == -1) {
					aux = (date.substr(0, pos));
					if (!isInteger(aux))
						return false;
					else
						year = std::atol(aux.c_str());
				} else if (month == -1) {
					aux = (date.substr(0, pos));
					if (!isInteger(aux))
						return false;
					else
						month = std::atol(aux.c_str());
					}
				else {
					aux = (date.substr(0, date.length()));
					if (!isInteger(aux))
						return false;
					else
						day = std::atol(aux.c_str());
					break;
				}
				date = date.substr(pos + 1);
			}
		}
		if (isValidDate(year, month, day))
			return true;
		else
			return false;
	}
}

bool		BitcoinExchange::isNumber(const std::string str) {
	size_t	i = 0;
	bool 	dot = false;
	bool	sign = false;
	if (!str.empty()) {
		if ((str[0] == '-' || str[0] == '+') && str[1]) {
			i++;
			sign = true;
		}
		while (str[i]) {
			if (!std::isdigit(str[i])) {
				if (i > 0 && str[i] == '.' && !dot && i != str.length() - 1)
					dot = true;
				else if (sign && i > 1 && str[i] == '.' && !dot && i != str.length() - 1)
					dot = true;
				else
					return false;
			}
			i++;
		}
		return true;
	}
	return false;
}

bool		BitcoinExchange::isInteger(const std::string str) {
	size_t i = 0;
	if (!str.empty()) {
		while (str[i]) {
			if (!std::isdigit(str[i]))
				return false;
			i++;
		}
		return true;
	}
	return false;
}

bool		BitcoinExchange::isValidDate(long year, long month, long day) {
	int month_limits[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (year < 2000 || month > 12 || month < 1)
		return false;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		month_limits[1] = 29;
	if (day > month_limits[month - 1] || day < 1)
		return false;
	return	true;

}



const char*	BitcoinExchange::InaccessibleDataBaseException::what() const throw() {
	return "The database is not accessible.";
}

const char*	BitcoinExchange::InaccessibleFileException::what() const throw() {
	return "The file is not accessible.";
}
