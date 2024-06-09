 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaile <mhaile@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:31:04 by mhaile            #+#    #+#             */
/*   Updated: 2024/06/08 20:03:59 by mhaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Default constructor
PmergeMe::PmergeMe() { }

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe &src) : _vec(src._vec) {
	*this = src;
}

// Destructor
PmergeMe::~PmergeMe() {}

// Assignment operator
PmergeMe & PmergeMe::operator=(const PmergeMe &src) {
	if (this != &src) {
		_vec = src._vec;
        _list = src._list;
		_pair = src._pair;
        _list_pair = src._list_pair;
        _time_vec = src._time_vec;
        _time_list = src._time_list;    
		isOdd = src.isOdd;
	}
	return *this;
}

// Getters
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

/**
 * @brief Parses and validates input arguments.
 * Adds valid integers from command line to vector and list containers.
 * 
 * @param ac Argument count.
 * @param av Argument values.
 * @throws std::invalid_argument if any argument is invalid.
 */
void PmergeMe::parse_input(int ac, char **av) {
	// Loop through the arguments and check if they are valid numbers.
	for (int i = 1; i < ac ; i++) {
		if (!isInt(av[i]))
			throw std::invalid_argument("Error: Invalid input");
		
		// Convert string to integer and add to vector and list containers.
		_vec.push_back(ft_stoi(av[i]));
        _list.push_back(ft_stoi(av[i]));
	}
}

