/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:52:12 by mhaile            #+#    #+#             */
/*   Updated: 2024/06/05 18:16:35 by mhaile           ###   ########.fr       */
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

// Find the index of an operator in the operations array.
// @param oper: The operator to find.
// @param operations: Array of supported operators.
// @param size: Size of the operations array.
// @return: Index of the operator if found; otherwise, -1.
// Iterates through the operations array and returns the index of the operator if found.
int RPN::findOperator(std::string oper, std::string operations[], int size) {
	for (int i = 0; i < size; i++) {
		if (oper == operations[i])
			return i;			
	}
	return -1;
}

// Convert a string to a double using stringstream.
// @param str: The string to convert.
// @return: The double value.
// @throws std::invalid_argument: If the input is not a valid number.
double RPN::ft_stoi(const std::string& str) {
    double num;
    std::stringstream ss(str);

    // Attempt to extract a double from the stringstream.
    if (!(ss >> num)) {
        throw std::invalid_argument("Error: Not a number");
    }

    // Return the converted number.
    return num;
}


// Validate the input string as a valid integer operand.
// @param input: The operand string.
// @return: The validated operand string.
// @throws std::invalid_argument: If the input is not a valid integer.
std::string RPN::operand(std::string input) {
    size_t idx = 0;

    // Check if the input length is 1 and if it is either '+' or '-'.
    if (input.length() == 1 && (input[0] == '+' || input[0] == '-'))
        throw std::invalid_argument("Error: Not a number");

    // Check if the input length is 0.
    if (input.length() == 0)
        throw std::invalid_argument("Error: Not a number");

    // If the input starts with '+' or '-', skip the first character.
    if (input[0] == '+' || input[0] == '-')
        idx++;

    // Iterate through the remaining characters to check if they are all digits.
    for (; idx < input.length(); idx++) {
        if (!isdigit(input[idx]))
            throw std::invalid_argument("Error: Not a number");
    }

    // Return the validated input string.
    return input;
}


// Perform an operation and push the result onto the stack.
// @param idx: Index of the operation in the operations array.
// @param a: First operand.
// @param b: Second operand.
void RPN::operation(int idx, int a, int b) {
    switch (idx) {
        case 0:
            // Case for addition: push the result of b + a onto the stack.
            _stack.push(b + a);
            break;
        case 1:
            // Case for subtraction: push the result of b - a onto the stack.
            _stack.push(b - a);
            break;
        case 2:
            // Case for multiplication: push the result of b * a onto the stack.
            _stack.push(b * a);
            break;
        case 3:
            // Case for division: push the result of b / a onto the stack.
			if (a == 0)
				throw std::invalid_argument("Error: Division by zero");
            _stack.push(b / a);
            break;
    }
}


// Calculate the result of the RPN (Reverse Polish Notation) expression.
// @param input: A string representing the RPN expression to be evaluated.
// The function reads tokens from the input string and uses a stack to evaluate the expression.
void RPN::calculate(std::string input) {
    // Create a stringstream from the input string to facilitate token extraction.
    std::stringstream ss(input);

    // Define the list of supported operations.
    std::string operations[] = {"+", "-", "*", "/"};

    try {
        // Process each token in the input string.
        while (ss >> input) {
            // Check if the token is an operator.
            int index = findOperator(input, operations, 4);
            
            // If the token is an operator.
            if (index != -1) {
                // Ensure there are at least two operands on the stack.
                if (_stack.size() < 2)
                    throw std::invalid_argument("Not enough operands");
                
                // Pop the top two operands from the stack.
                int a = _stack.top();
                _stack.pop();
                int b = _stack.top();
                _stack.pop();
                
                // Perform the operation and push the result back onto the stack.
                operation(index, a, b);
            }
			else
                // If the token is not an operator, treat it as an operand.
                // Convert the token to an integer and push it onto the stack.
                _stack.push(ft_stoi(operand(input)));
        }

        // After processing all tokens, there should be exactly one result on the stack.
        if (this->_stack.size() != 1) 
            throw std::invalid_argument("too many operands");
        
        // Print the result.
        std::cout << _stack.top() << std::endl;
    } catch (std::exception &e) {
        // Catch and print any exceptions that occur during evaluation.
        std::cerr << e.what() << std::endl;
        return;
    }
}
