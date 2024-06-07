/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:33:00 by mhaile            #+#    #+#             */
/*   Updated: 2024/06/07 21:01:12 by mhaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac < 2) {
		std::cout << "Usage: ./ex02 [numbers]" << std::endl;
		return 1;
	}
	
	try {
		PmergeMe<int> p;
		
		p.parse_input(ac, av);
		
		std::cout << "Before: ";
		p.print();

		p.merge_sort();

		std::cout << "After: ";
		p.print();

		std::cout << "time: " << std::fixed << std::setprecision(4) << p.getTime() << "ms" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}