#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::vector<int> &numbers): _numbers(numbers) {}

void PmergeMe::sort()
{

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
	struct timeval time{}; 
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}


template <typename T>

void PmergeMe::fjSort(T& lst)
{
	size_t n = lst.size();
	if (n <= 1)
		return;


}

