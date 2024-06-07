/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:13:03 by mhaile            #+#    #+#             */
/*   Updated: 2024/06/07 16:00:57 by mhaile           ###   ########.fr       */
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
		PmergeMe(int ac, char **av);
		PmergeMe(const PmergeMe &src);
		~PmergeMe();
		PmergeMe & operator=(const PmergeMe &src);

		// bool parse_input(int ac, char **av);
		pair createpair();
		void sort_pair(vec_pair &vec);
		void bitwise_merge();

		bool 	isInt(std::string num);
		int 	ft_stoi(const std::string& str);

		// void addNumber(T num);
		void print(); // print the vector. To be deleted later
		void printPairs(); // print the pairs. To be deleted later.
		// void bitwise_sort(vec_pair &vec);
		void sort(); //Later to make this function the main function to sort the vector.

};

#endif