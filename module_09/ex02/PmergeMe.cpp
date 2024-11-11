#include "PmergeMe.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sys/time.h>

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

// generated jacobsthal numbers up to element n
std::vector<size_t> generateJacob(size_t n)
{
    std::vector<size_t> jacob;
    jacob.push_back(0);
    jacob.push_back(1);

    size_t i = 1;
    while (jacob.back() < n)
    {
        size_t next = jacob[i] + 2 * jacob[i - 1];
        jacob.push_back(next);
        ++i;
    }
    return jacob;
}

// getters
template <typename T>
typename T::value_type getElementAt(T& container, size_t index, std::random_access_iterator_tag)
{
    return container[index];
}

template <typename T>
typename T::value_type getElementAt(T& container, size_t index, std::bidirectional_iterator_tag)
{
    typename T::iterator it = container.begin();
    std::advance(it, index);
    return *it;
}

template <typename T>
void jacobInsert(T& sorted, typename T::value_type val)
{
    size_t left = 0;
    size_t right = sorted.size();
    size_t n = right;

    // generate Jacobsthal numbers up to n
    std::vector<size_t> jacob = generateJacob(n);
    size_t i = jacob.size() - 1;

    typedef typename std::iterator_traits<typename T::iterator>::iterator_category Category;

    while (left < right)
    {
        size_t mid;
        if (i > 1)
        {
            mid = left + std::min(jacob[i - 1], right - left - 1);
            --i;
        }
        else
        {
            mid = left;
        }

        typename T::value_type midVal = getElementAt(sorted, mid, Category());

        if (val > midVal)
            left = mid + 1;
        else
            right = mid;
    }

    typename T::iterator insertPos = sorted.begin();
    std::advance(insertPos, left);
    sorted.insert(insertPos, val);
}

template <typename T>

// see https://cljdoc.org/d/decidedlyso/merge-insertion-sort/1.0.2/doc/readme
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
        jacobInsert(S, straggler);

    // make list of second elements
    T seconds;
    it = pairs.begin();
    ++it;
    while (it != pairs.end())
    {
        seconds.push_back(*it);
        ++it;
        if (it != pairs.end())
            ++it;
    }

    // find order of insertion with jacobsthal numbers
    size_t m = seconds.size();
    std::vector<size_t> jacobIndex;
    if (m > 0)
    {
        std::vector<size_t> jacob = generateJacob(m);
        // remove the first two jacobsthal numbers (0, 1)
        if (jacob.size() > 2)
            jacob.erase(jacob.begin(), jacob.begin() + 2);

        // generate the insertion indexes
        for (size_t j = jacob.size(); j > 0; --j)
        {
            size_t index = jacob[j - 1] - 1;
            if (index < m && std::find(jacobIndex.begin(), jacobIndex.end(), index) == jacobIndex.end())
                jacobIndex.push_back(index);
        }
        // add remaining indexes in order
        for (size_t i = 0; i < m; ++i)
        {
            if (std::find(jacobIndex.begin(), jacobIndex.end(), i) == jacobIndex.end())
                jacobIndex.push_back(i);
        }
    }

    // insert the second elements using the jacobsthal order
    typedef typename std::iterator_traits<typename T::iterator>::iterator_category Category;

    for (size_t i = 0; i < jacobIndex.size(); ++i)
    {
        size_t idx = jacobIndex[i];
        typename T::value_type val = getElementAt(seconds, idx, Category());
        jacobInsert(S, val);
    }

    lst = S;
}
