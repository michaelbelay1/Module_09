/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:52:12 by mhaile            #+#    #+#             */
/*   Updated: 2024/06/05 14:51:02 by mhaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& src) {
	*this = src;
}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& src) {
	if (this != &src)
		_stack = src._stack;
	return *this;
}

int RPN::findOperator(std::string oper, std::string operations[], int size) {
	for (int i = 0; i < size; i++) {
		if (oper == operations[i])
			return i;			
	}
	return -1;
}

// Convert a string to an integer using stringstream.
double RPN::ft_stoi(const std::string& str) {
	double num;
	std::stringstream ss(str);
	if (!(ss >> num)) {
        throw std::invalid_argument("Not a number");
    }
	ss >> num;
	return num;
}

std::string RPN::operand(std::string input) {
	size_t idx = 0;
	if (input.length() == 1 && (input[0] == '+' || input[0] == '-'))
		throw std::invalid_argument("Not a number");
	if (input.length() == 0)
		throw std::invalid_argument("Not a number");
	if (input[0] == '+' || input[0] == '-')
		idx++;
	for ( ; idx < input.length(); idx++) {
		if (!isdigit(input[idx]))
			throw std::invalid_argument("Not a number");
	}
	
	return input;		
}

void RPN::calculate(std::string input) {
	std::stringstream ss(input);
	std::string operations[] = {"+", "-", "*", "/"};

	try {
		while (ss >> input) {
			int index = findOperator(input, operations, 4);
			if (index != -1) {
				if (_stack.size() < 2)
					throw std::invalid_argument("Not enough operands");
				int a = _stack.top();
				_stack.pop();
				int b = _stack.top();
				_stack.pop();
				
				_stack.push(operations[index] == "+" ? b + a : operations[index] == "-" ? b - a : operations[index] == "*" ? b * a : b / a);
			}
			else 
				_stack.push(ft_stoi(operand(input)));
		}
		if (this->_stack.size() != 1) 	// Check if there are too many operands
            throw std::invalid_argument("too many operands");
		std::cout << _stack.top() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return;
	}
}
