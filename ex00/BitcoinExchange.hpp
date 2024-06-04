/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:36:56 by mhaile            #+#    #+#             */
/*   Updated: 2024/06/04 22:36:33 by mhaile           ###   ########.fr       */
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

		
		bool is_infile(std::ifstream& file); 	// Parse input file and check if it is empty.
		bool isDigit(std::string str); 			// Check if a string is a digit.
		int  setDB(std::ifstream& file); 		// Set the database from the input file.
		int  extractValue(std::ifstream& file);	// Parse data inside the input file.
		int  parseDate(std::string date); 		// Parse date from the input file.
		int  parseValue(std::string date); 		// Parse value from the input file.
		std::map<std::string, std::string>::iterator closestDate(std::string date); 	// Find the lower closest date to the input date.
		std::string ft_trim(std::string str); 	// Trim whitespace from a string.
		bool isLeapYear(int dayInt, int monthInt, int yearInt); // Check if a year is a leap year.
		std::string previousDay(std::string& date); 			// Get the previous day from a given date.
		double ft_stoi(const std::string& str); // Convert a string to an integer.

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& src);
		~BitcoinExchange();
		
		void exec(std::string input); 			// Main function to execute the program.
		void printData(); 				// Function to print map data. To be deleted later.
		std::map<std::string, std::string> getData(); // Getter for _data.
		// *** Exception classes *** //
		class fileNotFoundException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: File not found";
				}
		};

		class fileEmptyException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: File is empty";
				}
		};

		class invalidDBException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Error: Invalid DB";
				}
		};
};

#endif