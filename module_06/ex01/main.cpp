#include "serializer.hpp"
#include <iostream>

int main()
{
    Data data;
    data._str = "whats up";
    data._val = 42;

    std::cout << "Original Data pointer: " << &data << std::endl;
    std::cout << "Original Data values: " << data._str << ", " << data._val << std::endl;

    // serialize data pointer
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized Data (uintptr_t): " << raw << std::endl;

    // deserialize the data pointer back into data
    Data* deserialized = Serializer::deserialize(raw);
    std::cout << "Deserialized Data pointer: " << deserialized << std::endl;
    std::cout << "Deserialized Data values: " << deserialized->_str << ", " << deserialized->_val << std::endl;

    if (deserialized == &data)
        std::cout << "Success: Data match" << std::endl;
    else
        std::cout << "Error: data mismatch." << std::endl;

    return 0;
}
