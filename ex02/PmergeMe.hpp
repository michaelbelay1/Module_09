/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:13:03 by mhaile            #+#    #+#             */
/*   Updated: 2024/06/08 19:34:40 by mhaile           ###   ########.fr       */
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
#include <iomanip>
#include <cstdio> // To be deleted later. Note: remember to delete the print() function in PmergeMe.cpp

class PmergeMe {
	private:
		// typedef std::pair<int, int> pair;
		// typedef std::vector<pair> vec_pair;
		// typedef std::list<pair> list_pair;
		
		std::vector<int> _vec;
		std::list<int> _list;
		std::vector<std::pair<int, int> > _pair;
		std::list<std::pair<int, int> > _list_pair;
		double _time_vec;
		double _time_list;
		int stragler;
		
	public:

		PmergeMe();
		PmergeMe(const PmergeMe &src);
		~PmergeMe();
		PmergeMe & operator=(const PmergeMe &src);


		void merge_sort_vec();
		bool create_pair_vec();
		void sort_pair_vec(std::vector<std::pair<int, int> > &vec);
		void bitwise_merge_vec();

		void merge_sort_list();
		bool create_pair_list();
		void sort_pair_list(std::list<std::pair<int, int> > &vec);
		void bitwise_merge_list();


		void parse_input(int ac, char **av);
		bool isInt(std::string num);
		int  ft_stoi(const std::string& str);
		// double getTime() const;
		// void print(); 		// print the vector.
		// void printPairs(); 	// print the pairs. To be deleted later.

		double getTimeVec() const;
		double getTimeList() const;

		void printVec();
		void printList();
		std::vector<int> getVec() const;
		std::list<int> getList() const;
};

#endif