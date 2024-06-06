/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:31:04 by mhaile            #+#    #+#             */
/*   Updated: 2024/06/06 22:48:59 by mhaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
PmergeMe<T>::PmergeMe(int ac, char** str) {
	for (int i = 1; i < ac ; i++) {
		if (!isInt(str[i]))
			throw std::invalid_argument("Error: Invalid input");
		_vec.push_back(ft_stoi(str[i]));
	}

}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe &src) : _vec(src._vec) {
	*this = src;
}

template <typename T>
PmergeMe<T>::~PmergeMe() {}

template <typename T>
PmergeMe<T> & PmergeMe<T>::operator=(const PmergeMe &src) {
	if (this != &src) {
		_vec = src._vec;
	}
	return *this;
}

// template <typename T>
// void PmergeMe<T>::addNumber(T num) {
// 	_vec.push_back(num);
// }

template <typename T>
void PmergeMe<T>::print() {
	for (typename std::vector<T>::iterator it = _vec.begin(); it != _vec.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void PmergeMe<T>::sort() {
	std::sort(_vec.begin(), _vec.end());
}

template <typename T>
typename PmergeMe<T>::pair PmergeMe<T>::createpair() {
	pair p;

	if (_vec.size() % 2 != 0){
		stragler = _vec.back();
		_vec.pop_back();
	}
	else
		stragler = -1;

	for (size_t i = 0; i < _vec.size(); i += 2) {
		// swap is first element is greater than the second.
		if (_vec[i] > _vec[i + 1])
			std::swap(_vec[i], _vec[i + 1]);

		p.first = _vec[i];
		p.second = _vec[i + 1];
		_pair.push_back(p);
	}

	sort_pair(_pair);
	// printPairs();
	_vec.clear();
	for (size_t i = 0; i < _pair.size(); i++) {
		_vec.push_back(_pair[i].first);
		_vec.push_back(_pair[i].second);
	}
	if (stragler != -1)
		_vec.push_back(stragler);

	// printPairs();
	
	// printf("Stragler: %d\n", stragler);
	return p;
}

template <typename T>
void PmergeMe<T>::sort_pair(vec_pair &vec) {
	(void)vec;
	if (vec.size() == 1)
		return;
	size_t mid = vec.size() / 2;
	printf("Mid: %zu\n", mid);

	vec_pair left(vec.begin(), vec.begin() + mid);
	vec_pair right(vec.begin() + mid, vec.end());
	


	sort_pair(left);
	sort_pair(right);

	// Merge the two vectors.

    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            vec[k++] = left[i++];
        }
		else {
            vec[k++] = right[j++];
        }
    }
    while (i < left.size()) {
        vec[k++] = left[i++];
    }
    while (j < right.size()) {
        vec[k++] = right[j++];
    }

	
	// Print left and right vectors. To be deleted later.//
	// for (size_t i = 0; i < left.size(); i++) {
	// 	printf("Left: %d %d\n", left[i].first, left[i].second);
	// }
	// for (size_t i = 0; i < right.size(); i++) {
	// 	printf("Right: %d %d\n", right[i].first, right[i].second);
	// }
	// printf("\n");
	//////////////////////////////////////////////////////
}

// template <typename T>
// void PmergeMe<T>::bitwise_sort(vec_pair &vec) {
	
// }

template <typename T>
bool PmergeMe<T>::isInt(std::string num) {
	if (num.empty() || num[0] == '-') {
        return false;
    }

    size_t i = 0;

    if (num[0] == '+' && num.length() == 1) {
        return false;
    }
	else if (num[0] == '+') {
        i++;
    }

    for (; i < num.length(); i++) {
        if (!std::isdigit(num[i])) {
            return false;
        }
    }

    return true;
}

// Convert a string to a double using stringstream.
// @param str: The string to convert.
// @return: The double value.
// @throws std::invalid_argument: If the input is not a valid number.
template <typename T>
int PmergeMe<T>::ft_stoi(const std::string& str) {
    double num;
    std::stringstream ss(str);

    // Attempt to extract a double from the stringstream.
    if (!(ss >> num) || num > INT_MAX) {
        throw std::invalid_argument("Error: Not a number");
    }
	
    // Return the converted intger number.
	return (static_cast<int>(num));
}

template <typename T>
void PmergeMe<T>::printPairs() {
	for (typename std::vector<pair>::iterator it = _pair.begin(); it != _pair.end(); it++) {
		std::cout << it->first << " " << it->second << std::endl;
	}
}

// template class PmergeMe<double>;
template class PmergeMe<int>;