/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:33:00 by mhaile            #+#    #+#             */
/*   Updated: 2024/06/07 16:01:15 by mhaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av) {
	try {
		PmergeMe<int> p(ac, av);
		
		if (ac < 2) {
			std::cout << "Usage: ./ex02 [numbers]" << std::endl;
			return 1;
		}
		
		// printf("Before sorting: ");
		// p.print();
		// std::cout << std::endl;
		p.createpair();
		// printf("After sorting: ");
		// std::cout << std::endl;
		p.print();


	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}