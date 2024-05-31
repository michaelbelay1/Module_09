/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:36:56 by mhaile            #+#    #+#             */
/*   Updated: 2024/05/31 13:29:06 by mhaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <fstream>
#include <exception>

class BitcoinExchange {
	private:
		std::map<std::string, std::string> _data;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& src);
		~BitcoinExchange();
		
		void printData(); // Function to print map data. To be deleted later.
		bool is_infile(std::ifstream& file); // Parse input file and check if it is empty.
		bool isDigit(std::string str); // Check if a string is a digit.
		int  parseData(std::ifstream& file); // Parse data inside the input file.

		void exec(std::string input); // Main function to execute the program.
		// class fileNotFoundException : public std::exception {
		// 	public:
		// 		virtual const char* what() const throw() {
		// 			return "File not found";
		// 		}
		// };
};

#endif