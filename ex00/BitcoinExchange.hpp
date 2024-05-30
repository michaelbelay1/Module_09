/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:36:56 by mhaile            #+#    #+#             */
/*   Updated: 2024/05/30 20:42:44 by mhaile           ###   ########.fr       */
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
		void exec(std::string input); 
		int is_infile(std::string input);

		// class fileNotFoundException : public std::exception {
		// 	public:
		// 		virtual const char* what() const throw() {
		// 			return "File not found";
		// 		}
		// };
};

#endif