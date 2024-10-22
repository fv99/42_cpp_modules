#include <iostream>
#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: "  << sp.longestSpan()  << std::endl;

        // Test with 100,000 numbers
        Span largeSpan(100000);
        largeSpan.addRandomNumbers(100000);

        std::cout << "Large Span Shortest: " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Large Span Longest: "  << largeSpan.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
