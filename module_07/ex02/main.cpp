#include <iostream>
#include "Array.hpp"

int main()
{
    // Test default construction
    std::cout << "--- Default Construction ---" << std::endl;
    Array<int> arr_default;
    std::cout << "arr_default size: " << arr_default.size() << std::endl;

    // Test construction with size
    std::cout << "\n--- Construction with size ---" << std::endl;
    unsigned int n = 5;
    Array<int> arr_size(n);
    std::cout << "arr_size size: " << arr_size.size() << std::endl;

    // Test default values (before setting)
    std::cout << "Default values in arr_size:" << std::endl;
    for (unsigned int i = 0; i < arr_size.size(); ++i)
    {
        std::cout << "arr_size[" << i << "] = " << arr_size[i] << std::endl;
    }

    // Set values
    std::cout << "\nSetting values in arr_size:" << std::endl;
    for (unsigned int i = 0; i < arr_size.size(); ++i)
    {
        arr_size[i] = (i + 1) * 10;
    }

    // Display values
    std::cout << "Values in arr_size after setting:" << std::endl;
    for (unsigned int i = 0; i < arr_size.size(); ++i)
    {
        std::cout << "arr_size[" << i << "] = " << arr_size[i] << std::endl;
    }

    // Test accessing out of bounds
    std::cout << "\n--- Accessing out of bounds ---" << std::endl;
    try
    {
        std::cout << "Attempting to access arr_size[" << n << "]" << std::endl;
        arr_size[n] = 100;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test copy constructor
    std::cout << "\n--- Copy Constructor ---" << std::endl;
    Array<int> arr_copy(arr_size);
    std::cout << "arr_copy size: " << arr_copy.size() << std::endl;

    std::cout << "Values in arr_copy:" << std::endl;
    for (unsigned int i = 0; i < arr_copy.size(); ++i)
    {
        std::cout << "arr_copy[" << i << "] = " << arr_copy[i] << std::endl;
    }

    // Modify arr_size and arr_copy independently
    std::cout << "\nModifying arr_size and arr_copy independently:" << std::endl;
    arr_size[0] = 999;
    arr_copy[1] = 888;

    std::cout << "arr_size[0] = " << arr_size[0] << std::endl;
    std::cout << "arr_copy[0] = " << arr_copy[0] << std::endl;

    std::cout << "arr_size[1] = " << arr_size[1] << std::endl;
    std::cout << "arr_copy[1] = " << arr_copy[1] << std::endl;

    // Test assignment operator
    std::cout << "\n--- Assignment Operator ---" << std::endl;
    Array<int> arr_assign;
    arr_assign = arr_size;
    std::cout << "arr_assign size: " << arr_assign.size() << std::endl;

    std::cout << "Values in arr_assign:" << std::endl;
    for (unsigned int i = 0; i < arr_assign.size(); ++i)
    {
        std::cout << "arr_assign[" << i << "] = " << arr_assign[i] << std::endl;
    }

    // Modify arr_assign and arr_size independently
    std::cout << "\nModifying arr_assign and arr_size independently:" << std::endl;
    arr_assign[2] = 777;
    arr_size[2] = 666;

    std::cout << "arr_assign[2] = " << arr_assign[2] << std::endl;
    std::cout << "arr_size[2] = " << arr_size[2] << std::endl;

    // Test with std::string
    std::cout << "\n--- Testing with std::string ---" << std::endl;
    Array<std::string> arr_str(3);

    std::cout << "Default values in arr_str:" << std::endl;
    for (unsigned int i = 0; i < arr_str.size(); ++i)
    {
        std::cout << "arr_str[" << i << "] = \"" << arr_str[i] << "\"" << std::endl;
    }

    arr_str[0] = "Hello";
    arr_str[1] = "World";
    arr_str[2] = "!";

    std::cout << "Values in arr_str after setting:" << std::endl;
    for (unsigned int i = 0; i < arr_str.size(); ++i)
    {
        std::cout << "arr_str[" << i << "] = \"" << arr_str[i] << "\"" << std::endl;
    }

    // Test copy and modify
    std::cout << "\n--- Copying arr_str to arr_str_copy ---" << std::endl;
    Array<std::string> arr_str_copy(arr_str);

    arr_str_copy[1] = "C++";

    std::cout << "arr_str[1] = \"" << arr_str[1] << "\"" << std::endl;
    std::cout << "arr_str_copy[1] = \"" << arr_str_copy[1] << "\"" << std::endl;

    // Test exception with std::string array
    std::cout << "\n--- Accessing out of bounds in arr_str ---" << std::endl;
    try
    {
        std::cout << "Attempting to access arr_str[3]" << std::endl;
        arr_str[3] = "Exception";
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test default initialization
    std::cout << "\n--- Testing default initialization ---" << std::endl;
    int *a = new int();
    std::cout << "*a = " << *a << std::endl; // Should be zero
    delete a;

    int *b = new int;
    std::cout << "*b = " << *b << std::endl; // Uninitialized, may be garbage
    delete b;

    return 0;
}
