/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:13:03 by mhaile            #+#    #+#             */
/*   Updated: 2024/06/09 18:21:59 by mhaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// *** Merge-insert sort (Ford–Johnson algorithm) *** //

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

class PmergeMe {
	private:
		std::vector<int> _vec; // Vector container
		std::list<int> _list; // List container
		std::vector<std::pair<int, int> > _pair; // Pair container for vector
		std::list<std::pair<int, int> > _list_pair; // Pair container for list
		double _time_vec; // Time taken to process vector container in ms
		double _time_list; // Time taken to process list container in ms
		int isOdd; // If odd, the last element is stored here for later use in bitwise merge.
		
	public:
		// *** Canonical Orthodox Form *** //
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		~PmergeMe();
		PmergeMe & operator=(const PmergeMe &src);

		// *** Getters *** //
		std::vector<int> getVec() const;
		std::list<int> getList() const;
		double getTimeVec() const;
		double getTimeList() const;
		
		// *** Member Functions *** //
		void parse_input(int ac, char **av); // Parse input from command line
		bool isInt(std::string num); // Check if input is an integer
		int  ft_stoi(const std::string& str); // Convert string to integer using std::stringstream
		void printVec(); // Print vector container
		void printList(); // Print list container

		// *** Merge-insert sort (Ford–Johnson algorithm) *** //
	
		// -- Using vector container -- //
		void merge_sort_vec();
		bool create_pair_vec();
		void sort_pair_vec(std::vector<std::pair<int, int> > &vec);
		void bitwise_merge_vec();

		// -- Using list container -- //
		void merge_sort_list();
		bool create_pair_list();
		void sort_pair_list(std::list<std::pair<int, int> > &vec);
		void bitwise_merge_list();
};

#endif