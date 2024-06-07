/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:13:03 by mhaile            #+#    #+#             */
/*   Updated: 2024/06/07 18:33:59 by mhaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>
#include <utility>
#include <sstream>
#include <climits>
#include <cstdio> // To be deleted later. Note: remember to delete the print() function in PmergeMe.cpp

template <typename T>
class PmergeMe {
	private:
		std::vector<T> _vec;

		typedef typename std::pair<T, T> pair;
		typedef typename std::vector<pair> vec_pair;
		vec_pair _pair;
		int stragler;
		
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		~PmergeMe();
		PmergeMe & operator=(const PmergeMe &src);

		void sort();
		bool createpair();
		void sort_pair(vec_pair &vec);
		void bitwise_merge();


		void parse_input(int ac, char **av);
		bool isInt(std::string num);
		int  ft_stoi(const std::string& str);
		void print(); 		// print the vector.
		void printPairs(); 	// print the pairs. To be deleted later.
};

#endif