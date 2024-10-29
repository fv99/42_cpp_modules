#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./RPN <expression>" << std::endl;
        return EXIT_FAILURE;
    }

    RPN rpnCalculator;
    int result = rpnCalculator.calculate(argv[1]);
    std::cout << result << std::endl;

    return EXIT_SUCCESS;
}
