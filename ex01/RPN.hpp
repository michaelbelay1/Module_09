/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:44:29 by mhaile            #+#    #+#             */
/*   Updated: 2024/06/05 14:51:22 by mhaile           ###   ########.fr       */
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
		std::stack<int> _stack;
		int  	findOperator(std::string oper, std::string operations[], int size);
		double 	ft_stoi(const std::string& str);
		std::string operand(std::string input);
	public:
		RPN();
		RPN(const RPN& src);
		~RPN();
		RPN& operator=(const RPN& src);
		
		void calculate(std::string input);
};

#endif