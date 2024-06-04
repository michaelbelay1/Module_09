/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:46:48 by mhaile            #+#    #+#             */
/*   Updated: 2024/06/04 16:14:06 by mhaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "cstdio"

int main(int ac, char **av) {
	if (ac == 2) {
		try {
			BitcoinExchange exchange;
			
			exchange.exec(av[1]);
			// exchange.printData();
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	else
		std::cout << "Usage: ./bit infile.txt" << std::endl;
		
	return 0;
}