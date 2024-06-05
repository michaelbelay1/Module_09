/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:50:24 by mhaile            #+#    #+#             */
/*   Updated: 2024/06/05 12:57:11 by mhaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int ac, char **av) {
	RPN rpn;

	if (ac == 2) {
		rpn.calculate(av[1]);
	}
	else {
		std::cout << "Usage: ./rpn \"expression\"" << std::endl;
		return 1;
	}
	
	return 0;
}