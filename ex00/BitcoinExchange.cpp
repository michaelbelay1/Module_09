/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:59:10 by mhaile            #+#    #+#             */
/*   Updated: 2024/06/04 16:24:13 by mhaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() {
	std::ifstream file("data.csv");
	std::string line;
	
	if (file.is_open()) {
		if (file.peek() == EOF)
			throw invalidDBException();
	}
	if (file.is_open()) {
		std::getline(file, line);
		if (line.length() != 18 || line != "date,exchange_rate")
			throw invalidDBException();
		while(std::getline(file, line)) {
			std::string key = line.substr(0, line.find(","));
			std::string value = line.substr(line.find(",") + 1, line.length());
			_data[key] = value;
		}
		file.close();
	}
	else
		throw fileNotFoundException();
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

bool BitcoinExchange::is_infile(std::ifstream& file) {
	if (file.is_open()) {
		if (file.peek() == EOF) {
			std::cout << "input file is empty" << std::endl;
			return false;
		}
	}
	else {
		std::cout << "File not found" << std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::isDigit(std::string str) {
	for(int i = 0; i < (int)str.length(); i++) {
		if (!isdigit(str[i])) {
			std::cout << "Error: Nondigit character found on Date" << std::endl;
			return false;
		}
	}
	return true;
}

bool BitcoinExchange::isLeapYear(int dayInt, int monthInt, int yearInt) {
	if (monthInt == 2) {
		if ((yearInt % 4 == 0 && yearInt % 100 != 0) || (yearInt % 400 == 0)) {
			if (dayInt > 29) {
				// std::cout << "Invalid date" << std::endl;
				return false;
			}
		}
		else {
			if (dayInt > 28) {
				// std::cout << "Invalid date" << std::endl;
				return false;
			}
		}
	}
	return true;
}

int BitcoinExchange::parseValue(std::string value) {
	if (value.empty()) {
		std::cout << "Error: Value is empty" << std::endl;
		return 1;
	}
	char *endptr;
	double val = std::strtod(value.c_str(), &endptr);
	if (*endptr != '\0') {
		std::cout << "Error: Invalid value: " << value << std::endl;
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

	// for (int i = 1; i < (int)value.length() - 1; i++) {
	// 	if (!isdigit(value[i]) && value[i] != '.' && value[i] != '-' && value[i] != '+') {
	// 		std::cout << "Error: Nondigit character found on Value" << value[i] << std::endl;
	// 		return 1;
	// 	}
	// }
	return 0;
}

std::string BitcoinExchange::ft_trim(std::string str) {
	size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first)
        return str;

    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

std::string BitcoinExchange::previousDay(std::string& date) {
	int year = ft_stoi(date.substr(0, 4));
	int month = ft_stoi(date.substr(5, 2));
	int day = ft_stoi(date.substr(8, 2));
	
	// daysInMonth = number of days in each month
	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 0 is a placeholder
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) 			// check if year is a leap year
		daysInMonth[2] = 29;
	day--;
	if (day == 0) {
		month--;
		if (month == 0) {
			year--;
			month = 12;
		}
		day = daysInMonth[month];
	}
	std::string newYear = ft_toStr(year) + "-";
	std::string newMonth = (month < 10) ? "0" + ft_toStr(month) + "-": ft_toStr(month) + "-";
	std::string newDay = (month < 10) ? "0" + ft_toStr(day) : ft_toStr(day);
	return newYear + newMonth + newDay;
}

std::string BitcoinExchange::ft_toStr(int num) {
	std::stringstream ss;
	ss << num;
	return ss.str();
}

double BitcoinExchange::ft_stoi(const std::string& str) {
	std::stringstream ss(str);
	double num;
	ss >> num;
	return num;
}

int BitcoinExchange::parseData(std::ifstream& file) {
	std::string line;

	std::getline(file, line);
	for (int i = 0; i < (int)line.length() - 1; i++) {
		if (line[i] != "date | value"[i]) {
			std::cout << "Invalid infile header formate" << std::endl;
			return 1;
		}
	}
	
	while (std::getline(file, line)) {
		size_t pos = line.find('|');
		std::string date = ft_trim(line.substr(0, pos));
		std::string value = ft_trim(line.substr(pos + 1));
		if (value[value.length() - 1] == '\r')
			value = value.substr(0, value.length() - 1);
	
		// std::cout << value << std::endl;
		if (date.length() != 10) {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		if (date[4] != '-' || date[7] != '-') {
			std::cout << "Error: bad input => " << date << std::endl;
        	continue;
		}

		std::string year = date.substr(0, 4);
		std::string month = date.substr(5, 2);
		std::string day = date.substr(8, 2);

		if (!isDigit(year) || !isDigit(month) || !isDigit(day))
			continue;

		if (parseValue(value))
			continue;

		int yearInt, monthInt, dayInt;
	
		std::stringstream ssYear(year);
		std::stringstream ssMonth(month);
		std::stringstream ssDay(day);

		ssYear >> yearInt;
		ssMonth >> monthInt;
		ssDay >> dayInt;

		if ((yearInt < 2009 || yearInt > 2022)
			|| (monthInt < 1 || monthInt > 12)
			|| (dayInt < 1 || dayInt > 31)) {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		if (yearInt == 2009) {
			if (monthInt == 1) {
				if (dayInt < 2) {
					std::cout << "Error: bad input => " << date << std::endl;
					continue;
				}
			}
		}

		if ((monthInt == 4 || monthInt == 6 || monthInt == 9
			|| monthInt == 11) && dayInt > 30) {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		if (!isLeapYear(dayInt, monthInt, yearInt)) {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		std::map<std::string, std::string>::iterator it;
		std::string prevDate = date;
		it = _data.find(date);
		while (it == _data.end()) {
			std::string& currentDate = prevDate;
			prevDate = previousDay(currentDate);
			if (prevDate == "2009-01-01") {
				std::cout << "Error: No data found for " << date << std::endl;
				break;
			}
			it = _data.find(prevDate);
		}
		std::cout << date << " => " << value << " = " << ft_stoi(it->second) * ft_stoi(value) << std::endl;
	}
	return 0;
}

void BitcoinExchange::exec(std::string input) {
	std::ifstream file(input.c_str());
	std::string line;
	if (!this->is_infile(file))
		return ;

	if (this->parseData(file))
		return ;
	
	// printf("File found and has something inside\n");
}
