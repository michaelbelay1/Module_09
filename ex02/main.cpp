/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:33:00 by mhaile            #+#    #+#             */
/*   Updated: 2024/06/05 19:53:25 by mhaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av) {
	PmergeMe<int> p;

	if (ac < 2) {
		std::cout << "Usage: ./ex02 [numbers]" << std::endl;
		return 1;
	}
	for (int i = 1; i < ac; i++) {
		char *enptr;
		double num = strtod(av[i], &enptr);
		if (*enptr) {
			std::cout << "Invalid input" << std::endl;
			return 1;
		}
		int num_int = static_cast<int>(num);
		p.addNumber(num_int);
	}

	std::cout << "Before sorting: ";
	p.print();

	p.sort();

	std::cout << "After sorting: ";
	p.print();

	return 0;
}