#include <iostream>
#include "iter.hpp"

void printElement(int &elem)
{
    std::cout << elem << " ";
}

void printElement(std::string &elem)
{
    std::cout << elem << " ";
}

void increment(int &elem)
{
    elem += 1;
}

void addChar(std::string &elem)
{
    elem += '!';
}

int main()
{
    // Test with an array of integers
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLen = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original int array: ";
    iter(intArray, intLen, printElement);
    std::cout << std::endl;

    iter(intArray, intLen, increment);

    std::cout << "Incremented int array: ";
    iter(intArray, intLen, printElement);
    std::cout << std::endl;

    // Test with an array of strings
    std::string strArray[] = {"hello", "world", "!"};
    size_t strLen = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "Original string array: ";
    iter(strArray, strLen, printElement);
    std::cout << std::endl;

    iter(strArray, strLen, addChar);

    std::cout << "Modified string array: ";
    iter(strArray, strLen, printElement);
    std::cout << std::endl;

    return 0;
}
