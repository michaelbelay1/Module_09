/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:59:10 by mhaile            #+#    #+#             */
/*   Updated: 2024/06/12 16:10:49 by mhaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {
	*this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src) {
	if (this != &src)
		_data = src._data;	
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::printData() {
    std::map<std::string, std::string>::iterator it;
    for (it = _data.begin(); it != _data.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }
}

// Getter for _data.
std::map<std::string, std::string> BitcoinExchange::getData() {
	return _data;
}

// returns true if infile is open and not empty, else throws exception
bool BitcoinExchange::is_infile(std::ifstream& file) {
	if (file.is_open()) {
		if (file.peek() == EOF) {
			throw fileEmptyException();
		}
	}
	else {
		throw fileNotFoundException();
	}
	return true;
}

// returns true if string is a digit, else false
bool BitcoinExchange::isDigit(std::string str) {
	for(int i = 0; i < (int)str.length(); i++) {
		if (!isdigit(str[i])) {
			std::cout << "Error: Nondigit character found on Date" << std::endl;
			return false;
		}
	}
	return true;
}

// Checks if a year is a leap year. Returns false if it is not.
bool BitcoinExchange::isLeapYear(int dayInt, int monthInt, int yearInt) {
	if (monthInt == 2) {
		if ((yearInt % 4 == 0 && yearInt % 100 != 0) || (yearInt % 400 == 0)) {
			if (dayInt > 29) {
				return false;
			}
		}
		else {
			if (dayInt > 28) {
				return false;
			}
		}
	}
	return true;
}

// Parse value from the input file. Returns 1 if value is invalid.
int BitcoinExchange::parseValue(std::string value) {
	if (value.empty()) {
		std::cout << "Error: Value is empty" << std::endl;
		return 1;
	}
	char *endptr;
	double val = std::strtod(value.c_str(), &endptr);
	if (*endptr != '\0') {
		std::cout << "Error: bad input => " << value << std::endl;
		return 1;
	}
	if (val < 0) {
		std::cout << "Error: not a positive number." << std::endl;
		return 1;
	}
	else if (val > 1000) {
		std::cout << "Error: too large a number." << std::endl; 
		return 1;
	}

	return 0;
}

// Trim whitespace from a string.
std::string BitcoinExchange::ft_trim(std::string str) {
	size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first)
        return str;

    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

// Get the closest previous day from a given dates. 
std::string BitcoinExchange::previousDay(std::string& date) {
	std::map<std::string, std::string>::iterator it;

	it = _data.lower_bound(date);
	if (it == _data.begin()) {
		return "2009-01-01";
	}
	if (it == _data.end() || it->first != date) {
		--it;
	}
	
	return it->first;
}

// Convert a string to an integer using stringstream.
double BitcoinExchange::ft_stoi(const std::string& str) {
	double num;
	std::stringstream ss(str);
	ss >> num;
	return num;
}

// Parse date from the input and DB files. Returns 1 if date is invalid.
int BitcoinExchange::parseDate(std::string date) {
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);
	int yearInt, monthInt, dayInt;

	if (date.length() != 10 || date[4] != '-' || date[7] != '-'
		|| !isDigit(year) || !isDigit(month) || !isDigit(day))
		return 1;
	
	std::stringstream ssYear(year);
	std::stringstream ssMonth(month);
	std::stringstream ssDay(day);

	ssYear >> yearInt;
	ssMonth >> monthInt;
	ssDay >> dayInt;

	if ((yearInt > 2024) || (monthInt < 1 || monthInt > 12)
		|| (dayInt < 1 || dayInt > 31)) {
		return 1;
	}
	// if ((yearInt < 2009 || yearInt > 2022)
	// 	|| (monthInt < 1 || monthInt > 12)
	// 	|| (dayInt < 1 || dayInt > 31)) {
	// 	return 1;
	// }
	// if (yearInt == 2009) {
	// 	if (monthInt == 1) {
	// 		if (dayInt < 2) {
	// 			return 1;
	// 		}
	// 	}
	// }

	if ((monthInt == 4 || monthInt == 6 || monthInt == 9
		|| monthInt == 11) && dayInt > 30) {
		return 1;
	}
	
	if (!isLeapYear(dayInt, monthInt, yearInt))
		return 1;
		
	return 0;
}

// Find the lower closest date to the input date. 
std::map<std::string, std::string>::iterator  BitcoinExchange::closestDate(std::string date) {
	std::map<std::string, std::string>::iterator it;
	std::string prevDate = date;
	it = _data.find(date);
	if (it != _data.end())
		return it;
	while (it == _data.end()) {
		std::string& currentDate = prevDate;
		
		prevDate = previousDay(currentDate);
		if (prevDate == "2009-01-01")
			return _data.end();
		it = _data.find(prevDate);
	}
	return it;
	
}

// After parsing is done, extract the value from the input file. Display the final result.
int BitcoinExchange::extractValue(std::ifstream& file) {
	std::string line;

	std::getline(file, line);
	if (line[line.length() - 1] == '\r')
		line = line.substr(0, line.length() - 1);
	if (line != "date | value") {
		std::cout << "Invalid infile header formate" << std::endl;
		return 1;
	}
		
	while (std::getline(file, line)) {
		size_t pos = line.find('|');
		std::string date = ft_trim(line.substr(0, pos));
		std::string value = ft_trim(line.substr(pos + 1));
		if (value[value.length() - 1] == '\r')
			value = value.substr(0, value.length() - 1);
	
		if (parseValue(value))
			continue;
		
		if (parseDate(date)) {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		std::map<std::string, std::string>::iterator it = closestDate(date);
		if (it == _data.end()) {
			std::cout << "Error: No data found for " << date << std::endl;
			continue;
		}
		
		std::cout << date << " => " << value << " = " << ft_stoi(it->second) * ft_stoi(value) << std::endl;
	}
	return 0;
}

// Parse DB, then store the data in a map. returns 1 if DB is invalid.
int BitcoinExchange::setDB(std::ifstream& file) {
	std::string line;

	if (!file.is_open())
		throw fileNotFoundException();

	if (file.peek() == EOF)
		throw invalidDBException();
	
	std::getline(file, line);
	if (line.length() != 18 || line != "date,exchange_rate")
		throw invalidDBException();
	while(std::getline(file, line)) {
		std::string date = ft_trim(line.substr(0, line.find(",")));
		std::string value = ft_trim(line.substr(line.find(",") + 1, line.length()));
		
		if (date.length() != 10 || (date[4] != '-' || date[7] != '-')) {
			std::cout << "Error: date formate in DB => " << date << std::endl;
			continue;
		}

		char *endptr;
		double val = std::strtod(value.c_str(), &endptr);
		if (*endptr != '\0' || val < 0) {
			std::cout << "Error: Invalid value in DB: " << value << std::endl;
			continue;
		}
		
		if (parseDate(date)) {
			std::cout << "Error: Invalid date in DB: " << date << std::endl;
			continue;
		}
		
		if (_data.find(date) != _data.end()) {
			std::cout << "Error: Duplicate date in DB: " << date << std::endl;
			continue;
		}

		_data[date] = value;
	}
	if (_data.empty())
		throw invalidDBException();
	return (0);
}

// Main function to execute the program.
void BitcoinExchange::exec(std::string input) {
	std::ifstream DB("data.csv");
	std::ifstream file(input.c_str());

	if (setDB(DB))
		return ;

	if (!this->is_infile(file))
		return ;

	if (this->extractValue(file))
		return ;
}
