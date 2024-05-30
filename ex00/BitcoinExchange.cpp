/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:59:10 by mhaile            #+#    #+#             */
/*   Updated: 2024/05/30 20:43:02 by mhaile           ###   ########.fr       */
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

int BitcoinExchange::is_infile(std::string input) {
	std::ifstream file(input);
	std::string line;

	if (file.is_open())
		return (file.close(), 1);
	else
		return 0;
}

void BitcoinExchange::exec(std::string input) {
	std::ifstream file(input);
	std::string line;

	if (!this->is_infile(input)) {
		std::cout << "File not found" << std::endl;
		return ;
	}
	printf("File found\n");
	// if (file.is_open()) {
	// 	std::getline(file, line);
	// 	while(std::getline(file, line)) {
	// 		std::string key = line.substr(0, line.find(","));
	// 		std::string value = line.substr(line.find(",") + 1, line.length());
	// 		if (_data.find(key) != _data.end())
	// 			std::cout << key << " is in the file" << std::endl;
	// 		else
	// 			std::cout << key << " is not in the file" << std::endl;
	// 	}
	// 	file.close();
	// }
	// else
	// 	std::cout << "Unable to open file" << std::endl;
}
