/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:44:29 by mhaile            #+#    #+#             */
/*   Updated: 2024/06/05 18:17:33 by mhaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <cstdio>

class RPN {
	private:
		std::stack<int> _stack; // Stack to store the operands.
		int  		findOperator(std::string oper, std::string operations[], int size); // Find operator and return its index.
		double 		ft_stoi(const std::string& str); // Convert a string to an integer using stringstream.
		std::string operand(std::string input); // Return the operand from the input string.
		void 		operation(int idx, int a, int b); // Perform the operation on the operands.
		
	public:
		// *** Orthodox Canonical Form ***
		RPN();
		RPN(const RPN& src);
		~RPN();
		RPN& operator=(const RPN& src);
		
		// *** Member functions ***
		void calculate(std::string input); // Calculate the result of the RPN expression.
};

#endif