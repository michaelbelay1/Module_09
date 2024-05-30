/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:46:48 by mhaile            #+#    #+#             */
/*   Updated: 2024/05/30 20:42:41 by mhaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "cstdio"

int main(int ac, char **av) {
	if (ac == 2) {
		BitcoinExchange exchange;
		std::ifstream 	file(av[1]);
		
		exchange.exec(av[1]);
		// exchange.printData();
		
	}
	else
		std::cout << "Usage: ./bit infile.txt" << std::endl;
		
	return 0;
}