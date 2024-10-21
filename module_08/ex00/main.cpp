#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <iterator> // For std::distance
#include "easyfind.hpp"

int main()
{
    // Test with std::vector
    std::cout << "--- Testing with std::vector ---" << std::endl;
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i)
        vec.push_back(i * 2); // Fill vector with even numbers from 0 to 18

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 6);
        std::cout << "Found value in vector: " << *it << std::endl;
    }
    catch (const NotFoundException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 7);
        std::cout << "Found value in vector: " << *it << std::endl;
    }
    catch (const NotFoundException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    // Test with std::list
    std::cout << "\n--- Testing with std::list ---" << std::endl;
    std::list<int> lst;
    for (int i = 0; i < 10; ++i)
        lst.push_back(i * 3); // Fill list with multiples of 3 from 0 to 27

    try
    {
        std::list<int>::iterator it = easyfind(lst, 9);
        std::cout << "Found value in list: " << *it << std::endl;
    }
    catch (const NotFoundException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::list<int>::iterator it = easyfind(lst, 10);
        std::cout << "Found value in list: " << *it << std::endl;
    }
    catch (const NotFoundException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    // Test with std::deque
    std::cout << "\n--- Testing with std::deque ---" << std::endl;
    std::deque<int> deq;
    for (int i = 0; i < 10; ++i)
        deq.push_back(i + 5); // Fill deque with numbers from 5 to 14

    try
    {
        std::deque<int>::iterator it = easyfind(deq, 10);
        std::cout << "Found value in deque: " << *it << std::endl;
    }
    catch (const NotFoundException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::deque<int>::iterator it = easyfind(deq, 15);
        std::cout << "Found value in deque: " << *it << std::endl;
    }
    catch (const NotFoundException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    // Test with an empty container
    std::cout << "\n--- Testing with an empty std::vector ---" << std::endl;
    std::vector<int> emptyVec;
    try
    {
        std::vector<int>::iterator it = easyfind(emptyVec, 1);
        std::cout << "Found value in empty vector: " << *it << std::endl;
    }
    catch (const NotFoundException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    // Test with multiple occurrences
    std::cout << "\n--- Testing with multiple occurrences ---" << std::endl;
    std::vector<int> multiVec;
    multiVec.push_back(1);
    multiVec.push_back(2);
    multiVec.push_back(3);
    multiVec.push_back(2);
    multiVec.push_back(1);

    try
    {
        std::vector<int>::iterator it = easyfind(multiVec, 2);
        std::cout << "Found value in vector: " << *it << std::endl;
        std::cout << "First occurrence at position: " << std::distance(multiVec.begin(), it) << std::endl;
    }
    catch (const NotFoundException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    // Test with negative numbers
    std::cout << "\n--- Testing with negative numbers ---" << std::endl;
    std::vector<int> negVec;
    negVec.push_back(-10);
    negVec.push_back(-5);
    negVec.push_back(0);
    negVec.push_back(5);
    negVec.push_back(10);

    try
    {
        std::vector<int>::iterator it = easyfind(negVec, -5);
        std::cout << "Found value in vector: " << *it << std::endl;
    }
    catch (const NotFoundException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::vector<int>::iterator it = easyfind(negVec, -1);
        std::cout << "Found value in vector: " << *it << std::endl;
    }
    catch (const NotFoundException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    // Test with large numbers
    std::cout << "\n--- Testing with large numbers ---" << std::endl;
    std::vector<int> largeVec;
    largeVec.push_back(1000);
    largeVec.push_back(2000);
    largeVec.push_back(3000);
    largeVec.push_back(4000);
    largeVec.push_back(5000);

    try
    {
        std::vector<int>::iterator it = easyfind(largeVec, 3000);
        std::cout << "Found value in vector: " << *it << std::endl;
    }
    catch (const NotFoundException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::vector<int>::iterator it = easyfind(largeVec, 6000);
        std::cout << "Found value in vector: " << *it << std::endl;
    }
    catch (const NotFoundException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    // Test with single-element container
    std::cout << "\n--- Testing with single-element std::list ---" << std::endl;
    std::list<int> singleList;
    singleList.push_back(42);

    try
    {
        std::list<int>::iterator it = easyfind(singleList, 42);
        std::cout << "Found value in list: " << *it << std::endl;
    }
    catch (const NotFoundException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::list<int>::iterator it = easyfind(singleList, 43);
        std::cout << "Found value in list: " << *it << std::endl;
    }
    catch (const NotFoundException &e)
    {
        std::cerr << e.what() << std::endl;
    }


    return 0;
}
