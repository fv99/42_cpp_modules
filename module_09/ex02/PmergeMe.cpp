#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::vector<int> &numbers): _numbers(numbers) {}

void PmergeMe::sort()
{
	printNumbers("Before: ", _numbers);
	sortList();
	sortDeque();
}

void PmergeMe::printNumbers(const std::string &head, const std::vector<int> &seq) const
{
	std::cout << head << " ";

	for (size_t i = 0; i < seq.size(); i++)
		std::cout << seq[i] << " ";
	std::cout << std::endl;
}

double PmergeMe::getTime()
{
	struct timeval time_; 
	gettimeofday(&time_, NULL);
	return (time_.tv_sec * 1000000 + time_.tv_usec);
}

void PmergeMe::sortList()
{
	std::list<int> lst(_numbers.begin(), _numbers.end());
	
	double start = getTime();

	fjSort(lst);

	double end = getTime();

	std::vector<int> sorted(lst.begin(), lst.end());
	printNumbers("After: ", sorted);
	std::cout << "Time to process a range of " << _numbers.size() << " elements with std::list :" << std::fixed << std::setprecision(5) << end - start << " us" << std::endl;
}

void PmergeMe::sortDeque()
{
	std::deque<int> deq(_numbers.begin(), _numbers.end());

	double start = getTime();

	fjSort(deq);

	double end = getTime();

	std::vector<int> sorted(deq.begin(), deq.end());
	printNumbers("After: ", sorted);
	std::cout << "Time to process a range of " << _numbers.size() << " elements with std::deque :" << std::fixed << std::setprecision(5) << end - start << " us" << std::endl;
}

template <typename T>
void PmergeMe::insertSorted(T &sorted, typename T::value_type val)
{
	typename T::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), val);
	sorted.insert(pos, val);
}

template <typename T>

// see https://github.com/PunkChameleon/ford-johnson-merge-insertion-sort
// for a good explanation
void PmergeMe::fjSort(T& lst)
{
	size_t n = lst.size();
	if (n <= 1)
		return;

	// pairing and initial sort
	T pairs;
	typename T::iterator it = lst.begin();
	typename T::value_type straggler;
	bool hasStraggler = false;

	while (it != lst.end())
	{
		typename T::value_type first = *it;
		++it;
		if (it != lst.end())
		{
			typename T::value_type second = *it;
			++it;
			if (first > second)
				std::swap(first, second);
			pairs.push_back(first);
			pairs.push_back(second);
		}
		else
		{
			// unpaired element (odd no. of elements)
			straggler = first;
			hasStraggler = true;
		}
	}

	// creating list S of first elements
	T S;
	it = pairs.begin();
	while (it != pairs.end())
	{
		S.push_back(*it);
		++it;
		if (it != pairs.end())
			++it;
	}
	
	// recursively sort S
	fjSort(S);

	// insert straggler into sorted list
	if (hasStraggler)
		insertSorted(S, straggler);
	
	// insert the second elements into S
	it = pairs.begin();
	++it;
	while (it != pairs.end())
	{
		typename T::value_type val = *it;
		insertSorted(S, val);
		++it;
		if (it != pairs.end())
			++it;
	}
	lst = S;
}

