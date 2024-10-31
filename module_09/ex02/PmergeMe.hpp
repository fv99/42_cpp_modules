#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <sys/time.h>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <limits>

class PmergeMe
{
	private:
		std::vector <int> _numbers;

		void printNumbers(const std::string &head, const std::vector<int> &seq) const;
		double getTime();

		void sortList();
		void sortDeque();

		template <typename T>
		void insertSorted(T &sorted, typename T::value_type val);

		template <typename T>
		void fjSort(T& lst);

	public:
		PmergeMe(const std::vector<int>& numbers);
		void sort();


};
