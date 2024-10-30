#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: No input provided" << std::endl;
        return 1;
	}

	std::vector <int> numbers;
	for (int i = 0; i < argc; ++i)
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


}