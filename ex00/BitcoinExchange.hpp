/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:36:56 by mhaile            #+#    #+#             */
/*   Updated: 2024/06/01 16:24:56 by mhaile           ###   ########.fr       */
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
#include <sstream>

class BitcoinExchange {
	private:
		std::map<std::string, std::string> _data;

		
		void printData();       				// Function to print map data. To be deleted later.
		bool is_infile(std::ifstream& file); 	// Parse input file and check if it is empty.
		bool isDigit(std::string str); 			// Check if a string is a digit.
		int  parseData(std::ifstream& file);	// Parse data inside the input file.
		int  parseValue(std::string value); 	// Parse value from the input file.
		std::string ft_trim(std::string str); 	// Trim whitespace from a string.
		bool isLeapYear(int dayInt, int monthInt, int yearInt); // Check if a year is a leap year.
		std::string previousDay(std::string& date); 			// Get the previous day from a given date.
		std::string ft_toStr(int num);			// Convert an integer to a string.
		double ft_stoi(const std::string& str); // Convert a string to an integer.

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& src);
		~BitcoinExchange();
		
		void exec(std::string input); 			// Main function to execute the program.
		// *** Exception classes *** //
		class fileNotFoundException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: File not found";
				}
		};
};

#endif