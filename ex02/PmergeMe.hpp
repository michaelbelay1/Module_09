/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:13:03 by mhaile            #+#    #+#             */
/*   Updated: 2024/06/05 19:53:28 by mhaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

template <typename T>
class PmergeMe {
	private:
		std::vector<T> _vec;
	public:
		PmergeMe() {}
		PmergeMe(const PmergeMe &src) : _vec(src._vec) {}
		~PmergeMe() {}
		PmergeMe & operator=(const PmergeMe &src) {
			if (this != &src) {
				_vec = src._vec;
			}
			return *this;
		}

		void addNumber(T num) {
			_vec.push_back(num);
		}

		void print() {
			for (typename std::vector<T>::iterator it = _vec.begin(); it != _vec.end(); it++) {
				std::cout << *it << " ";
			}
			std::cout << std::endl;
		}

		void sort() {
			std::sort(_vec.begin(), _vec.end());
		}
};

#endif