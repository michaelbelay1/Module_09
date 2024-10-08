/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:33:00 by mhaile            #+#    #+#             */
/*   Updated: 2024/06/12 16:45:24 by mhaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac < 2) {
		std::cout << "Usage: ./ex02 [numbers]" << std::endl;
		return 1;
	}
	
	PmergeMe sorter;
	
	try {
		
		sorter.parse_input(ac, av);

		std::cout << "Before: ";
		sorter.printVec();
		// sorter.printList();

		sorter.merge_sort_vec();
		sorter.merge_sort_list();
		
		std::cout << "After: ";
		sorter.printVec();
		// sorter.printList();
		std::cout << "Time to process a range of " << ac - 1 << " with std::vector : " << std::fixed << std::setprecision(5) << sorter.getTimeVec() << " ms" << std::endl;
		std::cout << "Time to process a range of " << ac - 1 << " with std::list : " << std::fixed << std::setprecision(5) << sorter.getTimeList() << " ms" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}