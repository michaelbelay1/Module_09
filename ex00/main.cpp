/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:46:48 by mhaile            #+#    #+#             */
/*   Updated: 2024/06/12 14:19:23 by mhaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "cstdio"

int main(int ac, char **av) {
	if (ac == 2) {
		try {
			BitcoinExchange exchange;
			
			exchange.exec(av[1]);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	else
		std::cout << "Usage: ./bit infile.csv" << std::endl;
		
	return 0;
}