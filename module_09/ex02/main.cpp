#include "PmergeMe.hpp"
#include <sys/time.h>

double getTime()
{
    struct timeval time_;
    gettimeofday(&time_, NULL);
    return (time_.tv_sec * 1000000 + time_.tv_usec);
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: No input provided" << std::endl;
        return 1;
	}

	std::vector <int> numbers;
	for (int i = 1; i < argc; ++i)
	{
		std::string arg(argv[i]);
		for (size_t j = 0; j < arg.size(); ++j)
		{
			if (!std::isdigit(arg[j]))
			{
				std::cerr << "Error: Invalid input, not an integer: " << arg[j] << std::endl;
				return 1;
			}
		}
		long num = std::strtol(arg.c_str(), NULL, 10);
		if (num < 0 || num > std::numeric_limits<int>::max())
		{
			std::cerr << "Error: Integer out of bounds: " << num << std::endl;
			return 1;
		}
		numbers.push_back(static_cast<int>(num));
	}

	PmergeMe sortme(numbers);
	sortme.sort();

	// compare with std::sort
	double start = getTime();
	std::sort(numbers.begin(), numbers.end());
	double end = getTime();

	std::cout << "Time to sort with std::sort: " << end - start << " us" << std::endl;

	return 0;
}