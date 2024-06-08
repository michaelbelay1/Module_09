/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:31:04 by mhaile            #+#    #+#             */
/*   Updated: 2024/06/08 19:36:23 by mhaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe &src) : _vec(src._vec) {
	*this = src;
}

PmergeMe::~PmergeMe() {}

PmergeMe & PmergeMe::operator=(const PmergeMe &src) {
	if (this != &src) {
		_vec = src._vec;
        _list = src._list;
		_pair = src._pair;
        _list_pair = src._list_pair;
        _time_vec = src._time_vec;
        _time_list = src._time_list;    
		stragler = src.stragler;
	}
	return *this;
}

// double PmergeMe::getTime() const {
// 	return this->_time;
// }

double PmergeMe::getTimeVec() const {
    return this->_time_vec;
}

double PmergeMe::getTimeList() const {
    return this->_time_list;
}

std::vector<int> PmergeMe::getVec() const {
    return this->_vec;
}

std::list<int> PmergeMe::getList() const {
    return this->_list;
}

void PmergeMe::parse_input(int ac, char **av) {
	for (int i = 1; i < ac ; i++) {
		if (!isInt(av[i]))
			throw std::invalid_argument("Error: Invalid input");
		
		// std::vector<int>::iterator it = std::find(_vec.begin(), _vec.end(), ft_stoi(av[i]));
		// if (it != _vec.end())
		// 	throw std::invalid_argument("Error: Duplicate number");
		
		_vec.push_back(ft_stoi(av[i]));
        _list.push_back(ft_stoi(av[i]));
	}

}

bool PmergeMe::isInt(std::string num) {
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
int PmergeMe::ft_stoi(const std::string& str) {
    double num;
    std::stringstream ss(str);

    // Attempt to extract a double from the stringstream.
    if (!(ss >> num) || num > INT_MAX) {
        throw std::invalid_argument("Error: Not a number");
    }
	
    // Return the converted intger number.
	return (static_cast<int>(num));
}

void PmergeMe::printVec() {
    for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printList() {
    for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


bool PmergeMe::create_pair_vec() {
	std::pair<int, int> p;

	if (_vec.size() == 1) {
		p.first = _vec[0];
		// p.second = -1;
		_pair.push_back(p);
		return false;
	}
	// else

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

	return true;
}

bool PmergeMe::create_pair_list() {
	std::pair<int, int> p;

	if (_list.size() == 1) {
        p.first = _list.front();
        _list_pair.push_back(p);
        return false;
    }

    if (_list.size() % 2 != 0) {
        stragler = _list.back();
        _list.pop_back();  // Remove the last element to make the size even
    }
    else
        stragler = -1;


    std::list<int>::iterator it = _list.begin();
    while (it != _list.end()) {
        int first = *it;
        ++it;
        if (it == _list.end())
            break;
        int second = *it;
        ++it;
        if (first > second)
            std::swap(first, second);
        _list_pair.push_back(std::make_pair(first, second));
    }

	return true;
}

void PmergeMe::bitwise_merge_vec() {
	std::list<int> S;
	std::list<int> pend;

	for (size_t i = 0; i < _pair.size(); i++) {
		pend.push_back(_pair[i].first);
		S.push_back(_pair[i].second);
	}
	S.push_front(pend.front());
	pend.pop_front();
	
	while (!pend.empty()) {
		std::list<int>::iterator it = std::lower_bound(S.begin(), S.end(), pend.front());
		S.insert(it, pend.front());
		pend.pop_front();		
	}
	if (stragler != -1) {
		std::list<int>::iterator it = std::lower_bound(S.begin(), S.end(), stragler);
		S.insert(it, stragler);
	}
	
	_vec.clear();
	for (std::list<int>::iterator it = S.begin(); it != S.end(); it++) {
		_vec.push_back(*it);
	}
}

void PmergeMe::bitwise_merge_list() {
	std::list<int> S;
	std::list<int> pend;

	for (size_t i = 0; i < _pair.size(); i++) {
		pend.push_back(_pair[i].first);
		S.push_back(_pair[i].second);
	}
	S.push_front(pend.front());
	pend.pop_front();
	
	while (!pend.empty()) {
		std::list<int>::iterator it = std::lower_bound(S.begin(), S.end(), pend.front());
		S.insert(it, pend.front());
		pend.pop_front();		
	}
	if (stragler != -1) {
		std::list<int>::iterator it = std::lower_bound(S.begin(), S.end(), stragler);
		S.insert(it, stragler);
	}
	
	_vec.clear();
	for (std::list<int>::iterator it = S.begin(); it != S.end(); it++) {
		_vec.push_back(*it);
	}
}

void PmergeMe::sort_pair_vec(std::vector<std::pair<int, int> > &vec) {
	if (vec.size() == 1)
		return;
	size_t mid = vec.size() / 2;

	std::vector<std::pair<int, int> > left(vec.begin(), vec.begin() + mid);
	std::vector<std::pair<int, int> > right(vec.begin() + mid, vec.end());
	


	sort_pair_vec(left);
	sort_pair_vec(right);

	// Merge the two vectors. by sorting based on thier second element.
	size_t i = 0, j = 0, k = 0;
	while (i < left.size() && j < right.size()) {
		if (left[i].second <= right[j].second) {
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
}


void PmergeMe::sort_pair_list(std::list<std::pair<int, int> > &list) {
    if (list.size() == 1)
        return;
    size_t mid = list.size() / 2;

    std::list<std::pair<int, int> > left;
    std::list<std::pair<int, int> > right;

    // Copy the first half of the list to the left list.
    for (size_t i = 0; i < mid; i++) {
        left.push_back(*list.begin());
        list.pop_front();
    }
    // Copy the second half of the list to the right list.
    for (size_t i = 0; i < mid; i++) {
        right.push_back(*list.begin());
        list.pop_front();
    }

    sort_pair_list(left);
    sort_pair_list(right);

    // Merge the two lists by sorting based on their second element.
    // size_t i = 0, j = 0, k = 0;
    std::list<std::pair<int, int> >::iterator it = list.begin();
    std::list<std::pair<int, int> >::iterator it_left = left.begin(), it_right = right.begin();
    while (it_left != left.end() && it_right != right.end()) {
        if ((*it_left).second <= (*it_right).second) {
            *it++ = *it_left++;
        }
        else {
            *it++ = *it_right++;
        }
    }
    while (it_left != left.end()) {
        *it++ = *it_left++;
    }
    while (it_right != right.end()) {
        *it++ = *it_right++;
    }
}


void PmergeMe::merge_sort_vec() {

	clock_t start = clock();
	
	if (!create_pair_vec()) {
		_time_vec = static_cast<double>(clock() - start) / (CLOCKS_PER_SEC);
		return;
	}
	
	sort_pair_vec(_pair);
	
	bitwise_merge_vec();

	_time_vec = static_cast<double>(clock() - start) / (CLOCKS_PER_SEC);
}

void PmergeMe::merge_sort_list() {

	clock_t start = clock();
	
	if (!create_pair_list()) {
		_time_list = static_cast<double>(clock() - start) / (CLOCKS_PER_SEC);
		return;
	}
	
	sort_pair_list(_list_pair);
	
	bitwise_merge_list();

	_time_list = static_cast<double>(clock() - start) / (CLOCKS_PER_SEC);
}