/**
 * @brief Check if a string is a valid integer.
 * 
 * @param num The string to check.
 * @return true if the string is a valid integer.
 * @return false if the string is not a valid integer.
*/
bool PmergeMe::isInt(std::string num) {
	if (num.empty() || num[0] == '-')
        return false;

    size_t i = 0;

    if (num[0] == '+' && num.length() == 1)
        return false;
	else if (num[0] == '+')
        i++;

    for (; i < num.length(); i++) {
        if (!std::isdigit(num[i]))
            return false;
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

/**
 * @brief Print the vector container.
*/
void PmergeMe::printVec() {
    for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Print the list container.
*/
void PmergeMe::printList() {
    for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Create pairs of integers from the vector container.
 * 
 * @return true if the vector has more than one element.
 * @return false if the vector has only one element.
*/
bool PmergeMe::create_pair_vec() {
	std::pair<int, int> p;

	// If the vector has only one element, return false.
	if (_vec.size() == 1) {
		p.first = _vec[0];
		_pair.push_back(p);
		return false;
	}

	// If the vector has an odd number of elements, store the last element in isOdd.
	if (_vec.size() % 2 != 0){
		isOdd = _vec.back();
		_vec.pop_back();
	}
	else
		isOdd = -1;

	// Create pairs of integers from the vector and store in _pair.
	// Sort the pair based on the first element.
	for (size_t i = 0; i < _vec.size(); i += 2) {
		if (_vec[i] > _vec[i + 1])
			std::swap(_vec[i], _vec[i + 1]);

		p.first = _vec[i];
		p.second = _vec[i + 1];
		_pair.push_back(p); // Create a pair and add to the _pair.
	}

	return true;
}


/**
 * @brief Create pairs of integers from the list container.
 * 
 * @return true if the list has more than one element.
 * @return false if the list has only one element.
*/
bool PmergeMe::create_pair_list() {
	std::pair<int, int> p;

	// If the list has only one element, return false.
	if (_list.size() == 1) {
        p.first = _list.front();
        _list_pair.push_back(p);
        return false;
    }

	// If the list has an odd number of elements, store the last element in isOdd.
    if (_list.size() % 2 != 0) {
        isOdd = _list.back();
        _list.pop_back();
    }
    else
        isOdd = -1;

	// Create pairs of integers from the list and store in _list_pair.
	// Sort the pair based on the first element.
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
        _list_pair.push_back(std::make_pair(first, second)); // Create a pair and add to the _list_pair.
    }

	return true;
}

/**
 * @brief Merge the pairs of integers in the vector container.
 * 
 * The pairs are merged by sorting the second element of each pair using lower_bound().
 * The pairs are then merged into a single vector.
 * If isOdd is not -1, the last element is inserted into the vector.
 * E.g if the vector is {1, 3, 2, 4, 5}, the pairs are {(1, 3), (2, 4)}.
 * The pairs are merged to {1, 2, 3, 4, 5}.
*/
void PmergeMe::bitwise_merge_vec() {
	std::vector<int> S; // Sorted vector
	std::vector<int> pend; // Pending vector


	for (size_t i = 0; i < _pair.size(); i++) {
		pend.push_back(_pair[i].first); // Add the first element of the pair to the pending vector.
		S.push_back(_pair[i].second); // Add the second element of the pair to the sorted vector.
	}
	
	// Using binary search to insert the elements in the pending vector into the sorted vector(S).
	while (!pend.empty()) {
		std::vector<int>::iterator it = std::lower_bound(S.begin(), S.end(), pend.front());
		S.insert(it, pend.front());
		pend.erase(pend.begin());
	}

	// If isOdd is not -1, insert it into the sorted vector.
	if (isOdd != -1) {
		std::vector<int>::iterator it = std::lower_bound(S.begin(), S.end(), isOdd);
		S.insert(it, isOdd);
	}
	
	// Copy the sorted vector to the original vector.
	_vec.clear();
	for (std::vector<int>::iterator it = S.begin(); it != S.end(); it++) {
		_vec.push_back(*it);
	}
}


/**
 * @brief Merge the pairs of integers in the list container.
 * 
 * The pairs are merged by sorting the second element of each pair using lower_bound().
 * The pairs are then merged into a single list.
 * If isOdd is not -1, the last element is inserted into the list.
 * E.g if the list is {1, 3, 2, 4, 5}, the pairs are {(1, 3), (2, 4)}.
 * The pairs are merged to {1, 2, 3, 4, 5}.
 * 
 * Similar to bitwise_merge_vec() but using list container.
*/
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
	if (isOdd != -1) {
		std::list<int>::iterator it = std::lower_bound(S.begin(), S.end(), isOdd);
		S.insert(it, isOdd);
	}
	
	_list.clear();
	for (std::list<int>::iterator it = S.begin(); it != S.end(); it++) {
		_list.push_back(*it);
	}
}

/**
 * @brief Sort the pairs of integers in the vector container.
 * 
 * The pairs are sorted based on the second element of each pair.
 * The pairs are then merged into a single vector.
 * E.g if the vector is {1, 3, 2, 4, 5}, the pairs are {(1, 3), (2, 4)}.
 * The pairs are sorted to {(1, 3), (2, 4)}.
*/
void PmergeMe::sort_pair_vec(std::vector<std::pair<int, int> > &vec) {
	// If the vector has only one element, return.
	if (vec.size() == 1)
		return;
	size_t mid = vec.size() / 2; // Get the middle index of the vector.

	// Create two vectors from the original vector.
	std::vector<std::pair<int, int> > left(vec.begin(), vec.begin() + mid); // First half of the vector.
	std::vector<std::pair<int, int> > right(vec.begin() + mid, vec.end()); // Second half of the vector.

	// Recursively sort the two vectors. 
	sort_pair_vec(left);
	sort_pair_vec(right);

	// Merge two vectors into a one vector pair based on the second element.
	size_t i = 0, j = 0, k = 0;
	while (i < left.size() && j < right.size()) {
		if (left[i].second <= right[j].second) {
			vec[k++] = left[i++];
		}
		else {
			vec[k++] = right[j++];
		}
	}
	// Add the remaining elements to the vector.
	while (i < left.size()) {
		vec[k++] = left[i++];
	}
	while (j < right.size()) {
		vec[k++] = right[j++];
	}
}

/**
 * @brief Sort the pairs of integers in the list container.
 * 
 * The pairs are sorted based on the second element of each pair.
 * The pairs are then merged into a single list.
 * E.g if the list is {1, 3, 2, 4, 5}, the pairs are {(1, 3), (2, 4)}.
 * The pairs are sorted to {(1, 3), (2, 4)}.
 * 
 * Similar to sort_pair_vec() but using list container.
*/
void PmergeMe::sort_pair_list(std::list<std::pair<int, int> > &list) {
    if (list.size() == 1)
        return;
    size_t mid = list.size() / 2;

    std::list<std::pair<int, int> > left;
    std::list<std::pair<int, int> > right;

    // Copy the first half of the list to the left list.
    for (size_t i = 0; i < mid; i++) {
        left.push_back(*list.begin());
        // list.pop_front();
    }
    // Copy the second half of the list to the right list.
    for (size_t i = 0; i < mid; i++) {
        right.push_back(*list.begin());
        // list.pop_front();
    }

    sort_pair_list(left);
    sort_pair_list(right);

    std::list<std::pair<int, int> >::iterator it = list.begin();
    std::list<std::pair<int, int> >::iterator it_left = left.begin();
	std::list<std::pair<int, int> >::iterator it_right = right.begin();

	// Merge the two lists into one list based on the second element.
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

/**
 * @brief Sort the vector container using merge-insert sort.
 * 
 * The vector is sorted by creating pairs of integers and sorting them based on the second element.
 * The pairs are then merged into a single vector.
 * If the vector has an odd number of elements, the last element is stored in isOdd.
 * The pairs are then merged into a single vector.
 * 
 * The time taken to process the vector is stored in _time_vec.
*/
void PmergeMe::merge_sort_vec() {

	clock_t start = clock();
	
	// Create pairs of integers from the vector.
	if (!create_pair_vec()) {
		_time_vec = (static_cast<double>(clock() - start) / (CLOCKS_PER_SEC)) * 1000;
		return;
	}
	
	sort_pair_vec(_pair); // Sort the pairs based on the second element.
	bitwise_merge_vec(); // Merge the pairs into a single vector arranging them in ascending order.

	_time_vec = (static_cast<double>(clock() - start) / (CLOCKS_PER_SEC)) * 1000; // Calculate the time taken to process the vector in ms.
}

/**
 * @brief Sort the list container using merge-insert sort.
 * 
 * The list is sorted by creating pairs of integers and sorting them based on the second element.
 * The pairs are then merged into a single list.
 * If the list has an odd number of elements, the last element is stored in isOdd.
 * The pairs are then merged into a single list.
 * 
 * The time taken to process the list is stored in _time_list.
*/
void PmergeMe::merge_sort_list() {

	clock_t start = clock();
	
	// Create pairs of integers from the list.
	if (!create_pair_list()) {
		_time_list = (static_cast<double>(clock() - start) / (CLOCKS_PER_SEC)) * 1000;
		return;
	}
	
	sort_pair_list(_list_pair); // Sort the pairs based on the second element.
	bitwise_merge_list(); // Merge the pairs into a single list arranging them in ascending order.

	_time_list = (static_cast<double>(clock() - start) / (CLOCKS_PER_SEC)) * 1000; // Calculate the time taken to process the list in ms.
}
