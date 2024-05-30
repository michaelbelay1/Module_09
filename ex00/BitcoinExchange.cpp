/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:59:10 by mhaile            #+#    #+#             */
/*   Updated: 2024/05/30 21:28:29 by mhaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() {
	std::ifstream file("data.csv");
	std::string line;

	if (file.is_open()) {
		std::getline(file, line);
		while(std::getline(file, line)) {
			std::string key = line.substr(0, line.find(","));
			std::string value = line.substr(line.find(",") + 1, line.length());
			_data[key] = value;
		}
		file.close();
	}
	else
		std::cout << "Unable to open file" << std::endl;
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
			std::cout << "File is empty" << std::endl;
			return false;
		}
	}
	else {
		std::cout << "File not found" << std::endl;
		return false;
	}
	return true;
}

int BitcoinExchange::parseData(std::ifstream& file) {
	std::string line;

	std::getline(file, line);
	printf("line: %s\n", line.c_str());
	if (line != "date | value") {
		std::cout << "Invalid file format" << std::endl;
		return 1;
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
	
	printf("File found and has something inside\n");
}
